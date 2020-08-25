#include "Mascotas.h"


void HardcodeMascotas(Mascotas mascota[],int tam)
{
    int i;
    int id[11]={100,101,102,103,104,105,106,107,108,109,110};
    int idCliente[11]={1,3,1,2,3,3,4,2,5,5,5};
    char nombre[11][51]={{"Mia"},{"Manuela"},{"Dero"},{"nuni"},{"jart"},{"carlin"},{"cucu"},{"clanca"},{"rey"},{"mini"},{"donald"}};
    char tipo[11][51]={{"Gato"},{"Perro"},{"Gato"},{"Perro"},{"Gato"},{"Perro"},{"Perro"},{"Raro"},{"Gato"},{"Gato"},{"Perro"}};
    char raza[11][51]={{"Siames"},{"Mestizo"},{"Siames"},{"Pitbull"},{"Mestizo"},{"Mestizo"},{"Labrador"},{"Iguana"},{"Persa"},{"Siames"},{"Bulldog"}};
    int edad[11]={10,11,5,3,5,2,7,1,9,6,4};
    float peso[11]={5.6,7.28,5.21,21.5,35.69,78.2,15.2,25.2,23.6,7.21,2.9};
    char sexo[11]={'F','M','F','M','M','M','M','F','M','M','M'};


    for(i=0;i<tam;i++)
    {
        mascota[i].id=id[i];
        mascota[i].idCliente=idCliente[i];
        strcpy(mascota[i].nombre,nombre[i]);
        strcpy(mascota[i].tipo,tipo[i]);
        strcpy(mascota[i].raza,raza[i]);
        mascota[i].edad=edad[i];
        mascota[i].peso=peso[i];
        mascota[i].sexo=sexo[i];
        mascota[i].isEmpty=OCUPADO;
    }
}


int initMascota(Mascotas listaMascota[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaMascota[i].isEmpty = LIBRE;
  }
  if(i==tam)
  {
        ret= 0; //ok
  }else
  {
      ret= -1;// error
  }
  return ret;
}
