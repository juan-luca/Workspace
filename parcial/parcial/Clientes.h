#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    char telefono[51];
    int edad;
    char sexo;
    int estado;
}eCliente;

void HardcodeClientes(eCliente[],int);
void initCliente(eCliente cliente[], int tam,int estado);
void mostrarCliente(eCliente cliente[], int tam, int estado);
