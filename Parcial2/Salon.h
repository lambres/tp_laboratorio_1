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
#ifndef SALON_H_
#define SALON_H_
#include "LinkedList.h"


#define LEN_NOMBRE 20
#define LEN_DIRECCION 20
#define LEN_TIPOSALON 20
#define LEN_CHARSALONID 5
#define SHOPPING 1
#define LOCAL 2
//Salon_id,Salon_nombre,Salon_direccion,Salon_tipo

typedef struct
{
	int Salon_id;
	char Salon_nombre[LEN_NOMBRE];
	char Salon_direccion[LEN_DIRECCION];
	int Salon_tipo;
}Salon;

Salon* Salon_new();
Salon* Salon_newParametros(char* idSalonStr,char* nombreStr ,char* direccionStr, char* tipoStr);

void Salon_delete();

int Salon_setSalon_Id(Salon* this,int id);
int Salon_getSalon_Id(Salon* this,int* id);

int Salon_setSalon_IdTxt(Salon* this,char* id);
int Salon_getSalon_IdTxt(Salon* this,char* id);

int Salon_setSalon_Nombre(Salon* this,char* nombre);
int Salon_getSalon_Nombre(Salon* this,char* nombre);

int Salon_setSalon_Direccion(Salon* this,char* direccion);
int Salon_getSalon_Direccion(Salon* this,char* direccion);

int Salon_validateTipoSalon(char* tipoSalonStr);

int Salon_getTipoSalonStr(Salon* this, char* tipoSalonStr);
int Salon_setTipoSalonStr(Salon* this, char* tipoSalon);

int Salon_setTipoSalon(Salon* this,int tipoSalon);


int Salon_printOneSalon(Salon* pSalon);
int Salon_printOneSalonFile(FILE* archivo, Salon* pSalon);

int Salon_mayor(void* item1,void* item2);
int salon_obtenerValorTipo(int tipoInt, char* tipoStr);

#endif /* SALON_H_ */
