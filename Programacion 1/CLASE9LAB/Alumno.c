#include "Alumno.h"
void hardCodearAlumnos(eAlumno listado[], int tam)
{
  int legajos[5]={1,2,3,4,5};
  int nota1[5]={10,4,9,8,7};
  int nota2[5]={3,2,7,8,9};
  char nombre[5][20] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char mail[5][20] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com"};;
  eFecha fechas[5] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{4,8,1999}};
  int curso[5] = {101,100,101,102,100};
  int i;

  for(i=0; i<5; i++)
  {
      listado[i].legajo = legajos[i];
      listado[i].nota1 = nota1[i];
      listado[i].nota2 = nota2[i];
      listado[i].promedio = (float) (listado[i].nota1 + listado[i].nota2)/2;
      listado[i].fechaNacimiento = fechas[i];
      strcpy(listado[i].nombre, nombre[i]);
      strcpy(listado[i].email, mail[i]);
      listado[i].idCurso = curso[i];
      listado[i].estado = OCUPADO;
  }

    listado[3].estado = LIBRE;

}

void eliminarAlumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    for(i=0; i<tam;i++)
    {
        if(legajo == listado[i].legajo)
        {
            listado[i].estado=LIBRE;
            break;
        }
    }
}
void modificarALumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    for(i=0; i<tam;i++)
    {
        if(legajo == listado[i].legajo)
        {
           printf("Reingrese EMAIL:");
           fflush(stdin);
           gets(listado[i].email);
            break;
        }
    }
}

void inicializarAlumnos(eAlumno listado[], int tam)
{
    int i;

  for(i=0; i<tam; i++)
  {
      listado[i].estado = LIBRE;
  }
}
int buscarLibre(eAlumno listado[], int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if(listado[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;

}
void cargarUnAlumno(eAlumno listado[], int tam)
{
  int index;

  index = buscarLibre(listado, tam);

  if(index!=-1)
  {
      listado[index] = crearUnAlumno();//
      //ASOCIAR UN ALUMNO A UN CURSO
  }

  /*....*/

}
void mostrarTodosLosAlumnos(eAlumno listado[], int tam)
{
    int i;

   for(i=0; i<tam; i++)
   {
       if(listado[i].estado==OCUPADO)
       {
           mostrarUnAlumno(listado[i]);
       }

   }

}


eAlumno crearUnAlumno (void)
{
  eAlumno miAlumno;


  printf ("Ingrese legajo: ");
  scanf ("%d", &miAlumno.legajo);
  printf ("Ingrese nota 1: ");
  scanf ("%d", &miAlumno.nota1);
  printf ("Ingrese nota 2: ");
  scanf ("%d", &miAlumno.nota2);
  printf ("Ingrese nombre: ");
  fflush (stdin);
  gets(miAlumno.nombre);

  printf ("Ingrese email: ");
  fflush (stdin);
  gets (miAlumno.email);

  miAlumno.fechaNacimiento = getDate();

  miAlumno.promedio = promediarNotasAlumno(miAlumno.nota1,miAlumno.nota2);

  miAlumno.estado = OCUPADO;

  return miAlumno;

}


void mostrarUnAlumno (eAlumno miAlumno)
{
  printf ("%8d %8d %8d\t%8.2f %15s %15s [%d/%d/%d]  %d\n", miAlumno.legajo,
                                          miAlumno.nota1,
                                          miAlumno.nota2,
                                          miAlumno.promedio,
                                          miAlumno.nombre,
                                          miAlumno.email,
                                          miAlumno.fechaNacimiento.dia,
                                          miAlumno.fechaNacimiento.mes,
                                          miAlumno.fechaNacimiento.anio,
                                          miAlumno.idCurso);
}

void mostrarAlumnosPromocionados(eAlumno listado[], int tam, int aprobado)
{
   int i;

   for(i=0; i<tam; i++)
   {
       if(listado[i].nota1 >= aprobado && listado[i].nota2 >= aprobado)
       {
            mostrarUnAlumno(listado[i]);
       }

   }
}

float promediarNotasAlumno(int nota1, int nota2)
{
    return (float) (nota1+nota2)/2;
}

void ordenarAlumnosPorNombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
        }

    }

}

float buscarPromedioMaximo(eAlumno listado[], int tam)
{
    int i;
    float maxPromedio;
    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio>maxPromedio || i==0)
        {
            maxPromedio = listado[i].promedio;
        }
    }

    return maxPromedio;
}
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam)
{
    int i;
    float maximo;
    maximo = buscarPromedioMaximo(listado,tam);

    //mostrarAlumnosPromedioMaximo(listado,tam, maximo);

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio == maximo)
        {
            mostrarUnAlumno(listado[i]);
        }
    }
}

void ordenarAlumnosPorPromedio_Nombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listado[i].promedio>listado[j].promedio)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
            else
            {
               if(listado[i].promedio==listado[j].promedio)
               {
                   if(strcmp(listado[i].nombre,listado[j].nombre)>0)
                   {
                        auxAlumno = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxAlumno;
                   }
               }
            }
        }

    }
}
eFecha getDate(void)
{
    eFecha unaFecha;
    printf("Ingrese dia: ");
    scanf("%d", &unaFecha.dia);
    printf("Ingrese mes: ");
    scanf("%d", &unaFecha.mes);
    printf("Ingrese año: ");
    scanf("%d", &unaFecha.anio);
    return unaFecha;
}

void mostrarAlumnosConSuCurso(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i;//alumnos
    int j;//cursos
    //Tener en cuenta que hay alumnos que pueden estar dados de baja
    //Tener en cuenta que hay cursos que pueden estar dados de baja
    for(i=0; i<sizeAlumnos; i++)
    {
        for(j=0; j<sizeCursos; j++)
        {
            if(listaDeAlumnos[i].idCurso /*FK*/ == listaDeCursos[j].idCurso /*PK*/)
            {
                printf("%4d %15s %15s %4d\n", listaDeAlumnos[i].legajo, listaDeAlumnos[i].nombre, listaDeCursos[j].descripcion, listaDeCursos[j].duracion);
                break;
            }
        }
    }


}

void mostrarCursosConSusAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i;//
    int j;//

    for(i=0; i<sizeCursos; i++)
    {
        printf("CURSO: %s\n", listaDeCursos[i].descripcion);
        for(j=0; j<sizeAlumnos; j++)
        {
            //Preguntar si el alumno esta disponible
             if(listaDeAlumnos[j].idCurso /*FK*/ == listaDeCursos[i].idCurso /*PK*/)
             {
                  mostrarUnAlumno(listaDeAlumnos[j]);
             }

        }
    }

}

int getInt(char mensaje[], int min, int max)
{

    int ValorEntero=0;
    int noValidar=0;

    if(min==0 && max==0)
    {
        noValidar=1;
    }

    printf("%s \n",mensaje);
    fflush(stdin);
    scanf("%d",&ValorEntero);





    if(noValidar==0)
    {
    while(ValorEntero < min || ValorEntero > max)
    {
        printf("\nError, %d",mensaje);
        scanf("%d",&ValorEntero);
    }
    }



    return ValorEntero;
}
void mostrarCursosConSusAlumnosPorID(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i,j,h;
    int cursoelegido;


    for(i=0; i<sizeCursos; i++)
    {
        printf("%4d %15s %d\n", listaDeCursos[i].idCurso, listaDeCursos[i].descripcion, listaDeCursos[i].duracion);
    }

    cursoelegido=getInt("Ingrese el id del curso:",0,0);

    for(h=0; h<sizeCursos; h++)
    {
        if(listaDeCursos[h].idCurso==cursoelegido)
        {
            printf("%4d %15s %d\n", listaDeCursos[h].idCurso, listaDeCursos[h].descripcion, listaDeCursos[h].duracion);

             for(j=0; j<sizeAlumnos; j++)
            {

                     if(listaDeAlumnos[j].idCurso /*FK*/ == cursoelegido /*PK*/)
                     {
                          mostrarUnAlumno(listaDeAlumnos[j]);
                     }

            }

            break;
        }

    }

    // printf("CURSO: %s\n", listaDeCursos[h].descripcion);



}

void mostrarCantAlumJava(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i,j,h,CONT=0;
    int cursoelegido=100;



    for(h=0; h<sizeCursos; h++)
    {
        if(listaDeCursos[h].idCurso==cursoelegido)
        {
            printf("%4d %15s %d\n", listaDeCursos[h].idCurso, listaDeCursos[h].descripcion, listaDeCursos[h].duracion);
            for(j=0; j<sizeAlumnos; j++)
            {
            //Preguntar si el alumno esta disponible
             if(listaDeAlumnos[j].idCurso /*FK*/ == cursoelegido /*PK*/)
             {
                  CONT++;
             }

            }
            break;
        }

    }

    // printf("CURSO: %s\n", listaDeCursos[h].descripcion);

        printf("Cantidad de alumnos: %d\n",CONT);


}

void mostrarCantHorasAlumCursos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i,j,h,HORAS=0;
    int cursoelegido;

    for(i=0; i<sizeCursos; i++)
    {
        printf("%4d %15s %d\n", listaDeCursos[i].idCurso, listaDeCursos[i].descripcion, listaDeCursos[i].duracion);
    }

    cursoelegido=getInt("Ingrese el id del curso:",0,0);


    for(h=0; h<sizeCursos; h++)
    {
        if(listaDeCursos[h].idCurso==cursoelegido)
        {
            printf("%4d %15s %d\n", listaDeCursos[h].idCurso, listaDeCursos[h].descripcion, listaDeCursos[h].duracion);
            for(j=0; j<sizeAlumnos; j++)
            {
            //Preguntar si el alumno esta disponible
             if(listaDeAlumnos[j].idCurso /*FK*/ == cursoelegido /*PK*/)
             {
                  HORAS=HORAS+listaDeCursos[j].duracion;
             }

            }
            break;
        }

    }

    // printf("CURSO: %s\n", listaDeCursos[h].descripcion);

        printf("Cantidad de HORAS: %d\n",HORAS);


}



