/*
 * SWITCH.c
 *
 *  Created on: 11 feb 2022
 *      Author: Edgar Hernández, Victor Cervantes
 */
#include <stdio.h>
#include "bits.h"
#include "MK64F12.h"
#include "GPIO.h"
#include "SWITCH.h"

static gpio_pin_control_register_t pcr_SWPS_pin = GPIO_MUX1|GPIO_PS;
static gpio_pin_control_register_t pcr_SWPE_pin = GPIO_MUX1|GPIO_PE;

void SW_initialize_switch(switch_button sw_button, switch_state state)
{
	//** Implement switch case to initialize nswitch. Must do clok gating and PCR config
	switch(sw_button)
			{
				case SW2:
					GPIO_clock_gating(GPIO_C);
					switch(state)
					{
					case PULLUP:
						GPIO_pin_control_register(GPIO_C,SW2_PIN,&pcr_SWPS_pin);
						break;
					case PULLDOWN:
						GPIO_pin_control_register(GPIO_C,SW2_PIN,&pcr_SWPE_pin);
						break;
					default:
						break;
					}
				break;
				case SW3:
					GPIO_clock_gating(GPIO_A);
					switch(state)
					{
					case PULLUP:
						GPIO_pin_control_register(GPIO_A,SW3_PIN,&pcr_SWPS_pin);
						break;
					case PULLDOWN:
						GPIO_pin_control_register(GPIO_A,SW3_PIN,&pcr_SWPE_pin);
						break;
					default:
						break;
					}
				break;
				default: /**If doesn't exist the option*/
				break;
			}// end switch
}

boolean_t SW_read_switch_state(switch_button sw_button)
{
	switch(sw_button)
			{
				case SW2:
					//**It is necessary to do a mask with 1 to recover the correct value of the pin*/
					return (boolean_t) (~(GPIO_read_pin(GPIO_C, SW2_PIN))&0x1);
				break;
				case SW3:
					//**It is necessary to do a mask with 1 to recover the correct value of the pin*/
					return (boolean_t) (~(GPIO_read_pin(GPIO_A, SW3_PIN))&0x1);
				break;
				default: /**If doesn't exist the option*/
					return(FALSE);
				break;
			}// end switch
}
