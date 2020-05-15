#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int idProd;//PK
 char nombre[50];
  int precio;
  int stock;
  int idProv;
  int estado;
}eProducto;

typedef struct
{
    int idProv;//PK
    char nombre[50];
  char localidad[50];
  int estado;
}eProveedor;

void hardCodearProv(eProveedor listado[], int tam);

int getInt(char mensaje[], int min, int max);
void mostrarProvConSusProductos(eProducto[], int, eProveedor[], int);
void mostrarProvConMasProd(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov);

//void mostrarCursosConSusAlumnosPorID(eAlumno [], int , eCurso [], int );


void hardCodearProd(eProducto listado[], int tam);

