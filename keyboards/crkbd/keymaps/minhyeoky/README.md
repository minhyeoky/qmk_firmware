# minhyeoky keymap for Corne (crkbd)

## macOS Scroll Lock Brightness Issue

**Problem**: Pressing Scroll Lock dims the screen on macOS.

**Cause**: macOS maps Scroll Lock to F14 (brightness down) and Pause/Break to F15 (brightness up), inherited from Apple Extended Keyboard layout.

**Solution**: Disable the shortcut in System Settings:
1. **System Settings** → **Keyboard** → **Keyboard Shortcuts**
2. Expand **Display** section
3. Uncheck brightness shortcuts (F14/F15)

## Host-side settings the keymap depends on

`LANG_TOGGLE` (outermost right thumb) sends a bare Right Command on macOS, so
macOS must be told what that means:

1. **System Settings** → **Keyboard** → **Keyboard Shortcuts** → **Input Sources**
2. Bind **Select the previous input source** to Right Command

`SPC_PREV` / `SPC_NEXT` (L_NAV `Z` / `C`) send the OS-native desktop shortcuts,
so **Mission Control** → **Move left/right a space** must stay on `Ctrl+←/→`.
