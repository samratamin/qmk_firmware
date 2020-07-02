#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH
//#define SYM_L   MO(_SYMB)
#define SYM_L   MO(_NAV)
#define SYM_O   TO(_SYMB)
#define SYM_N   TO(_QWERTY)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_PSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     KC_GESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼         ┌────────┬────────┬────────┬────────┬────────┬
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_ESC  ,                           SYM_O  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼         ┌────────┬────────┬────────┬────────┬────────┬
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_CAPS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_LCTL ,KC_LALT ,KC_MAIL ,KC_CALC ,      SYM_L  ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    KC_MYCM ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     KC_MUTE ,KC_MPLY ,XXXXXXX ,XXXXXXX , KC_F4  ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PSLS ,XXXXXXX ,XXXXXXX ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_VOLU ,KC_MNXT ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          SYM_N  ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,KC_PAST ,XXXXXXX ,XXXXXXX ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_VOLD ,KC_MPRV ,XXXXXXX ,XXXXXXX , KC_UP  ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,KC_PMNS ,XXXXXXX ,XXXXXXX ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX, XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,_______ ,_______ ,        _______ ,_______ ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,KC_PPLS ,XXXXXXX ,XXXXXXX ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_LGUI ,KC_MYCM ,KC_MAIL ,KC_CALC ,     XXXXXXX ,    _______ ,_______ ,        _______ ,_______ ,    KC_KP_0 ,     KC_PDOT ,KC_PENT ,XXXXXXX ,XXXXXXX ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                             KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , KC_F12 ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BSLS ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______,     XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,XXXXXXX ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,XXXXXXX ,XXXXXXX ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______ ,                          _______ ,XXXXXXX ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,XXXXXXX ,XXXXXXX ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,XXXXXXX ,XXXXXXX ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_KP_0 ,     KC_KP_0 ,KC_PDOT ,XXXXXXX ,XXXXXXX ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  )

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _QWERTY:
            //set_led_off;
            break;
        case _SYMB:
            set_led_green;
            break;
        case _NAV:
            set_led_red;
            break;
        case _ADJUST:
            set_led_red;
            break;
        default:
            break;
    }


};




