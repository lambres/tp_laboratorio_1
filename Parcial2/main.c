#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "menuSalon.h"
#include "menuArcade.h"
#include "menuJuegos.h"
#include "menuInformes.h"

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
			printf("1. ABM Salones\n");
			printf("2. ABM Arcades\n");
			printf("3. ABM Juegos\n");
			printf("4. INFORMES\n");
			printf("5. Salir\n");
			utn_getNumeroInt(&option, "Seleccione opcion", "Error reintente", 1, 9, 1);
			switch(option)
			{
			case 1:
				adminSalones(listaSalon,listaArcade);
				break;
			case 2:
				adminArcades(listaSalon,listaArcade,listaJuego);
				break;
			case 3:
				adminJuegos(listaJuego);
				break;
			case 4://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)
				adminInformes(listaSalon,listaArcade,listaJuego);
				break;
			case 5://Salir
				if(!controller_saveFiles(listaSalon, listaArcade, listaJuego))
				{
					puts("Gracias por usar el software");
				}
				break;
			}

		}while(option != 5);
		return 0;
    }
}

