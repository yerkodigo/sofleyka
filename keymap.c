#include QMK_KEYBOARD_H

// Definición de capas
enum sofle_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Home Row Mods - Alias para mejor legibilidad
#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LSFT_T(KC_F)
#define HRM_J RSFT_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

// Configuración de encoders optimizada para desarrollo
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),     ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)) },  // Volumen / Zoom
    [_LOWER]  = { ENCODER_CCW_CW(C(KC_Z), C(KC_Y)),     ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)) }, // Undo-Redo / Tabs
    [_RAISE]  = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U),     ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },       // Scroll / Page
    [_ADJUST] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU),     ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },       // Brillo / Media
};
#endif

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * BASE - QWERTY con Home Row Mods Bilaterales (GACS)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´¨  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Mayus| A/GUI| S/Alt| D/Ctl| F/Sft|   G  |-------.    ,-------| H    | J/Sft| K/Ctl| L/Alt| Ñ/GUI| Enter|
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |  -_  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCtrl| Win  | LAlt |Space | /LOWER  /       \RAISE \  |Space | RAlt | Win  | RCtrl|
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_BASE] = LAYOUT(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
            KC_LSFT, HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                      KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN, KC_ENT,
            KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_LOWER), MO(_RAISE), KC_SPC, KC_RALT, KC_RGUI, KC_RCTL
            ),

    /* LOWER - Navegación y Media
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | F11  | F12  |      |      |      |                    | Home | PgDn | PgUp | End  | Ins  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | GUI  | Alt  | Ctrl | Shift|      |-------.    ,-------|  ←   |  ↓   |  ↑   |  →   |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | Mute | Vol- | Vol+ |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /LOWER  /       \RAISE \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(
            KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
            XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXXXXX,
            XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),

    /* RAISE - Símbolos y Números
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  |°  |   !  |   @  |   #  |   $  |   %  |                    |   &  |   /  |   (  |   )  |   =  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ¿   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   <  |   >  |   {  |   }  |   `  |-------.    ,-------|   ´  |   +  |   *  |   -  |   '  |  ¡   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |   [  |   ]  |   (  |   )  |   ~  |-------|    |-------|   ^  |   \  |   |  |   _  |   ?  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /LOWER  /       \RAISE \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(
            KC_GRV,  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                   S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_BSPC,
            XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
            XXXXXXX, KC_NUBS, S(KC_NUBS), KC_QUOT, KC_NUHS, KC_LBRC,                KC_LBRC, KC_RBRC, S(KC_RBRC), KC_SLSH, KC_MINS, S(KC_EQL),
            XXXXXXX, RALT(KC_LBRC), RALT(KC_NUHS), S(KC_8), S(KC_9), RALT(KC_RBRC), XXXXXXX, XXXXXXX, S(KC_LBRC), KC_GRV, S(KC_GRV), S(KC_SLSH), S(KC_MINS), XXXXXXX,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),

    /* ADJUST - Sistema (activada con LOWER + RAISE)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Reset|      |      |      |      |      |                    |      |      |      |      |      | Debug|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Caps |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /LOWER  /       \RAISE \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
            QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),
};

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
        oled_write_P(PSTR("Sof\n-----\nLayer\n"), false);
        switch (get_highest_layer(layer_state)) {
            case _BASE:   oled_write_ln_P(PSTR("BASE"), false); break;
            case _LOWER:  oled_write_ln_P(PSTR("NAV"), false); break;
            case _RAISE:  oled_write_ln_P(PSTR("SYM"), false); break;
            case _ADJUST: oled_write_ln_P(PSTR("SYS"), false); break;
            default:      oled_write_ln_P(PSTR("???"), false);
        }
    } else {
        oled_write_raw_P(yka_logo, 512);
    }
    return false;
}
#endif
