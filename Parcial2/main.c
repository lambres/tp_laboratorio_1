#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"
#include "Salon.h"
#include "utn.h"

int getIDNuevo(int* nuevoId);
int putIDNuevo(int* nuevoId);

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int auxIndice;
    LinkedList* listaSalon = ll_newLinkedList();
    LinkedList* listaArcade = ll_newLinkedList();
    LinkedList* listaJuego = ll_newLinkedList();

    if( !controller_loadSalonFromText("Salon.csv"", listaSalon))")&&
    	!controller_loadArcadeFromText("Arcade.csv", listaArcade) &&
		!controller_loadJuegoFromText("Juego.csv", listaJuego))
    {
		do{
			printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
			printf("2. Cargar los datos de los pasajeros desde el archivo data.dat (modo binario).\n");
			printf("3. Alta de pasajero\n");
			printf("4. Modificar datos de pasajero\n");
			printf("5. Baja de pasajero\n");
			printf("6. Listar pasajeros\n");
			printf("7. Ordenar pasajeros\n");
			printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
			printf("9. Guardar los datos de los pasajeros en el archivo data.dat (modo binario).\n");
			printf("10. Salir\n");
			utn_getNumeroInt(&option, "Seleccione opcion", "Error reintente", 1, 10, 1);
			switch(option)
			{
				case 1://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)
					if(controller_loadFromText("data.csv",listaPasajeros))
					{
						printf("No se pudo cargar el archivo en formato texto\n");
					}
					break;
				case 2://Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
					if(controller_loadFromBinary("data.bin", listaPasajeros))
					{
						printf("No se pudo cargar el archivo en formato binario.\n");
					}
					break;
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
				case 5://Baja de pasajero
					if(controller_removePassenger(listaPasajeros) != 0)
					{
						printf("No se pudo eliminar el pasajero\n");
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
					break;
				case 10://Salir
					//fcloseall();//en mac no anda
					break;
			}
		}while(option != 10);
		return 0;

    }
}

int getIDNuevo(int* nuevoId)
{
	FILE* pArchivo;
	if ((pArchivo=fopen("id.csv","r"))==NULL)
	{
		pArchivo=fopen("id.csv","w");
	}
	fscanf(pArchivo,"%d",nuevoId);
	printf("Nuevo ID: %d\n",*nuevoId);
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}


int putIDNuevo(int* nuevoId)
{
	FILE* pArchivo;
	if (!((pArchivo=fopen("id.csv","r"))==NULL))
	{
		pArchivo=fopen("id.csv","w");
		fprintf(pArchivo,"%d",*nuevoId);
	}
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}


