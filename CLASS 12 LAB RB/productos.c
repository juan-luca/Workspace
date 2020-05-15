#include "productos.h"

void hardCodearProd(eProducto listado[], int tam)
{
  int id[10]={1,2,3,4,5,6,7,8,9,10};
  char nombre[10][20] = {"pepas","oreo","okebon","vainillas","alfajores","pepitos","melitas","chocolinas","lincoln","donuts"};
  int precio[10]={10,4,9,8,7,54,76,87,231,78};
  int stock[10]={3,2,7,8,9,1,4,5,2,7};
  int idProv[10]={100,102,102,101,102,102,100,101,101,101};
  int i;

  for(i=0; i<10; i++)
  {
      listado[i].idProd = id[i];
      strcpy(listado[i].nombre, nombre[i]);
      listado[i].precio = precio[i];
      listado[i].stock = stock[i];
      listado[i].idProv = idProv[i];
      listado[i].estado = OCUPADO;
  }

    //listado[3].estado = LIBRE;

}

