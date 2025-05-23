/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
// #include "testKeymap.h"

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
    _GAMING
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSE MO(_MOUSE)
#define GAMING TG(_GAMING)

void pointing_device_init_user(void) {
    // set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6_right(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
    KC_HOME, KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
    KC_DEL, KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, GAMING,
                    KC_END,KC_BSLS,                      KC_LBRC, KC_RBRC, 
                      RAISE, KC_SPC,                      LOWER, 
                      KC_LSFT, KC_BSPC,                   KC_LCTL,
                      KC_TAB, KC_GRV,          KC_LGUI, KC_ENT
                    ),
  // [_QWERTY] = LAYOUT_5x6_right(
  //    KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //    KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
  //    KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //    KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
  //                     KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
  //                                     RAISE,KC_SPC,                                    LOWER,
  //                                     KC_TAB,KC_HOME,                                  KC_DEL,
  //                                     KC_BSPC, KC_GRV,                        KC_LGUI, KC_ENT
  // ),

  [_LOWER] = LAYOUT_5x6_right(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,KC_PGUP,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,_______,KC_HOME,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                     _______,KC_PSCR,                                                        KC_P0, KC_P0,
                                             _______,_______,                _______,
                                             _______,_______,                _______,
                                             _______,_______,        _______,_______

  ),

  [_RAISE] = LAYOUT_5x6_right(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______, KC_UP ,_______,KC_LBRC,                        KC_RBRC,_______,KC_SCLN,KC_INS ,KC_BSLS,KC_MUTE,
       _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                       _______,_______,                                                        KC_EQL ,_______,
                                               _______,_______,                _______,
                                               _______,_______,                _______,
                                               _______,_______,         _______,_______
  ),
  [_MOUSE] = LAYOUT_5x6_right(
     _______,_______, _______ ,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______, _______ , _______ ,_______ ,_______,_______,
     _______,_______,_______,_______,_______ ,_______,                        _______, KC_MS_BTN1 , KC_MS_BTN2 , _______ , SNIPING ,_______,
     _______,_______,_______,_______,_______,_______,                        _______, _______ , _______ , _______ ,_______ ,_______,
                     _______,_______,                                                        DRGSCRL, _______,
                                             _______,_______,                _______,
                                             _______,_______,                _______,
                                             _______,_______,        _______,_______

  ),
  [_GAMING] = LAYOUT_5x6_right(
    KC_BSPC, KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0,  
    KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P,  
    KC_QUOT, KC_HOME, KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, KC_SCLN,  
    KC_BSLS, KC_DEL, KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, GAMING, 
                    KC_LBRC,KC_RBRC,                      KC_LBRC, KC_RBRC, 
                      RAISE, KC_SPC,                      LOWER, 
                      KC_LSFT, KC_BSPC,                   KC_LCTL,
                      KC_TAB, KC_GRV,          KC_LGUI, KC_ENT
                    ),
};
