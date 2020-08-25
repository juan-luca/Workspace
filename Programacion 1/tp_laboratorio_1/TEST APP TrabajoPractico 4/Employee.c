
#include "Employee.h"
#include "GeneralCommands.h"



int employee_setNombre(Employee* employee,char* nombre)
{
    int ret = -1;
    if(employee!=NULL && nombre!=NULL)
    {
        strcpy(employee->nombre,nombre);
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
int employee_getNombre(Employee* employee,char* nombre)
{
    int ret=-1;

    if(employee!=NULL )
    {

        strcpy(nombre,employee->nombre);
        ret=0;

    }

    return ret;
}



int employee_setSueldo(Employee* employee,int sueldo)
{
    int ret = -1;
    if(employee!=NULL )
    {
        employee->sueldo = sueldo;
        ret = 0;
    }

    return ret;
}
int employee_getSueldo(Employee* employee,int* sueldo)
{
  int ret = -1;
    if(employee!=NULL )
    {
        *sueldo=employee->sueldo;
        ret=*sueldo;

    }

    return ret;

}

int employee_setId(Employee* employee,int id)
{
      int ret = -1;
    if(employee!=NULL )
    {
        employee->id = id;

        ret = 0;
    }

    return ret;

}
int employee_getId(Employee* employee,int* id)
{
    int ret = -1;
    if(employee!=NULL )
    {
        *id=employee->id;

        ret=*id;

    }

    return ret;

}

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas)
{
     int ret = -1;
    if(employee!=NULL)
    {
        employee->horasTrabajadas = horasTrabajadas;
        ret = 0;
    }

    return ret;
}
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajdas)
{
    int ret = -1;
    if(employee!=NULL )
    {
        *horasTrabajdas=employee->horasTrabajadas;
        ret=*horasTrabajdas;

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



int employee_CompareByName(void* e1, void* e2)
{
        e1 = (Employee*) e1;

        e2 = (Employee*) e2;

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



int employee_CompareById(void* e1, void* e2)
{
    int id1=0;
    int id2=0;

        e1 = (Employee*) e1;

        e2 = (Employee*) e2;


     employee_getId(e1,&id1);
     employee_getId(e2,&id2);
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





