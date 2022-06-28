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
#define LEN_NOMBREJUEGO 20
#define LEN_EMPRESA 30
#define LEN_GENERO 15
//juegoId,juegoNombre,juegoEmpresa,juegoGenero
#define PLATAFORMA 0
#define LABERINTO 1
#define AVENTURA 2
#define OTRO 3
typedef struct
{
	int juegoId;
	char juegoNombre[LEN_NOMBREJUEGO];
	char juegoEmpresa[LEN_EMPRESA];
	int juegoGenero;
}Juego;

Juego* Juego_new();
Juego* Juego_newParametros(char* juegoIDStr,char* juegoNombreStr ,char* juegoEmpresaStr, char* juegoGeneroStr);

void Juego_delete();

int Juego_setJuego_Id(Juego* this,int id);
int Juego_getJuego_Id(Juego* this,int* id);

int Juego_setJuegoIdTxt(Juego* this,char* id);
int Juego_getJuegoIdTxt(Juego* this,char* id);

int Juego_setJuegoNombre(Juego* this,char* nombre);
int Juego_getJuegoNombre(Juego* this,char* nombre);

int Juego_setJuegoEmpresa(Juego* this,char* empresa);
int Juego_getJuegoEmpresa(Juego* this,char* empresa);

int Juego_getJuegoGenero(Juego* this,int* genero);
int Juego_setJuegoGenero(Juego* this,int genero);

int Juego_setGeneroTxt(Juego* this,char* genero);
int Juego_getGeneroTxt(Juego* this,char* genero);


int Juego_printOneJuego(Juego* pSalon);
int Juego_printOneJuegoFile(FILE* archivo, Juego* pSalon);

int Juego_mayor(void* item1,void* item2);
void juego_obtenerValorGenero(int generoInt, char* generoStr);


#endif /* SALON_H_ */
