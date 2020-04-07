
#include <stdio.h>
#include <stdlib.h>
int getInt(char mensaje[], int min, int max);
int main()
{

    int numero, total=0;

    numero = getInt("Ingrese un numero:",0,0);

    for(numero; numero==0;numero --)
    {
        printf(" %d,",numero);

    }




    return 0;
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

