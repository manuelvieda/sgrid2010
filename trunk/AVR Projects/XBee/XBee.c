#include <stdio.h>			// Standard IO facilities 
#include <stdint.h>			// Standard Integer Types
#include <util/delay.h>		// Convenience functions for busy-wait delay loops
#include <avr/io.h>			// AVR device-specific IO definitions
#include <avr/pgmspace.h>	// Program Space Utilities
#include <avr/interrupt.h>	// Interrupts handling
#include "ZigBee.h"


//  ---------------------------------------------------------------------------
//     GLOBAL SYSTEM VARIABLES / BUFFERS
//  ---------------------------------------------------------------------------



//  ---------------------------------------------------------------------------
//      DECLARATION OF METHODS / INTERNAL PROCEDURES
//  ---------------------------------------------------------------------------

void initHardware(void);

//  ---------------------------------------------------------------------------
//      MAIN PROGRAM / ROUTINE
//  ---------------------------------------------------------------------------

int main(void){

	_delay_ms(200);
	initHardware();
	atenderXBee();
	while(1){USART_Enviar('x');}

}



//  ---------------------------------------------------------------------------
//      IMPLEMENTATION OF METHODS / ROUTINES / PROCEDURES
//  ---------------------------------------------------------------------------


/**
 * This method handles the initilization of the project's hardware. Within the
 * hardware are both external and internal peripherals of the microcontroller
 *
 * @PARAM:	None
 * @PRE:	None
 * @POST:	The hardware (Modules and Peripherals) is initialized and is
 * 			ready for use.
 */
void initHardware(void){

	ZigBee_init();
	sei();
}
