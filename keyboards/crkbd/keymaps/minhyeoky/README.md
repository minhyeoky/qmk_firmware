# minhyeoky keymap for Corne (crkbd)

## macOS Scroll Lock Brightness Issue

**Problem**: Pressing Scroll Lock dims the screen on macOS.

**Cause**: macOS maps Scroll Lock to F14 (brightness down) and Pause/Break to F15 (brightness up), inherited from Apple Extended Keyboard layout.

**Solution**: Disable the shortcut in System Settings:
1. **System Settings** → **Keyboard** → **Keyboard Shortcuts**
2. Expand **Display** section
3. Uncheck brightness shortcuts (F14/F15)
