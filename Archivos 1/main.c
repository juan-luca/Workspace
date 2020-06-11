#include <stdio.h>
#include <stdlib.h>
#include "GeneralCommands.h"
typedef struct
{
    char usuario[50];
    char password[50];

}login;
int main()
{
    login loginList[5] = {{"juan","juan124"},{"maria","maria123"},{"jose","jose123"},{"ana","ana123"}};
    FILE* pArchivo;

    int i;

    pArchivo = fopen("registro.csv","w");



/*
for(i=0;i<3;i++)
            {
            getString("Ingrese el usuario : ",loginList[i].usuario);
            getString("Ingrese la contrasenia : ",loginList[i].password);

            }*/
    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"Usuario,Password\n");



            for(i=0;i<4;i++)
            {

            fprintf(pArchivo,"%s,%s\n", loginList[i].usuario, loginList[i].password);

            }

        fclose(pArchivo);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }


    system("cls");
    //lo lee ahora
    pArchivo = fopen ("registro.csv", "r");
        i=0;
login listFromArchive[10];
   while(!feof(pArchivo))
   {

       fscanf(pArchivo, "%[^,],%[^\n]\n", listFromArchive[i].usuario, listFromArchive[i].password);

       printf("%s - %s\n", listFromArchive[i].usuario, listFromArchive[i].password);
       i++;

   }
   char inputUser[50], inputPassword[50];

   int searchSucces=0;
   do
   {
    getString("Usuario: ",inputUser);
   getString("Password: ",inputPassword);

   for(i=0;i<5;i++)
   {
       if(strcmp(inputUser,loginList[i].usuario)==0)
       {
           if(strcmp(inputPassword,loginList[i].password)==0)
           {
               setSucces("Usuario encontrado!",0);
               searchSucces=1;
           }else
           {
               searchSucces=-1;
               setError("Contraseña invalida!",0);
           }
       }
   }
    if(searchSucces==0)
    {
        setError("Usuario no existente",0);
    }

    }while(searchSucces!=1);
   fclose(pArchivo);

    return 0;
}
