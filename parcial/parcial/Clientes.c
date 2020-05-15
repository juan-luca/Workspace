#include "Clientes.h"

void HardcodeClientes(eCliente cliente[],int tam){
    int i;
    int idCliente[5]={1000,1001,1002,1003,1004};
    char nombre[5][51]={"Juana","Pedro","Lila","Ernesto","Pepe"};
    char apellido[5][51]={"Lala","Lolo","Lulu","Lele","Lili"};
    char localidad[5][51]={"Monte Grande","Lomas","Urquiza","Lanus","Belgrano"};
    char telefono[5][51]={"11111111","22222222","33333333","44444444","55555555"};
    int edad[5]={20,85,18,21,34};
    char sexo[5]={'F','M','F','M','M'};
    int estado[5]={1,1,1,1,1};

    for(i=0;i<tam;i++)
    {
        cliente[i].idCliente=idCliente[i];
        strcpy(cliente[i].nombre,nombre[i]);
        strcpy(cliente[i].apellido,apellido[i]);
        strcpy(cliente[i].localidad,localidad[i]);
        strcpy(cliente[i].telefono,telefono[i]);
        cliente[i].edad=edad[i];
        cliente[i].sexo=sexo[i];
        cliente[i].estado=estado[i];
    }
}

void initCliente(eCliente cliente[], int tam,int estado){
    int i;
    for(i=0;i<tam;i++){
        cliente[i].estado = estado;
    }

}

void mostrarCliente(eCliente cliente[], int tam, int estado){
    int i;
    for(i=0;i<tam;i++)
        {
            if(cliente[i].estado == estado){
                printf("%s %s %s %s %d %c\n",cliente[i].nombre
                                          ,cliente[i].apellido
                                          ,cliente[i].localidad
                                          ,cliente[i].telefono
                                          ,cliente[i].edad
                                          ,cliente[i].sexo);
            }
        }
}

