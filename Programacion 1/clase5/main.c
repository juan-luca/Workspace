#include <stdio.h>
#define T 10

void cargarNumeros(int [], int tam);
float calcularPromedio(int [], int tam);
int calcularMaximo(int [], int tam);
void mostrarNumeros(int pepe[], int tam);
void inicializarArray(int miArray[], int tam);
int CantidadDeCargados(int miArray[], int tam);
int SumaDeElementos(int miArray[], int tam);
int calcularMinimo(int vector[], int tam);
int calcularPares(int vector[], int tam);
int calcularImpares(int vector[], int tam);
int calcularPositivos(int vector[], int tam);
int calcularNegativos(int vector[], int tam);
float promedioPositivos(int vector[], int tam);
float promedioNegativos(int vector[], int tam);
int calcularPrimos(int vector[], int tam);

/*
minimo
pares /impares
positivos/negativos
primos
promedio de negativos/ positivos
validaciones
*/

int main ()
{
  int numeros[T];
  float promedio;
  int maximo;
  int minimo;
  int pares;
  int impares;
  int positivos;
  int negativos;
  int primos;
  float promediopositivos;
  float promedionegativos;



  inicializarArray(numeros, T);
  cargarNumeros(numeros, T);


  promedio = calcularPromedio(numeros,T);
  printf("\nEl promedio es: %.1f\n", promedio);
  maximo = calcularMaximo(numeros,T);
  printf ("El maximo es: %d\n", maximo);
  minimo = calcularMinimo(numeros,T);
  printf("El minimo es: %d\n", minimo);
  pares = calcularPares(numeros,T);
  printf("La cantidad de pares es: %d\n", pares);
  impares = calcularImpares(numeros,T);
  printf("La cantidad de impares es: %d\n", impares);
  positivos = calcularPositivos(numeros,T);
  printf("La cantidad de positivos es: %d\n", positivos);
  negativos = calcularNegativos(numeros,T);
  printf("La cantidad de negativos es: %d\n", negativos);
  primos = calcularPrimos(numeros,T);
  printf("La cantidad de primos es: %d\n", primos);
  promediopositivos = promedioPositivos(numeros,T);
  printf("El promedio de positivos es: %.1f\n", promediopositivos);
  promedionegativos = promedioNegativos(numeros,T);
  printf("El promedio de negativos es: %.1f\n\n", promedionegativos);

  mostrarNumeros(numeros, T);

  return 0;
}

int SumaDeElementos(int miArray[], int tam)
{
    int i;
    int AcumuladorDeCargados=0;
    for (i = 0; i < tam; i++)
    {
        if(miArray[i]!=-1)
        {
            AcumuladorDeCargados=AcumuladorDeCargados+miArray[i];
        }
    }
    return AcumuladorDeCargados;
}

int CantidadDeCargados(int miArray[], int tam)
{
    int i;
    int contadorDeCargados=0;
    for (i = 0; i < tam; i++)
    {
        if(miArray[i]!=-1)
        {
            contadorDeCargados++;
        }
    }
    return contadorDeCargados;
}

void cargarNumeros(int vector[], int tam)
{
    int i;
    int flag=0;

    do
    {
    for (i = 0; i < tam; i++)
    {
      if(flag==0)
      {
      printf ("Ingrese un numero entre -100 y 100: ");
      scanf ("%d", &vector[i]);
      }
      if(vector[i] < -100 || vector[i] >100)
      {
      flag=1;
      printf ("Error, por favor reingrese un numero entre -100 y 100: ");
      scanf ("%d", &vector[i]);
      flag=0;
      }
    }
    }while(vector[i] < -100 || vector[i] >100);
}

void inicializarArray(int miArray[], int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
      miArray[i]=-1;
    }

}

float calcularPromedio(int vector[], int tam)
{

    int i;
    int acumuladorNumeros;
    int cantidadDeNumeros;
    float promedio;

    acumuladorNumeros=SumaDeElementos(vector,tam);
    cantidadDeNumeros=CantidadDeCargados(vector,tam);
    promedio = (float)acumuladorNumeros/cantidadDeNumeros;

    return promedio;
    /*
    return  (float) SumaDeElementos(vector,tam)/CantidadDeCargados(vector,tam);
    */

}

int calcularMaximo(int vector[], int tam)
{
    int i;
    int maximo;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] > maximo || i == 0)
    	{
    	  maximo = vector[i];
    	}
    }


    return maximo;

}

void mostrarNumeros(int vector[], int tam)
{
    int i;
      for (i = 0; i < tam; i++)
    {

      printf ("%d\n", vector[i]);
    }

}

int calcularMinimo(int vector[], int tam)
{
    int i;
    int minimo;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] < minimo || i == 0)
    	{
    	  minimo = vector[i];
    	}
    }


    return minimo;

}

int calcularPares(int vector[], int tam)
{
    int i;
    int pares=0;


  for (i = 0; i < T; i++)
    {
      if (vector[i] %2==0)
    	{
    	  pares++;
    	}
    }


    return pares;
}

int calcularImpares(int vector[], int tam)
{
    int i;
    int impares=0;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] %2!=0)
    	{
    	  impares++;
    	}
    }


    return impares;
}

int calcularPositivos(int vector[], int tam)
{
    int i;
    int positivos=0;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] > 0)
    	{
    	  positivos++;
    	}
    }


    return positivos;
}

int calcularNegativos(int vector[], int tam)
{
    int i;
    int negativos=0;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] < 0)
    	{
    	  negativos++;
    	}
    }


    return negativos;
}

float promedioPositivos(int vector[], int tam)
{
    int i;
    int contadorpositivos=0;
    int acumuladorpositivos=0;
    float promedio=0;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] > 0)
    	{
          acumuladorpositivos+=vector[i];
    	  contadorpositivos++;
    	}
    }
    if(contadorpositivos==0)
    {
        promedio=0;
    }else
    {
    promedio=(float)acumuladorpositivos/contadorpositivos;
    }

    return promedio;
}

float promedioNegativos(int vector[], int tam)
{
    int i;
    int contadornegativos=0;
    int acumuladornegativos=0;
    float promedio=0;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] < 0)
    	{
          acumuladornegativos+=vector[i];
    	  contadornegativos++;
    	}
    }
    if(contadornegativos==0)
    {
        promedio=0;
    }else
    {
    promedio=(float)acumuladornegativos/contadornegativos;
    }

    return promedio;
}

int calcularPrimos(int vector[], int tam)
{
    int i;
    int primos=0;


  for (i = 0; i < tam; i++)
    {
      if (i%vector[i]==0 && vector[i]%1==0)
    	{
          primos++;
    	}
    }

    return primos;
}

