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
    switch(RGB_color_name)
    {
        case YELLOW:
            GPIO_clock_gating(GPIO_E);
            GPIO_pin_control_register(GPIO_E,GREEN_PIN,&pcr_green_pin);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
            GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,GREEN_PIN);
        // Also perform the steps for RED
        case RED:
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
        break;
        case PURPLE:
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
        // Also perform the steps for BLUE
        case BLUE:
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,BLUE_PIN,&pcr_blue_pin);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BLUE_PIN);
        break;
        case WHITE:
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);
        // Also perform the steps for CYAN and GREEN
        case CYAN:
            GPIO_clock_gating(GPIO_B);
            GPIO_pin_control_register(GPIO_B,BLUE_PIN,&pcr_blue_pin);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BLUE_PIN);
        // Also perform the steps for GREEN
        case GREEN:
            GPIO_clock_gating(GPIO_E);
            GPIO_pin_control_register(GPIO_E,GREEN_PIN,&pcr_green_pin);
            GPIO_set_pin(GPIO_E,GREEN_PIN);
            GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,GREEN_PIN);
        break;
    }
}

void RGB_initialize_all()
{

    GPIO_clock_gating(GPIO_B);
    GPIO_pin_control_register(GPIO_B,RED_PIN,&pcr_red_pin);
    GPIO_set_pin(GPIO_B,RED_PIN);
    GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,RED_PIN);

    GPIO_pin_control_register(GPIO_B,BLUE_PIN,&pcr_blue_pin);
    GPIO_set_pin(GPIO_B,BLUE_PIN);
    GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BLUE_PIN);

    GPIO_clock_gating(GPIO_E);
    GPIO_pin_control_register(GPIO_E,GREEN_PIN,&pcr_green_pin);
    GPIO_set_pin(GPIO_E,GREEN_PIN);
    GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,GREEN_PIN);
}

void RGB_turn_on(rgb_color RGB_color_name)
{
    switch(RGB_color_name)
    {
        case RED:
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_B,GREEN_PIN);
        break;
        case BLUE:
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_B,GREEN_PIN);
        break;
        case GREEN:
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_B,GREEN_PIN);
        break;
        case PURPLE:
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_set_pin(GPIO_B,GREEN_PIN);
        break;
        case YELLOW:
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_set_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_B,GREEN_PIN);
        break;
        case CYAN:
            GPIO_set_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_B,GREEN_PIN);
        break;
        case WHITE:
            GPIO_clear_pin(GPIO_B,RED_PIN);
            GPIO_clear_pin(GPIO_B,BLUE_PIN);
            GPIO_clear_pin(GPIO_B,GREEN_PIN);
        break;
    }
}

void RGB_turn_off(rgb_color RGB_color_name)
{

}
