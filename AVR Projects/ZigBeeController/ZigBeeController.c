/**
 * -------------------------------------------------------------------
 * Universidad de los Andes - Facultad de Ingenieria
 * Departamento de Ingenieria Electrica y Electronica
 * Proyecto Taller de Control 2010-20
 * ------------------------------------------------------------------
 *
 * File:			ZigBeeController.c
 * Description:		xxx
 *
 * Date (Creation):	October 11th, 2010
 * Date (LastModf):	October 11th, 2010
 * Version:			0.01 (0)
 */



#define F_CPU 8000000UL


// Used Libraries

#include "defines.h"

#include <stdio.h>			// Standard IO facilities 
#include <stdint.h>			// Standard Integer Types
#include <util/delay.h>		// Convenience functions for busy-wait delay loops
#include <avr/io.h>			// AVR device-specific IO definitions
#include <avr/pgmspace.h>	// Program Space Utilities
#include <avr/interrupt.h>	// Interrupts handling

#include "includes/USART.h"
#include "includes/ZigBee.h"


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
	USART_EnviarLn("Inicio");
	while(1){
	_delay_ms(20);
	
	 }
//	return 0;
	

}

//  ---------------------------------------------------------------------------
//      OS POLLING
//  ---------------------------------------------------------------------------

ISR(USART_RXC_vect) 
{
	USART_Enviar(USART_Recibir());
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

	USART_init();
	USART_EnableTx();
	USART_EnableRx();
	sei();
}
