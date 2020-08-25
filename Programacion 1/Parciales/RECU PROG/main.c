#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


 typedef struct
{
    int entero;
    float flotante;
    char cadena[51];
}edato;



int main()
{

edato parcial[5];

    int entero[5]={100,200,300,400,500};
  char cadena[5][51]= {"Juan","Maria","Ana","Juan","Luisa"};
  int flotante[5] = {50.5,11.2,23.8,56.1,80.032};
  int i;

  for(i=0; i<5; i++)
  {


      parcial[i].entero = entero[i];
      parcial[i].flotante = flotante[i];
      fflush(stdin);
      strcpy(parcial[i].cadena, cadena[i]);
      printf("\n %d  float %f   cadena %s",parcial[i].entero, parcial[i].flotante, parcial[i].cadena);


  }


    /*char cadena[31];
    getString("Ingrese una palabra",cadena);

    contarVocales(cadena);*/


    return 0;
}

int ordenardato(edato listado[],int tam)
{
    int j;
    int i;
    edato auxdato;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].cadena,listado[j].cadena)>0)
            {
                auxdato = listado[i];
                listado[i] = listado[j];
                listado[j] = auxdato;
            }else
            {
                if(strcmp(listado[i].cadena,listado[j].cadena)==0)
                {
                    if(listado[i].flotante>listado[j].flotante)
                    {
                        auxdato = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxdato;
                    }

                }

            }
        }

    }

    return 0;
}
void contarVocales(char cadena[])
{
    int  j,contvoc=0,  a=0,e=0,i=0,o=0,u=0;

    for(j=0;cadena[j]!='\0';j++)
    {
        cadena[j]=tolower(cadena[j]);


        printf("\nletra %c\n",cadena[j]);

        switch(cadena[j]){

            case 'a': a++;
            break;
            case 'e': e++;
            break;
            case 'i': i++;
            break;
            case 'o': o++;
            break;
            case 'u': u++;
            break;




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

    void getString(char msg[], char String[])
    {

        int tam;
        do
        {


        printf("%s\n", msg);
        fflush(stdin);
        fgets(String, 31, stdin);
        tam = strlen(String);
        String[tam-1] = '\0';
        }while(strcmp("",String)==0);
}
