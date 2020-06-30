#include "GeneralCommands.h"
#include "Vuelos.h"
#include "LinkedList.h"


int parser_VuelosFromText(FILE* pFile, LinkedList* ll)
{

    char id[128];
    char avionId[128];
    char pilotoId[128];
    char fecha[128];
    char destino[128];
    char cantPasajeros[128];
    char horaDespegue[128];
    char horaLlegada[128];

    int ret=-1;



    Vuelos* vuelos;





        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n] \n", id, avionId, pilotoId, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);


   while(!feof(pFile))
   {



       fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n] \n", id, avionId, pilotoId, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);



        vuelos = vuelos_newParametros(atoi(id), atoi(avionId), atoi(pilotoId), fecha, destino, atoi(cantPasajeros), atoi(horaDespegue), atoi(horaLlegada));




        ret=ll_add(ll,vuelos);




   }







    return ret;

}


int parser_PilotosFromText(FILE* pFile, LinkedList* ll)
{

    char id[128];
    char nombre[128];

    int ret=-1;



    Pilotos* pilotos;





        fscanf(pFile, "%[^,],%[^\n] \n", id, nombre);


   while(!feof(pFile))
   {



       fscanf(pFile, "%[^,],%[^\n] \n", id, nombre);



        pilotos = pilotos_newParametros(atoi(id), nombre);




        ret=ll_add(ll,pilotos);




   }







    return ret;

}
