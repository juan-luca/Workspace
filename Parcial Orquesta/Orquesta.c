#include "Orquesta.h"

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

void hardCodearTipoOrquesta(TipoOrquesta listado[], int tam)
{
  int id[3]={1,2,3};
  char name[3][51] = {"Sinfonica","Filarmonica","Camara"};

  int i;

  for(i=0; i<5; i++)
  {
      listado[i].id = id[i];
      strcpy(listado[i].nombre, name[i]);
      listado[i].isEmpty = OCUPADO;
  }




}
void hardCodearOrquesta(Orquesta listado[], int tam)
{
  int id[5], lastid=100;
  char name[5][51] = {"filarJUNIN","CAMACOLON","FIlacatam","jununin","filarklin"};
  char lugar[5][51] = {"lujan","caba","caba","caballito","junin"};
int idTipoOrquesta[5]={1,2,3,2,2};
  int i;

  for(i=0; i<5; i++)
  {
        id[i]=generateIdOrquesta(listado,tam,lastid);
        lastid=id[i];

        //getString("Ingrese el lugar",lugar[i]);
      addOrquesta(listado,tam,id[i], name[i],lugar[i],idTipoOrquesta[i]);
  }




}

int initOrquesta(Orquesta listaOrquesta[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaOrquesta[i].isEmpty = LIBRE;
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
int generateIdOrquesta(Orquesta listaOrquesta[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {
        if(listaOrquesta[i].isEmpty==LIBRE || listaOrquesta[i].isEmpty==ELIMINADO)
        {
            id = lastId + 1;
            break;
        }
    }
    return id;
}
int findOrquestaById(Orquesta listaOrquesta[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(id==listaOrquesta[i].id && listaOrquesta[i].isEmpty==OCUPADO)
        {
            index=i;
            break;
        }

    }
    return index;
}

int addOrquesta(Orquesta listaOrquesta[], int tam, int id, char nombre[],char lugar[],int idTipoOrquesta)
{
    int i, ret=-1;//generic var

    for(i=0;i<tam;i++)
    {
        if(listaOrquesta[i].isEmpty==LIBRE || listaOrquesta[i].isEmpty==ELIMINADO)
        {
            listaOrquesta[i].id=id;
            strcpy(listaOrquesta[i].nombre,nombre);
            strcpy(listaOrquesta[i].lugar,lugar);
            listaOrquesta[i].idTipoOrquesta=idTipoOrquesta;
            listaOrquesta[i].isEmpty=OCUPADO;
            ret=0;
            break;
        }
    }

    return ret;
}

int removeOrquesta(Orquesta listaOrquesta[], int tam, int id)
{
    int i, ret=-1;
    int index=findOrquestaById(listaOrquesta,tam, id);
   for(i=0; i<tam; i++)
   {
       if(index==i)
       {
           listaOrquesta[i].isEmpty=ELIMINADO;
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }
    return ret;
}
int modifyOrquesta(Orquesta listaOrquesta[],int tam,int id)
{
    int columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findOrquestaById(listaOrquesta,tam,id);
    if(index!=-1)
    {

    do
    {

                    system("cls");


            printf("1)Nombre\n2)Lugar\n3)Tipo de Orquesta\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,3);
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",listaOrquesta[index].nombre);
               //printOnOrquesta(listaOrquesta,tam, id);
                ret=0;
                break;

            case 2:
                getString("Ingrese el lugar nuevo: ",listaOrquesta[index].lugar);
                //printOnOrquesta(listaOrquesta,tam, id);
                ret=0;
                break;
            case 3:
                listaOrquesta[index].idTipoOrquesta=getInt("Escriba el tipo de orquesta nuevo:",0,0);
               // printOnOrquesta(listaOrquesta,tam, id);
                ret=0;
                break;



            }
    }while(columnaModificar!=0);
}else
{
    setError("NO SE ENCONTRO EL ID.",0);
}
    return ret;
}

int printOneOrquesta(Orquesta listaOrquesta[], int tam, int id)
{
    int index=findOrquestaById(listaOrquesta,tam, id);


            if(index>=0)
            {
                    printf("%d\t%s\t\t%s\t%d\n",listaOrquesta[index].id,listaOrquesta[index].nombre,listaOrquesta[index].lugar, listaOrquesta[index].idTipoOrquesta);
            }




    return index;
}
int printOrquestas(Orquesta listaOrquesta[], int tam)
{
    int i, ret=-1,printRet=-1;
    printf("ID\tNombre\t\tLugar\tTipo de Orquesta\t\n");
   for(i=0; i<tam; i++)
   {

       if(listaOrquesta[i].isEmpty==OCUPADO)
       {

            printRet = printOneOrquesta(listaOrquesta, tam, listaOrquesta[i].id);

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
