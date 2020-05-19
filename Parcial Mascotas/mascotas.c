
#include "mascotas.h"

void CargarTipoMascotas(TipoMascota TipoMascota[],int tam)
{
    int i;
    int id[3]={1,2,3};
    char tipo[3][51]={{"Gato"},{"Perro"},{"Raro"}};


    for(i=0;i<tam;i++)
    {
        TipoMascota[i].id=id[i];
        strcpy(TipoMascota[i].tipo,tipo[i]);
    }

}
void CargarRaza(Raza Raza[])
{
    int i;
    int id[7]={1,2,3,4,5,6,7};
    char nombre[7][51]={{"Labrador"},{"Pitbull"},{"Bulldog"},{"Overo"},{"Persa"},{"Siames"},{"Encharquido"}};
    char pais[7][51]={{"Hungria"},{"Ucrania"},{"Argentina"},{"Alemania"},{"Egipto"},{"Uruguay"},{"Espania"}};
    int idTipo[7]={2,2,2,3,1,1,3};

    for(i=0;i<R;i++)
    {
        Raza[i].id=id[i];
        strcpy(Raza[i].nombre,nombre[i]);
        strcpy(Raza[i].pais,pais[i]);
        Raza[i].idTipo=idTipo;

    }

}

void hardCodearMascotas(Mascota mascota[], int tam )
{
    int i;
   int id[11]={100,101,102,103,104,105,106,107,108,109,110};
    int idCliente[11]={1,3,1,2,3,3,4,2,5,5,5};
    char nombre[11][51]={{"Mia"},{"Manuela"},{"Dero"},{"nuni"},{"jart"},{"carlin"},{"cucu"},{"clanca"},{"rey"},{"mini"},{"donald"}};
    int idTipo[11]={1,2,1,2,1,2,1,3,1,1,2};
    int idRaza[11]={1,1,1,2,1,2,2,3,1,1,2};
    int edad[11]={10,11,5,3,5,2,7,1,9,6,4};
    float peso[11]={5.6,7.28,5.21,21.5,35.69,78.2,15.2,25.2,23.6,7.21,2.9};
    char sexo[11]={'F','M','F','M','M','M','M','F','M','M','M'};


    for(i=0;i<11;i++)
    {
        mascota[i].id=id[i];
        mascota[i].idCliente=idCliente[i];
        strcpy(mascota[i].nombre,nombre[i]);
        mascota[i].idTipo=idTipo[i];
        mascota[i].idRaza=idRaza[i];
        mascota[i].edad=edad[i];
        mascota[i].peso=peso[i];
        mascota[i].sexo=sexo[i];
        mascota[i].isEmpty=OCUPADO;
    }
    //printOneMascota(mascota,M,110);
}

int initMascota(Mascota listaMascota[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaMascota[i].isEmpty = LIBRE;
  }
  if(i==tam)
  {
        ret= 0; //ok
  }else
  {
      ret= -1;// error
  }
  return ret;
}

int generateIdMascota(Mascota listaMascota[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {

        if(listaMascota[i].isEmpty==LIBRE || listaMascota[i].isEmpty==ELIMINADO)
        {

            id = lastId + 1;

            break;
        }

    }

    return id;
}
int findMascotaById(Mascota listaMascota[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<M;i++)
    {

        if(id==listaMascota[i].id && listaMascota[i].isEmpty==OCUPADO )
        {
            index=i;
            break;
        }

    }
    return index;
}


int findMascotaByClienteId(Mascota listaMascota[], int tam, int idCliente)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(idCliente==listaMascota[i].idCliente && listaMascota[i].isEmpty==OCUPADO )
        {
            index=i;
            break;
        }

    }
    return index;
}

int printTiposMascota(TipoMascota TipoMascota[], int tam)
{
    int ret=-1,i;
    for(i=0;i<tam;i++)
    {
        linea(15);
        printf("\n");
        columna();
        printf(" %2d) %6s ",TipoMascota[i].id,TipoMascota[i].tipo);
        columna();
        printf("\n");

        ret=0;
    }
    linea(15);
    printf("\n");
    return ret;
}

int addMascota(Mascota listaMascota[], int tam, int id, char nombre[],int idTipo,int idRaza,int edad,float peso,char sexo,int idCliente)
{
    int i, ret=-1;//generic var

    for(i=0;i<tam;i++)
    {
        if(listaMascota[i].isEmpty==LIBRE || listaMascota[i].isEmpty==ELIMINADO)
        {

              listaMascota[i].id=id;
            nombre[0]=toupper(nombre[0]);
            strcpy(listaMascota[i].nombre,nombre);
            listaMascota[i].idTipo=idTipo;

            listaMascota[i].idRaza=idRaza;
            listaMascota[i].edad=edad;
            listaMascota[i].peso=peso;
            listaMascota[i].sexo=sexo;
            listaMascota[i].idCliente=idCliente;
            listaMascota[i].isEmpty=OCUPADO;
            ret=0;
            break;
        }
    }

    return ret;
}

int removeMascota(Mascota listaMascota[], int tam, int id)
{
    int i, ret=-1;
    int index=findMascotaById(listaMascota,tam, id);
   for(i=0; i<tam; i++)
   {
       if(index==i)
       {
           listaMascota[i].isEmpty=ELIMINADO;
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }
    return ret;
}

int removeMascotaByCliente(Mascota listaMascota[], int tam, int idCliente)
{
    int i, ret=-1;
    //int index=findMascotaById(listaMascota,M, idCliente);
   for(i=0; i<M; i++)
   {
       if(listaMascota[i].idCliente==idCliente)
       {
           listaMascota[i].isEmpty=ELIMINADO;
           ret=0;

       }

   }
    return ret;
}
int getTipoMascota(TipoMascota TipoMascota[],int idTipo,char tipoMascota[])
{
    int ret=-1,i;

    for(i=0;i<TM;i++)
    {
        if(TipoMascota[i].id==idTipo)
        {
            strcpy(tipoMascota,TipoMascota[i].tipo);
            ret=0;
            break;
        }
    }



    return ret;
}




int modifyMascota(Mascota listaMascota[],int tam,int id,TipoMascota TipoMascota[], Raza Raza[])
{
    int i,opc, columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findMascotaById(listaMascota,tam,id);
    int  edadMascota, sexoMascota, idTipo,  idRazaB;
     char nombreMascota[51], razaMascotaA[51],razaMascotaB[51], tipoMascota[51];
     float pesoMascota;
     int modificado[6]={0,0,0,0,0,0};//


    if(index!=-1)
    {

    getRazaMascota(Raza,listaMascota[index].idRaza, razaMascotaA);
    do
    {

                    system("cls");
lineaRGB(179,51);
        printf("\n");

            printf("1)Nombre\n2)Tipo\n3)Raza\n4)edad\n5)Peso\n6)sexo\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,6);
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

            }
    }while(columnaModificar!=0);

    setSucces("Desea realizar las siguientes modificaciones? (SI=1 o NO=2)",0);

                    for(i=0;i<6;i++)
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


int getRazaMascota(Raza Raza[],int idRaza,char cadena[])
{
    int ret=-1,i;

    for(i=0;i<R;i++)
    {
        if(Raza[i].id==idRaza)
        {
            strcpy(cadena,Raza[i].nombre);
            ret=0;
            break;
        }
    }



    return ret;

}




int printRazaMascota(Raza Raza[])
{
    int ret=-1,i;
    for(i=0;i<R;i++)
    {
        linea(54);
        printf("\n");
        columna();
        printf(" %2d) %15s   ",Raza[i].id,Raza[i].nombre);
        columna();
        printf("   %20s    ",Raza[i].pais);
        columna();
        printf("\n");

        ret=0;
    }
    linea(54);
    printf("\n");
    return ret;
}

