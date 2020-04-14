#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <windows.h>


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


float getFloat(char mensaje[], float min, float max)
{
    float numero;
    int ValorEntero=0, noValidar=0, temp;
    if(min==0 && max==0)
    {
        noValidar=1;
    }


    printf("%s \n",mensaje);

    scanf("%f",&numero);//falta hacer validacion de caracter
    /*temp=numero;
    tt=isdigit(temp);
    printf("\n ----- %d\n",tt);
    /*
    if(!isdigit(temp))
    {
       printf("Error, solo puede ingresar numeros \n");
    }
    else
    {
        printf("NUMERO \n");
    }*/
   /* while(isdigit(numero)>0)
    {

        printf("Error, solo puede ingresar numeros \n");
        scanf("%f",&numero);
    }
*/
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


char getChar(char mensaje[], char valida1, char valida2)
{
    char cadena;
    int noValidar=0;

    if(valida1=="" && valida2=="")
    {

        noValidar=1;
    }

    printf("%s \n",mensaje);
    fflush(stdin);
    scanf("%c",&cadena);
    if(noValidar==0)
    {
        while(cadena != valida1 & cadena != valida2)
        {
            setError(mensaje,0);
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

int factorialRecursivo(int numero)
{
    int resultado;

    if(numero==0)
    {
        return 1;
    }
    else
    {
        if(numero>0)
        {
          resultado = numero * factorialRecursivo(numero-1);
            return resultado;
        }
        else
        {
            return 0;
        }
    }

}

float sumar (float num[], int tam)
{
     int i=0;
    float res=0;

    for(i=0; i< tam ; i++ )
    {



            if(res==0 )
            {
                res=num[i];
            }else
            {
                res=res+num[i];
            }


    }



        return res;


}

float restar (float num[], int tam)
{

    int i=0;
    float res=0;

    for(i=0; i< tam ; i++ )
    {



            if(res==0 )
            {
                res=num[i];
            }else
            {
                res=res-num[i];
            }


    }



        return res;


}


float producto (float num[], int flotante, int tam)
{
    int i=0;
    float res=0;

    for(i=0; i< tam ; i++ )
    {



            if(res==0 )
            {
                res=num[i];
            }else
            {
                res=res*num[i];
            }


    }



        return res;


}

float division (float num[2])
{

   //solo debe poder recibir un array de maximo 2 posiciones

       float fres=num[0]/num[1];

        return fres;


}

void mostrar(float suma, float resta, float prod, float divi, int factA, int factB, int flotante, int divisionCero, float fnumA, float fnumB)
{

    int isuma=suma, iresta=resta, iprod=prod, inumA=fnumA, inumB=fnumB;
    if(flotante==1)//es flotante
    {
        printf("\na) El resultado de la %f+%f es: %f",fnumA,fnumB,suma);
        printf("\nb) El resultado de la %f-%f es: %f",fnumA,fnumB,resta);
        printf("\nc) El resultado de %f*%f es: %f",fnumA,fnumB,prod);

    }else//sino es entero
    {
        printf("\na) El resultado de la %d+%d es: %d",inumA,inumB,isuma);
        printf("\nb) El resultado de la %d-%d es: %d",inumA,inumB,iresta);
        printf("\nc) El resultado del %d*%d es: %d",inumA,inumB,iprod);
    }
    if(divisionCero==1)
    {
        setError("No se pudo realizar la division ya que se intento dividir por 0...",0);

    }else
    {

                printf("\nEl resultado de %f/%f es: %f",fnumA,fnumB,divi);



    }

    if(factA==0)
    {


        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);// 7 es el color normal de la consola, 79 rojo y blanco
        printf("\nEl factorial de %f no pudo ser realizado por numeros incompatibles...",inumA);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }else
    {
        printf("\nEl factorial de %d es: %d",inumA,factA);
    }

    if(factB==0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);// 7 es el color normal de la consola, 79 rojo y blanco
        printf("\nEl factorial de %f no pudo ser realizado por numeros incompatibles...",inumB);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }else
    {
        printf("\nEl factorial de %d es: %d",inumB,factB);
    }

    printf("\n");
    system("pause");
}


