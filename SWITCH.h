#ifndef SWITCH_H_
#define SWITCH_H_

#include "stdint.h"
#include "bits.h"

/** Constant that represent the pin that corresponds to the second switch*/
#define SW2_PIN 6
/** Constant that represent the pin that corresponds to the third switch*/
#define SW3_PIN 4

/*! These constants are used to select an specific switch in the different API functions*/
typedef enum{
	SW2,SW3
}switch_button;

/*! These constants are used to select an specific switch configuration in the different API functions*/
typedef enum{
	PULLUP,PULLDOWN
}switch_state;

void SW_initialize_switch(switch_button sw_button, switch_state state);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief This function intialize a specifc switch.
 	 \param[in]switch_button sw_button to be.
 	 \param[in] switch_state state to be set in PCR.
 	 \return void
 */

boolean_t SW_read_switch_state(switch_button sw_button);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function reads a specific SWITCH state.
	 \param[in] switch_button sw_button to be read.
 	 \return This function the current state of a switch returning a boolean value 0 if it is not pressed and 1 if it is pressed.
 */

#endif /* SWITCH_H_ */
