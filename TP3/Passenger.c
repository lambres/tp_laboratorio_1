/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"


Salon* Salon_new()
{
	return (Salon*) malloc(sizeof(Salon));
}

Salon* Salon_newParametros(char* idStr,char* nombreStr ,char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int auxTipoPasajero = -1;
	Salon* this = Salon_new();
	if (this != NULL)
	{
		auxTipoPasajero = Salon_validateTipoSalon(tipoPasajeroStr);
		if(auxTipoPasajero>=0)
		{
			if(Salon_setSalon_IdTxt(this, idStr) == -1 ||
			   Salon_setPrecioTxt(this, precioStr) == -1 ||
			   Salon_setTipoPasajero(this, auxTipoPasajero) == -1  ||
			   Salon_setSalon_Nombre(this, nombreStr) == -1  ||
			   Salon_setSalon_Direccion(this, apellidoStr) == -1  ||
			   Salon_setCodigoVuelo(this, codigoVueloStr) == -1  ||
			   Salon_setEstadoVuelo(this, estadoVueloStr) == -1 )
			{
				Salon_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}

void Salon_delete(Salon* this)
{
	if(this != NULL)
	{
		free (this);
	}
}

int Salon_setSalon_Id(Salon* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		this->id=id;
		retorno = 0;
	}
	return retorno;
}

int Salon_setSalon_IdTxt(Salon* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		if (esNumerica(id, LEN_CHARSALONID))
		{
			this->id=atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}

int Salon_getSalon_Id(Salon* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}

int Salon_getSalon_IdTxt(Salon* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->id);
		retorno = 0;
	}
	return retorno;
}

int Salon_setSalon_Nombre(Salon* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
int Salon_getSalon_Nombre(Salon* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}


int Salon_setSalon_Direccion(Salon* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL )
	{
		strncpy(this->apellido,apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

int Salon_getSalon_Direccion(Salon* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL )
	{
		strncpy(apellido,this->apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

int Salon_setPrecio(Salon* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int Salon_setPrecioTxt(Salon* this,char* precio)
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

int Salon_getPrecio(Salon* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio >=0 )
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Salon_getPrecioTxt(Salon* this,char* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL )
	{
		sprintf(precio,"%.0f",this->precio);
		retorno = 0;
	}
	return retorno;
}

int Salon_setTipoPasajero(Salon* this,int tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero >= 0 )
	{
		this->tipoPasajero=tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
int Salon_getTipoPasajero(Salon* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL )
	{
		*tipoPasajero=this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Salon_setCodigoVuelo(Salon* this,char* codigoVuelo)
{
	int retorno = -1;
	if (this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,LEN_CODVUELO);
		retorno = 0;
	}
	return retorno;
}
int Salon_getCodigoVuelo(Salon* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL )
	{
		strncpy(codigoVuelo,this->codigoVuelo,LEN_CODVUELO);
		retorno = 0;
	}
	return retorno;
}


int Salon_setEstadoVuelo(Salon* this,char* estadoVuelo)
{
	int retorno = -1;
	if (this != NULL && estadoVuelo != NULL)
	{
		strncpy(this->estadoVuelo,estadoVuelo,LEN_ESTADOVUELO);
		retorno = 0;
	}
	return retorno;
}
int Salon_getEstadoVuelo(Salon* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL )
	{
		strncpy(estadoVuelo,this->estadoVuelo,LEN_ESTADOVUELO);
		retorno = 0;
	}
	return retorno;
}

int Salon_validateTipoSalon(char* tipoPasajeroStr)
{
	int retorno = -1;
	if(strncmp(tipoPasajeroStr,"FirstClass",LEN_TIPOSALON)==0)
			{
				retorno = 0;
			}
			else
			{
				if(strncmp(tipoPasajeroStr,"ExecutiveClass",LEN_TIPOSALON)==0)
				{
					retorno = 1;
				}
				else
				{
					if(strncmp(tipoPasajeroStr,"EconomyClass",LEN_TIPOSALON)==0)
					{
						retorno = 2;
					}
				}
			}

	return retorno;
}

int Salon_printOneSalon(Salon* pPasajero)
{
	int retorno = -1;
	char auxTipoPasajero[LEN_TIPOSALON];
	Salon_getTipoSalonStr(pPasajero->tipoPasajero, auxTipoPasajero);
	if (pPasajero != NULL)
	{
		printf("%-10d|%-20s|%-20s|%-11.f|%-15s|%-15s|%-15s|\n",pPasajero->id, pPasajero->nombre,
				pPasajero->apellido, pPasajero->precio, pPasajero->codigoVuelo,
				auxTipoPasajero ,pPasajero->estadoVuelo);
	}
	return retorno;
}

int Salon_printOneSalonFile(FILE* archivo, Salon* pPasajero)
{
	int retorno = -1;
	char auxIdStr[LEN_CHARSALONID];
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	char auxPrecio[LEN_CHARPRICE];
	char auxFlycode[LEN_CODVUELO];
	char auxTipoPasajero[LEN_TIPOSALON];
	char auxEstadoVuelo[LEN_ESTADOVUELO];
	int auxTipo;
	if (pPasajero != NULL && archivo != NULL)
	{
		if(!(Salon_getSalon_IdTxt(pPasajero, auxIdStr)) &&
			!(Salon_getSalon_Nombre(pPasajero, auxNombre)) &&
			!(Salon_getSalon_Direccion(pPasajero, auxApellido)) &&
			!(Salon_getPrecioTxt(pPasajero, auxPrecio)) &&
			!(Salon_getCodigoVuelo(pPasajero, auxFlycode)) &&
			!(Salon_getTipoPasajero(pPasajero, &auxTipo)) &&
			!(Salon_getEstadoVuelo(pPasajero, auxEstadoVuelo)))
		{
			Salon_getTipoSalonStr(auxTipo, auxTipoPasajero);
			fprintf(archivo,"%s,%s,%s,%s,%s,%s,%s\n",auxIdStr, auxNombre,auxApellido,
					auxPrecio, auxFlycode, auxTipoPasajero, auxEstadoVuelo);
		}
		retorno = 0;
	}
	return retorno;
}


int Salon_getTipoSalonStr(int tipoPasajero, char* tipoPasajeroStr)
{
	int retorno = -1;
	if (tipoPasajeroStr != NULL && tipoPasajero >=0 && tipoPasajero <=2)
	{
		switch (tipoPasajero)
		{
		case 0:
			strncpy(tipoPasajeroStr,"FirstClass",LEN_TIPOSALON);
			break;
		case 1:
			strncpy(tipoPasajeroStr,"ExecutiveClass",LEN_TIPOSALON);
			break;
		case 2:
			strncpy(tipoPasajeroStr,"EconomyClass",LEN_TIPOSALON);
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int Salon_setTipoSalonStr(Salon* this,char* tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero != NULL)
	{
		if (strncmp(tipoPasajero,"FirstClass",LEN_TIPOSALON)==0)
		{
			this->tipoPasajero=0;
			retorno = 0;
		}
		else
		{
			if(strncmp(tipoPasajero,"ExecutiveClass",LEN_TIPOSALON)==0)
			{
				this->tipoPasajero=1;
				retorno = 0;
			}
			else
			{
				if(strncmp(tipoPasajero,"EconomyClass",LEN_TIPOSALON)==0)
				{
					this->tipoPasajero=2;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int Salon_mayor(void* item1,void* item2)
{
	int retorno = 0;
	Salon* primero;
	Salon* segundo;
	char valor1[LEN_APELLIDO];
	char valor2[LEN_APELLIDO];
	primero = (Salon*) item1;
	segundo = (Salon*) item2;
	if(!Salon_getSalon_Direccion(primero, valor1) &&
		!Salon_getSalon_Direccion(segundo, valor2))
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

