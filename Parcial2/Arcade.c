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
			//,"ID","NACIONALIDAD","TIPO SONIDO","CANT JUGADORES","CAPACIDAD","ID SALON","ID JUEGO");
			printf("|%-5d|%-30s|%-12s|%-15d|%-10d|%-10d|\n",pArcade->Arcade_id, pArcade->Arcade_nacionaliad,
					tipoSonido, pArcade->Arcade_cantJugadores, pArcade->Arcade_capacidad, pArcade->fkidJuego);
		}
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
			//Arcade_id,Arcade_nacionalidad,Arcade_tipoSonido,Arcade_cantJugadores,Arcade_capacidad,fkIdSalon,fkIdJuego
			fprintf(archivo,"%d,%s,%s,%d,%d,%d,%d\n",auxId, auxNacionalidad,auxTipoSonido,auxCantJugadores,auxCapacidad,auxfkIdSalon,auxfkIdJuego);
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

int Salon_validateTipoSonido(char* tipoSonidoStr)
{
	int retorno = -1;
	if(strncmp(tipoSonidoStr,"STEREO",LEN_TIPOSONIDO)==0)
			{
				retorno = STEREO;
			}
			else
			{
				if(strncmp(tipoSonidoStr,"MONO",LEN_TIPOSONIDO)==0)
				{
					retorno = MONO;
				}
			}
	return retorno;
}
