#include "MenuABM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>











void MenuABM(Mascota Mascota[], Cliente Cliente[], TipoMascota TipoMascota[], Raza Raza[])
{


 int opc;

 int  telefonoCliente, edadCliente, idCliente,   lastIdCliente=5,lastIdMascota=110;
 char nombreCliente[51], ApellidoCliente[51], LocalidadCliente[51], sexoCliente;
 int idMascota, edadMascota, idTipo, idRaza;
 char nombreMascota[51],   sexoMascota;
 float pesoMascota;
/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
for(int k = 1; k < 255; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    printf("%d COLOR\n");
  }
  system("pause");

*///-----PALETA DE COLORES



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
        CargarTipoMascotas(TipoMascota,TM);
        hardCodearMascotas(Mascota,M);
        CargarRaza( Raza);
            //printRazaMascota(Raza);
//printClientes(Cliente,C);
 //system("pause");

        do
        {


        setSucces("MENU PRINCIPAL",0);
        printf("1)Agregar Cliente\n");
        printf("2)Modificar Cliente\n");
        printf("3)Eliminar Cliente\n");
        printf("4)Imprimir Clientes\n");
        printf("5)Agregar Mascota\n");
        printf("6)Modificar Mascota\n");
        printf("7)Eliminar Mascota\n");
        printf("8)Imprimir Mascotas\n");
        printf("9)Imprimir Clientes con mascotas\n");
        printf("10)Ordenar Mascotas por tipo y listarla por cliente\n");
        printf("11)Listar los clientes con más de una mascota\n");
        printf("12)Listar las mascotas de mas de tres anios, con respectivos clientes.\n");
        printf("13)Listar las mascotas por un tipo en particular\n");
        printf("14)Ordenar a los clientes por cantidades de mascotas y mostrarlos.\n");
        printf("15)Ordenar a los clientes por cantidades de mascotas y por orden alfabético de los nombres y mostrarlos.\n");
        printf("16)Promedio de edad entre las mascotas\n");
        printf("17)Promedio de edad entre las mascotas, por tipo\n");
        printf("18)Promedio entre varones y mujeres de mis clientes\n");
        printf("19)listar los clientes que tienen mascotas del mismo sexo.\n");



        printf("0)Salir\n");
      opc=getInt("Seleccione una opcion:",0,19);

        lineaRGB(179,51);
        printf("\n");
      switch(opc)//FALTA BORRAR MENU Y DEJAR ENCASILLADA SOLO LA OPCION ELEGIDA
      {
            case 1:


                    idCliente=generateIdCliente(Cliente,M,lastIdCliente);
                    lastIdCliente=idCliente;
                    getString("Ingrese el nombre del  Cliente",nombreCliente);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    getString("Ingrese el apellido del Cliente",ApellidoCliente);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    getString("Ingrese la localidad del  Cliente",LocalidadCliente);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    telefonoCliente=getInt("Ingrese el telefono del  Cliente:",0,0);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    edadCliente=getInt("Ingrese la edad del  Cliente:",0,0);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    sexoCliente=getGender("Ingrese el sexo del Cliente (F o M)");

                if(addCliente(Cliente,  C,  idCliente,  nombreCliente, ApellidoCliente, LocalidadCliente, telefonoCliente, edadCliente, sexoCliente)==0)
                {
                    setSucces("Cliente agregado exitosamente,",0);

                }else
                {
                    setError("No se pudo agregar la Cliente",0);
                }


                break;
            case 2:
                printClientes(Cliente,C);
                idCliente=getInt("Ingrese el Cliente a modificar.",0,0);
                if(modifyCliente(Cliente,C,idCliente)==0)
                {
                 setSucces("Modificado correctamente",0);
                }else
                {
                    setError("No se pudo modificar.",0);
                }
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
                    lastIdMascota=idMascota;
                    getString("Ingrese el nombre de la MASCOTA",nombreMascota);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    printTiposMascota(TipoMascota,TM);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    idTipo=getInt("Ingrese el tipo de la MASCOTA",1,3);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    printf("\n");
                    printRazaMascota(Raza);
                    idRaza=getInt("Ingrese el id de raza de la MASCOTA",1,R);//VERIFICAR ID DE TABLA
                    printf("\n");
                    linea(179);
                    printf("\n");
                    edadMascota=getInt("Ingrese la edad de la MASCOTA:",0,0);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    pesoMascota=getFloat("Ingrese el peso de la MASCOTA:",0,0);
                    printf("\n");
                    linea(179);
                    printf("\n");
                    sexoMascota=getGender("Ingrese el sexo de la MASCOTA (F o M)");

                        if(addMascota(Mascota,  M,  idMascota,  nombreMascota, idTipo, idRaza, edadMascota, pesoMascota, sexoMascota, idCliente)==0)
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
                printMascotas(Mascota,Cliente,TipoMascota,Raza);
                idMascota=getInt("Ingrese la mascota a modificar.",0,0);
                if(modifyMascota(Mascota,M,idMascota,TipoMascota,Raza,Cliente)==0)
                {
                 setSucces("Modificada correctamente",0);
                }else
                {
                    setError("No se pudo modificar.",0);
                }
                break;
            case 7://eliminar mascota
                printMascotas(Mascota,Cliente,TipoMascota,Raza);
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
                printMascotas(Mascota,Cliente,TipoMascota,Raza);
                break;
            case 9:
                printClientesMascotas(Cliente,Mascota,TipoMascota, Raza);
                break;
                case 10:
                if(printMascotasOrderedByTipo(Mascota,Cliente,TipoMascota,Raza)==-1)
                {
                    setError("No se pudo ordenar las mascotas por tipo, contactese con soporte por favor.",0);
                }
                break;
                case 11:
                if(printClientes2MascotasUp(Cliente,Mascota)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }
                break;
                case 12:
                if(printMascotas3anios(Mascota,Cliente,TipoMascota, Raza)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }
                break;
                 case 13:
                if(printMascotasByTipo(Mascota,Cliente,TipoMascota, Raza)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }
                break;
                case 14:
                if(printClientesCantMascotas(Cliente,Mascota)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }

                break;
                case 15:
                if(printClientesCantMascotasAlfabeticoNombre(Cliente,Mascota)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }

                break;
                case 16:
                 if(promedioEdadMascota(Mascota)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }

                break;
                case 17:
                 if(promedioEdadMascotaByTipo(Mascota, TipoMascota)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }

                break;
                case 18:
                 if(promedioClientesBySexo(Cliente)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }

                break;
                case 19:
                 if(printClientesIdemSexo(Cliente, Mascota)==-1)
                {
                    setError("No se pudo resolver la consulta, contactese con soporte.",0);
                }

                break;


      }
        system("pause");
      system("cls");
}while(opc!=0);

}
