#include "LinkedList.h"
#include "Vuelos.h"
#include "parser.h"

int controller_SantoliquidoShortFilter(Vuelos* vuelos);
int controller_SantoliquidoPortugalFilter(Vuelos* vuelos);
int controller_Santoliquidocount_irlanda(Vuelos* vuelos);
int controller_Santoliquidocount(Vuelos* vuelos);
int controller_SantoliquidoAlexFilter(Vuelos* vuelos);
int controller_SantoliquidosaveAsTextPilotos(char* path, LinkedList* ll);
int controller_SantoliquidoloadFromTextPilotos(char* path, LinkedList* ll);
int controller_SantoliquidoFilterByPiloto(Pilotos* pilotos, char* nombrePiloto);
int controller_SantoliquidoListPilotos(LinkedList* ll);

int controller_SantoliquidoloadFromText(char* path , LinkedList* ll);
/**
*-Create the file and execute the parser loader text file
*
*-Char* - path of file
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/
int controller_SantoliquidoListVuelos(LinkedList* ll,LinkedList* pilotos_ll);
/**
*-List all flights saved in the linked list
*
*-LinkedList* - Linkedlist to search flights
*-return 0 if OK or -1 if an error encounter
*/

int controller_SantoliquidosaveAsTextShort(char* path , LinkedList* ll);
/**
*-Save the linked list on text file
*char* path of file
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/

void cabecera();
/**
*-Print on screen the columns
*/
