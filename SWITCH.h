#ifndef SWITCH_H_
#define SWITCH_H_

#include "stdint.h"

#define SW2_PIN 6

#define SW3_PIN 4

typedef enum{
	SW2,SW3
}switch_button;

typedef enum{
	PULLUP,PULLDOWN
}switch_state;

void SW_initialize_switch(switch_button sw_button, switch_state state);


uint8_t SW_read_switch_state(switch_button);

#endif /* DELAY_H_ */
