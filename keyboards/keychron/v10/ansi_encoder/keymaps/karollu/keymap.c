/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "os_detection.h"

enum layers{
    USER1,
    USER2,
    USER3,
    USER4,
    USER5,
    USER6,
    BASE,
    NUM,
    SYM,
    TAP,
    NAV,
    BTN,
    MOUSE,
    MEDIA,
    FUN,
};

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum custom_keycodes {
    U_RDO = SAFE_RANGE,
    U_PST,
    U_CPY,
    U_CUT,
    U_UND,
};


// Tap Dance declarations
enum {
    U_TD_BOOT,
    TD_ESC_LOCK,
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}
// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [U_TD_BOOT] = ACTION_TAP_DANCE_DOUBLE(KC_NO, QK_REBOOT),
    [TD_ESC_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_ESC_LOCK TD(TD_ESC_LOCK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [USER1] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_1,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,    KC_ESC_LOCK,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,    SC_SENT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        QK_LOCK,    KC_LCTL,  KC_LWIN,            SC_LAPO,  KC_SPC,  MO(USER2),                     KC_SPC,             SC_RAPC,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [USER2] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        KC_2,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),

    [USER3] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             KC_DEL,
        KC_3,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,    KC_ESC_LOCK,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,    KC_LCTL,  KC_LOPT,            KC_LCMD,  KC_SPC,  MO(USER2),                     KC_SPC,             KC_RCMD,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [USER4] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        KC_4,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),

    [USER5] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_5,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(USER2),                    KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [USER6] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_6,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(USER2),                    KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [BASE] = LAYOUT_ansi_89(
        KC_MUTE, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA,
        U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA,
        U_NA, U_NA,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  U_NA, U_NA, U_NA, U_NA,
        U_NA, U_NA,  LGUI_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), ALGR_T(KC_K), RCTL_T(KC_L), RGUI_T(KC_SCLN), U_NA, U_NA, U_NA,
        U_NA, U_NA,  KC_Z, ALGR_T(KC_X),  KC_C,    KC_V,   KC_B,      LT(FUN,KC_BSPC), KC_N, KC_M, KC_COMM, LALT_T(KC_DOT), KC_SLSH, U_NA,  U_NA,
        U_NA, U_NA, U_NA,  LT(MEDIA,KC_ESC), LT(NAV,KC_ENT), LT(MOUSE,KC_TAB),LT(NUM,KC_SPC),LT(SYM,KC_DEL), U_NA, U_NA, U_NA),

    [NUM] = LAYOUT_ansi_89(
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LBRC, KC_7,   KC_8, KC_9, KC_RBRC, U_NA, TD(BASE), U_NA, TD(TAP), TD(U_TD_BOOT), _______, _______, _______, _______,
        _______, _______, KC_QUOT, KC_4,   KC_5, KC_6, KC_EQL,  U_NA, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI,  _______, _______, _______,
        _______, _______, KC_GRV,  KC_1,   KC_2, KC_3, KC_BSLS, U_NA,  U_NA, TD(NUM), TD(NAV), KC_ALGR, U_NA, _______,  _______,
        _______, _______, _______, KC_DOT, KC_0, KC_MINS,          U_NA,  U_NA,  _______, _______, _______),

    [SYM] =  LAYOUT_ansi_89(
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_NA, TD(BASE), U_NA, TD(TAP), TD(U_TD_BOOT),  _______, _______, _______, _______,
        _______, _______,KC_DQUO, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI,  _______, _______, _______,
        _______, _______,KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,  U_NA, TD(SYM), TD(MOUSE), KC_ALGR, U_NA, _______,  _______,
        _______, _______, _______, KC_LPRN,KC_RPRN, KC_UNDS,          U_NA,  U_NA,  _______, _______, _______),

    [TAP] =  LAYOUT_ansi_89(
        U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA,
        U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA, U_NA,
        U_NA, U_NA, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, U_NA, U_NA, U_NA, U_NA,
        U_NA, U_NA, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, U_NA, U_NA, U_NA,
        U_NA, U_NA, KC_Z, KC_X, KC_C, KC_V, KC_B,                             LT(FUN,KC_BSPC), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, U_NA,  U_NA,
        U_NA, U_NA, U_NA,  LT(MEDIA,KC_ESC), LT(NAV,KC_ENT), LT(MOUSE,KC_TAB),LT(NUM,KC_SPC),LT(SYM,KC_DEL), U_NA, U_NA, U_NA),

    [NAV] =  LAYOUT_ansi_89(
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, TD(U_TD_BOOT), TD(TAP), U_NA, TD(BASE),  U_NA, U_CPY, U_UND, U_RDO, U_CUT, U_PST, _______, _______, _______, _______,
        _______, _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,      U_NA, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  CW_TOGG,_______, _______, _______,
        _______, _______, U_NA,    KC_ALGR,  TD(NUM), TD(NAV),     U_NA, KC_BSPC, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_INS, _______,  _______,
        _______, _______, _______, KC_DEL, KC_ENT, KC_BSPC,                U_NA,  U_NA,  _______, _______, _______),

    [BTN] =  LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_8,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(USER2),                 KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MOUSE] = LAYOUT_ansi_89(
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, TD(U_TD_BOOT), TD(TAP), U_NA, TD(BASE),  U_NA, U_CPY, U_UND, U_RDO, U_CUT, U_PST, _______, _______, _______, _______,
        _______, _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,      U_NA, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,_______, _______, _______,
        _______, _______, U_NA,    KC_ALGR,  TD(FUN), TD(MEDIA),     U_NA, KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,  _______,
        _______, _______, _______, U_NA, U_NA, U_NA,                     KC_BTN1,  KC_BTN2,  _______, _______, _______),

    [MEDIA] =  LAYOUT_ansi_89(
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, TD(U_TD_BOOT), TD(TAP), U_NA, TD(BASE),  U_NA, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, _______, _______, _______, _______,
        _______, _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,      U_NA, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,_______, _______, _______,
        _______, _______, U_NA,    KC_ALGR,  TD(SYM), TD(MOUSE),     U_NA, KC_MSTP,  NK_TOGG, U_NU, U_NU, U_NU, OU_AUTO, _______,  _______,
        _______, _______, _______, U_NA, U_NA, U_NA,                     KC_MPLY,  KC_MUTE,  _______, _______, _______),

    [FUN] =  LAYOUT_ansi_89(
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, U_NA, TD(BASE), U_NA, TD(TAP), TD(U_TD_BOOT), _______, _______, _______, _______,
        _______, _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, U_NA, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI,  _______, _______, _______,
        _______, _______, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, U_NA,  U_NA, TD(FUN), TD(MEDIA), KC_ALGR, U_NA, _______,  _______,
        _______, _______, _______,KC_APP,KC_SPC,KC_TAB,         U_NA,  U_NA,  _______, _______, _______),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [USER1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [USER2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [USER3] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [USER4] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [USER5] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [USER6] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NUM] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [SYM] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [TAP] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [NAV] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [BTN] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MOUSE] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MEDIA] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [FUN] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif // ENCODER_MAP_ENABLE

const uint16_t PROGMEM KJ_COMBO[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[] = {
    COMBO(KJ_COMBO, KC_ESC),
};

uint16_t os_based_key_code(uint16_t keycode) {
    switch (detected_host_os()) {
        case OS_WINDOWS:
            switch (keycode) {
                    case U_PST: return S(KC_INS);
                    case U_CPY: return C(KC_INS);
                    case U_CUT: return S(KC_DEL);
                    case U_RDO: return C(KC_Y);
                    case U_UND: return C(KC_Z);
                    default: return KC_NO;
            }
        case OS_MACOS:
            switch (keycode) {
                    case U_PST: return LCMD(KC_V);
                    case U_CPY: return LCMD(KC_C);
                    case U_CUT: return LCMD(KC_X);
                    case U_RDO: return SCMD(KC_Z);
                    case U_UND: return LCMD(KC_Z);
                    default: return KC_NO;
            }
        case OS_LINUX:
            switch (keycode) {
                    case U_PST: return KC_PSTE;
                    case U_CPY: return KC_COPY;
                    case U_CUT: return KC_CUT;
                    case U_RDO: return KC_AGIN;
                    case U_UND: return KC_UNDO;
                    default: return KC_NO;
            }
        default:
            switch (keycode) {
                    case U_PST: return S(KC_INS);
                    case U_CPY: return C(KC_INS);
                    case U_CUT: return S(KC_DEL);
                    case U_RDO: return KC_AGIN;
                    case U_UND: return KC_UNDO;
                    default: return KC_NO;
            }
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case U_PST:
    case U_CPY:
    case U_CUT:
    case U_RDO:
    case U_UND:
      if (record->event.pressed) {
        register_code16(os_based_key_code(keycode));
      } else {
        unregister_code16(os_based_key_code(keycode));
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? 6 : 0));
    }
    return false;
}
