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
#ifndef JUEGO_H_
#define JUEGO_H_
#include "LinkedList.h"

#define LEN_CHARJUEGOID 5
#define LEN_NOMBREJUEGO 30
#define LEN_EMPRESA 30
#define LEN_GENERO 15
//juegoId,juegoNombre,juegoEmpresa,juegoGenero

typedef struct
{
	int juegoId;
	char juegoNombre[LEN_NOMBREJUEGO];
	char juegoEmpresa[LEN_EMPRESA];
	char juegoGenero[LEN_GENERO];
}Juego;

Juego* Juego_new();
Juego* Juego_newParametros(char* juegoIDStr,char* juegoNombreStr ,char* juegoEmpresaStr, char* juegoGeneroStr);

void Juego_delete();

int Juego_setJuego_Id(Juego* this,int id);
int Juego_getJuego_Id(Juego* this,int* id);

int Juego_setjuegoIdTxt(Juego* this,char* id);
int Juego_getjuegoIdTxt(Juego* this,char* id);

int Juego_setjuegoNombre(Juego* this,char* nombre);
int Juego_getJuegoNombre(Juego* this,char* nombre);

int Juego_setjuegoEmpresa(Juego* this,char* empresa);
int Juego_getJuegoEmpresa(Juego* this,char* empresa);

int Juego_getjuegoGenero(Juego* this, char * genero);
int Juego_setjuegoGenero(Juego* this,char* genero);

int Juego_printOneJuego(Juego* pSalon);
int Juego_printOneJuegoFile(FILE* archivo, Juego* pSalon);

int Juego_mayor(void* item1,void* item2);

#endif /* SALON_H_ */
