#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _SYMB 2
#define _MOUSE 3
#define _MOVE 4
#define _SHORTCUTS 5
#define _UMLAUT 6
#define _UMLAUTclmk 7

enum custom_keycodes { QWERTY = SAFE_RANGE, SYMB, MOUSE, MOVE, ALT_UML_os, ALT_MOVE_to, ALT_HOME_to, KC_EURO, KC_SZ, KC_AE, KC_UE, KC_OE };

#define ALT_UCLMK_os LALT_T(KC_F14)
#define ALT_UML_os LALT_T(KC_F13)
#define ALT_MOVE_to LALT_T(KC_F12)
#define ALT_HOME_to LALT_T(KC_F11)

enum unicode_names { BANG, IRONY, SNEK, EURO, ae, AE, ue, UE, oe, OE, SZ };

const uint32_t PROGMEM unicode_map[] = {[BANG]  = 0x203D,   // ‽
                                        [IRONY] = 0x2E2E,   // ⸮
                                        [SNEK]  = 0x1F40D,  // 🐍
                                        [EURO] = 0x20AC,  [ae] = 0x00E4, [AE] = 0x00C4, [ue] = 0x00FC, [UE] = 0x00DC, [oe] = 0x00F6, [OE] = 0x00D6, [SZ] = 0x00DF};

#define KC_EURO X(EURO)
#define KC_SZ X(SZ)
#define KC_AE XP(ae, AE)
#define KC_UE XP(ue, UE)
#define KC_OE XP(oe, OE)

// Shortcut to make keymap more readable

#define ENTR_SYM LT(_SYMB, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        LT(_MOUSE, KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(_MOUSE, KC_MINS),
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MO(_MOVE), DF(_COLEMAK), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, MO(_SHORTCUTS), KC_MEH, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LEFT, KC_RIGHT, KC_DOWN, KC_UP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_CAPSLOCK, KC_UNDS, KC_RALT, ALT_UML_os, KC_LGUI, KC_BSPACE, ENTR_SYM, ENTR_SYM, KC_SPC, KC_RGUI, ALT_MOVE_to, KC_RALT, KC_BSLASH, CTL_T(KC_ESC)
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),
    [_COLEMAK] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TRNS, DF(_QWERTY), KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_A, KC_R, KC_S, KC_T, KC_D, KC_TRNS, KC_TRNS, KC_H, KC_N, KC_E, KC_I, KC_O, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, ALT_UCLMK_os, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),
    [_SYMB] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NUMLOCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_KP_PLUS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH, TO(0), TO(0), KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TAB,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, TO(_SYMB), TO(_SYMB), KC_HASH, KC_DLR, KC_LBRC, KC_RBRC, KC_GRV, KC_ESCAPE,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSHIFT, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_C), LCTL(KC_V), KC_PERC, KC_CIRC, KC_UNDS, KC_MINUS, KC_TILD, KC_RSHIFT,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_KP_ENTER, KC_KP_DOT, KC_P0, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_HASH, KC_DLR, KC_EURO, KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_MOUSE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_TRNS, TO(0), TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, TO(_MOUSE), TO(_MOUSE), KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_PGUP, KC_HOME
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_MOVE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, TO(0), TO(0), KC_NO, KC_PGUP, KC_UP, KC_PGDOWN, KC_NO, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, TO(_MOVE), TO(_MOVE), KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, ALT_HOME_to, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ALT_HOME_to, KC_NO, KC_TRNS, KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_SHORTCUTS] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCS(KC_UP), KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCS(KC_LEFT), RCS(KC_DOWN), RCS(KC_RIGHT), KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCS(KC_ENT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_UMLAUT] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), TO(0), KC_TRNS, KC_UE, KC_TRNS, KC_OE, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_AE, KC_SZ, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSHIFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSHIFT,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),
    [_UMLAUTclmk] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), TO(0), KC_TRNS, KC_UE, KC_TRNS, KC_OE, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_AE, KC_TRNS, KC_SZ, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSHIFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSHIFT,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // OneShot
    switch (keycode) {
        case ALT_UML_os:
            if (record->tap.count && record->event.pressed) {
                layer_on(_UMLAUT);
                set_oneshot_layer(_UMLAUT, ONESHOT_START);
                return false;
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
                return false;
            } else {
                unregister_code16(KC_LALT);
                return false;
            }
            break;
        case ALT_UCLMK_os:
            if (record->tap.count && record->event.pressed) {
                layer_on(_UMLAUTclmk);
                set_oneshot_layer(_UMLAUTclmk, ONESHOT_START);
                return false;
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
                return false;
            } else {
                unregister_code16(KC_LALT);
                return false;
            }
            break;
        default:
            if (!record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
    }
    // TO
    switch (keycode) {
        case ALT_MOVE_to:
            if (record->tap.count && record->event.pressed) {
                layer_move(_MOVE);
                return false;
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
                return false;
            } else {
                unregister_code16(KC_LALT);
                return false;
            }
            break;
        case ALT_HOME_to:
            if (record->tap.count && record->event.pressed) {
                layer_move(_QWERTY);
                return false;
            } else if (record->event.pressed) {
                register_code16(KC_LALT);
                return false;
            } else {
                unregister_code16(KC_LALT);
                return false;
            }
            break;
    }
    return true;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            set_led_off;
            break;
        case _SYMB:
            set_led_green;
            break;
        case _MOUSE:
            set_led_yellow;
            break;
        case _MOVE:
            set_led_red;
            break;
        default:
            break;
    }
    return state;
}
