/**
 * -------------------------------------------------------------------
 * Copyright (c) 2010 - Todos los derechos reservados
 * Manuel Eduardo Vieda Salomon <mail@manuelvieda.com>
 * Ingeniero Electronico, Ingeniero de Sistemas y Computacion
 * Universidad de los Andes. Bogota, Colombia.
 * -------------------------------------------------------------------
 *
 * Archivo:				ZigBee.h
 * Fecha Creacion:		Octubre 19 de 2010
 * Fecha Modificacion:	Octubre 24 de 2010
 * Version (Revision):  0.1 (1)
 *
 * Descripcion: Libreria que facilita el uso del modulo de comunicación
 *              intalambrica de un microcontrolador a traves de un modulo
 *              ZigBee (Ej: XBee 24)
 *
 *
 * --------------------------------------------------------------------
 * LICENCIA:
 * 
 * Se encuentra totalmente permitido el uso y distribucion en forma de codigo y
 * binario bajo la condicion de cumplir con las siguientes condiciones de uso:
 *
 *   - Toda redistribucion del codigo fuente debe mantener sin ningun cambio la
 *     presente notificacion de copyright, la lista de condiciones y la descripcion
 *     del archivo.
 *
 *   - Ni el nombre del poseedor del presente copyright o el nombre
 *     de cualquier colaborador puede ser usado para la promocion de productos
 *     derivados de este programa/codigo sin una autorizacion escrita y especifica
 *     por parte del autor.
 *
 *   - Si considera que este contenido le ha sido bastante util, puedes invitarme
 *     a una ronda de cervezas. (The Beer-Ware License, Revision 42)
 * ---------------------------------------------------------------------
 */



#include <stdio.h>			// Standard IO facilities 
#include <stdint.h>			// Standard Integer Types
#include <util/delay.h>		// Convenience functions for busy-wait delay loops
#include <avr/io.h>			// AVR device-specific IO definitions
#include <avr/pgmspace.h>	// Program Space Utilities
#include <avr/interrupt.h>	// Interrupts handling

#include "USART.h"
#include "ZigBee.h"



/**
 * Rutina de atencion de interrupcion generada cuando la USART0 recibe un dato
 */
/*
ISR(USART_RXC_vect) 
{
	USART_Enviar(USART_Recibir());


	
	buffer[++ptrBuffer]=USART_Recibir();
	USART_Enviar(buffer[ptrBuffer]);


		if(buffer[ptrBuffer]==0x0D){
				
				for(uint8_t i=0; i<ptrBuffer; i++){
				 	USART_Enviar(buffer[i]);
				}
				ptrBuffer=0x00;
		}

		

	
}



*/

void ZigBee_AT_EnviarCh(uint8_t msg){
	USART_Enviar(msg);
}


void ZigBee_AT_Config(){

		sei();

/*		ptrBuffer=0x00;

		USART_EnviarStr("OK");
		uint8_t i =0;
		for(i=0; i<50; i++){
			buffer[i]=0x00;
			bufferMsg[i]=0x00;
		}


		while(1){ 
			
			if(ptrBuffer==10){
				USART_EnviarStr("x");
				uint8_t j=0;
				for(j=0; j<ptrBuffer; j++){
					USART_Enviar(buffer[j]);
				}
				ptrBuffer=0;
			}
		}

		*/
}
