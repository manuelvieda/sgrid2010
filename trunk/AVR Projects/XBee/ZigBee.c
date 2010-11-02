#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ZigBee.h"

volatile uint8_t buffer0[BUFF_SIZE];
volatile uint8_t buffer1[BUFF_SIZE];

volatile uint8_t ptrBuffer0;
volatile uint8_t ptrBuffer1;

volatile uint8_t mensajeRecibido;

uint8_t bufferLibre = 0;

void USART_Enviar(uint8_t);



ISR(USART0_RX_vect){

	// Recibimos dato y lo almacenamos en buffer
	switch(bufferLibre){
		case 0:
				buffer0[ptrBuffer0++]=UDR0;
				if(buffer0[ptrBuffer0-1]==0x0D){
					// Atendemos el mensaje recibido
					mensajeRecibido |= _BV(0);
					bufferLibre=1;
				}
				break;


		case 1:
				buffer1[ptrBuffer1++]=UDR0;
				if(buffer1[ptrBuffer1-1]==0x0D){
					// Atendemos el mensaje recibido
					mensajeRecibido |= _BV(1);
					bufferLibre=0;
				}
				break;


		default: bufferLibre=0;break;

	}

}



void ZigBee_init(){

	// Nos aseguramos que la USART se encuentre inactiva y configuracion default
	UCSR0A = 0x20;
	UCSR0B = 0x00;
	UCSR0C = 0x06;
	

	// Asignamos el valor del valor de la tasa de transmision en baudios
	UBRR0L=UBRRVAL;			//Parte baja del byte
	UBRR0H=(UBRRVAL>>8);	//Parte alta del byte

	switch(CHAR_SIZE){
		case 5: UCSR0C &= ~(_BV(UCSZ00)|_BV(UCSZ01));break;
		case 6: UCSR0C &= ~(_BV(UCSZ01));break;
		case 7: UCSR0C &= ~(_BV(UCSZ00));break;
		case 9: UCSR0B|= _BV(UCSZ02);break;
		default:break;
	}

	UCSR0B |= (INT_TX_COMPLETA)?_BV(TXCIE0):0;
	UCSR0B |= (INT_RX_COMPLETA)?_BV(RXCIE0):0;

	switch(CONTROL_PARIEDAD){
		case 1: UCSR0C |= _BV(UPM01); break;
		case 2: UCSR0C |= (_BV(UPM01)|_BV(UPM00)); break;
		default: break;
	}

	if(NUM_STOP==2) UCSR0C |= _BV(USBS0);

	// Enable Tx
	UCSR0B |= _BV(TXEN0);

	// Enable Rx
	UCSR0B |= _BV(RXEN0);

	ptrBuffer0 = 0;
	ptrBuffer1 = 0;
	mensajeRecibido = 0;

}






 /**
  * USART0_Enviar
  * @PARAMS uint8_t dato -> Dato que se desea enviar
  * @PRE:   El puerto USART0 se encuentra configurado y habilitado para el envio de mensajes+
  * @POST:  Se coloca el mensaje en el buffer de salida de la USART0
  * @RETURN: Void
  */
void USART_Enviar(uint8_t dato){

	// Espera a que se se termina la transmision anterior si esta en curso
	while ( !( UCSR0A & (1<<UDRE0)) );
	// Coloca el dato a enviar en el buffer de salida
	UDR0 = dato;

}


/**
 * USART_EnviarStrLen(int len, char *buf)
 * @PARAMS:
 * @PRE:
 * @POST:
 * @RETURN:
 */
void USART_EnviarStrLen(int len, char *buf){

	for (; len > 0; len--){
		USART_Enviar(*buf++);
	}
}



/**
 *
 *
 */
void atenderXBee(void){

	
	while(1){

		if(mensajeRecibido==0x01){
			uint8_t i = 0;
			for(i=0; i<ptrBuffer0; i++){
				USART_Enviar(buffer0[i]);
			}
			mensajeRecibido &= ~_BV(0);
			ptrBuffer0=0;
		}

		if(mensajeRecibido==0x02){
			uint8_t i = 0;
			for(i=0; i<ptrBuffer1; i++){
				USART_Enviar(buffer1[i]);
			}
			mensajeRecibido &= ~_BV(1);
			ptrBuffer1=0;
		}
	}
}




void






