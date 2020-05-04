#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1



typedef struct
{
  int id;//PK
  char name[51];
  char lastName[51];
  float salary;
  int sector;//FK
  int isEmpty;
} eEmployee;


void MenuABM(eEmployee [], int );
void inicializarAlumnos(eEmployee [], int );
int getInt(char [], int , int );

 void setError(char [],int );
  /** \Recibe muestra un mensaje subrayado en rojo
 *
 * \char - Mensaje a mostrar
 * \int - flag que limpia la pantalla o no
 *
 */

 void setSucces(char [],int );
 /** \Recibe muestra un mensaje subrayado en verde
 *
 * \char - Mensaje a mostrar
 * \int - flag que limpia la pantalla o no
 *
 */
 float getFloat(char [], float , float );
/**
*-GetFloat pide ingresar un float y lo valida en los rangos establecidos en los parametro, al ponerle 0 a los rangos no lo valida
*
*-Char[]-mensaje de ingreso del dato
*-Float - el rango minimo a validar
*-Float - el rango maximo a validar
*-Float - devuelve el valor validado
*/
int addEmployee(Employee* list, int , int , char [],char [],float ,int );
/** \brief add in a existing list of employees the values received as parameters
*     in the first empty position
* \param list employee*
* \param len int * \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok *

*/
///////////////////////////////////////////////////////////////////////
