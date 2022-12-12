#include QMK_KEYBOARD_H

// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  WIN_FN1,
  FN2,
  NAV,
  WIN_NAV
};


#define MO_WNAV MO(WIN_NAV)
#define PREV_DE LGUI(LCTL(KC_LEFT))
#define NEXT_DE LGUI(LCTL(KC_RGHT))
#define ALT_TAB (LALT(KC_TAB))

#define OSM_LSF OSM(MOD_LSFT)
#define OSM_RSF OSM(MOD_RSFT)

enum custom_keycodes {
    M_ALT_T = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_ALT_T:
            if (record->event.pressed) {
               SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT));
            }
            return false;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT, MO(WIN_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     CAPSWRD,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT, MO(WIN_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  CMB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[FN2] = LAYOUT_ansi_68(
     KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     QK_BOOT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[NAV] = LAYOUT_ansi_68(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

[WIN_NAV] = LAYOUT_ansi_68(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  PREV_DE,  _______,  NEXT_DE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

};

const uint16_t PROGMEM lr_shift_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM jo_combo[] = {KC_J, KC_O, COMBO_END};
const uint16_t PROGMEM jio_combo[] = {KC_J, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM km_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM kml_combo[] = {KC_K, KC_M, KC_L, COMBO_END};
const uint16_t PROGMEM kmo_combo[] = {KC_K, KC_M, KC_O, COMBO_END};

const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM jn_combo[] = {KC_J, KC_N, COMBO_END};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fe_combo[] = {KC_F, KC_E, COMBO_END};
const uint16_t PROGMEM fw_combo[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM few_combo[] = {KC_F, KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM sdc_combo[] = {KC_S, KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM dc_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM sc_combo[] = {KC_S, KC_C, COMBO_END};

const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cx_combo[] = {KC_C, KC_X, COMBO_END};

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(lr_shift_combo, KC_CAPS),
    COMBO(jk_combo, KC_ESC),
    COMBO(ji_combo, LCTL(KC_BSPC)),
    COMBO(jo_combo, KC_BSPC),
    COMBO(jio_combo, KC_DEL),
    COMBO(km_combo, KC_ENTER),
    COMBO(kml_combo, LALT(KC_ENTER)),
    COMBO(kmo_combo, LCTL(KC_ENTER)),

    COMBO(fv_combo, OSM(MOD_LSFT)),
    COMBO(jn_combo, OSM(MOD_RSFT)),

    COMBO(df_combo, MO(NAV)),
    COMBO(fe_combo, LCTL(KC_SPC)),
    COMBO(fw_combo, LCTL(KC_DOT)),
    COMBO(few_combo, LALT(KC_INS)),
    COMBO(sdc_combo, KC_TASK),
    COMBO(dc_combo, M_ALT_T),
    COMBO(sc_combo, KC_LGUI),

    COMBO(cv_combo, NEXT_DE),
    COMBO(cx_combo, PREV_DE),

    COMBO(we_combo, KC_UP),
    COMBO(sd_combo, KC_DOWN),
};