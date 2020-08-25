#ifndef Vuelos_H_INCLUDED
#define Vuelos_H_INCLUDED
#include "LinkedList.h"
#define cantPilotos 5

typedef struct
{
    int id;
    int avionId;
    int pilotoId;
    char fecha[20];
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

}Vuelos;

typedef struct
{
    int id;
    int nombre[128];

}Pilotos;

int CargarPilotos(LinkedList* pilotos_ll);
Pilotos* pilotos_newParametros(int id,char* nombre);
Pilotos* pilotos_new();
void cabeceraPiloto();
/**
*-Reserve space of memory
*-Return the dir of the reserved space
*/

Vuelos* vuelos_new();
/**
*-Reserve space of memory
*-Return the dir of the reserved space
*/
Vuelos* vuelos_newParametros(int id,int avionId,int pilotoId,char* fecha,char* destino,int cantPasajeros,int horaDespegue,int horaLlegada);
/**
*-Reserve space of memory
*-int - Id
*-char* - pointer of name
*-int - HorasTrabajadas
*-int - Sueldo
*-Return the dir of the reserved space
*/

int vuelos_getNombre(Pilotos* pilotos,char* );
/**
*-Get Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getId(Vuelos* vuelos,int* );
/**
*-Get Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getAvionId(Vuelos* vuelos,int* );
/**
*-Get Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getPilotoId(Vuelos* vuelos,int* );
/**
*-Get Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getFecha(Vuelos* vuelos,char* );
/**
*-Get Date of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getDestino(Vuelos* vuelos,char* );
/**
*-Get Date of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getCantPasajeros(Vuelos* vuelos,int* );
/**
*-Get Horas of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the horas trabajadas variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getHoraDespegue(Vuelos* vuelos,int* );
/**
*-Get Sueldo of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the sueldo variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_getHoraLlegada(Vuelos* vuelos,int* );
/**
*-Get Date of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setNombre(Pilotos* pilotos,char* );
/**
*-set Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setId(Vuelos* vuelos,int );
/**
*-set Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setAvionId(Vuelos* vuelos,int );
/**
*-set Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setPilotoId(Vuelos* vuelos,int );
/**
*-set Id of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setFecha(Vuelos* vuelos,char* );
/**
*-set Date of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setDestino(Vuelos* vuelos,char* );
/**
*-set Date of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setCantPasajeros(Vuelos* vuelos,int );
/**
*-set Horas of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the horas trabajadas variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setHoraDespegue(Vuelos* vuelos,int );
/**
*-set Sueldo of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-int* - Pointer to the sueldo variable
*-Return 0 if OK or -1 if an error encounter
*/
int vuelos_setHoraLlegada(Vuelos* vuelos,int );
/**
*-set Date of 1 pointer to vuelos
*-Vuelos* - Pointer to vuelos
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/



#endif // employee_H_INCLUDED
