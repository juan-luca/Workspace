
#include <stdio.h>
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


void hardCodearProd(eProducto listado[], int tam);




