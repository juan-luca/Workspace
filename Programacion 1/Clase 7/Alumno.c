#include "Alumno.h"

eAlumno crearUnALumno ()
{
  eAlumno miAlumno;


  printf ("Ingrese legajo: ");
  scanf ("%d", &miAlumno.legajo);
  printf ("Ingrese nota 1: ");
  scanf ("%d", &miAlumno.nota1);
  printf ("Ingrese nota 2: ");
  scanf ("%d", &miAlumno.nota2);
  printf ("Ingrese nombre: ");
  __fpurge (stdin);
  fgets (miAlumno.nombre, 20, stdin);

  miAlumno.promedio = promediarNotasAlumno(miAlumno.nota1,miAlumno.nota2);


  return miAlumno;

}


void mostrarUnAlumno (eAlumno miAlumno)
{
  printf ("%d--%d--%d--%f--%s\n", miAlumno.legajo,
	  miAlumno.nota1, miAlumno.nota2, miAlumno.promedio, miAlumno.nombre);
}

float promediarNotasAlumno(int nota1, int nota2)
{
    return (float) (nota1+nota2)/2
}
