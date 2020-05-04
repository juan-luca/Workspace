#include "ArrayEmployees.h"
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
#define T 10 //cambiar a 1000


//-----------------------------------Funciones genericas
/*void hardCodearAlumnos(eEmployee listado[], int tam)
{
  int id[5]={1,2,3,4,5};
  char name[5][51] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char lastName[5][51] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com"};;
  eFecha fechas[5] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{4,8,1999}};
  int curso[5] = {101,100,101,102,100};
  int i;

  for(i=0; i<5; i++)
  {
      listado[i].legajo = legajos[i];
      listado[i].nota1 = nota1[i];
      listado[i].nota2 = nota2[i];
      listado[i].promedio = (float) (listado[i].nota1 + listado[i].nota2)/2;
      listado[i].fechaNacimiento = fechas[i];
      strcpy(listado[i].nombre, nombre[i]);
      strcpy(listado[i].email, mail[i]);
      listado[i].idCurso = curso[i];
      listado[i].estado = OCUPADO;
  }

    listado[3].estado = LIBRE;

}*/


void initEmployees(eEmployee listaEmployee[], int tam)
{
    int i;

  for(i=0; i<tam; i++)
  {
      listado[i].estado = LIBRE;
  }
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

    return -1;
}

void MenuABM(eEmployee listaEmployee[], int tam)
{
    int opc, ID, columnaModificar, flag1=0;
    initEmployees(listaEmployee,tam);

    while(opc!=0)
    {
      printf("1)ALTAS\n");
      printf("2)MODIFICAR\n");
      printf("3)BAJA\n");
      printf("4)INFORMAR\n");
      printf("0)Salir\n");
      opc=getInt("Seleccione una opcion:",0,7);

      switch(opc)
      {
            case 1://HACER CARGA DE A 1 REGISTRO
                //cargarAlumnos(listaAlumnos, T);

                flag1=1;
                break;
            case 2:
                //MODIFICAR
                /* mostrarTodosLosAlumnos(listaAlumnos, T);
                //printf("\n")
                ID=getInt("Escriba el ID del registro a modificar:",0,0);
                modificarAlumno(ID,listaAlumnos);
                mostrarUnAlumno(listaAlumnos[ID]);*/
                if(flag1==1)
                {

                }else
                {
                    setError("Primero debe ingresar los empleados en la opcion 1.",0);
                }


                break;
            case 3:
                //ELIMINAR
                /*mostrarTodosLosAlumnos(listaAlumnos, T);
                //printf("\n")
                ID=getInt("Escriba el ID del registro a eliminar:",0,0);
                listaAlumnos[ID].estado = 1;*/

                if(flag1==1)
                {

                }else
                {
                    setError("Primero debe ingresar los empleados en la opcion 1.",0);
                }
                break;
            case 4:

               // mostrarTodosLosAlumnos(listaAlumnos, T);
               if(flag1==1)
                {

                }else
                {
                    setError("Primero debe ingresar los empleados en la opcion 1.",0);
                }
                break;

      }
        system("pause");
      system("cls");
      }

}
float getFloat(char mensaje[], float min, float max)
{
    float numero;
    int ValorEntero=0, noValidar=0, temp;
    if(min==0 && max==0)
    {
        noValidar=1;
    }


    printf("%s \n",mensaje);

    scanf("%f",&numero);
if(noValidar==0)
    {
        while(numero < min || numero > max)
        {
            setError(mensaje,0);
        scanf("%f",&numero);
        }
}


     return numero;
}

int getInt(char mensaje[], int min, int max)
{

    int ValorEntero=0;
    int noValidar=0;

    if(min==0 && max==0)
    {
        noValidar=1;
    }

    printf("%s \n",mensaje);
    fflush(stdin);
    scanf("%d",&ValorEntero);





    if(noValidar==0)
    {
    while(ValorEntero < min || ValorEntero > max)
    {
        setError(mensaje,0);
        scanf("%d",&ValorEntero);
    }
    }



    return ValorEntero;
}

void setError(char mensaje[], int clean)
{

/*
  for(int k = 1; k < 255; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    printf("%d llllllllllllllllllllllllllll\n");
  }
  system("pause");*/

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 79);// 7 es el color normal de la consola, 79 rojo y blanco
    printf("Error, %s \n",mensaje);
    SetConsoleTextAttribute(hConsole, 7);

    if(clean!=0)
    {
        system("pause");
       system("cls");
    }
}

void setSucces(char mensaje[],int clean)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 175);// 7 es el color normal de la consola, 175 es verde con blanco
    printf("\n%s \n",mensaje);
    SetConsoleTextAttribute(hConsole, 7);

    if(clean!=0)
    {
        system("pause");
       system("cls");
    }

}

//*************************************Funciones genericas
