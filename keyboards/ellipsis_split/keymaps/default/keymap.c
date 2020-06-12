#include QMK_KEYBOARD_H
#include <print.h>
#include "drivers/oled/oled_driver.h"

enum layers {
	_WIN = 0,
	_MAC,
	_FN_WIN,
	_FN_MAC,
	_MED_WIN,
	_MED_MAC,
	_NUM,
	_GAME,
	_SPC
};

enum keycodes {
	KC_CYCLE_SPACE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_WIN] = LAYOUT_all(
		KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,   KC_GRV,  KC_7,    KC_8,        KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_PGUP, KC_ESC, KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_PGDN, KC_DEL, KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_END,  KC_HOME, KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
		KC_LCTL,  KC_LGUI, KC_LALT, MO(_FN_WIN), KC_LSFT, KC_LALT, KC_ENT, KC_SPC, KC_BSPC,  MO(_MED_WIN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[_FN_WIN] = LAYOUT_all(
		KC_TRNS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,        KC_F6,                           TG(_NUM),  KC_F7,    KC_F8,        KC_F9,    KC_F10,    KC_TRNS, KC_TRNS,  KC_TRNS,
		LALT(KC_TAB),   LALT(KC_F4),    LCTL(KC_W),    LCTL(KC_E),    LCTL(KC_R),    LCTL(KC_T), TO(_MAC), KC_TRNS, LCTL(KC_Y),    LCTL(KC_U),        LCTL(KC_I),    LCTL(KC_O),    LCTL(KC_P),    LCTL(KC_PGUP), LCTL(KC_PGDN), LCTL(KC_BSLS),
		KC_CAPS, LCTL(KC_A),    LCTL(KC_S),    LCTL(KC_D),    LCTL(KC_F),    LCTL(KC_G), KC_CYCLE_SPACE, KC_TRNS, LCTL(KC_H),    LCTL(KC_J),        LCTL(KC_K),    LCTL(KC_L),    LCTL(KC_SCLN), LCTL(KC_QUOT), LCTL(KC_ENT),  LCTL(KC_PGUP),
		KC_TRNS,  LCTL(KC_Z),    LCTL(KC_X),    LCTL(KC_C),    LCTL(KC_V),    LCTL(KC_B), KC_TRNS,  KC_TRNS, LCTL(KC_N),   LCTL(KC_M),        LCTL(KC_COMM), LCTL(KC_DOT),  LCTL(KC_SLSH), LCTL(KC_RSFT), LCTL(KC_UP),   LCTL(KC_PGDN),
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_ENT), LALT(KC_SPC), LCTL(KC_BSPC),  KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT)
	),
	[_MED_WIN] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_AUDIO_VOL_UP,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_AUDIO_VOL_DOWN,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
	),
	[_MAC] = LAYOUT_all(
		KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,   KC_GRV,  KC_7,    KC_8,        KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_PGUP, KC_ESC, KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_PGDN, KC_DEL, KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_END,  KC_HOME, KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
		KC_LCTL,  KC_LALT, KC_LGUI, MO(_FN_MAC), KC_LSFT, KC_LGUI, KC_ENT, KC_SPC, KC_BSPC,  MO(_MED_MAC), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[_FN_MAC] = LAYOUT_all(
		KC_TRNS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,        KC_F6,   TG(_NUM),  KC_F7,    KC_F8,        KC_F9,    KC_F10,    KC_TRNS, KC_TRNS,  KC_TRNS,
		LGUI(KC_TAB),   LGUI(KC_Q),    LGUI(KC_W),    LGUI(KC_E),    LGUI(KC_R),    LGUI(KC_T),        TO(_WIN), KC_TRNS, LGUI(KC_Y),    LGUI(KC_U),        LGUI(KC_I),    LGUI(KC_O),    LGUI(KC_P),    LGUI(KC_LBRC), LGUI(KC_RBRC), LGUI(KC_BSLS),
		KC_CAPS, LGUI(KC_A),    LGUI(KC_S),    LGUI(KC_D),    LGUI(KC_F),    LGUI(KC_G), KC_CYCLE_SPACE, KC_TRNS, LGUI(KC_H),    LGUI(KC_J),        LGUI(KC_K),    LGUI(KC_L),    LGUI(KC_SCLN), LGUI(KC_QUOT), LGUI(KC_ENT),  LGUI(KC_PGUP),
		KC_TRNS,  LGUI(KC_Z),    LGUI(KC_X),    LGUI(KC_C),    LGUI(KC_V),    LGUI(KC_B),        KC_TRNS,  KC_TRNS, LGUI(KC_N),   LGUI(KC_M),        LGUI(KC_COMM), LGUI(KC_DOT),  LGUI(KC_SLSH), LGUI(KC_RSFT), LALT(KC_UP),   LGUI(KC_PGDN),
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_ENT), LALT(KC_SPC), LALT(KC_BSPC),  KC_TRNS, KC_TRNS, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT)
	),
	[_MED_MAC] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC__VOLUP,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC__VOLDOWN,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
	),
	[_NUM] = LAYOUT_all(
		KC_TRNS,   KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_4,    KC_KP_5,        KC_KP_6,   KC_TRNS,  KC_KP_7,    KC_KP_8,        KC_KP_9,    KC_KP_0,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[_GAME] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_CYCLE_SPACE, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_F24, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[_SPC] = LAYOUT_all(
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_CYCLE_SPACE, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)
};

void keyboard_post_init_user(void) {
	if(is_keyboard_master()) {
		oled_init(OLED_ROTATION_270);
	}
}

void oled_task_user(void) {
	if(is_keyboard_master()) {
		bool invert = layer_state_is(_FN_WIN) || layer_state_is(_FN_MAC);
		if(layer_state_is(_WIN)) {
			oled_write_ln_P(PSTR("WIN"), invert);
		}
		else {
			oled_write_ln_P(PSTR("MAC"), invert);
		}

		if(layer_state_is(_GAME)) {
			oled_write_ln_P(PSTR("GAME"), invert);
		}
		else if(layer_state_is(_SPC)) {
			oled_write_ln_P(PSTR("SPACE"), invert);
		}
		else {
			oled_write_ln_P(PSTR(" "), invert);
		}

		oled_write_ln_P(PSTR(" "), invert);
		led_t led_state = host_keyboard_led_state();
		oled_write_P(layer_state_is(_NUM) ? PSTR("N") : PSTR(" "), invert);
		oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR(" "), invert);
		oled_write_P(led_state.scroll_lock ? PSTR("S") : PSTR(" "), invert);
	}
}

void matrix_scan_user(void) {
	if(is_keyboard_master()) {
		oled_task();
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case KC_CYCLE_SPACE:
			if(record->event.pressed && layer_state_is(_SPC)) {
				layer_off(_SPC);
			}
			else if(record->event.pressed && layer_state_is(_GAME)) {
				layer_off(_GAME);
				layer_on(_SPC);
			}
			else if (record->event.pressed) {
				layer_on(_GAME);
			}
			break;
		default: break;
	}
#ifdef CONSOLE_ENABLE
	// If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  	return true;
}