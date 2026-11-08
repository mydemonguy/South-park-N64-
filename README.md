# South Park 64: Recompiled (Android)

**South Park** for the Nintendo 64, rebuilt to run natively on Android phones. It isn't an emulator: the game's code was translated into a normal Android app with [N64: Recompiled](https://github.com/N64Recomp/N64Recomp), so it runs on the phone's own hardware with modern graphics through [RT64](https://github.com/rt64/rt64).

Extras on top of the original:

- **16:9 widescreen** and **longer view distance**
- **Higher resolutions** (up to 4x) and anti-aliasing
- **On-screen touch controls**, or any Bluetooth/USB gamepad
- **Multiplayer with AI bots**: play 2–4 player split-screen against up to 3 computer players
- **Saving** to an emulated Controller Pak

> **You need your own copy of the game.** This app contains no ROM and no game data. You supply a ROM of the US cartridge, which the app checks and copies into its own storage.

---

## Contents

- [What you need](#what-you-need)
- [Install](#install)
- [Controls](#controls)
- [Settings](#settings)
- [Multiplayer with bots](#multiplayer-with-bots)
- [Saving](#saving)
- [If something goes wrong](#if-something-goes-wrong)
- [Known issues](#known-issues)
- [For developers](#for-developers)
- [Credits and license](#credits-and-license)

---

## What you need

- An **Android 9 or newer** phone or tablet with a **64-bit (arm64) processor** and **Vulkan** graphics, which covers most devices from the last several years.
- A **South Park (USA) N64 ROM** in `.z64` format:
  - SHA-1 `42d7350d1f9040c5546f481c4d650b99a23aadbc`
  - Other regions and formats (`.n64`, `.v64`) are not supported.

## Install

1. On your phone, open the **[latest release](../../releases/tag/latest)** and download **`SouthPark64-debug.apk`**. A new build is published there automatically after every change.
2. Open the downloaded file. If Android asks, allow your browser or file manager to **install unknown apps**, then tap **Install**.
3. Open **South Park 64**.
   - If your phone has an SD card, the app asks once where to keep its data.
4. Tap **Select ROM** and pick your South Park (USA) `.z64` file. The app verifies it and copies it into its private storage, so you only do this once.
5. The game starts.

To update, install the newer APK over the old one. Your settings and saves are kept.

## Controls

### Touch screen

The on-screen controls appear automatically and hide while you use a gamepad.

- **Tap ☰** (bottom centre) to open the settings menu.
- **Long-press ☰** to choose a layout and change the controls' size, opacity and vibration. There are three layouts:
  - **Move + aim sticks, Turok controls** (default): the left stick moves, drag on the right half of the screen to aim, and use the big **FIRE** and **JUMP** buttons. **A**, **B** and **ALT** sit above them.
  - **Move + aim sticks, Brown-Eye controls**: the same pad, for when the game itself is set to the Brown-Eye control method.
  - **Classic N64 pad**: every N64 button, one for one.
- To move buttons around, go to **Settings → Touch → Edit Layout**. Drag them where you like, then press **Done**. **Reset** puts them back.
- Pick the touch layout that matches the control method chosen in the game's own options. Otherwise moving and aiming will feel swapped.

### Gamepad

Any controller Android recognises works (Xbox, PlayStation, Switch Pro, 8BitDo and so on). The defaults use Xbox button positions:

| N64 | Gamepad |
|---|---|
| Analog stick | Left stick |
| A / B | A / B (bottom / right) |
| Z | Left trigger |
| R | Right trigger |
| L | Left bumper |
| Start | Start / Menu |
| C-Up | X, right stick up, or D-pad up |
| C-Down | Right bumper, right stick down, or D-pad down |
| C-Left | Y, right stick left, or D-pad left |
| C-Right | Right stick right, or D-pad right |
| N64 D-pad (switch a weapon's fire mode) | Click the left stick |
| **Open settings** | **Back / Select / View** |

Everything can be remapped under **Settings → Controls**.

With the game's **Turok** control method (what the default touch layout expects), the C-buttons walk and strafe and the analog stick aims. **Z** throws and **R** jumps.

## Settings

Open the menu with **☰**, the gamepad's **Back/Select** button, or **Esc** on a keyboard.

| Tab | Highlights |
|---|---|
| **General** | **View Distance** (Original, Far, Farther, Max): how far away the world is drawn. **Multiplayer Bots** (Off, 1, 2, 3): see below. |
| **Graphics** | **Resolution** (Original to 4x), **Aspect Ratio** (16:9 widescreen by default, or the original 4:3), **Anti-Aliasing**, **Framerate**. If your phone struggles, lower Resolution first. |
| **Controls** | Remap every button for gamepad and keyboard. |
| **Sound** | Main, music and sound effect volume. |
| **Touch** | Show or hide the on-screen controls (Auto, On, Off), stick sensitivity and layout editing. |
| **Driver** | Advanced: load a custom Vulkan GPU driver (`.adpkg` or `.so`, e.g. Turnip for Adreno). If a driver stops the game from starting, the app switches back to the system driver by itself. |

## Multiplayer with bots

The game only lets you pick **Multiplayer** when more than one controller is connected. The app therefore adds computer players as controllers 2–4.

1. **Multiplayer Bots** is set to **3** out of the box. You can change it under **Settings → General**, and it takes effect straight away. **Off** greys Multiplayer out again.
2. On the main menu choose **Multiplayer**. Set **PLAYERS** to include the bots, e.g. 4 for you plus 3 bots, and pick the level, time and win limits.
3. Choose **Start Game**. The bots leave the menus to you and start playing as soon as the split-screen match begins.

What the bots do:

- They come looking for **you** first. They only fight each other when they run into one another and you're far away.
- They find their way around the level by remembering everywhere players have walked during the match.
- They aim ahead of a moving target, circle-strafe in a fight, and sidestep when you line up a shot on them.
- Each has its own style. **Player 2** is a brawler and gets in close, **Player 3** is a sharpshooter and hangs back, and **Player 4** is a dodger and hard to pin down.
- When knocked out, they press Continue and jump back in.

They can't see walls. Early in a match, before anyone has walked much of the level, a bot can get caught on a corner for a moment.

## Saving

The game saves to an emulated **Controller Pak**. Use the game's own save and load options as you would on the console. The save is stored in the app's data folder as `controller_pak_1.mpk`, a standard Controller Pak image that most N64 save tools can open. It survives app updates, but uninstalling the app deletes it.

## If something goes wrong

**The game crashed or froze.** Close the app from your recent apps and open it again. It shows **"Last game session didn't finish"** with the end of the log. Tap **Share** or **Copy log** and include it when you report the problem.

**To report anything else**, such as graphics glitches or bots acting strangely, play until it happens, then close the app from recent apps and reopen it to get the same log screen. The log covers what the game was doing, your settings and a summary of the bots' last match.

**Common questions:**

- *Multiplayer is greyed out.* Set **Settings → General → Multiplayer Bots** to 1, 2 or 3.
- *Short stutters the first time something new appears.* Your phone is preparing that graphics effect. It's remembered, so it only happens once.
- *It runs slowly.* Lower **Graphics → Resolution** and turn off anti-aliasing. 4-player split screen runs at the game's own reduced speed.
- *Moving and aiming feel swapped.* Long-press **☰** and pick the touch layout that matches the game's control method.

## Known issues

- **Clouds in the sky can look tiled or repeated** in some places. This is being investigated.
- **Only level 1 has been played through to the end on this build.** A full scan of the game's code found no remaining problems of the kind that stopped the game after level 1, but if a later level stops or looks wrong, please send the log.
- **Some screen effects are turned off on certain phones.** On Adreno GPUs, effects that read back what's already on screen are disabled to avoid driver problems, so a few screens may look slightly different from the console.

---

## For developers

The app layer is a fork of [Goemon64Recomp-Android](https://github.com/ogdanimal/Goemon64Recomp-Android), with South Park's game layer swapped in. A Linux desktop build is used for testing.

This repository contains no ROM or game data. It does contain the recompiled program code (`RecompiledFuncs/`, a machine translation of the game's MIPS code to C), so that CI can build without a ROM.

### Building

GitHub Actions builds everything: every push to `main` runs `.github/workflows/android.yml`. Each run attaches a debug APK to the run as an artifact and replaces the APK on the [`latest` release](../../releases/tag/latest).

To build locally you need the Android SDK, NDK `27.1.12297006`, JDK 17 and the host tool `build-host-tools/file_to_c` (see the workflow), then:

```bash
cd android && ./gradlew assembleDebug -PcustomDriver=true
```

For the Linux desktop build, use CMake and Ninja into `build-linux/`. These environment variables help with testing:

- `SOUTHPARK_ROM=<path>`: the ROM to load
- `SOUTHPARK_AUTOSTART=1`: skip the launcher and start the game
- `SOUTHPARK_AUTOPLAY=1`: controller 1 plays itself (Autoplay Test)
- `SOUTHPARK_TEST_INPUT=<file>`: drive the controllers from a text file of button names, e.g. `A`, `CU`, `X=0.5`, `P2:Z` or `BOTS=3`

### How the game is laid out

- **Boot stub:** at ROM `0x1000`, running at `0x80000400`. It maps virtual `0x00200000` to physical 0 with the TLB and jumps to `game_boot` (`0x0022BCE8`).
- **Main code:** at ROM `0x1128`–`0xA7ED8`, running at `0x00200528`. Data is read through KSEG0 (`0x800…`).
- **Block 2:** at ROM `0xC4000` (`0x14AA0` bytes of code). It is demand-paged into the heap and mapped at `0x00400000` (set up at `0x0028FD48`, mapped by `map_tlb` at `0x00291198`).
  - There is a second, unreferenced copy of this block at ROM `0xDC000` that the game never loads.
- **Audio microcode:** standard libultra `aspMain`, with text at ROM `0xBAE78`.
- **FPU:** runs in 64-bit register mode (Status.FR = 1).

### Regenerating the recompiled code

You need your ROM as `southpark.us.z64` in the repo root (never commit it), and N64Recomp at commit `81213c1` with `tools/n64recomp-tlb-jumptables.patch` applied.

```bash
N64Recomp southpark.us.toml      # -> RecompiledFuncs/
RSPRecomp aspMain.us.toml        # -> rsp/aspMain.cpp
make -C patches CC=clang LD=ld.lld NM=llvm-nm && N64Recomp patches.toml
build-host-tools/file_to_c patches/patches.bin mm_patches_bin RecompiledPatches/patches_bin.c RecompiledPatches/patches_bin.h
```

`southpark.us.syms.toml` lists every function's address and size. It is generated by `tools/gen_syms.py` from spimdisasm output; see that script's header.

Hooks are declared in `southpark.us.toml` (`[[patches.hook]]`). They cover the view distance and widescreen culling in the camera update (`func_0025B68C`) and the bots' camera tap.

### South Park-specific runtime code

**`src/main/main.cpp`:** game registration, the FR = 1 entry wrapper, TLB setup, and desktop testing helpers.

**`src/game/southpark_os.cpp`:** the game's OS layer.
- Its own DMA thread on `osPiRawStartDma`.
- Real TLB emulation, by mapping the shared RDRAM pages again at the virtual address.
- Cart I/O.
- **Controller Pak emulation** at the PIF level (status, read, write, CRC), saved to `controller_pak_1.mpk`.

**`src/game/southpark_bot.cpp`:** the multiplayer bots.
- **Camera matching:** each bot finds its own view by correlating its stick with how each camera turns.
- **Navigation:** a path map learned from players' movement.
- **Targeting and aim:** chooses a target, leads its throws, dodges, and handles the Continue screen.

**`src/main/rt64_render_context.cpp`:** widescreen and the far-plane scale. It also saves and pre-compiles the shader list at startup.

**`tools/patches/`:** local patches for RT64 and N64ModernRuntime, applied when CMake configures:
- RT64: waits for specialised shaders instead of skipping draws, and logs per-pass timings.
- N64ModernRuntime: `osContInit` reports every connected controller.

**`include/sp_recomp.h`:** float-to-int conversions that give the same results on x86 and ARM64.

**Builds and testing:**
- The recompiled code builds with `-ffp-contract=off` (no fused multiply-add).
- `tools/difftest/` runs recompiled functions on x86-64 and ARM64 (qemu) with identical inputs and compares the results.

### libultra identification

`tools/libultra_names.json` names 87 functions, each with its evidence: n64sym signature matches and structural identification against ultralib. N64ModernRuntime replaces them; `tools/gen_config.py` writes the stub and ignore lists.

The game doesn't use the PI manager. It has its own DMA thread, and it accesses the Controller Pak through raw SI from game code, which is why the pak is emulated at the PIF level.

## Credits and license

GPL-3.0 (see `COPYING`), inherited from Goemon64Recomp-Android.

Built on:
- [N64Recomp / N64ModernRuntime](https://github.com/N64Recomp)
- [RT64](https://github.com/rt64/rt64)
- [Goemon64Recomp-Android](https://github.com/ogdanimal/Goemon64Recomp-Android) (ogdanimal)
- [Goemon64Recomp](https://github.com/klorfmorf/Goemon64Recomp) (klorfmorf)
- [Zelda64Recomp-Android](https://github.com/linkzenic/Zelda64Recomp-Android) (linkzenic)
- RmlUi, lunasvg, libadrenotools and SDL2

The app artwork is original and generic. This project isn't affiliated with South Park's rights holders, and you need your own legally obtained copy of the game.
