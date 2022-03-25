#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _MOUSE 2
#define _MOVE 3
#define _UMLAUT 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  MOUSE,
  MOVE,
  ALT_OSL4,
  ALT_TO3,
  ALT_TO0,
  KC_SZ,
  KC_AE,
  KC_UE,
  KC_OE
};

#define ALT_OSL4 LALT_T(KC_F13)
#define ALT_TO3 LALT_T(KC_F12)
#define ALT_TO0 LALT_T(KC_F11)

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    ae,
    AE,
    ue,
    UE,
    oe,
    OE,
    SZ
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [ae] = 0x00E4,
    [AE] = 0x00C4,
    [ue] = 0x00FC,
    [UE] = 0x00DC,
    [oe] = 0x00F6,
    [OE] = 0x00D6,
    [SZ] = 0x00DF
};

#define KC_SZ X(SZ)
#define KC_AE XP(ae,AE)
#define KC_UE XP(ue,UE)
#define KC_OE XP(oe,OE)

// Shortcut to make keymap more readable

//#define TD_SZ ACTION_TAP_DANCE_DOUBLE(KC_S, RALT_T(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LT(2, KC_GRV),KC_1,KC_2   ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,LT(2, KC_MINS) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,MO(3)   ,                          MO(3)   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LGUI_T(KC_ESC),KC_A,KC_S,KC_D ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B   , LT(3, KC_BSLS),MOD_HYPR ,KC_RALT,LT(3, KC_BSLS),KC_N  ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSPC ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_CAPSLOCK ,KC_UNDS ,KC_RALT   ,ALT_OSL4 ,  LCTL_T(KC_BSPC),KC_SPC  ,LT(1, KC_ENT),LT(1, KC_ENT),KC_SPC, RCTL_T(KC_BSPC) ,ALT_TO3  ,KC_RALT   ,KC_BSLASH ,KC_TAB
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_NUMLOCK ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_HASH ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,TO(0) ,                          TO(0) ,KC_PSLS ,KC_P7 	,KC_P8 	 ,KC_P9   ,KC_PMNS ,KC_TAB ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DLR ,KC_LT ,KC_GT  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,TO(1) ,                          TO(1) ,KC_PAST ,KC_P4 	,KC_P5   ,KC_P6   ,KC_PPLS ,KC_ESCAPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSHIFT ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,KC_TRNS ,KC_TRNS ,        LCTL(KC_C) ,LCTL(KC_V) ,XXXXXXX ,KC_P1 	,KC_P2   ,KC_P3   ,KC_PENT ,KC_RSHIFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_DEL ,    KC_TRNS ,_______ ,        _______ ,KC_TRNS ,    KC_DEL   ,     KC_P0   ,KC_PDOT ,KC_PENT ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,TO(0) ,                          TO(0) ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,TO(2) ,                          TO(2) ,KC_NO ,KC_LEFT ,KC_DOWN   ,KC_UP,KC_RIGHT ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,    KC_TRNS ,     KC_END ,KC_PGDN ,KC_PGUP ,KC_HOME
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_MOVE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_TRNS ,TO(0) ,                            TO(0)   ,KC_TRNS   ,KC_PGUP ,KC_UP ,KC_PGDOWN ,KC_TRNS   ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_MPRV ,KC_MPLY ,KC_MNXT,KC_TRNS  ,TO(3) ,                           TO(3)   ,KC_TRNS    ,KC_LEFT ,KC_DOWN ,KC_RIGHT ,KC_TRNS   ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_HOME ,KC_NO   ,KC_END  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,         KC_TRNS    ,KC_TRNS ,KC_TRNS   ,KC_HOME   ,KC_NO   ,KC_END   ,KC_TRNS   ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,ALT_TO0      ,KC_TRNS     ,KC_TRNS ,KC_TRNS   ,        KC_TRNS   ,KC_TRNS   ,    KC_TRNS   ,     ALT_TO0  ,KC_NO   ,KC_TRNS   ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_UMLAUT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS                                             ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,TO(0)                             ,TO(0)   ,KC_TRNS ,KC_UE   ,KC_TRNS ,KC_OE   ,KC_TRNS ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_AE   ,KC_SZ   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS                           ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSHIFT ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS       ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_RSHIFT,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS      ,KC_TRNS     ,KC_TRNS ,KC_TRNS         ,KC_TRNS ,KC_TRNS     ,KC_TRNS      ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //OneShot
    switch (keycode) {
        case ALT_OSL4:
            if (record->tap.count && record->event.pressed) {
                layer_on(_UMLAUT);
                set_oneshot_layer(_UMLAUT, ONESHOT_START);
                return false;
            }
            else if (record->event.pressed) {
                register_code16(KC_LALT);
                return false;
            } else {
                unregister_code16(KC_LALT);
                return false;
            }
            break;
        default:
            if (!record->event.pressed){
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
    }
    //TO
    switch (keycode) {
        case ALT_TO3:
            if (record->tap.count && record->event.pressed) {
                layer_move(3);
                return false;
            }
            else if (record->event.pressed) {
                register_code16(KC_LALT);
                return false;
            } else {
                unregister_code16(KC_LALT);
                return false;
            }
            break;
        case ALT_TO0:
            if (record->tap.count && record->event.pressed) {
                layer_move(0);
                return false;
            }
            else if (record->event.pressed) {
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
            break;
         case _MOVE:
            set_led_red;
            break;
        default:
            break;
    }
  return state;
}


