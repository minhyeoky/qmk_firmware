# My QMK Keyboard Setup

## Keyboard Information
- **Keyboard**: Corne (crkbd) - Rev 4.1 Standard
- **Keymap**: minhyeoky
- **Compile Command**: `qmk compile -kb crkbd/rev4_1/standard -km minhyeoky`

## Keymap Layout

```
/* Base Layer
 * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
 * │  Tab  │   Q   │   W   │   E   │   R   │   T   │                   │   Y   │   U   │   I   │   O   │   ;   │   \   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │ LCtrl │   A   │   S   │   D   │   F   │   G   │                   │   H   │   J   │   K   │   L   │   P   │   '   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │ LShift│   Z   │   X   │   C   │   V   │   B   │                   │   N   │   M   │   ,   │   .   │   /   │ RShift│
 * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬───────┼───────┴───────┴───────┘
 *                         │ LAlt  │ LGui  │Enter/L│       │ │       │ Space/│ RCMD/ │
 *                         │       │       │ Nav   │ Bksp  │ │ Sym   │ R Nav │
 *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
 */

/* Symbol Layer
 * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
 * │       │   1   │   2   │   3   │   4   │   5   │                   │   6   │   7   │   8   │   9   │   0   │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │   {   │   }   │   `   │   ~   │                   │   ←   │   ↓   │   ↑   │   →   │       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │   (   │   )   │   [   │   ]   │                   │       │       │       │       │       │       │
 * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬───────┼───────┴───────┴───────┘
 *                         │       │       │ Space │       │ │       │       │       │
 *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
 */

/* Left Navigation Layer
 * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
 * │       │ Disp1 │ Disp2 │ Disp3 │ Disp4 │ Disp5 │                   │       │   7   │   8   │   9   │       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │BrwsrB │BrwsrP │BrwsrN │BrwsrF │Window │                   │       │   4   │   5   │   6   │       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │Manage │       │RecntSp│SlackLk│       │CapScr │                   │       │   1   │   2   │   3   │       │   0   │
 * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬───────┼───────┴───────┴───────┘
 *                         │       │       │       │       │ │       │   0   │   0   │
 *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
 */

/* Right Navigation Layer
 * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
 * │       │ Disp1 │ Disp2 │ Disp3 │ Disp4 │ Disp5 │                   │       │       │BrghtnD│BrghtnU│       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │BrwsrB │BrwsrP │BrwsrN │BrwsrF │Window │                   │MediaPv│VimNext│VimPrev│MediaNx│       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │       │                   │       │MediaPl│       │       │       │       │
 * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬───────┼───────┴───────┴───────┘
 *                         │       │       │       │       │ │       │       │       │
 *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
 */

/* Management Layer
 * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
 * │QK_BOOT│RGBPrev│RGBNext│       │       │       │                   │       │       │BrghtnD│BrghtnU│       │Sleep  │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │RGBTogg│RGBHueU│RGBSatU│RGBValU│RGBSpdU│       │                   │MediaPv│VolDn  │VolUp  │MediaNx│       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │RGBHueD│RGBSatD│RGBValD│RGBSpdD│       │                   │       │       │MediaPl│       │       │       │
 * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬───────┼───────┴───────┴───────┘
 *                         │       │       │       │       │ │       │       │       │
 *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
 */
```

## Quick Commands
- **Compile Firmware**: `qmk compile -kb crkbd/rev4_1/standard -km minhyeoky`
- **Flash Firmware**: `qmk flash -kb crkbd/rev4_1/standard -km minhyeoky`
- **Create New Keymap**: `qmk new-keymap -kb crkbd/rev4_1/standard`

## Useful Resources
- [Corne Keyboard Documentation](https://github.com/foostan/crkbd)
- [QMK Corne Documentation](https://docs.qmk.fm/#/keyboards/crkbd)
- [QMK Keycodes Reference](https://docs.qmk.fm/#/keycodes)
- [QMK Keymap FAQ](https://docs.qmk.fm/#/faq_keymap)

## Customizing Your Keymap
To customize your keymap, edit the files in: `/keyboards/crkbd/keymaps/minhyeoky/`

Key files include:
- `keymap.c` - Main keymap definitions
- `config.h` - Configuration options
- `rules.mk` - Build options and features

---

# THIS IS THE DEVELOP BRANCH

Warning- This is the `develop` branch of QMK Firmware. You may encounter broken code here. Please see [Breaking Changes](https://docs.qmk.fm/#/breaking_changes) for more information.

# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)
* [Corne (crkbd)](/keyboards/crkbd/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.

