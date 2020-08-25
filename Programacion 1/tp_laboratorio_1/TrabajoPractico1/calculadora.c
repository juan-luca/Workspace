
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <windows.h>

int main()
{
    int opcion, flagA=0, flagB=0, divisionCero=0, inum[2], isuma, iprod, iresta, factA, factB, entero, flotante, flag3=0;
float suma, prod, divi, resta, fnum[2], ffnum[2];

    while(opcion!=6)
    {
        if(flagA==0)
        {


            printf("1)Ingresar 1er operando (A=x)");

        }else
        {
            if(flotante==1) //
            {
                printf("1)Ingresar 1er operando (A=%f)",fnum[0]);
            }
            else
            {
                printf("1)Ingresar 1er operando (A=%d)",inum[0]);
            }


        }

        if(flagB==0)
        {
            printf("\n2)Ingresar 2do operando (B=y)");

        }else
        {
            if(flotante==1) //
            {
                printf("\n2)Ingresar 2do operando (B=%f)",fnum[1]);
            }
            else
            {
                printf("\n2)Ingresar 2do operando (B=%d)",inum[1]);
            }
        }

        printf("\n3)Calcular todas las operaciones :\n");

            if(flagA==0 && flagB==0)
                {
                    printf("    a) Calcular la suma (A+B)\n");
                    printf("    b) Calcular la resta (A-B) \n");
                    printf("    c) Calcular la division (A/B)\n");
                    printf("    d) Calcular la multiplicacion (A*B)\n");
                    printf("    e) Calcular el factorial (A!) (B!)\\n");

                }
                else
                {
                    if(flagA==0 && flagB==1)
                    {

                             if(flotante==1) //
                                {
                                printf("    a) Calcular la suma (%f+%f)\n",fnum[1]);
                                printf("    b) Calcular la resta (%f-%f) \n",fnum[1]);
                                printf("    c) Calcular la division (%f/%f)\n",fnum[1]);
                                printf("    d) Calcular la multiplicacion (%f*%f)\n",fnum[1]);
                                printf("    e) Calcular el factorial (%f!) (%f!)\n", fnum[1]);
                                }
                                else
                                {
                                printf("    a) Calcular la suma (x+%d)\n",inum[1]);
                                printf("    b) Calcular la resta (x-%d) \n",inum[1]);
                                printf("    c) Calcular la division (x/%d)\n",inum[1]);
                                printf("    d) Calcular la multiplicacion (x*%d)\n",inum[1]);
                                printf("    e) Calcular el factorial (x!) (%d!)\n", inum[1] );
                                }
                    }else
                    {
                        if(flagA==1 && flagB==0)
                        {
                            if(flotante==1) //
                                {
                                printf("    a) Calcular la suma (%f+y)\n",fnum[0]);
                                printf("    b) Calcular la resta (%f-y) \n",fnum[0]);
                                printf("    c) Calcular la division (%f/y)\n",fnum[0]);
                                printf("    d) Calcular la multiplicacion (%f*y)\n",fnum[0]);
                                printf("    e) Calcular el factorial (%f!) (%y!)\n", fnum[0]);
                                }
                                else
                                {
                                printf("    a) Calcular la suma (%d+y)\n",inum[0]);
                                printf("    b) Calcular la resta (%d-y) \n",inum[0]);
                                printf("    c) Calcular la division (%d/y)\n",inum[0]);
                                printf("    d) Calcular la multiplicacion (%d*y) \n",inum[0]);
                                printf("    e) Calcular el factorial (%d!) (%y!) \n", inum[0]);
                                }

                        }else
                        {
                            if(flagA==1 && flagB==1)
                            {
                                 if(flotante==1) //
                                {
                                printf("    a) Calcular la suma (%f+%f)\n",fnum[0],fnum[1]);
                                printf("    b) Calcular la resta (%f-%f) \n",fnum[0],fnum[1]);
                                printf("    c) Calcular la division (%f/%f)\n",fnum[0],fnum[1]);
                                printf("    d) Calcular la multiplicacion (%f*%f)\n",fnum[0],fnum[1]);
                                printf("    e) Calcular el factorial (%f!) (%f!)\n", fnum[0],fnum[1]);
                                }
                                else
                                {
                                printf("    a) Calcular la suma (%d+%d)\n",inum[0],inum[1]);
                                printf("    b) Calcular la resta (%d-%d) \n",inum[0],inum[1]);
                                printf("    c) Calcular la division (%d/%d)\n",inum[0],inum[1]);
                                printf("    d) Calcular la multiplicacion (%d*%d) \n",inum[0],inum[1]);
                                printf("    e) Calcular el factorial (%d!) (%d!) \n", inum[0],inum[1] );
                                }

                            }
                        }

                    }




                }

        printf("\n4)Informar resultados");
        printf("\n5) CE.");
        printf("\n6) Salir.\n");




        opcion = getInt("Ingrese la opcion deseada: ",1,6);

        switch(opcion)
        {
            case 1:
                system("cls");


            /*--------------------------------------------------TITULO------------------------------*/
                if(flagA==0)//Primera vez que ingresa
                {
                    printf("1)Ingresar 1er operando (A=x)\n");
                    flotante=0;
                    entero=0;

                }else
                {
                    if(flotante==1) //
                    {
                        printf("1)Ingresar 1er operando (A=%f)\n",fnum[0]);
                    }else
                    {
                        printf("1)Ingresar 1er operando (A=%d)\n",inum[0]);
                    }
                }

            /*----------------------------------------------FIN TITULO------------------------------*/
            //MODULO FLOAT / INT. En proceso de cambiarlo a una funcion
                fnum[0]=getFloat("Ingrese\n",0,0);
                inum[0] = (int)fnum[0];

                //
                //VERIFICA EL TIPO DE DATO INGRESADO
                //
                if(fnum[0]==inum[0])//entonces es entero
                {
                        flotante=0;
                        entero=1;

                }
                else//entonces flotante
                {
                        entero=0;
                        flotante=1;
                }
                system("cls");
                flagA=1;

                break;
            case 2:
                system("cls");
            /*--------------------------------------------------TITULO------------------------------*/
                if(flagB==0)//Primera vez que ingresa
                {
                    printf("2)Ingresar 2do operando (B=x)\n");
                    flotante=0;
                    entero=0;

                }else
                {
                    if(flotante==1) //
                    {
                        printf("2)Ingresar 2do operando (B=%f)\n",fnum[1]);
                    }else
                    {
                        printf("2)Ingresar 2do operando (B=%d)\n",inum[1]);
                    }


                }
            /*----------------------------------------------FIN TITULO------------------------------*/
            //MODULO FLOAT / INT. En proceso de cambiarlo a una funcion
                fnum[1]=getFloat("Ingrese\n",0,0);
                inum[1] = (int)fnum[1];
                //
                //VERIFICA EL TIPO DE DATO INGRESADO
                //
                if(fnum[1]==inum[1])//entonces es entero
                {
                        flotante=0;
                        entero=1;
                }
                else//entonces flotante
                {
                        entero=0;
                        flotante=1;
                }
                system("cls");
                flagB=1;
                break;

            case 3:
                if(fnum[0]!=inum[0] || fnum[1]!=inum[1])
                {
                    entero=0;
                    flotante=1;
                }else
                {
                    entero=1;
                    flotante=0;

                       /* for(int i=0; i< 2 ; i++ )
                        {
                            fnum[i]=inum[i];

                        }
                        system("pause");*/
                }

                if(flagA==1 && flagB==1)
                {
                    int ftam= sizeof(fnum)/sizeof(float);
                    int itam = sizeof(inum)/sizeof(int);
                    if(flotante==1)
                    {
                        suma=sumar(fnum,ftam);
                        resta=restar(fnum,ftam);
                        if(fnum[1]!=0)
                        {
                            divi=division(fnum);
                        }
                        else
                        {
                            divisionCero=1;
                        }
                        prod=producto(fnum, flotante, ftam);
                        factA=0;
                        factB=0;
                        flag3=1;
                        setSucces("Calculado!",1);

                    }else
                    {

                        isuma=sumar(fnum,itam);
                        iresta=restar(fnum,itam);
                        if(inum[1]!=0)
                        {
                            divi=division(inum);
                        divisionCero=0;
                        }
                        else
                        {
                            divisionCero=1;
                        }

                        iprod=producto(fnum, flotante, itam);
                        factA=factorialRecursivo(inum[0]);
                        factB=factorialRecursivo(inum[1]);
                        setSucces("Calculado",1);
                        flag3=1;
                    }
                }
                else
                {

                    setError("Error, primero debe ingresar los 2 operandos.",1);
                }

                break;
            case 4:
                if(flag3==1)
                {
                    system("cls");

                    if(flotante==1)
                    {

                        printf("\n4)Informar resultados\n");
                        mostrar(suma,resta,prod,divi,factA,factB,flotante,divisionCero,fnum[0],fnum[1]);
                    }else
                    {

                        printf("\n4)Informar resultados\n");
                        mostrar(isuma,iresta,iprod,divi,factA,factB,flotante,divisionCero,inum[0],inum[1]);
                    }
                }else
                {
                    setError("Error, primero debe calcular todo.",1);
                }

            system("cls");
                break;
            case 5:

                    flagA=0;
                    flagB=0;
                    inum[1]=0;
                    inum[0]=0;
                    fnum[0]=0;
                    fnum[1]=0;
                    entero=0;
                    flotante=0;
                    divisionCero=0;
                    flag3=0;
                    factA=0;
                    factB=0;
                    fflush(stdin);
                    setSucces("Se reinicio la calculadora.",1);


                break;
            case 6:
                setSucces("Hasta luego!",1);
                break;


        }


    }


    return 0;
}


