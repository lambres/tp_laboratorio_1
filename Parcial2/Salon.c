/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Ruben Dario Zevallos Lambrescht DivH
 */

#include "LinkedList.h"
#include "Salon.h"

Salon* Salon_new()
{
	return (Arcade*) malloc(sizeof(Arcade));
}

Salon* Salon_newParametros(char* idSalonStr,char* nombreStr ,char* direccionStr, char* tipoStr)
{
	int auxTipoSalon = -1;
	Salon* this = Salon_new();
	if (this != NULL)
	{
		auxTipoSalon = Salon_validateTipoSalon(tipoStr);
		if(auxTipoSalon>=0)
		{
			if(Salon_setSalon_IdTxt(this, idSalonStr) == -1 ||
			   Salon_setSalon_Nombre(this, nombreStr) == -1  ||
			   Salon_setSalon_Direccion(this, direccionStr) == -1 ||
			   Salon_setTipoSalon(this, auxTipoSalon) == -1)
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
		this->Salon_id=id;
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
			this->Salon_id=atoi(id);
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
		*id=this->Salon_id;
		retorno = 0;
	}
	return retorno;
}

int Salon_getSalon_IdTxt(Salon* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->Salon_id);
		retorno = 0;
	}
	return retorno;
}

int Salon_setSalon_Nombre(Salon* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->Salon_nombre,nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
int Salon_getSalon_Nombre(Salon* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->Salon_nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}


int Salon_setSalon_Direccion(Salon* this,char* direccion)
{
	int retorno = -1;
	if(this != NULL && direccion != NULL )
	{
		strncpy(this->Salon_direccion,direccion,LEN_DIRECCION);
		retorno = 0;
	}
	return retorno;
}

int Salon_getSalon_Direccion(Salon* this,char* direccion)
{
	int retorno = -1;
	if(this != NULL && direccion != NULL )
	{
		strncpy(direccion,this->Salon_direccion,LEN_DIRECCION);
		retorno = 0;
	}
	return retorno;
}

int Salon_setTipoSalon(Salon* this,int tipoSalon)
{
	int retorno = -1;
	if (this != NULL && tipoSalon >= 0 )
	{
		this->Salon_tipo=tipoSalon;
		retorno = 0;
	}
	return retorno;
}
int Salon_getTipoSalon(Salon* this,int* tipoSalon)
{
	int retorno = -1;
	if(this != NULL && tipoSalon != NULL )
	{
		*tipoSalon=this->Salon_tipo;
		retorno = 0;
	}
	return retorno;
}


int Salon_validateTipoSalon(char* tipoSalonStr)
{
	int retorno = -1;
	if(strncmp(tipoSalonStr,"SHOPPING",LEN_TIPOSALON)==0)
			{
				retorno = SHOPPING;
			}
			else
			{
				if(strncmp(tipoSalonStr,"LOCAL",LEN_TIPOSALON)==0)
				{
					retorno = LOCAL;
				}
			}

	return retorno;
}

int Salon_printOneSalon(Salon* pSalon)
{
	int retorno = -1;
	char auxTipoPasajero[LEN_TIPOSALON];
	Salon_getTipoSalonStr(pSalon->Salon_tipo, auxTipoPasajero);
	if (pSalon != NULL)
	{
		printf("%-10d|%-20s|%-20s|%-15s|\n",pSalon->Salon_id, pSalon->Salon_nombre,
				pSalon->Salon_direccion, pSalon->Salon_tipo);
	}
	return retorno;
}

int Salon_printOneSalonFile(FILE* archivo, Salon* pSalon)
{
	int retorno = -1;
	char auxIdStr[LEN_CHARSALONID];
	char auxNombre[LEN_NOMBRE];
	char auxDireccion[LEN_DIRECCION];
	char auxTipoSalon[LEN_TIPOSALON];
	int auxTipo;
	if (pSalon != NULL && archivo != NULL)
	{
		if(!(Salon_getSalon_IdTxt(pSalon, auxIdStr)) &&
			!(Salon_getSalon_Nombre(pSalon, auxNombre)) &&
			!(Salon_getSalon_Direccion(pSalon, auxDireccion)) &&
			!(Salon_getTipoSalonStr(pSalon, &auxTipo)))
		{
			Salon_getTipoSalonStr(auxTipo, auxTipoSalon);
			fprintf(archivo,"%s,%s,%s,%s\n",auxIdStr, auxNombre,auxDireccion,auxTipoSalon);
		}
		retorno = 0;
	}
	return retorno;
}


int Salon_getTipoSalonStr(int tipoSalon, char* tipoSalonStr)
{
	int retorno = -1;
	if (tipoSalonStr != NULL && tipoSalon >=0 && tipoSalon <=2)
	{
		switch (tipoSalon)
		{
		case 1:
			strncpy(tipoSalonStr,"SHOPPING",LEN_TIPOSALON);
			break;
		case 2:
			strncpy(tipoSalonStr,"LOCAL",LEN_TIPOSALON);
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int Salon_setTipoSalonStr(Salon* this,char* tipoSalon)
{
	int retorno = -1;
	if (this != NULL && tipoSalon != NULL)
	{
		if (strncmp(tipoSalon,"SHOPPING",LEN_TIPOSALON)==0)
		{
			this->Salon_tipo=1;
			retorno = 0;
		}
		else
		{
			if(strncmp(tipoSalon,"LOCAL",LEN_TIPOSALON)==0)
			{
				this->Salon_tipo=2;
				retorno = 0;
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
	char valor1[LEN_NOMBRE];
	char valor2[LEN_NOMBRE];
	primero = (Salon*) item1;
	segundo = (Salon*) item2;
	if(!Salon_getSalon_Nombre(primero, valor1) &&
		!Salon_getSalon_Nombre(segundo, valor2))
	{
		if(strncmp(valor1,valor2,LEN_NOMBRE)>0)
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

