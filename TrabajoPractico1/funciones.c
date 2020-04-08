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
#include <ctype.h>

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
        system("color 4F");
        printf("Error, %s \n",mensaje);
        scanf("%d",&ValorEntero);
    }
    system("color 0f");
    }



    return ValorEntero;
}


float getFloat(char mensaje[], float min, float max)
{
    float numero;
    int ValorEntero=0, noValidar=0, temp, tt;
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
            system("color 4F");
        printf("Error, %s \n",mensaje);
        scanf("%f",&numero);
        }
}
system("color 0F");


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
        {system("color 4F");
        printf("Error, %s \n",mensaje);
        fflush(stdin);
        scanf("%c",&cadena);

        }
        system("color 0F");
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

float sumar (float n1, float n2, int flotante)
{
    int in1=n1, in2=n2;
    if(flotante==1)
    {
        float fres=n1+n2;
        return fres;
    }else
    {
        int ires=in1+in2;
        /*printf("\n n1 %d -- n2 %d---------res= %d\n",in1,in2,ires);
        system("pause");*/
        return ires;
    }

}

float restar (float n1, float n2, int flotante)
{
    int in1=n1, in2=n2;
    if(flotante==1)
    {
        float fres=n1-n2;
        return fres;
    }else
    {
        int ires=in1-in2;
        /*printf("\n n1 %d -- n2 %d---------res= %d\n",in1,in2,ires);
        system("pause");*/
        return ires;
    }

}

float producto (float n1, float n2, int flotante)
{
    int in1=n1, in2=n2;
    if(flotante==1)
    {
        float fres=n1*n2;
        return fres;
    }else
    {
        int ires=in1*in2;
        /*printf("\n n1 %d -- n2 %d---------res= %d\n",in1,in2,ires);
        system("pause");*/
        return ires;
    }

}

float division (float n1, float n2)
{

    if(n2!=0)
    {

        float fres=n1/n2;
       /* printf("\n n1 %f -- n2 %f---------res= %f\n",n1,n2,fres);
        system("pause");*/
        return fres;


   }else
    {
        return -999999999;
    }

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
        printf("\nNo se pudo realizar la division ya que se intento dividir por 0...");

    }else
    {

                printf("\nEl resultado de %f/%f es: %f",fnumA,fnumB,divi);



    }

    if(factA==0)
    {
        printf("\nEl factorial %d no pudo ser realizado por numeros incompatibles...",inumA);
    }else
    {
        printf("\nEl factorial de %d es: %d",inumA,factA);
    }
    if(factB==0)
    {
        printf("\nEl factorial %d no pudo ser realizado por numeros incompatibles...",inumB);
    }else
    {
        printf("\nEl factorial de %d es: %d",inumB,factB);
    }
    printf("\n");
}


