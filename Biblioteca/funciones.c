/**
*-descripcion breve
*
*-parametros q recibe
*
*-lo que devuelve
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int getInt(char mensaje[], int min, int max)
{

    int ValorEntero=0;
    int noValidar=0;

    if(min==0 && max==0)
    {
        noValidar=1;
    }

    printf("%s \n",mensaje);
    scanf("%d",&ValorEntero);
    if(noValidar==0)
    {
        while(ValorEntero < min || ValorEntero > max)
    {
        printf("Error, %s \n",mensaje);
        scanf("%d",&ValorEntero);
    }

    }



    return ValorEntero;
}


float getFloat(char mensaje[], float min, float max)
{
    float numero;


    printf("%s \n",mensaje);
    scanf("%f",&numero);


        while(numero < min || numero > max)
        {
        printf("Error, %s \n",mensaje);
        scanf("%f",&numero);
        }





    return numero;
}


char getChar(char mensaje[], char valida1, char valida2)
{
    char cadena;
    int noValidar=0;

    if(valida1=="" && valida2=="")
    {
        printf("No valida");
        noValidar=1;
    }

    printf("%s \n",mensaje);
    fflush(stdin);
    scanf("%c",&cadena);
    if(noValidar==0)
    {
        while(cadena != valida1 & cadena != valida2)
        {
        printf("Error, %s \n",mensaje);
        fflush(stdin);
        scanf("%c",&cadena);

        }

    }



    return cadena;
}


int esPar(int numero)
{

    if(numero%2 == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}



