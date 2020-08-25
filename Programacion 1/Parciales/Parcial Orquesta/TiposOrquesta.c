#include "TiposOrquesta.h"
#include "GeneralCommands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

int initTiposOrquesta(TiposOrquesta listaTiposOrquesta[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaTiposOrquesta[i].isEmpty = LIBRE;
  }
  if(i==tam)
  {
        ret= 0; //ok
  }else
  {
      ret= -1;// error
  }
  return ret;
}
int generateIdTiposOrquesta(TiposOrquesta listaTiposOrquesta[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {
        if(listaTiposOrquesta[i].isEmpty==LIBRE || listaTiposOrquesta[i].isEmpty==ELIMINADO)
        {
            id = lastId + 1;
            break;
        }
    }
    return id;
}
int findTiposOrquestaById(TiposOrquesta listaTiposOrquesta[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(id==listaTiposOrquesta[i].id && listaTiposOrquesta[i].isEmpty==OCUPADO)
        {
            index=i;
            break;
        }

    }
    return index;
}

