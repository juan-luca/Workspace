#include "GeneralCommands.h"

typedef struct
{
    int id;
    char tipo[51];
}TipoMascota;

typedef struct
{
    int id;

    char nombre[51];
    int idTipo;
    char raza[51];
    int edad;
    float peso;
    char sexo;
    int idCliente;
    int isEmpty;
}Mascota;

void CargarTipoMascotas(TipoMascota [], int);
void hardCodearMascotas(Mascota [], int );
int initMascota(Mascota [], int);
int generateIdMascota(Mascota [], int , int );
int findMascotaById(Mascota [], int , int );
int findMascotaByClienteId(Mascota [], int , int );

int addMascota(Mascota [], int , int , char [],int,char[],int ,float ,char ,int );
int removeMascota(Mascota [], int , int );
int removeMascotaByCliente(Mascota [], int , int );
int modifyMascota(Mascota [],int ,int ,TipoMascota TipoMascota[]);

int printTiposMascota(TipoMascota [], int );
int getTipoMascota(TipoMascota [],int,char []);




