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
 * Fecha Modificacion:	Octubre 19 de 2010
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


#ifndef _ZIGBEE_H_
#define _ZIGBEE_H_

void ZigBee_AT_Config(void);

void ZigBee_AT_EnviarCh(uint8_t msg);


#endif /* ZIGBEE_H_ */


