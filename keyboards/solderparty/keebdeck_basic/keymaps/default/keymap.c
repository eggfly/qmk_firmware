// Copyright 2025 Solder Party
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum CUSTOM_KEYCODES {
  KC_SPC2 = SAFE_RANGE,
  KC_SPC3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q,  KC_E,   KC_R, KC_U,   KC_O,
        KC_W,  KC_S,    KC_G,    KC_H,    KC_L,  
        KC_COMM,    KC_D,    KC_T,    KC_Y,  KC_I, 
        KC_A,   KC_P,    KC_RSFT,    KC_ENT,    KC_BSPC, 
        KC_LALT, KC_Z,    KC_V,    KC_B,    _______, 
        KC_SPC, KC_X, KC_C, KC_N, KC_M, 
        _______, KC_LSFT, KC_F, KC_J, KC_K
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, 
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   
        _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, BL_STEP, 
        _______, _______, _______, _______, BL_STEP
    ),
};

// Prevent sending multiple space presses if more than one space dome is pressed at the same time
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t space_press_count = 0;

    switch (keycode) {
        case KC_SPC:
        case KC_SPC2:
        case KC_SPC3:
            if (record->event.pressed) {
                if (space_press_count == 0)
                    register_code(KC_SPC);

                space_press_count++;
            } else {
                space_press_count--;

                if (space_press_count == 0)
                  unregister_code(KC_SPC);
            }
            return false;
    }

    return true;
}
