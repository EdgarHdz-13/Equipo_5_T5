/*
 * RGB.h
 *
 *  Created on: 11 feb 2022
 *      Author: Edgar Hernández, Victor Cervantes
 */
#ifndef RGB_H_
#define RGB_H_

#include "stdint.h"

// Constant that represent the pin number where is the red led
#define RED_PIN 22
// Constant that represent the pin number where is the blue led
#define BLUE_PIN 21
// Constant that represent the pin number where is the green led
#define GREEN_PIN 26

/*! These constants are used to select an color for the RGB*/
typedef enum{
            RED,
			BLUE,
			GREEN,
			PURPLE,
			YELLOW,
			CYAN,
			WHITE
            }rgb_color;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
\brief	 This function turn on the clock gating, pin control register and establishes the port as output
         by default the led is turn off.

\param[in]  RGB_color_name RGB to turn on.
\return void

*/
void RGB_initialize(rgb_color RGB_color_name);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
\brief	 This function turn on all for led's clock gating, pin control register and establishes the ports as output
         by default the leds is turn off.

*/
void RGB_initialize_all();
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
\brief	 This function turn on the RGB led/leds for the color selected.

\param[in]  RGB_color_name RGB color to turn on.
\return void
*/
void RGB_turn_on(rgb_color RGB_color_name);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
\brief	 This function turn off the RGB led/leds for the color selected.

\param[in]  RGB_color_name RGB color to turn off.
\return void
*/
void RGB_turn_off(rgb_color RGB_color_name);

#endif /* RGB_H_ */
