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
#define SALON_H_
#include "LinkedList.h"


#define LEN_NOMBRE 50
#define LEN_APELLIDO 50
#define LEN_CODVUELO 8
#define LEN_ESTADOVUELO 20
#define LEN_TIPOSALON 20
#define LEN_CHARSALONID 5
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
}Salon;

Salon* Salon_new();
Salon* Salon_newParametros(char* idStr,char* nombreStr ,char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

void Salon_delete();

int Salon_setSalon_Id(Salon* this,int id);
int Salon_getSalon_Id(Salon* this,int* id);

int Salon_setSalon_IdTxt(Salon* this,char* id);
int Salon_getSalon_IdTxt(Salon* this,char* id);

int Salon_setSalon_Nombre(Salon* this,char* nombre);
int Salon_getSalon_Nombre(Salon* this,char* nombre);

int Salon_setSalon_Direccion(Salon* this,char* apellido);
int Salon_getSalon_Direccion(Salon* this,char* apellido);

int Salon_setPrecio(Salon* this,float precio);
int Salon_getPrecio(Salon* this,float* precio);

int Salon_setPrecioTxt(Salon* this,char* precio);
int Salon_getPrecioTxt(Salon* this,char* precio);

int Salon_setTipoPasajero(Salon* this,int tipoPasajero);
int Salon_getTipoPasajero(Salon* this,int* tipoPasajero);

int Salon_setCodigoVuelo(Salon* this,char* codigoVuelo);
int Salon_getCodigoVuelo(Salon* this,char* codigoVuelo);

int Salon_setEstadoVuelo(Salon* this,char* estadoVuelo);
int Salon_getEstadoVuelo(Salon* this,char* estadoVuelo);

int Salon_validateTipoSalon(char* tipoPasajeroStr);
int Salon_getTipoSalonStr(int tipoPasajero, char * tipoPasajeroStr);
int Salon_setTipoSalonStr(Salon* this,char* tipoPasajero);

int Salon_printOneSalon(Salon* pPasajero);
int Salon_printOneSalonFile(FILE* archivo, Salon* pPasajero);

int Salon_mayor(void* item1,void* item2);

#endif /* PASSENGER_H_ */
