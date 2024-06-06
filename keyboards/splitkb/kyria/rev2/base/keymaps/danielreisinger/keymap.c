#include QMK_KEYBOARD_H
#include "unicode.h"

enum layers {
	L_BASE = 0,
	L_U, // Unicode layer
	L_s, // Special key layer
	L_S, // Special key layer 2
	L_m, // Media layer
	L_M, // Media layer 2
};

enum unicode_names {
	U_a,
	U_A,
	U_o,
	U_O,
	U_u,
	U_U,
	U_s,
	U_S,
	U_EUR,
	U_USD
};

const uint32_t PROGMEM unicode_map[] = {
	[U_a]   =   0xE4, // ä (Latin Small Letter a with Diaeresis)
	[U_A]   =   0xC4, // Ä (Latin Capital Letter a with Diaeresis)
	[U_o]   =   0xF6, // ö (Latin Small Letter O with Diaeresis)
	[U_O]   =   0xD6, // Ö (Latin Capital Letter O with Diaeresis)
	[U_u]   =   0xFC, // ü (Latin Small Letter U with Diaeresis)
	[U_U]   =   0xDC, // Ü (Latin Capital Letter U with Diaeresis)
	[U_s]   =   0xDF, // ß (Latin Small Letter Sharp S)
	[U_S]   = 0x1E9E, // ẞ (Latin Capital Letter Sharp S)
	[U_EUR] = 0x20AC, // € (Euro Sign)
	[U_USD] =   0x24, // $ (Dollar Sign)
};

#define CC_VOLU KC_F13
#define CC_VOLD KC_F14

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT(
KC_ESC,         KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                        KC_Y,   KC_U,    KC_I,    KC_O,   KC_P, XXXXXXX,
LCTL_T(KC_TAB), KC_A, KC_S, KC_D,    KC_F,    KC_G,                                        KC_H,   KC_J,    KC_K,    KC_L,   KC_P, XXXXXXX,
KC_LALT,        KC_Z, KC_X, KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_Q, XXXXXXX,
                            KC_LGUI, MO(L_U), KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_SPC, TT(L_s), MO(L_m)
),

[L_U] = LAYOUT(
_______, _______,      _______, UM(U_EUR), _______, _______,                                     _______, UP(U_u, U_U), _______, UP(U_o, U_O), _______, XXXXXXX,
_______, UP(U_a, U_A), _______, UM(U_USD), _______, _______,                                     _______, _______,      _______, _______,      _______, XXXXXXX,
_______, _______,      _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______,      _______, XXXXXXX,
                                XXXXXXX,   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,      XXXXXXX
),

[L_s] = LAYOUT(
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           _______, XXXXXXX, MO(L_S), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX
),

[L_S] = LAYOUT(
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX
),

[L_m] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, XXXXXXX,
                           XXXXXXX, XXXXXXX, MO(L_M), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
),

[L_M] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, CC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, CC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
)

};

const key_override_t shift_space_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SPC, KC_ENT, ~0, MOD_MASK_CAG);
const key_override_t shift_backspace_override = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0, MOD_MASK_CAG);

const key_override_t **key_overrides = (const key_override_t *[]) {
	&shift_space_override,
	&shift_backspace_override,
	NULL
};
