#include "MenuABM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>











void MenuABM(Mascota Mascota[], Cliente Cliente[])
{


 int opc;

 int id, telefono, edadCliente, idCliente,   lastIdCliente=5,lastIdMascota=110;
 char nombreCliente[51], Apellido[51], Localidad[51], sexo;
 int idMascota, edadMascota, sexoMascota;
 char nombreMascota[51], tipoMascota[51], razaMascota[51];
 float pesoMascota;







        if(initCliente(Cliente,C)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }

        hardCodearClientes(Cliente,C);

        if(initMascota(Mascota,M)==0)
        {
            //setSucces("Inicializado con exito",1);

        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }

        hardCodearMascotas(Mascota,M);


    while(opc!=0)
    {
        setSucces("MENU PRINCIPAL",0);
        printf("1)Agregar Cliente\n");
        printf("2)Ordenar Mascotas por tipo y listarla por dueño\n");
        printf("3)Eliminar Cliente\n");
        printf("4)Imprimir Clientes\n");
        printf("5)Agregar Mascota\n");
        printf("6)Modificar Mascota\n");
        printf("7)Eliminar Mascota\n");
        printf("8)Imprimir Mascotas\n");
        printf("9)Imprimir Clientes con mascotas\n");
        printf("0)Salir\n");
      opc=getInt("Seleccione una opcion:",0,15);

      switch(opc)
      {
            case 1://alta dueño
                break;
            case 2:
                printMascotasOrderedByTipo(Mascota,Cliente);
                break;
            case 3:
                printClientes(Cliente,C);
                idCliente=getInt("Ingrese el ID a eliminar",0,0);
                if(findClienteById(Cliente,C,idCliente)!= -1)
                {
                    if(removeCliente(Cliente,Mascota,idCliente)!= -1)
                    {
                        setSucces("Eliminado correctamente",0);
                    }else
                    {
                        setError("No se pudo eliminar",0);
                    }
                }else
                {
                    setError("ID de cliente no encontrado.",0);
                }
                break;
            case 4:
                printClientes(Cliente,C);
                break;
            case 5:
                printClientes(Cliente,C);
                idCliente=getInt("Ingrese el id de CLIENTE:",0,0);
                if(findClienteById(Cliente,C,idCliente)!= -1)
                {
                    idMascota=generateIdMascota(Mascota,M,lastIdMascota);
                    getString("Ingrese el nombre de la MASCOTA",nombreMascota);
                    getString("Ingrese el tipo de la MASCOTA",tipoMascota);
                    getString("Ingrese la raza de la MASCOTA",razaMascota);
                    edadMascota=getInt("Ingrese la edad de la MASCOTA:",0,0);
                    pesoMascota=getFloat("Ingrese el peso de la MASCOTA:",0,0);
                    printf("Ingrese el sexo de la MASCOTA (F o M)\n");
                    fflush(stdin);
                    scanf("%c",&sexoMascota);
                    sexoMascota=toupper(sexoMascota);
                if(addMascota(Mascota,  M,  idMascota,  nombreMascota, tipoMascota, razaMascota, edadMascota, pesoMascota, sexoMascota, idCliente)==0)
                {
                    setSucces("Mascota agregada exitosamente,",0);

                }else
                {
                    setError("No se pudo agregar la MASCOTA",0);
                }

               }else
               {
                   setError("No se encontro el cliente",0);
               }
                break;

            case 6://modificar mascota
                printMascotas(Mascota,Cliente);
                idMascota=getInt("Ingrese la mascota a modificar.",0,0);
                if(modifyMascota(Mascota,M,idMascota)==0)
                {
                 setSucces("Modificada correctamente",0);
                }else
                {
                    setError("No se pudo eliminar.",0);
                }
                break;
            case 7://eliminar mascota
                printMascotas(Mascota,Cliente);
                idMascota=getInt("Ingrese la mascota a eliminar.",0,0);
                if(removeMascota(Mascota,M,idMascota)==0)
                {
                 setSucces("Eliminada correctamente",0);
                }else
                {
                    setError("No se pudo eliminar.",0);
                }

                break;
            case 8:
                printMascotas(Mascota,Cliente);
                break;
            case 9:
                printClientesMascotas(Cliente,Mascota);
                break;


      }
        system("pause");
      system("cls");
      }

}
