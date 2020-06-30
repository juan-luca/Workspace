#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define C 10
#define M 20
#define TM 3
#define R 7

#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

int getInt(char [], int , int );
/**
*-GetInt pide ingresar un INT y lo valida en los rangos establecidos en los parametro, al ponerle 0 a los rangos no lo valida
*
*-Char[]-mensaje de ingreso del dato
*-Int - el rango minimo a validar
*-Int - el rango maximo a validar
*-Int - devuelve el valor validado
*/
int getIntPos(char []);
/**
*-GetIntPos Es una variacion de getInt() la cual solo valida que el numero sea postivo (>0)
*
*-Char[]-mensaje de ingreso del dato
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

void linea(int);
/**
*-draw a line color 238
int amount of spaces
*/
void lineaRGB(int,int);
/**
*-draw a line with the indicated color
int amount of spaces
int color
*/
void columna();
/**
*-draw a column color 238
*/

char getGender(char [] );
/**
*-GetGender valida el caracter ingresado por F o M y los guarda siempre en mayuscula
*
*-Char[]-mensaje de ingreso del dato
*-return char - variable a guardar el caracter validado
*/
