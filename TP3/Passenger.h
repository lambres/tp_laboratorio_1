/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"


#define LEN_NOMBRE 50
#define LEN_APELLIDO 50
#define LEN_CODVUELO 8
#define LEN_ESTADOVUELO 20
#define LEN_TIPOPASAJERO 20
#define LEN_CHARID 5
#define LEN_CHARPRICE 10


typedef struct
{
	int id;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_APELLIDO];
	float precio;
	char codigoVuelo[LEN_CODVUELO];
	int tipoPasajero;
	char estadoVuelo[LEN_ESTADOVUELO];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr ,char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setIdTxt(Passenger* this,char* id);
int Passenger_getIdTxt(Passenger* this,char* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_getPrecioTxt(Passenger* this,char* precio);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_validatetipoPasajero(char* tipoPasajeroStr);
int Passenger_getTipoPasajeroStr(int tipoPasajero, char * tipoPasajeroStr);
int Passenger_setTipoPasajeroStr(Passenger* this,char* tipoPasajero);

int Passenger_printOne(Passenger* pPasajero);
int Passenger_printOneFile(FILE* archivo, Passenger* pPasajero);

int Passenger_mayor(void* item1,void* item2);

#endif /* PASSENGER_H_ */
