typedef struct
{
  int id;//PK
  char nombre[51];
  char apellido[51];
  int edad;
  int idOrquesta;
  int idInstrumento;
  int isEmpty;
} Musico;

void hardCodearMusicos(Musico [], int );
int initMusico(Musico [], int);


int generateIdMusico(Musico [], int , int );


int findMusicoById(Musico [], int , int );

int addMusico(Musico [], int , int id, char [],char [],int ,int ,int );
int removeMusico(Musico [], int , int );
int modifyMusico(Musico [],int ,int );
int printOneMusico(Musico [], int , int );
int printMusicos(Musico [], int );
