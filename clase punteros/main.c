#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *pEntero;

    pEntero = (int*) malloc(sizeof(int));

     if(pEntero != NULL)
    {
        *pEntero = 105;


        printf("%d",*pEntero);
    }

    return 0;
}

