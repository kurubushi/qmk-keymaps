/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 @kurubushi

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

// include quantum/quantum_keycodes.h via $(KEYBOARD_OUTPUT)/src/default_keyboard.h
#include QMK_KEYBOARD_H
#include <stdio.h>

// Layers
enum layers {
    L_QWERTY,
    L_DVORAK,
    L_COLMAK,
    L_LOWER,
    L_RAISE,
    L_MOUSE,
    L_ADJUST,
};

// Key codes
enum custom_keycodes {
  MO_LOWR = SAFE_RANGE, // the start of custom keycords which is defined in quantum_keycodes.h.
  MO_RAIS,
  MO_MOUS,
  TG_QWRT,
  TG_DVRK,
  TG_CLMK,
  CUSTOM_KEYCODE_RANGE, // the end of custom keycordes.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,  KC_SPC,    MO_RAIS, MO_LOWR, MO_MOUS
                                      //`--------------------------'  `--------------------------'

  ),

  [L_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,  KC_SPC,    MO_RAIS, MO_LOWR, MO_MOUS
                                      //`--------------------------'  `--------------------------'

  ),

  [L_COLMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,  KC_SPC,    MO_RAIS, MO_LOWR, MO_MOUS
                                      //`--------------------------'  `--------------------------'

  ),

  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD,  KC_GRV, KC_DQUO, KC_QUOT, XXXXXXX,                      KC_PLUS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ESC, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, TG_QWRT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, TG_DVRK, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, TG_CLMK, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

// 何の custom_keycodes が押されているかをメモ
bool memo[CUSTOM_KEYCODE_RANGE - SAFE_RANGE];

bool is_memorized(uint16_t keycode) {
  if (keycode >= SAFE_RANGE || keycode < CUSTOM_KEYCODE_RANGE)
    return memo[keycode - SAFE_RANGE];
  return false;
}

void memorize(uint16_t keycode, bool is_pressed) {
  if (keycode >= SAFE_RANGE || keycode < CUSTOM_KEYCODE_RANGE)
    memo[keycode - SAFE_RANGE] = is_pressed;
  return;
}

// memo に応じて layer を変化
void toggle_layer(void) {
  if (is_memorized(MO_LOWR))
    layer_on(L_LOWER);
  else
    layer_off(L_LOWER);

  if (is_memorized(MO_RAIS))
    layer_on(L_RAISE);
  else
    layer_off(L_RAISE);

  if (is_memorized(MO_MOUS))
    layer_on(L_MOUSE);
  else
    layer_off(L_MOUSE);

  if (layer_state_is(L_LOWER) && layer_state_is(L_RAISE))
    layer_on(L_ADJUST);
  else
    layer_off(L_ADJUST);

  if (is_memorized(TG_QWRT)) {
    layer_clear();
    default_layer_set(1UL<<L_QWERTY);
    layer_on(L_QWERTY);
  }

  if (is_memorized(TG_DVRK)) {
    layer_clear();
    default_layer_set(1UL<<L_DVORAK);
    layer_on(L_DVORAK);
  }

  if (is_memorized(TG_CLMK)) {
    layer_clear();
    default_layer_set(1UL<<L_COLMAK);
    layer_on(L_COLMAK);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MO_LOWR:
  case MO_RAIS:
  case MO_MOUS:
  case TG_QWRT:
  case TG_DVRK:
  case TG_CLMK:
    memorize(keycode, record->event.pressed);
    toggle_layer();
    return false;
  }
  return true;
}
