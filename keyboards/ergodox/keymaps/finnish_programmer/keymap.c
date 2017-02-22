#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_nordic.h"

#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};
enum macro_id {
    EZVER, TILDE_NO, CIRC_NO, ACUT_NO, GRV_NO
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   [  |   ]  |   4  |   5  |  :   |           |   ;  |   6  |   ?  |   {  |   }  |   =  |   Å    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |  (   |           |   )  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   DEL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  '   |           |   "  |------+------+------+------+------+--------|
 * |  SHIFT |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | SHIFT  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ctrl | left |  dn  |  up  | tg1  |                                       |  tg2  | dn  |  up  | right| ctrl  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | App  | Win  |       | PgDn |  Esc  |
 *                                        | Alt  |      |       |      |  Ctrl |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgDn |       |      |
 *                                 | Space| Bspc |------|       |------|  Tab  |Enter |
 *                                 |      |      | Home |       | End  |       |      |
 *                                 `--------------------'       `---------------------'
 */
  [0] = KEYMAP(
    // left hand
    KC_ESCAPE,        KC_1,     NO_LBRC,      NO_RBRC,      KC_4,         KC_5,       NO_COLN,
    KC_TAB,           KC_Q,     KC_W,         KC_E,         KC_R,         KC_T,       NO_LPRN,
    KC_DELETE,  SFT_T(KC_A),    KC_S,         KC_D,         KC_F,         KC_G,
    KC_LSHIFT,    CTL_T(KC_Z),    KC_X,         KC_C,         KC_V,         KC_B,       KC_BSLS,
    KC_LCTL,          KC_LEFT,  KC_DOWN,      KC_UP,        TG(1),
                                                                    ALT_T(KC_APPLICATION),    KC_LGUI,
                                                                                              KC_HOME,
                                                              KC_SPACE,   KC_BSPACE,    ALT_T(KC_HOME),

    // right hand
    NO_SCLN,          KC_6,     NO_QUES,      NO_LCBR,      NO_RCBR,      NO_EQL,       NO_AM,
    NO_RPRN,          KC_Y,     KC_U,         KC_I,         KC_O,         KC_P,       NO_BSLS,
                      KC_H,     KC_J,         KC_K,         KC_L,   SFT_T(NO_OSLH),   NO_AE,
    NO_QUO2,          KC_N,     KC_M,         KC_COMMA,     KC_DOT, CTL_T(KC_PSLS),   KC_RSHIFT,
                                TG(2),        KC_DOWN,      KC_UP,        KC_RIGHT,   KC_LCTL,
      KC_PGUP,  CTL_T(KC_ESCAPE),
      KC_PGDOWN,
ALT_T(KC_END),        KC_TAB,   KC_ENTER
  ),

  [1] = KEYMAP(
    // left hand
    M(EZVER),             KC_F1,    KC_F2,        KC_F3,        KC_F4,        KC_F5,      _______,
    _______,          KC_EXLM,  NO_AT,        NO_LCBR,      NO_RCBR,      NO_PIPE,    _______,
    _______,          KC_HASH,  NO_DLR,       NO_LPRN,      NO_RPRN,      KC_FN7,
    _______,          KC_PERC,  NO_CIRC,      NO_LBRC,      NO_RBRC,      M(1),     _______,
    _______,          _______,  _______,      _______,      _______, 
                                                                          _______,          _______,
                                                                                            _______,
                                                              _______,    _______,          _______,
    // right hand
    _______,          KC_F6,    KC_F7,        KC_F8,        KC_F9,        KC_F10,         KC_F11,
    _______,          NO_AMPR,  KC_1,         KC_2,         KC_3,         KC_KP_PLUS,     KC_F12,
                      NO_PIPE,  KC_4,         KC_5,         KC_6,         KC_KP_MINUS,    _______,
    M(CIRC_NO),       KC_EXLM,  KC_7,         KC_8,         KC_9,         KC_KP_ASTERISK, _______,
                                _______,      KC_0,         KC_DOT,       KC_KP_SLASH,    _______,
      _______,        _______,
      _______,
      _______,        _______,  _______
  ),

  [2] = KEYMAP(
    _______,          _______,  _______,      _______,      _______,      _______,      _______,
    _______,          _______,  KC_MS_BTN1,   KC_MS_UP,     KC_MS_BTN2,   KC_MS_ACCEL0, _______,
    _______,          _______,  KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT,  KC_MS_ACCEL1,
    _______,          _______,  LCTL(KC_X),   LCTL(KC_C),   LCTL(KC_V),   KC_MS_ACCEL2, _______,
    _______,          _______,  _______,      _______,      _______,
                                                                          _______,          _______,
                                                                                            _______,   
                                                          _______,        _______,          _______,

    _______,      _______,            _______,    _______,            _______,        _______,        _______,
    _______, LCTL(KC_W),         LCTL(KC_LEFT),   KC_UP,         LCTL(KC_RIGHT),      _______,        _______,
                  KC_HOME,            KC_LEFT,    KC_DOWN,            KC_RIGHT,       KC_END,         _______,
    _______, LSFT(KC_HOME), LCTL(LSFT(KC_LEFT)),  KC_PGUP,  LCTL(LSFT(KC_RIGHT)),LSFT(KC_END),        _______,
                                      _______,    KC_PGDOWN,          _______,        _______,        _______,
                                                                          _______,          _______,
                                                                                            _______,
                                                          _______,        _______,          _______
),

};



const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_MODS_ONESHOT(MOD_LSFT),  // Sticky shift light. Tap for the next keypress to be shifted. Hold for regular shift.
    [2] = ACTION_MACRO(TILDE_NO), // Completed ~ character(pc and mac), no space needed.
    [3] = ACTION_MACRO(CIRC_NO), // Completed ^ character, no space needed.
    [4] = ACTION_MACRO(ACUT_NO), // Completed ´ character, no space needed.
    [5] = ACTION_MACRO(GRV_NO), // Completed ` character, no space needed.
};

//const uint16_t PROGMEM fn_actions[] = {
//  [1] = ACTION_LAYER_TAP_TOGGLE(1)
//};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case EZVER:
          if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          }
        break;
        case TILDE_NO:
            return (record->event.pressed ? MACRO( D(RALT), T(RBRC), U(RALT), T(SPC), END ) : MACRO_NONE);
        case CIRC_NO:
            return (record->event.pressed ? MACRO( D(LSFT), T(RBRC), U(LSFT), T(SPC), END ) : MACRO_NONE);
        case ACUT_NO:
            return (record->event.pressed ? MACRO( D(RALT), T(EQL), U(RALT), T(SPC),  END ) : MACRO_NONE);
        case GRV_NO:
            return (record->event.pressed ? MACRO( D(LSFT), T(EQL), T(SPC), U(LSFT),  END ) : MACRO_NONE);
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
