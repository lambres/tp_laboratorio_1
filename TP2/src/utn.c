/*
 * Biblioteca funciones
 *
 *
 *
 *  Created on: 8 mar. 2022
 *      Author: Ruben Dario Zevallos Lambrescht 1H
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef __linux__
#define SO "Linux"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER __fpurge(stdin);
#include <stdio_ext.h>
#elif _WIN32
#define SO "Windows"
#define LIMPIAR_CONSOLA system("cls");
#define LIMPIAR_BUFFER fflush(stdin);
#define LIMPIAR_SALIDA	setbuf(stdout,NULL);
#elif __APPLE__
#define SO "OSX"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER fpurge(stdin);
#endif

static int esNumerica(char *cadena, int limite);
static int esNumeroDecimal(char *cadena, int limite);
static int getInt(int *pResultado);
static int myGets(char *cadena, int longitud);
static int getFloat(float *pResultado);
static int getNombre(char *pResultado, int longitud);
static int esNombre(char *cadena, int longitud);
static int getTexto(char *pResultado, int longitud);
static int esTexto(char *cadena, int longitud);

/// @fn int esNumerica(char*, int)
/// @brief Verifico si cadena contiene un valor numerico incluyendo +-
///
/// @param cadena array pasado para analizar
/// @param limite tamaño del array
/// @return Devuelve 0 si lo encontró y -1 si no es un número valido
static int esNumerica(char *cadena, int limite) {
	int retorno = -1; //ERROR
	int i;
	if (cadena != NULL && limite > 0) {
		retorno = 1; //VERDADERO
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
				continue;
			}
			if (cadena[i] > '9' || cadena[i] < '0') {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/// @fn int esNumeroDecimal(char*, int)
/// @brief Verifico si cadena contiene un valor numerico decimal incluyendo + - .
///
/// @param cadena array a ser analizado
/// @param limite tamaño del array
/// @return -1 si es incorrecto el valor ingresado y 0 si el numero es decimal
static int esNumeroDecimal(char *cadena, int limite) {
	int retorno = -1; //ERROR
	int i;
	int puntoEncontrado = 0; //bandera para dejar ingresar solo un punto
	if (cadena != NULL && limite > 0) {
		retorno = 1; //VERDADERO
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (puntoEncontrado == 0 && cadena[i] == '.') {
				puntoEncontrado = 1;
				continue;
			}
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] > '9' || cadena[i] < '0') {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @fn int getInt(int*)
/// @brief  Llama a la funcion myGets para gestinar el ingreso y es numerica para analizar si es un numero lo ingresado
///
/// @param pResultado array a analizar
/// @return -1 si no obtubo un entero (Error) y 0 si OK
static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL && !myGets(buffer, sizeof(buffer))
			&& esNumerica(buffer, sizeof(buffer))) {
		*pResultado = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

/// @fn int myGets(char*, int)
/// @brief funcion que toma datos de teclado y deja solo los valores a analizar, quitando
/// los valore \n y \0 para luego pasar a otras funciones el valor a analizar
/// @param cadena Cadena tomada del teclado
/// @param longitud Tamaño de la cadena
/// @return 0 si puedo obtener la cadena (Exito) y -1 si lo que se obtubo es otro dato (Error)
static int myGets(char *cadena, int longitud)
//int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096]; //arreglar en clases posteriores

	if (cadena != NULL && longitud > 0) {
#ifdef __linux__
			LIMPIAR_BUFFER
		#elif _WIN32
			LIMPIAR_BUFFER
		#elif __APPLE__
		LIMPIAR_BUFFER
#endif
		//fpurge(stdin);
		//__fpurge(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// @fn int getFloat(float*)
/// @brief Determina si array pasado como parametro es tipo flotante
///
/// @param pResultado Array devuelto con el valor pasado en caso de ser flotante
/// @return Devuelve 0 si EXITo y -1 si ERROR y devuelve el valor numerico convertido a flotante
static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNumeroDecimal(buffer, sizeof(buffer))) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
/// @brief Funcion que toma el array pResultado y llama a funciones para evaluar si es un numero
/// entero devolviendolo por referencia
/// @param pResultado array a analizar
/// @param mensaje Mensaje que solicita el dato al usuario
/// @param mensajeError Mensaje de error a mostrar en caso de valor ingresado erroneo
/// @param minimo valor minimo del rango a ingresar
/// @param maximo valor maximo del rango a ingresar
/// @param reintentos cantidad de veces que vuelve a solicitar el valor
/// @return devuleve 0 EXITO si pudo convertir pResultado a entero, -1 si dio ERROR
int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInt;
	do {
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && pResultado != NULL && mensaje != NULL
				&& mensajeError != NULL && reintentos >= 0
				&& bufferInt >= minimo && bufferInt <= maximo) {
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	} while (reintentos >= 0);
	return retorno;
}

/// @fn int utn_getNumeroFloat(float*, char*, char*, float, float, int)
/// @brief Funcion que toma el array pResultado y llama a funciones para evaluar si es un numero
/// flotante devolviendolo por referencia
/// @param pResultado array a analizar
/// @param mensaje Mensaje que solicita el dato al usuario
/// @param mensajeError Mensaje de error a mostrar en caso de valor ingresado erroneo
/// @param minimo valor minimo del rango a ingresar
/// @param maximo valor maximo del rango a ingresar
/// @param reintentos cantidad de veces que vuelve a solicitar el valor
/// @return devuleve 0 EXITO si pudo convertir pResultado a un float, -1 si dio ERROR
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		while (reintentos > 0) {
			reintentos--;
			printf("%s", mensaje);
			if (getFloat(&bufferFloat) == 0) {
				if (bufferFloat >= minimo && bufferFloat <= maximo) {
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}
	}
	return retorno;
}

/// @fn int utn_getNumeroAleatorio(int, int, int)
/// @brief Funcion que nos devuelve un numero aleatorio
///
/// @param desde Rango inferior desde donde deseamos el valor aleatorio
/// @param hasta Rango Superiro hasta donde deseamos el valor aleatorio
/// @param iniciar !=0 para dar orden de que calcule el valor
/// @return devuelve un numero aleatorio segun parametros ingresado
int utn_getNumeroAleatorio(int desde, int hasta, int iniciar) {
	if (iniciar)
		srand(time(NULL));
	return desde + (rand() % (hasta + 1 - desde));
}

/// @fn int utn_getCaracter(char*, char*, char*, char, char, int)
/// @brief  Funcion que toma un caracter y evalua si esta dentro de los valores deseados pasados como parametro
///
/// @param pResultado caracter a analizar
/// @param mensaje Mensaje a preguntar por el ingreso
/// @param mensajeError Mensjae a mostrar cuando el valor no este dentro de los valores deseados
/// @param minimo char minimo (ASCII)
/// @param maximo char maximo (ASCII)
/// @param reintentos cantidad de veces que puede volver a ingresa en caso de error
/// @return Devuleve -1 (ERROR) si el valor noe stá dentro de l parametro solicitado y 0 si tuvo EXITO
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
#ifdef __linux__
			LIMPIAR_BUFFER
#elif _WIN32
			LIMPIAR_BUFFER
#elif __APPLE__
			LIMPIAR_BUFFER
#endif
			scanf("%c", &bufferChar);
			if (bufferChar >= minimo && bufferChar <= maximo) {
				*pResultado = bufferChar;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

/// @fn int dividir(float*, int, int)
/// @brief funcion que divide don numeros teniendo en cuenta que sea posible hacer la division
///
/// @param pResultado puntero al valor a ser devuelto con el resultado de la operacion
/// @param operador1 numerador de la divison
/// @param operador2 divisor de la division
/// @return retorna el valor resultado de l aoperacion en el puntero PResultado y 0 (EXITO) si se pudo realizar la operacion y -1 ERROR
int dividir(float *pResultado, int operador1, int operador2) {
	float resultado;
	int retorno = -1;
	if (pResultado != NULL && operador2 != 0) {
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

/// @fn int factorial(int)
/// @brief Calcula el factorial del numero ingresado
///
/// @param n numero del cual se desea calcular el factorial
/// @return retorna el factorial del numero n
int factorial(int n) {
	int resp;
	if (n == 1)
		return 1;
	resp = n * factorial(n - 1);
	return (resp);
}

/// @fn int esSoloLetras_Espacio(char[])
/// @brief Funcion que evalua el array recibido si tiene letras mayusculas minusculas y espacios solamente
///
/// @param str cadena a evaluar
/// @return Devuelve -1 si hay caracteres que no cumplen con la condicion y 0 EXITO
int esSoloLetras_Espacio(char str[]) {
	int retorno = -1;
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z')
				&& (str[i] < 'Z' || str[i] > 'Z'))
			retorno = 0;
		i++;
	}
	return retorno;
}

/// @fn char getChar(char[])
/// @brief Funcion que devulve el char ingresado, mostrando un mensaje solicitandolo
///
/// @param mensaje Mensjae a mostrar al usuario
/// @return retorna el caracter (char) ingresado
char getChar(char mensaje[]) {
	char auxiliar;
	printf("%s", mensaje);
#ifdef __linux__
	LIMPIAR_BUFFER
#elif _WIN32
	LIMPIAR_BUFFER
#elif __APPLE__
	LIMPIAR_BUFFER
#endif
	scanf("%c", &auxiliar);
	return auxiliar;
}

/**
 * \brief obtiene un string y corrobora que no se desborde buffer
 * \param string puntero donde se guardara el strign
 * \param longitud longitud que no quereos desbordar observar en los getFloat, int, nombre etc
 * \return 0 SUCCESS -1 ERROR
 */
int getString(char *string, int longitud) {
	int retorno = -1;
	char bufferString[4096];

	if (string != NULL && longitud > 0) {
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (bufferString[0] == '\0') {
				return -1;
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
#ifdef __linux__
					LIMPIAR_BUFFER
				#elif _WIN32
					LIMPIAR_BUFFER
				#elif __APPLE__
				LIMPIAR_BUFFER
#endif
				strncpy(string, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// @fn unsigned int verifica(void)
/// @brief Función que pregunta al usuario por S/N
///
/// @return Retorna S o N según opcion ingresada
unsigned int verifica(void) {
	char letra;
	printf("\nIngrese opcion...S/N?");
#ifdef __linux__
	LIMPIAR_BUFFER
#elif _WIN32
	LIMPIAR_BUFFER
#elif __APPLE__
	LIMPIAR_BUFFER
#endif
	letra = toupper(getchar());
	while (!((letra == 'S') || (letra == 'N'))) {
		printf(
				"\nHa ingresado opcion no valida...Reintente el ingreso(S/N)... ");
#ifdef __linux__
		LIMPIAR_BUFFER
#elif _WIN32
		LIMPIAR_BUFFER
#elif __APPLE__
		LIMPIAR_BUFFER
#endif
		letra = toupper(getchar());
	}
	return (letra);		//=='S');
}

/// @brief Solicita un texto al usuario, luego de verificarlo devuelve el resultado
///			Permitiendo ingresar letras de la A al aZ, a a la z y espacios solamente
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Es la longitud del array resultado
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de error a ser mostgrado
/// @param reintentos Cantidad de reintentos
/// @return Retorna 0 si se obtuvo el nombre y -1 si no

int utn_getNombre(char *pResultado, int longitud, char *mensaje,
		char *mensajeError, int reintentos) {
	char bufferString[4096];
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getNombre(bufferString, sizeof(bufferString)) == 0
				&& strnlen(bufferString, sizeof(bufferString)) < longitud) {
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/// @brief Obtiene un string valido como nombre
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
static int getNombre(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < longitud) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}
/// @brief Verifica si la cadena ingresada es un nombre valido
///
/// @param cadena Cadena de caraacteres a ser analizada
/// @param longitud Tamaño del array
/// @return Retorna 0 si se obtiene un nombre y -1 si hay un error

static int esNombre(char *cadena, int longitud) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& cadena[i] != 32) {
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

/// @brief Solicita un texto al usuario, luego de verificarlo devuelve el resultado
///			Permitiendo ingresar los ascii del 32 al 126 (Caracteres imprimibles no extendidos)
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Es la longitud del array resultado
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de error a ser mostgrado
/// @param reintentos Cantidad de reintentos
/// @return Retorna 0 si se obtuvo el nombre y -1 si no

int utn_getTexto(char *pResultado, int longitud, char *mensaje,
		char *mensajeError, int reintentos) {
	char bufferString[4096];
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getTexto(bufferString, sizeof(bufferString)) == 0
				&& strnlen(bufferString, sizeof(bufferString)) <= longitud) {
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/// @brief Obtiene un string valido como nombre descripcion
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
static int getTexto(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& esTexto(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < longitud) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}
/// @brief Verifica si la cadena ingresada es una Descripcion valida
///
/// @param cadena Cadena de caraacteres a ser analizada
/// @param longitud Tamaño del array
/// @return Retorna 0 si se obtiene un nombre y -1 si hay un error
static int esTexto(char *cadena, int longitud) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if (cadena[i] < 32 || cadena[i] > 126) {
				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}
