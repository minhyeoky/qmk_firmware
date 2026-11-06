# CLAUDE.md

Corne (crkbd) Rev 4.1 keyboard with custom keymap (`minhyeoky`).

## Commands

```bash
qmk compile -kb crkbd/rev4_1/standard -km minhyeoky
qmk flash -kb crkbd/rev4_1/standard -km minhyeoky
```

## Project Structure

- `/keyboards/crkbd/keymaps/minhyeoky/` - Custom keymap (keymap.c, config.h, rules.mk)
- `/quantum/` - Core QMK firmware
- `/drivers/` - Hardware drivers
- `/lib/` - Submodules (chibios, pico-sdk, lufa, printf)

## KVM Switch (NEXT-7602KVM-4K)

| Keycode | Function | Sequence Sent |
|---------|----------|---------------|
| `KVM_TOGGLE` | Toggle PC1 ↔ PC2, and the platform mode with it | `Scroll Lock` x2 → `1`/`2` → `Enter` |
| `KVM_BEEP_OFF` | Turn off beep sound | `Scroll Lock` x2 → `B0` |

## Platform Mode (mac / win)

PC1 = mac, PC2 = win. The KVM position and the platform mode are one fact, so
they share one bit: `keymap_config.swap_lctl_lgui`, which QMK already persists
in EEPROM and reloads on boot. `plat_is_win()` reads it, `plat_set()` writes it.

| Keycode | Where | Function |
|---------|-------|----------|
| `PLAT_TOGGLE` | MANAGE, same physical key as `KVM_TOGGLE` | Flip the platform mode only — realigns the keyboard when the KVM was switched by its own button or remote |
| `LANG_TOGGLE` | BASE, outermost right thumb | Korean/English: mac sends `KC_RGUI`, win sends `WIN_HANGEUL` |
| `SPC_PREV` / `SPC_NEXT` | L_NAV, `Z` / `C` (flanking `X` = window overview) | Desktop switch: mac `Ctrl+←/→`, win `Win+Ctrl+←/→` |

Two mechanisms, and the split matters when adding platform-dependent keys:

- **Keymap keycodes** carrying a modifier (`OSM(...)`, `G(...)`, `C(...)`) go
  through `mod_config()`, so win mode swaps Ctrl/GUI on them automatically.
- **`SEND_STRING` macros** do not — `register_code()` skips `keycode_config()`.
  Anything platform-dependent there must branch on `plat_is_win()` by hand.

`WIN_HANGEUL` defaults to `KC_LNG1`; switch it to `KC_RALT` if the Windows
Korean IME ignores LANG1 (depends on the installed keyboard driver).

## Caps Word

Both shifts turn it on (`BOTH_SHIFTS_TURNS_ON_CAPS_WORD`). It mirrors ZMK
`&caps_word` on the wireless Corne so both boards type the same, which is why
it departs from QMK defaults:

- No idle timeout (`CAPS_WORD_IDLE_TIMEOUT 0`).
- `caps_word_press_user()` lets Shift (held or one-shot) and `-` continue the
  word; `-` stays `-`, Shift+`-` types `_`. Other modifiers end it.
- `LANG_TOGGLE` returns `false`, so Caps Word never sees it; it calls
  `caps_word_off()` itself.

The ZMK side lives in the wireless Corne's ZMK config (`config/corne.keymap`);
it needs `MINUS` in the `&caps_word` `continue-list` to match. Change either
board's Caps Word rules together with the other.
