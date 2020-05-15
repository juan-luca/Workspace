#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1


//-----------------------------------Funciones genericas
void hardCodearEmpleados(eEmployee listado[], int tam)
{
  int id[5]={100,200,300,400,500};
  char name[5][51] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char lastName[5][51] = {"santoliquido","lopez","cervantes","rocha","martinez"};;
  int sector[5] = {101,100,101,102,100};
  float salary[5] = {21515.9,899546.8,2215.7,334.6,12155.5};
  int i;

  for(i=0; i<5; i++)
  {
      listado[i].id = id[i];
      listado[i].salary = salary[i];
      strcpy(listado[i].name, name[i]);
      strcpy(listado[i].lastName, lastName[i]);
      listado[i].sector = sector[i];
      listado[i].isEmpty = OCUPADO;
  }



}


int initEmployees(eEmployee listaEmployee[], int tam)
{
    int i,ret=-1;

  for(i=0; i<tam; i++)
  {
      listaEmployee[i].isEmpty = LIBRE;
  }
  if(i==tam)
  {
        ret= 0; //ok
  }else
  {
      ret= -1;// error
  }
  return ret;
}
int generateIdEmployee(eEmployee listaEmployee[], int tam, int lastId)
{
    int id=-1, i;
    for(i=0;i<tam;i++)
    {
        if(listaEmployee[i].isEmpty==0)
        {
            id = lastId + 100;
            break;
        }
    }
    return id;
}
int findEmployeeById(eEmployee listaEmployee[], int tam, int id)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(id==listaEmployee[i].id)
        {
            index=i;
            break;
        }

    }
    return index;
}
int addEmployee(eEmployee listaEmployee[], int tam, int id, char name[],char lastName[],float salary,int sector)
{
    int i, ret=-1;
    for(i=0;i<tam;i++)
    {
        //printf("I VALE %d\n",i);
        if(listaEmployee[i].isEmpty==LIBRE)
        {
           // printf("I VALE %d\n",i);
            printf("%d\t%s\t%s\t%f\t%d\nI VALE = %d\n",id,name,lastName,salary,sector,i);
            listaEmployee[i].id=id;

            strcpy(listaEmployee[i].name,name);
            strcpy(listaEmployee[i].lastName,lastName);
            listaEmployee[i].salary=salary;
            listaEmployee[i].sector=sector;
            listaEmployee[i].isEmpty=OCUPADO;

            printOneEmployee(listaEmployee, tam, id);
            ret=0;
            break;
        }
    }

    return ret;
}
int removeEmployee(eEmployee listaEmployee[], int tam, int id)
{
    int i, ret=-1;
    int index=findEmployeeById(listaEmployee,tam, id);
   for(i=0; i<tam; i++)
   {
       if(index==i)
       {
           listaEmployee[i].isEmpty=ELIMINADO;
           ret=0;
           break;
       }else
       {
           ret = -1;
       }

   }
    return ret;
}


int modifyEmployee(eEmployee listaEmployee[],int tam,int id)
{
    int i,opc, columnaModificar, ret=-1;//AGREGAR SELECCION DE COLUMNA A MODIFICAR
   int sector;
   float salary;
   char nombre[51], apellido[51];
int index=findEmployeeById(listaEmployee,tam,id);
     int modificado[4]={0,0,0,0};//
    if(index!=-1)
    {



    do
    {

                    system("cls");


            printf("1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,4);
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",nombre);
                modificado[0]=1;

                break;

            case 2:
                getString("Ingrese el apellido nuevo: ",apellido);
              modificado[1]=1;
                break;
            case 3:
                salary=getInt("Escriba el salario nuevo:",0,0);
                modificado[2]=1;
                break;
            case 4:
                sector=getInt("Escriba el sector nuevo:",0,0);
                modificado[3]=1;
                break;


            }
    }while(columnaModificar!=0);

    setSucces("Desea realizar las siguientes modificaciones? (SI=1 o NO=2)",0);

                    for(i=0;i<4;i++)
                    {
                        if(modificado[i]==1)
                        {


                        switch(i)
                        {
                        case 0:
                            setSucces("Nombre ORIGINAL",0);
                            printf(" %s ",listaEmployee[index].name);
                            setSucces("Nombre NUEVO",0);
                            printf(" %s ",nombre);
                            break;
                        case 1:
                             setSucces("Apellido ORIGINAL",0);
                            printf(" %s ",listaEmployee[index].lastName);
                            setSucces("Apellido NUEVO",0);
                            printf(" %s ",apellido);
                            break;
                        case 2:
                             setSucces("Salario ORIGINAL",0);
                            printf(" %f ",listaEmployee[index].salary);
                            setSucces("Salario NUEVO",0);
                            printf(" %f ",salary);
                            break;
                        case 3:
                             setSucces("Sector ORIGINAL",0);
                            printf(" %d ",listaEmployee[index].sector);
                            setSucces("Sector NUEVO",0);
                            printf(" %d ",sector);
                            break;

                        }
                        }
                    }

    opc=getInt("",1,2);
    if(opc==1)
    {
        ret=0;
        for(i=0;i<6;i++)
        {
                if(modificado[i]==1)
                {


                    switch(i)
                    {
                        case 0:
                            strcpy(listaEmployee[index].name,nombre);

                            break;
                        case 1:
                            strcpy(listaEmployee[index].lastName,apellido);


                            break;
                        case 2:
                            listaEmployee[index].salary=salary;
                            break;
                        case 3:

                            listaEmployee[index].sector=sector;
                            break;

                    }
                }
        }
        ret=0;
    }else
    {
        ret=-1;
    }


}
    return ret;
}


int printOneEmployee(eEmployee listaEmployee[], int tam, int id)
{
    int index=findEmployeeById(listaEmployee,tam, id);


            if(index>=0)
            {
                    printf("%4d %15s %15s %12.2f %4d\n",listaEmployee[index].id,listaEmployee[index].name,listaEmployee[index].lastName, listaEmployee[index].salary,listaEmployee[index].sector);
            }




    return index;
}
int printEmployees(eEmployee listaEmployee[], int tam)
{
    int i, ret=-1,printRet=-1;
    printf("ID         Nombre         Apellido      Salario  Sector\n");
   for(i=0; i<tam; i++)
   {

       if(listaEmployee[i].isEmpty==OCUPADO)
       {

            printRet = printOneEmployee(listaEmployee, tam, listaEmployee[i].id);
          if(printRet==-1)
          {
              setError("Registro no encontrado",0);
              ret=-1;
          }else
          {
              ret=0;
          }
       }
   }
    return ret;
}


void MenuABM(eEmployee listaEmployee[], int tam)
{
    int opc, id,sector, succesAdd=1, lastId=500,order;
    float salary;
    char name[51],lastName[51];

        if(initEmployees(listaEmployee,tam)==0)
        {
            setSucces("Inicializado con exito",1);
            hardCodearEmpleados(listaEmployee,  tam);
        }else
        {
            setError("ERROR EN LA INICIALIZACION",0);
        }


    do
    {
      printf("1)ALTAS\n");
      printf("2)MODIFICAR\n");
      printf("3)BAJA\n");
      printf("4)INFORMAR\n");

      printf("0)Salir\n");
      opc=getInt("Seleccione una opcion:",0,7);

      switch(opc)
      {
            case 1://HACER CARGA DE A 1 REGISTRO
                    // Preguntar cuantos empleados
                    id=generateIdEmployee(listaEmployee,tam,lastId);
                    lastId=id;
                    if(id!=-1)//Solo entra si hay lugar
                    {
                        getString("Ingrese el nombre: ",name);
                        getString("Ingrese el apellido: ",lastName);
                        salary=getFloat("Ingrese el salario: ", 0,0);
                        sector=getInt("Ingrese el sector: ",0,0);
                        if(addEmployee(listaEmployee,tam, id,name,lastName,salary,sector)==0)
                        {
                            succesAdd=1;
                            printEmployees(listaEmployee,tam);
                            setSucces("Se cargo el empleado con exito",1);
                        }else
                        {
                            setError("ERROR EN LA CARGA.",0);
                        }
                    }else
                        {
                            setError("ERROR, No se encontro lugar disponible.",0);
                        }



                break;
            case 2:
                //MODIFICAR

                if(succesAdd==1)
                {
                        id=getInt("Ingrese el ID a eliminar.",100,100000);
                        if(modifyEmployee(listaEmployee,tam, id)==0)
                        {

                            setSucces("El empleado se modifico con exito",1);
                        }else
                        {
                            setError("No se produjo ningun cambio.",0);
                        }
                }else
                {
                    setError("Primero debe ingresar los empleados en la opcion 1.",0);
                }


                break;
            case 3:
                //ELIMINAR


                if(succesAdd==1)
                {
                    id=getInt("Ingrese el ID a eliminar.",100,100000);
                        if(removeEmployee(listaEmployee,tam, id)==0)
                        {

                            setSucces("El empleado se elimino con exito",1);
                        }else
                        {
                            setError("ERROR EN LA ELIMINACION.",0);
                        }

                }else
                {
                    setError("Primero debe ingresar los empleados en la opcion 1.",0);
                }
                break;
            case 4:

               if(succesAdd==1)
                {
                    printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
                    printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
                     opc=getInt("Ingrese la opcion deseada.",1,2);
                     switch(opc)
                     {
                     case 1:
                         setSucces("1=Ascendente",0);
                         setSucces("2=Decendente",0);
                         order=getInt("Ingrese el orden que desea establecer",1,2);


                         if(sortEmployees(listaEmployee, tam , order )!=-1)
                         {
                             printEmployees(listaEmployee,tam);
                         }else
                         {
                             //printf("sort== %d",sort);
                             setError("No se pudo ordenar el listado completo",0);
                         }



                        break;

                     case 2:

                         if(salaryQuery(listaEmployee, tam)!=-1)
                         {
                             printEmployees(listaEmployee,tam);
                         }else
                         {
                             //printf("sort== %d",sort);
                             setError("No se pudo ordenar el listado completo",0);
                         }

                        break;
                     }


                }else
                {
                    setError("Primero debe ingresar los empleados en la opcion 1.",0);
                }
                break;

      }
        system("pause");
      system("cls");
      }while(opc!=0);

      }

int sortEmployees(eEmployee listaEmployee[], int tam , int order )
{


int i, ret=-1,j;
eEmployee auxEmployee;

for(i=0; i<tam-1; i++)
   {
        for(j=i+1; j<tam; j++)
        {
            if(order==1)
            {
                        if(strcmp(listaEmployee[i].lastName,listaEmployee[j].lastName)>0)
                        {
                            auxEmployee = listaEmployee[i];
                            listaEmployee[i] = listaEmployee[j];
                            listaEmployee[j] = auxEmployee;
                        }else
                        {
                            if(strcmp(listaEmployee[i].lastName,listaEmployee[j].lastName)==0)
                            {
                                if(listaEmployee[i].sector>listaEmployee[j].sector)
                                {
                                    auxEmployee = listaEmployee[i];
                                    listaEmployee[i] = listaEmployee[j];
                                    listaEmployee[j] = auxEmployee;
                                }
                            }
                        }



            }else
            {
                if(strcmp(listaEmployee[i].lastName,listaEmployee[j].lastName)<0)
                        {
                            auxEmployee = listaEmployee[i];
                            listaEmployee[i] = listaEmployee[j];
                            listaEmployee[j] = auxEmployee;
                        }else
                        {
                            if(strcmp(listaEmployee[i].lastName,listaEmployee[j].lastName)==0)
                            {
                                if(listaEmployee[i].sector<listaEmployee[j].sector)
                                {
                                    auxEmployee = listaEmployee[i];
                                    listaEmployee[i] = listaEmployee[j];
                                    listaEmployee[j] = auxEmployee;
                                }
                            }
                        }

            }

        }



   }
   if(i==tam-1)
    {
            ret = 0;
    }
   return ret;
   }

int salaryQuery(eEmployee listaEmployee[], int tam)
{


int i, ret=-1,j,upSalaryEmployee=0,employeeCount=0;
float totalSalary=0,promSalary=0;

    for(i=0; i<tam; i++)
   {
       if(listaEmployee[i].isEmpty==1)
       {
           totalSalary= totalSalary + listaEmployee[i].salary;
           employeeCount++;
       }



   }
   promSalary=totalSalary/employeeCount;
   //printf("tam %d\n",tam);
   for(j=0; j<tam; j++)
   {
       if(listaEmployee[j].isEmpty==1)
       {


    if(listaEmployee[j].salary>promSalary)
    {
     upSalaryEmployee++;
     ret = 0;
    }
    }

   }
   printf("Salario promedio %10.2f\n",promSalary);
   printf("%d empleados tienen el salario mayor al promedio\n",upSalaryEmployee);


   return ret;
   }



//*************************************Funciones genericas
