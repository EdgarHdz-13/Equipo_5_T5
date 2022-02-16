/*
 * RGB.h
 *
 *  Created on: 11 feb 2022
 *      Author: Edgar Hernández, Victor Cervantes
 */
#include <stdio.h>
#include <stdint.h>
#include "bits.h"
#include "MK64F12.h"

#ifndef RGB_H_
#define RGB_H_
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
\brief	 This function clears all interrupts that were sensed by the GPIO.

\param[in]  port_name Port to clear interrupts.
\return void
\todo Implement a mechanism to clear interrupts by a specific pin.
*/
void initialize_rgb(rgb_color RGB_color_name);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
\brief	 This function clears all interrupts that were sensed by the GPIO.

\param[in]  port_name Port to clear interrupts.
\return void
\todo Implement a mechanism to clear interrupts by a specific pin.
*/
void turn_on(rgb_color RGB_color_name);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
\brief	 This function clears all interrupts that were sensed by the GPIO.

\param[in]  port_name Port to clear interrupts.
\return void
\todo Implement a mechanism to clear interrupts by a specific pin.
*/
void turn_off(rgb_color RGB_color_name);

#endif /* RGB_H_ */
