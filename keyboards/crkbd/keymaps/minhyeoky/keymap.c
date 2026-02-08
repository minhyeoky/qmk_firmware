/*
 * QMK Firmware for Corne (CRKBD) Keyboard
 *
 * Copyright 2019 @foostan
 * Copyright 2020 Drashna Jaelre <@drashna>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#if __has_include("secrets.h")
#    include "secrets.h"
#endif

/*
 * Layer Definitions
 */
enum layers {
    BASE = 0,
    SYMBOL,
    L_NAV,
    MANAGE
};

/*
 * Custom Keycodes
 */
enum custom_keycodes {
    BRACKET_COMPLETE = SAFE_RANGE,
    VIM_CNEXT,      // Vim next item
    VIM_CPREV,      // Vim previous item
    SLACK_COPY_LINK, // Copy link in Slack
    CAPTURE,        // macOS screen capture
    RECENT_SPACE,   // skhd (yabai - recent space)
    SEC_ID,         // Secret ID
    SEC_PW,         // Secret Password
    KVM_TOGGLE,     // Toggle KVM between PC1 and PC2
    KVM_BEEP_OFF,   // Turn off KVM beep sound
};

/*
 * Shortcut Macros
 */
// Browser controls
#define BRWSR_F G(KC_RBRC)      // Browser forward
#define BRWSR_B G(KC_LBRC)      // Browser back
#define BRWSR_P S(C(KC_TAB))    // Browser previous tab
#define BRWSR_N C(KC_TAB)       // Browser next tab

// Window management (Yabai)
#define WINDOWS  C(KC_UP)       // Window overview
#define SPACE_N  C(A(KC_P))     // Next space
#define SPACE_P  C(A(KC_N))     // Previous space
#define DISPY_P  A(KC_N)        // Previous display
#define DISPY_N  A(KC_P)        // Next display
#define DISPY_1  C(KC_1)        // Display 1
#define DISPY_2  C(KC_2)        // Display 2
#define DISPY_3  C(KC_3)        // Display 3
#define DISPY_4  C(KC_4)        // Display 4
#define DISPY_5  C(KC_5)        // Display 5

/*
 * Tap-Hold Definitions
 */
#define LT_SPC     LT(SYMBOL, KC_SPC)   // Space when tapped, Symbol layer when held
#define ENT_OR_LNAV LT(L_NAV, KC_ENT)   // Enter when tapped, L_NAV layer when held

/*
 * One-Shot Modifiers
 */
#define OS_LCTL OSM(MOD_LCTL)   // One-shot Left Control
#define OS_LSFT OSM(MOD_LSFT)   // One-shot Left Shift
#define OS_RSFT OSM(MOD_RSFT)   // One-shot Right Shift
#define OS_LALT OSM(MOD_LALT)   // One-shot Left Alt
#define OS_LGUI OSM(MOD_LGUI)   // One-shot Left GUI (Command)

/*
 * Combo Definitions
 */
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_mcomm[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_nm[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_jk, KC_ENTER),
    COMBO(combo_ui, KC_MINUS),
    COMBO(combo_io, KC_EQUAL),
    COMBO(combo_mcomm, KC_LBRC),
    COMBO(combo_commdot, KC_RBRC),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_kl, KC_COLN),
    COMBO(combo_nm, KC_B),
};

/*
 * Keymap Definitions
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     * │  Tab  │   Q   │   W   │   E   │   R   │   T   │                   │   Y   │   U   │   I   │   O   │   ;   │   \   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │ LCtrl │   A   │   S   │   D   │   F   │   G   │                   │   H   │   J   │   K   │   L   │   P   │   '   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │ LShift│   Z   │   X   │   C   │   V   │   B   │                   │   N   │   M   │   ,   │   .   │   /   │ RShift│
     * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬───────┼───────┴───────┴───────┘
     *                         │ LAlt  │ LGui  │Enter/L│       │ │       │ Space/│       │
     *                         │       │       │ Nav   │ Bksp  │ │ Sym   │ RCMD  │
     *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
     */
    [BASE] = LAYOUT_split_3x6_3_ex2(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KVM_TOGGLE, XXXXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, KC_BSLS,
        OS_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    SEC_PW, XXXXXXX,  KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
                                   OS_LALT, OS_LGUI, ENT_OR_LNAV, KC_BSPC, LT_SPC, KC_RCMD
    ),

    /* Symbol Layer
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │   1   │   2   │   3   │   4   │   5   │                   │   6   │   7   │   8   │   9   │   0   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │   {   │   }   │   `   │   ~   │                   │   ←   │   ↓   │   ↑   │   →   │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │   (   │   )   │   [   │   ]   │                   │       │       │       │       │       │       │
     * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬─────────┼───────┴───────┴───────┘
     *                         │       │       │ Space │       │ │       │       │       │
     *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
     */
    [SYMBOL] = LAYOUT_split_3x6_3_ex2(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_GRV,  KC_TILD, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,                   XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______,
                                   _______, _______, KC_SPC,  _______, _______, _______
    ),

    /* Left Navigation Layer
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │ Disp1 │ Disp2 │ Disp3 │ Disp4 │ Disp5 │                   │       │   7   │   8   │   9   │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │BrwsrB │BrwsrP │BrwsrN │BrwsrF │RecntSp│                   │       │   4   │   5   │   6   │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │Manage │       │Window │SlackLk│       │CapScr │                   │       │   1   │   2   │   3   │       │   0   │
     * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬─────────┼───────┴───────┴───────┘
     *                         │       │       │       │       │ │       │   0   │   0   │
     *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
     */
    [L_NAV] = LAYOUT_split_3x6_3_ex2(
        _______, DISPY_1, DISPY_2, DISPY_3, DISPY_4, DISPY_5, _______, _______, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, _______,
        _______, BRWSR_B, BRWSR_P, BRWSR_N, BRWSR_F, RECENT_SPACE, _______, _______, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
        MO(MANAGE),_______,WINDOWS,SLACK_COPY_LINK,XXXXXXX,CAPTURE,                   XXXXXXX, KC_1,    KC_2,    KC_3,    _______, KC_0,
                                   _______, _______, _______, _______, KC_0,    KC_0
    ),

    /* Management Layer
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐                   ┌───────┬───────┬───────┬───────┬───────┬───────┐
     * │QK_BOOT│RGBPrev│RGBNext│       │       │       │                   │       │       │BrghtnD│BrghtnU│       │Sleep  │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │RGBTogg│RGBHueU│RGBSatU│RGBValU│RGBSpdU│       │                   │MediaPv│VolDn  │VolUp  │MediaNx│       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤                   ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │RGBHueD│RGBSatD│RGBValD│RGBSpdD│       │                   │       │       │MediaPl│       │       │       │
     * └───────┴───────┴───────┼───────┼───────┼───────┼───────┐ ┌───────┬───────┬───────┬─────────┼───────┴───────┴───────┘
     *                         │       │       │       │       │ │       │       │       │
     *                         └───────┴───────┴───────┴───────┘ └───────┴───────┴───────┘
     */
    [MANAGE] = LAYOUT_split_3x6_3_ex2(
        QK_BOOT, RM_PREV, RM_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, _______, KVM_BEEP_OFF, XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX, KC_SYSTEM_SLEEP,
        RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

/*
 * KVM Switch State
 */
static bool kvm_current_pc = false;  // false = PC1, true = PC2

/**
 * Process custom keycodes
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BRACKET_COMPLETE:
            if (record->event.pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;

        case SLACK_COPY_LINK:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_BTN2) SS_DELAY(50) "l");
            }
            break;

        case CAPTURE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI("4"))) SS_DELAY(200) " ");
            }
            break;

        case RECENT_SPACE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_TAB))));
            }
            break;

#ifdef SECRET_ID
        case SEC_ID:
            if (record->event.pressed) {
                SEND_STRING(SECRET_ID);
            }
            break;
#endif

#ifdef SECRET_PW
        case SEC_PW:
            if (record->event.pressed) {
                SEND_STRING(SECRET_PW);
            }
            break;
#endif

        case KVM_TOGGLE:
            if (record->event.pressed) {
                kvm_current_pc = !kvm_current_pc;
                if (kvm_current_pc) {
                    SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL) "2" SS_TAP(X_ENT));
                } else {
                    SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL) "1" SS_TAP(X_ENT));
                }
            }
            break;

        case KVM_BEEP_OFF:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL) "B0");
            }
            break;
    }
    return true;
}

