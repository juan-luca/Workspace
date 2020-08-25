
int getInt(char [], int , int );
/**
*-GetInt pide ingresar un INT y lo valida en los rangos establecidos en los parametro, al ponerle 0 a los rangos no lo valida
*
*-Char[]-mensaje de ingreso del dato
*-Int - el rango minimo a validar
*-Int - el rango maximo a validar
*-Int - devuelve el valor validado
*/
void getString(char [], char []);
/**
*-GetString valida la cadena ingresada y pide rellarla con la cadena ingresada
*
*-Char[]-mensaje de ingreso del dato
*-char[] - variable a guardar la cadena
*/


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
*-Return - devuelve el valor validado
*/

void linea();
/**
*-draw a 110 space line color 238
*/
