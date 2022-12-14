//#include "ladis.h"
#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT(
		KC_WWW_BACK, KC_UP, KC_WWW_FORWARD, \
		KC_LEFT, KC_DOWN, KC_RIGHT, \
		MO(_FL), KC_WWW_REFRESH, KC_F16, \
		LCTL(KC_LGUI), KC_MUTE),

[_FL] = LAYOUT(
		KC_F17, KC_F18, KC_F19, \
		KC_F20, KC_F21, KC_F22, \
		KC_NO, KC_F23, KC_F24, \
		KC_SYSTEM_SLEEP, KC_MUTE),

[2] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS ),

[3] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise & layer_state_is(_BL)) {
            tap_code(KC_MS_WH_DOWN);
        } else if (clockwise & layer_state_is(_FL)){
			tap_code(KC_MS_WH_DOWN);
        } 
		else if (!clockwise & layer_state_is(_BL)){
            tap_code(KC_MS_WH_UP);
        }
		 else if (!clockwise & layer_state_is(_FL)) {
            tap_code(KC_MS_WH_UP);
		}
    } else if (index == 1) { /* Second encoder */
        if (clockwise & layer_state_is(_BL)) {
            tap_code(KC_AUDIO_VOL_UP);
        } else if (clockwise & layer_state_is(_FL)){
			tap_code(KC_MS_WH_RIGHT);
        } 
		
		else if (!clockwise & layer_state_is(_BL)){
            tap_code(KC_AUDIO_VOL_DOWN);
        }
		else if (!clockwise & layer_state_is(_FL)) {
            tap_code(KC_MS_WH_LEFT);
		}
    }
    return false;
}

