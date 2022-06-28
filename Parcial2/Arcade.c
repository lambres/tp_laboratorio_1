/*
 * Arcade.c
 *
 *  Created on: 19 may. 2022
 *      Author: Ruben Dario Zevallos Lambrescht DivH
 */

#include "LinkedList.h"
#include "Arcade.h"
/// @fn Arcade Arcade_new*()
/// @brief Crea un espacio de memoria para alojar un nuevo elemento
///
/// @return Retorna el espacio de memoria reservado
Arcade* Arcade_new()
{
	return (Arcade*) malloc(sizeof(Arcade));
}
/// @fn Arcade Arcade_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief Define los campos y los guarda en el espacio de memoria solicitado
///
/// @param idArcadeStr
/// @param nacionalidadStr
/// @param tipoSonidoStr
/// @param cantJugadoresStr
/// @param capacidadStr
/// @param fkidSalonStr
/// @param fkidJuegoStr
/// @return retorna el puntero con los datos del elemento tomados recibidos como parametro
Arcade* Arcade_newParametros(char* idArcadeStr,char* nacionalidadStr ,char* tipoSonidoStr, char* cantJugadoresStr,
							 char* capacidadStr, char* fkidSalonStr, char* fkidJuegoStr)
{
	Arcade* this = Arcade_new();
	if (this != NULL)
	{
		if(Arcade_setIdTxt(this, idArcadeStr) == -1 ||
		   Arcade_setNacionalidad(this, nacionalidadStr) == -1  ||
		   Arcade_setTipoSonidoTxt(this, tipoSonidoStr) == -1  ||
		   Arcade_setCantJugadoresTxt(this, cantJugadoresStr) == -1 ||
		   Arcade_setCapacidadTxt(this, capacidadStr) == -1 ||
		   Arcade_setfkSalonTxt(this, fkidSalonStr) == -1 ||
		   Arcade_setfkJuegoTxt(this, fkidJuegoStr) == -1 )
		{
			Arcade_delete(this);
			this = NULL;
		}
	}
	return this;
}

/// @fn void Arcade_delete(Arcade*)
/// @brief Borra el elemento y libera el espacio de memoria
///
/// @param this elemento a ser eliminado
void Arcade_delete(Arcade* this)
{
	if(this != NULL)
	{
		free (this);
	}
}
/// @fn int Arcade_setArcade_Id(Arcade*, int)
/// @brief setea el campo id en formato int
///
/// @param this elemento a asignar el valor del campo
/// @param id valor a asignar
/// @return 0 si se pudo asignar (EXITO) -1 si no se pudo (ERROR)
int Arcade_setArcade_Id(Arcade* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		this->Arcade_id=id;
		retorno = 0;
	}
	return retorno;
}
/// @fn int Arcade_getArcade_Id(Arcade*, int*)
/// @brief obtiene el id del elemento
///
/// @param this elemento para poder obtener el campo
/// @param id campo a obtener el valor retornado como puntero
/// @return 0 si se pudo obtener el valor (EXITO) -1 si (ERROR)
int Arcade_getArcade_Id(Arcade* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		*id=this->Arcade_id;
		retorno = 0;
	}
	return retorno;
}

/// @fn int Arcade_setIdTxt(Arcade*, char*)
/// @brief  setea el campo id en formato str
///
/// @param this elemento
/// @param id campo a asignar el valor recibido como parametro
/// @return 0 si se  pudo asignar (EXITO) -1 si no se pudo (ERROR)
int Arcade_setIdTxt(Arcade* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		if (esNumerica(id, LEN_CHARARCADEID))
		{
			this->Arcade_id=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}
/// @fn int Arcade_getIdTxt(Arcade*, char*)
/// @brief obtiene el id del elemento
///
/// @param this elemento para poder obtener el campo
/// @param id campo a obtener el valor retornado como puntero en format str
/// @return 0 si se pudo obtener el valor (EXITO) -1 si (ERROR)
int Arcade_getIdTxt(Arcade* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->Arcade_id);
		retorno = 0;
	}
	return retorno;
}


int Arcade_setTipoSonidoTxt(Arcade* this,char* tipoSonido)
{
	int retorno = -1;
	if(this != NULL && tipoSonido != NULL )
	{
		if (esNumerica(tipoSonido, LEN_CHARARCADEID))
		{
			this->Arcade_tipoSonido=atoi(tipoSonido);
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_getTipoSonidoTxt(Arcade* this,char* tipoSonido)
{
	int retorno = -1;
	if(this != NULL && tipoSonido != NULL )
	{
		sprintf(tipoSonido,"%d",this->Arcade_tipoSonido);
		retorno = 0;
	}
	return retorno;
}



int Arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(this->Arcade_nacionaliad,nacionalidad,LEN_NACIONALIDAD);
		retorno = 0;
	}
	return retorno;
}
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL )
	{
		strncpy(nacionalidad,this->Arcade_nacionaliad,LEN_NACIONALIDAD);
		retorno = 0;
	}
	return retorno;
}

int Arcade_setCantJugadores(Arcade* this,int cantJugadores)
{
	int retorno = -1;
	if(this != NULL && cantJugadores >= 0 )
	{
		this->Arcade_cantJugadores=cantJugadores;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getCantJugadores(Arcade* this,int* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >= 0 )
	{
		*cantidad=this->Arcade_cantJugadores;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setCantJugadoresTxt(Arcade* this,char* cantJugadores)
{
	int retorno = -1;
	if(this != NULL && cantJugadores != NULL )
	{
		if (esNumerica(cantJugadores, LEN_CANTJUGADORES))
		{
			this->Arcade_cantJugadores=atoi(cantJugadores);
			retorno = 0;
		}
	}
	return retorno;
}


int Arcade_setCapacidadTxt(Arcade* this,char* capacidad)
{
	int retorno = -1;
	if(this != NULL && capacidad != NULL )
	{
		if (esNumerica(capacidad, LEN_CAPACIDAD))
		{
			this->Arcade_capacidad=atoi(capacidad);
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_getCapacidad(Arcade* this,int* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >= 0 )
	{
		*cantidad=this->Arcade_capacidad;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setfkSalonTxt(Arcade* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		if (esNumerica(id, LEN_CHARARCADEID))
		{
			this->fkIdSalon=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_setfkIdSalon(Arcade* this,int fkIdSalon)
{
	int retorno = -1;
	if(this != NULL && fkIdSalon >= 0 )
	{
		this->fkIdSalon=fkIdSalon;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getfkIdSalon(Arcade* this,int* fkIdSalon)
{
	int retorno = -1;
	if(this != NULL && fkIdSalon >= 0 )
	{
		*fkIdSalon=this->fkIdSalon;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setfkJuegoTxt(Arcade* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		if (esNumerica(id, LEN_CHARARCADEID))
		{
			this->fkidJuego=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_setfkIdJuego(Arcade* this,int fkIdJuego)
{
	int retorno = -1;
	if(this != NULL && fkIdJuego >= 0 )
	{
		this->fkidJuego=fkIdJuego;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getfkIdJuego(Arcade* this,int* fkIdJuego)
{
	int retorno = -1;
	if(this != NULL && fkIdJuego >= 0 )
	{
		*fkIdJuego=this->fkidJuego;
		retorno = 0;
	}
	return retorno;
}



int Arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int retorno = -1;
	if(this != NULL && tipoSonido >=0)
	{
		this->Arcade_tipoSonido =tipoSonido;
		retorno = 0;
	}
return retorno;
}

int Arcade_setCapacidad(Arcade* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >=200 && cantidad <= 400 )
	{
		this->Arcade_capacidad = cantidad;
		retorno = 0;
	}
return retorno;
}

int Arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int retorno = -1;
	if(this != NULL && tipoSonido >=0 )
	{
		*tipoSonido=this->Arcade_tipoSonido;
		retorno = 0;
	}
	return retorno;
}


/// @fn int Arcade_printOne(Arcade*)
/// @brief funcion que imprime un solo registro de arcade recibido como elemento
///
/// @param pArcade elemento a ser impreso
/// @return 0 si se pudo imprimir (EXITO) -1 si no se pudo (ERROR)

int Arcade_printOne(Arcade* pArcade)
{
	int retorno = -1;
	char tipoSonido[LEN_TIPOSONIDO];
	int auxTipoSonido;
	if (pArcade != NULL)
	{
		auxTipoSonido = pArcade->Arcade_tipoSonido;
		if(!arcade_obtenerValorTipoSonido(auxTipoSonido, tipoSonido))
		{
			printf("|%-5d|%-30s|%-12s|%-15d|%-10d|%-10d|\n",pArcade->Arcade_id, pArcade->Arcade_nacionaliad,
					tipoSonido, pArcade->Arcade_cantJugadores, pArcade->Arcade_capacidad, pArcade->fkidJuego);
		}
	}
	return retorno;
}
/// @fn int Arcade_printOneFile(FILE*, Arcade*)
/// @brief Funcion que imprime en un archivo de texto los valores del elemento recibido como parametro
///
/// @param archivo nombre del archivo a ser impreso o guardado
/// @param pSalon elemento a ser impreso o guardado
/// @return 0 si se pudo imprimir (EXITO) y -1 si no se pudo (ERROR)
int Arcade_printOneFile(FILE* archivo, Arcade* pSalon)
{
	int retorno = -1;
	int auxId;
	char auxNacionalidad[LEN_NACIONALIDAD];
	char auxTipoSonido[LEN_TIPOSONIDO];
	int auxCantJugadores;
	int auxCapacidad;
	int auxfkIdSalon;
	int auxfkIdJuego;
	if (pSalon != NULL && archivo != NULL)
	{
		if(!(Arcade_getArcade_Id(pSalon, &auxId)) &&
			!(Arcade_getNacionalidad(pSalon, auxNacionalidad)) &&
			!(Arcade_getTipoSonidoTxt(pSalon, auxTipoSonido)) &&
			!(Arcade_getCantJugadores(pSalon, &auxCantJugadores)) &&
			!(Arcade_getCapacidad(pSalon, &auxCapacidad)) &&
			!(Arcade_getfkIdSalon(pSalon, &auxfkIdSalon)) &&
			!(Arcade_getfkIdJuego(pSalon, &auxfkIdJuego)))
		{
			fprintf(archivo,"%d,%s,%s,%d,%d,%d,%d\n",auxId, auxNacionalidad,auxTipoSonido,auxCantJugadores,auxCapacidad,auxfkIdSalon,auxfkIdJuego);
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int Arcade_mayor(void*, void*)
/// @brief compara dos elementos pasados como parametros
///
/// @param item1 elemento 1 a comparar
/// @param item2 elemento 2 a comparar
/// @return 0 si son los elementos iguales, -1 si valor 1 es mayor a valor 2 y 1 en caso contrario

int Arcade_mayor(void* item1,void* item2)
{
	int retorno = 0;
	Arcade* primero;
	Arcade* segundo;
	int valor1;
	int valor2;
	primero = (Arcade*) item1;
	segundo = (Arcade*) item2;
	if(!Arcade_getArcade_Id(primero, &valor1) &&
		!Arcade_getArcade_Id(segundo, &valor2))
	{
		if(valor1>valor2)
		{
			retorno = -1;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}


/// @fn int arcade_obtenerValorTipoSonido(int, char*)
/// @brief funcion que convierte el parametro recibido como entero en estring convertido
/// si es 0 devuelvo ESTEREO y si recibo 1 devuelvo MONO
/// @param tipoInt valor entero a convertir
/// @param tipoStr valor a devolver en formato cadena
/// @return
int arcade_obtenerValorTipoSonido(int tipoInt, char* tipoStr)
{
	int retorno = -1;
	if (tipoInt >= 0 && tipoInt <= 1 && tipoStr != NULL)
	{
		switch (tipoInt)
			{
			case STEREO:
				strncpy(tipoStr,"STEREO",LEN_TIPOSONIDO);
				break;
			case MONO:
				strncpy(tipoStr,"MONO",LEN_TIPOSONIDO);
				break;
			}
		retorno = 0;
	}
	return retorno;
}

