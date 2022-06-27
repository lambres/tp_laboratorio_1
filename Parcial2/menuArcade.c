#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "menuSalon.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "utn.h"

int getIDArcade(int* nuevoIdArcade);
int putIDArcade(int* nuevoIdArcade);
int auxIndice;
void adminArcades(LinkedList* listaSalones, LinkedList* listaArcades, LinkedList* listaJuegos)
{

	//variabes auxiliares
	int opcion = 0;
	while(opcion!=5)
	{
		printf("\n-------------- MENU ABM ARCADES --------------\n");
		printf("1. INCORPORAR ARCADE\n");
		printf("2. MODIFICAR ARCADE\n");
		printf("3. ELIMINAR ARCADE\n");
		printf("4. IMPRIMIR ARCADE\n");
		printf("5. Salir\n");
		utn_getNumeroInt(&opcion, "Seleccione opcion", "Error reintente", 1, 5, 2);

		switch(opcion)
		{
		case 1:
			if (!getIDArcade(&auxIndice))
			{
				auxIndice++;
			}
			if(!(controller_addArcade(listaSalones,listaArcades,listaJuegos,auxIndice)))
			{
				if (!putIDArcade(&auxIndice))
				{
					printf("Nuevo Id utilizado %d:\n",auxIndice);
				}
			}
			else
			{
				printf("ERROR, VUELVA A INTENTARLO\n");
			}
			break;
		case 2:
			if(controller_editArcade(listaArcades,listaJuegos)==1)
			{
				printf("No se pudo modificar el arcade\n");
			}
			break;
		case 3:
			if(controller_removeArcade(listaSalones , listaArcades, listaJuegos) == 1)
			{
				printf("No se pudo eliminar el arcade\n");
			}
			break;
		case 4:
			if (controller_mostrarArcadeJuego(listaArcades, listaJuegos)==-1)
			{
				printf("No se pudo listar los arcades\n");
			}
			break;
		case 5:
			break;
		}
	}


}


int getIDArcade(int* nuevoIdArcade)
{
	FILE* pArchivo;
	if ((pArchivo=fopen("idArcade.csv","r"))==NULL)
	{
		pArchivo=fopen("idArcade.csv","w");
	}
	fscanf(pArchivo,"%d",nuevoIdArcade);

	printf("Nuevo ID: Arcade %d \n", *nuevoIdArcade);
	return fclose(pArchivo);
}


int putIDArcade(int* nuevoIdArcade)
{
	FILE* pArchivo;
	if (!((pArchivo=fopen("idArcade.csv","r"))==NULL))
	{
		pArchivo=fopen("idArcade.csv","w");
		fprintf(pArchivo,"%d",*nuevoIdArcade);
	}
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}
