#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _SYMB 1
#define _MOUSE 2
#define _MOVE 3
#define _SHORTCUTS 4
#define _SHORTCUTSMAC 5
#define _UMLAUT 6

enum custom_keycodes { QWERTY = SAFE_RANGE, SYMB, MOUSE, MOVE, ALT_UML_os, ALT_MOVE_to, ALT_HOME_to, MODESWITCH, KC_EURO, KC_SZ, KC_AE, KC_UE, KC_OE };

#define ALT_UML_os LALT_T(KC_F13)
#define ALT_MOVE_to LALT_T(KC_F14)
#define ALT_HOME_to LALT_T(KC_F15)
#define MODESWITCH KC_F15
#define MO_SHORTCUTS KC_F16

enum unicode_names { BANG, IRONY, SNEK, EURO, ae, AE, ue, UE, oe, OE, SZ };

const uint32_t PROGMEM unicode_map[] = {[BANG]  = 0x203D,   // ‽
                                        [IRONY] = 0x2E2E,   // ⸮
                                        [SNEK]  = 0x1F40D,  // 🐍
                                        [EURO] = 0x20AC,  [ae] = 0x00E4, [AE] = 0x00C4, [ue] = 0x00FC, [UE] = 0x00DC, [oe] = 0x00F6, [OE] = 0x00D6, [SZ] = 0x00DF};

#define KC_SNEK X(SNEK)
#define KC_EURO X(EURO)
#define KC_SZ X(SZ)
#define KC_AE XP(ae, AE)
#define KC_UE XP(ue, UE)
#define KC_OE XP(oe, OE)

// Shortcut to make keymap more readable

#define ENTR_SYM LT(_SYMB, KC_ENT)

bool MACMODE = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ergodox(
        LT(_MOUSE, KC_GRV), KC_1,    KC_2,    KC_3,       KC_4,            KC_5,  KC_TRNS,
        KC_TAB,             KC_Q,    KC_W,    KC_E,       KC_R,            KC_T,  MO(_MOVE),
        LGUI_T(KC_ESC),     KC_A,    KC_S,    KC_D,       KC_F,            KC_G,
        KC_LSPO,            KC_Z,    KC_X,    KC_C,       KC_V,            KC_B,  MO_SHORTCUTS,
        KC_CAPSLOCK,        KC_UNDS, KC_RALT, ALT_UML_os, LCTL_T(KC_BSPC),

        KC_HYPR, TG(_MOUSE), KC_TRNS,
        KC_SPC,  ENTR_SYM,   KC_TRNS,

        KC_TRNS,    KC_6,   KC_7,            KC_8,        KC_9,    KC_0,      LT(_MOUSE, KC_MINS),
        MODESWITCH, KC_Y,   KC_U,            KC_I,        KC_O,    KC_P,      KC_EQL,
                    KC_H,   KC_J,            KC_K,        KC_L,    KC_SCLN,   LT(_MOVE, KC_QUOTE),
        KC_MEH,     KC_N,   KC_M,            KC_COMM,     KC_DOT,  KC_SLSH,   KC_RSPC,
                            RCTL_T(KC_BSPC), ALT_MOVE_to, KC_RALT, KC_BSLASH, RGUI_T(KC_ESC),

        MO_SHORTCUTS, MO(_MOVE), KC_TRNS,
        MO(_MOUSE),   ENTR_SYM,  KC_SPC
    ),
    [_SYMB] = LAYOUT_ergodox(
        KC_NUMLOCK, KC_F1,       KC_F2,     KC_F3,   KC_F4,   KC_F5,         KC_TRNS,
        KC_TRNS,    KC_KP_PLUS,  KC_KP_7,   KC_KP_8, KC_KP_9, KC_KP_SLASH,   TO(0),
        KC_TRNS,    KC_MINUS,    KC_KP_4,   KC_KP_5, KC_KP_6, KC_KP_ASTERISK,
        KC_LSHIFT,  KC_TRNS,     KC_KP_1,   KC_KP_2, KC_KP_3, KC_TRNS,       TO(_SYMB),
        KC_TRNS,    KC_KP_ENTER, KC_KP_DOT, KC_P0,   KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_DEL,  KC_TRNS, KC_TRNS,

        KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_TRNS,
        TO(0),     KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR,  KC_PIPE, KC_TAB,
                   KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC,  KC_GRV,  KC_ESCAPE,
        TO(_SYMB), KC_PERC, KC_CIRC, KC_UNDS, KC_MINUS, KC_TILD, KC_RSHIFT,
                            KC_TRNS, KC_HASH, KC_DLR,   KC_EURO, KC_TRNS,

        LCTL(KC_C), LCTL(KC_V), KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
    [_MOUSE] = LAYOUT_ergodox(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, TO(0),
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_MOUSE),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1,

        KC_TRNS, TG(_MOUSE), KC_TRNS,
        KC_BTN1, KC_BTN2,    KC_TRNS,

        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
        TO(0),      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                    KC_NO,   KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_TRNS,
        TO(_MOUSE), KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                             KC_TRNS, KC_END,   KC_PGDN, KC_PGUP,  KC_HOME,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_MOVE] = LAYOUT_ergodox(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_NO,   KC_MUTE, KC_VOLD,     KC_VOLU, KC_NO,   TO(0),
        KC_TRNS, KC_NO,   KC_MPRV, KC_MPLY,     KC_MNXT, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   TO(_MOVE),
        KC_TRNS, KC_TRNS, KC_TRNS, ALT_HOME_to, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS,
        TO(0),     KC_NO,   KC_PGUP, KC_UP,       KC_PGDOWN, KC_NO,   KC_TRNS,
                   KC_NO,   KC_LEFT, KC_DOWN,     KC_RIGHT,  KC_WH_U, KC_TRNS,
        TO(_MOVE), KC_NO,   KC_HOME, KC_NO,       KC_END,    KC_WH_D, KC_TRNS,
                            KC_TRNS, ALT_HOME_to, KC_NO,     KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_SHORTCUTS] = LAYOUT_ergodox(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,       LGUI(KC_UP),   KC_TRNS,        KC_TRNS, KC_TRNS,
                 KC_TRNS, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS,
                          KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_SHORTCUTSMAC] = LAYOUT_ergodox(
        KC_TRNS, LAG(KC_1), LAG(KC_2), LAG(KC_3), LAG(KC_4), LAG(KC_5), KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, LAG(KC_6), LAG(KC_7),    LAG(KC_8),    LAG(KC_9),     LAG(KC_0), KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,      LAG(KC_UP),   KC_TRNS,       KC_TRNS,   KC_TRNS,
                 KC_TRNS,   LAG(KC_LEFT), LAG(KC_DOWN), LAG(KC_RIGHT), KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,   KC_TRNS,
                            KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,   KC_TRNS,

        KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, LAG(KC_ENT), LAG(KC_SPC)
    ),
    [_UMLAUT] = LAYOUT_ergodox(
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_SNEK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
        KC_TRNS,   KC_AE,   KC_SZ,   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSHIFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0),   KC_TRNS, KC_UE,   KC_TRNS, KC_OE,   KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSHIFT,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // OneShot
    switch (keycode) {
        case ALT_UML_os:
            if (record->tap.count && record->event.pressed) {
                layer_on(_UMLAUT);
                set_oneshot_layer(_UMLAUT, ONESHOT_START);
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
            } else {
                unregister_code16(KC_LALT);
            }
            return false;
            break;
        default:
            if (!record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
    }
    // TO
    switch (keycode) {
        case ALT_MOVE_to:
            if (record->tap.count && record->event.pressed) {
                layer_move(_MOVE);
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
            } else {
                unregister_code16(KC_LALT);
            }
            return false;
            break;
        case ALT_HOME_to:
            if (record->tap.count && record->event.pressed) {
                layer_move(_QWERTY);
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
            } else {
                unregister_code16(KC_LALT);
            }
            return false;
            break;
        case MODESWITCH:
            if (!record->event.pressed) {
                MACMODE = !MACMODE;
                set_unicode_input_mode(MACMODE ? UC_MAC : UC_WINC);
            }
            return false;
            break;
        case MO_SHORTCUTS:
            if (record->event.pressed) {
                if (MACMODE) {
                    layer_on(_SHORTCUTSMAC);
                } else {
                    layer_on(_SHORTCUTS);
                }
            } else {
                if (MACMODE) {
                    layer_off(_SHORTCUTSMAC);
                } else {
                    layer_off(_SHORTCUTS);
                }
            }
            return false;
            break;
    }
    return true;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SHORTCUTS:
            if (MACMODE) {
                layer_on(_SHORTCUTSMAC);
            }
            break;
        case _SHORTCUTSMAC:
            layer_off(_SHORTCUTSMAC);
            break;
        default:
            break;
    }
    return state;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case _QWERTY:
        if (MACMODE) ergodox_right_led_1_off();
        else ergodox_right_led_1_on();
        break;
    case _MOVE:
        ergodox_right_led_2_on();
        break;
    case _SYMB:
        ergodox_right_led_3_on();
        break;
    default:
      // none
      break;
  }

};
