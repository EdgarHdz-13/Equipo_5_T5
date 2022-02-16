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

uint8_t SW_read_switch_state(switch_button sw_button)
{
	switch(sw_button)
			{
				case SW2:
					return GPIO_read_pin(GPIO_C, SW2_PIN);
				break;
				case SW3:
					return GPIO_read_pin(GPIO_A, SW3_PIN);
				break;
				default: /**If doesn't exist the option*/
				break;
			}// end switch
}
