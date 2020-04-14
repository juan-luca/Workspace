

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void getStringUpper(char dato[], char mensaje[]);


int main()
{
 char apellido[62] ;
    char nombre[30];
    char coma[32];

    strcpy(coma,", ");
    getStringUpper(apellido, "\nIngrese el apellido: ");
    getStringUpper(nombre, "\nIngrese el nombre: ");
    strcat(coma,nombre);
    strcat(apellido,coma);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 175);
    printf("\nEl nombre completo es: %s",apellido);
    SetConsoleTextAttribute(hConsole, 7);



    return 0;
}



void getStringUpper(char dato[], char mensaje[])
{
    int len, i;
     printf("%s", mensaje);
        fflush(stdin);

     fgets(dato, 30, stdin);

     len = strlen(dato);

     dato[len-1] = '\0';

    dato[0]= toupper(dato[0]);
    while(dato[len]!='\0')
    {

       len++;
    }

    for(i=0;i<len;i++)
    {

        if(dato[i]==' ')
        {
           dato[i+1]= toupper(dato[i+1]);

        }
    }
}









