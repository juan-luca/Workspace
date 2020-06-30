#include "Instrumento.h"
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
void hardCodearInstrumentos(Instrumento listado[], int tam)
{
  int id[5],lastid=1000;
  char name[5][51] = {"Guitarra","Acordeon","Flauta","Arpa","Tambor"};

  int i;

  for(i=0; i<5; i++)
  {
      id[i]=generateIdInstrumento(listado,tam,lastid);
        lastid=id[i];
      addInstrumento(listado,tam,id[i],name[i]);


      strcpy(listado[i].nombre, name[i]);
      listado[i].isEmpty = OCUPADO;
  }




}
int initInstrumento(Instrumento listaInstrumento[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaInstrumento[i].isEmpty = LIBRE;
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
int generateIdInstrumento(Instrumento listaInstrumento[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {

        if(listaInstrumento[i].isEmpty==LIBRE || listaInstrumento[i].isEmpty==ELIMINADO)
        {

            id = lastId + 1;
            break;
        }
    }
    return id;
}
int findInstrumentoById(Instrumento listaInstrumento[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(id==listaInstrumento[i].id && listaInstrumento[i].isEmpty==OCUPADO)
        {
            index=i;
            break;
        }

    }
    return index;
}

int addInstrumento(Instrumento listaInstrumento[], int tam, int id, char nombre[])
{
    int i, ret=-1;//generic var

    for(i=0;i<tam;i++)
    {

        if(listaInstrumento[i].isEmpty==LIBRE || listaInstrumento[i].isEmpty==ELIMINADO)
        {

            listaInstrumento[i].id=id;
            strcpy(listaInstrumento[i].nombre,nombre);
            listaInstrumento[i].isEmpty=OCUPADO;

            ret=0;
            break;
        }
    }

    return ret;
}

int removeInstrumento(Instrumento listaInstrumento[], int tam, int id)
{
    int i, ret=-1;
    int index=findInstrumentoById(listaInstrumento,tam, id);
   for(i=0; i<tam; i++)
   {
       if(index==i)
       {
           listaInstrumento[i].isEmpty=ELIMINADO;
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }
    return ret;
}


int printOneInstrumento(Instrumento listaInstrumento[], int tam, int id)
{
    int index=findInstrumentoById(listaInstrumento,tam, id);


            if(index>=0)
            {
                    printf("%d\t%s\n",listaInstrumento[index].id,listaInstrumento[index].nombre);
            }




    return index;
}
int printInstrumentos(Instrumento listaInstrumento[], int tam)
{
    int i, ret=-1,printRet=-1;
    printf("ID\tNombre\n");
   for(i=0; i<tam; i++)
   {

       if(listaInstrumento[i].isEmpty==OCUPADO)
       {

            printRet = printOneInstrumento(listaInstrumento, tam, listaInstrumento[i].id);
          if(printRet==-1)
          {
              setError("Registro no encontrado",0);
              ret=-1;
          }else
          {
              ret=0;
          }
       }
   }
    return ret;
}

