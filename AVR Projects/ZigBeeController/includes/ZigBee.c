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

uint8_t buffer[100];
short int ptrBuffer;

/**
 * Rutina de atencion de interrupcion generada cuando la USART0 recibe un dato
 */

ISR(USART_RXC_vect) 
{

	buffer[ptrBuffer++]=USART_Recibir();
	//USART_Enviar(buffer[ptrBuffer-1]);
	//USART_Enviar(ptrBuffer);
	aa


		if(buffer[ptrBuffer-1]==0x0D){
				
				for(uint8_t i=0; i<ptrBuffer; i++){
				 	USART_Enviar(buffer[i]);
				}
				ptrBuffer=0x00;
		}

	
}


ISR(USART_TXC_vect) 
{

	//buffer[ptrBuffer++]=USART_Recibir();
	//USART_Enviar(buffer[ptrBuffer-1]);
	
}




void ZigBee_AT_EnviarCh(uint8_t msg){
	USART_Enviar(msg);
}


void ZigBee_AT_Config(){

ptrBuffer=0x00;

		USART_EnviarStr("OK");
		
		sei();
		while(1){

			if(ptrBuffer>0x0A){
				USART_EnviarLn("Ok lineas recibidas");
				//USART_EnviarLn(buffer);
				ptrBuffer=0x00;
			}

		}


}


void pruebafalsar(void){

	USART_EnviarLn("Start Config");
	
	// Tiempo muerto de espera
	_delay_ms(100);_delay_ms(100);_delay_ms(100);_delay_ms(100);_delay_ms(100);
	_delay_ms(100);_delay_ms(100);_delay_ms(100);_delay_ms(100);_delay_ms(100);
	_delay_ms(100);_delay_ms(100);

	// Enviamos caracteres de configuracion
	USART_EnviarStr("+++");

	// Tiempo muerto de espera

	// Recibimos OK
	uint8_t i;
	i=0;
	uint8_t buf[10];
	uint8_t version[5];

	uint8_t recibioOK;
	recibioOK = 0;
	
	do{
		buf[i++] = USART_Recibir();
	}while(buf[i-1]!=0x0D);

	if( (buf[0]==0x4F) && (buf[1]==0x4B) ){

		i = 0;
		_delay_ms(20);
		USART_EnviarLn("atvr");
		while(i<4){
			version[i++] = USART_Recibir();
		}

		i = 0;
		_delay_ms(20);
		/*USART_EnviarLn("atcn");
		_delay_ms(200);
		USART_EnviarLn("Config OK");
		do{
			buf[i++] = USART_Recibir();
		}while(buf[i-1]!=0x0D);

		if( (buf[0]==0x4F) && (buf[1]==0x4B) ){
			_delay_ms(20);
			USART_EnviarLn("Config OK");

		}*/




	}
	
	
	


	_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);
	_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);
	_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);
	_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);_delay_ms(500);
	USART_Enviar(recibioOK+0x30);USART_Enviar(0x0D);
	USART_Enviar(buf[0]);
	USART_Enviar(buf[1]);
	USART_Enviar(buf[2]);
	USART_Enviar(version[0]);
	USART_Enviar(version[1]);
	USART_Enviar(version[2]);
	USART_Enviar(version[3]);

}

