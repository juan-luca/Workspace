#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char nombre[128];
    char cId[128];
    char cHoras[128];
    char cSueldo[128];

    int ret=-1;


    //Employee* listEmployee;
    Employee* employee;




         int i=0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n] \n", cId, nombre, cHoras, cSueldo);

   while(!feof(pFile))
   {


       fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n] \n", cId, nombre, cHoras, cSueldo);

        employee = employee_newParametros(atoi(cId),nombre,atoi(cHoras),atoi(cSueldo));




        ll_add(pArrayListEmployee,employee);



   }



   ////BINARY CREATE
// printf("len = %d",ll_len(pArrayListEmployee));



    /*  FILE* fBinary;
       fBinary = fopen("data.dat", "wb");

        for(int j=0;j<ll_len(pArrayListEmployee);j++)
        {
        employee=(Employee*)ll_get(pArrayListEmployee,j);


        fwrite(employee, sizeof(Employee), 1, fBinary);

        //printf("%d -%s - %d - %d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
        }


    fclose(fBinary);
*/



    return 0;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{


    int ret=-1;


    Employee* employee;


   while(!feof(pFile))
   {
       employee =(Employee*) malloc(sizeof(Employee));

       if(fread(employee,sizeof(Employee),1,pFile)==1)
       {
            ll_add(pArrayListEmployee,employee);
       }



       // printf("%d - %s - %d - %d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

 //ll_add(pArrayListEmployee,listEmployee[i]);

   }


    return 0;
}
