int esPar(int numero);
/**
*-esPar recibe un entero y valida su paridad
*
*-Int - el numero a validar su paridad
*-Int - devuelve el valor validado
*/
int getInt(char mensaje[], int min, int max);
/**
*-GetInt pide ingresar un entero y lo valida en los rangos establecidos en los parametro, al ponerle 0 a los rangos no lo valida
*
*-Char[]-mensaje de ingreso del dato
*-Int - el rango minimo a validar
*-Int - el rango maximo a validar
*-Int - devuelve el valor validado
*/
float getFloat(char mensaje[], float min, float max);
/**
*-GetFloat pide ingresar un float y lo valida en los rangos establecidos en los parametro, al ponerle 0 a los rangos no lo valida
*
*-Char[]-mensaje de ingreso del dato
*-Float - el rango minimo a validar
*-Float - el rango maximo a validar
*-Float - devuelve el valor validado
*/
char getChar(char mensaje[], char valida1, char valida2);
/**
*-GetChar pide ingresar un char y lo valida con 2 opciones posibles
*
*-Char[]-mensaje de ingreso del dato
*-Char - opcion 1 a comparar
*-Char - opcion 2 a comparar
*-Char - devuelve el valor ingresado y validado
*/
int factorialRecursivo(int numero);

/** \Recibe un valor entero y luego lo factorea recursivamente
 *
 * \Int - numero entero a factorizar
 * \return - resultado total del factoreo
 *
 */
 float sumar (float num[], int tam);
 /** \Recibe un array y suma todos los numeros del array
 *
 * \float - array a sumar
 \Int - tamaño del array
 * \return - resultado de la suma
 *
 */

 float restar (float num[], int tam);
/** \Recibe un array y resta todos los numeros del array
 *
 * \float - array a restar
 \Int - tamaño del array
 * \return - resultado de la resta
 *
 */

 float producto (float num[], int flotante, int tam);
 /** \Recibe un array y multiplica todos los numeros del array
 *
 * \float - array a multiplicar
 \Int - si es float o int
 \Int - tamaño del array
 * \return - resultado del producto
 *
 */

 float division (float num[]);
 /** \Recibe un array y divide el primero por el segundo
 *
 * \float - array a restar
 * \return - resultado de la division
 *
 */

 void mostrar(float suma, float resta, float prod, float divi, int factA, int factB, int flotante, int divisionCero, float fnumA, float fnumB);
  /** \Recibe los resultados y los muestra
 *
 * \float - resultado de la suma
 * \float - resultado de la resta
 * \float - resultado del producto
 * \float - resultado de la division
 * \int - resultado del factoreo A
 * \int - resultado del factoreo B
 * \int - flag si divide por 0 o no
 * \float - numero A
 * \float - numero B
 * ---- no retorna nada
 */

 void setError(char mensaje[],int clean);
  /** \Recibe muestra un mensaje subrayado en rojo
 *
 * \char - Mensaje a mostrar
 * \int - flag que limpia la pantalla o no
 *
 */

 void setSucces(char mensaje[],int clean);
 /** \Recibe muestra un mensaje subrayado en verde
 *
 * \char - Mensaje a mostrar
 * \int - flag que limpia la pantalla o no
 *
 */
int cargarVectorInt(int vector[], int tam);
 /** \Recibe un vector y pide al usuario cargar espacio por espacio
 *
 * \int - vector a ingresar
 * \int - tamaño del vector a ingresar
 *
 */
void mostrarVectorInt(int vector[], int tam);

int ordenarVectorInt(int vector[], int tam, char orden);

void getString(char dato[], char mensaje[]);

 void getStringUpper(char dato[], char mensaje[]);

