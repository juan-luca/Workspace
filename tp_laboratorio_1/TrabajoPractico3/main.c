#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "generalcommands.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* pArrayListEmployee = ll_newLinkedList();





    /**********************************************************************/
    int i;
      int opc;

    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);





    do
    {
        printf("\n");
      linea(50);
      printf("\n");
     printf(" Menu:");
     printf("\n");
      linea(50);
      printf("\n");
     printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
     printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
     printf("3. Alta de empleado\n");
     printf("4. Modificar datos de empleado\n");
     printf("5. Baja de empleado\n");
     printf("6. Listar empleados\n");
     printf("7. Ordenar empleados\n");
     printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
     printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
     printf("0. Salir\n");
      opc=getInt("Seleccione una opcion:",0,9);

      printf("\n");
      linea(112);
      printf("\n");

      switch(opc)
      {
            case 1:////carga mediante texto



                if(controller_loadFromText("data.csv",pArrayListEmployee)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);

                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.csv este en el root",0);
                }

                break;
            case 2://carga mediante binary text

                if(controller_loadFromBinary("data.dat",pArrayListEmployee)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);

                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.dat este en el root",0);
                }

                break;
            case 3://ALTA EMPLEADO
                if(controller_addEmployee(pArrayListEmployee)==-1)
                {
                    setError("No se pudo agregar el empleado",0);
                }

                break;
            case 4:



            break;

            case 6:

                if(controller_ListEmployee(pArrayListEmployee)==-1)
                {
                    setError("No se pudo listar los empleados",0);
                }

            break;


      }
        system("pause");
      system("cls");
      }while(opc!=0);
      /**********************************************************************/
    /*e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);



    size = ll_len(miLista);


    ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }*/

/*    printf("Remuevo 1\n");

    ll_remove(miLista, 1);

    size = ll_len(miLista);
    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("El indice de e2 es: %d\n", ll_indexOf(miLista,e3));
    */



    return 0;
}
