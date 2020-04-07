
#include <stdio.h>
#include <stdlib.h>

int main()//CLASE DE LABORATORIO 31/3/2020
{
    int num, fnum=0,contpos, contneg, prom=0, suma=0, maxpos=0;
    char respuesta='s';

    while(respuesta=='s')
    {

    while(fnum==0)
    {
        printf("Ingrese el numero (entre -100 y 100):\n");
        scanf("%d",&num);
        if(num>=-100 && num<=100)
        {
            fnum=1;
        }
    }




    printf("Escriba n para salir.");
        fflush(stdin);
        scanf("%c",&respuesta);
        fnum=0;

    }
    return 0;
}
