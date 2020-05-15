
#include "mascotas.h"


void hardCodearMascotas(Mascota mascota[],int tam)
{
    int i;
   int id[11]={100,101,102,103,104,105,106,107,108,109,110};
    int idCliente[11]={1,3,1,2,3,3,4,2,5,5,5};
    char nombre[11][51]={{"Mia"},{"Manuela"},{"Dero"},{"nuni"},{"jart"},{"carlin"},{"cucu"},{"clanca"},{"rey"},{"mini"},{"donald"}};
    char tipo[11][51]={{"Gato"},{"Perro"},{"Gato"},{"Perro"},{"Gato"},{"Perro"},{"Perro"},{"Raro"},{"Gato"},{"Gato"},{"Perro"}};
    char raza[11][51]={{"Siames"},{"Mestizo"},{"Siames"},{"Pitbull"},{"Mestizo"},{"Mestizo"},{"Labrador"},{"Iguana"},{"Persa"},{"Siames"},{"Bulldog"}};
    int edad[11]={10,11,5,3,5,2,7,1,9,6,4};
    float peso[11]={5.6,7.28,5.21,21.5,35.69,78.2,15.2,25.2,23.6,7.21,2.9};
    char sexo[11]={'F','M','F','M','M','M','M','F','M','M','M'};


    for(i=0;i<11;i++)
    {
        mascota[i].id=id[i];
        mascota[i].idCliente=idCliente[i];
        strcpy(mascota[i].nombre,nombre[i]);
        strcpy(mascota[i].tipo,tipo[i]);
        strcpy(mascota[i].raza,raza[i]);
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
    for(i=0;i<tam;i++)
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



int addMascota(Mascota listaMascota[], int tam, int id, char nombre[],char tipo[],char raza[],int edad,int peso,char sexo,int idCliente)
{
    int i, ret=-1;//generic var

    for(i=0;i<tam;i++)
    {
        if(listaMascota[i].isEmpty==LIBRE || listaMascota[i].isEmpty==ELIMINADO)
        {

              listaMascota[i].id=id;

            strcpy(listaMascota[i].nombre,nombre);
            strcpy(listaMascota[i].tipo,tipo);
            strcpy(listaMascota[i].raza,raza);
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




int modifyMascota(Mascota listaMascota[],int tam,int id)
{
    int i,opc, columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findMascotaById(listaMascota,tam,id);
    int idMascota, edadMascota, sexoMascota;
     char nombreMascota[51], tipoMascota[51], razaMascota[51];
     float pesoMascota;
     int modificado[6]={0,0,0,0,0,0};//
    if(index!=-1)
    {


    do
    {

                    system("cls");


            printf("1)Nombre\n2)Tipo\n3)Raza\n4)edad\n5)Peso\n6)sexo\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,6);
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",nombreMascota);

                modificado[0]=1;


                break;

            case 2:
                getString("Ingrese el tipo nuevo: ",tipoMascota);
                //printOnMascota(listaMascota,tam, id);
                 modificado[1]=1;

                break;
            case 3:
                getString("Ingrese la raza nuevo: ",razaMascota);
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
                printf("Ingrese el sexo de la MASCOTA (F o M)\n");
                    fflush(stdin);
                    scanf("%c",&sexoMascota);
                    sexoMascota=toupper(sexoMascota);
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
                            setSucces("Nombre ORIGINAL",0);
                            printf(" %s ",listaMascota[index].nombre);
                            setSucces("Nombre NUEVO",0);
                            printf(" %s ",nombreMascota);
                            break;
                        case 1:
                             setSucces("Tipo ORIGINAL",0);
                            printf(" %s ",listaMascota[index].tipo);
                            setSucces("Tipo NUEVO",0);
                            printf(" %s ",tipoMascota);
                            break;
                        case 2:
                             setSucces("Raza ORIGINAL",0);
                            printf(" %s ",listaMascota[index].raza);
                            setSucces("Raza NUEVO",0);
                            printf(" %s ",razaMascota);
                            break;
                        case 3:
                             setSucces("Edad ORIGINAL",0);
                            printf(" %d ",listaMascota[index].edad);
                            setSucces("Edad NUEVO",0);
                            printf(" %d ",edadMascota);
                            break;
                        case 4:
                             setSucces("Peso ORIGINAL",0);
                            printf(" %f ",listaMascota[index].peso);
                            setSucces("Peso NUEVO",0);
                            printf(" %f ",pesoMascota);
                            break;
                        case 5:
                             setSucces("Sexo ORIGINAL",0);
                            printf(" %c ",listaMascota[index].sexo);
                            setSucces("Sexo NUEVO",0);
                            printf(" %c ",sexoMascota);
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
                            strcpy(listaMascota[index].tipo,tipoMascota);


                            break;
                        case 2:
                            strcpy(listaMascota[index].raza,razaMascota);
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





