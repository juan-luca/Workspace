#define tOrquesta 50
#define tTipoOrquesta 3
#define tMusico 1000
#define tInstrumento 20

#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
int getInt(char [], int , int );
void getString(char [], char []);

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
void getStringUpper(char [], char []);

