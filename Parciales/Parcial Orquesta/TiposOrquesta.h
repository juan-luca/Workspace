typedef struct
{
  int id;//PK
  char name[51];
  char lastName[51];
  float salary;
  int sector;//FK
  int isEmpty;
} TiposOrquesta;
int initTiposOrquesta(TiposOrquesta [], int );
int generateIdTiposOrquesta(TiposOrquesta [], int , int );
int findTiposOrquestaById(TiposOrquesta [], int , int );


