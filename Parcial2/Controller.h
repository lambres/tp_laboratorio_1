#include "LinkedList.h"
int controller_loadSalonFromText(char* path , LinkedList* pArrayList);
int controller_loadArcadeFromText(char* path , LinkedList* pArrayList);
int controller_loadJuegoFromText(char* path , LinkedList* pArrayList);
int controller_loadFiles(LinkedList* listaSalon, LinkedList* listaArcade , LinkedList* listaJuego);
int controller_saveSalonAsText(char* path , LinkedList* pArrayList);
int controller_saveArcadeAsText(char* path , LinkedList* pArrayList);
int controller_saveJuegoAsText(char* path , LinkedList* pArrayList);
int controller_saveFiles(LinkedList* listaSalon, LinkedList* listaArcade , LinkedList* listaJuego);


int controller_mostrarArcadeSalon(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego);
int controller_mostrarArcadeJuego(LinkedList* listaArcade, LinkedList* listaJuego);
int controller_mostrarArcadeParaEliminar(LinkedList* listaSalon, LinkedList* listaArcade, LinkedList* listaJuego);

int controller_addSalon(LinkedList* pSalon, int idNuevo);
int controller_removeSalon(LinkedList* pListaSalon, LinkedList* pListaArcade);
int controller_ListSalones(LinkedList* pListaSalon);

int controller_addArcade(LinkedList* pSalon, LinkedList* pArcade, LinkedList* pJuego, int idNuevo);
int controller_ListArcades(LinkedList* pListaArcade);
int controller_editArcade(LinkedList* listaArcade, LinkedList* listaJuegos);
int controller_removeArcade(LinkedList* pListaSalon, LinkedList* pListaArcade, LinkedList* pListaJuegos);

int controller_ListJuegos(LinkedList* pListaJuegos);
int controller_addJuego(LinkedList* pJuego, int idNuevo);

/*
int controller_editSalon(LinkedList* pArrayList);
int controller_sortSalon(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);

*/
