/*
 * Passenger_Flight.c
 *
 *  Created on: 11 may. 2022
 *      Author: Ruben Dario Zevallos Lambrescht 1H
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Passenger_Flight.h"
static int GetID(void);
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

/// @fn int getDataPassenger_FlightCode(Passenger*, int, eFlight*, int)
/// @brief Funcion que toma datos del usuario para agregar al array, validando que el campo PK_flightcode exista
///  o permita crearlo
/// @param pArray Array Passenger
/// @param pLimite Limite Passenger
/// @param fArray Array eFlight
/// @param fLimite limite eFlight
/// @return -1 si hay un ERROR y 0 si EXITO
int getDataPassenger_FlightCode(Salon *pArray, int pLimite, eFlight *fArray,
	int fLimite) {
	int retorno = -1;
	char auxiliarName[LEN_CARACTERES];
	char auxiliarLastName[LEN_CARACTERES];
	float auxiliarPrice;
	char auxiliarFlightCode[LEN_FLIGHTCODE];
	eFlight auxVuelo;
	int auxiliarTypePassenger;
	int auxiliarId;
	int auxfIndex;
	int flightcodeOk = -1;
	int r;

	if (pArray != NULL && pLimite > 0 && fArray != NULL && fLimite > 0) {
		utn_getTexto(auxiliarFlightCode, LEN_FLIGHTCODE,
				"Ingrese codigo de vuelo\n", "Dato erroneo, 10 caracteres\n",
				2);
		if (eFlight_BuscarPorFlightCode(fArray, pLimite, auxiliarFlightCode)
				== -1) {
			printf("Codigo de vuelo inexiste, desea agregarlo? S/N\n");
			if (verifica() == 'S') {
				auxfIndex = eFlight_ObtenerIndexLibre(fArray, fLimite);
				strncpy(auxVuelo.PK_flightcode, auxiliarFlightCode,
						LEN_FLIGHTCODE);
				auxVuelo.flightStatus = ACTIVO;
				fArray[auxfIndex] = auxVuelo;
				flightcodeOk = 0;
				#ifdef __linux__
					LIMPIAR_BUFFER
				#elif _WIN32
					LIMPIAR_BUFFER
				#elif __APPLE__
					LIMPIAR_BUFFER
				#endif
			} else {
				printf("No se puede agregar pasajero sin Flight Code valido\n");
			}
		} else {
			flightcodeOk = 0;
		}
		if (flightcodeOk == 0
				&& !(utn_getNombre(auxiliarName, LEN_CARACTERES, "Nombre: \n",
						"Error: \n", 2))
				&& !(utn_getNombre(auxiliarLastName, LEN_CARACTERES,
						"Apellido: \n", "Error: \n", 2))
				&& !(utn_getNumeroFloat(&auxiliarPrice, "Precio: \n",
						"precio mayor que cero\n", 1, 10000, 2))
				&& !(utn_getNumeroInt(&auxiliarTypePassenger,
						"Tipo Pasajero (0 -> Turista / 1 -> Ejecutiva / 2-> Primera)\n",
						"Valor no valido\n", 0, 2, 2))) {
			auxiliarId = GetID();
			r = addPassenger(pArray, pLimite, auxiliarId, auxiliarName,
					auxiliarLastName, auxiliarPrice, auxiliarTypePassenger,
					auxiliarFlightCode);
			if (r == 0) {
				printf("Pasajero agregado correctamente %d\n", auxiliarId);
			} else {
				printf("Error en la carga del pasajero\n");
			}
		} else {
			printf("Datos incompletos\n");
		}
		retorno = 0;
	}
	sortPassengers(pArray, pLimite, 1);
	eFlight_Sort(fArray, fLimite, 1);

	return retorno;
}

/// @fn int GetID(void)
/// @brief Obtiene un id único
///
/// @return	Devuleve cada vez que se invoca un id unico incremental
static int GetID(void) {
	static int GetID = 0;
	return GetID++;
}


/// @fn int pasfl_printSumAverage(Passenger*, int, eFlight*, int)
/// @brief Funcion para imprimir el promedio de precio y cantidad de pasajeros activos
///
/// @param pArray Array Passenger
/// @param pLimite Limite estructura passenger
/// @param fArray array flight
/// @param fLimite limite array flight
/// @return retorna 0 si se logró imprimir y -1 si no
int pasfl_printSumAverage(Salon *pArray, int pLimite, eFlight *fArray,
		int fLimite) {
	int retorno = -1;
	float acumPrecio = 0;
	float promPrecio = 0;
	int cantidadRegistros = 0;
	int i;
	int j;
	if (pArray != NULL && pLimite > 0 && fArray != NULL && fLimite > 0) {
		for (i = 0; i < fLimite; i++) {
			if (fArray[i].flightStatus == ACTIVO) {
				for (j = 0; j < pLimite; j++) {
					if (pArray[j].isEmpty == OCUPADO) {
						acumPrecio = acumPrecio + pArray[j].price;
						cantidadRegistros++;
					}
				}
			}
			break;
		}
		if (dividir(&promPrecio, acumPrecio, cantidadRegistros) == 0) {
			printf("Total: %.2f y Promedio de precios: %.2f \n", acumPrecio,
					promPrecio);
		}
		retorno = 0;
	}

	return retorno;
}


/// @fn int pasfl_printSumAverage(Passenger*, int, eFlight*, int)
/// @brief Funcion para imprimir Pasajero x Codigo Activos
///
/// @param pArray Array Passenger
/// @param pLimite Limite estructura passenger
/// @param fArray array flight
/// @param fLimite limite array flight
/// @return retorna 0 si se logró imprimir y -1 si no
int pasfl_printPassengerActivSorted(Salon *pArray, int pLimite, eFlight *fArray,
		int fLimite) {
	int retorno = -1;
	int i;
	int j;
	printf("%-6s", "|ID");
		printf("%-21s", "|Nombre");
		printf("%-21s", "|Apellido");
		printf("%-13s", "|Cod. Vuelo");
		printf("%-11s", "|Precio");
		printf("%-17s", "|Tipo Pasajero");
		printf("|\n");
	if (pArray != NULL && pLimite > 0 && fArray != NULL && fLimite > 0) {
		for (i = 0; i < fLimite; i++) {
			if (fArray[i].flightStatus == ACTIVO) {
				for (j = 0; j < pLimite; j++) {
					if (pArray[j].isEmpty == OCUPADO) {
						printOnePassenger(&pArray[j]);
					}
				}
			}
			break;
		}
		retorno = 0;
	}

	return retorno;
}
/// @fn int modififyPassengerValues(Passenger *pArray, int pLimite, eFlight *fArray,int fLimite)
/// @brief Funcion que permite modificar los valores de ambas estructuras
///
/// @param pArray Array Passenger
/// @param pLimite Tamaño Passenger
/// @param fArray Array eFlight
/// @param fLimite Tamaño eFlight
/// @return devuelve 0 si EXITO y -1 si hubo un problema (ERROR)
int modififyPassengerValues(Salon *pArray, int pLimite, eFlight *fArray,int fLimite)
{
	int retorno = -1;
	//int i;
	char auxTexto[LEN_CARACTERES];
	//char auxFlyCode[LEN_FLIGHTCODE];
	float auxPrecio;
	int auxTipoPasajero;
	int auxiliarId;
	int nrocampo;
	int auxIndex;
	Salon auxiliarPasajero;
	eFlight auxiliarVuelos;
	char auxiliarFlightCode[LEN_FLIGHTCODE];
	int auxfPK_flightcode;
	//ordeno el array y lo muestro para que el usuario seleccione el id a modificar
	sortPassengers(pArray, pLimite, 1);
	printPassenger(pArray, pLimite);

	if (utn_getNumeroInt(&auxiliarId, "Que ID desea modificar\n","Error Valor entre 0 y 1999\n", 0, 1999, 2) == 0)
	{
		//busco si existe el ID ingresado
		auxIndex = findPassengerById(pArray, pLimite, auxiliarId);
		if (auxIndex != -1)
		{
			auxiliarPasajero = pArray[auxIndex];
			printOnePassenger(&auxiliarPasajero);
		}
		utn_getNumeroInt(&nrocampo,"Campo a modificar: 1: Nombre|2:Apellido|3:Cod. Vuelo|4:Precio|5:Tipo Pasajero|\n","Valor no válido\n", 1, 5, 2);
		switch (nrocampo)
		{
		case 1:
			utn_getNombre(auxTexto, LEN_CARACTERES, "Nombre: \n", "Error: \n",2);
			strncpy(pArray[auxIndex].name, auxTexto, LEN_CARACTERES);
			break;
		case 2:
			utn_getNombre(auxTexto, LEN_CARACTERES, "Apellido: \n", "Error: \n",2);
			strncpy(pArray[auxIndex].lastname, auxTexto, LEN_CARACTERES);
			break;
		case 3:
			utn_getTexto(auxiliarFlightCode, LEN_FLIGHTCODE,"Ingrese codigo de vuelo\n", "Dato erroneo, 10 caracteres\n",2);
			if (eFlight_BuscarPorFlightCode(fArray, pLimite, auxiliarFlightCode)== -1)
			{
				printf("Codigo de vuelo inexiste, desea agregarlo? S/N\n");
				if (verifica() == 'S')
				{
					auxfPK_flightcode = eFlight_ObtenerIndexLibre(fArray, fLimite);
					strncpy(auxiliarVuelos.PK_flightcode, auxiliarFlightCode,LEN_FLIGHTCODE);
					auxiliarVuelos.flightStatus = ACTIVO;
					fArray[auxfPK_flightcode] = auxiliarVuelos;
				}
			}
			strncpy(pArray[auxIndex].flycode,auxiliarFlightCode,LEN_FLIGHTCODE);
			break;
		case 4:
			utn_getNumeroFloat(&auxPrecio, "Precio: \n","precio mayor que cero\n", 1, 10000, 2);
			pArray[auxIndex].price = auxPrecio;
			break;
		case 5:
			utn_getNumeroInt(&auxTipoPasajero,"Tipo Pasajero (0 -> Turista / 1 -> Ejecutiva / 2-> Primera)\n","Valor no valido\n", 0, 2, 2);
			pArray[auxIndex].typePassenger = auxTipoPasajero;
			break;
		}
		retorno = 0;
	}
	return retorno;
}
