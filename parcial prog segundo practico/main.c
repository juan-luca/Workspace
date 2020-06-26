#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[50];
    char sector;
}Employee;


Employee* nuevoEmployee();
Employee* nuevoEmployeeParam(int id,char* nombre,char sector);

int main()
{




    //----------------EJERCICIO 2
    /*
    int id;
    char nombre[50];
    char sector;
    Employee* employee=nuevoEmployeeParam(98,"Juan",'A');

    id=employee->id;
    strcpy(nombre,employee->nombre);
    sector=employee->sector;
    printf("\n\n---------------------------------------------\n\n");
    printf("ID: %d \nNOMBRE: %s \nSector: %c",id,nombre,sector);
    printf("\n\n---------------------------------------------\n\n");

*/

//****************EJERCICIO 3
    Employee* employee = nuevoEmployee();
    int id;
    char nombre[50];
    char sector;
    printf("Ingrese el ID\n");
      scanf("%d",&id);
    printf("Ingrese el nombre\n");
        fflush(stdin);
        gets(nombre);
         printf("Ingrese el sector\n");
        fflush(stdin);
       scanf("%c",&sector);
    employee=nuevoEmployeeParam(id,nombre,sector);
    //printf("ID: %d \nNOMBRE: %s \nSector: %c",employee->id,employee->nombre,employee->sector);
    //system("pause");
    guardarArchivo("archivo.bin",employee);
    //system("cls");
    leerArchivo("archivo.bin");
//********************************************

    return 0;
}

//------------ejercicio 2
Employee* nuevoEmployee()
{
    Employee* employee;
employee =(Employee*) malloc(sizeof(Employee));

return employee;

}
Employee* nuevoEmployeeParam(int id,char* nombre,char sector)
{
    Employee* employee;
    employee=nuevoEmployee();


    employee->id=id;
    strcpy(employee->nombre,nombre);
    employee->sector=sector;


    return employee;

}




//--------------------------------


//******************ejercicio 3

int leerArchivo(char* path)
{
    int id;
    char nombre[50];
    char sector;




   Employee* employee;

FILE* pFile;

pFile = fopen(path,"rb");

   while(!feof(pFile))
   {

       employee = nuevoEmployee();
        fread(employee,sizeof(Employee),1,pFile);


   }
        id=employee->id;
        strcpy(nombre,employee->nombre);
        sector=employee->sector;

        printf("ID: %d \nNOMBRE: %s \nSector: %c",id,nombre,sector);

   return 0;

}

int guardarArchivo(char* path, Employee* employee)
{





 FILE* fBinary;
       fBinary = fopen(path, "wb");


        fwrite(employee, sizeof(Employee), 1, fBinary);

       // printf("ID: %d \nNOMBRE: %s \nSector: %c",employee->id,employee->nombre,employee->sector);

    fclose(fBinary);


return 0;
}





//*****************************

//PARRAFO
/*

Con memoria dinámica nos referimos a una memoria que no tiene tamaño, se va redimensionando a medida que el programa necesita.
Esta memoria se puede manejar con punteros a direcciones de memoria.
Para reservar espacio en tal memoria se debe usar el malloc() y para liberarlo cuando se deja de usar el free()
El heap es un sector en la memoria dinamica el cual esta asignado para almacenar datos durante la ejecucion de un programa.
La pila a es donde se almacenan las llamadas a funciones de un programa


*/
