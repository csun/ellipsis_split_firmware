#include QMK_KEYBOARD_H
#include <print.h>
#include "drivers/oled/oled_driver.h"

enum layers {
	_WIN = 0,
	_MAC,
	_LOWER_WIN,
	_LOWER_MAC,
	_NUM,
	_GAME,
	_SPC
};

enum keycodes {
	KC_CYCLE_SPACE = SAFE_RANGE,
	KC_RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_WIN] = LAYOUT_all(
		KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,   KC_GRV,  KC_7,    KC_8,        KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_PGUP, KC_ESC, KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_END, KC_HOME, KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_PGDN,  KC_DEL, KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
		KC_LCTL,  KC_LGUI, KC_LALT, KC_RAISE, KC_LSFT, MO(_LOWER_WIN), KC_ENT, KC_SPC, KC_BSPC,  MO(_LOWER_WIN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[_LOWER_WIN] = LAYOUT_all(
		KC_TRNS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,        KC_F6,                           TG(_NUM),  KC_F7,    KC_F8,        KC_F9,    KC_F10,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        TO(_MAC), KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    LCTL(KC_PGUP), LCTL(KC_PGDN), KC_TRNS,
		KC_CAPS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_CYCLE_SPACE, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_AUDIO_VOL_UP,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_AUDIO_VOL_DOWN,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
	),
	[_MAC] = LAYOUT_all(
		KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,   KC_GRV,  KC_7,    KC_8,        KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_PGUP, KC_ESC, KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_END, KC_HOME, KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_PGDN,  KC_DEL, KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
		KC_LCTL,  KC_LALT, KC_LGUI, KC_RAISE, KC_LSFT, MO(_LOWER_MAC), KC_ENT, KC_SPC, KC_BSPC,  MO(_LOWER_MAC), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
	),
	[_LOWER_MAC] = LAYOUT_all(
		KC_TRNS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,        KC_F6,                           TG(_NUM),  KC_F7,    KC_F8,        KC_F9,    KC_F10,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        TO(_WIN), KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), KC_TRNS,
		KC_CAPS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_CYCLE_SPACE, KC_TRNS, KC_LEFT,    KC_DOWN,        KC_UP,    KC_RIGHT,    KC_TRNS, KC_TRNS, KC_TRNS,  KC__VOLUP,
		KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC__VOLDOWN,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
	),
	[_NUM] = LAYOUT_all(
		KC_TRNS,   KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_4,    KC_KP_5,        KC_KP_6,   KC_TRNS,  KC_KP_7,    KC_KP_8,        KC_KP_9,    KC_KP_0,    KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    LSFT(LGUI(KC_LBRC)), LSFT(LGUI(KC_RBRC)), KC_TRNS,
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

static uint8_t raise_mod = 0;

void keyboard_post_init_user(void) {
	if(is_keyboard_master()) {
		oled_init(OLED_ROTATION_270);
	}
}

void oled_task_user(void) {
	if(is_keyboard_master()) {
		bool invert = raise_mod || layer_state_is(_LOWER_MAC) || layer_state_is(_LOWER_WIN);
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

bool process_cycle_space(uint16_t keycode, keyrecord_t *record) {
	if(keycode == KC_CYCLE_SPACE && record->event.pressed) {
		if(layer_state_is(_SPC)) {
			layer_off(_SPC);
		}
		else if(layer_state_is(_GAME)) {
			layer_off(_GAME);
			layer_on(_SPC);
		}
		else {
			layer_on(_GAME);
		}
		return false;
	}
	return true;
}

bool process_raise(uint16_t kc, keyrecord_t *record) {
	if(kc == KC_RAISE) {
		if(record->event.pressed) {
			raise_mod = layer_state_is(_WIN) ? MOD_LCTL : MOD_LGUI;
			register_mods(raise_mod);
		}
		else {
			unregister_mods(raise_mod);
			raise_mod = 0;
		}
		return false;
	}

	if (raise_mod) {
		uint8_t new_mod = raise_mod;

		if(layer_state_is(_WIN)) {
			if (kc == KC_Q) {
				uint8_t prev_mods = get_mods();
				clear_mods();
				register_mods(MOD_LALT);

				tap_code(KC_F4);

				clear_mods();
				register_mods(prev_mods);
				return false;
			}
			else if (kc == KC_TAB || kc == KC_SPC) {
				new_mod = MOD_LALT;
			}
			else {
				new_mod = MOD_LCTL;
			}
		}
		else {
			if (kc == KC_SPC ||
				kc == KC_BSPC ||
				kc == KC_LEFT ||
				kc == KC_RIGHT ||
				kc == KC_UP ||
				kc == KC_DOWN) {
				new_mod = MOD_LALT;
			}
			else {
				new_mod = MOD_LGUI;
			}
		}

		if (new_mod != raise_mod) {
			unregister_mods(raise_mod);
			register_mods(new_mod);
			raise_mod = new_mod;
		}
	}

	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
	// If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 

	if(!process_raise(keycode, record)) { return false; }
	if(!process_cycle_space(keycode, record)) { return false; }

  	return true;
}