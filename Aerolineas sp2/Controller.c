
#include "GeneralCommands.h"
#include "Controller.h"
#include "Vuelos.h"

int controller_SantoliquidoloadFromText(char* path, LinkedList* ll)
{
int ret;
FILE* pFile;

pFile = fopen(path,"r");

ret=parser_VuelosFromText(pFile,ll);

fclose(pFile);

return ret;
}


int controller_SantoliquidoListVuelos(LinkedList* ll, LinkedList* pilotos_ll)
{

    int len = ll_len(ll);
    int i;
    int id;
    int avionId;
    int pilotoId;
    char nombrePiloto[128];
    char fecha[20];
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int ret=-1;
    Pilotos* piloto;



    Vuelos* vuelos;
    system("cls");
    if(ll!=NULL)
    {

    cabecera();


    if(ll_isEmpty(ll)!=-1)
    {
        for(i=0;i<len;i++)
        {
        piloto=pilotos_new();

        vuelos = ll_get(ll,i);
        vuelos_getId(vuelos,&id);
        vuelos_getAvionId(vuelos,&avionId);
        vuelos_getPilotoId(vuelos,&pilotoId);
        vuelos_getFecha(vuelos,fecha);
        vuelos_getDestino(vuelos,destino);
        vuelos_getCantPasajeros(vuelos,&cantPasajeros);
        vuelos_getHoraDespegue(vuelos,&horaDespegue);
        vuelos_getHoraLlegada(vuelos,&horaLlegada);

        piloto=ll_get(pilotos_ll,pilotoId-1);
        vuelos_getNombre(piloto,nombrePiloto);
        columna();
        columna();
        printf("%8.d   ", id);
        columna();
         printf("%8.d   ", avionId);
        columna();
         printf("%30s   ", nombrePiloto);
        columna();
        printf("%20s    ", fecha);
        columna();
        printf("%40s    ", destino);
        columna();
        printf("%26.d   ", cantPasajeros);
        columna();
        printf("%14.d   ", horaDespegue);
        columna();
        printf("%14.d  ", horaLlegada);
        columna();
        columna();
        printf("\n");

        }

    linea(197);
    printf("\n");

    }else
    {
        printf("LISTA VACIA\n");
         ret=0;
    }

    }

    if(i==len)
    {
        ret=0;
    }

return ret;
}

int controller_Santoliquidocount_irlanda(Vuelos* vuelos)
{

    char destino[128];
    int cantPasajeros;
    int ret=-1;

    if(vuelos!=NULL)
    {

        vuelos_getDestino(vuelos,destino);
        vuelos_getCantPasajeros(vuelos,&cantPasajeros);


        destino[0]=tolower(destino[0]);

        if(strcmp(destino,"irlanda")==0)
        {
            ret=cantPasajeros;
        }
    }

return ret;
}

int controller_Santoliquidocount(Vuelos* vuelos)
{


    int cantPasajeros;
    int ret=-1;

    if(vuelos!=NULL)
    {

        vuelos_getCantPasajeros(vuelos,&cantPasajeros);
            ret=cantPasajeros;

    }

return ret;
}


int controller_SantoliquidoShortFilter(Vuelos* vuelos)
{
    int i;


    int horaDespegue;
    int horaLlegada;
    int horastot;
    int ret=-1;



    if(vuelos!=NULL)
    {


        vuelos_getHoraDespegue(vuelos,&horaDespegue);
        vuelos_getHoraLlegada(vuelos,&horaLlegada);
        horastot=horaLlegada-horaDespegue;
        if(horastot<0)
        {
            horastot=horastot*-1;
        }

        if(horastot<=3)
        {
            ret=1;
        }

    }


return ret;
}


int controller_SantoliquidoPortugalFilter(Vuelos* vuelos)
{
    int i;


    char destino[128];
    int ret=-1;



    if(vuelos!=NULL)
    {



        vuelos_getDestino(vuelos,destino);
       destino[0]=tolower(destino[0]);
        if(strcmp(destino,"portugal")==0)
        {
            ret=1;
        }

    }


return ret;
}

int controller_SantoliquidoAlexFilter(Vuelos* vuelos)
{
    int i;


   int idPiloto;
    int ret=-1;



    if(vuelos!=NULL)
    {

        vuelos_getPilotoId(vuelos,&idPiloto);
        if(idPiloto!=1)
        {
            ret=1;
        }

    }


return ret;
}



int controller_SantoliquidosaveAsTextShort(char* path, LinkedList* ll)
{
int ret=-1;
int i;
int len =ll_len(ll);
    int id;
    int avionId;
    int pilotoId;
    char nombrePiloto[128];
    char fecha[20];
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    char cid[128];
    char cavionId[128];
    char cpilotoId[128];
    char ccantPasajeros[128];
    char choraDespegue[128];
    char choraLlegada[128];

    Vuelos* vuelos;
FILE* pFile;

pFile = fopen(path,"w");

 for(i=0; i<len; i++)
    {

        vuelos=vuelos_new();
        vuelos = ll_get(ll,i);

        vuelos_getId(vuelos,&id);
        vuelos_getAvionId(vuelos,&avionId);
        vuelos_getPilotoId(vuelos,&pilotoId);
        vuelos_getFecha(vuelos,fecha);
        vuelos_getDestino(vuelos,destino);
        vuelos_getCantPasajeros(vuelos,&cantPasajeros);
        vuelos_getHoraDespegue(vuelos,&horaDespegue);
        vuelos_getHoraLlegada(vuelos,&horaLlegada);

        itoa(id,cid,10);

        itoa(avionId,cavionId,10);
        itoa(pilotoId,cpilotoId,10);
        itoa(cantPasajeros,ccantPasajeros,10);

        itoa(horaDespegue,choraDespegue,10);
        itoa(horaLlegada,choraLlegada,10);
        if(i==0)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        }
        fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s,%s\n",cid,cavionId,cpilotoId,fecha,destino,ccantPasajeros,choraDespegue,choraLlegada);

        //printf("\nEL ID ES %s",cId);
        ret=0;


    }

fclose(pFile);

return ret;
}



int controller_SantoliquidosaveAsTextPilotos(char* path, LinkedList* ll)
{
int ret=-1;
int i;
int len =ll_len(ll);

    int id;
    char nombrePiloto[128];

    char cid[128];

    Pilotos* pilotos;
FILE* pFile;

pFile = fopen(path,"w");

 for(i=0; i<len; i++)
    {

        pilotos=pilotos_new();
        pilotos = ll_get(ll,i);

        pilotos_getId(pilotos,&id);
        vuelos_getNombre(pilotos,nombrePiloto);

        itoa(id,cid,10);

        if(i==0)
        {
            fprintf(pFile,"id,nombre\n");
        }
        fprintf(pFile,"%s,%s\n",cid,nombrePiloto);


        ret=0;


    }

fclose(pFile);

return ret;
}


int controller_SantoliquidoloadFromTextPilotos(char* path, LinkedList* ll)
{
int ret;
FILE* pFile;

pFile = fopen(path,"r");

ret=parser_PilotosFromText(pFile,ll);

fclose(pFile);

return ret;
}


int controller_SantoliquidoListPilotos(LinkedList* ll)
{

    int len = ll_len(ll);
    int i;
    int id;
    char nombrePiloto[128];
    int ret=-1;
    Pilotos* pilotos;



    system("cls");
    if(ll!=NULL)
    {

    cabeceraPiloto();


    if(ll_isEmpty(ll)!=-1)
    {
        for(i=0;i<len;i++)
        {
        pilotos=pilotos_new();

        pilotos=ll_get(ll,i);
        pilotos_getId(pilotos,&id);
        vuelos_getNombre(pilotos,nombrePiloto);
        columna();
        columna();
        printf("%8.d   ", id);
        columna();
         printf("%30s   ", nombrePiloto);
        columna();
        columna();
        printf("\n");

        }

    linea(50);
    printf("\n");

    }else
    {
        printf("LISTA VACIA\n");
         ret=0;
    }

    }

    if(i==len)
    {
        ret=0;
    }

return ret;
}


int controller_SantoliquidoFilterByPiloto(Pilotos* pilotos, char* nombrePiloto)
{
    int i;


    int idPiloto;
    char nombreCompare[128];
    int ret=-1;



    if(pilotos!=NULL)
    {

        pilotos_getId(pilotos,&idPiloto);

        vuelos_getNombre(pilotos,nombreCompare);


        if(strcmp(nombreCompare,nombrePiloto)!=0)
        {
            ret=1;
        }

    }


return ret;
}











