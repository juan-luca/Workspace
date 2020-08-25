#include "productos.h"

void hardCodearProd(eProducto listado[], int tam)
{
  int id[10]={1,2,3,4,5,6,7,8,9,10};
  char nombre[10][20] = {"pepas","oreo","okebon","vainillas","alfajores","pepitos","melitas","chocolinas","lincoln","donuts"};
  int precio[10]={10,4,9,8,7,54,76,87,231,78};
  int stock[10]={3,2,7,8,9,1,4,5,2,7};
  int idProv[10]={100,102,102,101,100,102,102,101,101,101};
  int i;

  for(i=0; i<10; i++)
  {
      listado[i].idProd = id[i];
      strcpy(listado[i].nombre, nombre[i]);
      listado[i].precio = precio[i];
      listado[i].stock = stock[i];
      listado[i].idProv = idProv[i];
      listado[i].estado = OCUPADO;
  }

    //listado[3].estado = LIBRE;

}

void hardCodearProv(eProveedor listado[], int tam)
{
  int id[4]={100,101,102,103};
  char nombre[4][20] = {"Gallo de oro","Felfort","Arcor","Bagley"};
  char localidad[4][20]={"Caba","GBA","La matanza","Lomas de zamora"};
  int i;

  for(i=0; i<4; i++)
  {
      listado[i].idProv = id[i];
      strcpy(listado[i].nombre, nombre[i]);
      strcpy(listado[i].localidad, localidad[i]);
      listado[i].estado = OCUPADO;
  }

    //listado[3].estado = LIBRE;

}

void mostrarProvConSusProductos(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov)
{
    int i;//prov
    int j;//prod
    int resprod=0;
    //Tener en cuenta que hay alumnos que pueden estar dados de baja
    //Tener en cuenta que hay cursos que pueden estar dados de baja
    for(i=0; i<sizeprov; i++)
    {
        printf("Proveedor: %10s\n",proveedores[i].nombre);
        for(j=0; j<sizeprod; j++)
        {
            //printf("\n%d",productos[j].idProv);
            //printf("222222222");
            if(productos[j].idProv /*FK*/ == proveedores[i].idProv /*PK*/)
            {
                printf("\n%4d %15s %4d %4d\n", productos[j].idProd, productos[j].nombre, productos[j].precio, productos[j].stock);
            resprod++;
            }
        }
        if(resprod==0)
        {
            printf("NO HAY PRODUCTOS.");
        }
        resprod=0;
    }


}

void mostrarProvConMasProd(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov)
{
    int i;//prov
    int j;//prod
    int ii;
    int resprodA=0;
    int resprodB=0;
    int maxindex=0;
    //Tener en cuenta que hay alumnos que pueden estar dados de baja
    //Tener en cuenta que hay cursos que pueden estar dados de baja

    for(i=0; i<sizeprov; i++)
    {

        for(j=0; j<sizeprod; j++)
        {

            if(productos[j].idProv /*FK*/ == proveedores[i].idProv /*PK*/)
            {

                resprodA++;
            }

        }

        for(ii=i+1; ii<sizeprov; ii++)
        {



                for(j=0; j<sizeprod; j++)
                {

                    if(productos[j].idProv /*FK*/ == proveedores[ii].idProv /*PK*/)
                    {

                        resprodB++;
                    }

                }

        }

        if(resprodA<resprodB)
        {
            maxindex=i;
        }else
        {
            maxindex=ii;
        }


    }
        printf("\nMAXINDEX = %d",maxindex);
        printf("\nProveedor con  mas productos: %10s\n",proveedores[maxindex].nombre);






}


int getInt(char mensaje[], int min, int max)
{

    int ValorEntero=0;
    int noValidar=0;

    if(min==0 && max==0)
    {
        noValidar=1;
    }

    printf("%s \n",mensaje);
    fflush(stdin);
    scanf("%d",&ValorEntero);





    if(noValidar==0)
    {
    while(ValorEntero < min || ValorEntero > max)
    {
        printf("\nError, %d",mensaje);
        scanf("%d",&ValorEntero);
    }
    }



    return ValorEntero;
}

