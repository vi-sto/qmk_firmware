// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define CTL_ESC LCTL_T(KC_ESC)
#define LOW_BS LT(_LOWER, KC_BSPC)
#define RSE_ENT LT(_RAISE, KC_ENT)
#define LG_AREP LGUI_T(QK_AREP)
#define RA_REP  RALT_T(QK_REP)

enum layer_number {
  _QWERTY = 0,
  _GALLIUM,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ - │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤Alt│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            LG_AREP, LOW_BS,  KC_LALT,          KC_SPC,  RSE_ENT, RA_REP
    ),
    [_GALLIUM] = LAYOUT_split_3x6_3(
        _______, KC_B,    KC_L,    KC_D,    KC_C,    KC_V,                               KC_J,    KC_Y,    KC_O,    KC_U,    KC_COMM, _______,
        _______, KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                               KC_P,    KC_H,    KC_A,    KC_E,    KC_I,    KC_SLSH,
        _______, KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,                               KC_K,    KC_F,    KC_QUOT, KC_SCLN, KC_DOT,  _______,
                                            _______, _______, _______,          _______, _______, _______
    ),
    [_LOWER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, KC_EQL,  KC_GRV,
        KC_LCTL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, KC_DLR,
        _______, _______, _______, _______, _______, _______,                            KC_AMPR, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                            _______, _______, _______,          _______, _______, _______
),
    [_RAISE] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_F12,
        KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_HOME, KC_PGUP, KC_INS,  KC_DEL,  KC_PGDN, KC_END,
                                            _______, _______, _______,          _______, _______, _______
),
    [_ADJUST] = LAYOUT_split_3x6_3(
  DF(_QWERTY), DF(_GALLIUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, MS_BTN1, XXXXXXX, MS_BTN2, XXXXXXX, XXXXXXX,
  XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               _______, _______, _______,          _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // make non basic keycode taps possible with mod-tap keys
        case LGUI_T(QK_AREP):
            if (record->tap.count) {
                process_repeat_key(QK_AREP, record);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RALT_T(QK_REP):
            if (record->tap.count) {
                process_repeat_key(QK_REP, record);
                return false;        // Return false to ignore further processing of key
            }
            break;
    }

    return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        // currently for emulated gallium
        // TODO only for unmoded/shifted
        // e.g. ignore ctrl-o to keep vims ctrl-o <-> ctrl-i jumps
        case KC_O: return KC_L;  // For "UE" bigram.
        case KC_L: return KC_O;  // For "EU" bigram.
        case KC_I: return KC_K;  // For "OA" bigram.
        case KC_K: return KC_I;  // For "AO" bigram.
        case KC_S: return KC_W;  // For "RL" bigram.
        case KC_W: return KC_S;  // For "LR" bigram.
        case KC_H: return KC_J;  // For "PH" bigram.
    }

    return KC_TRNS;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        // don't repeat this:
        case LGUI_T(QK_AREP):
        case RALT_T(QK_REP):
            return false;
    }
    return true;
}
