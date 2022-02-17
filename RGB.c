/*
 * RGB.c
 *
 *  Created on: 11 feb 2022
 *      Author: Edgar Hernández, Victor Cervantes
 */
#include <stdio.h>
#include "bits.h"
#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"

static gpio_pin_control_register_t pcr_red_pin = GPIO_MUX1;
static gpio_pin_control_register_t pcr_green_pin = GPIO_MUX1;
static gpio_pin_control_register_t pcr_blue_pin = GPIO_MUX1;

void RGB_initialize(rgb_color RGB_color_name)
{
    switch(RGB_color_name)/** Selecting the RGB color for enabling*/
    {
        case YELLOW: /** Minimum settings to turn on the green led */
            GPIO_clock_gating(GPIO_E);
            GPIO_pin_control_register(GPIO_E,GREEN_PIN,&pcr_green_pin);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
            GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,GREEN_PIN);
        // Also perform the steps for RED
        case RED: /** Minimum settings to turn on the red led */
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
        break;
        case PURPLE: /** Minimum settings to turn on the red led */
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
        // Also perform the steps for BLUE
        case BLUE: /** Minimum settings to turn on the red led */
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,BLUE_PIN,&pcr_blue_pin);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BLUE_PIN);
        break;
        case WHITE: /** Minimum settings to turn on red led */
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
        // Also perform the steps for CYAN and GREEN
        case CYAN: /** Minimum settings to turn on the blue led */
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,BLUE_PIN,&pcr_blue_pin);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BLUE_PIN);
        // Also perform the steps for GREEN
        case GREEN: /** Minimum settings to turn on the green led */
            GPIO_clock_gating(GPIO_E);
            GPIO_pin_control_register(GPIO_E,GREEN_PIN,&pcr_green_pin);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
            GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,GREEN_PIN);
        break;
    }
}

void RGB_initialize_all()
{
	/** Minimum settings to turn on the red led */
    GPIO_clock_gating(GPIO_B);
    GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
    GPIO_set_pin(GPIO_B,RED_PIN);
    GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
    /** Minimum settings to turn on the blue led */
    GPIO_pin_control_register(GPIO_B,BLUE_PIN,&pcr_blue_pin);
    GPIO_set_pin(GPIO_B,BLUE_PIN);
    GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BLUE_PIN);
    /** Minimum settings to turn on the green led */
    GPIO_clock_gating(GPIO_E);
    GPIO_pin_control_register(GPIO_E,GREEN_PIN,&pcr_green_pin);
    GPIO_set_pin(GPIO_E,GREEN_PIN);
    GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,GREEN_PIN);
}

void RGB_turn_on(rgb_color RGB_color_name)
{
    switch(RGB_color_name)
    {
        case RED: /** Turning on the red led clearing his port and turning off else setting his pin */
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
        case BLUE: /** Turning on the blue led clearing his port and turning off else setting his pin */
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
        case GREEN: /** Turning on the green led clearing his port and turning off else setting his pin */
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_E,GREEN_PIN);
        break;
        case PURPLE: /** Turning on the red and blue LEDs clearing his ports and turning off else setting his pin */
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
        case YELLOW: /** Turning on the red and green LEDs clearing his ports and turning off else setting his pin */
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_E,GREEN_PIN);
        break;
        case CYAN: /** Turning on the bleu and green LEDs clearing his ports and turning off else setting his pin */
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_E,GREEN_PIN);
        break;
        case WHITE: /** Turning on the red, blue and green LEDs */
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_E,GREEN_PIN);
        break;
    }
}

void RGB_turn_off(rgb_color RGB_color_name)
{
    switch(RGB_color_name)
    {
        case RED: /** Turning off the red led setting his pin */
            GPIO_set_pin(GPIO_B,RED_PIN);
        break;
        case BLUE: /** Turning off the blue led setting his pin */
            GPIO_set_pin(GPIO_B,BLUE_PIN);
        break;
        case GREEN: /** Turning off the green led setting his pin */
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
        case PURPLE: /** Turning off the red and blue LEDs setting his pins */
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
        break;
        case YELLOW: /** Turning off the red and green LEDs setting his pins */
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
        case CYAN: /** Turning off the blue and green LEDs setting his pins */
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
        case WHITE: /** Turning off the red, blue and green LEDs setting his pins */
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
        break;
    }
}
