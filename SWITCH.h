#ifndef DELAY_H_
#define DELAY_H_

#include <stdint.h>

typedef enum{
	SW2,SW3
}switch_button;

void initialize_switch(switch_button sw_button);

uint8_t read_switch_state(switch_button);

#endif /* DELAY_H_ */