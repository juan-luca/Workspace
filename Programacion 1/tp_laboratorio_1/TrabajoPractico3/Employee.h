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
/**
*-Reserve space of memory
*-Return the dir of the reserved space
*/
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr);
/**
*-Reserve space of memory
*-int - Id
*-char* - pointer of name
*-int - HorasTrabajadas
*-int - Sueldo
*-Return the dir of the reserved space
*/



int employee_CompareByName(void* e1, void* e2);
/**
*-Compare names of 2 pointer to Employee
*-void* - Pointer to employee 1
*-void* - Pointer to employee 2
*-Return the ascii diference
*/
int employee_CompareById(void* e1, void* e2);
/**
*-Compare Id of 2 pointer to Employee
*-void* - Pointer to employee 1
*-void* - Pointer to employee 2
*-Return the bigger position
*/
int employee_getId(Employee* employee,int* );
/**
*-Get Id of 1 pointer to Employee
*-Employee* - Pointer to employee
*-int* - Pointer to the Id variable
*-Return 0 if OK or -1 if an error encounter
*/
int employee_getNombre(Employee* employee,char* );
/**
*-Get Name of 1 pointer to Employee
*-Employee* - Pointer to employee
*-char* - Pointer to the name variable
*-Return 0 if OK or -1 if an error encounter
*/
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajdas);
/**
*-Get Horas of 1 pointer to Employee
*-Employee* - Pointer to employee
*-int* - Pointer to the horas trabajadas variable
*-Return 0 if OK or -1 if an error encounter
*/
int employee_getSueldo(Employee* employee,int* );
/**
*-Get Sueldo of 1 pointer to Employee
*-Employee* - Pointer to employee
*-int* - Pointer to the sueldo variable
*-Return 0 if OK or -1 if an error encounter
*/
int employee_setNombre(Employee* employee,char* );
/**
*-Set Name of 1 pointer to Employee
*-Employee* - Pointer to employee
*-char* - Pointer to the Name
*-Return 0 if OK or -1 if an error encounter
*/
int employee_setSueldo(Employee* employee,int sueldo);
/**
*-Set Sueldo of 1 pointer to Employee
*-Employee* - Pointer to employee
*-int* - Pointer to the sueldo
*-Return 0 if OK or -1 if an error encounter
*/
int employee_setId(Employee* employee,int id);
/**
*-Set id of 1 pointer to Employee
*-Employee* - Pointer to employee
*-int* - Pointer to the id
*-Return 0 if OK or -1 if an error encounter
*/
int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);
/**
*-Set horas of 1 pointer to Employee
*-Employee* - Pointer to employee
*-int* - Pointer to the horas
*-Return 0 if OK or -1 if an error encounter
*/


#endif // employee_H_INCLUDED
