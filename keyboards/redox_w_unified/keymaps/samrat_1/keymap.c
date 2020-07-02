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


//#define OLED_TIMEOUT 10000

#define SOLENOID_DEFAULT_DWELL 12 
#define SOLENOID_MAX_DWELL 100
#define SOLENOID_MIN_DWELL 4
//#define OLED_TIMEOUT 10000


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) 
{

    // Host Keyboard Layer Status
    uint8_t layer = biton32(layer_state);
    bool NonDefaultLayerActive = false;
    switch (layer) 
    {
        case _QWERTY:
            oled_write_P(PSTR("\n"), false);
            //oled_off();
            NonDefaultLayerActive = false;
            break;
        case _SYMB:
            oled_write_P(PSTR("Layer: FN\n"), false);
            oled_on();
            NonDefaultLayerActive = true;
            break;
        case _NAV:
            oled_write_P(PSTR("Layer: NAV\n"), false);
            oled_on();
            NonDefaultLayerActive = true;
            break;
        case _ADJUST:
            oled_write_P(PSTR("Layer: ADJ\n"), false);
            oled_on();
            NonDefaultLayerActive = true;
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
            NonDefaultLayerActive = false;
    }



    
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();

    if(led_state.caps_lock == true)
    {
      oled_write_P(PSTR("Caps Lock Active\n"), false);
      oled_on();
    }
    if(led_state.num_lock == true)
    {
      oled_write_P(PSTR("Num Lock Active\n"), false);
      oled_on();
    }
    if(led_state.scroll_lock == true)
    {
      oled_write_P(PSTR("Scroll Lock Active\n"), false);
      oled_on();
    }
    if(led_state.caps_lock == false && led_state.num_lock == false && led_state.scroll_lock == false)
    {
      
      if(NonDefaultLayerActive == true)
      {
        oled_on();
      }
      else
      {
        oled_write_P(PSTR("\n"), false);
        oled_off();
      }
    }
    
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

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_PSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     KC_GESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼         ┌────────┬────────┬────────┬────────┬────────┬
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_PGUP  ,                         KC_PGDN ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼         ┌────────┬────────┬────────┬────────┬────────┬
     KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_MINS ,KC_EQL ,         HPT_ON  ,HPT_OFF ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     KC_LCTL ,KC_LGUI ,KC_LALT ,SYM_L         ,KC_SPC     ,KC_SPC  ,KC_BSPC,         KC_ENT  ,KC_SPC  ,    KC_SPC ,      KC_UP  , KC_DOWN ,KC_LEFT ,KC_RGHT ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX,     XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                             KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX , KC_F12 ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX,     XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘         ┼────────┼────────┼────────┼────────┼────────┤
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_VOLD, KC_VOLU ,KC_PEQL ,KC_PSLS ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_7    ,KC_8    ,KC_9    ,KC_PAST ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_4    ,KC_5    ,KC_6    ,KC_PMNS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_1    ,KC_2    ,KC_3    ,KC_PPLS ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤         ┌────────┬────────┬────────┬────────┬────────┬
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX,     XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,          KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,KC_NO 
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
