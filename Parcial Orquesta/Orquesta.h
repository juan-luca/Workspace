#include "GeneralCommands.h"
typedef struct
{
  int id;//PK
  char nombre[51];
  char lugar[51];
  int idTipoOrquesta;
  int isEmpty;
} Orquesta;

typedef struct
{
  int id;//PK
  char nombre[51];
  int isEmpty;
} TipoOrquesta;

int initOrquesta(Orquesta [], int );
int generateIdOrquesta(Orquesta [], int , int );
int findOrquestaById(Orquesta [], int , int );
int addOrquesta(Orquesta listaOrquesta[], int , int , char [],char [],int );
int removeOrquesta(Orquesta listaOrquesta[], int , int );
int modifyOrquesta(Orquesta listaOrquesta[],int ,int );
int printOneOrquesta(Orquesta [], int , int );
int printOrquestas(Orquesta [], int );



void hardCodearTipoOrquesta(TipoOrquesta [], int );
void hardCodearOrquesta(Orquesta [], int );


