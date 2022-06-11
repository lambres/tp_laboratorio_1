/*
 * funciones.c
 *
 *  Created on: 3 abr. 2022
 *      Author: dario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

static float calculoDiferencia(float valor1, float valor2);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);
static int getInt(int * pResultado);
static int getFloat(float* pResultado);


int menuOp4(int distancia,float precio1, float precio2, float debito1, float credito1, float btc1, float unitario1, float debito2, float credito2, float btc2, float unitario2)
{
	int retorno;
	retorno = -1;
	if(distancia!=0 && precio1 !=0 && precio2 != 0)
	{
		printf("KMs Ingresados: %d km\n\n", distancia);
		printf("Precio Aerolineas: $ %.2f\n", precio1);
		printf("a) Precio con tarjeta de debito: $ %.2f\n", debito1);
		printf("b) Precio con tarjeta de credito: $ %.2f\n", credito1);
		printf("c) Precio pagando con bitcoin: %.5f BTC\n", btc1);
		printf("d) Mostrar precio unitario: %.2f\n\n", unitario1);
		printf("Precio Latam: $ %.2f\n", precio2);
		printf("a) Precio con tarjeta de debito: $ %.2f\n", debito2);
		printf("b) Precio con tarjeta de credito: $ %.2f\n", credito2);
		printf("c) Precio pagando con bitcoin: %.5f BTC\n", btc2);
		printf("d) Mostrar precio unitario: %.2f\n\n", unitario2);
		printf("La diferencia de precio es: %.2f\n\n", calculoDiferencia(precio1, precio2));
		printf("Presiones una tecla para continuar");
		getchar();
		retorno=0;
	}
	else
	{
		printf("No se pueden mostrar los valores hasta que no ingrese una distancia\n");
	}
	return retorno;
}

/**
 * @fn int calculoPrecio(float, int, float*, float)
 * @brief Funcion que realiza los cálculos para los viajes
 *
 * @pre
 * @post
 * @param costo Es el precio del vuelo a calcular los descuentos
 * @param formaPago Se recibe 0 pago con Débito, 1 con crédito y 2 con BTC
 * @param precio puntero que recibe el precio con los descuentos o recargos segun la forma de pago
 * @param cotizacionBtc Valor del BTC para poder realizar el cálculo
 * @return Devuleve 0 si pudo realizar el cálculo y -1 en caso de error
 */
int calculoPrecio(float costo,int formaPago, float * precio, float cotizacionBtc)
{
	int retorno;
	retorno = -1;
	float buffer;
	switch (formaPago)
	{
		case 0:
			buffer = costo - costo * 10 / 100 ;
			retorno = 0;
			break;
		case 1:
			buffer = costo + costo * 25 / 100 ;
			retorno = 0;
			break;
		case 2:
			buffer = costo/cotizacionBtc ;

			retorno = 0;
			break;
	}
	*precio = buffer;
	return retorno;
}

/**
 * @fn float calculoDiferencia(float, float)
 * @brief Funcion que devuleve la diferencia entre dos números, tomando el de mayor valor como munuendo
 * y el de menor valor al sustraendo
 * @pre
 * @post
 * @param valor1 uno de los valores a restar
 * @param valor2 otro de los valores a restar
 * @return devuleve la resta de los numeros, dando valor positivo
 */
static float calculoDiferencia(float valor1, float valor2)
{
	float buffer;
	if (valor1 > valor2)
	{
		buffer = valor1-valor2;
	}
	else
	{
		buffer = valor2-valor1;
	}
	return buffer;
}

/**
 * @fn int esNumerica(char*)
 * @brief ​Verifica​ ​si​ ​la​ ​cadena​ ​ingresada​ ​es​ ​numerica
 *
 * @pre
 * @post
 * @param cadena Cadena​ ​de​ ​caracteres​ a ​ser​ ​analizada
 * @return Retorna​ 1 (​vardadero​) ​si​ ​la​ ​cadena​ ​es​ ​numerica​ y 0 (​falso​) ​si​ no ​lo​ ​es
 */
static int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if (cadena[i] == '.')
			{
				i++;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	} return retorno;
}

/**
 * @fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
 * @brief Solicita​ ​un​ ​numero​ entero ​al​ ​usuario​, ​leuego​ ​de​ ​verificarlo​ ​devuelve​ el ​resultado
 *
 * @pre
 * @post
 * @param pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
 * @param mensaje ​Es​ el ​mensaje​ a ​ser​ ​mostrado
 * @param mensajeError Es​ el ​mensaje​ ​de​ Error a ​ser​ ​mostrado
 * @param minimo Es​ el ​minimo​ ​minimo​ a ​ser​ ​aceptado
 * @param maximo Es​ el ​numero​ ​maximo​ a ​ser​ ​aceptado
 * @param reintentos Cantidad de veces que puede reintentar
 * @return ​Retorna​ 0 ​si​ ​se​ ​obtuvo​ el ​numero​ y -1 ​si​ no
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			fpurge(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/**
* \brief ​Solicita​ ​un​ ​numero​ flotante ​al​ ​usuario​, ​leuego​ ​de​ ​verificarlo​ ​devuelve​ el ​resultado
* \​param​ pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
* \​param​ ​mensaje​ ​Es​ el ​mensaje​ a ​ser​ ​mostrado
* \​param​ mensajeError ​Es​ el ​mensaje​ ​de​ Error a ​ser​ ​mostrado
* \​param​ ​minimo​ ​Es​ el ​numero​ ​maximo​ a ​ser​ ​aceptado
* \​param​ ​maximo​ ​Es​ el ​minimo​ ​minimo​ a ​ser​ ​aceptado
* \return ​Retorna​ 0 ​si​ ​se​ ​obtuvo​ el ​numero​ y -1 ​si​ no
**/
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/**
* \	brief	Lee ​ de​ ​ stdin​ ​ hasta​ ​ que​ ​ encuentra​ ​ un​ '\n' o ​ hasta​ ​ que​ ​ haya​ ​ copiado​ ​ en​ ​ cadena
* \			un​ máximo​ ​ de​ '​ longitud​ - 1' ​ caracteres​ .
* \​ param​	pResultado ​ Puntero​ ​ al​ ​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ copiara​ ​ la​ ​ cadena​ ​ obtenida
* \​ param​	longitud​ Define el ​ tamaño​ ​ de​ ​ cadena
* \ return	Retorna​ 0 (EXITO) ​ si​ ​ se​ ​ obtiene​ ​ una​ ​ cadena​ y -1 (ERROR) ​ si​ no
*/
static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fpurge(stdin); // LINUX-> ____fpurge o WIN-> fflush o MAC-> __fpurge
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
			return 0;
	}
	return -1;
}

/**
* \brief	Verifica si la cadena ingresada es numerica
* \​param​ 	pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return ​	Retorna​ 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
static int getInt(int * pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief ​Verifica​ ​si​ ​la​ ​cadena​ ​ingresada​ ​es​ ​numerica flotante
* \​param​ pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
* \return ​Retorna​ 0 (EXITO) ​si​ ​se​ ​obtiene​ ​un​ ​numero​ ​flotante y -1 (ERROR) ​si​ no
**/

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

