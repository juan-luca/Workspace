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
 float sumar (float n1, float n2, int flotante);

 float restar (float n1, float n2, int flotante);

 float producto (float n1, float n2, int flotante);

 float division (float n1, float n2);

 void mostrar(float suma, float resta, float prod, float divi, int factA, int factB, int flotante, int divisionCero, float fnumA, float fnumB);
