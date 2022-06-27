#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "menuInformes.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "utn.h"


void adminInformes(LinkedList* listaSalon,LinkedList* listaArcade,LinkedList* listaJuego)
{

	int opcion = 0;
	while(opcion!=8)
	{
		printf("\n\n-------------- MENU INFORMES --------------\n\n");
		printf("1.\tListar los salones con mas de 4 arcade. Indicando ID de salon, nombre,\n "
				"\tdireccion y tipo de salon.\n\n");
		printf("2.\tListar los arcade para mas de 2 jugadores, indicando ID de arcade, \n"
				"\tcantidad de jugadores, nombre del juego, su genero y nombre del salon al que pertenece\n\n");
		printf("3.\tListar toda la información de un salon en especifico ingresado por el usuario.\n "
				"\tImprimir ID de salon, nombre, tipo y direccion.\n\n");
		printf("4.\tUn salon se encuentra completo si posee al menos 4 juegos del genero plataforma,\n "
				"\t3 del genero laberinto y 5 del genero Aventura. \n"
				"\tListar los salones que cumplan con este minimo de requisito\n\n");
		printf("5.\tListar todos los arcades de un salon determinado ingresando su ID. \n"
				"\tInformar nombre y tipo de salon, listar todos los arcade con sus datos \n"
				"\tjunto con el nombre del juego que lo compone\n\n");
		printf("6.\tImprimir el salon con mas cantidad de arcade, indicando todos los \n"
				"\tdatos del salon y la cantidad de arcade que posee. Ordenado de manera ascendente\n\n");
		printf("7.\tListar los arcades que cumplan con sonido MONO y el genero de su juego sea \n"
				"\tPLATAFORMA, informando nombre de juego, genero y cantidad de jugadores que \n"
				"\tsoporta el arcade. El listado debera estar ordenado por nombre de juego.\n\n");
		printf("8.\tSalir\n");
		utn_getNumeroInt(&opcion, "Seleccione opcion", "Error reintente", 1, 8, 2);

		switch(opcion)
		{
		case 1:

			break;
		case 2:
			if(controller_mostrarArcadeSalon(listaSalon,listaArcade,listaJuego))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:
			break;
		}
	}


}


