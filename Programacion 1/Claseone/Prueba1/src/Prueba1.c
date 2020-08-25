/*
 ============================================================================
 Name        : Prueba1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num,max,min,flag=0;


	    for(int i=0;i<3;i++)
	    {
	        printf("Ingrese el numero:");
	        scanf("%d",&num);
	        if(flag==0)
	        {
	            max=num;
	            min=num;
	            flag=1;
	        }
	        if(num>max)
	        {
	            max = num;
	        }
	        if(num<min)
	        {
	            min = num;
	        }
	    }
	    printf("El menor numero es %d y el mayor es %d",min,max);
	return EXIT_SUCCESS;
}
