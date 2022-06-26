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
} Salon;

int initPassengers(Salon *list, int len);
int addPassenger(Salon *list, int len, int id, char name[], char lasName[],
float price, int typePassenger, char flycode[]);
int findPassengerById(Salon *list, int len, int id);
int removePassenger(Salon *list, int len, int id);
int sortPassengers(Salon *list, int len, int order);
int printPassenger(Salon *list, int length);
int sortPassengersByCode(Salon *list, int len, int order);
int Passenger_ObtenerIndexLibre(Salon array[], int TAM);
int Passenger_ObtenerIndexOcupado(Salon array[], int TAM);
void printOnePassenger(Salon *array);
//int modififyPassengerValues(Passenger *array, int limite);

#endif /* ARRAYPASSENGER_H_ */
