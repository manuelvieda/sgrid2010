/**
 * -------------------------------------------------------------------
 * Universidad de los Andes - Facultad de Ingenieria
 * Departamento de Ingenieria Electrica y Electronica
 * Proyecto Taller de Control 2010-20
 * ------------------------------------------------------------------
 *
 * File:			defines.h
 * Description:		xxx
 *
 * Date (Creation):	October 11th, 2010
 * Date (LastModf):	October 11th, 2010
 * Version:			0.00 (0)
 */

#ifndef _DEFINES_H_
#define _DEFINES_H_

/* Definimos la frecuencia del reloj de la CPU */
#define F_CPU 8000000UL


#define PEGAR(a, b)             a##b
#define PORT(x)                 PEGAR(PORT, x)
#define PIN(x)                  PEGAR(PIN, x)
#define DDR(x)                  PEGAR(DDR, x)

#endif /* _DEFINES_H */
