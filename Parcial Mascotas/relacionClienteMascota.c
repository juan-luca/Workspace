
#include "relacionClienteMascota.h"
int printOneMascota(Mascota listaMascota[],Cliente Cliente[], int id)
{
    int index=findMascotaById(listaMascota,M, id);
   // printOneCliente(Cliente,C,1);
   // printf("\n ID CLIENTE %d",listaMascota[index].idCliente);
    int indexC=findClienteById(Cliente,C, listaMascota[index].idCliente);
    //printf("INDEX CLIENTE %d",indexC);

           if(index>=0)
            {
                   printf("%d\t%15s\t%15s\t%15s\t%d\t%f\t%c\t%15s\n",listaMascota[index].id,
                                        listaMascota[index].nombre
                                          ,listaMascota[index].tipo
                                          ,listaMascota[index].raza
                                          ,listaMascota[index].edad
                                          ,listaMascota[index].peso
                                          ,listaMascota[index].sexo
                                          ,Cliente[indexC].nombre);
            }




    return index;
}


int printMascotas(Mascota listaMascota[], Cliente Cliente[])
{
    int i, ret=-1,printRet=-1;
    printf("ID\t\tNombre\t\tTipo\t\tRaza\tEdad\tPeso\t\tSexo\tCliente\n");
   for(i=0; i<M; i++)
   {

       if(listaMascota[i].isEmpty==OCUPADO)
       {

            printRet = printOneMascota(listaMascota, Cliente, listaMascota[i].id);

          if(printRet==-1)
          {
              setError("Registro no encontrado",0);
              ret=-1;
          }else
          {
              ret=0;
          }
       }
   }
    return ret;
}

int removeCliente(Cliente listaCliente[],Mascota Mascota[], int id)
{
    int i, ret=-1;
    int index=findClienteById(listaCliente,C, id);
    int indexM;



   for(i=0; i<C; i++)
   {
       if(index==i)
       {
            //indexM=findMascotaByClienteId(Mascota,M,id);
           // printf("\nINDEX MASCOTA %d",indexM);
           listaCliente[i].isEmpty=ELIMINADO;
           removeMascotaByCliente(Mascota,M,id);
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }

    return ret;
}
int printClientesMascotas(Cliente listaCliente[],Mascota Mascota[])
{
    int i, j,ret=-1,printRet=-1;

   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {

            //printf("\nID CLIENTE %d",listaCliente[i].id);
            setSucces("Cliente:",0);
            printf("ID\t\t\tNombre\t\tApellido\t\tLocalidad\tTelefono  Edad\tSexo\n");
            printRet = printOneCliente(listaCliente, C, listaCliente[i].id);
            setSucces("MASCOTAS:",0);
            printf("ID\t\tNombre\t\tTipo\t\tRaza\tEdad\tPeso\t\tSexo\n");
            for(j=0;j<M;j++)
            {
                if(listaCliente[i].id==Mascota[j].idCliente)
                {


                printf("%d\t%15s\t%15s\t%15s\t%d\t%f\t%c\n",Mascota[j].id,
                                        Mascota[j].nombre
                                          ,Mascota[j].tipo
                                          ,Mascota[j].raza
                                          ,Mascota[j].edad
                                          ,Mascota[j].peso
                                          ,Mascota[j].sexo
                                          );
                }
            }
          if(printRet==-1)
          {
              setError("Registro no encontrado",0);
              ret=-1;
          }else
          {
              ret=0;
          }
       }
   }
    return ret;
}


int printMascotasOrderedByTipo(Mascota listaMascota[], Cliente Cliente[])
{
    int i,oi,j, ret=-1,printRet=-1;
    printf("ID\t\tNombre\t\tTipo\t\tRaza\tEdad\tPeso\t\tSexo\tCliente\n");
   Mascota auxMascota;
   for(oi=0; oi<M-1; oi++)
   {
        for(j=i+1; j<M; j++)
        {
            if(strcmp(listaMascota[oi].tipo,listaMascota[j].tipo)>0)
            {
                auxMascota = listaMascota[oi];
                listaMascota[oi] = listaMascota[j];
                listaMascota[j] = auxMascota;
            }

        }

   }
   for(i=0; i<M; i++)
   {

       if(listaMascota[i].isEmpty==OCUPADO)
       {

            printRet = printOneMascota(listaMascota, Cliente, listaMascota[i].id);

          if(printRet==-1)
          {
              setError("Registro no encontrado",0);
              ret=-1;
          }else
          {
              ret=0;
          }
       }
   }
    return ret;
}

