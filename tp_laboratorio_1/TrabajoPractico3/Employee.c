#include <stdlib.h>
#include "Employee.h"
#include <string.h>



int employee_setNombre(Employee* this,char* nombre)
{
    int ret = -1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        ret = 0;
    }

    return ret;
}
void cabecera()
{
    printf("\n");
    linea(184);
    printf("\n");
            columna();
            columna();
           printf("    ID   ");
           columna();

           printf("                                                                                                                          Nombre    ");
           columna();
           printf(" Horas Trabajadas ");
           columna();
           printf("      Sueldo     ");
           columna();
           columna();

    printf("\n");
    linea(184);
    printf("\n");
}
int employee_getNombre(Employee* this,char* nombre)
{
    int ret=-1;

    if(this!=NULL )
    {

        strcpy(nombre,this->nombre);
        ret=0;

    }

    return ret;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int ret = -1;
    if(this!=NULL && sueldo!=NULL)
    {
        this->sueldo = sueldo;
        ret = 0;
    }

    return ret;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
  int ret = -1;
    if(this!=NULL )
    {
        sueldo=this->sueldo;
        ret=sueldo;

    }

    return ret;

}

int employee_setId(Employee* this,int id)
{
      int ret = -1;
    if(this!=NULL && id!=NULL)
    {
        this->id = id;

        ret = 0;
    }

    return ret;

}
int employee_getId(Employee* this,int* id)
{
    int ret = -1;
    if(this!=NULL )
    {
        id=this->id;

        ret=id;

    }

    return ret;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
     int ret = -1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        ret = 0;
    }

    return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int ret = -1;
    if(this!=NULL )
    {
        horasTrabajdas=this->horasTrabajadas;
        ret=horasTrabajdas;

    }

    return ret;

}


Employee* employee_new()
{
    Employee* employee;
employee =(Employee*) malloc(sizeof(Employee));

return employee;

}
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr)
{
    Employee* employee;
    employee=employee_new();

    employee_setId(employee,idStr);
    employee_setNombre(employee,nombreStr);
    employee_setHorasTrabajadas(employee,horasTrabajadasStr);
    employee_setSueldo(employee,sueldoStr);

    return employee;

}



int employee_CompareByName(Employee* e1, Employee* e2)
{

    int ret=-1;
    char nombre1[128];
    char nombre2[128];
    employee_getNombre(e1,nombre1);
    employee_getNombre(e2,nombre2);




    if(e1!=NULL || e2!=NULL)
    {
        ret=strcmp(nombre1, nombre2);
    }
    return ret;
}

/*int employee_CompareById(Employee* e1, Employee* e2)
{
    int ret=-1;


  if(e1!=NULL || e2!=NULL)
    {



        if(e1->id > e2->id)
        {
            return 1;
        }
        else
        {
            if(e1->id < e2->id)
            {
                ret=2;
            }

        }

    }


    return ret;
}*/

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad
    int id1=employee_getId(e1,id1);
    int id2=employee_getId(e2,id2);
    int ret;



 if(e1!=NULL || e2!=NULL)
    {

        if(id1 > id2)
        {

            ret= 1;
        }
        else
        {
            if(id1 < id2)
            {

                ret= -1;
            }
            else
            {
                ret=0;
            }
        }
    }



    return ret;
}





