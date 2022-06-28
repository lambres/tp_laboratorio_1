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
	return (Salon*) malloc(sizeof(Salon));
}

Salon* Salon_newParametros(char* idSalonStr,char* nombreStr ,char* direccionStr, char* tipoStr)
{
	Salon* this = Salon_new();
	if (this != NULL)
	{
		if(Salon_setSalon_IdTxt(this, idSalonStr) == -1 ||
		   Salon_setSalon_Nombre(this, nombreStr) == -1  ||
		   Salon_setSalon_Direccion(this, direccionStr) == -1 ||
		   Salon_setTipoSalonStr(this, tipoStr) == -1)
		{
			Salon_delete(this);
			this = NULL;
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
		char tipoSalon[LEN_TIPOSALON];
		int auxId;
		if (pSalon != NULL)
		{
			Salon_getTipoSalon(pSalon, &auxId);
			if(!salon_obtenerValorTipo(auxId, tipoSalon))
			{
				printf("|%-5d|%-30s|%-30s|%-15s|\n",pSalon->Salon_id, pSalon->Salon_nombre,pSalon->Salon_direccion,tipoSalon);
			}
		retorno = 0;
		}
	return retorno;
}

int Salon_printOneSalonFile(FILE* archivo, Salon* pSalon)
{
	int retorno = -1;
	char auxIdStr[LEN_CHARSALONID];
	char auxNombre[LEN_NOMBRE];
	char auxDireccion[LEN_DIRECCION];
	int auxTipo;
	if (pSalon != NULL && archivo != NULL)
	{
		if(!(Salon_getSalon_IdTxt(pSalon, auxIdStr)) &&
			!(Salon_getSalon_Nombre(pSalon, auxNombre)) &&
			!(Salon_getSalon_Direccion(pSalon, auxDireccion)) &&
			!(Salon_getTipoSalon(pSalon, &auxTipo)))
		{
			fprintf(archivo,"%s,%s,%s,%d\n",auxIdStr, auxNombre,auxDireccion,auxTipo);
		}
		retorno = 0;
	}
	return retorno;
}


int Salon_getTipoSalonStr(Salon* this, char* tipoSalonStr)
{
	int retorno = -1;
	if(this != NULL && tipoSalonStr != NULL )
	{
		sprintf(tipoSalonStr,"%d",this->Salon_tipo);
		retorno = 0;
	}
	return retorno;
}

int Salon_setTipoSalonStr(Salon* this,char* tipoSalon)
{
	int retorno = -1;
		if(this != NULL && tipoSalon != NULL )
		{
			if (esNumerica(tipoSalon, LEN_TIPOSALON))
			{
				this->Salon_tipo=atoi(tipoSalon);
				retorno = 0;
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


int salon_obtenerValorTipo(int tipoInt, char* tipoStr)
{
	int retorno = -1;
	if (tipoInt >= 1 && tipoInt <= 2 && tipoStr != NULL)
	{
		switch (tipoInt)
			{
			case SHOPPING:
				strncpy(tipoStr,"SHOPPING",LEN_TIPOSALON);
				break;
			case LOCAL:
				strncpy(tipoStr,"LOCAL",LEN_TIPOSALON);
				break;
			}
		retorno = 0;
	}
	return retorno;
}
