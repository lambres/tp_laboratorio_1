/*
 * ArrayPassenger.h
 *
 *
 *      Author: Ruben Dario Zevallos Lambrescht 1º H
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LIBRE 1
#define OCUPADO 0
#define TURISTA 0
#define EJECUTIVA 1
#define PRIMERA 2
#define LEN_CARACTERES 51
#define LEN_FLIGHTCODE 10

typedef struct {
	int id;
	char name[LEN_CARACTERES];
	char lastname[LEN_CARACTERES];
	float price;
	char flycode[LEN_FLIGHTCODE];
	int typePassenger;
	int isEmpty;
} Passenger;

int initPassengers(Passenger *list, int len);
int addPassenger(Passenger *list, int len, int id, char name[], char lasName[],
float price, int typePassenger, char flycode[]);
int findPassengerById(Passenger *list, int len, int id);
int removePassenger(Passenger *list, int len, int id);
int sortPassengers(Passenger *list, int len, int order);
int printPassenger(Passenger *list, int length);
int sortPassengersByCode(Passenger *list, int len, int order);
int Passenger_ObtenerIndexLibre(Passenger array[], int TAM);
int Passenger_ObtenerIndexOcupado(Passenger array[], int TAM);
void printOnePassenger(Passenger *array);
//int modififyPassengerValues(Passenger *array, int limite);

#endif /* ARRAYPASSENGER_H_ */
