/*
 * Passenger_Flight.h
 *
 *  Created on: 11 may. 2022
 *      Author: Ruben Dario Zevallos Lambrescht 1H
 */

#ifndef PASSENGER_FLIGHT_H_
#define PASSENGER_FLIGHT_H_

#include "ArrayPassenger.h"
#include "eFlight.h"
int getDataPassenger_FlightCode(Passenger* pArray, int pLimite, eFlight* fArray, int fLimite);
int pasfl_printSumAverage(Passenger* pArray, int pLimite, eFlight* fArray, int fLimite);
int pasfl_printPassengerActivSorted(Passenger *pArray, int pLimite, eFlight *fArray,int fLimite);
int modififyPassengerValues(Passenger *pArray, int pLimite, eFlight *fArray,int fLimite);

#endif /* PASSENGER_FLIGHT_H_ */
