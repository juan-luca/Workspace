
#include "clientes.h"



void hardCodearClientes(Cliente cliente[],int tam){

    int i;
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={"Roberta","Pablo","Liliana","Carlos","Juan"};
    char apellido[5][51]={"santos","lopez","Ken","Aguero","Messi"};
    char localidad[5][51]={"Paternal","Urquiza","Caballito","Lomas","Berazat"};
    int telefono[5]={546546,652132,5468798,3213578,54354};
    int edad[5]={22,15,35,21,85};
    char sexo[5]={'F','F','M','M','M'};

    for(i=0;i<5;i++)
    {
        cliente[i].id=id[i];
        strcpy(cliente[i].nombre,nombre[i]);
        strcpy(cliente[i].apellido,apellido[i]);
        strcpy(cliente[i].localidad,localidad[i]);
        cliente[i].telefono=telefono[i];
        cliente[i].edad=edad[i];
        cliente[i].sexo=sexo[i];
        cliente[i].isEmpty=OCUPADO;
    }


}

int initCliente(Cliente listaCliente[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaCliente[i].isEmpty = LIBRE;
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

int generateIdCliente(Cliente listaCliente[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {

        if(listaCliente[i].isEmpty==LIBRE || listaCliente[i].isEmpty==ELIMINADO)
        {

            id = lastId + 1;

            break;
        }

    }

    return id;
}
int findClienteById(Cliente listaCliente[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<C;i++)
    {
//printf("\nID PARAM %d ID CLIENTE %d ESTADO %d",id,listaCliente[i].id,listaCliente[i].isEmpty);
        if(id==listaCliente[i].id && listaCliente[i].isEmpty==OCUPADO )
        {


            index=i;
           // printf("INDEX %d  I %d",index,i);
            break;
        }

    }
    return index;
}


int addCliente(Cliente listaCliente[], int tam, int id, char nombre[],char apellido[],char localidad[],int telefono, int edad, char sexo)
{
    int i, ret=-1;//generic var

    for(i=0;i<C;i++)
    {
        if(listaCliente[i].isEmpty==LIBRE || listaCliente[i].isEmpty==ELIMINADO)
        {


            listaCliente[i].id=id;
            nombre[0]=toupper(nombre[0]);
            strcpy(listaCliente[i].nombre,nombre);
            apellido[0]=toupper(apellido[0]);
            strcpy(listaCliente[i].apellido,apellido);
            localidad[0]=toupper(localidad[0]);
            strcpy(listaCliente[i].localidad,localidad);
            listaCliente[i].telefono=telefono;
            listaCliente[i].edad=edad;
            listaCliente[i].sexo=sexo;
            listaCliente[i].isEmpty=OCUPADO;
            //printf("sadsa");
            ret=0;
            break;
        }
    }

    return ret;
}



int modifyCliente(Cliente listaCliente[],int tam,int id)
{
    int i,opc, columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
    int index=findClienteById(listaCliente,C,id);
    int  edadCliente, sexoCliente, telefonoCliente;
     char nombreCliente[51], localidadCliente[51], apellidoCliente[51];

     int modificado[6]={0,0,0,0,0,0};
    if(index!=-1)
    {


    do
    {

        system("cls");
        lineaRGB(179,51);
        printf("\n");

            printf("1)Nombre\n2)Apellido\n3)Localidad\n4)Telefono\n5)Edad\n6)sexo\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,6);
        lineaRGB(179,51);
        printf("\n");
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",nombreCliente);
                nombreCliente[0]=toupper(nombreCliente[0]);
                modificado[0]=1;


                break;

            case 2:

                getString("Ingrese el apellido nuevo: ",apellidoCliente);
                apellidoCliente[0]=toupper(apellidoCliente[0]);
                 modificado[1]=1;

                break;
            case 3:
                getString("Ingrese la localidad nueva: ",localidadCliente);
                modificado[2]=1;
                localidadCliente[0]=toupper(localidadCliente[0]);
                break;
                case 4:
                telefonoCliente=getInt("Escriba el telefono nuevo:",0,0);
                modificado[3]=1;

                break;
                case 5:
                   edadCliente=getInt("Escriba la edad nueva:",0,0);
                     modificado[4]=1;

                break;
                case 6:
                sexoCliente=getGender("Ingrese el sexo de la Cliente (F o M)");

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
                            printf("\nNombre ORIGINAL [ %s ]  ----> ",listaCliente[index].nombre);

                            printf("Nombre NUEVO [ %s ]\n",nombreCliente);
                            linea(60);
                            printf("\n");

                            break;
                        case 1:
                            printf("\n");
                            linea(60);
                            printf("\n");

                             printf("Apellido ORIGINAL [ %s ] ----> ",listaCliente[index].apellido);

                            printf("Apellido NUEVO [ %s ]",apellidoCliente);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 2:
                             printf("\n");
                            linea(60);
                            printf("\n");
                            printf("Localidad ORIGINAL [ %s ] ----> ",listaCliente[index].localidad);
                            printf("Localidad NUEVO [ %s ]",localidadCliente);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 3:
                            printf("\n");
                            linea(60);
                            printf("\n");
                             printf("Telefono ORIGINAL [ %d ] ----> ",listaCliente[index].telefono);
                            printf("Telefono NUEVO [ %d ]",telefonoCliente);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 4:
                             printf("\n");
                            linea(60);
                            printf("\n");
                            printf("Edad ORIGINAL [ %d ] ----> ",listaCliente[index].edad);
                            printf("Edad NUEVO [ %d ]",edadCliente);
                            printf("\n");
                            linea(60);
                            printf("\n");
                            break;
                        case 5:
                             printf("\n");
                            linea(60);
                            printf("\n");
                             printf("Sexo ORIGINAL [ %c ] ----> ",listaCliente[index].sexo);
                            printf("Sexo NUEVO [ %c ]",sexoCliente);
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
                            strcpy(listaCliente[index].nombre,nombreCliente);

                            break;
                        case 1:
                            strcpy(listaCliente[index].apellido,apellidoCliente);


                            break;
                        case 2:
                            strcpy(listaCliente[index].localidad,localidadCliente);
                            break;
                        case 3:

                            listaCliente[index].telefono=telefonoCliente;
                            break;
                        case 4:
                             listaCliente[index].edad=edadCliente;
                            break;
                        case 5:
                            listaCliente[index].sexo=sexoCliente;
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



int printOneCliente(Cliente listaCliente[], int tam, int id)
{
    int index=findClienteById(listaCliente,tam, id);


            if(index>=0)
            {   columna();
                columna();
                    printf(" %6d  ",listaCliente[index].id);
                    columna();
                    printf(" %36s  ",listaCliente[index].nombre);
                    columna();
                    printf(" %36s  ",listaCliente[index].apellido);
                    columna();
                    printf(" %20s  ",listaCliente[index].localidad);
                    columna();
                    printf(" %12d  ",listaCliente[index].telefono);
                    columna();
                    printf(" %6d  ",listaCliente[index].edad);
                    columna();
                    printf(" %6c  ",listaCliente[index].sexo);
                columna();
                columna();
                printf("\n");

            }




    return index;
}
void membreteClientes()
{

    linea(154);
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
    columna();
    printf("\n");
    linea(154);
    printf("\n");
}
int printClientes(Cliente listaCliente[], int tam)
{
    int i, ret=-1,printRet=-1;
    printf("\n");
    membreteClientes();
   for(i=0; i<C; i++)
   {

       if(listaCliente[i].isEmpty==OCUPADO)
       {

            //printf("\nID CLIENTE %d",listaCliente[i].id);

            printRet = printOneCliente(listaCliente, C, listaCliente[i].id);

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
