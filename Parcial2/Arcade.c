/*
 * Arcade.c
 *
 *  Created on: 19 may. 2022
 *      Author: Ruben Dario Zevallos Lambrescht DivH
 */

#include "LinkedList.h"
#include "Arcade.h"

Arcade* Arcade_new()
{
	return (Arcade*) malloc(sizeof(Arcade));
}

Arcade* Arcade_newParametros(char* idArcadeStr,char* nacionalidadStr ,char* tipoSonidoStr, char* cantJugadoresStr,
							 char* capacidadStr, char* fkidSalonStr, char* fkidJuegoStr)
{
	Arcade* this = Arcade_new();
	if (this != NULL)
	{
		/*
		 * 	int Arcade_id;
			char Arcade_nacionaliad[LEN_NACIONALIDAD];
			char Arcade_tipoSonido[LEN_TIPOSONIDO];
			int Arcade_cantJugadores;
			int Arcade_capacidad;
			int fkIdSalon;
			int fkidJuego;
		 */
		if(Arcade_setIdTxt(this, idArcadeStr) == -1 ||
		   Arcade_setNacionalidad(this, nacionalidadStr) == -1  ||
		   Arcade_setTipoSonido(this, tipoSonidoStr) == -1  ||
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

void Arcade_delete(Arcade* this)
{
	if(this != NULL)
	{
		free (this);
	}
}

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

int Arcade_setCantJugadores(Arcade* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >= 0 )
	{
		this->Arcade_cantJugadores=cantidad;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setCantJugadoresTxt(Arcade* this,char* cantJugadores)
{
	int retorno = -1;
	if(this != NULL && cantJugadores != NULL )
	{
		sprintf(cantJugadores,"%d",this->Arcade_cantJugadores);
		retorno = 0;
	}
	return retorno;
}


int Arcade_setCapacidadTxt(Arcade* this,char* capacidad)
{
	int retorno = -1;
	if(this != NULL && capacidad != NULL )
	{
		sprintf(capacidad,"%d",this->Arcade_capacidad);
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

int Arcade_setTipoSonido(Arcade* this,char* tipoSonido)
{
	int retorno = -1;
	if (this != NULL && tipoSonido != NULL )
	{
		strncpy(tipoSonido,this->Arcade_tipoSonido,LEN_TIPOSONIDO);
		retorno = 0;
	}
	return retorno;
}

int Arcade_getTipoSonido(Arcade* this,char* tipoSonido)
{
	int retorno = -1;
	if(this != NULL && tipoSonido != NULL )
	{
		strncpy(tipoSonido,this->Arcade_tipoSonido,LEN_TIPOSONIDO);
		retorno = 0;
	}
	return retorno;
}



int Arcade_printOne(Arcade* pArcade)
{
	int retorno = -1;
	if (pArcade != NULL)
	{
		printf("|%-5d|%-30s|%-8s|%4d|%4d|\n",pArcade->Arcade_id, pArcade->Arcade_nacionaliad,
				pArcade->Arcade_tipoSonido, pArcade->Arcade_cantJugadores, pArcade->Arcade_capacidad);
	}
	return retorno;
}

int Arcade_printOneFile(FILE* archivo, Arcade* pSalon)
{
	int retorno = -1;
	int auxId;
	char auxNacionalidad[LEN_NACIONALIDAD];
	char auxTipoSonido[LEN_TIPOSONIDO];
	int auxCantJugadores;
	int auxCapacidad;
	if (pSalon != NULL && archivo != NULL)
	{
		if(!(Arcade_getArcade_Id(pSalon, &auxId)) &&
			!(Arcade_getNacionalidad(pSalon, auxNacionalidad)) &&
			!(Arcade_getTipoSonido(pSalon, auxTipoSonido)) &&
			!(Arcade_getCantJugadores(pSalon, &auxCantJugadores)) &&
			!(Arcade_getCapacidad(pSalon, &auxCapacidad))
			)
		{
			fprintf(archivo,"|%-5d|%-30s|%-8s|%4d|%4d|\n",auxId, auxNacionalidad,auxTipoSonido,auxCantJugadores,auxCapacidad);
		}
		retorno = 0;
	}
	return retorno;
}



int Arcade_mayor(void* item1,void* item2)
{
	int retorno = 0;
	Arcade* primero;
	Arcade* segundo;
	char valor1[LEN_NACIONALIDAD];
	char valor2[LEN_NACIONALIDAD];
	primero = (Arcade*) item1;
	segundo = (Arcade*) item2;
	if(!Arcade_getNacionalidad(primero, valor1) &&
		!Arcade_getNacionalidad(segundo, valor2))
	{
		if(strncmp(valor1,valor2,LEN_NACIONALIDAD)>0)
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

