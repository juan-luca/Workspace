#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[50];
    float sueldo;
}Employee;


Employee* nuevoEmployee();
Employee* nuevoEmployeeParam(int id,char* nombre,float sueldo);

int main()
{




    /*----------------EJERCICIO 1
    int id;
    char nombre[50];
    float sueldo;
    Employee* employee=nuevoEmployeeParam(98,"Juan",99999.5469);

    id=employee->id;
    strcpy(nombre,employee->nombre);
    sueldo=employee->sueldo;
    printf("\n\n---------------------------------------------\n\n");
    printf("ID: %d \nNOMBRE: %s \nSueldo: %12.4f",id,nombre,sueldo);
    printf("\n\n---------------------------------------------\n\n");

    return 0;*/

//****************EJERCICIO 2
    char nombre[50];
    char apellido[50];
    printf("Ingrese el nombre\n");
        fflush(stdin);
        gets(nombre);
    printf("Ingrese el apellido\n");
        fflush(stdin);
        gets(apellido);

    guardarArchivo("archivo.csv",nombre,apellido);
    system("cls");
    leerArchivo("archivo.csv");
//********************************************

    return 0;
}

//------------ejercicio 1
Employee* nuevoEmployee()
{
    Employee* employee;
employee =(Employee*) malloc(sizeof(Employee));

return employee;

}
Employee* nuevoEmployeeParam(int id,char* nombre,float sueldo)
{
    Employee* employee;
    employee=nuevoEmployee();


    employee->id=id;
    strcpy(employee->nombre,nombre);
    employee->sueldo=sueldo;


    return employee;

}

//--------------------------------


//******************ejercicio 2

int leerArchivo(char* path)
{
    char nombre[50];
    char apellido[50];

    int ret=-1;

FILE* pFile;

pFile = fopen(path,"r");


                    fscanf(pFile, "%[^,],%[^\n] \n", nombre, apellido);

                   while(!feof(pFile))
                   {

                       fscanf(pFile, "%[^,],%[^\n] \n", nombre, apellido);




                        printf("Nombre: %s \nApellido: %s \n",nombre,apellido);

                   }



   fclose(pFile);

}

int guardarArchivo(char* path, char* nombre,char* apellido)
{



FILE* pFile;

pFile = fopen(path,"w");



            fprintf(pFile,"nombre,apellido\n");

        fprintf(pFile,"%s,%s\n",nombre,apellido);



fclose(pFile);

return 0;
}





//*****************************

//PARRAFO
/*

Con memoria dinámica nos referimos a una memoria que no tiene tamaño, se va redimensionando a medida que el programa necesita.
Esta memoria se puede manejar con punteros a direcciones de memoria.
El heap es un sector en la memoria dinamica el cual esta asignado para almacenar datos durante la ejecucion de un programa.
La pila a es donde se almacenan las llamadas a funciones de un programa


*/
