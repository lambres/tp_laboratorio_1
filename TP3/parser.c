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
	char auxId[LEN_CHARID];
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	char auxPrecio[LEN_CHARPRICE];
	char auxCodigoVuelo[LEN_CODVUELO];
	char auxTipoPasajero[LEN_TIPOPASAJERO];
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
				Passenger* pasajero = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
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
	int retorno = 1;
	Passenger* this;
	int cant;
	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			cant=fread(&this, sizeof(this), 1,pFile);
			if(cant!=1)
			{
				if(feof(pFile))
				{
					break;
				}
				else
				{
					printf("Error en la lectura del registro\n");
				}
			}
			else
			{
				printf("ID%d|Apellido%s|CodVuelo%s\n",this->id,this->apellido,this->codigoVuelo);
				ll_add(pArrayListPassenger, this);
			}
		}
		retorno=0;
	}

    return retorno;
}




