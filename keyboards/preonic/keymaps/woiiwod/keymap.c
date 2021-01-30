/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _MOVEMENT,
  _SHORTCUTS,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  MOVEMENT,
  SHORTCUTS,
  LOWER,
  RAISE,
  BACKLIT
};


// Tap Dance declarations
enum {
    TD_SCLN_COLN,
    TD_AA,
    TD_AE,
    TD_OE,
    TD_OECOL
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for semicolon, twice for colon
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_AA] = ACTION_TAP_DANCE_DOUBLE(KC_A, RALT(KC_W)),
    [TD_AE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, RALT(KC_Q)),
    [TD_OE] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, RALT(KC_P)),
    [TD_OECOL] = ACTION_TAP_DANCE_DOUBLE(KC_O, RALT(KC_P))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty 0
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | WIN  | Alt  |BACKLI|Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_NO,       KC_1,     KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,      KC_BSPC,
  KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,          KC_I,    KC_O,    KC_P,      KC_DEL,
  LT(3,KC_ESC),TD(TD_AA),KC_S,    KC_D,    LT(2,KC_F),KC_G,    KC_H,    KC_J,          KC_K,    KC_L,    TD(TD_OE), TD(TD_AE),
  KC_LSFT,     KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,          KC_COMM, KC_DOT,  KC_SLSH,   KC_ENT,
  KC_LCTL,     KC_LGUI,  KC_LALT, BACKLIT, MO(4),     KC_SPC,  KC_SPC,  LT(5, KC_ENT), KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT
),

/* Colemak 1
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EscSho|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | WIN  |  Alt |BACKLI|Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_NO,       KC_1,      KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,         KC_BSPC,
  KC_TAB,      KC_Q,      KC_W,    KC_F,    KC_P,       KC_B,    KC_J,    KC_L,          KC_U,    KC_Y,    KC_SCLN,      KC_DEL,
  LT(3,KC_ESC),TD(TD_AA), KC_R,    KC_S,    LT(2,KC_T), KC_G,    KC_M,    KC_N,          KC_E,    KC_I,    TD(TD_OECOL), TD(TD_AE),
  KC_LSFT,     KC_Z,      KC_X,    KC_C,    KC_D,       KC_V,    KC_K,    KC_H,          KC_COMM, KC_DOT,  KC_SLSH,      KC_ENT,
  KC_LCTL,     KC_LGUI,   KC_LALT, BACKLIT, MO(4),      KC_SPC,  KC_SPC,  LT(5, KC_ENT), KC_LEFT, KC_DOWN, KC_UP,        KC_RGHT
),

/* MOVEMENT 2
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |    
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |WDLeft|ScrlUp|ScrlDn|WDRight|     |      |      
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Shift |Layer |      | Left | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = LAYOUT_preonic_grid(
  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,          KC_NO,          KC_NO,           KC_NO,           KC_NO,        KC_NO,
  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   LCTL(KC_LEFT),  LCTL(KC_DOWN),  LCTL(KC_UP),     LCTL(KC_RIGHT),  KC_NO,        KC_NO,
  KC_NO,  KC_NO,  KC_NO,    KC_LSFT, KC_TRNS,  KC_NO,   KC_LEFT,        KC_DOWN,        KC_UP,           KC_RIGHT,        KC_NO,        KC_NO,
  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_HOME,        KC_PGDN,        KC_PGUP,         KC_END,          KC_NO,        KC_NO,
  KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,          KC_NO,          KC_NO,           KC_NO,           KC_NO,        KC_NO
),

/* Shortcuts 3
 * ,-----------------------------------------------------------------------------------.
 * |ACT   |VAX   |      |      |AltF4 |      |      |      |      |      |Restrt|CADEL |    
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |All   |Save  |Deskto|Find  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Undo  |Cut   |Copy  |Paste |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_SHORTCUTS] = LAYOUT_preonic_grid(
  RCS(KC_ESC),  C(KC_F1), KC_NO,    KC_NO,    A(KC_F4),   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, RCS(KC_F10), LCA(KC_DEL),
  KC_NO,        KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,       KC_NO,
  KC_NO,        C(KC_A),  C(KC_S),  C(KC_D),  C(KC_F),    KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,       KC_NO,
  KC_NO,        C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),    KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,       KC_NO,
  KC_NO,        KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,       KC_NO
),


/* Lower 4
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   &  |   /  |  ^   |   (  |   )  |Backsp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   &  |   7  |   8  |   9  |   -  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ?  |      |  (   |   )  |      |      |   4  |   5  |   6  |   +  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  %>% |  <-  |  {[  |  ]}  |      |      |   1  |   2  |   3  |   =  |  ^   |     
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |Adj/O |   .  |   ,  |   %  |End   | 
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM,      KC_AT,      KC_HASH, KC_DLR,    KC_PERC, KC_AMPR,   KC_SLSH,     KC_CIRC, KC_LPRN, KC_RPRN,  KC_BSPC,
  KC_TILD, KC_EXLM,      KC_AT,      KC_HASH, KC_DLR,    KC_PERC, KC_AMPR,   KC_P7,       KC_P8,   KC_P9,   KC_MINUS, KC_SLASH,
  _______, KC_QUES,      KC_NO,      KC_LPRN, KC_RPRN,   KC_NO,   KC_NO,     KC_P4,       KC_P5,   KC_P6,   KC_PLUS,  KC_PAST,
  _______, RCS(KC_M),    A(KC_MINS), KC_LBRC, KC_RBRC,   KC_NO,   KC_NO,     KC_P1,       KC_P2,   KC_P3,   KC_EQUAL, KC_CIRC,
  _______, _______,      _______,    _______, _______,   _______, _______,   LT(6,KC_P0), KC_DOT,  KC_COMM, KC_PERC,  KC_END
),

/* Raise 5
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  |  F12 |      |   "  |   +  |   /  |   *  |   ^  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |  '   |   -  |   =  |   |  |   \  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   F1 |  F2  |  F3  |  F4  |      |  `   |   _  |   ~  |   %  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_F11,    KC_F12,
  _______, KC_F9,    KC_F10,  KC_F11,  KC_F12, KC_NO,    KC_DQUO,  KC_PLUS,  KC_SLSH, KC_ASTR, KC_CIRC,   KC_DEL,
  _______, KC_F5,    KC_F6,   KC_F7,   KC_F8,  KC_NO,    KC_QUOT,  KC_MINS,  KC_EQL,  KC_PIPE, KC_BSLS,   KC_BSLS,
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,  KC_NO,    KC_GRV,   KC_UNDS,  KC_TILD, KC_PERC, KC_NO,     KC_NO,
  _______, _______,  _______, _______, MO(6),  _______,  _______,  KC_TRNS,  KC_MNXT, KC_VOLD, KC_VOLU,   KC_MPLY
),

/* Adjust (Lower + Raise) 6
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|Debug |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MU_MOD|AU_ON |AU_OFF|      |      |Qwerty|Colemk|Numpad|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |MUV_DE|MUV_IN|Mus on|MusOff|MI_ON |MI_OFF|NumLoc|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11, KC_F12,
  KC_NO,   RESET,   DEBUG,    KC_NO,   KC_NO,     KC_NO,   KC_NO,   RGB_M_R, RGB_M_SW, RGB_M_SN,RGB_M_K,KC_DEL,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,     KC_NO,   KC_NO,   QWERTY,  COLEMAK,  KC_NO,   KC_NO,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,    MU_ON,   MU_OFF,    KC_NO,   KC_NO,   KC_NLCK, KC_NO,    KC_NO,   KC_NO,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_TRNS,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,    KC_NO,   KC_NO,  KC_NO
)


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
      }
    return true;
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_AA):
            return 250;
        case TD(TD_AE):
            return 250;
        case TD(TD_OE):
            return 250;
        case TD(TD_OECOL):
            return 250;
        default:
            return TAPPING_TERM;
    }
}



void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
}


#define NUMLOCOFF Q__NOTE(_B5), Q__NOTE(_E5),
#define NUMLOCON Q__NOTE(_E5), Q__NOTE(_B5), Q__NOTE(_E5), Q__NOTE(_B5),


#ifdef AUDIO_ENABLE

float tone_numlk_on[][2]   = SONG(NUMLOCON);
float tone_numlk_off[][2]  = SONG(NUMLOCOFF);

void matrix_init_user(void)
{
    set_voice(default_voice);
    startup_user();
    println("Matrix Init");
}

void led_set_user(uint8_t usb_led)
{
    static uint8_t old_usb_led = 0;

    if (!is_playing_notes())
    {
        if ((usb_led & (1<<USB_LED_NUM_LOCK)) && !(old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                /* If NUM LK LED is turning on... */
                PLAY_SONG(tone_numlk_on);
        }
        else if (!(usb_led & (1<<USB_LED_NUM_LOCK)) && (old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                /* If NUM LED is turning off...  */
                PLAY_SONG(tone_numlk_off);
        }
    }

    old_usb_led = usb_led;
}


#endif /* AUDIO_ENABLE */