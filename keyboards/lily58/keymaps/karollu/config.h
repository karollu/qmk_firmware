/*
Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) 2020 Max Drasbeck
 *
 * You are free to:
 *
 *  Share — copy and redistribute the material in any medium or format
 *  Adapt — remix, transform, and build upon the material
 *   for any purpose, even commercially.
 *
 * The licensor cannot revoke these freedoms as long as you follow the license terms.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */
#undef WEAR_LEVELING_LOGICAL_SIZE
#define WEAR_LEVELING_LOGICAL_SIZE 2048 * 8
#undef WEAR_LEVELING_BACKING_SIZE
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)
#define DYNAMIC_KEYMAP_LAYER_COUNT 10

#define MASTER_LEFT

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define QUICK_TAP_TERM 0

#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_INTERVAL           20
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_TIME_TO_MAX        60
#define MOUSEKEY_MAX_SPEED          7
#define MOUSEKEY_WHEEL_DELAY        400
#define MOUSEKEY_WHEEL_INTERVAL     MOUSEKEY_INTERVAL
#define MOUSEKEY_WHEEL_MAX_SPEED    MOUSEKEY_MAX_SPEED
#define MOUSEKEY_WHEEL_TIME_TO_MAX  MOUSEKEY_TIME_TO_MAX

#define TRI_LAYER_LOWER_LAYER 10
#define TRI_LAYER_UPPER_LAYER 11
#define TRI_LAYER_ADJUST_LAYER 12

#define FN_LAYER_TRANSPARENT_KEYS_OFF
#undef OLED_FONT_H
#define OLED_FONT_END 217
#define OLED_DISPLAY_64X128
#define OLED_DISPLAY_WIDTH 64
#define OLED_DISPLAY_HEIGHT 128
#define OLED_FONT_H "glcdfont_lily.c"



#undef RGBLED_NUM
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_HUE_STEP 6
#define RGBLIGHT_SAT_STEP 6
#define RGBLIGHT_VAL_STEP 6
#define RGBLIGHT_SLEEP
#define RGBLED_NUM 10
#define RGBLED_SPLIT { 5, 5 }

