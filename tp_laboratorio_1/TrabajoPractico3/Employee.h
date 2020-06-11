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


int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);

//setters
int set_id(Employee*, int);
int set_nombre(Employee*, char*);
int set_horasTrabajadas(Employee*, int);
int set_sueldo(Employee*, int);

//getters
int get_id(Employee*);
char* get_nombre(Employee*);
int get_horasTrabajadas(Employee*);
int get_sueldo(Employee*);


#endif // employee_H_INCLUDED
