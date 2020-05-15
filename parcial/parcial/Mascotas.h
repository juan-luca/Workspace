#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int idMascota;
    int idDuenio;
    char nombre[51];
    char tipo[51];
    char raza[51];
    int edad;
    float peso;
    char sexo;
    int estado;
}eMascotas;

void HardcodeMascotas(eMascotas[],int);
void initMascota(eMascotas mascota[], int tam,int estado);
