#include <stdlib.h>
#include "Alumno.h"

#define T 10

int main ()
{
    //tipodedato nombrevariable;

    eAlumno listaAlumnos[T]={{1,8,9,8.5,"Pepe","pepe@gmail.com",{10,5,1999},0},
                             {3,10,10,10,"Fatiga","fatiga@gmail.com",{3,7,1997},0},
                             {2,4,5,4.5,"Coqui","coqui@gmail.com",{5,10,2001},0},
                             {5,10,10,10,"Ana","paola@gmail.com",{12,2,1990},0},
                             {4,10,10,10,"Paola","moni@gmail.com",{15,3,1989},0}};
    inicializarListado(listaAlumnos, T);
    MenuABM(listaAlumnos, T);

    //printf("CARGA DE DATOS:\n");
    //cargarTodosLosAlumnos(listaAlumnos, T);

  /*  printf("LISTADO:\n");
    mostrarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO DE PROMOCIONADOS:\n");
    mostrarAlumnosPromocionados(listaAlumnos, T, 6);
    printf("LISTADO ORDENADO:\n");
    ordenarAlumnosPorNombre(listaAlumnos,T);
    mostrarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO DE ALUMNOS CON PROMEDIO MAXIMO:\n");
    mostrarAlumnosConMaximoPromedio(listaAlumnos, T);
    printf("LISTADO ORDENADO POR PROMEDIO:\n");
    ordenarAlumnosPorPromedio_Nombre(listaAlumnos,T);

    mostrarTodosLosAlumnos(listaAlumnos, T);*/
  return 0;
}

