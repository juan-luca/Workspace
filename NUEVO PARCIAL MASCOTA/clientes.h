#include "GeneralCommands.h"


typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    char telefono[51];
    int edad;
    char sexo;
    int isEmpty;
}Cliente;

void hardCodearClientes(Cliente [], int );
int initCliente(Cliente [], int);
int generateIdCliente(Cliente [], int , int );
int findClienteById(Cliente [], int , int );

int addCliente(Cliente [], int , int id, char [],char [],int ,int ,int );
int removeCliente(Cliente [], int , int );
//int modifyCliente(Cliente [],int ,int );

int printOneCliente(Cliente [], int , int );
int printClientes(Cliente [], int );
