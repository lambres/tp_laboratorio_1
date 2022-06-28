/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Ruben Dario Zevallos Lambrescht DivH
 */

#include "LinkedList.h"
#include "Juego.h"

Juego* Juego_new()
{
	return (Juego*) malloc(sizeof(Juego));
}

Juego* Juego_newParametros(char* juegoIDStr,char* juegoNombreStr ,char* juegoEmpresaStr, char* juegoGeneroStr)
{
	Juego* this = Juego_new();
	if (this != NULL)
	{
		if(Juego_setJuegoIdTxt(this, juegoIDStr) == -1 ||
		   Juego_setJuegoNombre(this, juegoNombreStr) == -1  ||
		   Juego_setJuegoEmpresa(this, juegoEmpresaStr) == -1 ||
		   Juego_setGeneroTxt(this, juegoGeneroStr) == -1)
		{
		   Juego_delete(this);
		   this = NULL;
		}
	}
	return this;
}

void Juego_delete(Juego* this)
{
	if(this != NULL)
	{
		free (this);
	}
}

int Juego_setJuego_Id(Juego* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		this->juegoId=id;
		retorno = 0;
	}
	return retorno;
}

int Juego_getJuego_Id(Juego* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		*id=this->juegoId;
		retorno = 0;
	}
	return retorno;
}

int Juego_setJuegoIdTxt(Juego* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		if (esNumerica(id, LEN_CHARJUEGOID))
		{
			this->juegoId=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}

int Juego_getJuegoIdTxt(Juego* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->juegoId);
		retorno = 0;
	}
	return retorno;
}

int Juego_setJuegoNombre(Juego* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->juegoNombre,nombre,LEN_NOMBREJUEGO);
		retorno = 0;
	}
	return retorno;
}
int Juego_getJuegoNombre(Juego* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->juegoNombre,LEN_NOMBREJUEGO);
		retorno = 0;
	}
	return retorno;
}


int Juego_setJuegoEmpresa(Juego* this,char* empresa)
{
	int retorno = -1;
	if(this != NULL && empresa != NULL )
	{
		strncpy(this->juegoEmpresa,empresa,LEN_EMPRESA);
		retorno = 0;
	}
	return retorno;
}

int Juego_getJuegoEmpresa(Juego* this,char* empresa)
{
	int retorno = -1;
	if(this != NULL && empresa != NULL )
	{
		strncpy(empresa,this->juegoEmpresa,LEN_EMPRESA);
		retorno = 0;
	}
	return retorno;
}

int Juego_setJuegoGenero(Juego* this,int genero)
{
	int retorno = -1;
	if(this != NULL && genero >=0 )
	{
		this->juegoGenero=genero;
		retorno = 0;
	}
	return retorno;
}
int Juego_getJuegoGenero(Juego* this,int* genero)
{
	int retorno = -1;
	if(this != NULL && genero >=0 )
	{
		*genero=this->juegoGenero;
		retorno = 0;
	}
	return retorno;
}

int Juego_setGeneroTxt(Juego* this,char* genero)
{
	int retorno = -1;
	if(this != NULL && genero != NULL )
	{
		if (esNumerica(genero, LEN_CHARJUEGOID))
		{
			this->juegoGenero=atoi(genero);
			retorno = 0;
		}
	}
	return retorno;
}

int Juego_getGeneroTxt(Juego* this,char* genero)
{
	int retorno = -1;
	if(this != NULL && genero != NULL )
	{
		sprintf(genero,"%d",this->juegoGenero);
		retorno = 0;
	}
	return retorno;
}
int Juego_printOneJuego(Juego* pJuego)
{
	int retorno = -1;
	int auxjuegoGenero;
	char auxGenero[LEN_GENERO];
	Juego_getJuegoGenero(pJuego, &auxjuegoGenero);
	juego_obtenerValorGenero(auxjuegoGenero, auxGenero);
	if (pJuego != NULL)
	{
		printf("|%-5d|%-30s|%-30s|%-15s|\n",pJuego->juegoId, pJuego->juegoNombre,pJuego->juegoEmpresa, auxGenero);
	}
	return retorno;
}

int Juego_printOneJuegoFile(FILE* archivo, Juego* pJuego)
{
	int retorno = -1;
	int auxId;
	char auxNombre[LEN_NOMBREJUEGO];
	char auxEmpresa[LEN_EMPRESA];
	int auxGenero;
	if (pJuego != NULL && archivo != NULL)
	{
		if(!(Juego_getJuego_Id(pJuego, &auxId)) &&
			!(Juego_getJuegoNombre(pJuego, auxNombre)) &&
			!(Juego_getJuegoEmpresa(pJuego, auxEmpresa)) &&
			!(Juego_getJuegoGenero(pJuego, &auxGenero)))
		{
			fprintf(archivo,"%d,%s,%s,%d\n",auxId, auxNombre,auxEmpresa,auxGenero);
		}
		retorno = 0;
	}
	return retorno;
}


int Juego_mayor(void* item1,void* item2)
{
	int retorno = 0;
	Juego* primero;
	Juego* segundo;
	char valor1[LEN_NOMBREJUEGO];
	char valor2[LEN_NOMBREJUEGO];
	primero = (Juego*) item1;
	segundo = (Juego*) item2;
	if(!Juego_getJuegoNombre(primero, valor1) &&
		!Juego_getJuegoNombre(segundo, valor2))
	{
		if(strncmp(valor1,valor2,LEN_NOMBREJUEGO)>0)
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

int Salon_validateGenero(char* generoStr)
{
	int retorno = -1;
	if(strncmp(generoStr,"PLATAFORMA",LEN_GENERO)==0)
			{
				retorno = PLATAFORMA;
			}
			else
			{
				if(strncmp(generoStr,"LABERINTO",LEN_GENERO)==0)
				{
					retorno = LABERINTO;
				}
				else
				{
					if(strncpy(generoStr,"AVENTURA",LEN_GENERO)==0)
					{
						retorno = AVENTURA;
					}
					else
					{
						if(strncpy(generoStr,"OTRO",LEN_GENERO)==0)
						{
							retorno = OTRO;
						}
					}
				}
			}

	return retorno;
}


void juego_obtenerValorGenero(int generoInt, char* generoStr)
{
	switch (generoInt)
		{
		case 0:
			strncpy(generoStr,"PLATAFORMA",LEN_GENERO);
			break;
		case 1:
			strncpy(generoStr,"LABERINTO",LEN_GENERO);
			break;
		case 2:
			strncpy(generoStr,"AVENTURA",LEN_GENERO);
			break;
		case 3:
			strncpy(generoStr,"OTRO",LEN_GENERO);
			break;
		}
}
