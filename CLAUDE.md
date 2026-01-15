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
| `KVM_TOGGLE` | Toggle PC1 ↔ PC2 | `Scroll Lock` x2 → `1`/`2` → `Enter` |
| `KVM_BEEP_OFF` | Turn off beep sound | `Scroll Lock` x2 → `B0` |
