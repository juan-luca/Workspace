
/*Defina una estructura que posea un dato de tipo int, un float y una cadena de caracteres.
Confeccionar una función que permita ordenar un array del tipo de dato definido,
por el atributo de tipo cadena, de la A-Z y ante igualdad de criterio, por el atributo flotante
, de mayor a menor. Mostrar los datos por medio de otra función. **/


#include <stdio.h>
#include <string.h>

typedef struct
{
   int edad;
float altura;
char nombre[100];

}eDatos;

typedef struct{

   char vocal;
   int contador;
}eVocales;



void hardcodeo(eDatos persona[]);
void mostrarHardcodeo(eDatos persona[], int tam);
void ordenar(eDatos persona[],int tam);
void MasCantidadVocales(eVocales vocales[], int tam, char texto[]);


int main()
{
   eDatos persona[4];
   eVocales vocales[5]={{'a',0},{'e',0},{'i', 0},{'o', 0},{'u',0}};
   hardcodeo(persona);
   char texto[20];



   printf("Hello World\n");

   ordenar(persona, 4);
   mostrarHardcodeo(persona, 4);

   printf("ingrese\n");
   fgets(texto, 20, stdin);

    MasCantidadVocales(vocales, 5, texto);


    return 0;
}
void hardcodeo(eDatos persona[])
{

   int edad[4]={10,15,20,5};
   char nombre[4][100]={"juan", "juan", "aico", "na"};
   float altura[4]={1.78, 1.99, 1.49, 1.49 };
    int i;
    for(i=0;i<4;i++)
    {
        persona[i].edad=edad[i];
        strcpy(persona[i].nombre, nombre[i]);
        persona[i].altura=altura[i];

    }

}
void ordenar(eDatos persona[],int tam)
{
    int i;
    int j;
    eDatos aux;

    for(i=0; i<tam-1; i++)
    {

        for(j=i+1; j<tam;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0||strcmp(persona[i].nombre,persona[j].nombre)==0 && persona[i].altura < persona[j].altura)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;

            }
        }
    }

}

void mostrarHardcodeo(eDatos persona[],int tam)
{
    int i;

    for(i=0; i<tam;i++)
    {
        printf("%8d %20s %8.2f\n", persona[i].edad, persona[i].nombre, persona[i].altura);

    }

}
void MasCantidadVocales(eVocales vocales[], int tam, char texto[])
{
    int i;
    int j;
    int maximo;

    for (i=0; i<tam; i++)
    {

        for(j=0; texto[j]!='\0'; j++)
        {
            if(texto[j] == vocales[i].vocal)
            {
                vocales[i].contador++;
            }
        }

        printf("%c : %d\n",vocales[i].vocal,vocales[i].contador);
    }

    for(i=0;i<tam;i++)
    {
        if(maximo<vocales[i].contador|| i==0)
        {
            maximo=vocales[i].contador;
        }
    }

    printf("Maximo:%d\n",maximo);


}







