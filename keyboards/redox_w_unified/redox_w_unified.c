#include "redox_w_unified.h"

void uart_init(void) 
{
	SERIAL_UART_INIT();
}

/*
void led_init(void) {
	DDRD  |= (1<<0) | (1<<1);
	PORTD |= (1<<0) | (1<<1);
	DDRF  |= (1<<4) | (1<<5);
	PORTF |= (1<<4) | (1<<5);
}
*/

void led_init(void) 
{
	
	DDRB  |= (1<<5) | (1<<6);
	PORTB |= (1<<5) | (1<<6);
	DDRC  |= (1<<6);
	PORTC |= (1<<6);
	
}


static void render_logo(void) 
{
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void matrix_init_kb(void) 
{
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	uart_init();
	led_init();
	render_logo();
}



void matrix_scan_kb(void) 
{
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
}


void led_set_kb(uint8_t usb_led) 
{
	led_set_user(usb_led);
	
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) 
	{
        // Turn capslock on
		//PORTD |= (1<<3);
		set_led_white;
        
		//oled_write_P(PSTR("Caps Lock\n"), false);
		//oled_on();

    } 
    else 
    {
        // Turn capslock off
		set_led_off;
		//oled_off();
		//oled_write_P(PSTR("\n"), false);
	}
	
}





#ifdef ONEHAND_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
{{20, 0}, {19, 0}, {18, 0}, {17, 0}, {16, 0}, {15, 0}, {14, 0}, {13, 0}, {12, 0}, {11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
{{20, 1}, {19, 1}, {18, 1}, {17, 1}, {16, 1}, {15, 1}, {14, 1},{13, 1}, {12, 1}, {11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
{{20, 2}, {19, 2}, {18, 2}, {17, 2}, {16, 2}, {15, 2}, {14, 2},{13, 2}, {12, 2}, {11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
{{20, 3}, {19, 3}, {18, 3}, {17, 3}, {16, 3}, {15, 3}, {14, 3},{13, 3}, {12, 3}, {11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
{{20, 4}, {19, 4}, {18, 4}, {17, 4}, {16, 4}, {15, 4}, {14, 4},{13, 4}, {12, 4}, {11, 4}, {10, 4}, {9, 4}, {8, 4}, {7, 4}, {6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
};
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}
