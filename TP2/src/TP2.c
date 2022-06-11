/*
 ============================================================================
 Name        : TP2.c
 Author      : Ruben Dario Zevallos Lambrescht 1ºH
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Passenger_Flight.h"

#define PAS_ELEMENTS 2000 //2000
#define FLI_ELEMENTS 100

int main(void) {
	#ifdef _WIN32
		LIMPIAR_SALIDA
	#endif
	Passenger pasajeros[PAS_ELEMENTS];
	eFlight vuelos[FLI_ELEMENTS];

	int auxiliarId = 0;
	int r = 0;
	int s = 0;
	int opcion = 0;
	int opcionInformes = 0;
	r = initPassengers(pasajeros, PAS_ELEMENTS);
	s = eFlight_Inicializar(vuelos, FLI_ELEMENTS);
	if (r == 0 && s == 0) {
		while (opcion != 5) {
			if (utn_getNumeroInt(&opcion,
					"1.-ALTAS:\n2.-MODIFICAR\n3.-BAJA\n4.-INFORMES\n5.-TERMINAR\n",
					"Error opcion no valida:\n", 0, 5, 2)) {
				opcion = 5;
			}
			switch (opcion) {
			case 1: //ALTA
				if (Passenger_ObtenerIndexLibre(pasajeros, PAS_ELEMENTS)
						!= -1) {
					getDataPassenger_FlightCode(pasajeros, PAS_ELEMENTS, vuelos,
					FLI_ELEMENTS);
				} else {
					printf("No hay lugar para agregar pasajeros\n");
					break;
				}

				break;
			case 2: //MODIFICAR
				if (Passenger_ObtenerIndexOcupado(pasajeros, PAS_ELEMENTS)!= -1) {
					modififyPassengerValues(pasajeros, PAS_ELEMENTS, vuelos, FLI_ELEMENTS);
				} else {
					printf(
							"No se puede ingresar a esta sección hasta que no se ingresen valores\n");
				}
				break;
			case 3: //BAJA
				if (Passenger_ObtenerIndexOcupado(pasajeros, PAS_ELEMENTS)
						!= -1) {
					sortPassengers(pasajeros, PAS_ELEMENTS, 1);
					printPassenger(pasajeros, PAS_ELEMENTS);
					r = utn_getNumeroInt(&auxiliarId, "Que id desea Eliminar\n",
							"Error Valor entre 0 y 1999\n", 0, 1999, 2);
					if (r == 0) {
						printf("Id %d Eliminado correctamente\n",
								removePassenger(pasajeros, PAS_ELEMENTS,
										auxiliarId));
					}
				} else {
					printf(
							"No se puede ingresar a esta sección hasta que no se ingresen valores\n");
				}
				break;
			case 4: //INFORMES
				if (Passenger_ObtenerIndexOcupado(pasajeros, PAS_ELEMENTS)
						!= -1) {
					while (opcionInformes != 4) {
						if (utn_getNumeroInt(&opcionInformes,
								"\n1.-Pasajero x Apellido y Tipo:\n2.-Total "
										"y Promedio Precios\n3.-Pasajero x Codigo Activos\n4.-TERMINAR\n",
								"Error opcion no valida:\n", 1, 4, 2)) {
							opcionInformes = 4;
						}
						switch (opcionInformes) {
						case 1: //Pasajero x Apellido y Tipo
							sortPassengers(pasajeros, PAS_ELEMENTS, 1);
							printPassenger(pasajeros, PAS_ELEMENTS);
							break;
						case 2: // Total y Promedio de precios
							pasfl_printSumAverage(pasajeros, PAS_ELEMENTS,
									vuelos, FLI_ELEMENTS);
							break;
						case 3: //Pasajero x Codigo Activos
							sortPassengersByCode(pasajeros, PAS_ELEMENTS, 1);
							pasfl_printPassengerActivSorted(pasajeros, PAS_ELEMENTS, vuelos, FLI_ELEMENTS);
							break;
						case 4: //Terminar
							break;
						}
					}
				} else {
					printf(
							"No se puede ingresar a esta sección hasta que no se ingresen valores\n");
				}
				opcionInformes = 0;
				break;
			case 5:
				break;
			}
		}
	} else {
		printf("No se pudo inicializar el array\n");
	}
	printf("Gracias por usar el software!");
	return EXIT_SUCCESS;
}
