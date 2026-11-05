#include <atomic>
#include <cmath>
#include <cstdio>
#include <memory>
#include <string>
#include <cstring>
#include <variant>
#include <algorithm>

#if defined(__ANDROID__)
// Needed to pull the ANativeWindow out of the SDL_Window for RT64's RenderWindow.
#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
// ANativeWindow_acquire/_release for the resume-window ownership invariant.
#include <android/native_window.h>
#endif

#define HLSL_CPU
#include "common/rt64_device_workarounds.h"
#include "hle/rt64_application.h"
#include "rt64_render_hooks.h"
#include "overloaded.h"

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"

#include "goemon_config.h"
#include "goemon_render.h"
#include "recomp_ui.h"
#include "concurrentqueue.h"

#if defined(__ANDROID__)
#include "goemon_support.h"
#endif

// Renderer whose timings the status report prints (see southpark_renderer_timings).
static std::atomic<RT64::Application*> timing_app{nullptr};
// The GPU-heavy settings in effect, repeated on every [perf] line: the one-off "[perf] settings"
// line can fall into the part of a long log the launcher leaves out when sharing it.
static std::atomic<int> timing_msaa{-1};
static std::atomic<bool> timing_fbe{true};

static RT64::UserConfiguration::Antialiasing device_max_msaa = RT64::UserConfiguration::Antialiasing::None;
static bool sample_positions_supported = false;
static bool high_precision_fb_enabled = false;

#if defined(__ANDROID__)
#include <atomic>
#include <cmath>
// Fresh ANativeWindow published by the SDL/main thread on resume and consumed
// by the gfx thread (in update_screen) to hand down to the swap chain. Using a
// global atomic avoids the main thread needing a reference to the gfx-thread-
// owned RendererContext; each hop is touched only by its owning thread.
//
// Ordering: publish stores with release, consume exchanges with acq_rel. The
// ANativeWindow it points at is fully constructed by SDL before this store
// (SDL ran surfaceCreated/surfaceChanged synchronously on the UI thread prior
// to DIDENTERFOREGROUND), so release/acquire on the pointer is sufficient to
// hand a valid window to the gfx thread on ARM's weak memory model.
//
// OWNERSHIP (S4 fix): this slot owns exactly one ANativeWindow ref. SDL releases
// its own ref on the window a bounded ~500ms after surfaceDestroyed regardless
// of who is still using it, so a raw pointer stashed here could be freed before
// the gfx thread adopts it (rapid background->foreground->background). Acquire at
// publish so the window cannot die while in our custody; the ref is handed down
// to the swap chain's pendingRenderWindow slot on consume (see the ownership
// invariant in plume_vulkan.cpp VulkanSwapChain's constructor). A publish that
// supersedes an unconsumed window releases the old one.
static std::atomic<void*> g_pending_resume_window{nullptr};

namespace goemon64::renderer {
    void android_publish_resume_window(void* native_window) {
        if (native_window != nullptr) {
            ANativeWindow_acquire(static_cast<ANativeWindow*>(native_window));
        }
        void* prev = g_pending_resume_window.exchange(native_window, std::memory_order_acq_rel);
        if (prev != nullptr) {
            // Superseded before the gfx thread consumed it; release our ref.
            ANativeWindow_release(static_cast<ANativeWindow*>(prev));
        }
    }
}
#endif

static uint8_t DMEM[0x1000];
static uint8_t IMEM[0x1000];

struct TexturePackEnableAction {
    std::string mod_id;
};

struct TexturePackDisableAction {
    std::string mod_id;
};

struct TexturePackSecondaryEnableAction {
    std::string mod_id;
};

struct TexturePackSecondaryDisableAction {
    std::string mod_id;
};

struct TexturePackUpdateAction {
};

using TexturePackAction = std::variant<TexturePackEnableAction, TexturePackDisableAction, TexturePackSecondaryEnableAction, TexturePackSecondaryDisableAction, TexturePackUpdateAction>;

static moodycamel::ConcurrentQueue<TexturePackAction> texture_pack_action_queue;

unsigned int MI_INTR_REG = 0;

unsigned int DPC_START_REG = 0;
unsigned int DPC_END_REG = 0;
unsigned int DPC_CURRENT_REG = 0;
unsigned int DPC_STATUS_REG = 0;
unsigned int DPC_CLOCK_REG = 0;
unsigned int DPC_BUFBUSY_REG = 0;
unsigned int DPC_PIPEBUSY_REG = 0;
unsigned int DPC_TMEM_REG = 0;

void dummy_check_interrupts() {}

RT64::UserConfiguration::Antialiasing compute_max_supported_aa(plume::RenderSampleCounts bits) {
    if (bits & plume::RenderSampleCount::Bits::COUNT_2) {
        if (bits & plume::RenderSampleCount::Bits::COUNT_4) {
            if (bits & plume::RenderSampleCount::Bits::COUNT_8) {
                return RT64::UserConfiguration::Antialiasing::MSAA8X;
            }
            return RT64::UserConfiguration::Antialiasing::MSAA4X;
        }
        return RT64::UserConfiguration::Antialiasing::MSAA2X;
    };
    return RT64::UserConfiguration::Antialiasing::None;
}

RT64::UserConfiguration::AspectRatio to_rt64(ultramodern::renderer::AspectRatio option) {
    switch (option) {
    case ultramodern::renderer::AspectRatio::Original:
        return RT64::UserConfiguration::AspectRatio::Original;
    case ultramodern::renderer::AspectRatio::Expand:
        return RT64::UserConfiguration::AspectRatio::Expand;
    case ultramodern::renderer::AspectRatio::Manual:
        return RT64::UserConfiguration::AspectRatio::Manual;
    case ultramodern::renderer::AspectRatio::OptionCount:
        return RT64::UserConfiguration::AspectRatio::OptionCount;
    }
}

RT64::UserConfiguration::Antialiasing to_rt64(ultramodern::renderer::Antialiasing option) {
    switch (option) {
    case ultramodern::renderer::Antialiasing::None:
        return RT64::UserConfiguration::Antialiasing::None;
    case ultramodern::renderer::Antialiasing::MSAA2X:
        return RT64::UserConfiguration::Antialiasing::MSAA2X;
    case ultramodern::renderer::Antialiasing::MSAA4X:
        return RT64::UserConfiguration::Antialiasing::MSAA4X;
    case ultramodern::renderer::Antialiasing::MSAA8X:
        return RT64::UserConfiguration::Antialiasing::MSAA8X;
    case ultramodern::renderer::Antialiasing::OptionCount:
        return RT64::UserConfiguration::Antialiasing::OptionCount;
    }
}

RT64::UserConfiguration::RefreshRate to_rt64(ultramodern::renderer::RefreshRate option) {
    switch (option) {
    case ultramodern::renderer::RefreshRate::Original:
        return RT64::UserConfiguration::RefreshRate::Original;
    case ultramodern::renderer::RefreshRate::Display:
        return RT64::UserConfiguration::RefreshRate::Display;
    case ultramodern::renderer::RefreshRate::Manual:
        return RT64::UserConfiguration::RefreshRate::Manual;
    case ultramodern::renderer::RefreshRate::OptionCount:
        return RT64::UserConfiguration::RefreshRate::OptionCount;
    }
}

RT64::UserConfiguration::InternalColorFormat to_rt64(ultramodern::renderer::HighPrecisionFramebuffer option) {
    switch (option) {
    case ultramodern::renderer::HighPrecisionFramebuffer::Off:
        return RT64::UserConfiguration::InternalColorFormat::Standard;
    case ultramodern::renderer::HighPrecisionFramebuffer::On:
        return RT64::UserConfiguration::InternalColorFormat::High;
    case ultramodern::renderer::HighPrecisionFramebuffer::Auto:
        return RT64::UserConfiguration::InternalColorFormat::Automatic;
    case ultramodern::renderer::HighPrecisionFramebuffer::OptionCount:
        return RT64::UserConfiguration::InternalColorFormat::OptionCount;
    }
}

void set_application_user_config(RT64::Application* application, const ultramodern::renderer::GraphicsConfig& config) {
    switch (config.res_option) {
    default:
    case ultramodern::renderer::Resolution::Auto:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
        application->userConfig.downsampleMultiplier = 1;
        break;
    case ultramodern::renderer::Resolution::Original:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = std::max(config.ds_option, 1);
        application->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
        break;
    case ultramodern::renderer::Resolution::Original2x:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = 2.0 * std::max(config.ds_option, 1);
        application->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
        break;
    // Higher fixed multiples of native (240p). Downsampling is forced off on
    // these tiers (see ui_config.cpp downsampling_available) to avoid stacking
    // supersampling on top of an already-large render and blowing past RT64's
    // ResolutionMultiplierLimit, so no ds_option factor is applied here.
    case ultramodern::renderer::Resolution::Original2_5x:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = 2.5;
        application->userConfig.downsampleMultiplier = 1;
        break;
    case ultramodern::renderer::Resolution::Original3x:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = 3.0;
        application->userConfig.downsampleMultiplier = 1;
        break;
    case ultramodern::renderer::Resolution::Original4x:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = 4.0;
        application->userConfig.downsampleMultiplier = 1;
        break;
    case ultramodern::renderer::Resolution::Original6x:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = 6.0;
        application->userConfig.downsampleMultiplier = 1;
        break;
    case ultramodern::renderer::Resolution::Original8x:
        application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
        application->userConfig.resolutionMultiplier = 8.0;
        application->userConfig.downsampleMultiplier = 1;
        break;
    }

    switch (config.hr_option) {
    default:
    case ultramodern::renderer::HUDRatioMode::Original:
        application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Original;
        break;
    case ultramodern::renderer::HUDRatioMode::Clamp16x9:
        application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Manual;
        application->userConfig.extAspectTarget = 16.0/9.0;
        break;
    case ultramodern::renderer::HUDRatioMode::Full:
        application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Expand;
        break;
    }

    application->userConfig.aspectRatio = to_rt64(config.ar_option);
    // The menu's third Aspect Ratio choice ("16:9") is Manual with a fixed 16:9 target.
    application->userConfig.aspectTarget = 16.0 / 9.0;
    application->userConfig.antialiasing = to_rt64(config.msaa_option);
    application->userConfig.refreshRate = to_rt64(config.rr_option);
    application->userConfig.refreshRateTarget = config.rr_manual_value;
    application->userConfig.internalColorFormat = to_rt64(config.hpfb_option);
#if defined(__ANDROID__)
    // Auto means 16-bit-per-channel colour targets on any GPU with over 512 MB of memory,
    // i.e. every phone. That doubles the memory traffic of every draw (the limit on mobile
    // GPUs, especially at 3x and above) for no visible gain in N64 output, so on Android
    // Auto means standard 8-bit colour. The setting has no menu entry; "On" still forces it.
    if (config.hpfb_option == ultramodern::renderer::HighPrecisionFramebuffer::Auto) {
        application->userConfig.internalColorFormat = RT64::UserConfiguration::InternalColorFormat::Standard;
    }
#endif
    application->userConfig.displayBuffering = RT64::UserConfiguration::DisplayBuffering::Triple;

    // Not part of userConfig: the sites that read this are deep inside command
    // recording with no path to the configuration. See rt64_device_workarounds.h.
    // Set here rather than only at startup so the toggle applies without a restart
    // -- update_config() routes every later change through this same function.
    RT64::SetFramebufferSyncEnabled(config.fbe_option != ultramodern::renderer::FramebufferEffects::Off);
    // Render to RAM goes with it. In that mode the display-list parse draws the frame a
    // second time on the GPU, waits for it, and copies the result into RDRAM, before the
    // game is told the frame is done -- so every frame's GPU time lands on the game's own
    // critical path (on the Adreno 710 the parse took as long as the GPU, 13-28 ms, and the
    // game fell 13-18% behind while the GPU itself was under budget). With framebuffer
    // sync off the copy into RDRAM is skipped anyway, so the extra render buys nothing.
    application->emulatorConfig.framebuffer.renderToRAM = (config.fbe_option != ultramodern::renderer::FramebufferEffects::Off);

    // The settings that multiply GPU work, logged when they change (a slow-game report is
    // otherwise unreadable without them).
    {
        static const char* const msaa_names[] = { "none", "2x", "4x", "8x" };
        static const char* const rr_names[] = { "Original", "Display (interpolated)", "Manual" };
        const int msaa = int(config.msaa_option), rr = int(config.rr_option);
        char line[200];
        std::snprintf(line, sizeof(line), "[perf] settings: resolution %gx (downsample %dx), MSAA %s, framerate %s%s, framebuffer effects %s\n",
            double(application->userConfig.resolutionMultiplier), int(application->userConfig.downsampleMultiplier),
            (msaa >= 0 && msaa < 4) ? msaa_names[msaa] : "?", (rr >= 0 && rr < 3) ? rr_names[rr] : "?",
            (config.rr_option == ultramodern::renderer::RefreshRate::Manual) ? (" " + std::to_string(config.rr_manual_value)).c_str() : "",
            (config.fbe_option == ultramodern::renderer::FramebufferEffects::Off) ? "off" : "on");
        timing_msaa.store(msaa);
        timing_fbe.store(config.fbe_option != ultramodern::renderer::FramebufferEffects::Off);
        static std::string last;
        if (last != line) {
            last = line;
            std::fputs(line, stderr);
        }
    }
}

ultramodern::renderer::SetupResult map_setup_result(RT64::Application::SetupResult rt64_result) {
    switch (rt64_result) {
    case RT64::Application::SetupResult::Success:
        return ultramodern::renderer::SetupResult::Success;
    case RT64::Application::SetupResult::DynamicLibrariesNotFound:
        return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
    case RT64::Application::SetupResult::InvalidGraphicsAPI:
        return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
    case RT64::Application::SetupResult::GraphicsAPINotFound:
        return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
    case RT64::Application::SetupResult::GraphicsDeviceNotFound:
        return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
    }

    fprintf(stderr, "Unhandled `RT64::Application::SetupResult` ?\n");
    assert(false);
    std::exit(EXIT_FAILURE);
}

ultramodern::renderer::GraphicsApi map_graphics_api(RT64::UserConfiguration::GraphicsAPI api) {
    switch (api) {
    case RT64::UserConfiguration::GraphicsAPI::D3D12:
        return ultramodern::renderer::GraphicsApi::D3D12;
    case RT64::UserConfiguration::GraphicsAPI::Vulkan:
        return ultramodern::renderer::GraphicsApi::Vulkan;
    case RT64::UserConfiguration::GraphicsAPI::Metal:
        return ultramodern::renderer::GraphicsApi::Metal;
    case RT64::UserConfiguration::GraphicsAPI::Automatic:
        return ultramodern::renderer::GraphicsApi::Auto;
    }

    fprintf(stderr, "Unhandled `RT64::UserConfiguration::GraphicsAPI` ?\n");
    assert(false);
    std::exit(EXIT_FAILURE);
}

goemon64::renderer::RT64Context::RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool debug) {
    static unsigned char dummy_rom_header[0x40];
    recompui::set_render_hooks();

#if defined(__ANDROID__)
    // TEMPORARY Bug-6 diagnostics: publish the RDRAM base so the crash handler
    // can classify a fault as an out-of-bounds recompiled pointer.
    goemon64::diag::set_rdram_base(rdram);
#endif

    // Set up the RT64 application core fields.
    RT64::Application::Core appCore{};
#if defined(_WIN32)
    appCore.window = window_handle.window;
#elif defined(__ANDROID__)
    // On Android RT64's RenderWindow is an ANativeWindow* (Plume creates the
    // Vulkan surface from it directly). The ultramodern WindowHandle is the
    // SDL_Window*, so extract the native window that SDL created for it.
    {
        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWindowWMInfo(window_handle, &wmInfo);
        appCore.window = wmInfo.info.android.window;
    }
#elif defined(__linux__)
    appCore.window = window_handle;
#elif defined(__APPLE__)
    appCore.window.window = window_handle.window;
    appCore.window.view = window_handle.view;
#endif

    appCore.checkInterrupts = dummy_check_interrupts;

    appCore.HEADER = dummy_rom_header;
    appCore.RDRAM = rdram;
    appCore.DMEM = DMEM;
    appCore.IMEM = IMEM;

    appCore.MI_INTR_REG = &MI_INTR_REG;

    appCore.DPC_START_REG = &DPC_START_REG;
    appCore.DPC_END_REG = &DPC_END_REG;
    appCore.DPC_CURRENT_REG = &DPC_CURRENT_REG;
    appCore.DPC_STATUS_REG = &DPC_STATUS_REG;
    appCore.DPC_CLOCK_REG = &DPC_CLOCK_REG;
    appCore.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
    appCore.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
    appCore.DPC_TMEM_REG = &DPC_TMEM_REG;

    ultramodern::renderer::ViRegs* vi_regs = ultramodern::renderer::get_vi_regs();

    appCore.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
    appCore.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
    appCore.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
    appCore.VI_INTR_REG = &vi_regs->VI_INTR_REG;
    appCore.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
    appCore.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
    appCore.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
    appCore.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
    appCore.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
    appCore.VI_H_START_REG = &vi_regs->VI_H_START_REG;
    appCore.VI_V_START_REG = &vi_regs->VI_V_START_REG;
    appCore.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
    appCore.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
    appCore.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;

    // Set up the RT64 application configuration fields.
    RT64::ApplicationConfiguration appConfig;
    appConfig.useConfigurationFile = false;
#if defined(__ANDROID__)
    // RT64's detectDataPath() takes the __linux__ branch on Android: HOME is unset
    // for an app, so it falls back to getpwuid()->pw_dir, which is "/". It then
    // throws from std::filesystem::create_directories("/.rt64") (EACCES) and the
    // desktop code never catches it -> SIGABRT on the Gfx Thread during setup.
    // Point RT64 at our app-private data dir (same dir assets/config resolve under)
    // and disable the detection so it never touches the filesystem root.
    appConfig.detectDataPath = false;
    appConfig.dataPath = goemon64::android_program_path();
#endif

    // Create the RT64 application.
    app = std::make_unique<RT64::Application>(appCore, appConfig);

    // Set initial user config settings based on the current settings.
    auto& cur_config = ultramodern::renderer::get_graphics_config();
    set_application_user_config(app.get(), cur_config);
    app->userConfig.developerMode = debug;
    // Prevent the upscaling of texture rectangles.
    app->userConfig.upscale2D = RT64::UserConfiguration::Upscale2D::Original;
    // Force gbi depth branches to prevent LODs from kicking in.
    app->enhancementConfig.f3dex.forceBranch = true;
    // Scale LODs based on the output resolution.
    app->enhancementConfig.textureLOD.scale = true;
    // Do not copy with GPU as it breaks effects in menus and the quality loss is negligible.
    // TODO: Fix the underlying issue in RT64 and re-enable GPU copying — it can cause issues in
    // Goemon's Great Adventure's underwater sections (low resolution). Separate configs per game maybe?
    app->emulatorConfig.framebuffer.copyWithGPU = false;
    // Pick an API if the user has set an override.
    switch (cur_config.api_option) {
    case ultramodern::renderer::GraphicsApi::D3D12:
        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::D3D12;
        break;
    case ultramodern::renderer::GraphicsApi::Vulkan:
        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Vulkan;
        break;
    case ultramodern::renderer::GraphicsApi::Metal:
        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Metal;
        break;
    case ultramodern::renderer::GraphicsApi::Auto:
        app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic;
        break;
    }

    // Set up the RT64 application.
    uint32_t thread_id = 0;
#ifdef _WIN32
    thread_id = window_handle.thread_id;
#endif
    setup_result = map_setup_result(app->setup(thread_id));
    // Get the API that RT64 chose.
    chosen_api = map_graphics_api(app->chosenGraphicsAPI);
    if (setup_result != ultramodern::renderer::SetupResult::Success) {
        app = nullptr;
        return;
    }

#if defined(__ANDROID__)
    // Report the device we actually got. This is where the optional user-supplied
    // Vulkan driver is confirmed or refuted: loading one succeeds even when the
    // system driver ends up being used, so the selected device name is the only
    // evidence of which driver rendered. It also clears the boot latch that
    // otherwise deselects a driver which never gets this far -- see
    // android_glue.cpp. A no-op in a build without custom-driver support.
    goemon64::report_render_device(app->device->getDescription().name.c_str());
#endif

    // Set the application's fullscreen state.
    app->setFullScreen(cur_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);

    // Check if the selected device actually supports MSAA sample positions and MSAA for for the formats that will be used
    // and downgrade the configuration accordingly.
    if (app->device->getCapabilities().sampleLocations) {
        plume::RenderSampleCounts color_sample_counts = app->device->getSampleCountsSupported(plume::RenderFormat::R8G8B8A8_UNORM);
        plume::RenderSampleCounts depth_sample_counts = app->device->getSampleCountsSupported(plume::RenderFormat::D32_FLOAT);
        plume::RenderSampleCounts common_sample_counts = color_sample_counts & depth_sample_counts;
        device_max_msaa = compute_max_supported_aa(common_sample_counts);
        sample_positions_supported = true;
    }
    else {
        device_max_msaa = RT64::UserConfiguration::Antialiasing::None;
        sample_positions_supported = false;
    }

    high_precision_fb_enabled = app->shaderLibrary->usesHDR;
    std::fprintf(stderr, "[perf] colour targets: %s\n", high_precision_fb_enabled ? "16-bit per channel (high precision)" : "8-bit per channel");
    timing_app.store(app.get());
}

goemon64::renderer::RT64Context::~RT64Context() {
    timing_app.store(nullptr);
}

// One line of renderer timings (averages over the last 120 frames, in ms) for the status
// report: whether the GPU, the display-list parsing on the CPU, or neither is the limit.
extern "C" void southpark_renderer_timings(char* out, size_t size) {
    RT64::Application* a = timing_app.load();
    if ((a == nullptr) || (size == 0)) {
        if (size > 0) out[0] = '\0';
        return;
    }
    static const char* const msaa_names[] = { "none", "2x", "4x", "8x" };
    const int msaa = timing_msaa.load();
    std::snprintf(out, size, "gpu=%.1fms per frame, renderer cpu=%.1fms, display-list parse=%.1fms, frame interval=%.1fms, %gx, MSAA %s, fb effects %s",
        a->workloadQueue->rendererGPUProfiler.average(), a->workloadQueue->workloadProfiler.average(),
        a->state->dlCpuProfiler.average(), a->presentQueue->presentProfiler.average(),
        double(a->userConfig.resolutionMultiplier), (msaa >= 0 && msaa < 4) ? msaa_names[msaa] : "?",
        timing_fbe.load() ? "on" : "off");

    // Render passes per frame since the previous report (see RT64::RenderCounters).
    static RT64::RenderCounters last_counters{};
    const RT64::RenderCounters now = RT64::GetRenderCounters();
    const unsigned long long frames = now.workloads - last_counters.workloads;
    if (frames > 0) {
        const size_t used = std::strlen(out);
        const double f = double(frames);
        const double setup = double(now.gpuSetupNs - last_counters.gpuSetupNs) / f / 1e6;
        const double draw = double(now.gpuDrawNs - last_counters.gpuDrawNs) / f / 1e6;
        const double total = double(now.gpuTotalNs - last_counters.gpuTotalNs) / f / 1e6;
        std::snprintf(out + used, size - used,
            ", per frame: %.1f framebuffer pairs, %.1f depth switches, %.0f draws, gpu split %.1f setup + %.1f drawing + %.1f other ms",
            double(now.framebufferPairs - last_counters.framebufferPairs) / f,
            double(now.depthSwitches - last_counters.depthSwitches) / f,
            double(now.draws - last_counters.draws) / f,
            setup, draw, std::max(0.0, total - setup - draw));
    }
    {
        float px = 0.0f, py = 0.0f;
        RT64::GetLastProjectionScale(px, py);
        if (px != 0.0f) {
            const size_t used = std::strlen(out);
            std::snprintf(out + used, size - used, ", projection x/y %.4f/%.4f (aspect %.4f)", px, py, py / px);
        }
    }
    last_counters = now;
}

namespace southpark::status { void count_gfx_task(); void count_screen_update(); }

#if defined(__ANDROID__)
void southpark_android_frame_done();
#endif

// Widescreen: RT64 shows the game's 4:3 picture in the middle and widens every perspective
// projection by target/source aspect (rt64_workload_queue.cpp, rt64_projection_processor.cpp).
// The game culls to its own 4:3 view, so it is told the same factor (southpark.us.toml hook in
// its camera code) and widens its culling to match. South Park's frame is 480x360, so the
// source is 4:3; the target follows RT64's rules for each mode.
static std::atomic<float> widescreen_scale{ 1.0f };

extern "C" float southpark_widescreen_scale(void) {
    return widescreen_scale.load(std::memory_order_relaxed);
}

static void update_widescreen_scale(RT64::Application* application) {
    constexpr float source = 4.0f / 3.0f;
    float target = source;
    switch (application->userConfig.aspectRatio) {
    case RT64::UserConfiguration::AspectRatio::Expand: {
        const uint32_t w = application->sharedQueueResources->swapChainWidth;
        const uint32_t h = application->sharedQueueResources->swapChainHeight;
        if (w > 0 && h > 0) {
            target = std::max(float(w) / float(h), source);
        }
        break;
    }
    case RT64::UserConfiguration::AspectRatio::Manual:
        target = std::max(float(application->userConfig.aspectTarget), source);
        break;
    default:
        break;
    }
    const float scale = target / source;
    if (std::fabs(widescreen_scale.exchange(scale, std::memory_order_relaxed) - scale) > 0.001f) {
        std::fprintf(stderr, "[aspect] widescreen: game culls %.3f times wider (target %.3f)\n", double(scale), double(target));
    }
}

void goemon64::renderer::RT64Context::send_dl(const OSTask* task) {
    southpark::status::count_gfx_task();
    update_widescreen_scale(app.get());
    // View Distance is applied by the game itself now (hooks in southpark.us.toml scale its
    // projection, culling and fade together), so RT64 must not stretch the far plane again.
    RT64::SetFarPlaneScale(1.0f);
#if defined(__ANDROID__)
    southpark_android_frame_done();
#endif
    check_texture_pack_actions();
    app->state->rsp->reset();
    app->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
    app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
}

void goemon64::renderer::RT64Context::update_screen() {
    southpark::status::count_screen_update();
    {
        // Log the VI registers the renderer presents from, on each change (first 12), so a
        // black screen can be told apart from "nothing drawn": a VI_STATUS type of 0 is
        // blank, and VI_ORIGIN must point into the framebuffer the game renders to.
        static ultramodern::renderer::ViRegs last{};
        static int changes = 0;
        // Only once the game runs (the runtime's own boot defaults are not interesting),
        // and a change of the origin alone is just the game swapping buffers.
        ultramodern::renderer::ViRegs now = *ultramodern::renderer::get_vi_regs();
        now.VI_V_CURRENT_LINE_REG = 0;   // changes every frame
        const ultramodern::renderer::ViRegs* r = &now;
        ultramodern::renderer::ViRegs cmp_now = now, cmp_last = last;
        cmp_now.VI_ORIGIN_REG = 0;
        cmp_last.VI_ORIGIN_REG = 0;
        if (ultramodern::is_game_started() && changes < 12 && std::memcmp(&cmp_last, &cmp_now, sizeof(cmp_now)) != 0) {
            changes++;
            last = now;
            fprintf(stderr, "[vi] status=0x%X origin=0x%06X width=%u x_scale=0x%X y_scale=0x%X h_start=0x%X v_start=0x%X\n",
                    r->VI_STATUS_REG, r->VI_ORIGIN_REG, r->VI_WIDTH_REG, r->VI_X_SCALE_REG, r->VI_Y_SCALE_REG,
                    r->VI_H_START_REG, r->VI_V_START_REG);
        }
    }
#if defined(__ANDROID__)
    // On the gfx thread: if the SDL/main thread published a fresh ANativeWindow
    // on resume, hand it to the swap chain. The present thread rebuilds the
    // Vulkan surface from it inside resize(). Done here (not from the main
    // thread) so only gfx/present threads ever touch RT64/Plume Vulkan state.
    if (void* nw = g_pending_resume_window.exchange(nullptr, std::memory_order_acq_rel)) {
        if (app && app->swapChain != nullptr) {
            // Transfer our owned ref into the swap chain's pendingRenderWindow slot.
            app->swapChain->setRenderWindow(static_cast<ANativeWindow*>(nw));
        }
        else {
            // No swap chain to adopt it (early startup / teardown); don't leak
            // the ref we acquired at publish.
            ANativeWindow_release(static_cast<ANativeWindow*>(nw));
        }
    }
#endif
    app->updateScreen();
}

void goemon64::renderer::RT64Context::shutdown() {
    if (app != nullptr) {
        app->end();
    }
}

bool goemon64::renderer::RT64Context::update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) {
    if (old_config == new_config) {
        return false;
    }

    if (new_config.wm_option != old_config.wm_option) {
        app->setFullScreen(new_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
    }

    set_application_user_config(app.get(), new_config);

    app->updateUserConfig(true);
    app->updateEmulatorConfig();

    if (new_config.msaa_option != old_config.msaa_option) {
        app->updateMultisampling();
    }
    return true;
}

void goemon64::renderer::RT64Context::enable_instant_present() {
    // Enable the present early presentation mode for minimal latency.
    app->enhancementConfig.presentation.mode = RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;

    app->updateEnhancementConfig();
}

uint32_t goemon64::renderer::RT64Context::get_display_framerate() const {
    return app->presentQueue->ext.sharedResources->swapChainRate;
}

float goemon64::renderer::RT64Context::get_resolution_scale() const {
    constexpr int ReferenceHeight = 240;
    switch (app->userConfig.resolution) {
    case RT64::UserConfiguration::Resolution::WindowIntegerScale:
        if (app->sharedQueueResources->swapChainHeight > 0) {
            return std::max(float((app->sharedQueueResources->swapChainHeight + ReferenceHeight - 1) / ReferenceHeight), 1.0f);
        }
        else {
            return 1.0f;
        }
    case RT64::UserConfiguration::Resolution::Manual:
        return float(app->userConfig.resolutionMultiplier);
    case RT64::UserConfiguration::Resolution::Original:
    default:
        return 1.0f;
    }
}

void goemon64::renderer::RT64Context::check_texture_pack_actions() {
    bool packs_changed = false;
    TexturePackAction cur_action;
    while (texture_pack_action_queue.try_dequeue(cur_action)) {
        std::visit(overloaded{
            [&](TexturePackDisableAction &to_disable) {
                enabled_texture_packs.erase(to_disable.mod_id);
                packs_changed = true;
            },
            [&](TexturePackEnableAction &to_enable) {
                enabled_texture_packs.insert(to_enable.mod_id);
                packs_changed = true;
            },
            [&](TexturePackSecondaryDisableAction &to_override_disable) {
                secondary_disabled_texture_packs.insert(to_override_disable.mod_id);
                packs_changed = true;
            },
            [&](TexturePackSecondaryEnableAction &to_override_enable) {
                secondary_disabled_texture_packs.erase(to_override_enable.mod_id);
                packs_changed = true;
            },
            [&](TexturePackUpdateAction &) {
                packs_changed = true;
            }
            }, cur_action);
    }

    // If any packs were disabled, unload all packs and load all the active ones.
    if (packs_changed) {
        // Sort the enabled texture packs in reverse order so that earlier ones override later ones.
        std::vector<std::string> sorted_texture_packs{};
        sorted_texture_packs.reserve(enabled_texture_packs.size());
        for (const std::string& mod : enabled_texture_packs) {
            if (!secondary_disabled_texture_packs.contains(mod)) {
                sorted_texture_packs.emplace_back(mod);
            }
        }

        std::sort(sorted_texture_packs.begin(), sorted_texture_packs.end(),
            [](const std::string& lhs, const std::string& rhs) {
                return recomp::mods::get_mod_order_index(lhs) > recomp::mods::get_mod_order_index(rhs);
            }
        );

        // Build the path list from the sorted mod list.
        std::vector<RT64::ReplacementDirectory> replacement_directories;
        replacement_directories.reserve(enabled_texture_packs.size());
        for (const std::string &mod_id : sorted_texture_packs) {
            replacement_directories.emplace_back(RT64::ReplacementDirectory(recomp::mods::get_mod_filename(mod_id)));
        }

        if (!replacement_directories.empty()) {
            app->textureCache->loadReplacementDirectories(replacement_directories);
        }
        else {
            app->textureCache->clearReplacementDirectories();
        }
    }
}

RT64::UserConfiguration::Antialiasing goemon64::renderer::RT64MaxMSAA() {
    return device_max_msaa;
}

std::unique_ptr<ultramodern::renderer::RendererContext> goemon64::renderer::create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<goemon64::renderer::RT64Context>(rdram, window_handle, developer_mode);
}

bool goemon64::renderer::RT64SamplePositionsSupported() {
    return sample_positions_supported;
}

bool goemon64::renderer::RT64HighPrecisionFBEnabled() {
    return high_precision_fb_enabled;
}

void goemon64::renderer::trigger_texture_pack_update() {
    texture_pack_action_queue.enqueue(TexturePackUpdateAction{});
}

void goemon64::renderer::enable_texture_pack(const recomp::mods::ModContext& context, const recomp::mods::ModHandle& mod) {
    texture_pack_action_queue.enqueue(TexturePackEnableAction{mod.manifest.mod_id});

    // Check for the texture pack enabled config option.
    const recomp::mods::ConfigSchema& config_schema = context.get_mod_config_schema(mod.manifest.mod_id);
    auto find_it = config_schema.options_by_id.find(goemon64::renderer::special_option_texture_pack_enabled);
    if (find_it != config_schema.options_by_id.end()) {
        const recomp::mods::ConfigOption& config_option = config_schema.options[find_it->second];

        if (is_texture_pack_enable_config_option(config_option, false)) {
            recomp::mods::ConfigValueVariant value_variant = context.get_mod_config_value(mod.manifest.mod_id, config_option.id);
            uint32_t value;
            if (uint32_t* value_ptr = std::get_if<uint32_t>(&value_variant)) {
                value = *value_ptr;
            }
            else {
                value = 0;
            }

            if (value) {
                goemon64::renderer::secondary_enable_texture_pack(mod.manifest.mod_id);
            }
            else {
                goemon64::renderer::secondary_disable_texture_pack(mod.manifest.mod_id);
            }
        }
    }
}

void goemon64::renderer::disable_texture_pack(const recomp::mods::ModHandle& mod) {
    texture_pack_action_queue.enqueue(TexturePackDisableAction{mod.manifest.mod_id});
}

void goemon64::renderer::secondary_enable_texture_pack(const std::string& mod_id) {
    texture_pack_action_queue.enqueue(TexturePackSecondaryEnableAction{mod_id});
}

void goemon64::renderer::secondary_disable_texture_pack(const std::string& mod_id) {
    texture_pack_action_queue.enqueue(TexturePackSecondaryDisableAction{mod_id});
}


// HD texture enable option. Must be an enum with two options.
// The first option is treated as disabled and the second option is treated as enabled.
bool goemon64::renderer::is_texture_pack_enable_config_option(const recomp::mods::ConfigOption& option, bool show_errors) {
    if (option.id == goemon64::renderer::special_option_texture_pack_enabled) {
        if (option.type != recomp::mods::ConfigOptionType::Enum) {
            if (show_errors) {
                recompui::message_box(("Mod has the special config option id for enabling an HD texture pack (\"" + goemon64::renderer::special_option_texture_pack_enabled + "\"), but the config option is not an enum.").c_str());
            }
            return false;
        }

        const recomp::mods::ConfigOptionEnum &option_enum = std::get<recomp::mods::ConfigOptionEnum>(option.variant);
        if (option_enum.options.size() != 2) {
            if (show_errors) {
                recompui::message_box(("Mod has the special config option id for enabling an HD texture pack (\"" + goemon64::renderer::special_option_texture_pack_enabled + "\"), but the config option doesn't have exactly 2 values.").c_str());
            }
            return false;
        }

        return true;
    }
    return false;
}
