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
#include "os_detection.h"
#include "layer.h"

extern uint8_t is_master;
bool frame = false;
bool krl_anim_sleep = true;
char wpm_str[16];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    DB_TOGG,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
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
static void render_status(void) {
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write(wpm_str, false);
    oled_write_P(PSTR(" w\n"), false);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
      return OLED_ROTATION_0;
  }
  return OLED_ROTATION_270;
}
const char *read_layer_state(void);

static void render_layer(bool invert) {
    oled_write_P(read_layer_state(), invert);
}

const int *render_bongo_cat_anim(void);

bool oled_task_user(void) {
  if (!is_keyboard_master()) {
    render_bongo_cat_anim();
  } else {
    oled_clear();
    render_status();
    render_layer(true);
  }
    return false;
}
#endif // OLED_ENABLE

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
  krl_anim_sleep = true;
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

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}


/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [EXTRA] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)   },
    [NUM] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [TAP] = {  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [NAV] = {  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)  },
    [BTN] = {  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)  },
    [MOUSE] = {  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)  },
    [MEDIA] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [FUN] = {  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [SPEC] = { ENCODER_CCW_CW(LCTL(KC_I), LCTL(KC_O)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
}; */


#if defined(ENCODER_ENABLE) && !defined(ENCODER_MAP_ENABLE)
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
            if (!clockwise) {
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
