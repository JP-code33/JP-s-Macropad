// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC, KC_L, KC_D,
        KC_E, KC_M, LCTL(KC_Z)
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_DIRECTION_MAP(KC_VOLU, KC_VOLD)}
};
#else

bool encoder_update_user(uint8_t index, bool clockwise) {
    if(index == 0) {
        if(clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

bool oled_task_user(void) {
    oled_write_P("\n", false);
    oled_write_P(PSTR("         JP\n"), false);
    return false;
}
#endif