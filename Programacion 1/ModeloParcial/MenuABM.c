#include "MenuABM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

#define tOrquesta 5
#define tTipoOrquesta 3
#define tMusico 5
#define tInstrumento 10








void MenuABM(Orquesta Orquesta[], Instrumento Instrumento[], Musico Musico[], int tam)
{
    int opc, id, edadMusico, idOrquesta, idInstrumento, idMusico, columnaModificar, succesAdd=1, lastIdMusico=1,lastIdOrquesta=100,lastIdInstrumento=1000;
int idTipoOrquesta;

    int i;
    char nombreMusico[51],apellidoMusico[51],nombreOrquesta[51],lugarOrquesta[51],nombreInstrumento[51];

        if(initOrquesta(Orquesta,tam)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }
        if(initMusico(Musico,tam)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }
        if(initInstrumento(Instrumento,tam)==0)
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
                        addOrquesta(Orquesta,tOrquesta, idOrquesta,nombreOrquesta,lugarOrquesta,idTipoOrquesta);
                           printOrquestas(Orquesta,tOrquesta);

                        }else
                        {
                                setError("No se encontro lugar disponible",0);
                        }

                break;
            case 2:
                id=getInt("Ingrese el ID a eliminar.",0,0);
                removeOrquesta(Orquesta,tOrquesta, id);

                break;
            case 3:
                printOrquestas(Orquesta,tOrquesta);

                break;
            case 4:
                        lastIdMusico=generateIdMusico(Musico,tam,lastIdMusico);
                        if(lastIdMusico=!-1)
                        {


                        idMusico=lastIdMusico;
                        getString("Ingrese el nombre: ",nombreMusico);
                        getString("Ingrese el apellido: ",apellidoMusico);
                        edadMusico=getInt("Ingrese LA EDAD: ", 0,0);
                        idOrquesta=getInt("Ingrese la orquesta: ",0,0);
                        idInstrumento=getInt("Ingrese el instrumento: ",0,0);
                       addMusico(Musico,tam, idMusico,nombreMusico,apellidoMusico,edadMusico,idOrquesta, idInstrumento);
                       printMusicos(Musico,tMusico);
                       }else
                       {
                           setError("No se encontro lugar disponible",0);
                       }

                break;
            case 5:
                idMusico=getInt("Ingrese el musico a eliminar:",0,0);
                modifyMusico(Musico, tMusico,idMusico);
                break;
                case 6:
                id=getInt("Ingrese el ID a eliminar.",0,0);
                removeMusico(Musico,tMusico, id);
                break;
                case 7:
                 printMusicos(Musico,tMusico);
                break;
                case 8:
                       lastIdInstrumento=generateIdInstrumento(Instrumento,tam,lastIdInstrumento);

                        idInstrumento=lastIdInstrumento;
                        getString("Ingrese el nombre del instrumento: ",nombreInstrumento);
                       addInstrumento(Instrumento,tam, idInstrumento,nombreInstrumento);
                       printInstrumentos(Instrumento,tInstrumento);
                break;
                case 9:
                 printInstrumentos(Instrumento,tInstrumento);
                break;
                case 10:

                break;

      }
        system("pause");
      system("cls");
      }

}
