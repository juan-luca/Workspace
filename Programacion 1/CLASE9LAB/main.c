#include <stdlib.h>
#include "Alumno.h"
#define T 6


int main ()
{
    eAlumno listaAlumnos[T];
    eCurso listaCursos[3] = {{100,"Java",7},{101,"Inkscape", 10},{102,"Office", 9}};
    int opcion;
    int i;

    inicializarAlumnos(listaAlumnos,T);
    hardCodearAlumnos(listaAlumnos,T);
    do
    {
        printf("1.Cargar un ALUMNO\n");
        printf("2.Eliminar un ALUMNO\n");
        printf("3.Modificar un ALUMNO\n");
        printf("4.Listar ALUMNOS\n");
        printf("5.Ordenar ALUMNOS\n");
        printf("6.Mostrar CURSOS\n");
        printf("7.Mostrar ALUMNOS CON SU CURSO\n");
        printf("8.Mostrar CURSOS CON SUS ALUMNOS\n");
        printf("9.Mostrar 1 CURSO CON SUS ALUMNOS\n");
        printf("10.Mostrar CANTIDAD DE ALUMNOS EN JAVA\n");
        printf("11.Mostrar SUMATORIA DE HORAS (de alumnos) DE CADA CURSO\n");
        printf("0.SALIR\n");
        printf("ELIJA UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:

                 printf("CARGA DE DATOS:\n");
             //COMPLETAR LA FUNCION PARA TRABAJAR CON RETORNO
                cargarUnAlumno(listaAlumnos, T);
            break;
            case 2:
                eliminarAlumno(listaAlumnos,T);
                break;
            break;
            case 3:
                modificarALumno(listaAlumnos,T);
            break;
            case 4:
                printf("LISTADO:\n");
                mostrarTodosLosAlumnos(listaAlumnos, T);
            break;
            case 5:
                printf("LISTADO ORDENADO:\n");
                ordenarAlumnosPorNombre(listaAlumnos,T);
            break;
            case 6:
                for(i=0; i<3; i++)
                {
                    printf("%4d %15s %d\n", listaCursos[i].idCurso, listaCursos[i].descripcion, listaCursos[i].duracion);
                }
            break;
            case 7:
                mostrarAlumnosConSuCurso(listaAlumnos, T, listaCursos, 3);
                break;
            case 8:
                mostrarCursosConSusAlumnos(listaAlumnos, T, listaCursos, 3);

            break;
            case 9:
                mostrarCursosConSusAlumnosPorID(listaAlumnos, T, listaCursos, 3);

            break;
            case 10:
                mostrarCantAlumJava(listaAlumnos, T, listaCursos, 3);
            break;

            case 11:
                mostrarCantHorasAlumCursos(listaAlumnos, T, listaCursos, 3);
            break;



        }

    }while(opcion!=0);


   /*printf("LISTADO DE PROMOCIONADOS:\n");
    mostrarAlumnosPromocionados(listaAlumnos, T, 6);

    mostrarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO DE ALUMNOS CON PROMEDIO MAXIMO:\n");
    mostrarAlumnosConMaximoPromedio(listaAlumnos, T);
    printf("LISTADO ORDENADO POR PROMEDIO:\n");
    ordenarAlumnosPorPromedio_Nombre(listaAlumnos,T);
    mostrarTodosLosAlumnos(listaAlumnos, T);*/
  return 0;
}
