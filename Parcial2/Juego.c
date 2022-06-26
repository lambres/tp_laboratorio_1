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
	int auxTipoSalon = -1;
	Juego* this = Juego_new();
	if (this != NULL)
	{
		/*
		 * int juegoId;
			char juegoNombre[LEN_NOMBREJUEGO];
			char juegoEmpresa[LEN_EMPRESA];
			char juegoGenero[LEN_GENERO];
		 */
		if(Juego_setjuegoIdTxt(this, juegoIDStr) == -1 ||
		   Juego_setjuegoNombre(this, juegoNombreStr) == -1  ||
		   Juego_setjuegoEmpresa(this, juegoEmpresaStr) == -1 ||
		   Juego_setjuegoGenero(this, juegoGeneroStr) == -1)
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

int Juego_setjuegoIdTxt(Juego* this,char* id)
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

int Juego_getjuegoIdTxt(Juego* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->juegoId);
		retorno = 0;
	}
	return retorno;
}

int Juego_setjuegoNombre(Juego* this,char* nombre)
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


int Juego_setjuegoEmpresa(Juego* this,char* empresa)
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

int Juego_setjuegoGenero(Juego* this,char* genero)
{
	int retorno = -1;
	if(this != NULL && genero != NULL )
	{
		strncpy(this->juegoGenero,genero,LEN_GENERO);
		retorno = 0;
	}
	return retorno;
}
int Juego_getjuegoGenero(Juego* this,char* genero)
{
	int retorno = -1;
	if(this != NULL && genero != NULL )
	{
		strncpy(genero,this->juegoGenero,LEN_GENERO);
		retorno = 0;
	}
	return retorno;
}


int Juego_printOneJuego(Juego* pJuego)
{
	int retorno = -1;
	if (pJuego != NULL)
	{
		printf("|%-5d|%-30s|%-30s|%-15s|\n",pJuego->juegoId, pJuego->juegoNombre,pJuego->juegoEmpresa, pJuego->juegoGenero);
	}
	return retorno;
}

int Juego_printOneJuegoFile(FILE* archivo, Juego* pSalon)
{
	int retorno = -1;
	char auxId;
	char auxNombre[LEN_NOMBREJUEGO];
	char auxEmpresa[LEN_EMPRESA];
	char auxGenero[LEN_GENERO];
	if (pSalon != NULL && archivo != NULL)
	{
		if(!(Juego_getJuego_Id(pSalon, &auxId)) &&
			!(Juego_getJuegoNombre(pSalon, auxNombre)) &&
			!(Juego_getJuegoEmpresa(pSalon, auxEmpresa)) &&
			!(Juego_getjuegoGenero(pSalon, auxGenero)))
		{
			fprintf(archivo,"|%-5d|%-30s|%-30s|%-15s|\n",auxId, auxNombre,auxEmpresa,auxGenero);
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

