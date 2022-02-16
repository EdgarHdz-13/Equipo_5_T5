
#include "MK64F12.h"
#include "RGB.h"
#include "Delay.h"

#define DELAY_CONST 65000

int main(void) {

    RGB_initialize_all();
    //SW intialize
    RGB_turn_on(RED);
    RGB_turn_on(BLUE);
    RGB_turn_on(GREEN);
    RGB_turn_on(PURPLE);
    RGB_turn_on(CYAN);
    RGB_turn_on(YELLOW);
    RGB_turn_on(WHITE);
	for (;;) {


	}
    return 0 ;
}
