
#include "Musico.h"
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

void hardCodearMusicos(Musico listado[], int tam)
{
  int id[5]={100,200,300,400,500};
  char name[5][51] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char lastName[5][51] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com"};;
  int edad[5] = {50,11,23,56,80};
  int idOrquesta[5] = {1,3,5,2,1};
  int idInstrumento[5]={2,5,9,7,2};
  int i;

  for(i=0; i<5; i++)
  {

      addMusico(listado,tam,id[i],name[i],lastName[i],edad[i],idOrquesta[i],idInstrumento[i]);
      /*
      listado[i].id = id[i];
      listado[i].edad = edad[i];
      strcpy(listado[i].nombre, name[i]);
      strcpy(listado[i].apellido, lastName[i]);
      listado[i].idOrquesta = idOrquesta[i];
      listado[i].idInstrumento = idInstrumento[i];
      listado[i].isEmpty = OCUPADO;*/
  }




}

int initMusico(Musico listaMusico[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaMusico[i].isEmpty = LIBRE;
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

int generateIdMusico(Musico listaMusico[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {
        if(listaMusico[i].isEmpty==LIBRE || listaMusico[i].isEmpty==ELIMINADO)
        {
            id = lastId + 1;

            break;
        }

    }

    return id;
}
int findMusicoById(Musico listaMusico[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(id==listaMusico[i].id || listaMusico[i].isEmpty==OCUPADO )
        {
            index=i;
            break;
        }

    }
    return index;
}


int addMusico(Musico listaMusico[], int tam, int id, char nombre[],char apellido[],int edad,int idOrquesta,int idInstrumento)
{
    int i, ret=-1;//generic var

    for(i=0;i<tam;i++)
    {
        if(listaMusico[i].isEmpty==LIBRE || listaMusico[i].isEmpty==ELIMINADO)
        {
            listaMusico[i].id=id;
            strcpy(listaMusico[i].nombre,nombre);
            strcpy(listaMusico[i].apellido,apellido);
            listaMusico[i].edad=edad;
            listaMusico[i].idOrquesta=idOrquesta;
            listaMusico[i].idInstrumento=idInstrumento;
            listaMusico[i].isEmpty=OCUPADO;
            ret=0;
            break;
        }
    }

    return ret;
}

int removeMusico(Musico listaMusico[], int tam, int id)
{
    int i, ret=-1;
    int index=findMusicoById(listaMusico,tam, id);
   for(i=0; i<tam; i++)
   {
       if(index==i)
       {
           listaMusico[i].isEmpty=ELIMINADO;
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }
    return ret;
}

int modifyMusico(Musico listaMusico[],int tam,int id)
{
    int columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findMusicoById(listaMusico,tam,id);
    if(index!=-1)
    {


    do
    {

                    system("cls");


            printf("1)Nombre\n2)Lugar\n3)Tipo de Musico\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,3);
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",listaMusico[index].nombre);

               //printOnMusico(listaMusico,tam, id);

                ret=0;
                break;

            case 2:
                getString("Ingrese el apellido nuevo: ",listaMusico[index].apellido);
                //printOnMusico(listaMusico,tam, id);
                ret=0;
                break;
            case 3:
                listaMusico[index].edad=getInt("Escriba el edad nuevo:",0,0);
               // printOnMusico(listaMusico,tam, id);
                ret=0;
                break;
                case 4:
                listaMusico[index].idOrquesta=getInt("Escriba la orquesta nuevo:",0,0);
               // printOnMusico(listaMusico,tam, id);
                ret=0;
                break;
                case 5:
                listaMusico[index].idInstrumento=getInt("Escriba el instrumento nuevo:",0,0);
               // printOnMusico(listaMusico,tam, id);
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


int printOneMusico(Musico listaMusico[], int tam, int id)
{
    int index=findMusicoById(listaMusico,tam, id);


            if(index>=0)
            {
                    printf("%d\t%s\t\t%s\t%d\t%d\t\t%d\n",listaMusico[index].id,listaMusico[index].nombre,listaMusico[index].apellido, listaMusico[index].edad,listaMusico[index].idOrquesta,listaMusico[index].idInstrumento);
            }




    return index;
}
int printMusicos(Musico listaMusico[], int tam)
{
    int i, ret=-1,printRet=-1;
    printf("ID\tNombre\t\tApellido\tEdad\tOrquesta\tInstrumento\n");
   for(i=0; i<tam; i++)
   {

       if(listaMusico[i].isEmpty==OCUPADO)
       {

            printRet = printOneMusico(listaMusico, tam, listaMusico[i].id);
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
