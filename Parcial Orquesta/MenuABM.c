#include "MenuABM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>











void MenuABM(Orquesta Orquesta[], Instrumento Instrumento[], Musico Musico[], int tam)
{
    int opc, id, edadMusico, idOrquesta, idInstrumento, idMusico,   lastIdMusico=5,lastIdOrquesta=105,lastIdInstrumento=1005;
int idTipoOrquesta;


    char nombreMusico[51],apellidoMusico[51],nombreOrquesta[51],lugarOrquesta[51],nombreInstrumento[51];

        if(initOrquesta(Orquesta,tOrquesta)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }
        if(initMusico(Musico,tMusico)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }
        if(initInstrumento(Instrumento,tInstrumento)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }
        hardCodearMusicos(Musico,tMusico);
        hardCodearOrquesta(Orquesta,tOrquesta);
       hardCodearInstrumentos(Instrumento, tInstrumento);

    while(opc!=0)
    {
        printf("1).Agregar Orquesta\n");
        printf("2).Eliminar Orquesta\n");
        printf("3).Imprimir Orquestas\n");
        printf("4).Agregar Musico\n");
        printf("5).Modificar Musico\n");
        printf("6).Eliminar Musico\n");
        printf("7).Imprimir Musicos\n");
        printf("8).Agregar Instrumento\n");
        printf("9).Imrimir Instrumentos\n");
        printf("10).Informes\n");
        printf("0)Salir\n");
      opc=getInt("Seleccione una opcion:",0,10);

      switch(opc)
      {
            case 1:
                        lastIdOrquesta=generateIdOrquesta(Orquesta,tOrquesta,lastIdOrquesta);
                        if(lastIdOrquesta!=-1)
                        {

                        idOrquesta=lastIdOrquesta;
                        getString("Ingrese el nombre: ",nombreOrquesta);
                        getString("Ingrese el lugar: ",lugarOrquesta);
                        idTipoOrquesta=getInt("Ingrese el tipo de orquesta: ", 0,0);

                        if(addOrquesta(Orquesta,tOrquesta, idOrquesta,nombreOrquesta,lugarOrquesta,idTipoOrquesta)==-1)
                        {
                            setError("No se pudo agregar",0);
                        }
                           printOrquestas(Orquesta,tOrquesta);

                        }else
                        {
                                setError("No se encontro lugar disponible",0);
                        }

                break;
            case 2:
                printOrquestas(Orquesta,tOrquesta);
                id=getInt("Ingrese el ID a eliminar.",0,0);

                if(removeOrquesta(Orquesta,tOrquesta, id)==-1)
                 {
                            setError("No se encontro el ID a eliminar",0);
                    }else
                    {
                        if(removeMusicoByOrquestaID(Musico,tMusico, id)==-1)
                        {
                            setError("No se encontraron musicos de la orquesta seleccionada, solo se elimino la orquesta",0);
                        }
                    }

                break;
            case 3:
                printOrquestas(Orquesta,tOrquesta);

                break;
            case 4:

                        lastIdMusico=generateIdMusico(Musico,tam,lastIdMusico);

                        if(lastIdMusico!= -1)
                        {


                        idMusico=lastIdMusico;
                        getString("Ingrese el nombre: ",nombreMusico);
                        getString("Ingrese el apellido: ",apellidoMusico);
                        edadMusico=getInt("Ingrese LA EDAD: ", 0,0);
                        idOrquesta=getInt("Ingrese la orquesta: ",0,0);
                        idInstrumento=getInt("Ingrese el instrumento: ",0,0);
                       if(addMusico(Musico,tam, idMusico,nombreMusico,apellidoMusico,edadMusico,idOrquesta, idInstrumento)==-1)
                        {
                            setError("No se pudo agregar",0);
                        }
                       printMusicos(Musico,tMusico);
                       }else
                       {
                           setError("No se encontro lugar disponible",0);
                       }

                break;
            case 5:printMusicos(Musico,tMusico);
                idMusico=getInt("Ingrese el musico a modificar:",0,0);
                if(modifyMusico(Musico, tMusico,idMusico)==-1)
                {
                            setError("No se encontro el ID a modificar",0);
                    }
                break;
                case 6:
                    printMusicos(Musico,tMusico);
                id=getInt("Ingrese el ID a eliminar.",0,0);

                if(removeMusico(Musico,tMusico, id)==-1)
                {
                            setError("No se encontro el ID a eliminar",0);
                }
                break;
                case 7:
                 printMusicos(Musico,tMusico);
                break;
                case 8:
                       lastIdInstrumento=generateIdInstrumento(Instrumento,tInstrumento,lastIdInstrumento);

                            if(lastIdInstrumento!= -1)
                            {
                                idInstrumento=lastIdInstrumento;
                                getString("Ingrese el nombre del instrumento: ",nombreInstrumento);
                                if(addInstrumento(Instrumento,tInstrumento, idInstrumento,nombreInstrumento)==-1)
                                 {
                                        setError("No se pudo agregar",0);
                                    }

                                printInstrumentos(Instrumento,tInstrumento);
                            }else
                       {
                           setError("No se encontro lugar disponible",0);
                       }

                break;
                case 9:
                 printInstrumentos(Instrumento,tInstrumento);
                break;
                case 10:
                    system("cls");
                    printf("1).Orquesta con ams de 3 musicos\n");
                    printf("2).Orquesta por lugar\n");
                    printf("3).Musico por id de ORQUESTA\n");
                    printf("4).Orquesta con mas musicos\n");
                    printf("5).\n");
                    opc=getInt("Ingrese el informe deseado",1,5);
                    switch(opc)
                    {
                    case 1:
                        informeOrquesta5musicos(Orquesta,Musico);
                        break;
                    case 2:
                        informeOrquestaByLugar(Orquesta);
                        break;
                    case 3:
                        informeMusicoByOrquesta(Orquesta,Musico);
                        break;
                    case 4:
                        informeOrquestaMasMusicos(Orquesta,Musico);
                        break;
                    case 5:

                        break;
                    }

                break;

      }
        system("pause");
      system("cls");
      }

}
