#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "menuJuegos.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "utn.h"

int getIDJuego(int* nuevoIdJuego);
int putIDJuego(int* nuevoIdJuego);
int auxIndice;
void adminJuegos(LinkedList* listaJuego)
{

	//variabes auxiliares
	int opcion = 0;
	while(opcion!=3)
	{
		printf("\n-------------- MENU ABM JUEGOS --------------\n");
		printf("1. AGREGAR JUEGO\n");
		printf("2. IMPRIMIR JUEGO\n");
		printf("3. Salir\n");
		utn_getNumeroInt(&opcion, "Seleccione opcion", "Error reintente", 1, 5, 2);

		switch(opcion)
		{
		case 1:
			if (!getIDJuego(&auxIndice))
			{
				auxIndice++;
			}
			if(!(controller_addJuego(listaJuego,auxIndice)))
			{
				if (!putIDJuego(&auxIndice))
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
			if (controller_ListJuegos(listaJuego)==1)
			{
				printf("No se pudo listar los arcades\n");
			}
			break;
		case 3:
			break;
		}
	}


}


int getIDJuego(int* nuevoIdJuego)
{
	FILE* pArchivo;
	if ((pArchivo=fopen("idJuego.csv","r"))==NULL)
	{
		pArchivo=fopen("idJuego.csv","w");
	}
	fscanf(pArchivo,"%d",nuevoIdJuego);

	printf("Nuevo ID: Arcade %d \n", *nuevoIdJuego);
	return fclose(pArchivo);
}


int putIDJuego(int* nuevoIdJuego)
{
	FILE* pArchivo;
	if (!((pArchivo=fopen("idJuego.csv","r"))==NULL))
	{
		pArchivo=fopen("idJuego.csv","w");
		fprintf(pArchivo,"%d",*nuevoIdJuego);
	}
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}
