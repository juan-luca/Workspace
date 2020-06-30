#include "Informes.h"

int informeOrquesta5musicos(Orquesta Orquesta [], Musico Musico[])
{
    int i,j,cantMusicos=0,ret=-1;
    for(i=0;i<tOrquesta;i++)
    {
        for(j=0;j<tMusico;j++)
        {

            if(Musico[j].idOrquesta==Orquesta[i].id && Musico[j].isEmpty==OCUPADO)
            {
                //printf("ID DE ORQUESTA= %d DEL MUSICO=%d",Orquesta[i].id,Musico[j].id);
              cantMusicos++;
            }

        }
        if(Orquesta[i].isEmpty==OCUPADO)
        {


           // printf("\nCANTIDAD DE MUSICO: %d         ",cantMusicos);
            if(cantMusicos>=2)
            {
                printOneOrquesta(Orquesta,tOrquesta,Orquesta[i].id);
                ret=0;
            }
        }
        cantMusicos=0;
    }
    return ret;
}

int informeOrquestaByLugar(Orquesta Orquesta[])
{
    int i,ret=-1;
    char lugar[51];
    getString("Ingrese el lugar",lugar);
    for(i=0;i<tOrquesta;i++)
    {
            if(strcmp(Orquesta[i].lugar,lugar)==0)
            {
                 printOneOrquesta(Orquesta,tOrquesta,Orquesta[i].id);
                ret=0;
            }
    }

    return ret;
}

int informeMusicoByOrquesta(Orquesta Orquesta [], Musico Musico[], Instrumento Instrumento[])
{
int i,ret=-1,idorq,index;
idorq=getInt("Ingrese el ID de orquesta",0,0);
index=findOrquestaById(Orquesta,tOrquesta,idorq);
if(index!=-1)
{


        for(i=0;i<tMusico;i++)
            {
                    if(idorq==Musico[i].idOrquesta)
                    {
                         printf("%d\t%s\t\t%s\t%d\t%s\t\t%d\n",Musico[i].id,Musico[i].nombre,Musico[i].apellido, Musico[i].edad,Orquesta[index].nombre,Musico[i].idInstrumento);
                        ret=0;
                    }
            }
        }else
        {
            setError("NO SE ENCONTRO LA ORQUESTA",0);
        }
    return ret;
}
int informeOrquestaMasMusicos(Orquesta Orquesta [], Musico Musico[])
{


int i,j,cantMusicos=0,ret=-1, maxMusico=0,idMax;
    for(i=0;i<tOrquesta;i++)
    {
        if(Orquesta[i].isEmpty==OCUPADO)
        {


        for(j=0;j<tMusico;j++)
        {

            if(Musico[j].isEmpty==OCUPADO && Musico[j].idOrquesta==Orquesta[i].id)
            {

              cantMusicos++;
            }

        }

        if(maxMusico<cantMusicos || i==0)
        {
            maxMusico=cantMusicos;
            idMax=Orquesta[i].id;



        }
        cantMusicos=0;
    }
    }
    printOneOrquesta(Orquesta,tOrquesta,idMax);
    return ret;
}

int informeMusico30(Orquesta Orquesta [], Musico Musico[])
{
int ret=-1;

    return ret;
}
