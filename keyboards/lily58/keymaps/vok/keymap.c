#include QMK_KEYBOARD_H

#define CTL_ESC LCTL_T(KC_ESC)
#define LOW_BS LT(_LOWER, KC_BSPC)
#define RSE_ENT LT(_RAISE, KC_ENT)

// --- considerations and thoughts ---
//#define xxx LT(LGUI, KC_DEL)
//#define xxx LT(RAlt, KC_INS)
//
// need to put üöäß somewhere
//   double tab LAlt = RAlt ???
//
// check out repeat + alt repeat (also for magic)
// maybe on LGUI and RAlt

enum layer_number {
  _QWERTY = 0,
  _GALLIUM,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | / LAlt  /       \Space \  |RAISE | RAlt |      |
 *                   |      |      | BSPC |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_MINS,
  CTL_ESC, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      XXXXXXX, KC_LGUI, LOW_BS,  KC_LALT,           KC_SPC, RSE_ENT, KC_RALT, XXXXXXX
),
/* GALLIUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   B  |   L  |   D  |   C  |   V  |                    |   J  |   Y  |   O  |   U  |   ,  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   N  |   R  |   T  |   S  |   G  |-------.    ,-------|   P  |   H  |   A  |   E  |   I  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   X  |   Q  |   M  |   W  |   Z  |-------|    |-------|   K  |   F  |   ;  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | / LAlt  /       \Space \  |RAISE | RAlt |      |
 *                   |      |      | BSPC |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_GALLIUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______,    KC_B,    KC_L,    KC_D,    KC_C,    KC_V,                      KC_J,    KC_Y,    KC_O,    KC_U, KC_COMM, _______,
  _______,    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                      KC_P,    KC_H,    KC_A,    KC_E, KC_I,    KC_SLSH,
  _______,    KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z, KC_LBRC, KC_RBRC,    KC_K,    KC_F, KC_QUOT, KC_SCLN, KC_DOT,  _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   +  |   -  |   [  |   ]  |   =  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   *  |   (  |   )  |   \  |   $  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   &  |   _  |   {  |   }  |   |  |   ~  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | / LAlt  /       \Space \  |RAISE | RAlt |      |
 *                   |      |      | BSPC |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, KC_EQL,  KC_GRV,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, KC_DLR,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  F1  |  F2  |  F3  |  F4  |  F5  |-------.    ,-------| Left | Down |  Up  |Right | F11  | F12  |
 * |------+------+------+------+------+------|   [   |    | BOOT  |------+------+------+------+------+------|
 * |LShift|  F6  |  F7  |  F8  |  F9  | F10  |-------|    |-------| Home | PgUp |Insert|Delete| PgDn | End  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | / LAlt  /       \Space \  |RAISE | RAlt |      |
 *                   |      |      | BSPC |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_F12,
  KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______, QK_BOOT,   KC_HOME, KC_PGUP, KC_INS,  KC_DEL,  KC_PGDN, KC_END,
                             _______, _______, _______,  _______, _______,   _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QWERTY|COLMAK|      |      |      |      |                    |      |      |      |      |      | BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |MS_BT1|      |MS_BT2|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|MS_LFT|MS_DWN|MS_UP |MS_RHT|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | / LAlt  /       \Space \  |RAISE | RAlt |      |
 *                   |      |      | BSPC |/       /         \      \ |Enter |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  DF(_QWERTY), DF(_GALLIUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, MS_BTN1, XXXXXXX, MS_BTN2, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

/*
 * maybe usefull to show CAPS_WORD state on OLED
void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
    } else {
        // Do something when Caps Word deactivates.
    }
}
*/
