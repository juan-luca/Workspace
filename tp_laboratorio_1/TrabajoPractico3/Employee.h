#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr);
void employee_delete();


int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);

int employee_getId(Employee* employee,int* );
int employee_getNombre(Employee* employee,char* );
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajdas);
int employee_getSueldo(Employee* employee,int* );

int employee_setNombre(Employee* employee,char* );
int employee_setSueldo(Employee* employee,int sueldo);
int employee_setId(Employee* employee,int id);
int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);



#endif // employee_H_INCLUDED
