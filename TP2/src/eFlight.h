/*
 * eFlight.h
 *
 *
 *      Author: Ruben Dario Zevallos Lambrescht 1 H
 */
#ifndef EFLIGHT_H_
#define EFLIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define ACTIVO 0
#define CANCELADO -1
#define LEN_FLIGHTCODE 10
#define LEN_FLIGHTSTATUS 10
//*** eFlight
typedef struct {
	char PK_flightcode[LEN_FLIGHTCODE];
	int flightStatus;
} eFlight;
//***

/** INICIO CABECERAS DE FUNCION*/
int eFlight_Inicializar(eFlight array[], int TAM);
int eFlight_ObtenerIndexLibre(eFlight array[], int TAM);
int eFlight_BuscarPorFlightCode(eFlight array[], int TAM, char ID[]);
void eFlight_MostrarUno(eFlight Gen);
int eFlight_MostrarTodos(eFlight array[], int TAM);
int eFlight_MostrarDadosDeBaja(eFlight array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eFlight_Sort(eFlight array[], int TAM, int criterio);

//ABM
eFlight eFlight_CargarDatos(eFlight array[], int TAM);
int eFlight_Alta(eFlight array[], int TAM);
int eFlight_Baja(eFlight array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
