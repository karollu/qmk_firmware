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

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 2

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


// Underglow
/*
#undef RGBLED_NUM
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_SLEEP
*/
