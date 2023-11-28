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
    EMPTY1,
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
    TD_BOOT,
    TD_ESC_LOCK,
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

