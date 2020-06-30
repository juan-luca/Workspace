#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Vuelos.h"
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

    system("cls");
    LinkedList* ll = NULL;
    LinkedList* pilotos_ll = NULL;
    LinkedList* cortos_ll = ll_newLinkedList();
    LinkedList* portugal_ll = ll_newLinkedList();
    LinkedList* noAlex_ll = ll_newLinkedList();
    LinkedList* filterby_piloto = ll_newLinkedList();

    //CargarPilotos(pilotos_ll);







    /**********************************************************************/

      int opc;
        char nombrePiloto[128];

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
    printf("\n1)	Cargar archivo: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.\n");
    printf("2)	Imprimir vuelos: Se imprimirá por pantalla la tabla con los datos de los vuelos indicando el nombre del piloto (no el número)\n");
    printf("3)	Cantidad de pasajeros: Cantidad de pasajeros totales\n");
    printf("4)	Cantidad de pasajeros  a Irlanda: cantidad de pasajeros a irlanda.\n");
    printf("5)	Filtrar vuelos cortos: Generar un archivo de iguales características que el original, con los datos de los vuelos cuya duración sea inferior a 3 horas.\n");
    printf("6)	Listar vuelos a Portugal: Generar un listado que solo incluya los vuelos con destino a Portugal.\n");
    printf("7)	Filtrar a Alex Lifeson: Necesitamos un listado de vuelos que no incluya al chofer Alex Lifeson\n");
    //printf("8)	Guardar pilotos en pilotos.csv.\n");
    printf("8)	Cargar pilotos desde archivo\n");
    printf("9)	Listar pilotos por nombre\n");
     printf("0. Salir\n");
      opc=getInt("Seleccione una opcion:",0,15);

      printf("\n");
      linea(112);
      printf("\n");

      switch(opc)
      {
            case 1:

                if(ll!=NULL)
                {
                ll_deleteLinkedList(ll);

                }

                ll = ll_newLinkedList();
                if(controller_SantoliquidoloadFromText("vuelos.csv",ll)!=-1)
                {

                    setSucces("Carga realizada exitosamente",0);


                }else
                {
                    setError("No se pudo realizar la carga del archivo, verifique que el data.csv este en el root",0);
                }

                break;
            case 2:


                if(ll!=NULL && pilotos_ll!=NULL)
                {

                    if(controller_SantoliquidoListVuelos(ll,pilotos_ll)!=-1)
                    {




                    }else
                    {
                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1 y 9",0);
                }

                break;
            case 3:
                if(ll!=NULL)
                {

                        if(ll_count(ll,controller_Santoliquidocount)!=-1)
                    {

                        printf("\nCantidad de pasajeros totales: %d\n",ll_count(ll,controller_Santoliquidocount));


                    }else
                    {
                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                    }


                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }

                break;
                case 4:
                if(ll!=NULL)
                {

                    if(ll_count(ll,controller_Santoliquidocount_irlanda)!=-1)
                    {

                        printf("\nCantidad de pasajeros a irlanda: %d\n",ll_count(ll,controller_Santoliquidocount_irlanda));


                    }else
                    {
                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                    }

                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }




            break;

            case 5:
                if(ll!=NULL)
                {
                    cortos_ll=ll_filter(ll,controller_SantoliquidoShortFilter);


                            if(controller_SantoliquidosaveAsTextShort("cortos.csv",cortos_ll)!=-1)
                            {

                                setSucces("Carga realizada exitosamente",0);
                                 if(controller_SantoliquidoListVuelos(cortos_ll,pilotos_ll)!=-1)
                                    {




                                    }else
                                    {
                                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                                    }


                            }else
                            {
                                setError("No se pudo guardar el archivo",0);
                            }

                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }




            break;

            case 6:
                 if(ll!=NULL)
                {
                    portugal_ll=ll_filter(ll,controller_SantoliquidoPortugalFilter);



                                 if(controller_SantoliquidoListVuelos(portugal_ll,pilotos_ll)!=-1)
                                    {




                                    }else
                                    {
                                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                                    }



                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }


            break;
            case 7:
                 if(ll!=NULL)
                {


                    noAlex_ll=ll_filter(ll,controller_SantoliquidoAlexFilter);



                                 if(controller_SantoliquidoListVuelos(noAlex_ll,pilotos_ll)!=-1)
                                    {




                                    }else
                                    {
                                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                                    }




                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }
                break;
/***********GUARDAR PILOTOS
            case 8:
                if(pilotos_ll!=NULL)
                {



                            if(controller_SantoliquidosaveAsTextPilotos("pilotos.csv",pilotos_ll)!=-1)
                            {

                                setSucces("Guardado realizado exitosamente",0);

                            }else
                            {
                                setError("No se pudo guardar el archivo",0);
                            }

                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }




            break;

            *////////////////////
            case 8:


                pilotos_ll = ll_newLinkedList();

                            if(controller_SantoliquidoloadFromTextPilotos("pilotos.csv",pilotos_ll)!=-1)
                            {

                                setSucces("Cargado realizado exitosamente",0);

                            }else
                            {
                                setError("No se pudo cargar el archivo",0);
                            }








            break;
            case 9:


                        if(pilotos_ll!=NULL && ll!=NULL)
                        {


                            if(controller_SantoliquidoListPilotos(pilotos_ll)!=-1)
                            {
                                    getString("Ingrese el nombre del piloto que desa buscar",nombrePiloto);



                                    filterby_piloto=ll_filter_parametro(pilotos_ll,controller_SantoliquidoFilterByPiloto,nombrePiloto);

                                    if(controller_SantoliquidoListPilotos(filterby_piloto)!=-1)
                                    {




                                    }else
                                    {
                                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                                    }


                            }else
                            {
                                setError("No se pudo listar los pilotos",0);
                            }



                        }else
                        {
                            setError("Primero debe cargar los archivos de datos en la opcion 1 y 9",0);
                        }


            break;
            case 11:
            if(ll!=NULL)
                {


                    //filterby_piloto=ll_filter(ll,controller_SantoliquidoAlexFilter);



                                 if(controller_SantoliquidoListVuelos(filterby_piloto,pilotos_ll)!=-1)
                                    {




                                    }else
                                    {
                                        setError("No se pudo realizar el listado, el archivo introducido esta corrupto",0);
                                    }




                }else
                {
                    setError("Primero debe cargar los archivos de datos en la opcion 1",0);
                }
                break;





      }
        system("pause");
      system("cls");
      }while(opc!=0);
      /**********************************************************************/



    return 0;
}
