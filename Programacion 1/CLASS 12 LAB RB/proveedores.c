#include "proveedores.h"
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
void iniProvProd(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov, ProvProd listpp[])
{
  int i;//prov
    int j;//prod
    int cantprods=0;

    for(i=0; i<sizeprov; i++)
    {
        cantprods=0;
        for(j=0; j<sizeprod; j++)
        {

            if(productos[j].idProv /*FK*/ == proveedores[i].idProv /*PK*/)
            {
            cantprods++;
            }
        }
        listpp[i].idProv = proveedores[i].idProv;
        listpp[i].cantProd = cantprods;

        printf("\n Proveedor %d cantidad de productos %d ",listpp[i].idProv,listpp[i].cantProd);



    }

}

void mostrarProvConSusProductos(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov)
{
    int i;//prov
    int j;//prod
    int resprod;

    for(i=0; i<sizeprov; i++)
    {
        //resprod=0;
        printf("Proveedor: %10s\n",proveedores[i].nombre);
        for(j=0; j<sizeprod; j++)
        {

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

    }


}

void mostrarProvConMasProd(eProducto productos[], int sizeprod, eProveedor proveedores[], int sizeprov, ProvProd listpp[])
{
    int i;//prov
    int j;//prod
    int index;
    int resprodA=0;
    int MaxProds=0;
    int idProvMax=0;

    for(i=0; i<sizeprov; i++)
    {
        for(j=0; j<sizeprod; j++)
        {

            if(productos[j].idProv /*FK*/ == proveedores[i].idProv /*PK*/)
            {
            resprodA++;
            }
        }
        printf("\n El prov %d tiene %d productos",proveedores[i].idProv, resprodA);

        if(resprodA > MaxProds || i==0)
        {
            MaxProds=resprodA;
        }

        resprodA=0;
    }
        for(i=0;i<sizeprod;i++)
        {
            for(j=0;j<sizeprov;j++)
            {
                if(listpp[i].idProv==proveedores[j].idProv)
                {
                  index=j;
                }

            }
            if(MaxProds==listpp[i].cantProd)
            {
                printf("\nProveedor con  mas productos: %10s\n",proveedores[index].nombre);
            }

        }


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

