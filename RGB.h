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

typedef enum{
	RED,BLUE,GREEN,PURPLE,YELLOW,CYAN,WHITE
}rgb_color;

void initialize_rgb(rgb_color);

#endif /* RGB_H_ */
