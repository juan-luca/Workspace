#include <stdio.h>
#include <stdlib.h>
#include "Mascotas_Clientes.h"
#define C 10
#define M 20

#define OCUPADO 1
#define LIBRE 0


int main()
{

        ///int opcion;
        eCliente cliente[C];
        eMascotas mascota[M];

        initCliente(cliente,C,LIBRE);
        initMascota(mascota,M,LIBRE);
        HardcodeClientes(cliente,C);
        HardcodeMascotas(mascota,M);

        mostrarCliente(cliente, C, OCUPADO);
        mostrarMascotasConSusDuenios(cliente,C,mascota,M);
        mostrarClientesConSusMascotas(cliente,C,mascota,M);

        /**
        printf("1-Mostrar Clientes\n2-\n3-\n4-\n5-: ");
    	printf("\nIngrese la opcion que desea utilizar: ");
    	scanf("%d",&opcion);
    	while(opcion > 5 || opcion < 1){
                    printf("Ingrese una opcion valida!!!!! ");
                    scanf("%d", &opcion);
                }
        do{
    	switch(opcion){
    	case 1:

            break;

       case 3:

        case 4:

        case 5:

    	}
        while(opcion!=5);
*/
}

