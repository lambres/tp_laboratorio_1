#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"


/** \brief Parsea los datos los datos de los Salones desde el archivo Salon.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *	int Salon_id;
 *	char Salon_nombre[LEN_NOMBRE];
 *	char Salon_direccion[LEN_DIRECCION];
 *	int Salon_tipo;
 */
int parser_SalonFromText(FILE* pFile , LinkedList* pArrayListSalon)
{
	int retorno = 1;
	char auxId[LEN_CHARSALONID];
	char auxSalon_nombre[LEN_NOMBRE];
	char auxSalon_direccion[LEN_DIRECCION];
	char auxSalon_Tipo[LEN_TIPOSALON];

	int camposLeidos;

	if (pFile != NULL && pArrayListSalon != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxSalon_nombre,auxSalon_direccion,auxSalon_Tipo);
		do
		{
			camposLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxSalon_nombre,auxSalon_direccion,auxSalon_Tipo);
			if (camposLeidos==4)
			{
				Salon* salon = Salon_newParametros(auxId,auxSalon_nombre,auxSalon_direccion,auxSalon_Tipo);
				if (salon!=NULL)
				{
					ll_add(pArrayListSalon, salon);
					retorno = 0;
				}
			}
		}while (!feof(pFile));
		puts("Archivo Salon.csv procesado correctamente");
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los Arcades desde el archivo Arcade.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *	int Arcade_id;
 *	char Arcade_nacionaliad[LEN_NACIONALIDAD];
 *	char Arcade_tipoSonido[LEN_TIPOSONIDO];
 *	int Arcade_cantJugadores;
 *	int Arcade_capacidad;
 *	int fkIdSalon;
 *	int fkidJuego;
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno = 1;
	char aux_Id[LEN_CHARARCADEID];
	char aux_nacionalidad[LEN_NACIONALIDAD];
	char aux_tipoSonido[LEN_TIPOSONIDO];
	char aux_cantJugadores[LEN_CANTJUGADORES];
	char aux_capacidad[LEN_CAPACIDAD];
	char auxfkSalon[LEN_CHARSALONID];
	char auxfkJuego[LEN_CHARJUEGOID];

	int camposLeidos;

	if (pFile != NULL && pArrayListArcade != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",aux_Id,aux_nacionalidad,aux_tipoSonido,
				aux_cantJugadores,aux_capacidad,auxfkSalon,auxfkJuego);
		do
		{
			camposLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",aux_Id,aux_nacionalidad,aux_tipoSonido,
					aux_cantJugadores,aux_capacidad,auxfkSalon,auxfkJuego);
			if (camposLeidos==7)
			{
				Arcade* arcade = Arcade_newParametros(aux_Id,aux_nacionalidad,aux_tipoSonido,
						aux_cantJugadores,aux_capacidad,auxfkSalon,auxfkJuego);
				if (arcade!=NULL)
				{
					ll_add(pArrayListArcade, arcade);
					retorno = 0;
				}
			}
		}while (!feof(pFile));
		puts("Archivo Arcade.csv procesado correctamente");
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los Juegos desde el archivo Juego.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *	int juegoId;
 *	char juegoNombre[LEN_NOMBREJUEGO];
 *	char juegoEmpresa[LEN_EMPRESA];
 *	char juegoGenero[LEN_GENERO];
 */
int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuegos)
{
	int retorno = 1;
	char auxjuegoId[LEN_CHARJUEGOID];
	char auxjuegoNombre[LEN_NOMBREJUEGO];
	char auxjuegoEmpresa[LEN_EMPRESA];
	char auxjuegoGenero[LEN_GENERO];

	int camposLeidos;

	if (pFile != NULL && pArrayListJuegos != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxjuegoId,auxjuegoNombre,auxjuegoEmpresa,auxjuegoGenero);
		do
		{
			camposLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxjuegoId,auxjuegoNombre,auxjuegoEmpresa,auxjuegoGenero);
			if (camposLeidos==4)
			{
				Juego* juego = Juego_newParametros(auxjuegoId,auxjuegoNombre,auxjuegoEmpresa,auxjuegoGenero);
				if (juego!=NULL)
				{
					ll_add(pArrayListJuegos, juego);
					retorno = 0;
				}
			}
		}while (!feof(pFile));
		puts("Archivo Juego.csv procesado correctamente");
	}
	return retorno;
}

