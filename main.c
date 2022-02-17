
#include <stdint.h>
#include "MK64F12.h"
#include "RGB.h"
#include "Delay.h"
#include "SWITCH.h"
#include "Bits.h"

#define DELAY_CONST 900000
/** These constants are used to select an specific state of switches */
typedef enum{
	        NOTHING_pressed,
			SW2_pressed,
			SW3_pressed,
			BOTH_pressed
            }SW_status;
/** These constants are used to select an specific state of RGB sequence  */
typedef enum{
	        G,
			B,
			P,
			R,
			Y,
			W
            }order;
int main(void) {
    /** Initialize RGB and switch state in 0*/
    uint8_t state_RGB = 0;
    uint8_t state_switch = 0;

    RGB_initialize_all();
    /** Initialize both switches as pullup */
    SW_initialize_switch(SW3,PULLUP);
    SW_initialize_switch(SW2,PULLUP);

	for (;;)
	{
		state_switch = (SW_read_switch_state(SW2)) | (SW_read_switch_state(SW3)<<1); /** Actual state of switch buttons */
        switch(state_switch)
        {
            case SW2_pressed: /** Pressed left switch of FRDM */
            	state_RGB = (state_RGB > G) ? (state_RGB-1) : Y; /** Decreases state of RGB sequence */
            	delay(DELAY_CONST);
            break;
            case SW3_pressed: /** Pressed right switch of FRDM */
            	state_RGB = (state_RGB < Y) ? (state_RGB+1) : G; /** Increase state of RGB sequence */
            	delay(DELAY_CONST);
            break;
            case BOTH_pressed: /** Pressed both switches of FRDM */
            	state_RGB = W;
            	delay(DELAY_CONST);
            break;
            case NOTHING_pressed: /** Didn't pressed any of the switches */
            default:
            break;
        }
        /** RGB sequence  */
        switch(state_RGB)
        {
            case G: /** First state of the RGB sequence */
            	RGB_turn_on(GREEN);
            break;
            case B: /** Second state of the RGB sequence */
            	RGB_turn_on(BLUE);
            break;
            case P: /** Third state of the RGB sequence */
            	RGB_turn_on(PURPLE);
            break;
            case R: /** Fourth state of the RGB sequence */
            	RGB_turn_on(RED);
            break;
            case Y: /** Fifth state of the RGB sequence */
            	RGB_turn_on(YELLOW);
            break;
            case W: /** Especial state of the RGB sequence */
            	RGB_turn_on(WHITE);
            break;
        }



	}
    return 0 ;
}
