#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
  extern rgblight_config_t rgblight_config;
#endif

// Timer for M_BSPC
static uint16_t timer;

// Layers
#define _CO 0
#define _QW 1
#define _FN 2
#define _AD 3
#define _NP 4
#define _MS 5
enum custom_keycodes {
  M_BSPC = SAFE_RANGE,
  M_RAN64,
  UC_FLIP,
  UC_TABL,
  UC_SHRG,
  UC_DISA,
  UC_DANC,
  UC_SCRE,
  UC_WALL,
  UC_SOB,
  UC_DEAL,
  UC_RAGE,
  UC_NOOO,
  UC_SALU,
};

// Shift when held, Enter when tapped
#define LSEN LSFT_T(KC_ENT)
#define RSEN RSFT_T(KC_ENT)
// RShift when held, Space when tapped
#define RSSP RSFT_T(KC_SPC)
// LShift when held, TAB when tapped
#define LSTAB LSFT_T(KC_TAB)
// _FN layer when held, BACKSPACE when tapped
#define LT_BSPC LT(_FN, KC_BSPC)
// _FN layer when held, DEL when tapped
#define LT_DEL LT(_FN, KC_DEL)
// ALTGR when held, Space when tapped
#define RALSPC RALT_T(KC_SPC)
// Cut/Paste shortcuts
#define PASTE RSFT(KC_INS)
#define CUT LSFT(KC_DEL)
#define COPY LCTL(KC_INS)
// NumPAD when held, ESC when tapped
#define NT_ESC LT(_NP, KC_ESC)
#define LC_CAPS LCTL_T(KC_CAPS)
#define RC_BSLS RCTL_T(KC_BSLS)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CO] = LAYOUT( /* COLEMAK MOD-DH*/
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_LBRC,        KC_RBRC,  KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_INS,  \
    KC_LBRC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_DEL,         KC_GRV,   KC_J,   KC_L,       KC_U,    KC_Y,    KC_SCLN, KC_RBRC, \
    KC_GRV,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_EQL,         KC_MINS,  KC_M,   KC_N,       KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_MINS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   TT(_MS),        KC_BSLS,  KC_K,   KC_H,       KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,  \
    KC_LCTL, KC_INS,  KC_LALT, KC_LGUI, NT_ESC,  LSTAB,  LT_DEL,         LT_BSPC,  RSSP,   KC_ENT,     KC_RGUI, KC_RALT, TT(_AD), KC_RCTL  \
  ),
  [_QW] = LAYOUT( /* QWERTY */
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_E,    KC_R,    KC_T,    _______,       _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
    _______, _______, KC_S,    KC_D,    KC_F,    _______, _______,       _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
    _______, _______, _______, _______, KC_V,    KC_B,    _______,       _______, KC_N,    KC_M,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______  \
  ),
  [_FN] = LAYOUT( /* FUNCTION */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_VOLU,       KC_MNXT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, CUT,     COPY,    KC_WH_U, PASTE,   KC_LBRC, KC_VOLD,       KC_MPRV, KC_RBRC, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, \
    _______, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_GRV,  KC_MUTE,       KC_MPLY, KC_QUOT, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, KC_SLCK, \
    KC_CAPS, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_MINS, M_RAN64,       KC_INS,  KC_EQL,  KC_BTN1, KC_MS_UP,KC_BTN2, KC_INS,  KC_CAPS, \
    KC_CAPS, _______, _______, _______, _______, KC_TAB,  KC_DEL,        KC_BSPC, KC_SPC,  KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, KC_CAPS  \
  ),
  [_AD] = LAYOUT( /* ADJUST */
    _______,    DEBUG,    KC_ACL0,KC_ACL1,KC_ACL2, _______, M_RAN64,      M_RAN64, _______, _______, _______, KC_SLCK, KC_PAUS, KC_PSCR, \
    RGB_M_G,  RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_K, _______, _______,      _______, UC_TABL, KC_BTN1, KC_MS_UP,KC_BTN2, _______, _______, \
    RGB_MOD,  RGB_HUI,  RGB_SAI, RGB_VAI, _______, _______, _______,      _______, UC_SCRE, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, _______, \
    RGB_RMOD, RGB_HUD,  RGB_SAD, RGB_VAD, _______, _______, _______,      _______, UC_SALU, UC_DANC, UC_SHRG, UC_DEAL, _______, KC_CAPS, \
    TG(_QW),  RGB_TOG,  AG_SWAP, _______, _______, TG(_QW), _______,      _______, RGB_TOG, _______, _______, _______, _______, _______  \
  ),
  [_NP] = LAYOUT( /* NUMPAD */ 
    _______, _______,   _______, _______, _______, _______,  _______,     _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______, _______, \
    _______, _______,   _______, _______, _______, _______,  _______,     _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, \
    _______, _______,   _______, _______, _______, _______,  _______,     KC_NLCK, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, \
    _______, _______,   _______, _______, _______, _______,  _______,     _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______, \
    TG(_CO), TG(_QW),   _______, _______, _______, _______,  _______,     _______, _______, KC_PENT, KC_P0,   KC_PDOT, _______, _______  \
  ),
  [_MS] = LAYOUT( /* MOUSE */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_VOLU,       KC_MNXT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, CUT,     COPY,    KC_WH_U, PASTE,   KC_LBRC, KC_VOLD,       KC_MPRV, KC_RBRC, KC_BTN1, KC_MS_UP,KC_BTN2, KC_PGUP, KC_PSCR, \
    _______, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_GRV,  KC_MUTE,       KC_MPLY, KC_QUOT, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, KC_SLCK, \
    KC_CAPS, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_MINS, M_RAN64,       KC_INS,  KC_EQL,  KC_BTN1, KC_MS_UP,KC_BTN2, KC_INS,  KC_CAPS, \
    KC_CAPS, _______, _______, _______, _______, KC_TAB,  KC_DEL,        KC_BSPC, KC_SPC,  KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, KC_CAPS  \
  ),
};

void matrix_init_user(void) { // Runs boot tasks for keyboard
  #ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    //rgblight_sethsv(276,255,170); // Purple
    //rgblight_sethsv(0,0,100); // White
    //rgblight_sethsv(240,255,50); // blue
    rgblight_sethsv_noeeprom(43,100,50); // Goldenrod
    rgblight_mode(13);
  #endif
};

static uint16_t bspc_role;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Our ounky backspace key!
    case M_BSPC:
      if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        bspc_role = KC_ENT;
      } else {
        bspc_role = KC_BSPC;
      }
      if (record->event.pressed) {
        if (timer_elapsed(timer) > TAPPING_TERM) {
          register_code(KC_RSFT);
        } else {
          register_code(bspc_role);
        }
        timer = timer_read();
      } else {
        // Unregister Right Shift if registered
        if (get_mods() & MOD_BIT(KC_RSHIFT)) {
          unregister_code(KC_RSFT);
        }
        // Check if we are into the TAPPING_TERM threshold
        if (timer_elapsed(timer) < TAPPING_TERM) {
          switch (bspc_role) {
            case KC_ENT:
              unregister_code(KC_LSFT);
              register_code(bspc_role);
              register_code(KC_LSFT);
            case KC_BSPC:
              register_code(bspc_role);
          }
        }
        unregister_code(bspc_role);
      }
      return false;
      break;
    case M_RAN64:
      if (record->event.pressed) {
          tap_random_base64();
      }
      return false;
      break;
    #ifdef UNICODE_ENABLE
      case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
        if (record->event.pressed) {
          send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        }
        return false;
        break;
      case UC_TABL: // ┬─┬ノ( º _ ºノ)
        if (record->event.pressed) {
          send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
        }
        return false;
        break;
      case UC_SHRG: // ¯\_(ツ)_/¯
        if (record->event.pressed) {
          send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }
        return false;
        break;
      case UC_DISA: // ಠ_ಠ
        if (record->event.pressed) {
          send_unicode_hex_string("0CA0 005F 0CA0");
        }
        return false;
        break;
      case UC_DANC: // (〜￣△￣)〜
        if (record->event.pressed) {
          send_unicode_hex_string("0028 301C FFE3 25B3 FFE3 0029 301C");
        }
        return false;
        break;
      case UC_SCRE: // ヽ(ﾟДﾟ)ﾉ
        if (record->event.pressed) {
          send_unicode_hex_string("30FD 0028 FF9F 0414 FF9F 0029 FF89");
        }
        return false;
        break;
      case UC_WALL: // ┬┴┬┴┤(･_├┬┴┬┴
        if (record->event.pressed) {
          send_unicode_hex_string("252C 2534 252C 2534 2524 0028 FF65 005F 251C 252C 2534 252C 2534");
        }
        return false;
        break;
      case UC_SOB: // (ಢ⊱ಢ ｡)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0CA2 22B1 0CA2 0020 FF61 0029");
        }
        return false;
        break;
      case UC_DEAL: // ( ∙_∙) ( ∙_∙)>⌐■-■ (⌐■_■)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0020 2219 005F 2219 0029 0020 0028 0020 2219 005F 2219 0029 003E 2310 25A0 002D 25A0 0020 0028 2310 25A0 005F 25A0 0029");
        }
        return false;
        break;
      case UC_RAGE: // （╬ಠ益ಠ)
        if (record->event.pressed) {
          send_unicode_hex_string("FF08 256C 0CA0 76CA 0CA0 0029");
        }
        return false;
        break;
      case UC_NOOO: // (」ﾟﾛﾟ)｣NOOOooooo━
        if (record->event.pressed) {
          send_unicode_hex_string("0028 300D FF9F FF9B FF9F 0029 FF63 004E 004F 004F 004F 006F 006F 006F 006F 006F 2501");
        }
        return false;
        break;
      case UC_SALU: // (￣^￣)ゞ
        if (record->event.pressed) {
          send_unicode_hex_string("0028 FFE3 005E FFE3 0029 309E");
        }
        return false;
        break;
    #endif
  }
  return true;
};

// Change LED colors depending on the layer.
// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
#ifdef RGBLIGHT_ENABLE
  uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
      case _CO:
        //rgblight_sethsv(240,255,rgblight_config.val); // blue
        rgblight_sethsv_noeeprom(43,100,rgblight_config.val); // Goldenrod
        break;
      case _QW:
        rgblight_sethsv(39,255,rgblight_config.val); // Orange
        break;
      case _FN:
        rgblight_sethsv(180,255,rgblight_config.val); // Purple
        break;
      case _AD:
        rgblight_sethsv(0,255,rgblight_config.val); // Red
        break;
    }
    return state;
  };
#endif
