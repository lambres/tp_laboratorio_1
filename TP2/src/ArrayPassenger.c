/*
 * ArrayPassenger.c
 *
 *
 *      Author: Ruben Dario Zevallos Lambrescht 1 H
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayPassenger.h"

/** \brief	To indicate that all position in the array are empty,
 * 			this function put the flag (isEmpty) in TRUE in all
 * 			position of the array
 * \param 	list Passenger* Pointer to array of passenger
 * \param 	len int Array length
 * \return 	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger *list, int len) {
	int retorno = -1;
	int i;
	for (i = 0; i < len; i++) {
		list[i].isEmpty = LIBRE;
		retorno = 0;
	}

	return retorno;
}

/** \brief	add in a existing list of passengers the values received as parameters
 *			in the first empty position
 * \param 	list passenger*
 * \param 	len int
 * \param 	id int
 * \param 	name[] char
 * \param 	lastName[] char
 * \param 	price float
 * \param 	typePassenger int
 * \param 	flycode[] char
 * \return 	int Return (-1) if Error [Invalid length or NULL pointer or without
 * \			free space] - (0) if Ok
 */
int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
		float price, int typePassenger, char flycode[]) {
	int retorno = -1;
	Passenger bufferPasajero;
	if (list != NULL
			&& len
					> 0&& id >= 0 && name != NULL && lastName != NULL && price > 0 && typePassenger >= 0 && typePassenger <=2 && flycode != NULL) {
		strncpy(bufferPasajero.flycode, flycode, LEN_FLIGHTCODE);
		strncpy(bufferPasajero.lastname, lastName, LEN_CARACTERES);
		strncpy(bufferPasajero.name, name, LEN_CARACTERES);
		bufferPasajero.price = price;
		bufferPasajero.typePassenger = typePassenger;
		bufferPasajero.isEmpty = OCUPADO;
		bufferPasajero.id = id;
		list[Passenger_ObtenerIndexLibre(list, len)] = bufferPasajero;
		retorno = 0;
	}
	return retorno;
}

/** \brief find a Passenger by Id en returns the index position in array.
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return passenger index position or (-1) if [Invalid length or
 * \NULL pointer received or passenger not found]
 *
 */
int findPassengerById(Passenger *list, int len, int id) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0 && id >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == OCUPADO) {
				if (list[i].id == id) {
					retorno = i;
				}
			}
		}
	}
	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 * \find a passenger] - (0) if Ok
 *
 */
int removePassenger(Passenger *list, int len, int id) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0 && id >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == OCUPADO) {
				if (list[i].id == id) {
					list[i].isEmpty = LIBRE;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief 	Sort the elements in the array of passengers, the argument order
 *			indicate UP or DOWN order
 *
 * \param 	list Passenger* Array a ser ordenado
 * \param 	len int tamaño del array
 * \param 	order int [1] indicate UP - [0] indicate DOWN
 * \return 	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengers(Passenger *list, int len, int order) {
	int retorno = -1;
	int flagSwap;
	int auxComparacion;
	int i;
	Passenger buffer;
	if (list != NULL && len > 0 && (order == 0 || order == 1)) {
		do {
			flagSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (list[i].isEmpty == OCUPADO) {
					auxComparacion = strncmp(list[i].lastname,
							list[i + 1].lastname, LEN_CARACTERES);
					if (order == 1) {
						if (auxComparacion > 0
								|| (auxComparacion == 0
										&& (list[i].typePassenger
												> list[i + 1].typePassenger))) {
							flagSwap = -1;
							buffer = list[i];
							list[i] = list[i + 1];
							list[i + 1] = buffer;
						}
					} else {
						if (auxComparacion < 0
								|| (auxComparacion == 0
										&& (list[i].typePassenger
												< list[i + 1].typePassenger))) {
							flagSwap = -1;
							buffer = list[i];
							list[i] = list[i + 1];
							list[i + 1] = buffer;
						}
					}
				}
			}
			len--;
		} while (flagSwap);
		retorno = 0;
	}
	return retorno;
}

/// @fn void printOnePassenger(Passenger[])
/// @brief imprimo el dato pasado como argumento
///
/// @param pPassenger estructura pasada como dato para imprimir
void printOnePassenger(Passenger pPassenger[]) {
	//PRINTF DE UN SOLO Passenger
	char auxTipo[10];
	printf("|%5d", pPassenger->id);
	printf("|%-20s", pPassenger->name);
	printf("|%-20s", pPassenger->lastname);
	printf("|%12s", pPassenger->flycode);
	printf("|%10.2f", pPassenger->price);
	switch (pPassenger->typePassenger) {
	case TURISTA:
		strncpy(auxTipo, "Turista", 10);
		break;
	case PRIMERA:
		strncpy(auxTipo, "Primera", 10);
		break;
	case EJECUTIVA:
		strncpy(auxTipo, "Ejecutiva", 10);
		break;
	}
	printf("|%16s", auxTipo);
	printf("|\n");
}
/** \brief print the content of passengers array
 *
 * \param list Passenger*
 * \param length int
 * \return int
 *
 */
int printPassenger(Passenger *list, int length) {
	int retorno = -1;
	int i;
	Passenger auxPasajero;
	printf("%-6s", "|ID");
	printf("%-21s", "|Nombre");
	printf("%-21s", "|Apellido");
	printf("%-13s", "|Cod. Vuelo");
	printf("%-11s", "|Precio");
	printf("%-17s", "|Tipo Pasajero");
	printf("|\n");
	for (i = 0; i < length; i++) {
		if (list[i].isEmpty == OCUPADO) {
			auxPasajero = list[i];
			printOnePassenger(&auxPasajero);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
 *			indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengersByCode(Passenger *list, int len, int order) {
	int retorno = -1;
	int flagSwap;
	int auxComparacion;
	int i;
	Passenger buffer;
	if (list != NULL && len > 0 && (order == 0 || order == 1)) {
		do {
			flagSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (list[i].isEmpty == OCUPADO) {
					auxComparacion = strncmp(list[i].flycode,
							list[i + 1].flycode, LEN_CARACTERES);
					if (order == 1) {
						if (auxComparacion > 0
								|| (auxComparacion == 0
										&& (list[i].typePassenger
												> list[i + 1].typePassenger))) {
							flagSwap = -1;
							buffer = list[i];
							list[i] = list[i + 1];
							list[i + 1] = buffer;
						}
					} else {
						if (auxComparacion < 0
								|| (auxComparacion == 0
										&& (list[i].typePassenger
												< list[i + 1].typePassenger))) {
							flagSwap = -1;
							buffer = list[i];
							list[i] = list[i + 1];
							list[i + 1] = buffer;
						}
					}
				}
			}
			len--;
		} while (flagSwap);
		retorno = 0;
	}
	return retorno;
}

/// @fn int Passenger_ObtenerIndexLibre(Passenger[], int)
/// @brief Buscar primer posicion vacia
///
/// @param array Array de Passenger donde buscar
/// @param TAM Tamaño del array de Passenger
/// @return Devuelve el indice de la posicion vacia si lo encuentra y -1 si no hay (ERROR)
int Passenger_ObtenerIndexLibre(Passenger array[], int TAM) {
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/// @fn int Passenger_ObtenerIndexOcupado(Passenger[], int)
/// @brief Buscar primer posicion ocupada
///
/// @param array Array de Passenger donde buscar
/// @param TAM Tamaño del array de Passenger
/// @return Devuelve el indice de la posicion ocupada si lo encuentra y -1 si no hay (ERROR)
int Passenger_ObtenerIndexOcupado(Passenger array[], int TAM) {
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == OCUPADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/// @fn int getPassengerId(Passenger*, int, int)
/// @brief Obtengo el id pasando el index
///
/// @param array Puntero a la estructura creada Passenger
/// @param limite Tamaño del puntero
/// @param indice indice buscado
/// @return devuelve el ID (EXITO) buscado si lo encuentra y -1 si no lo encuentra (ERROR)
int getPassengerId(Passenger *array, int limite, int indice) {
	int retorno = -1;
	int i;
	if (array != NULL && limite > 0 && indice < limite) {
		for (i = 0; i < limite; i++) {
			if (i == indice) {
				retorno = i;
			}
		}
	}
	return retorno;
}

