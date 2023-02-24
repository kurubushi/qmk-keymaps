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
#define MO_LOWR MO(L_LOWER)
#define MO_RAIS MO(L_RAISE)
#define MO_MOUS MO(L_MOUSE)
#define MO_AJST MO(L_ADJUST)
#define DF_QWRT DF(L_QWERTY)
#define DF_DVRK DF(L_DVORAK)
#define DF_CLMK DF(L_COLMAK)
#define KC_CTAL LCTL(KC_LALT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_MOD1 OSM(KC_MOD1)
#define OS_MOD4 OSM(KC_MOD4)
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTAL OSM(MOD_LCTL | MOD_LALT)

enum custom_keycodes {
  OS_CLR = SAFE_RANGE,
  KC_MOD1,
  KC_MOD4,
  MAC_ON,
  MAC_OFF,
  JIS_ON,
  JIS_OFF,
  CUSTOM_KEYCODE_RANGE // the end of custom_keycodes
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MOD1,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_CTAL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MOD4, KC_LSFT,  KC_SPC,    MO_RAIS, MO_LOWR, MO_MOUS
                                      //`--------------------------'  `--------------------------'

  ),

  [L_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MOD1, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MOD4, KC_LSFT,  KC_SPC,    MO_RAIS, MO_LOWR, MO_MOUS
                                      //`--------------------------'  `--------------------------'

  ),

  [L_COLMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MOD1,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_CTAL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MOD4, KC_LSFT,  KC_SPC,    MO_RAIS, MO_LOWR, MO_MOUS
                                      //`--------------------------'  `--------------------------'

  ),

  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS,  KC_GRV, KC_DQUO, KC_QUOT, KC_TILD,                      KC_PLUS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    MO_AJST, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ESC, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_CAPS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, MO_AJST, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       OS_CTL, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_MOD1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, OS_CTAL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OS_MOD4,  OS_SFT,  OS_CLR,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, MAC_OFF,  MAC_ON, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DB_TOGG, JIS_OFF,  JIS_ON, DF_DVRK, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       EE_CLR, XXXXXXX, XXXXXXX, DF_CLMK, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LSFT,  QK_RBT,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

typedef struct {
  bool macos_mode;
  bool jis_mode;
} settings_t;

settings_t settings = { false, false };

void send_code(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    register_code(keycode);
  }
  else {
    unregister_code(keycode);
  }
}

void send_code_with_shift(uint16_t keycode, keyrecord_t *record) {
  // MEMO: `send_code` does not seem to recognize KC_EXLM and S(KC_1) as Shift+1.
  // `send_code(KC_EXLM)` seems to send just KC_1 without pressed and released Shift key.
  // Therefore, I defined `send_code_without_shift` which sends pressed Shift, keycode, and released Shift.

  bool pressed = get_mods() & MOD_BIT(KC_LSFT);

  if (!pressed) register_code(KC_LSFT);
  send_code(keycode, record);
  if (!pressed) unregister_code(KC_LSFT);
}

void send_code_without_shift(uint16_t keycode, keyrecord_t *record) {
  bool left_pressed = get_mods() & MOD_BIT(KC_LSFT);
  bool right_pressed = get_mods() & MOD_BIT(KC_RSFT);

  if (left_pressed) unregister_code(KC_LSFT);
  if (right_pressed) unregister_code(KC_RSFT);
  send_code(keycode, record);
  if (left_pressed) register_code(KC_LSFT);
  if (right_pressed) register_code(KC_RSFT);
}

bool handle_persistent_default_layer(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  if (!(get_mods() & MOD_MASK_SHIFT)) {
    return true;
  }

  uint8_t layer;

  switch (keycode) {
  case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
    // ref.
    // https://github.com/qmk/qmk_firmware/blob/0.18.8/quantum/quantum_keycodes.h#L46-L47
    // https://github.com/qmk/qmk_firmware/blob/0.18.8/quantum/quantum_keycodes.h#L808-L809
    layer = keycode & 0xFF;
    set_single_persistent_default_layer(layer);
    return false;
  }

  return true;
}

bool handle_oneshot_modifiers(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
  case OS_CLR:
    clear_oneshot_mods();
    return false;
  }

  return true;
}

bool handle_custom_modifiers(uint16_t keycode, keyrecord_t *record) {
  uint16_t code = 0;

  switch (keycode) {
  case KC_MOD1:
    code = settings.macos_mode ? KC_LGUI : KC_LALT;
    break;
  case KC_MOD4:
    code = settings.macos_mode ? KC_LALT : KC_LGUI;
    break;
  }

  if (code) {
    send_code(code, record);
    return false;
  }

  return true;
}

bool handle_settings_change(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
  case MAC_ON:
    settings.macos_mode = true;
    return false;
  case MAC_OFF:
    settings.macos_mode = false;
    return false;
  case JIS_ON:
    settings.jis_mode = true;
    return false;
  case JIS_OFF:
    settings.jis_mode = false;
    return false;
  }

  return true;
}

bool handle_jis_keycode(uint16_t keycode, keyrecord_t *record) {
  if (!settings.jis_mode) {
    return true;
  }

  switch (keycode) {
  case KC_TILD:
    send_code_with_shift(KC_EQL, record); // means +
    return false;
  case KC_GRV:
    send_code_with_shift(KC_LBRC, record); // means {
    return false;
  case KC_AT:
    send_code(KC_LBRC, record);
    return false;
  case KC_CIRC:
    send_code(KC_EQL, record);
    return false;
  case KC_AMPR:
    send_code_with_shift(KC_6, record); // means ^
    return false;
  case KC_ASTR:
    send_code_with_shift(KC_QUOT, record); // means "
    return false;
  case KC_LPRN:
    send_code_with_shift(KC_8, record); // means *
    return false;
  case KC_RPRN:
    send_code_with_shift(KC_9, record); // means (
    return false;
  case KC_MINS:
    if (get_mods() & MOD_MASK_SHIFT) { // means _
      send_code_with_shift(KC_INT1, record);
      return false;
    }
    break;
  case KC_PLUS:
    send_code_with_shift(KC_SCLN, record); // means :
    return false;
  case KC_EQL:
    send_code_with_shift(KC_MINS, record); // means _
    return false;
  case KC_LCBR:
    send_code_with_shift(KC_RBRC, record); // means }
    return false;
  case KC_LBRC:
    send_code(KC_RBRC, record);
    return false;
  case KC_RCBR:
    send_code_with_shift(KC_BSLS, record); // means |
    return false;
  case KC_RBRC:
    send_code(KC_BSLS, record);
    return false;
  case KC_PIPE:
    send_code_with_shift(KC_INT3, record);
    return false;
  case KC_BSLS:
    send_code(KC_INT3, record);
    return false;
  case KC_SCLN:
    if (get_mods() & MOD_MASK_SHIFT) { // means `:` key
      send_code_without_shift(KC_QUOT, record);
      return false;
    }
    break;
  case KC_DQUO:
    send_code_with_shift(KC_2, record); // means @
    return false;
  case KC_QUOT:
    send_code_with_shift(KC_7, record); // means &
    return false;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool process_continued = true;

  process_continued &= handle_persistent_default_layer(keycode, record);
  process_continued &= handle_oneshot_modifiers(keycode, record);
  process_continued &= handle_custom_modifiers(keycode, record);
  process_continued &= handle_settings_change(keycode, record);
  process_continued &= handle_jis_keycode(keycode, record);

  return process_continued;
};
