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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  MACRO_COLON_EQUAL,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |Hy/Tab|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ct/Es|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   \  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   \  | Alt  | GUI  |Lower |Space | Sft/-|Raise |   '  | Left |Right |  '   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {MT(MOD_HYPR, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC},
  {MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_BSLS,              KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS},
  {KC_GRV,               KC_BSLS, KC_LALT, KC_LGUI, LOWER, KC_SPC, SFT_T(KC_MINS), RAISE, KC_QUOT, KC_LEFT, KC_RGHT, KC_QUOT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      | Left |  Up  |Right |Pg Up |      |   =  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | CADwn| Home | Down |  End |Pg Dn |      |ISO ~ |ISO | |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Space |   _  |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
// [_LOWER] = {
//   {KC_TILD,  KC_EXLM,             KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
//   {MOD_LCTL, _______,             KC_LEFT, KC_UP,   KC_RGHT, KC_PGUP, _______, KC_EQL,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
//   {_______,  LGUI(LALT(KC_DOWN)), KC_HOME, KC_DOWN, KC_END,  KC_PGDN, _______, KC_NUHS, KC_NUBS, KC_LBRC, KC_RBRC, _______},
//   {_______,  _______,             _______, _______, _______, KC_SPC,  KC_UNDS, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
// },

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      | Home |  Up  |  End |Pg Up |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | CADwn| Left | Down |Right |Pg Dn |  :=  |  F5  |  F6  |  F7  |  F8  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |DMPLY1|DMPLY2|      |      |      |      |  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Space |   -  |      |   `  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV,  _______,             KC_HOME,         KC_UP,   KC_END,  KC_PGUP, _______,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   _______},
  {KC_LCTL, LGUI(LALT(KC_DOWN)), KC_LEFT,         KC_DOWN, KC_RGHT, KC_PGDN, MACRO_COLON_EQUAL, KC_F5,   KC_F6,  KC_F7,   KC_F8,   KC_QUOT},
  {_______, DYN_MACRO_PLAY1,     DYN_MACRO_PLAY2, _______, _______, _______, _______,           KC_F9,   KC_F10, KC_F11,  KC_F12,  _______},
  {_______, _______,             KC_LALT,         KC_LGUI, _______, KC_SPC,  KC_MINS,           _______, KC_GRV, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   +  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Vol+ | Mute |      |      |Space |      |      |   0  |   .  |   *  |  /   |
 * `-----------------------------------------------------------------------------------'
 */
// [_RAISE] = {
//   {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
//   {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_LBRC, KC_RBRC, KC_BSLS},
//   {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PLUS, KC_MINS},
//   {KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_SPC,  _______, _______, KC_0,    KC_DOT,  KC_ASTR, KC_SLSH}
// },

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Mute |   |  |      |      |      |      |   -  |   +  |   {  |   }  |   [  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Vol+ | Alt  | GUI  |      |Space |   -  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL },
  {KC_MUTE, KC_PIPE, _______, _______, _______, _______, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC},
  {KC_VOLD, KC_VOLU, KC_LALT, KC_LGUI, _______, KC_SPC,  KC_MINS, _______, _______, _______, _______, _______}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | DMSTP|DMREC1|DMREC2|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET,        _______,        DEBUG,          _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______,      _______,        MU_MOD,         AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {DYN_REC_STOP, DYN_REC_START1, DYN_REC_START2, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______,      _______,        _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

static keyrecord_t last_record = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  bool next;
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (IS_LAYER_OFF(_RAISE) && KEYEQ(record->event.key, last_record.event.key) && TIMER_DIFF_16(record->event.time, last_record.event.time) < TAPPING_TERM) {
          register_code(KC_LANG2);
          unregister_code(KC_LANG2);
        }
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (IS_LAYER_OFF(_LOWER) && KEYEQ(record->event.key, last_record.event.key) && TIMER_DIFF_16(record->event.time, last_record.event.time) < TAPPING_TERM) {
          register_code(KC_LANG1);
          unregister_code(KC_LANG1);
        }
      }
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      break;
    case MACRO_COLON_EQUAL:
      if (record->event.pressed) {
        SEND_STRING(":=");
      }
      break;
    default:
      next = true;
  }

  last_record = *record;
  return next;
}