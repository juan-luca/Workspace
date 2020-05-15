#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#include "productos.h"

typedef struct
{
    int idProv;//PK
    char nombre[50];
  char localidad[50];
  int estado;
}eProveedor;

typedef struct
{
    int idProv;//PK
  int cantProd;
}ProvProd;

void hardCodearProv(eProveedor listado[], int tam);

int getInt(char mensaje[], int min, int max);
void mostrarProvConSusProductos(eProducto[], int, eProveedor[], int);
void mostrarProvConMasProd(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov, ProvProd listpp[]);
void iniProvProd(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov, ProvProd listpp[]);

//void mostrarCursosConSusAlumnosPorID(eAlumno [], int , eCurso [], int );

