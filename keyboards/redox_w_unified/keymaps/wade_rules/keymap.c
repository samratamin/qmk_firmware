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

//HAPTIC_ENABLE += SOLENOID
//define SOLENOID_ENABLE
#define SOLENOID_PIN A7
#define SOLENOID_ACTIVE true
//define SOLENOID_DEFAULT_DWELL 12
//define SOLENOID_MAX_DWELL 100
//define SOLENOID_MIN_DWELL 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) 
{
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    uint8_t layer = biton32(layer_state);

    switch (layer) 
    {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    /*
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    */
}

/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}
*/
#endif

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH
//#define SYM_L   MO(_SYMB)
#define SYM_L   MO(_NAV)
#define SYM_O   TO(_SYMB)
#define SYM_N   TO(_QWERTY)
#define SYM_P   TO(_ADJUST)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_PSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     KC_GESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,          KC_MYCM ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    , SYM_P  ,                           SYM_O  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,          KC_P7   ,KC_P8   ,KC_P9   ,KC_PSLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,          KC_P4   ,KC_P5   ,KC_P6   ,KC_PAST ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,          KC_P1   ,KC_P2   ,KC_P3   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LALT ,KC_MAIL ,KC_CALC ,      SYM_L  ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    KC_MYCM ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,          KC_P0   ,KC_PDOT ,KC_PENT ,KC_PPLS ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         └────────┴────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     KC_MUTE ,KC_MPRV ,KC_MNXT ,XXXXXXX , KC_F4  ,XXXXXXX ,                                            XXXXXXX ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,KC_PMNS ,XXXXXXX ,          KC_MYCM ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_VOLU ,KC_MPLY , KC_UP  ,XXXXXXX ,XXXXXXX ,XXXXXXX , SYM_P  ,                           SYM_N  ,XXXXXXX ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,KC_PAST ,XXXXXXX ,           KC_P7   ,KC_P8   ,KC_P9   ,KC_PSLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_VOLD ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,KC_PPLS ,XXXXXXX ,          KC_P4   ,KC_P5   ,KC_P6   ,KC_PAST ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_KP_0 ,KC_PENT ,KC_PDOT ,KC_PSLS ,XXXXXXX ,          KC_P1   ,KC_P2   ,KC_P3   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_MYCM ,KC_MAIL ,KC_CALC ,     XXXXXXX ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,     _______ ,_______ ,_______ ,_______ ,          KC_P0   ,KC_PDOT ,KC_PENT ,KC_PPLS ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         └────────┴────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                             KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,          KC_MYCM ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , KC_F12 ,          KC_P7   ,KC_P8   ,KC_P9   ,KC_PSLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_P4   ,KC_P5   ,KC_P6   ,KC_PAST ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BSLS ,          KC_P1   ,KC_P2   ,KC_P3   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______,     XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_P0   ,KC_PDOT ,KC_PENT ,KC_PPLS ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         └────────┴────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,          HPT_BUZ ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE , SYM_N  ,                           SYM_O  ,XXXXXXX ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,XXXXXXX ,XXXXXXX ,          KC_P7   ,KC_P8   ,KC_P9   ,KC_PSLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______ ,                          _______ ,XXXXXXX ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,XXXXXXX ,XXXXXXX ,          KC_P4   ,KC_P5   ,KC_P6   ,KC_PAST ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,XXXXXXX ,XXXXXXX ,          KC_P1   ,KC_P2   ,KC_P3   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_KP_0 ,     KC_KP_0 ,KC_PDOT ,XXXXXXX ,XXXXXXX ,          KC_P0   ,KC_PDOT ,KC_PENT ,KC_PPLS ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         └────────┴────────┴────────┴────────┴────────┘
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
            set_led_blue;
            break;
        case _ADJUST:
            set_led_red;
            break;
        default:
            break;
    }


};