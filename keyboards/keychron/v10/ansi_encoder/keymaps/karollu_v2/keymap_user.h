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

#pragma once

enum layers {
    QWERTY,
    QWERTY_EXTRA,
    BASE,
    EXTRA,
    TAP,
    BTN,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
    SPEC,
    EMPTY2,
    EMPTY3,
};

enum {
    TD_BASE = BASE,
    TD_EXTRA,
    TD_TAP,
    TD_BTN,
    TD_NAV,
    TD_MOUSE,
    TD_MEDIA,
    TD_NUM,
    TD_SYM,
    TD_FUN,
    TD_SPEC,
    TD_BOOT,
    TD_ESC_LOCK,
};

enum custom_keycodes {
    U_RDO = SAFE_RANGE,
    U_PST,
    U_CPY,
    U_CUT,
    U_UND,
};

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

// double tap
#define _BOOT__ TD(TD_BOOT)
#define __TAP__ TD(TD_TAP)
#define _EXTRA_ TD(TD_EXTRA)
#define _MOUSE_ TD(TD_MOUSE)
#define _BASE__ TD(TD_BASE)
#define __NUM__ TD(TD_NUM)
#define __NAV__ TD(TD_NAV)
#define _MEDIA_ TD(TD_MEDIA)
#define __FUN__ TD(TD_FUN)
#define __SYM__ TD(TD_SYM)
#define __BTN__ TD(TD_BTN)

// go layers
#define GOMEDIA LT(MEDIA,KC_ESC)
#define GO__NAV LT(NAV,KC_TAB)
#define GOMOUSE LT(MOUSE,KC_ENT)
#define GO__FUN LT(FUN,KC_BSPC)
#define GO__NUM LT(NUM,KC_SPC)
#define GO__SYM LT(SYM,KC_DEL)
#define GO_SPEC LT(SPEC,KC_MUTE)

#define _COPY__ U_CPY
#define _UNDO__ U_UND
#define _REDO__ U_RDO
#define __CUT__ U_CUT
#define _PASTE_ U_PST

// Colemak Mod-DH defs
#define __HRA__ LGUI_T(KC_A)
#define __HRR__ LCTL_T(KC_R)
#define __HRS__ LALT_T(KC_S)
#define __HRT__ LSFT_T(KC_T)

#define __HRN__ RSFT_T(KC_N)
#define __HRE__ LALT_T(KC_E)
#define __HRI__ RCTL_T(KC_I)
#define __HRO__ RGUI_T(KC_O)

// QWERTY defs
#define __HRS2_ LCTL_T(KC_S)
#define __HRD__ LALT_T(KC_D)
#define __HRF__ LSFT_T(KC_F)

#define __HRJ__ RSFT_T(KC_J)
#define __HRK__ LALT_T(KC_K)
#define __HRL__ RCTL_T(KC_L)
#define HRSCLN_ RGUI_T(KC_O)

// common
#define _HRSLA_ ALGR_T(KC_SLSH)
#define __HRX__ ALGR_T(KC_X)



