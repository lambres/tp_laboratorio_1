#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "menuSalon.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "utn.h"
int getIDSalon(int* nuevoIdSalon);
int putIDSalon(int* nuevoIdSalon);
int auxIndice;
void adminSalones(LinkedList* listaSalones, LinkedList* listaArcades)
{

	//variabes auxiliares
	int opcion = 0;
	while(opcion!=4)
	{
		printf("\n-------------- MENU ABM SALON --------------\n");
		printf("1. ALTA DE SALON\n");
		printf("2. ELIMINAR SALON\n");
		printf("3. LISTAR SALONES\n");
		printf("4. Salir\n");
		utn_getNumeroInt(&opcion, "Seleccione opcion", "Error reintente", 1, 4, 2);

		switch(opcion)
		{
		case 1:
			if (!getIDSalon(&auxIndice))
			{
				auxIndice++;
			}
			if(!(controller_addSalon(listaSalones, auxIndice)))
			{
				if (!putIDSalon(&auxIndice))
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
			if(controller_removeSalon(listaSalones , listaArcades) != 0)
			{
				printf("No se pudo eliminar el salon\n");
			}
			break;
		case 3:
			if (controller_ListSalones(listaSalones)!=0)
			{
				printf("No se pudo listar los salones\n");
			}
			break;
		case 4:
			break;
		}
	}


}


int getIDSalon(int* nuevoIdSalon)
{
	FILE* pArchivo;
	if ((pArchivo=fopen("idSalon.csv","r"))==NULL)
	{
		pArchivo=fopen("idSalon.csv","w");
	}
	fscanf(pArchivo,"%d",nuevoIdSalon);

	printf("Nuevo ID: Salon %d \n", *nuevoIdSalon);
	return fclose(pArchivo);
}


int putIDSalon(int* nuevoIdSalon)
{
	FILE* pArchivo;
	if (!((pArchivo=fopen("idSalon.csv","r"))==NULL))
	{
		pArchivo=fopen("idSalon.csv","w");
		fprintf(pArchivo,"%d",*nuevoIdSalon);
	}
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}
