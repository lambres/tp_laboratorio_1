#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "menuSalon.h"
#include "menuArcade.h"

#include "utn.h"



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    //int auxIndiceSalon;
    //int auxIndiceArcade;
    //int auxIndiceJuego;

    LinkedList* listaSalon = ll_newLinkedList();
    LinkedList* listaArcade = ll_newLinkedList();
    LinkedList* listaJuego = ll_newLinkedList();

    if(!controller_loadFiles(listaSalon, listaArcade , listaJuego))
    {
		do{
			#ifdef __linux__
				LIMPIAR_CONSOLA
			#elif _WIN32
				LIMPIAR_CONSOLA
			#elif __APPLE__
				LIMPIAR_CONSOLA
			#endif
			printf("1. ABM Salones\n");
			printf("2. ABM Arcades\n");
			printf("9. Listar los arcade para más de 2 jugadores, indicando ID de arcade,"
					" cantidad de jugadores, nombre del juego, su género y nombre del salón al que pertenece.\n");
			printf("3. Alta de pasajero\n");
			printf("4. Modificar datos de pasajero\n");
			printf("5. Baja de pasajero\n");
			printf("6. Listar pasajeros\n");
			printf("7. Ordenar pasajeros\n");
			printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
			printf("10. Salir\n");
			utn_getNumeroInt(&option, "Seleccione opcion", "Error reintente", 1, 10, 1);
			switch(option)
			{
			case 1:
				adminSalones(listaSalon,listaArcade);
				break;
			case 2:
				adminArcades(listaSalon,listaArcade,listaJuego);
				break;
			case 9://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)
				if(controller_mostrarArcadeSalon(listaSalon,listaArcade,listaJuego))
				{
					printf("No se pudo listar\n");
				}
				break;
			case 10://Salir
				if(!controller_saveFiles(listaSalon, listaArcade, listaJuego))
				{
					puts("Gracias por usar el software");
				}
				break;
			}

			/*
				case 3://Alta de pasajero
					if (!getIDNuevo(&auxIndice))
					{
						auxIndice++;
					}
					if(!(controller_addSalon(listaPasajeros, auxIndice)))
					{
						if (!putIDNuevo(&auxIndice))
						{
							printf("Nuevo Id utilizado %d:\n",auxIndice);
						}
					}
					else
					{
						printf("ERROR, VUELVA A INTENTARLO\n");
					}
					break;
				case 4://Modificar datos de pasajero
					if(controller_editSalon(listaPasajeros) == 1)
					{
						printf("Indice no encontrado\n");
					}
					break;
				case 6://Listar pasajeros
					if (controller_ListPassenger(listaPasajeros)!=0)
					{
						printf("No se pudo listar los pasajeros\n");
					}
					break;
				case 7://Ordenar pasajeros
					if(controller_sortPassenger(listaPasajeros)!=0)
					{
						printf("No se pudieron ordenar los pasajeros\n");
					}
					break;
				case 8://Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
					if(controller_saveAsText("data.csv",listaPasajeros)==1)
					{
						printf("No se pudo guardar el archivo en formato texto\n");
					}
					break;
				case 9://Guardar los datos de los pasajeros en el archivo data.dat (modo binario)
					if(controller_saveAsBinary("data.dat", listaPasajeros)==1)
					{
						printf("No se pudo guardar el archivo en formato binario\n");
					}
					break;*/

		}while(option != 10);
		return 0;
    }
}

