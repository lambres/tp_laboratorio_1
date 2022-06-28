#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "menuInformes.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "utn.h"


void adminInformes(LinkedList* listaSalon,LinkedList* listaArcade,LinkedList* listaJuego)
{

	int opcion = 0;
	while(opcion!=8)
	{
		printf("\n\n-------------- MENU INFORMES --------------\n\n");
		printf("1.\tListar los salones con mas de 4 arcade. Indicando ID de salon, nombre,\n "
				"\tdireccion y tipo de salon.\n\n");
		printf("2.\tListar los arcade para mas de 2 jugadores, indicando ID de arcade, \n"
				"\tcantidad de jugadores, nombre del juego, su genero y nombre del salon al que pertenece\n\n");
		printf("3.\tListar toda la informacion de un salon en especifico ingresado por el usuario.\n "
				"\tImprimir ID de salon, nombre, tipo y direccion.\n\n");
		printf("4.\tUn salon se encuentra completo si posee al menos 4 juegos del genero plataforma,\n "
				"\t3 del genero laberinto y 5 del genero Aventura. \n"
				"\tListar los salones que cumplan con este minimo de requisito\n\n");
		printf("5.\tListar todos los arcades de un salon determinado ingresando su ID. \n"
				"\tInformar nombre y tipo de salon, listar todos los arcade con sus datos \n"
				"\tjunto con el nombre del juego que lo compone\n\n");
		printf("6.\tImprimir el salon con mas cantidad de arcade, indicando todos los \n"
				"\tdatos del salon y la cantidad de arcade que posee. Ordenado de manera ascendente\n\n");
		printf("7.\tListar los arcades que cumplan con sonido MONO y el genero de su juego sea \n"
				"\tPLATAFORMA, informando nombre de juego, genero y cantidad de jugadores que \n"
				"\tsoporta el arcade. El listado debera estar ordenado por nombre de juego.\n\n");
		printf("8.\tSalir\n");
		utn_getNumeroInt(&opcion, "Seleccione opcion", "Error reintente", 1, 8, 2);

		switch(opcion)
		{
		case 1:
			if(ReporteA(listaSalon,listaArcade))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 2:
			if(ReporteB(listaSalon,listaArcade,listaJuego))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 3:
			if(ReporteC(listaSalon))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 4:
			if(ReporteD(listaSalon,listaArcade,listaJuego))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 5:
			if(ReporteE(listaSalon,listaArcade,listaJuego))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 6:
			if(ReporteF(listaSalon,listaArcade))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 7:
			if(ReporteG(listaArcade,listaJuego))
			{
				printf("No se pudo listar\n");
			}
			break;
		case 8:
			break;
		}
	}
}


int ReporteA(LinkedList* listaSalon, LinkedList* listaArcade)
{
	int retorno = -1;
	int i,j;
	int contadorArcades=0;
	int imprimir = 0;
	Salon* pSalon = NULL;
	Arcade* pArcade = NULL;
	if(listaSalon != NULL && listaArcade != NULL)
	{
		printf("\n1.\tListar los salones con mas de 4 arcade. Indicando ID de salon, nombre,\n "
				"\tdireccion y tipo de salon.\n\n");
		printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO SALON");
		for (i=0; i<ll_len(listaSalon);i++)
		{
			pSalon = ll_get(listaSalon, i);
			for(j=0;j<ll_len(listaArcade);j++)
			{
				pArcade  = ll_get(listaArcade,j);
				if(pArcade->fkIdSalon == pSalon->Salon_id)
				{
					contadorArcades++;
				}
				if(contadorArcades>4)
				{
					imprimir = 1;
					break;
				}
			}
			if(imprimir==1)
			{
				Salon_printOneSalon(pSalon);
			}
			imprimir = 0;
			contadorArcades=0;
		}
		retorno = 0;
	}
	return retorno;
}


//B) Listar los arcade para más de 2 jugadores, indicando ID
//de arcade, cantidad de jugadores, nombre del juego, su
//género y nombre del salón al que pertenece.
int ReporteB(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego)
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
	if(listaSalon != NULL && listaSalon != NULL && listaSalon != NULL)
	{
		printf("2.\tListar los arcade para mas de 2 jugadores, indicando ID de arcade, \n"
						"\tcantidad de jugadores, nombre del juego, su genero y nombre del salon al que pertenece\n\n");
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
		}
		retorno = 0;
	}
	return retorno;
}

int ReporteC(LinkedList* listaSalon)
{
	int retorno = -1;
	int auxId,i;
	Salon* pSalon = NULL;
	if(listaSalon != NULL)
	{
		printf("3.\tListar toda la informacion de un salon en especifico ingresado por el usuario.\n "
						"\tImprimir ID de salon, nombre, tipo y direccion.\n\n");
		printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO SALON");
		for (i=0; i<ll_len(listaSalon);i++)
		{
			pSalon = ll_get(listaSalon, i);
			Salon_printOneSalon(pSalon);
		}
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A LISTAR:", "ERROR", 0, 9999, 2))
		{
			for (i=0; i<ll_len(listaSalon);i++)
			{
				pSalon = ll_get(listaSalon, i);
				if(pSalon->Salon_id == auxId)
				{
					printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO SALON");
					Salon_printOneSalon(pSalon);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int ReporteD(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego)
{
	int retorno = -1;
	int i,j,k;
	int cantPlataforma=0;
	int cantLaberinto=0;
	int cantAventura=0;
	int auxTipo=0;
	Arcade* pArcade = NULL;
	Salon* pSalon = NULL;
	Juego* pJuego = NULL;
	if(listaSalon != NULL && listaSalon != NULL && listaSalon != NULL)
	{
		printf("4.\tUn salon se encuentra completo si posee al menos \n"
				"\t4 juegos del genero plataforma,\n "
				"\t3 del genero laberinto y \n"
				"\t5 del genero Aventura. \n");
		printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO SALON");
		for (i=0; i<ll_len(listaSalon);i++)
		{
			pSalon = ll_get(listaSalon, i);
			for(j=0;j<ll_len(listaArcade);j++)
			{
				pArcade  = ll_get(listaArcade,j);
				if(pArcade->fkIdSalon == pSalon->Salon_id)
				{
					for(k=0;k<ll_len(listaJuego);k++)
					{
						pJuego = ll_get(listaJuego,k);
						if(pJuego->juegoId == pArcade->fkidJuego)
						{
							auxTipo = pJuego->juegoGenero;
							switch (auxTipo)
							{
							case PLATAFORMA:
								cantPlataforma++;
								break;
							case LABERINTO:
								cantLaberinto++;
								break;
							case AVENTURA:
								cantAventura++;
								break;
							}
						}
					}

				}
				if(cantPlataforma >= 4 && cantLaberinto >= 3 && cantAventura >= 5)
				{
					Salon_printOneSalon(pSalon);
					break;
				}
			}
			cantPlataforma = 0;
			cantLaberinto = 0;
			cantAventura = 0;
		}
		retorno = 0;
	}
	return retorno;
}


int ReporteE(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego)
{
	int retorno = -1;
	int i,j,k;
	char auxNombreJuego[LEN_NOMBREJUEGO];
	char auxGenero[LEN_GENERO];
	char tipoSonido[LEN_TIPOSONIDO];

	int auxIdSalon;
	int idLocalizado = -1;
	int genero;
	int auxTipoSonido;

	Arcade* pArcade = NULL;
	Salon* pSalon = NULL;
	Juego* pJuego = NULL;
	if(listaSalon != NULL && listaSalon != NULL && listaSalon != NULL)
	{
		printf("5.\tListar todos los arcades de un salon determinado ingresando su ID. \n"
				"\tInformar nombre y tipo de salon, listar todos los arcade con sus datos \n"
				"\tjunto con el nombre del juego que lo compone\n\n");

		for (i=0; i<ll_len(listaSalon);i++)
		{
			pSalon = ll_get(listaSalon, i);
			Salon_printOneSalon(pSalon);
		}
		if(!utn_getNumeroInt(&auxIdSalon, "ID SALON:", "ERROR", 0, 9999, 2))
		{
			for(i=0; i<ll_len(listaSalon); i++)
			{
				pSalon = ll_get(listaSalon,i);
				if(pSalon->Salon_id == auxIdSalon)
				{
					printf("------------------------------------------------------------------------------------\n");
					printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO SALON");
					Salon_printOneSalon(pSalon);
					printf("--------------------------------------------------------------------------------------------------------------\n");
					printf("|%-5s|%-30s|%-12s|%-15s|%-10s|%-20s|%-10s|\n","ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","JUEGO","GENERO");
					printf("--------------------------------------------------------------------------------------------------------------\n");
					idLocalizado = 0;
					for(j=0;j<ll_len(listaArcade);j++)
					{
						pArcade = ll_get(listaArcade,j);
						if(pArcade->fkIdSalon == pSalon->Salon_id)
						{
							for(k=0;k<ll_len(listaJuego);k++)
							{
								pJuego = ll_get(listaJuego, k);
								if(pJuego->juegoId == pArcade->fkidJuego)
								{
									strncpy(auxNombreJuego,pJuego->juegoNombre,LEN_NOMBREJUEGO);
									genero = pJuego->juegoGenero;
									juego_obtenerValorGenero(genero, auxGenero);
								}
							}
							auxTipoSonido = pArcade->Arcade_tipoSonido;
							if(arcade_obtenerValorTipoSonido(auxTipoSonido, tipoSonido)!=-1)
							printf("|%-5d|%-30s|%-12s|%-15d|%-10d|%-20s|%-10s|\n",pArcade->Arcade_id,pArcade->Arcade_nacionaliad,tipoSonido,
									pArcade->Arcade_cantJugadores,pArcade->Arcade_capacidad,auxNombreJuego, auxGenero);
						}
					}
				}
			}
			if(idLocalizado != 0)
			{
				puts("ID Salon no encontrdo, vuelva a listar los salones");
			}
		}
		retorno = 0;
	}
	return retorno;
}


int ReporteF(LinkedList* listaSalon, LinkedList* listaArcade)
{
	int retorno = -1;
	int i,j;
	int contadorArcades=0;
	int mayorCantidad=0;
	int primero = 0;
	int imprimir = 0;
	Salon* pSalon = NULL;
	Arcade* pArcade = NULL;
	Salon* auxMayor=NULL;
	if(listaSalon != NULL && listaArcade != NULL)
	{
		controller_sortArcade(listaArcade);
		printf("6.\tImprimir el salon con mas cantidad de arcade, indicando todos los \n"
				"\tdatos del salon y la cantidad de arcade que posee. Ordenado de manera ascendente\n\n");
		for (i=0; i<ll_len(listaSalon);i++)
		{
			pSalon = ll_get(listaSalon, i);
			for(j=0;j<ll_len(listaArcade);j++)
			{
				pArcade  = ll_get(listaArcade,j);
				if(pArcade->fkIdSalon == pSalon->Salon_id)
				{
					contadorArcades++;
					if(contadorArcades > mayorCantidad || primero == 0)
					{
						mayorCantidad=contadorArcades;
						primero = 1;
						auxMayor = pSalon;
						imprimir=1;
					}
				}
			}
			if(imprimir==1)
			{
				printf("|%-5s|%-30s|%-30s|%-15s|\n","ID", "NOMBRE","DIRECCION","TIPO SALON");
				Salon_printOneSalon(auxMayor);
				printf("|%-5s|%-30s|%-12s|%-15s|%-10s|%-10s|\n","ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","ID JUEGO");
				for(j=0;j<ll_len(listaArcade);j++)
				{
					pArcade = ll_get(listaArcade,j);
					if(pArcade->fkIdSalon==auxMayor->Salon_id)
					{
						Arcade_printOne(pArcade);
					}
				}
				printf("Cantidad de Arcades: %d: \n ", mayorCantidad);
			}
			imprimir = 0;
			contadorArcades=0;
		}
		retorno = 0;
	}
	return retorno;
}


int ReporteG(LinkedList* listaArcade, LinkedList* listaJuegos)
{
	int retorno = -1;
	int i,j;
	int contadorArcades=0;
	int mayorCantidad=0;
	int primero = 0;
	int imprimir = 0;
	Salon* pSalon = NULL;
	Arcade* pArcade = NULL;
	Salon* auxMayor=NULL;
	if(listaArcade != NULL && listaJuegos != NULL)
	{

	}
	return retorno;
}


