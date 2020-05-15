#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

#include "GeneralCommands.h"

typedef struct
{
  int id;//PK
  char name[51];
  char lastName[51];
  float salary;
  int sector;//FK
  int isEmpty;
} eEmployee;
int salaryQuery(eEmployee [], int );
/** \brief Print  average of salary and amount of employees have that or superior
* * \param list Employee
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */
int sortEmployees(eEmployee [], int , int );

/** \brief Sort the elements in the array of employees, the argument order indicate UP(1) or DOWN (2) order
* * \param list Employee
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */


void hardCodearEmpleados(eEmployee listado[], int tam);
void MenuABM(eEmployee [], int );
/** \brief put in 0 (empty) all positions of blank array
* * \param list Employee
* \param lenght int */
int inicializarAlumnos(eEmployee [], int );
/** \brief put in 0 (empty) all positions of blank array
* * \param list Employee
* \param lenght int
* \return Return 0 ok or (-1) if [Invalid length or NULL list received or employee not found] * */
int findEmployeeById(eEmployee [], int , int );
/** \brief find an Employee by Id en returns the index position in array.
* * \param list Employee
* \param lenght int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL list received or employee not found] * */
int generateIdEmployee(eEmployee [], int , int );
/** \brief generate an the first id empty
* * \param list Employee
* \param lenght int
* \param id int
* \return Return the first id empty or (-1) if the array is busy* */
int removeEmployee(eEmployee [], int , int );
/** \brief Remove a Employee by Id (put isEmpty Flag in -1)
* * \param list Employee
* * \param lenght int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL list or if can't find a employee] - (0) if Ok * */
int modifyEmployee(eEmployee [],int , int);
/** \brief Modify an employee specifying the received ID as paramete
* * \param list Employee
* * \param lenght int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL list or if can't modify a employee] - (0) if Ok * */
int printOneEmployee(eEmployee [], int , int );
/** \brief Print an employee specifying the received ID as parameter
* * \param list Employee
* * \param length int
* \return int Return (-1) if Error [Invalid length or NULL list or if can't print any employee] - (0) if Ok * */
int printEmployees(eEmployee [], int  );
/** \brief print the all content of employees array
* * \param list Employee
* * \param length int
* \return int Return (-1) if Error [Invalid length or NULL list or if can't print any employee] - (0) if Ok * */


int addEmployee(eEmployee [], int , int , char [],char [],float ,int );
/** \brief add in a existing list of employees the values received as parameters
*     in the first empty position
* \param list employee
* \param lenght int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL list or without free space] - (0) if Ok *

*/
///////////////////////////////////////////////////////////////////////
