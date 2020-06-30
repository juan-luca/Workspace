#include <stdio.h>
#include <stdlib.h>

 typedef struct
{
    char car;
    int entero;
    char cadena[51];
}edato;


float CalcularSueldoNeto( float sueldoBruto, int porcentajeObraSocial, int porcentajeJubilacion);
void getString(char msg[], char String[]);
float getFloat(char mensaje[], float min, float max);
int getInt(char mensaje[], int min, int max);
int ordenardato(edato listado[],int tam);




int main()
{
    edato parcial[5];
    /*
    float sueldobruto;
    int porcentajeObra;
    int porcentajeJub;
    float tot;
    sueldobruto=getFloat("ingrese el sueldo bruto",0,0);
    porcentajeObra=getInt("ingrese el porcentaje de jubilacion",0,0);
    porcentajeObra=getInt("ingrese el porcentaje de obra social",0,0);
    tot=CalcularSueldoNeto(sueldobruto,porcentajeObra,porcentajeJub);
    printf("sueldo neto es %f",tot);

    */



    int entero[5]={100,200,300,400,500};
  char cadena[5][51]= {"Juan","Maria","Ana","Juan","Luisa"};
  char car[5]= {'s','w','a','r','f'};
  int i;

  for(i=0; i<5; i++)
  {


      parcial[i].entero = entero[i];
      parcial[i].car = car[i];
      fflush(stdin);
      strcpy(parcial[i].cadena, cadena[i]);
      printf("\n %d  car %c   cadena %s",parcial[i].entero, parcial[i].car, parcial[i].cadena);


  }

 ordenardato(parcial,5);


  for(i=0; i<5; i++)
  {



      printf("\n %d  car %c   cadena %s",parcial[i].entero, parcial[i].car, parcial[i].cadena);


  }



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
                    if(listado[i].car!=listado[j].car)
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



float CalcularSueldoNeto( float sueldoBruto, int porcentajeObraSocial, int porcentajeJubilacion)
{
    float tot;
    float descobra,descjub;

    descjub = (sueldoBruto * porcentajeJubilacion)/100;
     descobra = (sueldoBruto * porcentajeObraSocial)/100;
     tot=sueldoBruto-descjub-descobra;
    return tot;
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

        scanf("%d",&ValorEntero);
    }
    }



    return ValorEntero;
}

float getFloat(char mensaje[], float min, float max)
{
    float numero;
    int noValidar=0;
    if(min==0 && max==0)
    {
        noValidar=1;
    }


    printf("%s \n",mensaje);

    scanf("%f",&numero);
if(noValidar==0)
    {
        while(numero < min || numero > max)
        {

        scanf("%f",&numero);
        }
}


     return numero;
}


void getString(char msg[], char String[]){

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
