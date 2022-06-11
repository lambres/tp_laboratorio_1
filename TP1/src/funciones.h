/*
 * funciones.h
 *
 *  Created on: 3 abr. 2022
 *      Author: dario
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int calculoPrecio(float costo,int formaPago, float * precio, float cotBtc);
int menuOp4(int distancia,float precio1, float precio2, float debito1, float credito1, float btc1, float unitario1, float debito2, float credito2, float btc2, float unitario2);
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* FUNCIONES_H_ */
