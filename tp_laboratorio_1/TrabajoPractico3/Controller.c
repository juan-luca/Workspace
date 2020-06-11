#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
int ret;
FILE* pFile;

pFile = fopen(path,"r");

ret=parser_EmployeeFromText(pFile,pArrayListEmployee);

fclose(pFile);

return ret;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
int ret;
FILE* pFile;

pFile = fopen("data.bin","rb");

ret=parser_EmployeeFromBinary(pFile,pArrayListEmployee);

fclose(pFile);

return ret;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int horas;
    int sueldo;
    char nombre[128];
    int ret=-1;
    Employee* employee;

                    id=ll_len(pArrayListEmployee);
                    id++;


                    getString("Ingrese el nombre",nombre);
                    nombre[0]=toupper(nombre[0]);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    horas=getInt("Ingrese las horas trabajadas: ",1,9999999999);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    sueldo=getInt("Ingrese el sueldo: ",1,99999999999);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    employee= employee_newParametros(id,nombre,horas,sueldo);
                    ret=ll_add(pArrayListEmployee,employee);



return ret;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;
    int id;
    int horas;
    int sueldo;
    char nombre[128];
    int ret=-1;

    Employee* employee;


    for(i=0;i<len;i++)
    {
        employee = ll_get(pArrayListEmployee,i);
        id=employee_getId(employee,id);
        employee_getNombre(employee,nombre);
        horas=employee_getHorasTrabajadas(employee,horas);
        sueldo=employee_getSueldo(employee,sueldo);

        printf("%6.d - %128s - %8.d - %10.d\n", id, nombre, horas, sueldo);
    }
    if(i==len)
    {
        ret=0;
    }

return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}

