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

/** \brief Carga los datos de los Juegos desde el archivo Juego.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadJuegoFromText(char* path , LinkedList* pArrayList)
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
			if(parser_JuegoFromText(pFile, pArrayList)==1)
			{
				printf("No se pudo cargar el archivo en controller\n");
			}
			retorno = 0;
			fclose(pFile);
		}
	}
    return retorno;
}
/** \brief Carga los datos de los Arcades desde el archivo Arcade.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadArcadeFromText(char* path , LinkedList* pArrayList)
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
			if(parser_ArcadeFromText(pFile, pArrayList)==1)
			{
				printf("No se pudo cargar el archivo en controller\n");
			}
			retorno = 0;
			fclose(pFile);
		}
	}
    return retorno;
}


/// @fn int controller_loadFiles(LinkedList*, LinkedList*, LinkedList*)
/// @brief Llama a las funciones para carga de archivos con datos para la correcta utilizacion del software
///
/// @param listaSalon Puntero a lista Salon
/// @param listaArcade Puntero a lista Arcade
/// @param listaJuego Puntero a lista Juego
/// @return -1 si no se pudo abrir un archivo (ERROR) y 0 si se pudo (Exito)
int controller_loadFiles(LinkedList* listaSalon, LinkedList* listaArcade , LinkedList* listaJuego)
{
	int retorno = -1;
	if( !controller_loadSalonFromText("Salon.csv", listaSalon) &&
		!controller_loadArcadeFromText("Arcade.csv", listaArcade) &&
		!controller_loadJuegoFromText("Juego.csv", listaJuego))
	    {
			retorno = 0;
	    }
	return retorno;
}


/** \brief Guarda los datos de los Salones en el archivo Salon.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int 1 si no se pudo (Error) 0 si Se pudo guardar (Exito)
 *
 */
int controller_saveSalonAsText(char* path , LinkedList* pArrayList)
{
	int retorno = 1;
	FILE* pArchivo;
	int i;
	Salon* pSalon = NULL;
	if (path != NULL && pArrayList != NULL)
	{
		pArchivo = fopen(path,"w");
		if (pArchivo != NULL)
		{
			int cantidad = ll_len(pArrayList);
			//"%[^,],%[^,],%[^,],%[^\n]\n" Salon_id,Salon_nombre,Salon_direccion,Salon_tipo
			fprintf(pArchivo,"%s,%s,%s,%s\n","Salon_id","Salon_nombre","Salon_direccion","Salon_tipo");
			for (i=0; i< cantidad; i++)
			{
				pSalon = (Salon*) ll_get(pArrayList, i);
				Salon_printOneSalonFile(pArchivo, pSalon);
			}
		}
		if(!fclose(pArchivo))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los Arcades en el archivo Arcade.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int 1 si no se pudo (Error) 0 si Se pudo guardar (Exito)
 *
 */
int controller_saveArcadeAsText(char* path , LinkedList* pArrayList)
{
	int retorno = 1;
	FILE* pArchivo;
	int i;
	Arcade* pArcade = NULL;
	if (path != NULL && pArrayList != NULL)
	{
		pArchivo = fopen(path,"w");
		if (pArchivo != NULL)
		{
			int cantidad = ll_len(pArrayList);
			fprintf(pArchivo,"%s,%s,%s,%s,%s,%s,%s\n","Arcade_id","Arcade_nacionalidad","Arcade_tipoSonido",
					"Arcade_cantJugadores","Arcade_capacidad","fkIdSalon","fkIdJuego");
			for (i=0; i< cantidad; i++)
			{
				pArcade = (Arcade*) ll_get(pArrayList, i);
				Arcade_printOneFile(pArchivo, pArcade);
			}
		}
		if(!fclose(pArchivo))
		{
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Guarda los datos de los Juegos en el archivo Juego.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int 1 si no se pudo (Error) 0 si Se pudo guardar (Exito)
 *
 */
int controller_saveJuegoAsText(char* path , LinkedList* pArrayList)
{
	int retorno = 1;
	FILE* pArchivo;
	int i;
	Juego* pJuego = NULL;
	if (path != NULL && pArrayList != NULL)
	{
		pArchivo = fopen(path,"w");
		if (pArchivo != NULL)
		{
			int cantidad = ll_len(pArrayList);
			fprintf(pArchivo,"%s,%s,%s,%s\n","idJuego","juegoNombre","juegoEmpresa","juegoGenero");
			for (i=0; i< cantidad; i++)
			{
				pJuego = (Juego*) ll_get(pArrayList, i);
				Juego_printOneJuegoFile(pArchivo, pJuego);
			}
		}
		if(!fclose(pArchivo))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int controller_saveFiles(LinkedList*, LinkedList*, LinkedList*)
/// @brief Llama a las funciones para guardar los archivos antes de salir de la aplicacion
///
/// @param listaSalon Puntero a lista Salon
/// @param listaArcade Puntero a lista Arcade
/// @param listaJuego Puntero a lista Juego
/// @return -1 si no se pudo abrir un archivo (ERROR) y 0 si se pudo (Exito)
int controller_saveFiles(LinkedList* listaSalon, LinkedList* listaArcade , LinkedList* listaJuego)
{
	int retorno = -1;
	if( !controller_saveSalonAsText("Salon.csv", listaSalon) &&
		!controller_saveArcadeAsText("Arcade.csv", listaArcade) &&
		!controller_saveJuegoAsText("Juego.csv", listaJuego))
	    {
			retorno = 0;
	    }
	return retorno;
}

/// @fn int controller_mostrarArcadeParaEliminar(LinkedList*, LinkedList*, LinkedList*)
/// @brief Funcion para mostrar los datos antes de eliminar
///
/// @param listaSalon puntero a LinkedList
/// @param listaArcade puntero a LinkedList
/// @param listaJuego puntero a LinkedList
/// @return 0 si se pudo regresar el conjunto de registros (EXITO) y -1 si no se pudo (ERROR)
int controller_mostrarArcadeParaEliminar(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego)
{
	int retorno = -1;
	int i,j,k;
	char auxNombreJuego[LEN_NOMBREJUEGO];
	char auxNombreSalon[LEN_NOMBRE];
	char auxGenero[LEN_GENERO];
	int genero;
	int auxSalon_id;
	int auxfkIdSalon;
	char auxSalon_nombre[LEN_NOMBRE];
	int auxjuegoId;
	int auxfkidJuego;
	Arcade* pArcade = NULL;
	Salon* pSalon = NULL;
	Juego* pJuego = NULL;
	printf("| %-5s | %-5s | %-20s | %-20s | %-15s |\n","IDArc","Jug","Nombre Juego","Nombre Salon", "Genero");
	for (i=0; i<ll_len(listaArcade);i++)
	{
		pArcade = ll_get(listaArcade, i);
		for(j=0;j<ll_len(listaSalon);j++)
		{
			pSalon  = ll_get(listaSalon,j);
			Salon_getSalon_Id(pSalon, &auxSalon_id);
			Arcade_getArcade_Id(pArcade, &auxfkIdSalon);
			//if(pArcade->fkIdSalon == pSalon->Salon_id)
			if(auxfkIdSalon == auxSalon_id)
			{
				Salon_getSalon_Nombre(pSalon, auxSalon_nombre);
				strncpy(auxNombreSalon,auxSalon_nombre,LEN_NOMBRE);
			}
		}
		for (k=0;k<ll_len(listaJuego);k++)
		{
			pJuego = ll_get(listaJuego,k);
			Arcade_getArcade_Id(pArcade, &auxfkidJuego);
			Juego_getJuego_Id(pJuego, &auxjuegoId);
			//if(pJuego->juegoId == pArcade->fkidJuego)
			if(auxjuegoId == auxfkidJuego)
			{
				strncpy(auxNombreJuego,pJuego->juegoNombre,LEN_NOMBREJUEGO);
				genero = pArcade->fkidJuego;
				juego_obtenerValorGenero(genero, auxGenero);
			}
		}
		printf("| %-5d | %-5d | %-20s | %-20s | %-15s |\n",pArcade->Arcade_id,pArcade->Arcade_cantJugadores,
				auxNombreJuego, auxNombreSalon, auxGenero);
		retorno = 0;
	}
	return retorno;
}

/// @fn int controller_mostrarArcadeJuego(LinkedList*, LinkedList*)
/// @brief Funcion para mostrar los Arcade llamada desde el menu ABM ARCADE
///
/// @param listaArcade
/// @param listaJuego
/// @return 0 Si se pudo listar (EXITO y -1 si hubo un error (ERROR)
int controller_mostrarArcadeJuego(LinkedList* listaArcade, LinkedList* listaJuego)
{
	int retorno = -1;
	int i,j;
	char auxNombreJuego[LEN_NOMBREJUEGO];
	char auxGenero[LEN_GENERO];

	char tipoSonido[LEN_TIPOSONIDO];
	int auxjuegoId;
	int auxfkidJuego;
	char auxjuegoNombre[LEN_NOMBREJUEGO];
	int auxJuegoGenero;
	int auxArcade_tipoSonido;

	Arcade* pArcade = NULL;
	Juego* pJuego = NULL;
	printf("|%-5s|%-30s|%-12s|%-15s|%-10s|%-20s|%-10s|\n","ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","JUEGO","GENERO");
	for (i=0; i<ll_len(listaArcade);i++)
	{
		pArcade = ll_get(listaArcade, i);
		for (j=0;j<ll_len(listaJuego);j++)
		{
			pJuego = ll_get(listaJuego,j);
			Juego_getJuego_Id(pJuego, &auxjuegoId);
			Arcade_getfkIdJuego(pArcade, &auxfkidJuego);
			//if(pJuego->juegoId == pArcade->fkidJuego)
			if(auxjuegoId == auxfkidJuego)
			{
				Juego_getJuegoNombre(pJuego, auxjuegoNombre);
				strncpy(auxNombreJuego,auxjuegoNombre,LEN_NOMBREJUEGO);
				Juego_getJuegoGenero(pJuego, &auxJuegoGenero);
				//genero = pJuego->juegoGenero;
				juego_obtenerValorGenero(auxJuegoGenero, auxGenero);
			}
		}
		Arcade_getTipoSonido(pArcade, &auxArcade_tipoSonido);
		//auxTipoSonido = pArcade->Arcade_tipoSonido;
		if(arcade_obtenerValorTipoSonido(auxArcade_tipoSonido, tipoSonido)!=-1)
		printf("|%-5d|%-30s|%-12s|%-15d|%-10d|%-20s|%-10s|\n",pArcade->Arcade_id,pArcade->Arcade_nacionaliad,tipoSonido,
				pArcade->Arcade_cantJugadores,pArcade->Arcade_capacidad,auxNombreJuego, auxGenero);
		retorno = 0;
	}
	return retorno;
}

/// @fn int controller_removeSalon(LinkedList*, LinkedList*)
/// @brief Elimina un salon y los arcades relacionados
///
/// @param pListaSalon
/// @param pListaArcade
/// @return 0 si se pudo (EXITO) y 1 si no se pudo (ERROR)
int controller_removeSalon(LinkedList* pListaSalon, LinkedList* pListaArcade)
{
	int retorno = 1;
	int auxId;
	int i,j;
	char respuesta;
	Salon* thisSalon = NULL;
	Arcade* thisArcade = NULL;
	int auxfkIdSalon;

	int auxSalon_id;
	if (pListaSalon != NULL && pListaArcade != NULL)
	{
		controller_ListSalones(pListaSalon);
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A ELIMINAR", "ERROR", 0, 9999, 2))
		{
			for(i=0; i<ll_len(pListaSalon);i++)
			{
				thisSalon = ll_get(pListaSalon, i);
				if(thisSalon!= NULL)
				{
					Salon_getSalon_Id(thisSalon, &auxSalon_id);
					if(auxSalon_id == auxId)
					{
						respuesta = verifica();
						if(respuesta=='S')
						{
							for(j=0;j<ll_len(pListaArcade);j++)
							{
								thisArcade=ll_get(pListaArcade,j);
								if(thisArcade!=NULL)
								{
									Arcade_getfkIdSalon(thisArcade, &auxfkIdSalon);
									if(auxfkIdSalon == auxId)
									{
										ll_remove(pListaArcade, j);
									}
								}
							}
							ll_remove(pListaSalon, i);
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}

/// @fn int controller_removeArcade(LinkedList*, LinkedList*, LinkedList*)
/// @brief elimina un Arcade y los juegos asignados
///
/// @param pListaSalon
/// @param pListaArcade
/// @param pListaJuegos
/// @return 0 si se pudo eliminar (EXITO) y 1 si no se pudo (ERROR)
int controller_removeArcade(LinkedList* pListaSalon, LinkedList* pListaArcade, LinkedList* pListaJuegos)
{
	int retorno = 1;
	int auxId;
	int i,j;
	char respuesta;
	Arcade* thisArcade = NULL;
	Juego* thisJuego = NULL;


	int auxArcade_id;
	int auxjuegoId;
	if (pListaSalon != NULL && pListaArcade != NULL && pListaJuegos != NULL)
	{
		controller_mostrarArcadeParaEliminar(pListaSalon, pListaArcade, pListaJuegos);
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A ELIMINAR", "ERROR", 0, 9999, 2))
		{
			for(i=0; i<ll_len(pListaArcade);i++)
			{
				thisArcade = ll_get(pListaArcade, i);
				if(thisArcade!= NULL)
				{
					Arcade_getArcade_Id(thisArcade, &auxArcade_id);
					if(auxArcade_id == auxId)
					{
						respuesta = verifica();
						if(respuesta=='S')
						{
							for(j=0;j<ll_len(pListaJuegos);j++)
							{
								thisJuego=ll_get(pListaJuegos,j);
								if(thisJuego!=NULL)
								{
									Juego_getJuego_Id(thisJuego, &auxjuegoId);
									if(auxjuegoId == auxId)
									{
										ll_remove(pListaJuegos, j);
									}
								}
							}
							ll_remove(pListaArcade, i);
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}

/// @fn int controller_ListSalones(LinkedList*)
/// @brief Lista los salones pasados como parametro en la lista
///
/// @param pListaSalon puntero a la lista de salones
/// @return 1 si hay error en parametros (ERROR) 0 si se pudo listar (EXITO)
int controller_ListSalones(LinkedList* pListaSalon)
{
	int retorno = 1;
	int i;
	Salon* pSalon = NULL;
	if (pListaSalon != NULL)
	{
		int cantidad = ll_len(pListaSalon);
		printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO");
		for (i=0; i< cantidad; i++)
		{
			pSalon = (Salon*) ll_get(pListaSalon, i);
			Salon_printOneSalon(pSalon);
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int controller_ListArcades(LinkedList*)
/// @briefLista Arcades
///
/// @param pListaArcade
/// @return 0 si se pudo listar (EXITO) y -1 si no se pudo (ERROR)
int controller_ListArcades(LinkedList* pListaArcade)
{
	int retorno = 1;
	int i;
	Arcade* pArcade = NULL;
	if (pListaArcade != NULL)
	{
		int cantidad = ll_len(pListaArcade);
		printf("|%-5s|%-30s|%-12s|%-15s|%-10s|%-10s|\n","ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","ID JUEGO");
		for (i=0; i< cantidad; i++)
		{
			pArcade = (Arcade*) ll_get(pListaArcade, i);
			Arcade_printOne(pArcade);
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int controller_ListJuegos(LinkedList*)
/// @brief Lista los juegos pasados como parametro en la lista
///
/// @param pListaJuegos puntero a la lista de juegos
/// @return 1 si hay error en parametros (ERROR) 0 si se pudo listar (EXITO)
int controller_ListJuegos(LinkedList* pListaJuegos)
{
	int retorno = 1;
	int i;
	Juego* pJuego = NULL;
	if (pListaJuegos != NULL)
	{
		int cantidad = ll_len(pListaJuegos);
		printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE JUEGO","EMPRESA","GENERO");
		for (i=0; i< cantidad; i++)
		{
			pJuego = (Juego*) ll_get(pListaJuegos, i);
			Juego_printOneJuego(pJuego);
		}
		retorno = 0;
	}
	return retorno;
}


/** \brief Alta de Salon
 *
 * \param path char*
 * \param pSalon LinkedList*
 * \return int -1 Si no se pudo dar de alta el Salon (ERROR)
 *			0 si salio todo correcto (EXITO)
 */
int controller_addSalon(LinkedList* pSalon, int idNuevo)
{
	int retorno = -1;
	Salon* aux = Salon_new();
	int id=-1;
	char nombre[LEN_NOMBRE];
	char direccion[LEN_DIRECCION];
	int tipoSalon;

	if (aux!=NULL && idNuevo >= 0)
	{
		id = idNuevo;
		if(!(utn_getTexto(nombre, LEN_NOMBRE, "NOMBRE SALON:", "ERROR REINTENTAR", 2)))
		{
			if(!(utn_getTexto(direccion, LEN_DIRECCION, "DIRECCION:", "ERROR REINTENTAR", 2)))
			{
				if(!(utn_getNumeroInt(&tipoSalon, "TIPO: 1.- SHOPPING 2.- LOCAL:", "ERROR", 1, 2, 2)))
				{
					Salon_setSalon_Id(aux, id);
					Salon_setSalon_Nombre(aux, nombre);
					Salon_setSalon_Direccion(aux, direccion);
					Salon_setTipoSalon(aux, tipoSalon);
					ll_add(pSalon, aux);
					retorno = 0;
				}
			}
		}
		if(retorno == 0)
		{
			puts("Salon dado de alta:\n");
			printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO");
			Salon_printOneSalon(aux);
		}
	}
	else
	{
		Salon_delete(aux);
	}
    return retorno;
}

/// @fn int controller_addArcade(LinkedList*, LinkedList*, LinkedList*, int)
/// @brief Agrega Arcade
///
/// @param pSalon
/// @param pArcade
/// @param pJuego
/// @param idNuevo nuevo id
/// @return 0 si dio ok (EXITO) y -1 si no se pudo (ERROR)
int controller_addArcade(LinkedList* pSalon, LinkedList* pArcade, LinkedList* pJuego, int idNuevo)
{
	int retorno = -1;
	Arcade* aux = Arcade_new();
	int id = -1;
	int i,j;
	char auxNacionalidad[LEN_NACIONALIDAD];
	int tipoSonido;
	int auxCantJugadores;
	int auxCapacidad;
	int auxIdSalon;
	int auxIdJuego;
	Salon* auxSalon = NULL;
	Juego* auxJuego = NULL;

	int auxSalon_id;
	int auxjuegoId;
	if(pSalon != NULL && pArcade != NULL && pJuego != NULL && idNuevo >=0)
	{
		if (aux!=NULL)
		{
			id = idNuevo;
			if(!(utn_getTexto(auxNacionalidad, LEN_NACIONALIDAD, "NACIONALIDAD:", "ERROR REINTENTAR", 2)) &&
				!(utn_getNumeroInt(&tipoSonido, "TIPO: 0.- STEREO 1.- MONO:", "ERROR", 0, 1, 2)) &&
				!(utn_getNumeroInt(&auxCantJugadores, "CANT. JUGADORES (1-4:)", "ERROR REINTENTE", 1, 4, 2)) &&
				!(utn_getNumeroInt(&auxCapacidad, "CAPACIDAD: (200-300)", "ERROR", 200, 300, 2)))
			{
				Arcade_setArcade_Id(aux, id);
				Arcade_setNacionalidad(aux, auxNacionalidad);
				Arcade_setTipoSonido(aux, tipoSonido);
				Arcade_setCantJugadores(aux, auxCantJugadores);
				Arcade_setCapacidad(aux, auxCapacidad);
				for(i=0;i<ll_len(pSalon);i++)
				{
					controller_ListSalones(pSalon);
				}
				if(!utn_getNumeroInt(&auxIdSalon, "INGRESE ID SALON", "ERROR", 0, 9999, 2))
				{
					for(i=0; i<ll_len(pSalon);i++)
					{
						auxSalon = ll_get(pSalon, i);
						if(auxSalon!= NULL)
						{
							Salon_getSalon_Id(auxSalon, &auxSalon_id);
							if(auxSalon_id == auxIdSalon)
							{
								Arcade_setfkIdSalon(aux, auxIdSalon);
								break;
							}
						}
					}
				}

				for(j=0;j<ll_len(pJuego);j++)
				{
					controller_ListJuegos(pJuego);
				}
				if(!utn_getNumeroInt(&auxIdJuego, "INGRESE ID JUEGO", "ERROR", 0, 9999, 2))
				{
					for(j=0; j<ll_len(pJuego);j++)
					{
						auxJuego = ll_get(pJuego, i);
						if(auxJuego!= NULL)
						{
							Juego_getJuego_Id(auxJuego, &auxjuegoId);
							if(auxjuegoId == auxIdJuego)
							{
								Arcade_setfkIdJuego(aux, auxIdJuego);
								break;
							}
						}
					}
				}
				ll_add(pArcade, aux);
				retorno = 0;
			}
			if(retorno == 0)
			{
				puts("Arcade dado de alta:\n");
				printf("|%-10s|%-30s|%-30s|%-30s|\n","ID JUEGO", "NOMBRE JUEGO","EMPRESA","GENERO");
				Arcade_printOne(aux);
			}
		}
		else
		{
			Arcade_delete(aux);
		}
	}
	return retorno;
}
/// @fn int controller_addJuego(LinkedList*, int)
/// @brief Agrega elemento a la lista pJuego
///
/// @param pJuego
/// @param idNuevo
/// @return 0 si se pudo (EXITO) y -1 si no se pudo (ERROR)
int controller_addJuego(LinkedList* pJuego, int idNuevo)
{
	int retorno = -1;
	Juego* this = Juego_new();
	int id = -1;
	char auxJuegoNombre[LEN_NOMBREJUEGO];
	char auxJuegoEmpresa[LEN_EMPRESA];
	int auxJuegoGenero;
	if(pJuego != NULL && idNuevo >=0)
	{
		if (this!=NULL && idNuevo >= 0)
		{
			id = idNuevo;
			if(!(utn_getTexto(auxJuegoNombre, LEN_NOMBREJUEGO, "NOMBRE JUEGO:", "ERROR REINTENTAR", 2)) &&
				!(utn_getTexto(auxJuegoEmpresa, LEN_EMPRESA, "NOMBRE EMPRESA:", "ERROR REINTENTAR", 2)) &&
				!(utn_getNumeroInt(&auxJuegoGenero, "GENERO \n0: PLATAFORMA\n1: LABERINTO\n2: AVENTURA\n3: OTRO", "ERROR REINTENTE", 0, 3, 2)))
			{
				Juego_setJuego_Id(this, id);
				Juego_setJuegoNombre(this, auxJuegoNombre);
				Juego_setJuegoEmpresa(this, auxJuegoEmpresa);
				Juego_setJuegoGenero(this, auxJuegoGenero);
				ll_add(pJuego, this);
				retorno = 0;
			}
			if(retorno == 0)
			{
				puts("Juego dado de alta:\n");
				printf("|%-10s|%-30s|%-30s|%-30s|\n","ID JUEGO", "NOMBRE JUEGO","EMPRESA","GENERO");
				Juego_printOneJuego(this);
			}
		}
		else
		{
			Juego_delete(this);
		}
	}
    return retorno;
}



/** \brief Modificar datos de Arcade
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* listaArcade, LinkedList* listaJuegos)
{
	int retorno = 1;
	int i,j;
	int auxId;
	int opc;
	char auxNacionalidad[LEN_NACIONALIDAD];
	int auxTipoSonido;
	int auxCantJugadores;
	int auxCapacidad;
	int auxJuego;
	Arcade* this = NULL;
	if (listaArcade != NULL && listaJuegos != NULL)
	{
		controller_ListArcades(listaArcade);
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A MODIFICAR", "ERROR", 0, 9999, 2))
		{
			int cantidad = ll_len(listaArcade);
			for (i=0; i< cantidad; i++)
			{
				this = (Arcade*) ll_get(listaArcade, i);
				if(auxId==this->Arcade_id)
				{
					printf("|%-5s|%-30s|%-12s|%-15s|%-10s|%-10s|\n","ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","ID JUEGO");
					ll_get(listaArcade, i);
					Arcade_printOne(this);
					if(!utn_getNumeroInt(&opc, "DATO A MODIF:\n1: NACIONALIDAD\n2: TIPO SONIDO\n3: CANT JUGADORES\n4: CAPACIDAD\n5: ID JUEGO\n", "ERROR", 1, 5, 2))
					{
						switch(opc)
						{
						case 1:
							if(!utn_getNombre(auxNacionalidad, LEN_NACIONALIDAD, "NUEVA NACIONALIDAD", "ERROR", 2))
							{
								if(Arcade_setNacionalidad(this, auxNacionalidad)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo nacionalidad\n");
								}
							}
							break;
						case 2:
							if(!utn_getNumeroInt(&auxTipoSonido, "TIPO SONIDO (0:STEREO 1:MONO)", "ERROR REINGRESE", 0, 1, 2))
							{
								if(Arcade_setTipoSonido(this, auxTipoSonido)==-1)
								{
									printf("ERROR \nNo se pudo editar tipo sonido\n");
								}
							}
							break;
						case 3:
							if(!utn_getNumeroInt(&auxCantJugadores, "CANT JUGADORES (1-4)", "ERROR REINGRESE", 1, 4, 2))
							{
								if(Arcade_setCantJugadores(this, auxCantJugadores)==-1)
								{
									printf("ERROR \nNo se pudo editar cantidad de jugadores\n");
								}
							}
							break;
						case 4:
							if(!utn_getNumeroInt(&auxCapacidad, "CAPACIDAD (200-300)", "ERROR REINGRESE", 200, 300, 2))
							{
								if(Arcade_setCapacidad(this, auxCapacidad)==-1)
								{
									printf("ERROR \nNo se pudo editar capacidad\n");
								}
							}
							break;
						case 5:
							controller_ListJuegos(listaJuegos);
							if(!utn_getNumeroInt(&auxJuego, "ID JUEGO", "ERROR REINGRESE", 1, 9999, 2))
							{
								Juego* thisJuego = NULL;
								for(j=0; j<ll_len(listaJuegos);j++)
								{
									thisJuego = ll_get(listaJuegos,j);
									if(thisJuego!=NULL)
									{
										int auxjuegoId;
										Juego_getJuego_Id(thisJuego, &auxjuegoId);
										if(auxjuegoId==auxJuego)
										{
											if(Arcade_setfkIdJuego(this, auxJuego)==-1)
											{
												printf("ERROR \nNo se pudo editar ID Juego\n");
											}
										}
									}
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


/** \brief Ordenar Arcade
 *
 * \param path char*
 * \param pListaArcade LinkedList*
 * \return int
 *
 */
int controller_sortArcade(LinkedList* pListaArcade)
{
	int retorno = -1;
	if(pListaArcade != NULL)
	{
		ll_sort(pListaArcade, Arcade_mayor, 0);
		retorno = 0;
	}
    return retorno;
}
/// @fn int controller_sortJuego(LinkedList*)
/// @brief  Ordena lista juego
///
/// @param pListaJuego
/// @return 0 si se pudo ordenar (EXITO) y -1 si no se pudo (ERROR)
int controller_sortJuego(LinkedList* pListaJuego)
{
	int retorno = -1;
	if(pListaJuego != NULL)
	{
		ll_sort(pListaJuego, Juego_mayor, 0);
		retorno = 0;
	}
    return retorno;
}

