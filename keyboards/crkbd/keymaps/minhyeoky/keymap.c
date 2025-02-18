/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define BASE 0
#define SYMBOL 1
#define L_NAV 2
#define R_NAV 3
#define MANAGE 4

#define WINDOWS C(KC_UP)
#define BRWSR_F G(KC_RBRC)
#define BRWSR_B G(KC_LBRC)
#define BRWSR_P S(C(KC_TAB))
#define BRWSR_N C(KC_TAB)

/*
 * For Yabai
 */
#define SPACE_N C(A(KC_P))
#define SPACE_P C(A(KC_N))
#define DISPY_P A(KC_N)
#define DISPY_N A(KC_P)
#define DISPY_1 C(KC_1)
#define DISPY_2 C(KC_2)
#define DISPY_3 C(KC_3)
#define DISPY_4 C(KC_4)
#define DISPY_5 C(KC_5)

/*
 * Macros
 */
enum custom_keycodes {
    BRACKET_COMPLETE = SAFE_RANGE,

    // Vim
    VIM_CNEXT,
    VIM_CPREV,

    // Slack
    SLACK_COPY_LINK,

    // Mac
    CAPTURE,

    // skhd (yabai - recent space)
    RECENT_SPACE,
};

/*
 * Tap Hold
 */
#define LT_SPC LT(SYMBOL, KC_SPC)
#define ENT_OR_LNAV LT(L_NAV, KC_ENT)
#define LT_RCMD LT(R_NAV, KC_RCMD)
//#define LT_RCMD LT(NAVIGATION, KC_RCMD)
//#define TEST_NAV LT(3, OS_LALT)

/*
 * One Shot Modifiers
 */
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

/*
 * Combos
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
 * Keymaps
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,     KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,                          KC_Y,   KC_U,    KC_I,    KC_O,   KC_SCLN, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_LCTL,    KC_A,    KC_S,   KC_D,   KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,      KC_P, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, OS_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OS_LALT, OS_LGUI, ENT_OR_LNAV,     KC_BSPC,  LT_SPC, LT_RCMD
                                      //`--------------------------'  `--------------------------'

  ),

    [SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LCBR, KC_RCBR,  KC_GRV, KC_TILD,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,                      XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [L_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, DISPY_1, DISPY_2, DISPY_3, DISPY_4, DISPY_5,                      XXXXXXX, KC_7,    KC_8,    KC_9,   XXXXXXX,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, BRWSR_B, BRWSR_P, BRWSR_N, BRWSR_F, WINDOWS,                      XXXXXXX, KC_4,    KC_5,    KC_6,   XXXXXXX,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(MANAGE), _______, RECENT_SPACE, SLACK_COPY_LINK, XXXXXXX, CAPTURE,           XXXXXXX, KC_1,    KC_2,    KC_3,   _______,  KC_0,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, KC_0,    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [R_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, DISPY_1, DISPY_2, DISPY_3, DISPY_4, DISPY_5,                      XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, BRWSR_B, BRWSR_P, BRWSR_N, BRWSR_F, WINDOWS,                      KC_MPRV,VIM_CNEXT,VIM_CPREV, KC_MNXT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______,   XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [MANAGE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, RM_PREV, RM_NEXT, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX, KC_SYSTEM_SLEEP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

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
    }
    return true;
};

