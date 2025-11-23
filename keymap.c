#include QMK_KEYBOARD_H

// Definición de capas
enum sofle_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Definición de keycodes personalizados
// enum custom_keycodes {
//     KC_MACRO1 = SAFE_RANGE,
// };

// Configuración de encoders
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_LOWER] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_DOWN, KC_UP),   ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
};
#endif

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * BASE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´¨  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Mayus| A/Sft| S/Ctl| D/Alt| F/GUI|   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  | Enter|
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |  -_  |LShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCtrl| Win  | LAlt | Space| /LOWER  /       \RAISE \  |Space | RAlt | Win  | RCtrl|
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_BASE] = LAYOUT(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
            KC_LSFT, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
            KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                            KC_CAPS, KC_LGUI, KC_LALT, KC_SPC, MO(_LOWER),   MO(_RAISE), KC_SPC, KC_RALT, KC_LGUI, KC_RCTL
            ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  |°  |      |      |      |      |      |                    |      |      |      |  '?  |  ¿¡  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |  ´¨  |  +*  |  }]  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------| RIGHT|  UP  | DOWN | LEFT |      |  {[  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      |  ,;  |  .:  |  -_  |LShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCtrl|      |      |LCtrl | /LOWER  /       \RAISE \  |Space | RAlt |  Del |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(
            KC_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_DEL,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_NUHS,
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, KC_QUOT,
            KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                              KC_CAPS, XXXXXXX, XXXXXXX, KC_LCTL, MO(_LOWER),   MO(_RAISE), KC_SPC, KC_RALT, KC_DEL, XXXXXXX
            ),

    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|  <>  |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |LCtrl | /LOWER  /       \RAISE \  |Space |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(
            KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, MO(_LOWER),   MO(_RAISE), KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX
            ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |LCtrl | /LOWER  /       \RAISE \  |Space |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, MO(_LOWER),   MO(_RAISE), KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX
            ),
};

// Macro personalizada
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case KC_MACRO1:
    //         if (record->event.pressed) {
    //             SEND_STRING("=>");
    //         }
    //         return false;
    // }
    return true;
}

// Gestión de tri-layer (LOWER + RAISE = ADJUST)
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Imagen de 128px x 32px x 72ppp
#ifdef OLED_ENABLE

static const char PROGMEM yka_logo[] = {
    0xC0, 0xC0, 0x40, 0x40, 0xC0, 0xC0,
    0x80, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xC0, 0x40, 0xC0, 0xC0, 0xC0, 0xC0,
    0x40, 0x40, 0x40, 0xC0, 0xC0, 0x00,
    0x00, 0x00, 0xC0, 0xC0, 0x40, 0x40,
    0x40, 0xC0, 0xC0, 0xC0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0x40, 0xC0, 0xC0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0xC0, 0xC0, 0xC0, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0xC0, 0xC0, 0x00, 0x00, 0x00, 0x80,
    0x80, 0xC0, 0xC0, 0xC0, 0x40, 0x40,
    0x40, 0xC0, 0xC0, 0xC0, 0x80, 0x80,
    0x00, 0x00, 0x00, 0xC0, 0xC0, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0xC0, 0xC0, 0xC0, 0x80, 0x00,
    0xC0, 0xC0, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0xC0, 0xC0, 0xC0,
    0x80, 0x00, 0x01, 0x0F, 0x7E, 0xF0,
    0x80, 0x07, 0x1F, 0x7C, 0x70, 0x7E,
    0x0F, 0x0D, 0xEC, 0xFC, 0x3F, 0x07,
    0xE7, 0xE7, 0x24, 0x24, 0x24, 0x27,
    0x27, 0x30, 0x3C, 0x3F, 0x07, 0x01,
    0xE0, 0xF8, 0x3E, 0x0F, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xF0, 0x7E,
    0x1F, 0x03, 0x00, 0x03, 0x1F, 0xFE,
    0xF0, 0x80, 0x00, 0x00, 0xE0, 0xFC,
    0x3E, 0x07, 0x03, 0xF1, 0xF8, 0x1C,
    0x0C, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x07, 0xE7, 0xF8, 0x3E,
    0x07, 0x03, 0xE1, 0xF0, 0x38, 0x18,
    0x18, 0x08, 0x18, 0x18, 0x38, 0xF1,
    0xE1, 0x03, 0x0F, 0x3E, 0xF8, 0xE7,
    0xE7, 0xE4, 0x24, 0x24, 0xE4, 0xE4,
    0xE4, 0xE4, 0x24, 0x24, 0x24, 0x24,
    0x24, 0x24, 0x24, 0x24, 0x24, 0xA5,
    0xE7, 0xE7, 0xE7, 0xE7, 0x24, 0x24,
    0xE4, 0xE4, 0x04, 0xE4, 0xE4, 0x24,
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
    0x24, 0xA5, 0xE7, 0xE7, 0x00, 0x00,
    0x00, 0x07, 0xFF, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0xF8, 0xFF, 0x0F, 0x01,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0xFE, 0xFE, 0x02, 0x1E, 0x7E,
    0xF0, 0xC0, 0x03, 0x0F, 0x3E, 0xF8,
    0xE0, 0x80, 0x80, 0xF0, 0x7E, 0x1F,
    0x83, 0xE0, 0xFC, 0x7E, 0xF6, 0xDE,
    0x9C, 0x18, 0x1F, 0x1F, 0xFC, 0xF0,
    0x83, 0x1F, 0x3E, 0x70, 0xE0, 0xC7,
    0x8F, 0x9C, 0x98, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0xF0, 0xF3,
    0x1F, 0x3E, 0x70, 0xE0, 0xC7, 0x8F,
    0x9C, 0x98, 0x18, 0x10, 0x18, 0x98,
    0x9C, 0xCF, 0xC7, 0xE0, 0x78, 0x3E,
    0x0F, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
    0xFF, 0xFF, 0x03, 0x07, 0x0E, 0x1C,
    0x38, 0x70, 0xE6, 0xCE, 0x8E, 0x1A,
    0x33, 0x63, 0xC1, 0xC0, 0xFF, 0xFF,
    0x00, 0x00, 0x0F, 0x0F, 0x08, 0x0B,
    0x0B, 0x0A, 0x0E, 0x0E, 0x0E, 0x0E,
    0x0E, 0x0B, 0x1B, 0x3B, 0xF1, 0xE0,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01,
};

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Sofle\n-----\nLayer\n"), false);
        switch (get_highest_layer(layer_state)) {
            case _BASE:  oled_write_ln_P(PSTR("BASE"), false); break;
            case _LOWER: oled_write_ln_P(PSTR("LOWER"), false); break;
            case _RAISE: oled_write_ln_P(PSTR("RAISE"), false); break;
            case _ADJUST: oled_write_ln_P(PSTR("SETUP"), false); break;
            default:     oled_write_ln_P(PSTR("Unknown"), false);
        }
    } else {
        oled_write_raw_P(yka_logo, 512);
    }
    return false;
}
#endif
