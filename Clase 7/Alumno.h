#include <stdio.h>

typedef struct
{
  int legajo;
  int nota1;
  int nota2;
  float promedio;
  char nombre[20];
} eAlumno;

void mostrarUnAlumno (eAlumno miAlumno);
eAlumno crearUnALumno ();
float promediarNotasAlumno(int nota1, int nota2);