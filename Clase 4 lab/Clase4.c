
#include <stdio.h>
#include <stdlib.h>
int getInt(char mensaje[], int min, int max);
float getFloat(char mensaje[], float min, float max);
char getChar(char mensaje[], char valida1, char valida2);
int esPar(int numero);

int main()
{

   int numero, total=0,flag=0, res=0;

    numero = getInt("Ingrese un numero:",0,0);
    /*for(numero; numero!=0 ;numero--)
    {
        printf(" %d,",numero);
        if(flag==0)
        {
            total=numero;
            flag=1;
        }
        else
        {
            total=total*numero;
        }

    }*/

    res=factorialRecursivo(numero);
    printf("\nEl total es: %d",res);

    /*

    if(esPar(numero)==1)
    {
        printf("es par");

    }else
    {
        printf("es impar");
    }

*/



    return 0;
}
int factorialRecursivo(int numero)
{
    int resultado;

    if(numero==0)
    {
        resultado=1;
    }
    else
    {
        resultado = numero * factorialRecursivo(numero-1);
    }
    return resultado;
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
