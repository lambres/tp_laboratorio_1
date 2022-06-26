#include "Controller.h"

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Salon.h"
#include "Juego.h"
#include "Arcade.h"



/** \brief Carga los datos de los Salones desde el archivo Salon.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadSalonFromText(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
	if(path != NULL && pArrayList != NULL)
	{
		if(ll_len(pArrayList)>0)
		{
			puts("Archivo cargado previamente");
		}
		else
		{
			FILE* pFile=fopen(path,"r");
			if(parser_SalonFromText(pFile, pArrayList)==1)
			{
				printf("No se pudo cargar el archivo en controller\n");
			}
			retorno = 0;
			fclose(pFile);
		}
	}
    return retorno;
}


/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addSalon(LinkedList* pArrayListPassenger, int idNuevo)
{
	int retorno = -1;
	Arcade* aux = Salon_new();
	int id=-1;
	char nombre[LEN_NOMBRE];
	char direccion[LEN_DIRECCION];
	int tipoSalon;

	if (aux!=NULL && idNuevo >= 0)
	{
		id = idNuevo;
		if(!(utn_getNumeroFloat(&precio, "INGRESE PRECIO DEL VUELO", "ERROR REINTENTE", 0, 99999, 2)))
		{
			if(!(utn_getNumeroInt(&tipoSalon, "TIPO PASAJERO (0:FirstClass 1:ExecutiveClass "
					"2:EconomyClass): ", "ERROR", 0, 2, 2)))
			{
				if(!(utn_getNombre(nombre, LEN_NOMBRE, "NOMBRE: ", "ERROR",2)))
				{
					if(!(utn_getNombre(direccion, LEN_APELLIDO, "APELLIDO: ", "ERROR", 2)))
					{
						if(!utn_getTexto(codigoVuelo, LEN_CODVUELO, "CODIGO VUELO", "ERROR", 2))
						{
							if(!(utn_getTexto(estadoVuelo, LEN_ESTADOVUELO, "ESTADO VUELO (Aterrizado/En Horario/En Vuelo/Demorado: ", "ERROR", 2)))
							{
								Salon_setSalon_Id(aux, id);
								Salon_setSalon_Nombre(aux, nombre);
								Juego_setjuegoEmpresa(aux, direccion);
								Salon_setCodigoVuelo(aux, codigoVuelo);
								Salon_setEstadoVuelo(aux, estadoVuelo);
								Salon_setPrecio(aux, precio);
								Salon_setTipoSalon(aux, tipoSalon);
								ll_add(pArrayListPassenger, aux);
								retorno = 0;
							}
						}
					}
				}
			}
		}
		else
		{
			Salon_delete(aux);
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editSalon(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int i;
	int auxId;
	int opc;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_APELLIDO];
	float precio;
	char codigoVuelo[LEN_CODVUELO];
	char tipoPasajero[LEN_TIPOSALON];
	char estadoVuelo[LEN_ESTADOVUELO];
	Arcade* this = NULL;
	if (pArrayListPassenger != NULL)
	{
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A MODIFICAR", "ERROR", 0, 9999, 2))
		{
			int cantidad = ll_len(pArrayListPassenger);
			for (i=0; i< cantidad; i++)
			{
				this = (Arcade*) ll_get(pArrayListPassenger, i);
				//Passenger_printOne(pPasajero);
				if(auxId==this->id)
				{
					printf("%-10s|%-20s|%-20s|%-11s|%-16s|%-15s|%-15s|\n","Indice","Nombre","Apellido","Precio","Cod. Vuelo","TipoPasajero","Est. Vuelo");
					ll_get(pArrayListPassenger, i);
					Juego_printOneJuego(this);
					if(!utn_getNumeroInt(&opc, "DATO A MODIF:\n1: NOMBRE\n2: APELLIDO\n3: PRECIO\n4: COD. VUELO\n5: TIPO PASAJERO\n6: EST. VUELO\n", "ERROR", 1, 6, 2))
					{
						switch(opc)
						{
						case 1:
							if(!utn_getNombre(nombre, LEN_NOMBRE, "NUEVO NOMBRE", "ERROR", 2))
							{
								if(Salon_setSalon_Nombre(this, nombre)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 2:
							if(!utn_getNombre(apellido, LEN_APELLIDO, "NUEVO APELLIDO", "ERROR", 2))
							{
								if(Juego_setjuegoEmpresa(this, apellido)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 3:
							if(!utn_getNumeroFloat(&precio, "NUEVO PRECIO", "ERROR", 0, 99999, 2))
							{
								if(Salon_setPrecio(this, precio)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 4:
							if(!utn_getTexto(codigoVuelo, LEN_CODVUELO, "NUEVO CODIGO", "ERROR", 2))
							{
								if(Salon_setCodigoVuelo(this, codigoVuelo)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 5:
							if(!utn_getTexto(tipoPasajero, LEN_TIPOSALON, "NUEVO TIPO PASAJERO", "ERROR", 2))
							{
								if(Salon_setTipoSalonStr(this, tipoPasajero)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 6:
							if(!(utn_getTexto(estadoVuelo, LEN_ESTADOVUELO, "NUEVO ESTADO VUELO (Aterrizado/En Horario/En Vuelo/Demorado: ", "ERROR", 2)))
							{
								if(Salon_setEstadoVuelo(this, estadoVuelo)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						}
					}
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int auxId;
	int auxIndice;
	Arcade* this;
	if (pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A ELIMINAR", "ERROR", 0, 9999, 2))
		{
			this=ll_get(pArrayListPassenger, auxId);
			auxIndice=ll_indexOf(pArrayListPassenger, this);
			ll_remove(pArrayListPassenger, auxIndice);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int i;
	Arcade* pPasajero = NULL;
	if (pArrayListPassenger != NULL)
	{
		int cantidad = ll_len(pArrayListPassenger);
		printf("%-10s|%-20s|%-20s|%-11s|%-16s|%-15s|%-15s|\n","Indice","Nombre","Apellido","Precio","Cod. Vuelo","TipoPasajero","Est. Vuelo");
		for (i=0; i< cantidad; i++)
		{
			pPasajero = (Arcade*) ll_get(pArrayListPassenger, i);
			Juego_printOneJuego(pPasajero);
		}
		retorno = 0;
	}
	return retorno;
}



/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		ll_sort(pArrayListPassenger, Arcade_mayor, 0);
		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	FILE* pArchivo;
	int i;
	Arcade* pPasajero = NULL;
	if (path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"w");
		if (pArchivo != NULL)
		{
			int cantidad = ll_len(pArrayListPassenger);
			fprintf(pArchivo,"%s,%s,%s,%s,%s,%s,%s\n","id","name","lastname","price","flycode","typePassenger","statusFlight");
			for (i=0; i< cantidad; i++)
			{
				pPasajero = (Arcade*) ll_get(pArrayListPassenger, i);
				Salon_printOneSalonFile(pArchivo, pPasajero);
			}
		}
		if(!fclose(pArchivo))
		{
			retorno = 0;
		}
	}
	return retorno;
}

