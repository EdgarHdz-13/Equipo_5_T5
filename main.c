
#include <stdint.h>
#include "MK64F12.h"
#include "RGB.h"
#include "Delay.h"
#include "SWITCH.h"
#include "Bits.h"

#define DELAY_CONST 900000

typedef enum{
	        NOTHING_pressed,
			SW2_pressed,
			SW3_pressed,
			BOTH_pressed
            }SW_status;
typedef enum{
	        G,
			B,
			P,
			R,
			Y,
			W
            }order;
int main(void) {

    uint8_t state_RGB = 0;
    uint8_t state_switch = 0;
    RGB_initialize_all();

    SW_initialize_switch(SW3,PULLUP);
    SW_initialize_switch(SW2,PULLUP);

	for (;;)
	{
		state_switch = (SW_read_switch_state(SW2)) | (SW_read_switch_state(SW3)<<1);
        switch(state_switch)
        {
            case SW2_pressed:
            	state_RGB = (state_RGB > G) ? (state_RGB-1) : Y;
            	delay(DELAY_CONST);
            break;
            case SW3_pressed:
            	state_RGB = (state_RGB < Y) ? (state_RGB+1) : G;
            	delay(DELAY_CONST);
            break;
            case BOTH_pressed:
            	state_RGB = W;
            	delay(DELAY_CONST);
            break;
            case NOTHING_pressed:
            default:
            break;
        }
        switch(state_RGB)
        {
            case G:
            	RGB_turn_on(GREEN);
            break;
            case B:
            	RGB_turn_on(BLUE);
            break;
            case P:
            	RGB_turn_on(PURPLE);
            break;
            case R:
            	RGB_turn_on(RED);
            break;
            case Y:
            	RGB_turn_on(YELLOW);
            break;
            case W:
            	RGB_turn_on(WHITE);
            break;
        }



	}
    return 0 ;
}
