
#include "GeneralCommands.h"
#include "Controller.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
int ret;
FILE* pFile;

pFile = fopen(path,"r");

ret=parser_EmployeeFromText(pFile,pArrayListEmployee);

fclose(pFile);

return ret;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
int ret;
FILE* pFile;

pFile = fopen(path,"rb");

ret=parser_EmployeeFromBinary(pFile,pArrayListEmployee);

fclose(pFile);

return ret;
}
int controller_lastId(LinkedList* pArrayListEmployee)
{
    int i;
    int lastid=0;
    int len=ll_len(pArrayListEmployee);
    int maxid=0;

    Employee* employee;
    for(i=0;i<len;i++)
    {
        employee = employee_new();

        employee = ll_get(pArrayListEmployee,i);

        employee_getId(employee,&lastid);
        if(lastid>maxid)
        {
            maxid=lastid;
        }

    }
    return maxid;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int horas;
    int sueldo;
    char nombre[128];
    int ret=-1;
    int num=0;
    int i=0;
    Employee* employee;



                    id=controller_lastId(pArrayListEmployee);
                    id++;

                    do
                    {


                    num=0;
                    i=0;
                    getString("Ingrese el nombre",nombre);

                        while(nombre[i]!='\0')
                        {
                            if(nombre[i]=='0' || nombre[i]=='1' || nombre[i]=='2' || nombre[i]=='3' || nombre[i]=='4' || nombre[i]=='5' || nombre[i]=='6' || nombre[i]=='7' || nombre[i]=='8' || nombre[i]=='9')
                            {
                               num++;

                            }
                            i++;

                        }

                        if(num>0)
                        {
                            setError("Ingrese solo letras",0);
                        }
                    }while(num>0);

                    nombre[0]=toupper(nombre[0]);

                    printf("\n");
                    linea(179);
                    printf("\n");
                    horas=getIntPos("Ingrese las horas trabajadas: ");
                    printf("\n");
                    linea(179);
                    printf("\n");
                    sueldo=getIntPos("Ingrese el sueldo: ");
                    printf("\n");
                    linea(179);
                    printf("\n");
                    employee= employee_newParametros(id,nombre,horas,sueldo);
                    ret=ll_add(pArrayListEmployee,employee);



return ret;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int lastid=controller_lastId(pArrayListEmployee);
    int queryId;
    int i;
    int opc;
    int len=ll_len(pArrayListEmployee);
    int id=0;
    int horas=0;
    int sueldo=0;
    char nombre[128];

    int horasNuevo;
    int sueldoNuevo;
    char nombreNuevo[128];
    int columnaModificar;
    int modificado[3]={0,0,0};

    Employee* employee;

    id=getInt("Ingrese el ID a modificar",0,lastid);


    for(i=0;i<len;i++)
    {
        employee = employee_new();

        employee = ll_get(pArrayListEmployee,i);

        employee_getId(employee,&queryId);

        if(id==queryId)
        {
            break;
        }

    }

        employee_getId(employee,&id);
        employee_getNombre(employee,nombre);
        employee_getHorasTrabajadas(employee,&horas);
        employee_getSueldo(employee,&sueldo);

    system("cls");
    cabecera();

    columna();
        columna();
        printf("%6.d   ", id);
        columna();
        printf("%128s    ", nombre);
        columna();
        printf("%16.d  ", horas);
        columna();
        printf("%15.d  ", sueldo);
        columna();
        columna();
        printf("\n");


    linea(184);
    printf("\n\n");





    do
    {

       printf("\n");
        lineaRGB(179,51);
        printf("\n");

            printf("1)Nombre\n2)Horas Trabajadas\n3)Sueldo\n");
            columnaModificar=getInt("Escriba el campo que desea modificar: \n Presiones 0 para salir...",0,3);
        lineaRGB(179,51);
        printf("\n");
            switch(columnaModificar)
            {
            case 1:
                getString("Ingrese el nombre nuevo: ",nombreNuevo);
                nombreNuevo[0]=toupper(nombreNuevo[0]);
                modificado[0]=1;


                break;

            case 2:

                horasNuevo=getIntPos("Ingrese la cantidad de horas trabajadas nuevas: ");

                 modificado[1]=1;

                break;
            case 3:

                sueldoNuevo=getIntPos("Ingrese el sueldo nuevo: ");


                modificado[2]=1;

                break;


            }
    }while(columnaModificar!=0);
    system("cls");
    setSucces("Desea realizar las siguientes modificaciones? (SI=1 o NO=2)",0);

                    for(i=0;i<3;i++)
                    {
                        if(modificado[i]==1)
                        {


                        switch(i)
                        {
                        case 0:
                            printf("\n");
                            linea(85);
                            printf("\nNombre ORIGINAL [ %s ]  ----> ",nombre);

                            printf("Nombre NUEVO [ %s ]\n",nombreNuevo);
                            linea(85);
                            printf("\n");

                            break;
                        case 1:
                            printf("\n");
                            linea(85);
                            printf("\n");

                             printf("Horas trabajadas ORIGINAL [ %d ] ----> ",horas);

                            printf("Horas trabajadas NUEVO [ %d ]",horasNuevo);
                            printf("\n");
                            linea(85);
                            printf("\n");
                            break;
                        case 2:
                             printf("\n");
                            linea(85);
                            printf("\n");
                            printf("Sueldo ORIGINAL [ %d ] ----> ",sueldo);
                            printf("Sueldo NUEVO [ %d ]",sueldoNuevo);
                            printf("\n");
                            linea(85);
                            printf("\n");
                            break;

                        }
                        }
                    }

    opc=getInt("",1,2);
    if(opc==1)
    {
        ret=0;
        for(i=0;i<3;i++)
        {
                if(modificado[i]==1)
                {


                    switch(i)
                    {
                        case 0:
                            strcpy(nombre,nombreNuevo);

                            break;
                        case 1:
                            horas=horasNuevo;


                            break;
                        case 2:
                            sueldo=sueldoNuevo;
                            break;

                    }
                }
        }


            employee_setNombre(employee,nombre);
            employee_setHorasTrabajadas(employee,horas);
            employee_setSueldo(employee,sueldo);
           ret= ll_set(pArrayListEmployee,ll_indexOf(pArrayListEmployee,employee),employee);


    }else
    {
        ret=-1;
    }



return ret;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int lastid=controller_lastId(pArrayListEmployee);
    int queryId;
    int i;
    int opc;
    int len=ll_len(pArrayListEmployee);
    int id=0;
    int horas=0;
    int sueldo=0;
    char nombre[128];

    Employee* employee;

    id=getInt("Ingrese el ID a eliminar",0,lastid);



    for(i=0;i<len;i++)
    {
        employee = employee_new();

        employee = ll_get(pArrayListEmployee,i);
        employee_getId(employee,&queryId);
        if(id==queryId)
        {
            break;
        }

    }


        employee_getId(employee,&id);
        employee_getNombre(employee,nombre);
        employee_getHorasTrabajadas(employee,&horas);
        employee_getSueldo(employee,&sueldo);
    system("cls");
        cabecera();


        columna();
        columna();
        printf("%6.d   ", id);
        columna();
        printf("%128s    ", nombre);
        columna();
        printf("%16.d  ", horas);
        columna();
        printf("%15.d  ", sueldo);
        columna();
        columna();
        printf("\n");


    linea(184);
    printf("\n\n");

    opc=getInt("Desea eliminar el registro? 1=SI o 2=NO",1,2);
    if(opc==1)
    {
       ret=ll_remove(pArrayListEmployee,i);
    }



return ret;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;
    int id;
    int horas;
    int sueldo;
    char nombre[128];
    int ret=-1;

    Employee* employee;
    system("cls");

    cabecera();
    for(i=0;i<len;i++)
    {
        employee = ll_get(pArrayListEmployee,i);
        employee_getId(employee,&id);
        employee_getNombre(employee,nombre);
        employee_getHorasTrabajadas(employee,&horas);
        employee_getSueldo(employee,&sueldo);
        columna();
        columna();
        printf("%6.d   ", id);
        columna();
        printf("%128s    ", nombre);
        columna();
        printf("%16.d  ", horas);
        columna();
        printf("%15.d  ", sueldo);
        columna();
        columna();
        printf("\n");

    }
    linea(184);
    printf("\n");
    if(i==len)
    {
        ret=0;
    }

return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;


    int opc;



            system("cls");
            linea(50);
            printf("\n1)Nombre\n");
            printf("2)ID\n");
            linea(50);

            opc=getInt("",1,2);


            system("cls");

            switch(opc)
            {
            case 1:
                linea(51);
                printf(" Nombre ");
                 linea(51);
                 printf("\n");

                 printf("\n1)A-Z");
                 printf("\n2)Z-A");

                 printf("\n\n");
                 linea(110);
                 printf("\n\n");
                 opc=getInt("",1,2);


                        switch(opc)
                        {
                            case 1:

                                ret=ll_sort(pArrayListEmployee,employee_CompareByName,1);

                                break;

                            case 2:

                                ret=ll_sort(pArrayListEmployee,employee_CompareByName,0);

                                break;
                        }

                break;

            case 2:

                 linea(51);
                 printf("   ID   ");
                 linea(51);
                 printf("\n");

                 printf("\n1)Ascendente");
                 printf("\n2)Descendente");

                 printf("\n\n");
                 linea(110);
                 printf("\n\n");
                 opc=getInt("",1,2);
                        switch(opc)
                        {
                        case 1:

                            ret=ll_sort(pArrayListEmployee,employee_CompareById,1);

                            break;

                        case 2:

                            ret=ll_sort(pArrayListEmployee,employee_CompareById,0);
                            break;
                        }

                break;
            }




return ret;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
int ret=-1;
int i;
int len =ll_len(pArrayListEmployee);
    char nombre[128];
    char cId[128];
    char cHoras[128];
    char cSueldo[128];
    int id;
    int horas;
    int sueldo;

    Employee* employee;
FILE* pFile;

pFile = fopen("data.csv","w");

 for(i=0; i<len; i++)
    {
        employee=employee_new();
        employee=ll_get(pArrayListEmployee,i);
        employee_getNombre(employee,nombre);
        employee_getId(employee,&id);
        employee_getHorasTrabajadas(employee,&horas);
        employee_getSueldo(employee,&sueldo);

        itoa(id,cId,10);

        itoa(sueldo,cSueldo,10);

        itoa(horas,cHoras,10);
        if(i==0)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        }
        fprintf(pFile,"%s,%s,%s,%s\n",cId,nombre,cHoras,cSueldo);

        //printf("\nEL ID ES %s",cId);
        ret=0;


    }

fclose(pFile);

return ret;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
      ////BINARY CREATE

        int ret=-1;

       FILE* fBinary;
       fBinary = fopen(path, "wb");
       Employee* employee;

        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            employee =employee_new();
            employee=(Employee*)ll_get(pArrayListEmployee,i);


        fwrite(employee, sizeof(Employee), 1, fBinary);
        ret=0;

        //printf("%d -%s - %d - %d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
        }


    fclose(fBinary);

return ret;
}

