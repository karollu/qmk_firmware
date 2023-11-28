/* Copyright 2023 @ karollu
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
#include "keymap_user.h"
#include "os_detection.h"
#include "layer.h"
#include <stdint.h>


// Tap Dance declarations
void u_td_fn_layer(tap_dance_state_t *state, void *user_data) {
  int layer = (int)(intptr_t)user_data;
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << layer);
  }
}

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}
#define ACTION_TAP_DANCE_SET_LAYER(data) \
    { .fn = {NULL, u_td_fn_layer, NULL, NULL}, .user_data = (void *)(intptr_t)data, }
// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_BASE] =  ACTION_TAP_DANCE_SET_LAYER(BASE),
    [TD_EXTRA] =  ACTION_TAP_DANCE_SET_LAYER(EXTRA),
    [TD_NUM] =   ACTION_TAP_DANCE_SET_LAYER(NUM),
    [TD_SYM] =   ACTION_TAP_DANCE_SET_LAYER(SYM),
    [TD_TAP] =   ACTION_TAP_DANCE_SET_LAYER(TAP),
    [TD_NAV] =   ACTION_TAP_DANCE_SET_LAYER(NAV),
    [TD_BTN] =   ACTION_TAP_DANCE_SET_LAYER(BTN),
    [TD_MOUSE] = ACTION_TAP_DANCE_SET_LAYER(MOUSE),
    [TD_MEDIA] = ACTION_TAP_DANCE_SET_LAYER(MEDIA),
    [TD_FUN] =   ACTION_TAP_DANCE_SET_LAYER(FUN),
    [TD_SPEC] =   ACTION_TAP_DANCE_SET_LAYER(SPEC),
    [TD_BOOT] =  ACTION_TAP_DANCE_DOUBLE(KC_NO, QK_REBOOT),
    [TD_ESC_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_1,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,    KC_ESC_LOCK,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,    SC_SENT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        QK_LOCK,    KC_LCTL,  KC_LWIN,            SC_LAPO,  KC_SPC,  MO(QWERTY_EXTRA),                     KC_SPC,             SC_RAPC,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [QWERTY_EXTRA] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        KC_2,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),

    [BASE] =  LAYOUT_ansi_89(
        GO_SPEC, __BTN__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , XXXXXXX, /**/ KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          __HRA__, __HRR__, __HRS__, __HRT__, KC_G   , /**/ XXXXXXX, KC_M   , __HRN__, __HRE__, __HRI__, __HRO__, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          KC_Z   , __HRX__, KC_C   , KC_D   , KC_V   , /**/ XXXXXXX, KC_K   , KC_H   , KC_COMM, KC_DOT , _HRSLA_, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          XXXXXXX, XXXXXXX, GOMEDIA, GO__NAV, GOMOUSE, /**/ GO__FUN, GO__NUM, GO__SYM, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, QK_REP	, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [EXTRA] =  LAYOUT_ansi_89(
        KC_MUTE, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , XXXXXXX, /**/ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          __HRA__, __HRS2_, __HRD__, __HRF__, KC_G   , /**/ XXXXXXX, KC_H   , __HRJ__, __HRK__, __HRL__, HRSCLN_, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          KC_Z   , __HRX__, KC_C   , KC_V   , KC_B   , /**/ XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , _HRSLA_, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          XXXXXXX, XXXXXXX, GOMEDIA, GO__NAV, GOMOUSE, /**/ GO__FUN, GO__NUM, GO__SYM, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            _______, _______, _______, /**/ _______, _______,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [TAP] =  LAYOUT_ansi_89(
        KC_MUTE, _BASE__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , XXXXXXX, /**/ KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , /**/ XXXXXXX, KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , /**/ XXXXXXX, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          XXXXXXX, XXXXXXX, KC_ESC , KC_TAB , KC_ENT , /**/ KC_BSPC, KC_SPC , KC_DEL , XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [BTN] =  LAYOUT_ansi_89(
        KC_MUTE, _BASE__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ JS_1   , JS_2   , JS_3   , JS_4   ,  JS_5  , XXXXXXX, /**/ JS_6   , JS_7   , JS_8   , JS_9   , JS_10  , /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          JS_11  , JS_12  , JS_13  , JS_14  , JS_15  , /**/ XXXXXXX, JS_16  , JS_17  , JS_18  , JS_19  , JS_20  , /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          JS_21  , JS_22  , JS_23  , JS_24  , JS_25  , /**/ XXXXXXX, JS_26  , JS_27  , JS_28  , JS_29  , JS_30  , /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          XXXXXXX, XXXXXXX, JS_25  , JS_6   , JS_24  , /**/ JS_31  , JS_5   , JS_14  , XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [NAV] =  LAYOUT_ansi_89(
        KC_MUTE, _BASE__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _BOOT__, __TAP__, _EXTRA_, _BASE__, XXXXXXX, XXXXXXX, /**/ _COPY__, _UNDO__, _REDO__, __CUT__, _PASTE_, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, /**/ XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, CW_TOGG, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          _______, KC_ALGR, __NUM__, __NAV__, XXXXXXX, /**/ XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS,  /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/          XXXXXXX, XXXXXXX, _______, _______, KC_SPC , /**/ KC_BSPC, KC_ENT , KC_DEL , XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, QK_AREP, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [MOUSE] =  LAYOUT_ansi_89(
        KC_MUTE, _BASE__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _BOOT__, __TAP__, _EXTRA_, _BASE__, XXXXXXX, XXXXXXX, /**/ _COPY__, _UNDO__, _REDO__, __CUT__, _PASTE_, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, /*         */ XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, KC_ALGR, _MEDIA_, __FUN__, XXXXXXX, /*         */ XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, _______, _______, _______, /*         */ KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [MEDIA] =  LAYOUT_ansi_89(
        KC_MUTE, _BASE__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _BOOT__, __TAP__, _EXTRA_, _BASE__, XXXXXXX, XXXXXXX, /**/ RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, /*         */ XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, KC_ALGR, __SYM__, _MOUSE_, XXXXXXX, /*         */ XXXXXXX, KC_MSTP, NK_TOGG, XXXXXXX, XXXXXXX, OU_AUTO, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, _______, _______, _______, /*         */ KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [FUN] =  LAYOUT_ansi_89(
        KC_MUTE, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR, XXXXXXX, /**/ _______, _BASE__, _EXTRA_, __TAP__, _BOOT__, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL, /*         */ XXXXXXX, _______, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS, /*         */ XXXXXXX, _______, __FUN__, _MEDIA_, KC_ALGR, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, KC_APP , KC_SPC , KC_TAB , /*         */ _______, _______, _______, _______, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [NUM] =  LAYOUT_ansi_89(
        KC_MUTE, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC, XXXXXXX, /**/ _______, _BASE__, _EXTRA_, __TAP__, _BOOT__, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_QUOT, KC_4   , KC_5   , KC_6   , KC_EQL , /*         */ XXXXXXX, _______, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_GRV,  KC_1   , KC_2   , KC_3   , KC_BSLS, /*         */ XXXXXXX, _______, __NUM__, __NAV__, KC_ALGR, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, KC_DOT , KC_0   , KC_MINS, /*         */ _______, _______, _______, _______, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [SYM] =  LAYOUT_ansi_89(
        KC_MUTE, _BASE__,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, /**/ _______, _BASE__, _EXTRA_, __TAP__, _BOOT__, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_DQUO, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, /*         */ XXXXXXX, _______, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, /*         */ XXXXXXX, _______, __SYM__, _MOUSE_, KC_ALGR, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, /*         */ _______, _______, _______, _______, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

    [SPEC] =  LAYOUT_ansi_89(
        KC_MUTE, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, XXXXXXX, /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, _______, _______, _______, _______, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, _______, _______, _______, _______, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, _______, _______, _______, /*         */ _______, _______, _______, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            _______, _______, _______, /**/ _______, _______,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

   [EMPTY2] = LAYOUT_ansi_89(
        KC_MUTE, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, XXXXXXX, /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, _______, _______, _______, _______, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, _______, _______, _______, _______, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, _______, _______, _______, /*         */ _______, _______, _______, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            _______, _______, _______, /**/ _______, _______,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),


    [EMPTY3] = LAYOUT_ansi_89(
        KC_MUTE, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, XXXXXXX, /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, _______, _______, _______, _______, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ _______, _______, _______, _______, _______, /*         */ XXXXXXX, _______, _______, _______, _______, _______, /**/ XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,          /**/ XXXXXXX, XXXXXXX, _______, _______, _______, /*         */ _______, _______, _______, XXXXXXX, XXXXXXX, /*         */ XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, /**/                            _______, _______, _______, /**/ _______, _______,                            /*         */ XXXXXXX, XXXXXXX, XXXXXXX ),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [QWERTY_EXTRA] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [EXTRA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [TAP] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [BTN] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [NAV] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MOUSE] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MEDIA] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [NUM] = { ENCODER_CCW_CW(LCTL(KC_I), LCTL(KC_O)) },
    [SYM] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [FUN] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [SPEC] = { ENCODER_CCW_CW(LCTL(KC_I), LCTL(KC_O)) },
    [EMPTY2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [EMPTY3] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif // ENCODER_MAP_ENABLE

const uint16_t PROGMEM QW_COMBO[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    COMBO(QW_COMBO, KC_ESC),
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
        default_layer_set(1UL << (active ? BASE : 0));
    }
    return false;
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("elo");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}
