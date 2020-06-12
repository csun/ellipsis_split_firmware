#include QMK_KEYBOARD_H
#include <print.h>
#include "drivers/oled/oled_driver.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(
		KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP, KC_ESC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN, KC_DEL, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_HOME, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
		KC_LCTL,  KC_LGUI, KC_LALT, KC_LGUI, KC_LSFT, KC_LALT, KC_ENT, KC_SPC, KC_BSPC,  KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
	)
};

void keyboard_post_init_user(void) {
	if(is_keyboard_master()) {
		oled_init(OLED_ROTATION_270);

		oled_clear();
		for(uint8_t i = 0; i < 4; i++) {
			for(uint8_t j = 0; j < 4; j++) {
				oled_set_cursor(i, j);
				oled_write_char('B', false);
			}
		}
		oled_render();
	}
}

void oled_task_user(void) {
	for(uint8_t i = 0; i < 4; i++) {
		for(uint8_t j = 0; j < 4; j++) {
			oled_set_cursor(i, j);
			oled_write_char('D', false);
		}
	}
}

void matrix_scan_user(void) {
	if(is_keyboard_master()) {
		oled_task();
	}
}

#ifdef CONSOLE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  	return true;
}
#endif 