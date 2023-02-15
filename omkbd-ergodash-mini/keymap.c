/*
Copyright 2022 @kurubushi
*/

#include QMK_KEYBOARD_H

// Layers
enum layers {
    L_QWERTY,
    L_QWEMAC,
    L_LOWER,
    L_RAISE,
    L_MOUSE,
    L_MOUSEMAC,
    L_ADJUST,
};

// Key codes
#define MO_LOWR MO(L_LOWER)
#define MO_RAIS MO(L_RAISE)
#define MO_MOUS MO(L_MOUSE)
#define MO_MMAC MO(L_MOUSEMAC)
#define MO_AJST MO(L_ADJUST)
#define DF_QWRT DF(L_QWERTY)
#define DF_QMAC DF(L_QWEMAC)
#define KC_CTAL LCTL(KC_LALT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTAL OSM(MOD_LCTL | MOD_LALT)

enum custom_keycodes {
  OS_CLR = SAFE_RANGE,
  CUSTOM_KEYCODE_RANGE // the end of custom_keycodes
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  Alt |   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  |CtlAlt|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||  GUI | Shift| Space|      |||||||       | Raise| Lower| Mouse||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                   XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,                   XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,                   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_CTAL,
    XXXXXXX, XXXXXXX, XXXXXXX,          KC_LGUI, KC_LSFT, KC_SPC,  XXXXXXX, XXXXXXX, MO_RAIS, MO_LOWR, MO_MOUS,          XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* QWERTY for macOS
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  Cmd |   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  |CtlOpt|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||  Opt | Shift| Space|      ||||||||      | Raise| Lower| Mouse||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_QWEMAC] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                   XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,                   XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,                   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_CTAL,
    XXXXXXX, XXXXXXX, XXXXXXX,          KC_LALT, KC_LSFT, KC_SPC,  XXXXXXX, XXXXXXX, MO_RAIS, MO_LOWR, MO_MMAC,          XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |  =   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   \  |   `  |   "  |   '  |   ~  |      |                    |      |   +  |   {  |   [  |   ]  |   }  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |Adjust|      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_LOWER] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                   _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
    _______, KC_BSLS, KC_GRV,  KC_DQUO, KC_QUOT, KC_TILD, _______,                   _______, KC_PLUS, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______,
    _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, MO_AJST, _______, _______,          _______, _______, _______
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   F1 |   F2 |   F3 |   F4 |   F5 |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |Delete|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |      |      |      |                    |      | Left | Down |  Up  | Right|Escape|BSpace|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Home |PgDown| PgUp |  End | Caps |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |      |Adjust|      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ESC,  KC_BSPC,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS, _______,
    _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, _______, MO_AJST, _______,          _______, _______, _______
  ),

  /* Mouse
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |  ↑  |      |      |      |                    |      |      |      | Wh↑ |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Ctrl |      |  ←  |  ↓  |  →  |      |      |                    |      |      |LClick|WClick|RClick|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  Alt |      |      |      |      |      |      |                    |      |      |      | Wh↓ |      |      |CtrAlt|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |||||||| Super| Shift|OsCler|      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
    OS_CTL,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
    OS_ALT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, OS_CTAL,
    XXXXXXX, XXXXXXX, XXXXXXX,          OS_GUI,  OS_SFT,  OS_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Mouse for mac
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |  ↑  |      |      |      |                    |      |      |      | Wh↑ |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Ctrl |      |  ←  |  ↓  |  →  |      |      |                    |      |      |LClick|WClick|RClick|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  Cmd |      |      |      |      |      |      |                    |      |      |      | Wh↓ |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||  Opt | Shift|OsCler|      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_MOUSEMAC] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
    OS_CTL,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
    OS_GUI,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, OS_CTAL,
    XXXXXXX, XXXXXXX, XXXXXXX,          OS_ALT,  OS_SFT,  OS_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Reset|QWERTY|  mac |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Debug|      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |EepRst|      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||     |       | Shift|      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_ADJUST] = LAYOUT(
    RESET,   DF_QWRT, DF_QMAC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_LSFT,  QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
  )
};

void handle_persistent_default_layer(uint16_t keycode) {
  uint8_t layer;

  if (!(get_mods() & MOD_MASK_SHIFT)) {
    return;
  }

  switch (keycode) {
  case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
    // ref.
    // https://github.com/qmk/qmk_firmware/blob/0.18.8/quantum/quantum_keycodes.h#L46-L47
    // https://github.com/qmk/qmk_firmware/blob/0.18.8/quantum/quantum_keycodes.h#L808-L809
    layer = keycode & 0xFF;
    set_single_persistent_default_layer(layer);
  }
}

void handle_oneshot_modifiers(uint16_t keycode) {
  switch (keycode) {
  case OS_CLR:
    clear_oneshot_mods();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  handle_persistent_default_layer(keycode);
  handle_oneshot_modifiers(keycode);

  return true;
};
