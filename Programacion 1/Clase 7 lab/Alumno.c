#include "Alumno.h"
#define T 10
void MenuABM(eAlumno listaAlumnos[], int tam)
{
    int opc, ID, columnaModificar;
    while(opc!=7)
    {
  printf("1)Cargar datos\n");
  printf("2)Modificar datos\n");
  printf("3)Eliminar datos\n");
  printf("4)Mostrar listado\n");
  printf("5)Ordenar nombre ascendentemente listado\n");
  printf("6)Ordenar promdedio ascendentemente listado\n");
  printf("7)Salir\n");
  opc=getInt("Seleccione una opcion:",1,7);

  switch(opc)
  {
        case 1://HACER CARGA DE A 1 REGISTRO
            cargarAlumnos(listaAlumnos, T);

            break;
        case 2:
            //MODIFICAR
             mostrarTodosLosAlumnos(listaAlumnos, T);
            //printf("\n")
            ID=getInt("Escriba el ID del registro a modificar:",0,0);
            modificarAlumno(ID,listaAlumnos);
            mostrarUnAlumno(listaAlumnos[ID]);


            break;
        case 3:
            //ELIMINAR
            mostrarTodosLosAlumnos(listaAlumnos, T);
            //printf("\n")
            ID=getInt("Escriba el ID del registro a eliminar:",0,0);
            listaAlumnos[ID].estado = 1;


            break;
        case 4:

            mostrarTodosLosAlumnos(listaAlumnos, T);
            break;
        case 5:
            ordenarAlumnosPorNombre(listaAlumnos,T);
            mostrarTodosLosAlumnos(listaAlumnos, T);
            break;
        case 6:
            ordenarAlumnosPorPromedio_Nombre(listaAlumnos,T);
            mostrarTodosLosAlumnos(listaAlumnos, T);
            break;
        case 7:

            break;
  }
system("pause");
  system("cls");
  }

}

void EliminarAlumno(eAlumno listado[], int tam,int ID)
{
    int i;

   for(i=0; i<tam; i++)
   {
       if(ID==i)
       {
           listado[i].estado=1;
       }
   }

}

void inicializarListado(eAlumno listado[], int tam)
{
    int i;

   for(i=0; i<tam; i++)
   {

           listado[i].estado=-1;

   }
   //HARDCODEO
   for(i=0; i<5; i++)
   {

           listado[i].estado=0;

   }

}

void modificarAlumno(int ID, eAlumno listado[])
{
    int columnaModificar;
    do
    {
                    system("pause");
                    system("cls");


            printf("1)Legajo\n2)Nota 1\n3)Nota 2\n4)Nombre\n5)Email\n6)Fecha de nacimiento\n");
            columnaModificar=getInt("Escriba el ID del dato que desea modificar: \n Presiones 7 para salir...",1,7);
            switch(columnaModificar)
            {
            case 1:
                listado[ID].legajo=getInt("Escriba el legajo nuevo:",0,0);
                mostrarUnAlumno(listado[ID]);
                break;

            case 2:
                listado[ID].nota1=getInt("Escriba la nota 1 nueva:",0,0);
                listado[ID].promedio=promediarNotasAlumno(listado[ID].nota1,listado[ID].nota2);
                mostrarUnAlumno(listado[ID]);
                break;
            case 3:
                listado[ID].nota2=getInt("Escriba la nota 2 nueva:",0,0);
                listado[ID].promedio=promediarNotasAlumno(listado[ID].nota1,listado[ID].nota2);
                mostrarUnAlumno(listado[ID]);
                break;
            case 4:
                printf("\nEscriba el nombre nuevo:\n");
                fflush(stdin);
                gets(listado[ID].nombre);
                mostrarUnAlumno(listado[ID]);
                break;
            case 5:
                printf("\nEscriba el email nuevo:\n");
                fflush(stdin);
                gets(listado[ID].email);
                mostrarUnAlumno(listado[ID]);
                break;
            case 6:

                listado[ID].fecha=getDate();
                mostrarUnAlumno(listado[ID]);
                break;

            }
    }while(columnaModificar!=7);
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
void cargarAlumnos(eAlumno listado[], int tam)
{
  int i;
  listado[buscarLibre(listado, tam)]=crearUnAlumno();
}

void mostrarTodosLosAlumnos(eAlumno listado[], int tam)
{
    int i;
printf("ID\tLegajo\tNota 1\tNota 2\tPromedio\tNombre\t\tEmail\t\tDia/Mes/Anio\n");
   for(i=0; i<tam; i++)
   {
       if(listado[i].estado==0)
       {
          printf("%d",i);
          mostrarUnAlumno(listado[i]);
       }


   }

}

int buscarLibre(eAlumno listado[], int tam)
{
    int i;

   for(i=0; i<tam; i++)
   {
       if(listado[i].estado==-1)
       {
          printf("\nposicion nro %d LIBRE\n",i);
          system("pause");
          break;
       }


   }
   return i;

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
  miAlumno.fecha=getDate();

  miAlumno.estado=0;
  miAlumno.promedio = promediarNotasAlumno(miAlumno.nota1,miAlumno.nota2);

  return miAlumno;

}
eFecha getDate(void)
{
    eFecha unaFecha;

    unaFecha.dia=getInt("Ingrese el dia de nacimiento:",1,31);
    unaFecha.mes=getInt("Ingrese el mes de nacimiento:",1,12);
    unaFecha.anio=getInt("Ingrese el dia de nacimiento:",1900,2021);

    return unaFecha;
}


void mostrarUnAlumno (eAlumno miAlumno)
{

  printf ("%8d %8d %8d\t%8f %15s\t%15s  [%d/%d/%d]\n", miAlumno.legajo,
                                          miAlumno.nota1,
                                          miAlumno.nota2,
                                          miAlumno.promedio,
                                          miAlumno.nombre,
                                          miAlumno.email,
                                          miAlumno.fecha.dia,
                                          miAlumno.fecha.mes,
                                          miAlumno.fecha.anio);

}

void mostrarAlumnosPromocionados(eAlumno listado[], int tam, int aprobado)
{
   int i;
    printf("ID\tLegajo\tNota 1\tNota 2\tPromedio\tNombre\t\tEmail\n");
   for(i=0; i<tam; i++)
   {
       if(listado[i].nota1 >= aprobado && listado[i].nota2 >= aprobado)
       {
           printf("%d",i);
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
    printf("ID\tLegajo\tNota 1\tNota 2\tPromedio\tNombre\t\tEmail\n");
    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio == maximo)
        {
            printf("%d",i);
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
