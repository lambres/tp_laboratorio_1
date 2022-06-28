#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

#ifndef MENUINFORMES_H_
#define MENUINFORMES_H_

void adminInformes(LinkedList* listaSalon,LinkedList* listaArcade,LinkedList* listaJuego);
int ReporteA(LinkedList* listaSalon, LinkedList* listaArcade);
int ReporteB(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego);
int ReporteC(LinkedList* listaSalon);
int ReporteD(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego);
int ReporteE(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego);
int ReporteF(LinkedList* listaSalon, LinkedList* listaArcade);
int ReporteG( LinkedList* listaArcade, LinkedList* listaJuego);

#endif /* MENUINFORMES_H_ */
