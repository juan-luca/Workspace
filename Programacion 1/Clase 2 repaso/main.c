
#include <stdio.h>
#include <stdlib.h>

int main()//CLASE DE LABORATORIO 31/3/2020
{
    int num, flag=0, fnum=0,contpos=0, contneg=0, cantnum=0, prom=0, suma=0, maxpos=0;
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

         if(flag==0 && num>0)//primer ingreso
        {
            maxpos = num;
            flag=1;
        }
        if(num<0)
        {
            contneg++;
        }
        else
         {
             contpos++;
             if(num>maxpos)
             {
                 maxpos = num;
             }
         }


        suma+=num;
        cantnum++;





    printf("Escriba n para salir.");
        fflush(stdin);
        scanf("%c",&respuesta);
        fnum=0;

    }
    prom=suma/cantnum;
    printf("Cantidad positivos: %d \n",contpos);
    printf("Cantidad negativos: %d \n",contneg);
    printf("Promedio de todos los numeros: %d \n",prom);
    printf("Maximo positivo: %d",maxpos);

    return 0;
}
