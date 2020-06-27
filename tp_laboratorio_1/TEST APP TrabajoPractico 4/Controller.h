#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/**
*-Create the file and execute the parser loader text file
*
*-Char* - path of file
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/**
*-Create the file and execute the parser loader Binary File
*
*-Char* - path of file
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/
int controller_lastId(LinkedList* pArrayListEmployee);
/**
*-Search the last id and return that
*
*-LinkedList* - Linkedlist to save text
*-return last id
*/
int controller_addEmployee(LinkedList* pArrayListEmployee);
/**
*-Add an new employee to linkedlist
*
*-LinkedList* - Linkedlist to add employee
*-return 0 if OK or -1 if an error encounter
*/
int controller_editEmployee(LinkedList* pArrayListEmployee);
/**
*-Edit an  employee in linkedlist
*
*-LinkedList* - Linkedlist to edit an employee
*-return 0 if OK or -1 if an error encounter
*/
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/**
*-Remove an  employee in the linkedlist
*
*-LinkedList* - Linkedlist to remove the employee selected
*-return 0 if OK or -1 if an error encounter
*/
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/**
*-List all employees saved in the linked list
*
*-LinkedList* - Linkedlist to search employees
*-return 0 if OK or -1 if an error encounter
*/
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/**
*-Sort the employees by any criterion
*
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/**
*-Save the linked list on text file
*char* path of file
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/**
*-Save the linked list on binary file
*char* path of file
*-LinkedList* - Linkedlist to save text
*-return 0 if OK or -1 if an error encounter
*/
void cabecera();
/**
*-Print on screen the columns
*/
int contains_employee(LinkedList* pArrayListEmployee);

