#ifndef _ZIGBEE_H_
#define _ZIGBEE_H_

#ifndef F_CPU

	#error "ERROR: No se encuentra definida la frecuencia del reloj (F_CPU). Se ha definido una frecuencia de operación de 8MHz por defecto"
	#define F_CPU 8000000UL

#endif


/**
 *  Tasa de transmision en Baudios
 */
#define BAUDRATE 9600

/**
 * INT_TX_COMPLETA=1  Se genera una interrupcion(Si estan habilitadas globalmente) cuando
 *                    se completa la transmisión de lo que se encuentra en el registro de salida
 * ITN_TX_COMPLETA=0  No se genera la interrupcion
 */
#define INT_TX_COMPLETA 0

/**
 * INT_RX_COMPLETA=1  Se genera una interrupcion(Si estan habilitadas globalmente) cuando
 *                    se completa la recepcion de un dato en la USART
 * INT_RX_COMPLETA=0  No se genera la interrupcion
 */
#define INT_RX_COMPLETA 1

/**
 * CONTROL_PARIEDAD=0  No se realiza ningun tipo de control de pariedad en la informacion transmitida
 * CONTROL_PARIEDAD=1  Se genera automaticamente un bit de pariedad PAR al enviar un dato y el
 *                     receptor se encarga de comprobarlo. Esta dato se revisa manualmente.
 * CONTROL_PARIEDAD=2  Se genera automaticamente un bit de pariedad IMPAR al enviar un dato y el
 *                     receptor se encarga de comprobarlo. Esta dato se revisa manualmente.
 */
#define CONTROL_PARIEDAD 0

/**
 * Se define el numero de bits de STOP que se envia en cada comunicacion. Puede tomar el valor de 1 o 2
 */
#define NUM_STOP 1

/**
 * Se define el tamañao en bits que conforma cada caracter enviado por la USART en cada una de las 
 * transimisiones. Este valor puede tomar valores de 5,6,7,8 y 9 bits. 
 */
#define CHAR_SIZE 8



#define BUFF_SIZE 50



/**
 * Se define el valor del registro que controla la tasa de transimision en baudios
 */
#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)

void ZigBee_init();



 /**
  * USART0_Enviar
  * @PARAMS uint8_t dato -> Dato que se desea enviar
  * @PRE:   El puerto USART0 se encuentra configurado y habilitado para el envio de mensajes+
  * @POST:  Se coloca el mensaje en el buffer de salida de la USART0
  * @RETURN: Void
  */
void USART_Enviar(uint8_t dato);


/**
 * USART_EnviarStrLen(int len, char *buf)
 * @PARAMS:
 * @PRE:
 * @POST:
 * @RETURN:
 */
void USART_EnviarStrLen(int len, char *buf);



/**
 * USART_EnviarStr(str)
 * Envia un String por la USART
 */
#define USART_EnviarStr(str) USART_EnviarStrLen(sizeof(str)-1, str)

/**
 * USART_EnviarLn(str)
 * Envian una linea de String (String + /n)
 */
#define USART_EnviarLn(str) USART_EnviarStrLen(sizeof(str)-1, str); USART_Enviar(0x0D)




void atenderXBee(void);

#endif
