#include <stdio.h>
#include <stdlib.h>

int main()//CLASE DE LABORATORIO 31/3/2020
{
    int ejercicio;
    char respuesta='s';

    while(respuesta=='s')
    {
    printf("Ingrese el ejercicio que desea abrir (1 o 2):\n");
    scanf("%d",&ejercicio);
    switch(ejercicio)
    {
    case 1: ejercicio1();
        break;
    case 2: ejercicio2();
        break;

    }

    printf("Escriba n para salir.");
        fflush(stdin);
        scanf("%c",&respuesta);

    }
    return 0;
}
void ejercicio1()
{
    int n1, n2, suma,resta,producto;
    float promedio;
    printf("Ingrese 2 numeros enteros:");
    scanf("%d",&n1);
    scanf("%d",&n2);
    suma=n1+n2;
    resta=n2-n1;
    producto=n1*n2;
    promedio=(float)suma/2.0;
    printf("La suma es %d:\n",suma);
    printf("La resta es %d:\n",resta);
    printf("El producto es %d:\n",producto);
    printf("El promedio es %.2f:\n",promedio);
}

void ejercicio2()
{
    //ejercicio 2
    char r='s';
    int flag=0, num, max, min, contpos=0, contneg=0,contpar=0,prom=0, suma=0, cantnum=0;
    while(r=='s')
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&num);

        if(flag==0)//primer ingreso
        {
            max = num;
            min = num;
            flag=1;
        }
        if(num<0)
        {
            contneg++;
        }
        else
         {
             contpos++;
         }

         if(num%2 ==0)
         {
             contpar++;
         }
        suma+=num;
        cantnum++;
        printf("Escriba n para imprimir los resultados");
        fflush(stdin);
        scanf("%c",&r);
    }
    prom=suma/cantnum;
    printf("Cantidad pares: %d \n",contpar);
    printf("Cantidad positivos: %d \n",contpos);
    printf("Cantidad negativos: %d \n",contneg);
    printf("Promedio de todos los numeros: %d \n",prom);
}
