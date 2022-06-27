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

//B) Listar los arcade para más de 2 jugadores, indicando ID
//de arcade, cantidad de jugadores, nombre del juego, su
//género y nombre del salón al que pertenece.
int controller_mostrarArcadeSalon(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego)
{
	int retorno = -1;
	int i,j,k;
	char auxNombreJuego[LEN_NOMBREJUEGO];
	char auxNombreSalon[LEN_NOMBRE];
	char auxGenero[LEN_GENERO];
	int genero;
	Arcade* pArcade = NULL;
	Salon* pSalon = NULL;
	Juego* pJuego = NULL;
	printf("| %-5s | %-5s | %-20s | %-20s | %-15s |\n","IDArc","Jug","Nombre Juego","Nombre Salon", "Genero");
	for (i=0; i<ll_len(listaArcade);i++)
	{
		pArcade = ll_get(listaArcade, i);
		if(pArcade->Arcade_cantJugadores >= 2)
		{
			for(j=0;j<ll_len(listaSalon);j++)
			{
				pSalon  = ll_get(listaSalon,j);
				if(pArcade->fkIdSalon == pSalon->Salon_id)
				{
					strncpy(auxNombreSalon,pSalon->Salon_nombre,LEN_NOMBRE);
				}
			}
			for (k=0;k<ll_len(listaJuego);k++)
			{
				pJuego = ll_get(listaJuego,k);
				if(pJuego->juegoId == pArcade->fkidJuego)
				{
					strncpy(auxNombreJuego,pJuego->juegoNombre,LEN_NOMBREJUEGO);
					genero = pArcade->fkidJuego;
					juego_obtenerValorGenero(genero, auxGenero);
				}
			}
			printf("| %-5d | %-5d | %-20s | %-20s | %-15s |\n",pArcade->Arcade_id,pArcade->Arcade_cantJugadores,
					auxNombreJuego, auxNombreSalon, auxGenero);
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

/// @fn int controller_removePassenger(LinkedList*)
/// @brief Elimina Salon
///
/// @param pListaSalon puntero a lista Salon
/// @return
int controller_removeSalon(LinkedList* pListaSalon, LinkedList* pListaArcade)
{
	int retorno = 1;
	int auxId;
	int auxIndiceSalon;
	int auxIndiceArcade;
	int i,j;
	char respuesta;
	Salon* thisSalon = NULL;
	Arcade* thisArcade = NULL;
	if (pListaSalon != NULL)
	{
		controller_ListSalones(pListaSalon);
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A ELIMINAR", "ERROR", 0, 9999, 2))
		{
			for(i=0; i<ll_len(pListaSalon);i++)
			{
				thisSalon = ll_get(pListaSalon, i);
				if(thisSalon!= NULL)
				{
					if(thisSalon->Salon_id == auxId)
					{
						respuesta = verifica();
						if(respuesta=='S')
						{
							for(j=0;j<ll_len(pListaArcade);j++)
							{
								thisArcade=ll_get(pListaArcade,j);
								if(thisArcade!=NULL)
								{
									if(thisArcade->fkIdSalon == auxId)
									{
										auxIndiceArcade = ll_indexOf(pListaArcade, &j);
										ll_remove(pListaArcade, j);
									}
								}
							}
							auxIndiceSalon = ll_indexOf(pListaSalon,&i);
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


/// @fn int controller_ListSalones(LinkedList*)
/// @brief Lista los salones pasados como parametro en la lista
///
/// @param pListaSalon puntero a la lista de salones
/// @return 1 si hay error en parametros (ERROR) 0 si se pudo listar (EXITO)
int controller_ListArcades(LinkedList* pListaArcade)
{
	int retorno = 1;
	int i;
	Arcade* pArcade = NULL;
	if (pListaArcade != NULL)
	{
		int cantidad = ll_len(pListaArcade);
		printf("|%-5s|%-30s|%-12s|%-15s|%-10s|%-10s|%-10s|\n","ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","ID SALON","ID JUEGO");
		for (i=0; i< cantidad; i++)
		{
			pArcade = (Arcade*) ll_get(pListaArcade, i);
			Arcade_printOne(pArcade);
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int controller_ListSalones(LinkedList*)
/// @brief Lista los salones pasados como parametro en la lista
///
/// @param pListaSalon puntero a la lista de salones
/// @return 1 si hay error en parametros (ERROR) 0 si se pudo listar (EXITO)
int controller_ListJuegos(LinkedList* pListaJuegos)
{
	int retorno = 1;
	int i;
	Juego* pJuego = NULL;
	if (pListaJuegos != NULL)
	{
		int cantidad = ll_len(pListaJuegos);
		//idJuego,juegoNombre,juegoEmpresa,juegoGenero
		printf("|%-10s|%-30s|%-30s|%-30s|\n","ID JUEGO", "NOMBRE JUEGO","EMPRESA","GENERO");
		for (i=0; i< cantidad; i++)
		{
			pJuego = (Juego*) ll_get(pListaJuegos, i);
			Juego_printOneJuego(pJuego);
		}
		retorno = 0;
	}
	return retorno;
}

//------------------------ARCADES-------------------------------------


/** \brief Alta de Salon
 *
 * \param path char*
 * \param pSalon LinkedList*
 * \return int -1 Si no se pudo dar de alta el Salon (ERROR)
 *			0 si salio todo correcto (EXITO)
 */
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
	if (aux!=NULL && idNuevo >= 0)
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
						if(auxSalon->Salon_id == auxIdSalon)
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
						if(auxJuego->juegoId == auxIdJuego)
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
    return retorno;
}


//
///** \brief Modificar datos de pasajero
// *
// * \param path char*
// * \param pArrayListPassenger LinkedList*
// * \return int
// *
// */
//int controller_editSalon(LinkedList* pArrayListPassenger)
//{
//	int retorno = 1;
//	int i;
//	int auxId;
//	int opc;
//	char nombre[LEN_NOMBRE];
//	char apellido[LEN_APELLIDO];
//	float precio;
//	char codigoVuelo[LEN_CODVUELO];
//	char tipoPasajero[LEN_TIPOSALON];
//	char estadoVuelo[LEN_ESTADOVUELO];
//	Arcade* this = NULL;
//	if (pArrayListPassenger != NULL)
//	{
//		if(!utn_getNumeroInt(&auxId, "INGRESE ID A MODIFICAR", "ERROR", 0, 9999, 2))
//		{
//			int cantidad = ll_len(pArrayListPassenger);
//			for (i=0; i< cantidad; i++)
//			{
//				this = (Arcade*) ll_get(pArrayListPassenger, i);
//				//Passenger_printOne(pPasajero);
//				if(auxId==this->id)
//				{
//					printf("%-10s|%-20s|%-20s|%-11s|%-16s|%-15s|%-15s|\n","Indice","Nombre","Apellido","Precio","Cod. Vuelo","TipoPasajero","Est. Vuelo");
//					ll_get(pArrayListPassenger, i);
//					Juego_printOneJuego(this);
//					if(!utn_getNumeroInt(&opc, "DATO A MODIF:\n1: NOMBRE\n2: APELLIDO\n3: PRECIO\n4: COD. VUELO\n5: TIPO PASAJERO\n6: EST. VUELO\n", "ERROR", 1, 6, 2))
//					{
//						switch(opc)
//						{
//						case 1:
//							if(!utn_getNombre(nombre, LEN_NOMBRE, "NUEVO NOMBRE", "ERROR", 2))
//							{
//								if(Salon_setSalon_Nombre(this, nombre)==-1)
//								{
//									printf("ERROR \nNo se pudo editar el campo\n");
//								}
//							}
//							break;
//						case 2:
//							if(!utn_getNombre(apellido, LEN_APELLIDO, "NUEVO APELLIDO", "ERROR", 2))
//							{
//								if(Juego_setjuegoEmpresa(this, apellido)==-1)
//								{
//									printf("ERROR \nNo se pudo editar el campo\n");
//								}
//							}
//							break;
//						case 3:
//							if(!utn_getNumeroFloat(&precio, "NUEVO PRECIO", "ERROR", 0, 99999, 2))
//							{
//								if(Salon_setPrecio(this, precio)==-1)
//								{
//									printf("ERROR \nNo se pudo editar el campo\n");
//								}
//							}
//							break;
//						case 4:
//							if(!utn_getTexto(codigoVuelo, LEN_CODVUELO, "NUEVO CODIGO", "ERROR", 2))
//							{
//								if(Salon_setCodigoVuelo(this, codigoVuelo)==-1)
//								{
//									printf("ERROR \nNo se pudo editar el campo\n");
//								}
//							}
//							break;
//						case 5:
//							if(!utn_getTexto(tipoPasajero, LEN_TIPOSALON, "NUEVO TIPO PASAJERO", "ERROR", 2))
//							{
//								if(Salon_setTipoSalonStr(this, tipoPasajero)==-1)
//								{
//									printf("ERROR \nNo se pudo editar el campo\n");
//								}
//							}
//							break;
//						case 6:
//							if(!(utn_getTexto(estadoVuelo, LEN_ESTADOVUELO, "NUEVO ESTADO VUELO (Aterrizado/En Horario/En Vuelo/Demorado: ", "ERROR", 2)))
//							{
//								if(Salon_setEstadoVuelo(this, estadoVuelo)==-1)
//								{
//									printf("ERROR \nNo se pudo editar el campo\n");
//								}
//							}
//							break;
//						}
//					}
//					retorno = 0;
//				}
//			}
//		}
//	}
//	return retorno;
//}
//
//
///** \brief Ordenar pasajeros
// *
// * \param path char*
// * \param pArrayListPassenger LinkedList*
// * \return int
// *
// */
//int controller_sortPassenger(LinkedList* pArrayListPassenger)
//{
//	int retorno = -1;
//	if(pArrayListPassenger != NULL)
//	{
//		ll_sort(pArrayListPassenger, Arcade_mayor, 0);
//		retorno = 0;
//	}
//    return retorno;
//}
//
//
