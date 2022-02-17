/**
	\file
	\brief
		This is the source file for the GPIO device driver for Kinetis K64.
		It contains all the implementation for configuration functions and runtime functions.
		i.e., this is the application programming interface (API) for the GPIO peripheral.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	18/02/2019
	\todo
	    Interrupts are not implemented in this API implementation.
 */
#include "MK64F12.h"
#include "GPIO.h"
#include "Bits.h"

uint8_t GPIO_clock_gating(gpio_port_name_t port_name)
{
	switch(port_name)/** Selecting the GPIO for clock enabling*/
			{
				case GPIO_A: /** GPIO A is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA; /** Bit 9 of SIM_SCGC5 is  set*/
					break;
				case GPIO_B: /** GPIO B is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTB; /** Bit 10 of SIM_SCGC5 is set*/
					break;
				case GPIO_C: /** GPIO C is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTC; /** Bit 11 of SIM_SCGC5 is set*/
					break;
				case GPIO_D: /** GPIO D is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTD; /** Bit 12 of SIM_SCGC5 is set*/
					break;
				case GPIO_E: /** GPIO E is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTE; /** Bit 13 of SIM_SCGC5 is set*/
					break;
				default: /**If doesn't exist the option*/
					return(FALSE);
			}// end switch
	/**Successful configuration*/
	return(TRUE);
}// end function

uint8_t GPIO_pin_control_register(gpio_port_name_t port_name, uint8_t pin,const gpio_pin_control_register_t*  pin_control_register)
{

    switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			PORTA->PCR[pin] = *pin_control_register; /** Establishes PCR port A with pin control register values */
			break;
		case GPIO_B:/** GPIO B is selected*/
			PORTB->PCR[pin] = *pin_control_register; /** Establishes PCR port B with pin control register values */
			break;
		case GPIO_C:/** GPIO C is selected*/
			PORTC->PCR[pin] = *pin_control_register; /** Establishes PCR port C with pin control register values */
			break;
		case GPIO_D:/** GPIO D is selected*/
			PORTD->PCR[pin] = *pin_control_register; /** Establishes PCR port D with pin control register values */
			break;
		case GPIO_E: /** GPIO E is selected*/
			PORTE->PCR[pin] = *pin_control_register; /** Establishes PCR port E with pin control register values */
		default:/**If doesn't exist the option*/
			return(FALSE);
		break;
		}
	/**Successful configuration*/
	return(TRUE);
}

void GPIO_write_port(gpio_port_name_t port_name, uint32_t data)
{
    switch(port_name) /** Selecting the GPIO for writing the PDOR*/
    {
        case GPIO_A:/** GPIO A is selected*/
        	GPIOA->PDOR = data; /** Port data output register of GPIO A is set like data */
		break;
        case GPIO_B:/** GPIO B is selected*/
        	GPIOB->PDOR = data; /** Port data output register of GPIO B is set like data */
        break;
        case GPIO_C:/** GPIO C is selected*/
        	GPIOC->PDOR = data; /** Port data output register of GPIO C is set like data */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	GPIOD->PDOR = data; /** Port data output register of GPIO D is set like data */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	GPIOE->PDOR = data; /** Port data output register of GPIO E is set like data */
        break;
        default:/**If doesn't exist the option*/
        break;
    }
}
uint32_t GPIO_read_port(gpio_port_name_t port_name)
{
    switch(port_name)
    {
        case GPIO_A:/** GPIO A is selected*/
            return (uint32_t)(GPIOA->PDIR); /** Return Port data input register of GPIO A */
		break;
        case GPIO_B:/** GPIO B is selected*/
            return (uint32_t)(GPIOB->PDIR); /** Return Port data input register of GPIO B */
        break;
        case GPIO_C:/** GPIO C is selected*/
            return (uint32_t)(GPIOC->PDIR); /** Return Port data input register of GPIO C */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	return (uint32_t)(GPIOD->PDIR); /** Return Port data input register of GPIO E */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	return (uint32_t)(GPIOE->PDIR); /** Return Port data input register of GPIO D */
        break;
        default:/**If doesn't exist the option*/
            return (FALSE);
        break;
    }
}
uint8_t GPIO_read_pin(gpio_port_name_t port_name, uint8_t pin)
{
	/**variables for read an specific pin */
	uint8_t pin_data = 0x0;
	uint8_t mask_pin = 0x1;
	uint32_t GPIO_data = 0x0;

    switch(port_name)/** Selecting the GPIO for reading a specific pin*/
    {
        case GPIO_A:/** GPIO A is selected*/
        	GPIO_data = GPIOA->PDIR >> pin; /** Move specific pin of GPIO A to the first bit */
        	pin_data = GPIO_data & mask_pin;
            return pin_data; /** Returned specific pin masked */
		break;
        case GPIO_B:/** GPIO B is selected*/
        	GPIO_data = GPIOB->PDIR >> pin; /** Move specific pin of GPIO B to the first bit */
        	pin_data = GPIO_data & mask_pin;
            return pin_data; /** Returned specific pin masked */
        break;
        case GPIO_C:/** GPIO C is selected*/
        	GPIO_data = GPIOC->PDIR >> pin; /** Move specific pin of GPIO C to the first bit */
        	pin_data = GPIO_data & mask_pin;
            return pin_data; /** Returned specific pin masked */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	GPIO_data = GPIOD->PDIR >> pin; /** Move specific pin of GPIO D to the first bit */
        	pin_data = GPIO_data & mask_pin;
            return pin_data; /** Returned specific pin masked */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	GPIO_data = GPIOE->PDIR >> pin; /** Move specific pin of GPIO E to the first bit */
        	pin_data = GPIO_data & mask_pin;
            return pin_data; /** Returned specific pin masked */
        break;
        default:/**If doesn't exist the option*/
            return (FALSE);
        break;
    }
}
void GPIO_set_pin(gpio_port_name_t port_name, uint8_t pin)
{
    switch(port_name)
	{
        case GPIO_A:/** GPIO A is selected*/
            GPIOA->PSOR |= 1<<pin; /** Port set output register of GPIO A set in pin displaced */
		break;
        case GPIO_B:/** GPIO B is selected*/
        	GPIOB->PSOR |= 1<<pin; /** Port set output register of GPIO B set in pin displaced */
        break;
        case GPIO_C:/** GPIO C is selected*/
        	GPIOC->PSOR |= 1<<pin; /** Port set output register of GPIO C set in pin displaced */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	GPIOD->PSOR |= 1<<pin; /** Port set output register of GPIO D set in pin displaced */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	GPIOE->PSOR |= 1<<pin; /** Port set output register of GPIO E set in pin displaced */
        break;
        default:/**If doesn't exist the option*/

        break;
    }
}
void GPIO_clear_pin(gpio_port_name_t port_name, uint8_t pin)
{
	uint8_t mask_pin = 0x1;

    switch(port_name)/** Selecting the GPIO for clearing a specific pin*/
    {
        case GPIO_A:/** GPIO A is selected*/
        	GPIOA->PCOR |= mask_pin<<pin; /** Port clear output register of GPIO A set in pin displaced */
		break;
        case GPIO_B:/** GPIO B is selected*/
        	GPIOB->PCOR |= mask_pin<<pin; /** Port clear output register of GPIO B set in pin displaced */
        break;
        case GPIO_C:/** GPIO C is selected*/
        	GPIOC->PCOR |= mask_pin<<pin; /** Port clear output register of GPIO C set in pin displaced */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	GPIOD->PCOR |= mask_pin<<pin; /** Port clear output register of GPIO D set in pin displaced */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	GPIOE->PCOR |= mask_pin<<pin; /** Port clear output register of GPIO E set in pin displaced */
        break;
        default:/**If doesn't exist the option*/
        break;
    }
}
void GPIO_toogle_pin(gpio_port_name_t port_name, uint8_t pin)
{
    switch(port_name)
	{
        case GPIO_A:/** GPIO A is selected*/
            GPIOA->PTOR |= 1<<pin; /** Port toggle output register of GPIO A set in pin displaced */
		break;
        case GPIO_B:/** GPIO B is selected*/
        	GPIOB->PTOR |= 1<<pin; /** Port toggle output register of GPIO B set in pin displaced */
        break;
        case GPIO_C:/** GPIO C is selected*/
        	GPIOC->PTOR |= 1<<pin; /** Port toggle output register of GPIO C set in pin displaced */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	GPIOD->PTOR |= 1<<pin; /** Port toggle output register of GPIO D set in pin displaced */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	GPIOE->PTOR |= 1<<pin; /** Port toggle output register of GPIO E set in pin displaced */
        break;
        default:/**If doesn't exist the option*/

        break;
    }
}
void GPIO_data_direction_port(gpio_port_name_t port_name ,uint32_t direction)
{
    switch(port_name) /** Selecting the GPIO for writing the data direction port*/
	{
        case GPIO_A:/** GPIO A is selected*/
            GPIOA->PDDR = direction; /** Establishes port data direction register of GPIO A as direction */
		break;
        case GPIO_B:/** GPIO B is selected*/
        	GPIOB->PDDR = direction; /** Establishes port data direction register of GPIO B as direction */
        break;
        case GPIO_C:/** GPIO C is selected*/
        	GPIOC->PDDR = direction; /** Establishes port data direction register of GPIO C as direction */
        break;
        case GPIO_D:/** GPIO D is selected*/
        	GPIOD->PDDR = direction; /** Establishes port data direction register of GPIO D as direction */
        break;
        case GPIO_E: /** GPIO E is selected*/
        	GPIOE->PDDR = direction; /** Establishes port data direction register of GPIO E as direction */
        break;
        default:/**If doesn't exist the option*/

        break;
    }
}
void GPIO_data_direction_pin(gpio_port_name_t port_name, uint8_t state, uint8_t pin)
{
    switch(port_name)
	{
        case GPIO_A:/** GPIO A is selected*/
            if(TRUE == state)
            {
                GPIOA->PDDR |= 1<<pin;    /** Configure specific pin of GPIO A as general-purpose input */
            }
        	else
        	{
                GPIOA->PDDR &= ~(1<<pin); /** Configure specific pin of GPIO A as general-purpose output */
        	}
		break;
        case GPIO_B:/** GPIO B is selected*/
            if(TRUE == state)
            {
                GPIOB->PDDR |= 1<<pin;    /** Configure specific pin of GPIO B as general-purpose input */
            }
        	else
            {
                GPIOB->PDDR &= ~(1<<pin); /** Configure specific pin of GPIO B as general-purpose output */
            }
        break;
        case GPIO_C:/** GPIO C is selected*/
            if(TRUE == state)
            {
                GPIOC->PDDR |= 1<<pin;    /** Configure specific pin of GPIO C as general-purpose input */
            }
        	else
            {
                GPIOC->PDDR &= ~(1<<pin); /** Configure specific pin of GPIO C as general-purpose output */
            }
        break;
        case GPIO_D:/** GPIO D is selected*/
            if(TRUE == state)
            {
                GPIOD->PDDR |= 1<<pin;    /** Configure specific pin of GPIO D as general-purpose input */
            }
        	else
            {
                GPIOD->PDDR &= ~(1<<pin); /** Configure specific pin of GPIO D as general-purpose output */
            }
        break;
        case GPIO_E: /** GPIO E is selected*/
            if(TRUE == state)
            {
                GPIOE->PDDR |= 1<<pin;    /** Configure specific pin of GPIO E as general-purpose input */
            }
        	else
            {
                GPIOE->PDDR &= ~(1<<pin); /** Configure specific pin of GPIO E as general-purpose output */
            }
        break;
        default:/**If doesn't exist the option*/

        break;
    }
}

