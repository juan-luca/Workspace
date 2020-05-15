typedef struct
{
  int id;//PK
  char nombre[51];
  int isEmpty;
} Instrumento;

int initInstrumento(Instrumento [], int );
int generateIdInstrumento(Instrumento [], int , int );
int findInstrumentoById(Instrumento [], int , int );
int addInstrumento(Instrumento [], int , int id, char [] );
int removeInstrumento(Instrumento [], int , int );
int printOneInstrumento(Instrumento [], int , int );
int printInstrumentos(Instrumento [], int );

void hardCodearInstrumentos(Instrumento [], int );
