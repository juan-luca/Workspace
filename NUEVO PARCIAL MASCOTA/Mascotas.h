#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
typedef struct
{
    int id;
    int idCliente;
    char nombre[51];
    char tipo[51];
    char raza[51];
    int edad;
    float peso;
    char sexo;
    int isEmpty;
}Mascotas;

void HardcodeMascotas(Mascotas[],int);
int initMascota(Mascotas [], int );
int generateIdMascota(Mascotas [], int , int );
int findMascotaById(Mascotas [], int , int );

//
int removeMascota(Mascotas [], int , int );

int printOneMascota(Mascotas [], int , int );
int printMascotas(Mascotas [], int );
int addMascota(Mascotas [], int , int , char [],char [],int ,int ,char [] ,int )
