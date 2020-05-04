/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "funciones.h"
#define CANTIDADNUMEROS 10

int main()
{
    printf("Clase 04 18 de abril");
    int numero;
    int listadoDeNumeros[CANTIDADNUMEROS];
    int i;
    int sumaNumeros;



    InicializarArray(listadoDeNumeros,CANTIDADNUMEROS);
    listadoDeNumeros[9]=2;
    listadoDeNumeros[0]=8;

   testArray(listadoDeNumeros,CANTIDADNUMEROS);
    MostarArray(listadoDeNumeros,CANTIDADNUMEROS);

    sumaNumeros=SacarLaSuma(listadoDeNumeros,CANTIDADNUMEROS);

    printf("\nla suma es %d",sumaNumeros);
    /*
    for(i=0;i<CANTIDADNUMEROS;i++)
    {
        printf("\ningrese un numero :");
        scanf("%d",&listadoDeNumeros[i]);
        //listadoDeNumeros[i]=i*2;
    }
    */
    printf("\n\n");

  // MostarArray(listadoDeNumeros,CANTIDADNUMEROS);


    return 0;
}













