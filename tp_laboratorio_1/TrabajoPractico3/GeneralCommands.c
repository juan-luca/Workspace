#include "GeneralCommands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


float getFloat(char mensaje[], float min, float max)
{
    float numero;
    int noValidar=0;
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
void getString(char msg[], char String[]){

        int tam;
        do
        {


        printf("%s\n", msg);
        fflush(stdin);
        fgets(String, 31, stdin);
        tam = strlen(String);
        String[tam-1] = '\0';
        }while(strcmp("",String)==0);
}

int getIntPos(char mensaje[])
{

    int ValorEntero=0;




    printf("%s \n",mensaje);
    fflush(stdin);
    scanf("%d",&ValorEntero);


    while(ValorEntero <= 0)
    {
        setError(mensaje,0);
        scanf("%d",&ValorEntero);
    }




    return ValorEntero;
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
void linea(int len)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 238);
                for(int k = 1; k < len; k++)
                  {

                    printf(" ");
                  }
                  SetConsoleTextAttribute(hConsole, 7);

}
void lineaRGB(int len, int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
                for(int k = 1; k < len; k++)
                  {

                    printf(" ");
                  }
                  SetConsoleTextAttribute(hConsole, 7);

}
void columna()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 238);
    printf(" ");
    SetConsoleTextAttribute(hConsole, 7);

}
void setError(char mensaje[], int clean)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/*
  for(int k = 1; k < 255; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    printf("%d llllllllllllllllllllllllllll\n");
  }
  system("pause");*/

    SetConsoleTextAttribute(hConsole, 79);// 7 es el color normal de la consola, 79 rojo y blanco
    printf("\nError, %s",mensaje);
    SetConsoleTextAttribute(hConsole, 7);
    printf("\n");

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
    printf("\n%s ",mensaje);

    SetConsoleTextAttribute(hConsole, 7);
    printf("\n");

    if(clean!=0)
    {
        system("pause");
       system("cls");
    }

}

char getGender(char msg[])
{

int validate=0;
char gender;

        printf("%s\n", msg);
        fflush(stdin);
        scanf("%c",&gender);
        gender=toupper(gender);

        switch(gender)
        {
            case 'F':

                validate=1;
                break;
            case 'M':validate=1;

                break;
        }

    while(validate!=1)
    {
       setError(msg,0);

        fflush(stdin);
        scanf("%c",&gender);
        gender=toupper(gender);
        switch(gender)
        {
            case 'F':

                validate=1;
                break;
            case 'M':validate=1;

                break;
        }
    }
return gender;
}
