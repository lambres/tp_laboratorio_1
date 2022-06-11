/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"


Passenger* Passenger_new()
{
	return (Passenger*) malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr ,char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int auxTipoPasajero = -1;
	Passenger* this = Passenger_new();
	if (this != NULL)
	{
		auxTipoPasajero = Passenger_validatetipoPasajero(tipoPasajeroStr);
		if(auxTipoPasajero>=0)
		{
			if(Passenger_setIdTxt(this, idStr) == -1 ||
			   Passenger_setPrecioTxt(this, precioStr) == -1 ||
			   Passenger_setTipoPasajero(this, auxTipoPasajero) == -1  ||
			   Passenger_setNombre(this, nombreStr) == -1  ||
			   Passenger_setApellido(this, apellidoStr) == -1  ||
			   Passenger_setCodigoVuelo(this, codigoVueloStr) == -1  ||
			   Passenger_setEstadoVuelo(this, estadoVueloStr) == -1 )
			{
				Passenger_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free (this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		this->id=id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setIdTxt(Passenger* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		if (esNumerica(id, LEN_CHARID))
		{
			this->id=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getIdTxt(Passenger* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->id);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL )
	{
		strncpy(this->apellido,apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL )
	{
		strncpy(apellido,this->apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int retorno = -1;
	float auxiliarPrecio;
	if(this != NULL && precio != NULL)
	{
		if (esFlotante(precio))
		{
			auxiliarPrecio = atof(precio);
			if(auxiliarPrecio >=0)
			{
				this->precio = auxiliarPrecio;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio >=0 )
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getPrecioTxt(Passenger* this,char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL )
	{
		sprintf(precio,"%.0f",this->precio);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero >= 0 )
	{
		this->tipoPasajero=tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL )
	{
		*tipoPasajero=this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if (this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,LEN_CODVUELO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL )
	{
		strncpy(codigoVuelo,this->codigoVuelo,LEN_CODVUELO);
		retorno = 0;
	}
	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if (this != NULL && estadoVuelo != NULL)
	{
		strncpy(this->estadoVuelo,estadoVuelo,LEN_ESTADOVUELO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL )
	{
		strncpy(estadoVuelo,this->estadoVuelo,LEN_ESTADOVUELO);
		retorno = 0;
	}
	return retorno;
}

int Passenger_validatetipoPasajero(char* tipoPasajeroStr)
{
	int retorno = -1;
	if(strncmp(tipoPasajeroStr,"FirstClass",LEN_TIPOPASAJERO)==0)
			{
				retorno = 0;
			}
			else
			{
				if(strncmp(tipoPasajeroStr,"ExecutiveClass",LEN_TIPOPASAJERO)==0)
				{
					retorno = 1;
				}
				else
				{
					if(strncmp(tipoPasajeroStr,"EconomyClass",LEN_TIPOPASAJERO)==0)
					{
						retorno = 2;
					}
				}
			}

	return retorno;
}

int Passenger_printOne(Passenger* pPasajero)
{
	int retorno = -1;
	char auxTipoPasajero[LEN_TIPOPASAJERO];
	Passenger_getTipoPasajeroStr(pPasajero->tipoPasajero, auxTipoPasajero);
	if (pPasajero != NULL)
	{
		printf("%-10d|%-20s|%-20s|%-11.f|%-15s|%-15s|%-15s|\n",pPasajero->id, pPasajero->nombre,
				pPasajero->apellido, pPasajero->precio, pPasajero->codigoVuelo,
				auxTipoPasajero ,pPasajero->estadoVuelo);
	}
	return retorno;
}

int Passenger_printOneFile(FILE* archivo, Passenger* pPasajero)
{
	int retorno = -1;
	char auxIdStr[LEN_CHARID];
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	char auxPrecio[LEN_CHARPRICE];
	char auxFlycode[LEN_CODVUELO];
	char auxTipoPasajero[LEN_TIPOPASAJERO];
	char auxEstadoVuelo[LEN_ESTADOVUELO];
	int auxTipo;
	if (pPasajero != NULL && archivo != NULL)
	{
		if(!(Passenger_getIdTxt(pPasajero, auxIdStr)) &&
			!(Passenger_getNombre(pPasajero, auxNombre)) &&
			!(Passenger_getApellido(pPasajero, auxApellido)) &&
			!(Passenger_getPrecioTxt(pPasajero, auxPrecio)) &&
			!(Passenger_getCodigoVuelo(pPasajero, auxFlycode)) &&
			!(Passenger_getTipoPasajero(pPasajero, &auxTipo)) &&
			!(Passenger_getEstadoVuelo(pPasajero, auxEstadoVuelo)))
		{
			Passenger_getTipoPasajeroStr(auxTipo, auxTipoPasajero);
			fprintf(archivo,"%s,%s,%s,%s,%s,%s,%s\n",auxIdStr, auxNombre,auxApellido,
					auxPrecio, auxFlycode, auxTipoPasajero, auxEstadoVuelo);
		}
		retorno = 0;
	}
	return retorno;
}


int Passenger_getTipoPasajeroStr(int tipoPasajero, char* tipoPasajeroStr)
{
	int retorno = -1;
	if (tipoPasajeroStr != NULL && tipoPasajero >=0 && tipoPasajero <=2)
	{
		switch (tipoPasajero)
		{
		case 0:
			strncpy(tipoPasajeroStr,"FirstClass",LEN_TIPOPASAJERO);
			break;
		case 1:
			strncpy(tipoPasajeroStr,"ExecutiveClass",LEN_TIPOPASAJERO);
			break;
		case 2:
			strncpy(tipoPasajeroStr,"EconomyClass",LEN_TIPOPASAJERO);
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajeroStr(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero != NULL)
	{
		if (strncmp(tipoPasajero,"FirstClass",LEN_TIPOPASAJERO)==0)
		{
			this->tipoPasajero=0;
			retorno = 0;
		}
		else
		{
			if(strncmp(tipoPasajero,"ExecutiveClass",LEN_TIPOPASAJERO)==0)
			{
				this->tipoPasajero=1;
				retorno = 0;
			}
			else
			{
				if(strncmp(tipoPasajero,"EconomyClass",LEN_TIPOPASAJERO)==0)
				{
					this->tipoPasajero=2;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int Passenger_mayor(void* item1,void* item2)
{
	int retorno = 0;
	Passenger* primero;
	Passenger* segundo;
	char valor1[LEN_APELLIDO];
	char valor2[LEN_APELLIDO];
	primero = (Passenger*) item1;
	segundo = (Passenger*) item2;
	if(!Passenger_getApellido(primero, valor1) &&
		!Passenger_getApellido(segundo, valor2))
	{
		if(strncmp(valor1,valor2,LEN_APELLIDO)>0)
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

