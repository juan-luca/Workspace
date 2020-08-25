#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <windows.h>

int main()
{
    char palabra1[15] ;
    char palabra2[15] = "arbol";


    char letra;
    int len;
    int comp;



    getString(palabra1, "Ingrese una palabra: ");

    /*
    int strlen(const char*)
    len = strlen(palabra1);
    printf("%d\n", len);
    printf("La palabra es: %s",palabra1);*/

    //char* strcpy(char*,  const char* )
    /*strcpy(palabra2,palabra1);
    puts(palabra2);*/

    //int strcmp(const char*, const char*);

    /*comp = strcmpi(palabra1, palabra2);

    printf("%d", comp);*/

    /*if(stricmp(palabra1,"Avellaneda")==0)
    {
        printf("Vive en avellaneda");
    }
    else
    {
        printf("No vive en avellaneda");
    }*/

    /*strupr(palabra1);
    //strlwr(palabra1);

    letra = tolower(palabra1[0]);

    printf("%c\n", letra);


    puts(palabra1);*/


    /*strcat(palabra2, palabra1);

puts(palabra2);*/


    int i = 0;

    while(palabra1[i]!='\0')
    {

       i++;
    }


    printf("El largo es: %d", i);


    return 0;
}


