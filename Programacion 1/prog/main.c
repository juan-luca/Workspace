#include <stdio.h>
#include <stdlib.h>
#define P 3
#define L 3


/*
Armar un párrafo en donde se pueda ver la relación entre los siguientes
términos:
 Función
 Recursividad
 Pila
 Parámetro formal
 Parámetro actual
2. Trabajar con las siguientes entidades: Persona (dni, nombre y localidad) y
Localidad (id, descripción y código postal) . Realizar las funciones necesarias
para poder relacionar cada persona con una localidad. Hardcodear coda
entidad (con la cantidad de datos que ud desee) y generar un listado de
personas ordenadas por nombre y luego por localidad.
*/
typedef struct
{
    char dni[50];
    char nombre[50];
    int localidad;
}ePersona;

typedef struct
{
    int id;
    char descripcion[150];
    int codigoPostal;
}eLocalidad;

void Ordenar(ePersona* lista[],int len);
void listarPersonas(ePersona* persona, int tamPersona,eLocalidad* localidad,int tamLocalidad);

int main()
{
    ePersona* persona[P]={ {"39242857","maximiliano",1}, {"39656666", "german" , 2}, {"35646458","octavio",3} };
    eLocalidad* localidades[L] ={ {1,"Longchamps: Ciudad zona sur",1854}, {3, "Burzaco: CIUDAD ZONA SUR DE AMBA" , 1666}, {2,"HURLINGHAM CIUDAD NORTE",1332} };

    listarPersonas(persona,P,localidades,L);
}
/*
void Ordenar(eDato lista[],int len)
{
    int i;
    int j;
    eDato aux;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(lista[i].num1>lista[j].num1)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
            else
            {
                if(lista[i].num1==lista[j].num1 && strcmp(lista[i].algo,lista[j].algo)>0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }

            }
        }
    }


}
*/
void listarPersonas(ePersona* persona, int tamPersona,eLocalidad* localidad,int tamLocalidad)
{
    int i;
    int j;
    for(i=0;i<tamPersona;i++)
    {
        for (j=0;j<tamLocalidad;j++)
        {
                   if(persona[i]->localidad == localidad[j]->id)
        {
                    printf("%s , %s , %s\n",persona[i]->dni,persona[i]->nombre,localidad[i]->descripcion);
        }

        }

    }
}
