
#include "Vuelos.h"
#include "GeneralCommands.h"

int CargarPilotos(LinkedList* pilotos_ll)
{
    int i;
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={{"Alex Lifeson"},{"Richard Bach"},{"John Kerry"},{"Erwin Rommel"},{"Stephen Coonts"}};
    Pilotos* pilotos;

    for(i=0;i<cantPilotos;i++)
    {
        pilotos=pilotos_new();

        pilotos->id=id[i];
        vuelos_setNombre(pilotos,nombre[i]);
        ll_add(pilotos_ll,pilotos);
    }

}


void cabecera()
{
    printf("\n");
    linea(197);
    printf("\n");
            columna();
            columna();
           printf("  Id Vuelo ");
           columna();
           printf("  Id Avion ");
           columna();
           printf("                  Nombre Piloto  ");
           columna();
           printf("           Fecha        ");
           columna();
           printf("                                 Destino    ");
           columna();
           printf("        Cantidad Pasajeros   ");
           columna();
           printf("  Hora Despegue  ");
           columna();
           printf("  Hora Llegada  ");
           columna();
           columna();

    printf("\n");
    linea(197);
    printf("\n");
}

void cabeceraPiloto()
{
    printf("\n");
    linea(50);
    printf("\n");
            columna();
            columna();
           printf("  Id Piloto ");
           columna();
           printf("                  Nombre Piloto ");
           columna();
           columna();

    printf("\n");
    linea(50);
    printf("\n");
}

Pilotos* pilotos_new()
{
    Pilotos* pilotos;

    pilotos =(Pilotos*) malloc(sizeof(Pilotos));

return pilotos;

}

Vuelos* vuelos_new()
{
    Vuelos* vuelos;
vuelos =(Vuelos*) malloc(sizeof(Vuelos));

return vuelos;

}
Vuelos* vuelos_newParametros(int id,int avionId,int pilotoId,char* fecha,char* destino,int cantPasajeros,int horaDespegue,int horaLlegada)
{
    Vuelos* vuelos;
    vuelos=vuelos_new();

    vuelos_setId(vuelos,id);
    vuelos_setAvionId(vuelos,avionId);
    vuelos_setPilotoId(vuelos,pilotoId);
    vuelos_setFecha(vuelos,fecha);
    vuelos_setDestino(vuelos,destino);
    vuelos_setCantPasajeros(vuelos,cantPasajeros);
    vuelos_setHoraDespegue(vuelos,horaDespegue);
    vuelos_setHoraLlegada(vuelos,horaLlegada);

    return vuelos;

}

Pilotos* pilotos_newParametros(int id,char* nombre)
{
    Pilotos* pilotos;
    pilotos=pilotos_new();

    pilotos_setId(pilotos,id);
    vuelos_setNombre(pilotos,nombre);

    return pilotos;

}



int pilotos_setId(Pilotos* pilotos,int id)
{
      int ret = -1;
    if(pilotos!=NULL )
    {
        pilotos->id = id;

        ret = 0;
    }

    return ret;

}
int pilotos_getId(Pilotos* pilotos,int* id)
{
    int ret = -1;
    if(pilotos!=NULL )
    {
        *id=pilotos->id;

        ret=*id;

    }

    return ret;

}


int vuelos_setId(Vuelos* vuelos,int id)
{
      int ret = -1;
    if(vuelos!=NULL )
    {
        vuelos->id = id;

        ret = 0;
    }

    return ret;

}
int vuelos_getId(Vuelos* vuelos,int* id)
{
    int ret = -1;
    if(vuelos!=NULL )
    {
        *id=vuelos->id;

        ret=*id;

    }

    return ret;

}

int vuelos_setAvionId(Vuelos* vuelos,int avionId)
{
    int ret = -1;
    if(vuelos!=NULL )
    {
        vuelos->avionId = avionId;
        ret = 0;
    }

    return ret;
}
int vuelos_getAvionId(Vuelos* vuelos,int* avionId)
{
  int ret = -1;
    if(vuelos!=NULL )
    {
        *avionId=vuelos->avionId;
        ret=*avionId;

    }

    return ret;

}


int vuelos_setPilotoId(Vuelos* vuelos,int pilotoId)
{
    int ret = -1;
    if(vuelos!=NULL )
    {
        vuelos->pilotoId = pilotoId;
        ret = 0;
    }

    return ret;
}
int vuelos_getPilotoId(Vuelos* vuelos,int* pilotoId)
{
  int ret = -1;
    if(vuelos!=NULL )
    {
        *pilotoId=vuelos->pilotoId;
        ret=*pilotoId;

    }

    return ret;

}

int vuelos_setNombre(Pilotos* pilotos,char* nombre)
{
    int ret = -1;
    if(pilotos!=NULL && nombre!=NULL)
    {
        strcpy(pilotos->nombre,nombre);
        ret = 0;
    }

    return ret;
}
int vuelos_getNombre(Pilotos* pilotos,char* nombre)
{
    int ret=-1;

    if(pilotos!=NULL )
    {

        strcpy(nombre,pilotos->nombre);
        ret=0;

    }

    return ret;
}

int vuelos_setFecha(Vuelos* vuelos,char* fecha)
{
    int ret = -1;
    if(vuelos!=NULL && fecha!=NULL)
    {
        strcpy(vuelos->fecha,fecha);
        ret = 0;
    }

    return ret;
}
int vuelos_getFecha(Vuelos* vuelos,char* fecha)
{
    int ret=-1;

    if(vuelos!=NULL )
    {

        strcpy(fecha,vuelos->fecha);
        ret=0;

    }

    return ret;
}


int vuelos_setDestino(Vuelos* vuelos,char* destino)
{
    int ret = -1;
    if(vuelos!=NULL && destino!=NULL)
    {
        strcpy(vuelos->destino,destino);
        ret = 0;
    }

    return ret;

}

int vuelos_getDestino(Vuelos* vuelos,char* destino)
{
    int ret=-1;

    if(vuelos!=NULL )
    {

        strcpy(destino,vuelos->destino);
        ret=0;

    }

    return ret;
}






int vuelos_setCantPasajeros(Vuelos* vuelos,int cantPasajeros)
{
     int ret = -1;
    if(vuelos!=NULL)
    {
        vuelos->cantPasajeros = cantPasajeros;
        ret = 0;
    }

    return ret;
}
int vuelos_getCantPasajeros(Vuelos* vuelos,int* cantPasajeros)
{
    int ret = -1;
    if(vuelos!=NULL )
    {
        *cantPasajeros=vuelos->cantPasajeros;
        ret=*cantPasajeros;

    }

    return ret;

}


int vuelos_setHoraDespegue(Vuelos* vuelos,int horaDespegue)
{
    int ret = -1;
    if(vuelos!=NULL )
    {
        vuelos->horaDespegue = horaDespegue;
        ret = 0;
    }

    return ret;
}
int vuelos_getHoraDespegue(Vuelos* vuelos,int* horaDespegue)
{
  int ret = -1;
    if(vuelos!=NULL )
    {
        *horaDespegue=vuelos->horaDespegue;
        ret=*horaDespegue;

    }

    return ret;

}


int vuelos_setHoraLlegada(Vuelos* vuelos,int horaLlegada)
{
    int ret = -1;
    if(vuelos!=NULL )
    {
        vuelos->horaLlegada = horaLlegada;
        ret = 0;
    }

    return ret;
}
int vuelos_getHoraLlegada(Vuelos* vuelos,int* horaLlegada)
{
  int ret = -1;
    if(vuelos!=NULL )
    {
        *horaLlegada=vuelos->horaLlegada;
        ret=*horaLlegada;

    }

    return ret;

}




