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
#ifndef ARCADE_H_
#define ARCADE_H_
#include "LinkedList.h"


#define LEN_NACIONALIDAD 30
#define LEN_TIPOSONIDO 8
#define LEN_CHARARCADEID 5
#define LEN_CANTJUGADORES 5
#define LEN_CAPACIDAD 5
#define STEREO 0
#define MONO 1
//Arcade_id,Arcade_nacionalidad,Arcade_tipoSonido,Arcade_cantJugadores,Arcade_capacidad,fkIdSalon,fkIdJuego

typedef struct
{
	int Arcade_id;
	char Arcade_nacionaliad[LEN_NACIONALIDAD];
	int Arcade_tipoSonido;
	int Arcade_cantJugadores;
	int Arcade_capacidad;
	int fkIdSalon;
	int fkidJuego;
}Arcade;

Arcade* Arcade_new();
Arcade* Arcade_newParametros(char* idArcadeStr,char* nacionalidadStr ,char* tipoSonidoStr, char* cantJugadoresStr,
							 char* capacidadStr, char* fkidSalonStr, char* fkidJuegoStr);
void Arcade_delete();

int Arcade_setArcade_Id(Arcade* this,int id);
int Arcade_getArcade_Id(Arcade* this,int* id);

int Arcade_setIdTxt(Arcade* this,char* id);
int Arcade_getIdTxt(Arcade* this,char* id);

int Arcade_setNacionalidad(Arcade* this,char* nombre);
int Arcade_getNacionalidad(Arcade* this,char* nombre);

int Arcade_setCantJugadores(Arcade* this,int cantidad);
int Arcade_getCantJugadores(Arcade* this,int* direccion);

int Arcade_setCantJugadoresTxt(Arcade* this,char* cantJugadores);

int Arcade_setCapacidadTxt(Arcade* this,char* capacidad);
int Arcade_setCapacidad(Arcade* this,int cantidad);

int Arcade_setfkIdSalon(Arcade* this,int fkIdSalon);
int Arcade_getfkIdSalon(Arcade* this,int* fkIdSalon);
int Arcade_setfkSalonTxt(Arcade* this,char* id);

int Arcade_setfkIdJuego(Arcade* this,int fkIdJuego);
int Arcade_setfkJuegoTxt(Arcade* this,char* id);

int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);

int Arcade_setTipoSonidoTxt(Arcade* this,char* tipoSonido);
int Arcade_getTipoSonidoTxt(Arcade* this,char* tipoSonido);
int Arcade_getfkIdJuego(Arcade* this,int* fkIdJuego);


int Arcade_printOne(Arcade* pSalon);
int Arcade_printOneFile(FILE* archivo, Arcade* pSalon);

int Arcade_mayor(void* item1,void* item2);
int arcade_obtenerValorTipoSonido(int tipoInt, char* tipoStr);
int Arcade_filterArgentina(void* item1, char* pais);

#endif /* SALON_H_ */
