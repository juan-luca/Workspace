#include "GeneralCommands.h"

typedef struct
{
    int id;
    char tipo[51];
    int isEmpty;
}tipoMascota;

typedef struct
{
    int id;

    char nombre[51];
    char tipo[51];
    char raza[51];
    int edad;
    float peso;
    char sexo;
    int idCliente;
    int isEmpty;
}Mascota;


void hardCodearMascotas(Mascota [], int );
int initMascota(Mascota [], int);
int generateIdMascota(Mascota [], int , int );
int findMascotaById(Mascota [], int , int );
int findMascotaByClienteId(Mascota [], int , int );

int addMascota(Mascota [], int , int , char [],char[],char [],int ,int ,char ,int );
int removeMascota(Mascota [], int , int );
int removeMascotaByCliente(Mascota [], int , int );
int modifyMascota(Mascota [],int ,int );


