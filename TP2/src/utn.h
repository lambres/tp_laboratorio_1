/*
 * utn.h
 *
 *  Created on: 8 mar. 2022
 *      Author: Ruben Dario Zevallos Lambrescht 1H
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);
int utn_getNumeroAleatorio(int desde, int hasta, int iniciar);
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos);
int dividir(float *pResultado, int operador1, int operador2);
int factorial(int n);
int esSoloLetras_Espacio(char str[]);
int getStringLetras(char *mensaje, char *input);
int getStringNumeros(char *mensaje, char *input);
char getChar(char mensaje[]);
int getString(char *mensaje, char *input);
void insertion(int data[], int len);
unsigned int verifica(void);
int utn_getNombre(char *pResultado, int longitud, char *mensaje,
		char *mensajeError, int reintentos);
int utn_getTexto(char *pResultado, int longitud, char *mensaje,
		char *mensajeError, int reintentos);

#endif /* UTN_H_ */
