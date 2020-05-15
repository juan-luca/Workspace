#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int entero;
  char cadena[6];
  float flotante;
} Parcial;

int main()
{

Parcial parcial[5];

    int entero[5]={100,200,300,400,500};
  char cadena[5][51] = {"Juan.","Maria.","Ana.","Juan.","Luisa."};
  int flotante[5] = {50.5,11.2,23.8,56.1,80.032};
  int i;
printf("PARRAFO\n Los vectores estan alojados en una direccion de memoria la cual para acceder se debe pasar por referencia, osea *vector eso nos daria como resultado la direccion de memoria del vector que es pasada por referencia");
  for(i=0; i<5; i++)
  {


      parcial[i].entero = entero[i];
      parcial[i].flotante = flotante[i];
      fflush(stdin);
      strcpy(parcial[i].cadena, cadena[i]);
        //parcial[i].cadena[6-1] = '\0';

  }

  printParcial(parcial, 5);




 ordenarCadena(parcial, 5);
 printParcial(parcial, 5);

 /*for(i=0;i<5;i++)
 {
     contarVocales(parcial[i].cadena, 51);
 }*/
 contarVocales(parcial[0].cadena, 51);






    return 0;
}


void printParcial(Parcial parcial[], int tam)
{
    int i;
    printf("\nENTERO\tCADENA\t\tFLOTANTE\n");
    for(i=0;i<tam;i++)
    {
        printf("%d\t%s\t\t%f\n",parcial[i].entero,parcial[i].cadena,parcial[i].flotante);
    }
}


void ordenarCadena(Parcial listado[], int tam)
{
    int i;
    int j;
    Parcial auxParcial;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].cadena,listado[j].cadena)>0)
            {
                auxParcial = listado[i];
                listado[i] = listado[j];
                listado[j] = auxParcial;
            }else
            {
                if(strcmp(listado[i].cadena,listado[j].cadena)==0)
                {
                    if(listado[i].flotante<listado[j].flotante)
                    {
                        auxParcial = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxParcial;
                    }
                }
            }
        }

    }

}

void contarVocales(char cadena[], int tam)
{
    int  j,contvoc=0,  a=0,e=0,i=0,o=0,u=0;

    for(j=0;j<tam;j++)
    {
        printf("\nletra %c",cadena[j]);
        if(strcmp(cadena[j],'.')==0)
        {
            break;
        }
        switch(cadena[j]){
            case '0/':continue; break;
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
            case 'A': a++; break;
            case 'E': e++; break;
            case 'I': i++; break;
            case 'O': o++; break;
            case 'U': u++; break;
            //default: break;

         }


    }

    printf("\nCANTIDAD VOCALES  de %s ",cadena);
            contvoc=0;
             printf("\n VOCAL   \t   Repite");
      printf("\n  A      \t    %d",a);
      printf("\n  E      \t    %d",e);
      printf("\n  I      \t    %d",i);
      printf("\n  O      \t    %d",o);
      printf("\n  U      \t    %d",u);

      a=0;
      e=0;
      i=0;
      o=0;
      u=0;


    }




//Los vectores estan alojados en una direccion de memoria la cual para acceder se debe pasar por referencia, osea *vector eso nos daria como resultado la direccion de memoria del vector que es pasada por referencia
