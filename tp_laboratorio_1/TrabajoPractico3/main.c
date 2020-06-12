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
 Employee* employee;




    /**********************************************************************/
    int i;
      int opc;
      int flagCarga=-1;

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

                if(flagCarga==1)
                {
                ll_deleteLinkedList(pArrayListEmployee);
                pArrayListEmployee = ll_newLinkedList();
                }


                if(controller_loadFromText("data.csv",pArrayListEmployee)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);
                    flagCarga=1;

                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.csv este en el root",0);
                }

                break;
            case 2://carga mediante binary text


                if(flagCarga==1)
                {
                ll_deleteLinkedList(pArrayListEmployee);
                pArrayListEmployee = ll_newLinkedList();
                }

                if(controller_loadFromBinary("data.bin",pArrayListEmployee)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);
                    flagCarga=1;

                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.dat este en el root",0);
                }

                break;
            case 3://ALTA EMPLEADO
                if(flagCarga==1)
                {


                    if(controller_addEmployee(pArrayListEmployee)!=0)
                    {
                        setError("No se pudo agregar el empleado",0);
                    }else
                    {
                        setSucces("Empleado agregado con exito.",0);
                    }
                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }

                break;
                case 4://EDIT EMPLEADO
                if(flagCarga==1)
                {


                    if(controller_editEmployee(pArrayListEmployee)!=0)
                    {
                        setError("No se pudo modificar el empleado",0);
                    }else
                    {
                        setSucces("Empleado modificado con exito.",0);
                    }
                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }




            break;
            case 5://BAJA EMPLEADO
                if(flagCarga==1)
                {


                      if(controller_removeEmployee(pArrayListEmployee)!=0)
                        {
                            setError("No se pudo eliminar el empleado",0);
                        }else
                        {
                            setSucces("Empleado eliminado con exito.",0);
                        }
                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }




            break;

            case 6:
                 if(flagCarga==1)
                {

                     if(controller_ListEmployee(pArrayListEmployee)==-1)
                    {
                        setError("No se pudo listar los empleados",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }


            break;
            case 7:
                 if(flagCarga==1)
                {
                    if(controller_sortEmployee(pArrayListEmployee)==-1)
                        {
                            setError("No se pudo ordenar los empleados",0);
                        }else
                        {
                            setSucces("Se realizo correctamente el ordenamiento.",0);
                        }





                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;
            case 8:
                 if(flagCarga==1)
                {



                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;
            case 9:


                 if(flagCarga==1)
                {



                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;


      }
        system("pause");
      system("cls");
      }while(opc!=0);
      /**********************************************************************/



    return 0;
}
