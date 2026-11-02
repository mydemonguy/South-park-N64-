#include "sp_recomp.h"
#include "funcs.h"
#include "librecomp/sections.h"

static FuncEntry section_1_text_funcs[] = {
    { .func = sp_patches_placeholder, .offset = 0x00000000, .rom_size = 0x00000008 },
};
static SectionTableEntry section_table[] = {
    { .rom_addr = 0x00000000, .ram_addr = 0x80801000, .size = 0x00000008, .funcs = section_1_text_funcs, .num_funcs = ARRLEN(section_1_text_funcs), .relocs = nullptr, .num_relocs = 0, .index = 1 },
};
const size_t num_sections = 7;
static int overlay_sections_by_index[] = {
    -1,
};

static FunctionExport export_table[] = {
    { NULL, 0 }
};

static const char* event_names[] = {
    NULL
};

static const ManualPatchSymbol manual_patch_symbols[] = {
    { 0x8F000000, recomp_update_inputs },
    { 0x8F000004, recomp_puts },
    { 0x8F000008, recomp_exit },
    { 0x8F00000C, recomp_get_gyro_deltas },
    { 0x8F000010, recomp_get_mouse_deltas },
    { 0x8F000014, recomp_powf },
    { 0x8F000018, recomp_get_target_framerate },
    { 0x8F00001C, recomp_get_window_resolution },
    { 0x8F000020, recomp_get_target_aspect_ratio },
    { 0x8F000024, recomp_get_targeting_mode },
    { 0x8F000028, recomp_get_bgm_volume },
    { 0x8F00002C, recomp_get_se_volume },
    { 0x8F000030, recomp_time_us },
    { 0x8F000034, recomp_get_autosave_enabled },
    { 0x8F000038, recomp_load_overlays },
    { 0x8F00003C, recomp_unload_overlays },
    { 0x8F000040, recomp_high_precision_fb_enabled },
    { 0x8F000044, recomp_get_resolution_scale },
    { 0x8F000048, recomp_get_inverted_axes },
    { 0x8F00004C, recomp_get_analog_inverted_axes },
    { 0x8F000050, recomp_get_analog_cam_enabled },
    { 0x8F000054, recomp_get_camera_inputs },
    { 0x8F000058, recomp_set_right_analog_suppressed },
    { 0x8F00005C, recomp_run_ui_callbacks },
    { 0x8F000060, recomp_set_analog_cam_yaw },
    { 0x8F000064, recomp_get_analog_cam_sensitivity },
    { 0x8F000068, recomp_get_camera_recenter_pressed },
    { 0x8F00006C, recomp_get_infinite_health_enabled },
    { 0x8F000070, recomp_get_infinite_money_enabled },
    { 0x8F000074, recomp_get_infinite_lives_enabled },
    { 0x8F000078, recomp_get_swap_while_moving_enabled },
    { 0x8F00007C, recomp_set_autosave_in_progress },
    { 0x8F000080, recomp_notify_saved },
    { 0x8F000084, recomp_get_camera_zoom_held },
    { 0x8F000088, recomp_get_attack_while_moving_enabled },
    { 0x8F00008C, recomp_is_config_menu_open },
    { 0x8F000090, recomp_set_field_engine_active },
    { 0, NULL }
};
