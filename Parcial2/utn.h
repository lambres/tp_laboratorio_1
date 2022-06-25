/*
 * utn.h
 *
 *  Created on: 8 mar. 2022
 *      Author: Ruben Dario Zevallos Lambrescht 1H
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef __linux__
#define SO "Linux"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER __fpurge(stdin);
#include <stdio_ext.h>
#elif _WIN32
#define SO "Windows"
#define LIMPIAR_CONSOLA system("cls");
#define LIMPIAR_BUFFER fflush(stdin);
#define LIMPIAR_SALIDA	setbuf(stdout,NULL);
#elif __APPLE__
#define SO "OSX"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER fpurge(stdin);
#endif



#ifndef UTN_H_
#define UTN_H_

int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);
int utn_getNumeroAleatorio(int desde, int hasta, int iniciar);
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,char minimo, char maximo, int reintentos);
int dividir(float *pResultado, int operador1, int operador2);
int factorial(int n);
int esSoloLetras_Espacio(char str[]);
int getStringLetras(char *mensaje, char *input);
int getStringNumeros(char *mensaje, char *input);
char getChar(char mensaje[]);
int getString(char *string, int longitud);
void insertion(int data[], int len);
unsigned int verifica(void);
int utn_getNombre(char *pResultado, int longitud, char *mensaje,char *mensajeError, int reintentos);
int utn_getTexto(char *pResultado, int longitud, char *mensaje,char *mensajeError, int reintentos);
int utn_getEmail(char *pResultado, int longitud, char *mensaje,char *mensajeError, int reintentos);
long int time_Current(void);
long int time_Add(double secondsAdd);
int esNumerica(char *cadena, int limite);
int esFlotante(char *cadena);

#endif /* UTN_H_ */
