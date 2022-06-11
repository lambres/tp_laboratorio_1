/*
 * eFlight.c
 *
 *
 *      Author: Ruben Dario Zevallos Lambrescht 1 H
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eFlight.h"


/// @fn int eFlight_Inicializar(eFlight[], int)
/// @brief Inicializo la estructura con valores CANCELADO en el flighstatus
///
/// @param array array de estructura eFlight
/// @param TAM Tamaño del array
/// @return retorna 0 si salio EXITO y -1 si hubo problemas
int eFlight_Inicializar(eFlight array[], int TAM) {
	int i;
	int retorno = -1;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "ACTIVO"
			array[i].flightStatus = CANCELADO;
		}
		retorno = 0;
	}
	return retorno;
}
/// @fn int eFlight_ObtenerIndexLibre(eFlight[], int)
/// @brief Obtiene un indice libre en el caso de encontrar
///
/// @param array array vuelo
/// @param TAM tamaño del array
/// @return 0 EXITO en el caso de que haya un lugar libre y -1 si no lo hay ERROR
int eFlight_ObtenerIndexLibre(eFlight array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "CANCELADO"
			if (array[i].flightStatus == CANCELADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "ACTIVO" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
/// @fn int eFlight_BuscarPorFlightCode(eFlight[], int, char[])
/// @brief busca dentro del array eFlight por campo PK_flightcode
///
/// @param array array donde buscar
/// @param TAM tamaño del array
/// @param ID PK_flightcode a buscar
/// @return 0 EXITO si lo encuentra, caso contrario -1
int eFlight_BuscarPorFlightCode(eFlight array[], int TAM, char ID[]) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if ((strncmp(array[i].PK_flightcode, ID, LEN_FLIGHTCODE) == 0)
					&& array[i].flightStatus == ACTIVO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/// @fn void eFlight_MostrarUno(eFlight)
/// @brief muestra solo un valor pasado por parametro
///
/// @param Flight campo con formato de estructura eFlight
void eFlight_MostrarUno(eFlight Flight) {
	//PRINTF DE UN SOLO eFlight
	printf("%11s\n", Flight.PK_flightcode);
	printf("%14d\n", Flight.flightStatus);
}
/// @fn int eFlight_MostrarTodos(eFlight[], int)
/// @brief Funcion que muetra en pantalla todos los datos activos de la estructura eFlight
///
/// @param array array pasado a ser listado
/// @param TAM Tamaño del array
/// @return retorna 0 ERROR si no puede listarlo y 1 si logró imprimir al menos un registro
int eFlight_MostrarTodos(eFlight array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO eFlight");
	printf("|%11s|%14s|\n", "StatusCode", "Flight Status"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].flightStatus == ACTIVO) {
				//MUESTRO UN SOLO Gen
				eFlight_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO eFlight PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

/// @fn int eFlight_MostrarDadosDeBaja(eFlight[], int)
/// @brief Funcion que muetra en pantalla todos los datos cancelados de la estructura eFlight
///
/// @param array array pasado a ser listado
/// @param TAM Tamaño del array
/// @return retorna 0 ERROR si no puede listarlo y 1 si logró imprimir al menos un registro
int eFlight_MostrarDadosDeBaja(eFlight array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Vuelos Inactivos\n");
	printf("|%11s|%14s|\n", "StatusCode", "Flight Status"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].flightStatus == CANCELADO) {
				//MUESTRO UN SOLO eFlight
				eFlight_MostrarUno(array[i]);
				//CONTADOR DE eFlight
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO eFlight PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

/// @fn eFlight eFlight_CargarDatos(eFlight[], int)
/// @brief
///
/// @param array
/// @param TAM
/// @return
eFlight eFlight_CargarDatos(eFlight array[], int TAM) {
	eFlight auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	char auxCodigo[LEN_FLIGHTCODE];
	utn_getNombre(auxCodigo, LEN_FLIGHTCODE, "Ingrese Codigo de vuelo\n",
			"Valor invalido (10 caracteres MAX)\n", 2);
	auxiliar.flightStatus = ACTIVO;
	return auxiliar;
}
/// @fn int eFlight_Alta(eFlight[], int)
/// @brief   Funcion para dar de alta valores a la estructura eFlight
///
/// @param array puntero a la estructura
/// @param TAM Tamaño del array
/// @return 0 si hubo un ERROR y 1 EXITO
int eFlight_Alta(eFlight array[], int TAM) {
	int rtn = 0;
	eFlight auxFlight;

	//BUSCO ESPACIO EN ARRAY
	int index = eFlight_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY ACTIVO
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxFlight = eFlight_CargarDatos(array, TAM);
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL - Tomo el valor cargado manualemnte verificando que no exista
		//auxFlight.PK_flightcode = eFlight_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxFlight.flightStatus = ACTIVO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX ACTIVO OBTENIDO PREVIAMENTE
		array[index] = auxFlight;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

/// @fn int eFlight_Baja(eFlight[], int)
/// @brief Array para elimanar un registro del array
///
/// @param array array con el contenido donde realizar la baja
/// @param TAM tamaño del array
/// @return 0 en case de ERROR y 1 EXITO
int eFlight_Baja(eFlight array[], int TAM) {
	int rtn = 0;
	char FlightCode;
	int index;
	int flag = 0;
	int confirma = 0;

	//LISTO TODOS LOS eFlight
	if (eFlight_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY eFlight DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY eFlight PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		utn_getNombre(&FlightCode, LEN_FLIGHTCODE,
				"Ingrese Código de vuelo a eliminar\n", "Valor inexistente", 2);

		//BUSCO INDEX POR PK_flightcode EN ARRAY
		while (eFlight_BuscarPorFlightCode(array, TAM, &FlightCode) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			utn_getNombre(&FlightCode, LEN_FLIGHTCODE,
					"Ingrese Código de vuelo a eliminar\n", "Valor inexistente",
					2);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eFlight_BuscarPorFlightCode(array, TAM, &FlightCode);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		utn_getNumeroInt(&confirma, "Confirma la baja? 1: Si | 0: No\n",
				"Valor invalido 1: Si | 0: No\n", 0, 1, 2);
		if (confirma == 1) {
			//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			array[index].flightStatus = CANCELADO;
			//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			rtn = 1;
		} else {
			printf("Baja cancelada por el usuario\n");
		}
	}

	return rtn;
}



int eFlight_Sort(eFlight array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eFlight aux;

	/** EJEMPLO DE SORT CON PK_flightcode DE eFlight
	 MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	 CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	 CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	 UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	 */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].flightStatus == ACTIVO
							&& array[j].flightStatus == ACTIVO) {
						//CRITERIO DE ORDENAMIENTO
						if ((strncmp(array[i].PK_flightcode,
								array[j].PK_flightcode, LEN_FLIGHTCODE) > 0)) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].flightStatus == ACTIVO
							&& array[j].flightStatus == ACTIVO) {
						//CRITERIO DE ORDENAMIENTO
						if ((strncmp(array[i].PK_flightcode,
								array[j].PK_flightcode, LEN_FLIGHTCODE) < 0)) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}
