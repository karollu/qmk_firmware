/* Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) 2020 Max Drasbeck
 *
 * You are free to:
 *
 *  Share — copy and redistribute the material in any medium or format
 *  Adapt — remix, transform, and build upon the material
 *   for any purpose, even commercially.
 *
 * The licensor cannot revoke these freedoms as long as you follow the license terms.
 */

#include QMK_KEYBOARD_H
#include "keymap_user.h"
//#include "os_detection.h"
#include "layer.h"

extern uint8_t is_master;
bool frame = false;
bool anim_sleep = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, QK_REP,
  KC_LALT,  __HRA__, __HRR__, __HRS__, __HRT__, KC_G,                      KC_M   , __HRN__, __HRE__, __HRI__, __HRO__,SC_SENT,
  SC_LSPO, KC_Z   , KC_X, KC_C   , KC_D   , KC_V,    KC_NO,   KC_MUTE, KC_K   , KC_H   , KC_COMM, KC_DOT , _HRSLA_, SC_RCPC,
                             GO_SPEC, GOMEDIA, GO__NAV, GOMOUSE,  GO__FUN, GO__NUM, KC_ALGR, KC_DEL
  ),

  [EXTRA] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
  CW_TOGG,  __HRA__, __HRS2_, __HRD__, __HRF__, KC_G   ,                     KC_H   , __HRJ__, __HRK__, __HRL__, HRSCLN_, _______,
  SC_LSPO, KC_Z   , __HRX__, KC_C   , KC_V   , KC_B   ,   KC_NO,   KC_MUTE, KC_N   , KC_M   , KC_COMM, KC_DOT , _HRSLA_, _______,
                             _______, _______, _______, _______,  _______, _______, _______, _______
  ),

  [TAP] = LAYOUT(
  QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC,
  KC_ESC,  KC_A   , KC_R   , KC_S   , KC_T   , KC_G,                      KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , _______,
  SC_LSPO, KC_Z   , __HRX__, KC_C   , KC_D   , KC_V,    KC_NO,   KC_MUTE, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, _______,
                             KC_LALT, KC_ESC , KC_TAB , KC_ENT , KC_BSPC, KC_SPC , KC_ALGR, KC_DEL
  ),

  [BTN] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5, KC_F6,                       KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11, KC_F12,
  KC_TAB,  JS_1   , JS_2   , JS_3   , JS_4   ,  JS_5  ,                      JS_6   , JS_7   , JS_8   , JS_9   , JS_10  , _______,
  KC_ESC,  JS_11  , JS_12  , JS_13  , JS_14  , JS_15  ,                      JS_16  , JS_17  , JS_18  , JS_19  , JS_20  , _______,
  SC_LSPO, JS_21  , JS_22  , JS_23  , JS_24  , JS_25  ,    KC_NO,   KC_MUTE, JS_26  , JS_27  , JS_28  , JS_29  , JS_30  , _______,
                             KC_LALT, JS_25  , JS_6   , JS_24  ,  JS_31  , JS_5   , JS_14  , KC_ALGR
  ),

  [NAV] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  _______, __TAP__, _EXTRA_, _BASE__, KC_NO,                        _COPY__, _UNDO__, _REDO__, __CUT__, _PASTE_, QK_AREP,
  KC_ESC,  KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, CW_TOGG, _______,
  SC_LSPO, _______, KC_ALGR, __NUM__, __NAV__, XXXXXXX,    KC_NO,   KC_MUTE, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS, _______,
                             _______, _______, KC_SPC , KC_ENT,  KC_BSPC, KC_ENT , KC_DEL , KC_ALGR
  ),

  [MOUSE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  _______, __TAP__, _EXTRA_, _BASE__, KC_NO,                     _COPY__, _UNDO__, _REDO__, __CUT__, _PASTE_, _______,
  KC_ESC,  KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, _______,
  SC_LSPO, _______, KC_ALGR, _MEDIA_, __FUN__, XXXXXXX,   KC_NO,   KC_MUTE, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,  _______,
                             _______, _______, KC_SPC , KC_ENT,  KC_BTN3, KC_BTN1, KC_BTN2, KC_ALGR
  ),

  [MEDIA] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  _______, __TAP__, _EXTRA_, _BASE__, KC_NO,                     RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, _______,
  KC_ESC,  KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, KC_ALGR, _______, _MOUSE_, XXXXXXX,    KC_NO,   KC_MUTE, KC_MSTP, NK_TOGG, XXXXXXX, XXXXXXX, OU_AUTO, _______,
                             _______, _______, KC_SPC , KC_ENT,  KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX
  ),

  [FUN] = LAYOUT(
  KC_F13,  KC_F14,    KC_F15,    KC_F16,    KC_F17,    KC_F18,                      KC_F19,    KC_F20,    KC_F21,    KC_F22,    KC_F23,    KC_F24,
  KC_TAB,  KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR,                      _______, _BASE__, _EXTRA_, __TAP__, _______, _______,
  KC_ESC,  KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL,                      _______, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI, _______,
  _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS,    KC_NO,   KC_MUTE, _______, __FUN__, _MEDIA_, KC_ALGR, _______, _______,
                             KC_LALT, KC_APP , KC_SPC , KC_TAB , _______, _______, _______, _______
  ),

  [NUM] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                      _______, _BASE__, _EXTRA_, __TAP__, _______, _______,
  KC_ESC,  KC_QUOT, KC_4   , KC_5   , KC_6   , KC_EQL ,                      _______, KC_RSFT, KC_ALGR, KC_RCTL, KC_RGUI, _______,
  _______, KC_GRV,  KC_1   , KC_2   , KC_3   , KC_BSLS, KC_NO,   KC_MUTE, _______, __NUM__, __NAV__, KC_ALGR, _______, _______,
                             KC_LALT, KC_DOT , KC_0   , KC_MINS, KC_RSFT, _______, _______, _______
  ),

  [SPEC] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,  KC_Q, KC_W   , KC_F   , KC_P   , KC_B,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, _______,
  KC_ESC,  __HRA__, __HRR__, __HRS__, __HRT__, KC_G,                      KC_M   , __HRN__, __HRE__, __HRI__, __HRO__, _______,
  KC_LSFT, KC_Z   , __HRX__, KC_C   , KC_D   , KC_V,    KC_NO,   KC_MUTE, KC_K   , KC_H   , KC_COMM, KC_DOT , _HRSLA_, _______,
                             KC_LALT, GOMEDIA, GO__NAV, GOMOUSE,  GO__FUN, GO__NUM, KC_ALGR, _______
  ),

};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

static void render_logo2(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,192,192,240,112, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,112,112,192,192,192,192,192,  0,  0,128,192,192,254,126,126,127,115,241,240,240,240,128,128,  0,  0,240,240,240,  0,  0,  0,112,112,112,113,113,113,113,113,206,142, 15, 15, 15,127,112,112,240,240,255,143,143,143, 15, 15,  0,  0, 35,115,115,126,126,126,112,112,240,240,240,240,112,112, 15, 15,240,240,240, 14, 14, 14,  1,  1,  1,  1,  1, 15, 14, 14,254,254,254,240,240,128,128,128,142,142,143,243,243,241,  0,  0,  0,  0,
        1,  3,  3,126,126,126,128,128,128,  0,  0,  0,  0,  0, 15, 15, 15, 15, 15,113,113,113,255,255,255,127,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3, 15, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
static void render_logo3(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,128,128,240,112,126, 30, 30, 30, 30, 30, 30, 30, 30, 30,126,112,112,112,112,112,240,128,128,  0,  0,  0,  0,  0,  0,  0,240,240, 63, 31, 31, 28, 60,252,224,224,  0,  0,124,124,  0,128,156, 28, 28, 28, 28, 28,255,243,243,  0,  0,  0,  0,  0,  0,  0,  3,  3,131,254,254,254,231,227,131,131,128,128, 28, 28, 28, 31, 31,156,252,252,252,156,159,  3,  3,  0,  0,  0,  0,248,252,  7,  7,  7, 15,120,224,  0,  0,  0,129,227,227,255,252,248,224,224,224,227,255,255,255,135, 31, 28,252,224,  0,  0,
        0,  0,231,231,255, 60, 60, 60,255,255,255,255,255,255,255,255,255,252,255,255,255, 63, 31,  0,  7,  7,255,248,255,  7,  0,  0,  0,  0,  7,  7, 63, 56, 56, 56, 56, 57, 63,  7,  7,  1,  1,  1,  7,  7, 63, 57, 56, 56, 56, 56, 56,  7,  7,  1,  1,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
static void render_logo(bool invert) {
    static const char PROGMEM data[] = {
        //base
        128,129,129,129,130,
        32, 66, 115,101, 32,
        160,161,161,161,162,0,
        //navi
        128,129,129,129,130,
        32, 78,97,118, 32,
        160,161,161,161,162,0
    };

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(data, invert);
        break;
        case EXTRA:
        case TAP:
        case BTN:
        case NAV:
        case MOUSE:
        case MEDIA:
        case NUM:
        case FUN:
        case SPEC:
        default:
            oled_write_P(data + 16, invert);
    }
}
bool oled_task_user(void) {
  if (!is_keyboard_master()) {
    render_logo(false);
  } else {
    render_logo(true);
    if (frame) {
        render_logo3();
        if (anim_sleep) frame = false;
    } else {
        render_logo2();
        if (anim_sleep) frame = true;
    }
    anim_sleep = false;
  }
    return false;
}
#endif // OLED_ENABLE


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(BASE)) {
        if (index == 0) {
            if (clockwise) {
            // Przesunięcie do przodu
                tap_code16(LCTL(LSFT(KC_TAB)));
            } else {
                tap_code16(LCTL(KC_TAB));

            }
        }
        // Prawy enkoder - regulacja głośności
        else if (index == 1) {
            if (clockwise) {
            // Zwiększenie głośności
            tap_code(KC_VOLU);
            } else {
            // Zmniejszenie głośności
            tap_code(KC_VOLD);
            }
        }
    }
  return false;
}
#endif


// Tap Dance declarations
void u_td_fn_layer(tap_dance_state_t *state, void *user_data) {
  int layer = (int)(intptr_t)user_data;
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << layer);
  }
}

#define ACTION_TAP_DANCE_SET_LAYER(data) \
    { .fn = {NULL, u_td_fn_layer, NULL, NULL}, .user_data = (void *)(intptr_t)data, }
// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [BASE] =  ACTION_TAP_DANCE_SET_LAYER(BASE),
    [EXTRA] =  ACTION_TAP_DANCE_SET_LAYER(EXTRA),
    [NUM] =   ACTION_TAP_DANCE_SET_LAYER(NUM),
    [TAP] =   ACTION_TAP_DANCE_SET_LAYER(TAP),
    [NAV] =   ACTION_TAP_DANCE_SET_LAYER(NAV),
    [BTN] =   ACTION_TAP_DANCE_SET_LAYER(BTN),
    [MOUSE] = ACTION_TAP_DANCE_SET_LAYER(MOUSE),
    [MEDIA] = ACTION_TAP_DANCE_SET_LAYER(MEDIA),
    [FUN] =   ACTION_TAP_DANCE_SET_LAYER(FUN),
    [SPEC] =   ACTION_TAP_DANCE_SET_LAYER(SPEC),
};

uint16_t edit_key_code(uint16_t keycode) {
            switch (keycode) {
                    case U_PST: return S(KC_INS);
                    case U_CPY: return C(KC_INS);
                    case U_CUT: return S(KC_DEL);
                    case U_RDO: return KC_AGIN;
                    case U_UND: return KC_UNDO;
                    default: return KC_NO;
            }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  anim_sleep = true;
  switch (keycode) {
    case U_PST:
    case U_CPY:
    case U_CUT:
    case U_RDO:
    case U_UND:
      if (record->event.pressed) {
        register_code16(edit_key_code(keycode));
      } else                    {
        unregister_code16(edit_key_code(keycode));
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
};

const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM lj_combo[] = {KC_L, KC_J, COMBO_END};
const uint16_t PROGMEM pb_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM kh_combo[] = {KC_K, KC_H, COMBO_END};

combo_t key_combos[] = {
    COMBO(wf_combo, KC_ESC),
    COMBO(fp_combo, KC_DEL),
    COMBO(xc_combo, U_CPY),
    COMBO(cd_combo, U_PST),
    COMBO(lu_combo, KC_BSPC),
    COMBO(uy_combo, SC_SENT),
    COMBO(lj_combo, KC_RBRC),
    COMBO(pb_combo, KC_LBRC),
    COMBO(dv_combo, KC_LPRN),
    COMBO(kh_combo, KC_RPRN),
};
