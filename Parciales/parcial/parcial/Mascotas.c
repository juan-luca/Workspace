#include "Mascotas.h"


void HardcodeMascotas(eMascotas mascota[],int tam)
{
    int i;
    int idMascota[11]={2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010};
    int idDuenio[11]={1000,1000,1001,1001,1001,1002,1002,1003,1004,1004,1004};
    char nombre[11][51]={{"Michix"},{"Michox"},{"Tutuca"},{"Potter"},{"michifusi"},{"Brutus"},{"Godzilla"},{"Manchita"},{"Michooox"},{"Micheeex"},{"Tyson"}};
    char tipo[11][51]={{"Gato"},{"Gato"},{"Perro"},{"Perro"},{"Gato"},{"Perro"},{"Raro"},{"Perro"},{"Gato"},{"Gato"},{"Perro"}};
    char raza[11][51]={{"Persa"},{"Callejero"},{"Pug"},{"Pitbull"},{"Persa"},{"Pitbull"},{"Reptil"},{"Labrador"},{"Persa"},{"Persa"},{"Bulldog"}};
    int edad[11]={8,7,9,7,3,9,8,4,5,6,9};
    float peso[11]={5.35,3.25,4.30,7.00,6.35,3.64,10.23,7.85,4.43,4.96,3.79};
    char sexo[11]={'F','F','M','M','M','M','F','M','M','M','M'};
    int estado[11]={1,1,1,1,1,1,1,1,1,1,1};

    for(i=0;i<tam;i++)
    {
        mascota[i].idMascota=idMascota[i];
        mascota[i].idDuenio=idDuenio[i];
        strcpy(mascota[i].nombre,nombre[i]);
        strcpy(mascota[i].tipo,tipo[i]);
        strcpy(mascota[i].raza,raza[i]);
        mascota[i].edad=edad[i];
        mascota[i].peso=peso[i];
        mascota[i].sexo=sexo[i];
        mascota[i].estado=estado[i];
    }
}

void initMascota(eMascotas mascota[], int tam,int estado){
    int i;
    for(i=0;i<tam;i++){
        mascota[i].estado = estado;
    }

}
