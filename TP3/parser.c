#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	char auxId[LEN_CHARSALONID];
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	char auxPrecio[LEN_CHARPRICE];
	char auxCodigoVuelo[LEN_CODVUELO];
	char auxTipoPasajero[LEN_TIPOSALON];
	char auxEstadoVuelo[LEN_ESTADOVUELO];

	int camposLeidos;

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
		do
		{
			camposLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
			if (camposLeidos==7)
			{
				Salon* pasajero = Salon_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				if (pasajero!=NULL)
				{
					ll_add(pArrayListPassenger, pasajero);
					retorno = 0;
				}
			}
		}while (!feof(pFile));
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pFile != NULL && pArrayListPassenger !=NULL)
	{
		do
		{
			Salon* this = Salon_new();
			if(this !=NULL)
			{
				if(fread(this,sizeof(Salon),1,pFile) != 1)
				{
					free(this);
					break;
				}
				else
				{
					if(ll_add(pArrayListPassenger,this) == 0)
					{
						retorno = 0;
					}
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}




