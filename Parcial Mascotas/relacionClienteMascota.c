
#include "relacionClienteMascota.h"
int printOneMascota(Mascota listaMascota[],Cliente Cliente[], int id, TipoMascota TipoMascota[], Raza Raza[])
{
    int index=findMascotaById(listaMascota,M, id);
   // printOneCliente(Cliente,C,1);
   // printf("\n ID CLIENTE %d",listaMascota[index].idCliente);
   char tipoMascota[51];

    int indexC=findClienteById(Cliente,C, listaMascota[index].idCliente);
    //printf("INDEX CLIENTE %d",indexC);
    char razaMascota[51];


           if(index>=0)
            {
                getRazaMascota(Raza,listaMascota[index].idRaza,razaMascota );
                getTipoMascota(TipoMascota,listaMascota[index].idTipo,tipoMascota);

                    columna();
                    columna();
                   printf("%6d  ",listaMascota[index].id);
                   columna();
                                          printf(" %36s  ", listaMascota[index].nombre);
                                           columna();
                                          printf(" %24s  ",tipoMascota);
                                           columna();
                                          printf(" %14s  ",razaMascota);
                                         columna();
                                          printf(" %10d  ",listaMascota[index].edad);
                                          columna();
                                          printf(" %11.2f  ",listaMascota[index].peso);
                                           columna();
                                          printf(" %6c  ",listaMascota[index].sexo);
                                          columna();
                                          printf(" %36s   ",Cliente[indexC].nombre);






                   columna();
                   columna();
                    printf("\n");
            }




    return index;
}
void membrete11()
{

    linea(168);
    printf("\n");
    columna();
    columna();

    printf("     ID  ");
    columna();
    printf("                               Nombre  ");
    columna();
    printf("                             Apellido  ");
    columna();
    printf("            Localidad  ");
    columna();
    printf("     Telefono  ");
    columna();
    printf("   Edad  ");
    columna();
    printf("   Sexo  ");
    columna();
    printf("  Mascotas   ");
    columna();
    columna();
    printf("\n");
    linea(168);
    printf("\n");
}



int printMascotas(Mascota listaMascota[], Cliente Cliente[], TipoMascota TipoMascota[], Raza Raza[])
{
    int i, ret=-1,printRet=-1;


        membreteMascotasCliente();
   for(i=0; i<M; i++)
   {

       if(listaMascota[i].isEmpty==OCUPADO)
       {


         printRet = printOneMascota(listaMascota, Cliente, listaMascota[i].id, TipoMascota, Raza);


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

    linea(179);
    printf("\n");

    return ret;
}

int removeCliente(Cliente listaCliente[],Mascota Mascota[], int id)
{
    int i, ret=-1;
    int index=findClienteById(listaCliente,C, id);




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
int printClientesMascotas(Cliente listaCliente[],Mascota Mascota[], TipoMascota TipoMascota[],Raza Raza[])
{
    int i, j,ret=-1;
    char tipoMascota[51], razaMascota[51];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {


            //printf("\nID CLIENTE %d",listaCliente[i].id);
           // setSucces("Cliente:",0);
            printf("\n");
             printf("\n");
           SetConsoleTextAttribute(hConsole, 175);// 7 es el color normal de la consola, 175 es verde con blanco
            printf("MASCOTAS de %-34s  ",listaCliente[i].nombre);

            SetConsoleTextAttribute(hConsole, 7);

            printf("\n");



            getTipoMascota(TipoMascota,Mascota[i].idTipo,tipoMascota);
            membreteMascotas();
            for(j=0;j<M;j++)
            {
                if(listaCliente[i].id==Mascota[j].idCliente)
                {

                        getRazaMascota(Raza,Mascota[j].idRaza, razaMascota);
                       getTipoMascota(TipoMascota,Mascota[j].idTipo,tipoMascota);

                    columna();
                    columna();
                   printf("%6d  ",Mascota[j].id);
                   columna();
                                          printf(" %36s  ", Mascota[j].nombre);
                                           columna();
                                          printf(" %24s  ",tipoMascota);
                                           columna();
                                          printf(" %14s  ",razaMascota);
                                         columna();
                                          printf(" %10d  ",Mascota[j].edad);
                                          columna();
                                          printf(" %11.2f  ",Mascota[j].peso);
                                           columna();
                                          printf(" %6c  ",Mascota[j].sexo);







                   columna();
                   columna();
                    printf("\n");
                    ret=0;

                }
            }
            linea(138);
            printf("\n");

       }
   }
    return ret;
}
void membreteMascotasTipo()
{

    printf("\n");
    linea(110);
    printf("\n");

    columna();
    columna();

    printf("   ID   ");
    columna();
    printf("                              Nombre   ");
    columna();

    printf("          Raza   ");
    columna();
    printf("        Edad ");
    columna();
    printf("        Peso  ");
    columna();
    printf("    Sexo ");



    columna();
    columna();
    printf("\n");
    linea(110);
    printf("\n");
}
void membreteMascotas()
{

    printf("\n");
    linea(138);
    printf("\n");

    columna();
    columna();

    printf("   ID   ");
    columna();
    printf("                              Nombre   ");
    columna();
    printf("                     Tipo  ");
    columna();
    printf("          Raza   ");
    columna();
    printf("        Edad ");
    columna();
    printf("        Peso  ");
    columna();
    printf("    Sexo ");



    columna();
    columna();
    printf("\n");
    linea(138);
    printf("\n");
}
void membreteMascotasCliente()
{

    printf("\n");
    linea(179);
    printf("\n");

    columna();
    columna();

    printf("   ID   ");
    columna();
    printf("                              Nombre   ");
    columna();
    printf("                     Tipo  ");
    columna();
    printf("          Raza   ");
    columna();
    printf("        Edad ");
    columna();
    printf("        Peso  ");
    columna();
    printf("    Sexo ");
    columna();
    printf("                              Cliente   ");



    columna();
    columna();
    printf("\n");
    linea(179);
    printf("\n");
}

int printMascotasOrderedByTipo(Mascota listaMascota[], Cliente Cliente[], TipoMascota TipoMascota[],Raza Raza[])
{
    int i,j, ret=-1;
    char tipoMascota[51], razaMascota[51];
    printf("\n");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  for(j=0;j<TM;j++)
    {
            printf("\n\n");

                SetConsoleTextAttribute(hConsole, 112);// 7 es el color normal de la consola, 175 es verde con blanco
                printf(" %6ss                                                                                                     \n",TipoMascota[j].tipo);

                SetConsoleTextAttribute(hConsole, 7);

               // printf("\n");



        for(i=0; i<C; i++)
        {

           if(Cliente[i].isEmpty==OCUPADO)
           {

                    for(int u=0;u<M;u++)
                    {
                        if(Cliente[i].id==listaMascota[u].idCliente && listaMascota[u].idTipo==j+1)
                        {







                 printf("\n");
               SetConsoleTextAttribute(hConsole, 175);// 7 es el color normal de la consola, 175 es verde con blanco
                printf("%-34s  ",Cliente[i].nombre);

                SetConsoleTextAttribute(hConsole, 7);

                printf("\n");



                membreteMascotasTipo();
                    for(int z=0;z<M;z++)
                    {
                        if(Cliente[i].id==listaMascota[z].idCliente && listaMascota[z].idTipo==j+1)
                        {


                               getTipoMascota(TipoMascota,listaMascota[z].idTipo,tipoMascota);
                                getRazaMascota(Raza,listaMascota[z].idTipo, razaMascota);
                            columna();
                            columna();
                           printf("%6d  ",listaMascota[z].id);
                           columna();
                                                  printf(" %36s  ", listaMascota[z].nombre);
                                                   columna();
                                                  printf(" %14s  ",razaMascota);
                                                 columna();
                                                  printf(" %10d  ",listaMascota[z].edad);
                                                  columna();
                                                  printf(" %11.2f  ",listaMascota[z].peso);
                                                   columna();
                                                  printf(" %6c  ",listaMascota[z].sexo);







                           columna();
                           columna();
                            printf("\n");
                            ret=0;

                        }
                    }
                linea(110);
                printf("\n");
                break;
                 }

                                    }

                           }
                   }

            lineaRGB(210,112);
            }
    return ret;
}

int printMascotas3anios(  Mascota listaMascota[], Cliente Cliente[],TipoMascota TipoMascota[],Raza Raza[])
{
    int i, ret=-1;

        membreteMascotasCliente();
   for(i=0; i<M; i++)
   {

       if(listaMascota[i].isEmpty==OCUPADO)
       {
            if(listaMascota[i].edad>3)
            {
                 if(printOneMascota(listaMascota, Cliente, listaMascota[i].id, TipoMascota,Raza)==-1)
                {
                      setError("No se encpontro ningun registro.",0);
                      ret=-1;
                  }else
                  {
                      ret=0;
                  }

            }


       }
   }

    linea(179);
    printf("\n");

    return ret;
}


int printMascotasByTipo(Mascota listaMascota[], Cliente Cliente[], TipoMascota TipoMascota[], Raza Raza[])
{
    int i,j, ret=-1,opc;
    char tipoMascota[51], razaMascota[51];
    printf("\n");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        printTiposMascota(TipoMascota,TM);
        opc=getInt("Ingrese el tipo de mascota: ",1,3);


  for(j=0;j<TM;j++)
    {
        if(TipoMascota[j].id==opc)
        {


            printf("\n\n");

                SetConsoleTextAttribute(hConsole, 112);// 7 es el color normal de la consola, 175 es verde con blanco
                printf(" %6ss                                                                                                     \n",TipoMascota[j].tipo);

                SetConsoleTextAttribute(hConsole, 7);

               // printf("\n");



        for(i=0; i<C; i++)
        {

           if(Cliente[i].isEmpty==OCUPADO)
           {

                    for(int u=0;u<M;u++)
                    {
                        if(Cliente[i].id==listaMascota[u].idCliente && listaMascota[u].idTipo==j+1)
                        {







                 printf("\n");
               SetConsoleTextAttribute(hConsole, 175);// 7 es el color normal de la consola, 175 es verde con blanco
                printf("%-34s  ",Cliente[i].nombre);

                SetConsoleTextAttribute(hConsole, 7);

                printf("\n");



                membreteMascotasTipo();
                    for(int z=0;z<M;z++)
                    {
                        if(Cliente[i].id==listaMascota[z].idCliente && listaMascota[z].idTipo==j+1)
                        {

                                    getRazaMascota(Raza,listaMascota[z].idTipo, razaMascota);

                               getTipoMascota(TipoMascota,listaMascota[z].idTipo,tipoMascota);

                            columna();
                            columna();
                           printf("%6d  ",listaMascota[z].id);
                           columna();
                                                  printf(" %36s  ", listaMascota[z].nombre);
                                                   columna();
                                                  printf(" %14s  ",razaMascota);
                                                 columna();
                                                  printf(" %10d  ",listaMascota[z].edad);
                                                  columna();
                                                  printf(" %11.2f  ",listaMascota[z].peso);
                                                   columna();
                                                  printf(" %6c  ",listaMascota[z].sexo);







                           columna();
                           columna();
                            printf("\n");
                            ret=0;

                        }
                    }
                linea(110);
                printf("\n");

                break;
                 }

                                    }

                           }
                   }
                   }

                printf("\n");
                lineaRGB(210,112);

            }
    return ret;
}
int printClientes2MascotasUp(Cliente listaCliente[], Mascota Mascota[])
{
    int i, ret=-1, cantMascotas[C];
    printf("\n");
   membrete11();
   for(i=0; i<C; i++)//Inicializa la cantidad de mascotas por cliente
    {
            cantMascotas[i]=0;
            if(listaCliente[i].isEmpty==OCUPADO)
            {

           for(int j=0;j<M;j++)
           {
               if(Mascota[j].idCliente==listaCliente[i].id)
               {
                   cantMascotas[i]++;
               }
           }
           }

    }


   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {


            if(cantMascotas[i]>1)
            {


            columna();
            columna();
                    printf(" %6d  ",listaCliente[i].id);
                    columna();
                    printf(" %36s  ",listaCliente[i].nombre);
                    columna();
                    printf(" %36s  ",listaCliente[i].apellido);
                    columna();
                    printf(" %20s  ",listaCliente[i].localidad);
                    columna();
                    printf(" %12d  ",listaCliente[i].telefono);
                    columna();
                    printf(" %6d  ",listaCliente[i].edad);
                    columna();
                    printf(" %6c  ",listaCliente[i].sexo);
                    columna();
                    printf("    %6d   ",cantMascotas[i]);
                columna();
                columna();
                ret=0;
                printf("\n");

                }


       }
   }

    linea(168);
    printf("\n");
    return ret;
}


int printClientesCantMascotas(Cliente listaCliente[], Mascota Mascota[])
{
    int i, ret=-1,  auxCantMascotas, cantMascotas[C];
    printf("\n");
   membrete11();
   Cliente auxcliente;

        for(i=0; i<C; i++)//Inicializa las cantidades de mascotas en la misma posicion del cliente
        {
            cantMascotas[i]=0;
            if(listaCliente[i].isEmpty==OCUPADO)
            {

                   for(int j=0;j<M;j++)
                   {
                       if(Mascota[j].idCliente==listaCliente[i].id)
                       {
                           cantMascotas[i]++;
                       }
                   }
           }

        }

        for(int z=0; z<C-1; z++)//Ordena de mayor a menor la cantidad de mascotas
               {
                    for(int y=z+1; y<C; y++)
                    {
                        if(listaCliente[z].isEmpty==OCUPADO)
                        {

                               if(cantMascotas[z]<cantMascotas[y])
                               {
                                  auxcliente=listaCliente[z];
                                  listaCliente[z]=listaCliente[y];
                                  listaCliente[y]=auxcliente;
                                  auxCantMascotas=cantMascotas[z];
                                  cantMascotas[z]=cantMascotas[y];
                                  cantMascotas[y]=auxCantMascotas;
                               }
                       }

               }

           }


   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {





            columna();
            columna();
                    printf(" %6d  ",listaCliente[i].id);
                    columna();
                    printf(" %36s  ",listaCliente[i].nombre);
                    columna();
                    printf(" %36s  ",listaCliente[i].apellido);
                    columna();
                    printf(" %20s  ",listaCliente[i].localidad);
                    columna();
                    printf(" %12d  ",listaCliente[i].telefono);
                    columna();
                    printf(" %6d  ",listaCliente[i].edad);
                    columna();
                    printf(" %6c  ",listaCliente[i].sexo);
                    columna();
                    printf("    %6d   ",cantMascotas[i]);
                columna();
                columna();
                ret=0;
                printf("\n");


                cantMascotas[i]=0;
       }

   }

    linea(168);
    printf("\n");
    return ret;
}

int printClientesCantMascotasAlfabeticoNombre(Cliente listaCliente[], Mascota Mascota[])
{
    int i, ret=-1,  auxCantMascotas, cantMascotas[C];
    printf("\n");
   membrete11();
   Cliente auxcliente;

        for(i=0; i<C; i++)//Inicializa las cantidades de mascotas en la misma posicion del cliente
        {
            cantMascotas[i]=0;
            if(listaCliente[i].isEmpty==OCUPADO)
            {

                   for(int j=0;j<M;j++)
                   {
                       if(Mascota[j].idCliente==listaCliente[i].id)
                       {
                           cantMascotas[i]++;
                       }
                   }
           }

        }

        for(int z=0; z<C-1; z++)//Ordena de mayor a menor la cantidad de mascotas
               {
                    for(int y=z+1; y<C; y++)
                    {
                        if(listaCliente[z].isEmpty==OCUPADO)
                        {

                               if(cantMascotas[z]<cantMascotas[y])
                               {
                                  auxcliente=listaCliente[z];
                                  listaCliente[z]=listaCliente[y];
                                  listaCliente[y]=auxcliente;
                                  auxCantMascotas=cantMascotas[z];
                                  cantMascotas[z]=cantMascotas[y];
                                  cantMascotas[y]=auxCantMascotas;
                               }
                       }

               }

           }

           for(int z=0; z<C-1; z++)//Ordena asc alfabeticamente por nombre
               {
                    for(int y=z+1; y<C; y++)
                    {
                        if(listaCliente[z].isEmpty==OCUPADO)
                        {

                               if(strcmp(listaCliente[z].nombre,listaCliente[y].nombre)>0)
                               {
                                  auxcliente=listaCliente[z];
                                  listaCliente[z]=listaCliente[y];
                                  listaCliente[y]=auxcliente;
                                  auxCantMascotas=cantMascotas[z];
                                  cantMascotas[z]=cantMascotas[y];
                                  cantMascotas[y]=auxCantMascotas;
                               }
                       }

               }

           }


   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {





            columna();
            columna();
                    printf(" %6d  ",listaCliente[i].id);
                    columna();
                    printf(" %36s  ",listaCliente[i].nombre);
                    columna();
                    printf(" %36s  ",listaCliente[i].apellido);
                    columna();
                    printf(" %20s  ",listaCliente[i].localidad);
                    columna();
                    printf(" %12d  ",listaCliente[i].telefono);
                    columna();
                    printf(" %6d  ",listaCliente[i].edad);
                    columna();
                    printf(" %6c  ",listaCliente[i].sexo);
                    columna();
                    printf("    %6d   ",cantMascotas[i]);
                columna();
                columna();
                ret=0;
                printf("\n");


                cantMascotas[i]=0;
       }

   }

    linea(168);
    printf("\n");
    return ret;
}

int promedioEdadMascota(Mascota Mascota[])
{
    int ret=-1,i, contEdad=0,cantMascotas=0,promEdad;
    for(i=0;i<M;i++)
    {

        if(Mascota[i].isEmpty==OCUPADO)
        {
            contEdad=contEdad+Mascota[i].edad;
            cantMascotas++;
        }
        ret=0;
    }
    promEdad=contEdad/cantMascotas;
    linea(57);
        printf("\n");
        columna();
        printf(" El promedio de edad en las mascotas es de --> %6d ",promEdad);
        columna();
        printf("\n");
    linea(57);
    printf("\n");
    return ret;
}

int promedioEdadMascotaByTipo(Mascota Mascota[], TipoMascota TipoMascota[])
{
    int i, j,ret=-1,contEdad,cantMascotas,promEdad;
    printf("\n");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);




  for(j=0;j<TM;j++)
    {
        contEdad=0;
        cantMascotas=0;
        promEdad=0;



            printf("\n\n");

                SetConsoleTextAttribute(hConsole, 112);// 7 es el color normal de la consola, 175 es verde con blanco
                printf(" %6ss                            \n",TipoMascota[j].tipo);

                SetConsoleTextAttribute(hConsole, 7);
            printf("\n");
                for(i=0;i<M;i++)
                {

                        if(Mascota[i].isEmpty==OCUPADO && Mascota[i].idTipo==TipoMascota[j].id)
                        {
                            contEdad=contEdad+Mascota[i].edad;
                            cantMascotas++;
                        }
                        ret=0;
                }

            promEdad=contEdad/cantMascotas;
            linea(33);
                printf("\n");
                columna();
                printf(" Promedio de edad  --> %6d ",promEdad);
                columna();
                printf("\n");
            linea(33);
            printf("\n");




                printf("\n");
                lineaRGB(210,112);

            }
    return ret;
}


int promedioClientesBySexo(Cliente Cliente[])
{
    int i, ret=-1,cantMujeres=0,cantHombres=0,totClientes;
    float promMujeres,promHombres,porcMujeres,porcHombres;

    printf("\n");








        for(i=0;i<C;i++)
        {

                    switch(Cliente[i].sexo)
                    {
                        case 'F':

                            cantMujeres++;
                            break;
                        case 'M':
                            cantHombres++;


                            break;
                    }


                        ret=0;
                }

                totClientes=cantHombres+cantMujeres;

                promMujeres=(float)totClientes/(float)cantMujeres;

                promHombres=(float)totClientes/(float)cantHombres;
                porcHombres=((float)cantMujeres*100)/(float)totClientes;
                porcMujeres=((float)cantHombres*100)/(float)totClientes;
            printf("\n");
            printf("\n");
            linea(46);
                printf("\n");
                columna();
                printf(" Promedio de mujeres  --> %4.2f -->  %4.2f  ",promMujeres,porcMujeres);
                columna();
                printf("\n");
            linea(46);
            printf("\n");
            printf("\n");
            printf("\n");
            linea(46);
                printf("\n");
                columna();
                printf(" Promedio de hombres  --> %4.2f -->  %4.2f  ",promHombres,porcHombres);
                columna();
                printf("\n");
            linea(46);
            printf("\n");







    return ret;
}


int modifyMascota(Mascota listaMascota[],int tam,int id,TipoMascota TipoMascota[], Raza Raza[], Cliente Cliente[])
{
    int i,opc, columnaModificar, ret=-1, indexCA,indexCB;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findMascotaById(listaMascota,tam,id);
    int  edadMascota, sexoMascota, idTipo,  idRazaB, idCliente;
     char nombreMascota[51], razaMascotaA[51],razaMascotaB[51], tipoMascota[51];
     float pesoMascota;
     int modificado[7]={0,0,0,0,0,0,0};//


    if(index!=-1)
    {

    getRazaMascota(Raza,listaMascota[index].idRaza, razaMascotaA);
    do
    {

                    system("cls");
lineaRGB(179,51);
        printf("\n");

            printf("1)Nombre\n2)Tipo\n3)Raza\n4)edad\n5)Peso\n6)sexo\n7)Cliente\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,7);
        lineaRGB(179,51);
        printf("\n");
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",nombreMascota);
                nombreMascota[0]=toupper(nombreMascota[0]);
                modificado[0]=1;


                break;

            case 2:
                printTiposMascota(TipoMascota,TM);
                idTipo=getInt("Ingrese el tipo nuevo: ",1,3);
                //printOnMascota(listaMascota,tam, id);
                 modificado[1]=1;

                break;
            case 3:
                printRazaMascota(Raza);
                idRazaB=getInt("Ingrese la raza nuevo: ",0,0);
                getRazaMascota(Raza,idRazaB, razaMascotaB);
               // printOnMascota(listaMascota,tam, id);
                modificado[2]=1;

                break;
                case 4:
                edadMascota=getInt("Escriba la edad nuevo:",0,0);
               // printOnMascota(listaMascota,tam, id);
                modificado[3]=1;

                break;
                case 5:
                    pesoMascota=getFloat("Escriba la peso nuevo:",0,0);
                     modificado[4]=1;

                break;
                case 6:
                sexoMascota=getGender("Ingrese el sexo de la MASCOTA (F o M)");

                      modificado[5]=1;

                break;
                case 7:
                    printClientes(Cliente,C);
                idCliente=getInt("Ingrese el id cliente de la MASCOTA ",0,0);

                      modificado[6]=1;

                break;

            }
    }while(columnaModificar!=0);

    setSucces("Desea realizar las siguientes modificaciones? (SI=1 o NO=2)",0);

                    for(i=0;i<7;i++)
                    {
                        if(modificado[i]==1)
                        {


                        switch(i)
                        {
                        case 0:
                            printf("\n");
                            linea(60);
                            printf("\nNombre ORIGINAL [ %s ]  ----> ",listaMascota[index].nombre);

                            printf("Nombre NUEVO [ %s ]\n",nombreMascota);
                            linea(60);
                            printf("\n");

                            break;
                        case 1:
                            printf("\n");
                            linea(60);
                            printf("\n");
                            getTipoMascota(TipoMascota,listaMascota[index].idTipo,tipoMascota);
                             printf("Tipo ORIGINAL [ %s ] ----> ",tipoMascota);
                            getTipoMascota(TipoMascota,idTipo,tipoMascota);
                            printf("Tipo NUEVO [ %s ]",tipoMascota);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 2:
                             printf("\n");
                            linea(60);
                            printf("\n");
                            printf("Raza ORIGINAL [ %s ] ----> ",razaMascotaA);
                            printf("Raza NUEVO [ %s ]",razaMascotaB);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 3:
                            printf("\n");
                            linea(60);
                            printf("\n");
                             printf("Edad ORIGINAL [ %d ] ----> ",listaMascota[index].edad);
                            printf("Edad NUEVO [ %d ]",edadMascota);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 4:
                             printf("\n");
                            linea(60);
                            printf("\n");
                             printf("Peso ORIGINAL [ %6.2f ] ----> ",listaMascota[index].peso);
                            printf("Peso NUEVO [ %6.2f ]",pesoMascota);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 5:
                             printf("\n");
                            linea(60);
                            printf("\n");
                             printf("Sexo ORIGINAL [ %c ] ----> ",listaMascota[index].sexo);
                            printf("Sexo NUEVO [ %c ]",sexoMascota);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;

                        case 6:
                            indexCA=findClienteById(Cliente,C,listaMascota[index].idCliente);
                            indexCB=findClienteById(Cliente,C,idCliente);
                             printf("\n");
                            linea(60);
                            printf("\n");
                             printf("Cliente ORIGINAL [ %s ] ----> ",Cliente[indexCA].nombre);
                            printf("Cliente NUEVO [ %s ]",Cliente[indexCB].nombre);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        }
                        }
                    }

    opc=getInt("",1,2);
    if(opc==1)
    {
        ret=0;
        for(i=0;i<6;i++)
        {
                if(modificado[i]==1)
                {


                    switch(i)
                    {
                        case 0:
                            strcpy(listaMascota[index].nombre,nombreMascota);

                            break;
                        case 1:
                            listaMascota[index].idTipo=idTipo;


                            break;
                        case 2:
                            listaMascota[index].idRaza=idRazaB;
                            break;
                        case 3:

                            listaMascota[index].edad=edadMascota;
                            break;
                        case 4:
                             listaMascota[index].peso=pesoMascota;
                            break;
                        case 5:
                            listaMascota[index].sexo=sexoMascota;
                            break;
                    }
                }
        }
        ret=0;
    }else
    {
        ret=-1;
    }


}
    return ret;
}


int printClientesIdemSexo(Cliente listaCliente[], Mascota Mascota[])
{
    int i, ret=-1,printRet=-1, cantMascotaF[C], cantMascotaM[C];


     for(i=0; i<C; i++)//Inicializa las cantidades de mascotas en la misma posicion del cliente
        {
            cantMascotaF[i]=0;
            cantMascotaM[i]=0;
            if(listaCliente[i].isEmpty==OCUPADO)
            {

                   for(int j=0;j<M;j++)
                   {
                       if(Mascota[j].idCliente==listaCliente[i].id )
                       {
                            switch(Mascota[j].sexo)
                            {
                                case 'F':cantMascotaF[i]++;


                                    break;
                                case 'M':cantMascotaM[i]++;

                                    break;
                            }



                       }
                   }
           }

        }





    printf("\n");
    membreteClientes();





   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {

            //printf("\nID CLIENTE %d",listaCliente[i].id);
            if(cantMascotaF[i]>1 || cantMascotaM[i]>1)
            {


            printRet = printOneCliente(listaCliente, C, listaCliente[i].id);
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
   linea(154);
   printf("\n");
    return ret;
}


