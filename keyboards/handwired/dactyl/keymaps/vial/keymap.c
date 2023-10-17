#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define MOVE 1 // Move and mouse
#define SYMB 2 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,----------------------------------.                  ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  |   '  |
 * `------+------+------+-------------'                  `-------------+------+------+------'
 *        | { [  | ] }  |                                              |   -  |   =  |
 *        --------------',-------------.                ,-------------.`-------------'
 *                       |LSFT_T| LCTL |                | LALT |LSFT_T|
 *                       |KC_ESC|Backsp|                |Space |Enter |
 *                       |      |------'                `------|      |
 *                       `------'                              `------'
 *                              ,-------------.  ,-------------.
 *                              |  Tab | Home |  |  End |  Del |
 *                              |------|------|  |------+------|
 *                              |L1/HAN| ` ~  |  |  GUI |L2/PRI|
 *                              '-------------'  '-------------'
 *                                                                              
 *                                                                              
 */
[BASE] = LAYOUT_dactyl(  // layer 0 : default
        // left hand
          KC_Q,    KC_W,     KC_E,   KC_R,    KC_T,
          KC_A,    KC_S,     KC_D,   KC_F,    KC_G,
          KC_Z,    KC_X,     KC_C,   KC_V,    KC_B,
                KC_LBRC,  KC_RBRC,
                            SFT_T(KC_ESC), CTL_T(KC_BSPC),
                                                         KC_TAB,  KC_HOME,
                                              LT(MOVE, KC_LNG1), KC_GRAVE,
        // right hand
                             KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,
                             KC_H,   KC_J,     KC_K,     KC_L,  KC_SCLN,
                             KC_N,   KC_M,  KC_COMM,   KC_DOT,  KC_QUOT,
                                            KC_MINS,   KC_EQL,
                    ALT_T(KC_SPC), SFT_T(KC_ENT),
            KC_END,  KC_DEL,
           KC_LGUI, LT(SYMB, KC_PSCR)
    ),
/* Keymap 1: Move Layer
 *
 * ,----------------------------------.                  ,----------------------------------.
 * |      |      | MUP  |      |      |                  | Vol+ |      |  Up  |      | PgUp |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * | RESET| MLF  | MDN  | MRT  |      |                  | Mute | Left | Down | Right| PgDn |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |      |      |      |      |      |                  | Vol- | / ?  | \ |  |   ?  |  |   |
 * '------+------+------+-------------'                  `-------------+------+------+------'
 *        |      |      |                                              |  M1  |  M2  |
 *        --------------',-------------.                ,-------------.`-------------'
 *                       |      |      |                |      |      |
 *                       |      |      |                |      |      |
 *                       |      |------'                `------|      |
 *                       `------'                              `------'
 *                              ,-------------.  ,-------------.
 *                              |      |      |  |      |      |
 *                              |------|------|  |------+------|
 *                              |      |      |  |      |      |
 *                              '-------------'  '-------------'
 *                                                                              
 *                                                                              
 */
// Move and Mouse
[MOVE] = LAYOUT_dactyl(
       // left hand
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,
       QK_BOOT, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS,
                KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
       // right hand
                         KC_VOLU, KC_TRNS,   KC_UP, KC_TRNS, KC_PGUP,
                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
                         KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
                                  KC_BTN1, KC_BTN2,
                KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS
),
/* Keymap 2: Symbol Layer
 *
 * ,----------------------------------.                  ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                  |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |
 * |------+------+------+------+------|                  |------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |                  |   ^  |   &  |   *  |   (  |   )  |
 * '------+------+------+-------------'                  `-------------+------+------+------'
 *        |  F11 |  F12 |                                              |      |      |
 *        --------------',-------------.                ,-------------.`-------------'
 *                       |      |      |                |      |      |
 *                       |      |      |                |      |      |
 *                       |      |------'                `------|      |
 *                       `------'                              `------'
 *                              ,-------------.  ,-------------.
 *                              |      |      |  |      |      |
 *                              |------|------|  |------+------|
 *                              |      |      |  |      |      |
 *                              '-------------'  '-------------'
 *                                                                              
 *                                                                              
 */
// SYMBOLS
[SYMB] = LAYOUT_dactyl(
       // left hand
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,
                 KC_F11,  KC_F12,
                                  KC_TRNS, KC_TRNS,
                                           KC_TRNS,  KC_TRNS,
                                           KC_TRNS,  KC_TRNS,
       // right hand
                  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                                  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
	uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};
