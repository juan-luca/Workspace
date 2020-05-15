
#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


void hardCodearClientes(Cliente cliente[],int tam){

    int i;
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={"Roberta","Pablo","liliana","Carlos","Juan"};
    char apellido[5][51]={"santos","lopez","Ken","Aguero","Messi"};
    char localidad[5][51]={"Paternal","Urquiza","Caballito","Lomas","Berazategui"};
    char telefono[5][51]={"546546","652132","5468798","3213578","54354654"};
    int edad[5]={22,15,35,21,85};
    char sexo[5]={'F','F','M','M','M'};

    for(i=0;i<tam;i++)
    {
        cliente[i].id=id[i];
        strcpy(cliente[i].nombre,nombre[i]);
        strcpy(cliente[i].apellido,apellido[i]);
        strcpy(cliente[i].localidad,localidad[i]);
        strcpy(cliente[i].telefono,telefono[i]);
        cliente[i].edad=edad[i];
        cliente[i].sexo=sexo[i];
        cliente[i].isEmpty=OCUPADO;
    }
}

int initCliente(Cliente listaCliente[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaCliente[i].isEmpty = LIBRE;
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

int generateIdCliente(Cliente listaCliente[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {

        if(listaCliente[i].isEmpty==LIBRE || listaCliente[i].isEmpty==ELIMINADO)
        {

            id = lastId + 1;

            break;
        }

    }

    return id;
}
int findClienteById(Cliente listaCliente[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(id==listaCliente[i].id && listaCliente[i].isEmpty==OCUPADO )
        {
            index=i;
            break;
        }

    }
    return index;
}


int addCliente(Cliente listaCliente[], int tam, int id, char nombre[],char apellido[],int edad,int idOrquesta,int idInstrumento)
{
    int i, ret=-1;//generic var

    for(i=0;i<tam;i++)
    {
        if(listaCliente[i].isEmpty==LIBRE || listaCliente[i].isEmpty==ELIMINADO)
        {

            /* Cliente[i].id=id;
            strcpy(Cliente[i].nombre,nombre);
            strcpy(Cliente[i].apellido,apellido);
            strcpy(Cliente[i].localidad,localidad);
            strcpy(Cliente[i].telefono,telefono);
            Cliente[i].edad=edad;
            Cliente[i].sexo=sexo;
            Cliente[i].isEmpty=OCUPADO;
            ret=0;
            break;*/
        }
    }

    return ret;
}

int removeCliente(Cliente listaCliente[], int tam, int id)
{
    int i, ret=-1;
    int index=findClienteById(listaCliente,tam, id);
   for(i=0; i<tam; i++)
   {
       if(index==i)
       {
           listaCliente[i].isEmpty=ELIMINADO;
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }
    return ret;
}


/*
int modifyCliente(Cliente listaCliente[],int tam,int id)
{
    int columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findClienteById(listaCliente,tam,id);
    if(index!=-1)
    {


    do
    {

                    system("cls");


            printf("1)Nombre\n2)Apellido\n3)Tipo de Cliente\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,3);
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",listaCliente[index].nombre);

               //printOnCliente(listaCliente,tam, id);

                ret=0;
                break;

            case 2:
                getString("Ingrese el apellido nuevo: ",listaCliente[index].apellido);
                //printOnCliente(listaCliente,tam, id);
                ret=0;
                break;
            case 3:
                listaCliente[index].edad=getInt("Escriba el edad nuevo:",0,0);
               // printOnCliente(listaCliente,tam, id);
                ret=0;
                break;
                case 4:
                listaCliente[index].idOrquesta=getInt("Escriba la orquesta nuevo:",0,0);
               // printOnCliente(listaCliente,tam, id);
                ret=0;
                break;
                case 5:
                listaCliente[index].idInstrumento=getInt("Escriba el instrumento nuevo:",0,0);
               // printOnCliente(listaCliente,tam, id);
                ret=0;
                break;

            }
    }while(columnaModificar!=0);
}
    return ret;
}
*/

int printOneCliente(Cliente listaCliente[], int tam, int id)
{
    int index=findClienteById(listaCliente,tam, id);


            if(index>=0)
            {
                    /*printf("%s\t%s\t%s\t%s\t%d\t%c\n",listaCliente[i].nombre
                                          ,listaCliente[i].apellido
                                          ,listaCliente[i].localidad
                                          ,listaCliente[i].telefono
                                          ,listaCliente[i].edad
                                          ,listaCliente[i].sexo);*/
            }




    return index;
}
int printClientes(Cliente listaCliente[], int tam)
{
    int i, ret=-1,printRet=-1;
    printf("ID\tNombre\t\tApellido\tLocalidad\tTelefono\tEdad\tSexo\n");
   for(i=0; i<tam; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {

            printRet = printOneCliente(listaCliente, C, listaCliente[i].id);
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
