#include <stdio.h>

typedef struct
{
    int a;
    char b;
}eDato;

int main()
{

  /* eDato lista[2]={{1,'C'},{1,'F'}};

   eDato* puntero;
   int i;

   puntero = lista;

   for(i=0; i<2; i++)
   {
       printf("%d--%c\n", (*(puntero+i)).a, (*(puntero+i)).b);
   }
   */


   /*eDato miVariable = {1,'C'};
    eDato* miPuntero;

    miPuntero = &miVariable;



    printf("%d--%c", (*miPuntero).a, (*miPuntero).b);*/


/*eDato miVariable = {1,'C'};
    eDato* miPuntero;

    miPuntero = &miVariable;



    printf("%d--%c", miPuntero->a, miPuntero->b;*/

    eDato lista[2];//={{1,'C'},{1,'F'}};

   eDato* puntero;
   int i;

   puntero = lista;

   for(i=0; i<2; i++)
   {
       printf("Ingrese a: ");
      // scanf("%d", &((puntero+i)->a));
      scanf("%d", &((*(puntero+i)).a));

       __fpurge(stdin);
        printf("Ingrese b: ");
       scanf("%c", &((puntero+i)->b));
   }


   for(i=0; i<2; i++)
   {
       printf("%d--%c\n", (puntero+i)->a, (puntero+i)->b);
   }

  return 0;
}


