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
    //caratula();
    system("cls");
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    LinkedList* pArrayListEmployee2 = NULL;





    /**********************************************************************/

      int opc;
      int flagCarga=-1;

      int from;
      int to;

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
     printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
     printf("10. Vaciar lista.\n");
     printf("11. Buscar empleado.\n");
     printf("12. Clonar lista a auxiliar.\n");
     printf("13. Clonar lista a auxiliar desde/hasta.\n");
     printf("---------------------- LISTA 2 ---------------------- \n");
     printf("14. Mostrar lista 2.\n");
     printf("15. Cargar los datos de los empleados desde el archivo data2.csv (modo texto) a la lista 2.\n");
     printf("16. Cargar los datos de los empleados desde el archivo data2.csv (modo binario) a la lista 2.\n");
     printf("17. Guardar los datos de los empleados en el archivo data2.csv (modo texto) de la lista 2.\n");
     printf("18. Guardar los datos de los empleados en el archivo data2.bin (modo binario) de la lista 2.\n");
     printf("19. Comparar listas.\n");

     printf("9. .\n");
     printf("0. Salir\n");
      opc=getInt("Seleccione una opcion:",0,20);

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
                    if(controller_saveAsText("data.csv", pArrayListEmployee)!=0)
                    {
                     setError("No se pudo guardar el archivo",0);
                    }else
                    {
                        setSucces("Guardado con exito.",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;
            case 9:


                 if(flagCarga==1)
                {
                    if(controller_saveAsBinary("data.bin", pArrayListEmployee)!=0)
                    {
                     setError("No se pudo guardar el archivo",0);
                    }else
                    {
                        setSucces("Guardado con exito.",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;


                case 10:


                if(flagCarga==1)
                {

                    if(ll_clear(pArrayListEmployee)!=-1)
                    {
                        setSucces("Vaciada con exito.",0);

                    }else
                    {
                        setError("No se pudo vaciar la lista.",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;




                case 11:


                 if(flagCarga==1)
                {
                    if(contains_employee(pArrayListEmployee)!=-1)
                    {


                    }else
                    {
                        setError("No se encontro el empleado en la lista.",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;

                case 12:


                 if(flagCarga==1)
                {

                    pArrayListEmployee2=ll_clone(pArrayListEmployee);

                    if(pArrayListEmployee2!=NULL)
                    {
                        setSucces("Clonada con exito.",0);

                    }else
                    {
                        setError("No se pudo clonar.",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;

                case 13:


                 if(flagCarga==1)
                {
                    from=getInt("Desde que posicion desea clonar",0,ll_len(pArrayListEmployee));
                    to=getInt("Hasta que posicion desea clonar",0,ll_len(pArrayListEmployee));

                    pArrayListEmployee2=ll_subList(pArrayListEmployee,from,to);

                    if(pArrayListEmployee2!=NULL)
                    {
                        setSucces("Clonada con exito.",0);

                    }else
                    {
                        setError("No se pudo clonar.",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 o 2",0);
                }
                break;

                case 14:
                 if(pArrayListEmployee2!=NULL)
                {

                     if(controller_ListEmployee(pArrayListEmployee2)==-1)
                    {
                        setError("No se pudo listar los empleados",0);
                    }


                }else
                {
                    setError("Primero debe cargar la segunda lista",0);
                }
                break;

                case 15:////carga mediante texto

                if(pArrayListEmployee2!=NULL)
                {
                ll_deleteLinkedList(pArrayListEmployee2);
                pArrayListEmployee2 = ll_newLinkedList();
                }else
                {
                    pArrayListEmployee2 = ll_newLinkedList();
                }


                if(controller_loadFromText("data2.csv",pArrayListEmployee2)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);


                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.csv este en el root",0);
                }

                break;
            case 16://carga mediante binary text


                 if(pArrayListEmployee2!=NULL)
                {
                ll_deleteLinkedList(pArrayListEmployee2);
                pArrayListEmployee2 = ll_newLinkedList();
                }else
                {
                    pArrayListEmployee2 = ll_newLinkedList();
                }

                if(controller_loadFromBinary("data2.bin",pArrayListEmployee2)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);
                    //flagCarga=1;

                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.dat este en el root",0);
                }

                break;
                case 17:
                 if(pArrayListEmployee2!=NULL)
                {
                    if(controller_saveAsText("data2.csv", pArrayListEmployee2)!=0)
                    {
                     setError("No se pudo guardar el archivo",0);
                    }else
                    {
                        setSucces("Guardado con exito.",0);
                    }


                }else
                {
                    setError("Primero debe cargar la segunda lista",0);
                }
                break;
            case 18:


                 if(pArrayListEmployee2!=NULL)
                {
                    if(controller_saveAsBinary("data2.bin", pArrayListEmployee2)!=0)
                    {
                     setError("No se pudo guardar el archivo",0);
                    }else
                    {
                        setSucces("Guardado con exito.",0);
                    }


                }else
                {
                    setError("Primero debe cargar la segunda lista",0);
                }
                break;

        case 19:


                 if(pArrayListEmployee2!=NULL && pArrayListEmployee!=NULL)
                {
                    printf("\n1 size %d",pArrayListEmployee->size);
                    printf("\n2 size %d",pArrayListEmployee2->size);
                    if(ll_containsAll(pArrayListEmployee,pArrayListEmployee2)==-1)
                    {
                     printf("|||| Listas diferentes |||| \n");
                    }else
                    {
                        setSucces("|||| Listas identicas |||| ",0);
                    }


                }else
                {
                    setError("Primero debe cargar la ambas listas",0);
                }
                break;




      }
        system("pause");
      system("cls");
      }while(opc!=0);
      /**********************************************************************/



    return 0;
}
