#include <stdlib.h>
#include "Employee.h"
#include <string.h>


//setters
/*int set_id(Employee* employee, int id)
{
    int ret = -1;
    if(employee!=NULL && id!=NULL)
    {
        employee->id = id;
        ret = 0;
    }

    return ret;
}
int set_nombre(Employee* employee, char* nombre)
{
    int ret = -1;
    if(employee!=NULL && nombre!=NULL)
    {
        strcpy(employee->nombre,nombre);
        ret = 0;
    }

    return ret;
}
int set_horasTrabajadas(Employee* employee, int horas)
{
    int ret = -1;
    if(employee!=NULL && horas!=NULL)
    {
        employee->horasTrabajadas = horas;
        ret = 0;
    }

    return ret;
}
int set_sueldo(Employee* employee, int sueldo)
{
    int ret = -1;
    if(employee!=NULL && sueldo!=NULL)
    {
        employee->sueldo = sueldo;
        ret = 0;
    }

    return ret;
}
*/
//getters
/*
int get_id(Employee* employee)
{
    int ret = -1;
    if(employee!=NULL )
    {
        ret=employee->id;

    }

    return ret;
}
char* get_nombre(Employee* employee)
{
    char* ret="-1";
    if(employee!=NULL )
    {

        strcpy(ret,employee->nombre);

    }

    return ret;
}
int get_horasTrabajadas(Employee* employee)
{
    int ret = -1;
    if(employee!=NULL )
    {
        ret=employee->horasTrabajadas;

    }

    return ret;
}
int get_sueldo(Employee* employee)
{
    int ret = -1;
    if(employee!=NULL )
    {
        ret=employee->sueldo;

    }

    return ret;
}*/
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
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    return strcmp(e1->nombre, e2->nombre);
}





