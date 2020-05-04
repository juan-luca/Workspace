#include <stdio.h>
#define T 2

#define OCUPADO 1
#define LIBRE 0
#define ELIMINADO 2

void inicializarEstado(int estado[], int tam, int valorInicial);
int buscarLibre(int estado[], int tam, int valorInicial);
int cargarAlumno(int legajo[], int notaMatematica[], int notaProgramacion[], float promedio[], char nombre[][20], int estado[], int tam, int valorInicial, int valorOcupado);
void mostrarAlumnos(int legajo[], int notaMatematica[], int notaProgramacion[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado);
int modificarAlumno(int legajo[], int notaMatematica[], int notaProgramacion[], float promedio[], char nombre[][20], int estado[]);
int buscarLegajo(int legajo[], int legajobuscado);
float calcularPromedioNotas(int notaMatematica, int notaProgramacion);

int main()
{
    /*-------ALUMNO-------*/
    int legajo[T];
    int notaMatematica[T];
    int notaProgramacion[T];
    float promedio[T];
    char nombre[T][20];
    int estado[T];
    /*--------------------*/
    int i;
    int retorno;
    int opcion;


    inicializarEstado(estado, T, LIBRE);

    do
    {
        system("pause");
        system("cls");
        printf("1. Cargar un ALUMNO\n");
        printf("2. Eliminar un ALUMNO\n");
        printf("3. Modificar un ALUMNO\n");
        printf("4. Listar ALUMNOS\n");
        printf("5. Ordenar ALUMNOS por NOMBRE\n");
        printf("10. SALIR: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
               retorno = cargarAlumno(legajo, notaMatematica, notaProgramacion, promedio, nombre, estado, T, LIBRE, OCUPADO);
               switch(retorno)
               {
                    case 1:
                        printf("Alumno ingresado!!\n");
                    break;

                    case -1:
                        printf("No hay espacio!");
                    break;
               }
                break;

            case 2:
                break;

            case 3:
                 modificarAlumno(legajo, notaMatematica, notaProgramacion, promedio, nombre, estado);
                break;

            case 4:
                mostrarAlumnos(legajo, notaMatematica, notaProgramacion, promedio, nombre, estado, T, OCUPADO);
                break;
            case 5:
                break;
        }

    }while(opcion!=10);


    return 0;
}


void inicializarEstado(int estado[], int tam, int valorInicial)
{
    int i;
    for(i=0; i<tam; i++)
    {
        estado[i] = valorInicial;
    }

}

int buscarLibre(int estado[], int tam, int valorInicial)
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(estado[i] == valorInicial)
        {
            indice = i;
            break;
        }
    }


    return indice;
}
/*
return -1 si no pudo cargar un alumno, porque no hay lugar
        1 si pudo efectuar la carga de datos

*/
int cargarAlumno(int legajo[], int notaMatematica[], int notaProgramacion[], float promedio[], char nombre[][20], int estado[], int tam, int valorInicial, int valorOcupado)
{
    //buscar espacio
    //si encuentro espacio le pido datos al usuario
    //si no ecnuentro espacio lo informo


    int indice;
    indice = buscarLibre(estado, tam, valorInicial);
    if(indice != -1)
    {
        //pedir datos
        printf("Ingrese legajo: ");
        scanf("%d", &legajo[indice]);

        printf("Ingrese nota de matematica: ");
        scanf("%d", &notaMatematica[indice]);

        printf("Ingrese nota de programacion: ");
        scanf("%d", &notaProgramacion[indice]);

        promedio[indice] = calcularPromedioNotas(notaMatematica[indice],notaProgramacion[indice]);

        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(nombre[indice], 20, stdin);

        estado[indice] = valorOcupado;

        /* pedir el resto de los datos */
        //promedio lo calculan con una funcion
        //cambiar el estado;

        indice = 1;
    }
  return indice;
}


void mostrarAlumnos(int legajo[], int notaMatematica[], int notaProgramacion[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado)
{
    int i;

    for(i=0; i<tam; i++)
    {
       if(estado[i]==valorOcupado)
       {
           printf("%4d %2d %2d %.2f %20s\n", legajo[i], notaMatematica[i], notaProgramacion[i], promedio[i], nombre[i]);
       }

    }


}

float calcularPromedioNotas(int notaMatematica, int notaProgramacion)
{

    return (float)(notaMatematica+notaProgramacion)/2;
}

int modificarAlumno(int legajo[], int notaMatematica[], int notaProgramacion[], float promedio[], char nombre[][20], int estado[])
{



    int indice, i=0, legajobuscado,opc, existeLegajo;
    int legajoNuevo;
    legajobuscado=getInt("Ingrese el legajo",0,0);

    if(buscarLegajo(legajo,legajobuscado)==1)
        {


            for(i=0;i<T;i++)
            {
                    system("cls");
                    printf("\nMODIFICAR:");
                    printf("\n----------");
                    printf("\n1)Legajo");
                    printf("\n2)Nombre");
                    printf("\n3)Nota de matematica");
                    printf("\n4)Nota de programacion");
                    printf("\n5)Estado");
                    getInt("Ingrese la opcion deseada: ",1,5);//verificar si se encontro en todos los casos
                    switch(opc)
                    {
                    case 1://CORROBORAR QUE NO EXISTA EL VALOR NUEVO
                         legajoNuevo=getInt("Ingrese el LEGAJO NUEVO: ",0,0);

                        if(buscarLegajo(legajo,legajoNuevo)==0)
                        {
                            legajo[i]=legajoNuevo;
                            printf("\nLegajo modificado con exito!\n");
                        }else
                        {
                            printf("\nEl legajo ya existe!\n");
                        }


                        break;

                    case 2://falta ingresar nombre
                        printf("\nIngrese nombre: ");
                        fflush(stdin);
                        fgets(nombre[i], 20, stdin);
                        printf("\nNombre modificado con exito!\n");

                        break;

                    case 3:
                         notaMatematica[i]=getInt("Ingrese la nota de MATEMATICA NUEVA: ",1,10);
                        promedio[i] = calcularPromedioNotas(notaMatematica[i],notaProgramacion[i]);
                        printf("\nNota modificada con exito!\n");
                        break;

                    case 4:
                        notaProgramacion[i]=getInt("Ingrese la nota de PROGRAMACION NUEVA: ",1,10);
                        printf("\nNota modificada con exito!\n");
                        promedio[i] = calcularPromedioNotas(notaMatematica[i],notaProgramacion[i]);
                        break;

                    case 5:
                        estado[i]=getInt("Ingrese el estado NUEVO: ",-1,ELIMINADO);
                        printf("\nEstado modificado con exito!\n");
                        break;


                        printf("\n");
                    }

                    break;//salir del ciclo
                }

        }else
        {
            printf("\n No se encontro el legajo\n");

        }


  return indice;
}

int buscarLegajo(int legajo[], int legajobuscado)
{
    int i=0;


    for(i=0;i<T;i++)
    {
        if(legajobuscado==legajo[i])
        {
           return 1;
        }else
        {
            if(i==T-1)
            {
                return 0;
            }

        }
    }



}




