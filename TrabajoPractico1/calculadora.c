
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>

int main()
{
    int opcion, flagA=0, flagB=0, flag3=0,  inumB=0, inumA=0, divisionCero=0;
float fnumA=0, fnumB=0, suma, prod, divi, resta;
int isuma, iprod, iresta, factA, factB;
int entero, flotante;




    while(opcion!=6)
    {
        if(flagA==0)
        {


            printf("1)Ingresar 1er operando (A=x)");

        }else
        {
            if(flotante==1) //
            {
                printf("1)Ingresar 1er operando (A=%f)",fnumA);
            }
            else
            {
                printf("1)Ingresar 1er operando (A=%d)",inumA);
            }


        }

        if(flagB==0)
        {
            printf("\n2)Ingresar 2do operando (B=y)");

        }else
        {
            if(flotante==1) //
            {
                printf("\n2)Ingresar 2do operando (B=%f)",fnumB);
            }
            else
            {
                printf("\n2)Ingresar 2do operando (B=%d)",inumB);
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
                     if(flotante==1) //
                    {
                            printf("    a) Calcular la suma (%f+%f)\n",fnumA,fnumB);
                            printf("    b) Calcular la resta (%f-%f) \n",fnumA,fnumB);
                            printf("    c) Calcular la division (%f/%f)\n",fnumA,fnumB);
                            printf("    d) Calcular la multiplicacion (%f*%f)\n",fnumA,fnumB);
                            printf("    e) Calcular el factorial (%f!) (%f!)\n", fnumA,fnumB);
                    }
                    else
                    {
                            printf("    a) Calcular la suma (%d+%d)\n",inumA,inumB);
                            printf("    b) Calcular la resta (%d-%d) \n",inumA,inumB);
                            printf("    c) Calcular la division (%d/%d)\n",inumA,inumB);
                            printf("    d) Calcular la multiplicacion (%d*%d)\n",inumA,inumB);
                            printf("    e) Calcular el factorial (%d!) (%d!)\n", inumA,inumB );
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
                        printf("1)Ingresar 1er operando (A=%f)\n",fnumA);
                    }else
                    {
                        printf("1)Ingresar 1er operando (A=%d)\n",inumA);
                    }


                }
            /*----------------------------------------------FIN TITULO------------------------------*/
            //MODULO FLOAT / INT. En proceso de cambiarlo a una funcion
                fnumA=getFloat("Ingrese\n",0,0);
                inumA = fnumA;
                //
                //VERIFICA EL TIPO DE DATO INGRESADO
                //
                if(fnumA==inumA)//entonces es entero
                {
                        flotante=0;
                        entero=1;

                }
                else//entonces flotante
                {
                        entero=0;
                        flotante=1;
                }
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
                        printf("2)Ingresar 2do operando (B=%f)\n",fnumB);
                    }else
                    {
                        printf("2)Ingresar 2do operando (B=%d)\n",inumB);
                    }


                }
            /*----------------------------------------------FIN TITULO------------------------------*/
            //MODULO FLOAT / INT. En proceso de cambiarlo a una funcion
                fnumB=getFloat("Ingrese\n",0,0);
                inumB = (int)fnumB;
                //
                //VERIFICA EL TIPO DE DATO INGRESADO
                //
                if(fnumB==inumB)//entonces es entero
                {
                        flotante=0;
                        entero=1;
                }
                else//entonces flotante
                {
                        entero=0;
                        flotante=1;
                }
                flagB=1;
                break;

            case 3:
                if(fnumA!=inumA || fnumB!=inumB)
                {
                    entero=0;
                    flotante=1;
                }else
                {
                    entero=1;
                    flotante=0;
                }
                if(flagA==1 && flagB==1)
                {
                    if(flotante==1)
                    {
                        suma=sumar(fnumA,fnumB,flotante);
                        resta=restar(fnumA,fnumB,flotante);
                        if(fnumB!=0)
                        {
                            divi=division(fnumA,fnumB);
                        }
                        else
                        {
                            divisionCero=1;
                        }
                        prod=producto(fnumA,fnumB,flotante);
                        factA=0;
                        factB=0;
                        system("cls");
                        printf("\nCalculado!\n");

                    }else
                    {
                        isuma=sumar(inumA,inumB,flotante);
                        iresta=restar(inumA,inumB,flotante);
                        if(inumB!=0)
                        {
                            divi=division(inumA,inumB);
                        divisionCero=0;
                        }
                        else
                        {
                            divisionCero=1;
                        }

                        iprod=producto(inumA,inumB,flotante);
                        factA=factorialRecursivo(inumA);
                        factB=factorialRecursivo(inumB);
                        system("cls");
                        system("color 20");
                        printf("\nCalculado!\n");
                    }
                }
                else
                {
                    system("cls");
                    system("color 4F");
                    printf("\n Error, primero debe ingresar los 2 operandos.\n");
                }

                break;
            case 4:
                if(flotante==1)
                {
                    system("cls");
                    printf("\n4)Informar resultados\n");
                    mostrar(suma,resta,prod,divi,factA,factB,flotante,divisionCero,fnumA,fnumB);
                }else
                {
                    system("cls");
                    printf("\n4)Informar resultados\n");
                    mostrar(isuma,iresta,iprod,divi,factA,factB,flotante,divisionCero,inumA,inumB);
                }

                break;
            case 5:
                    flag3=0;
                    flagA=0;
                    flagB=0;
                    inumB=0;
                    inumA=0;
                    fnumA=0;
                    fnumB=0;
                    entero=0;
                    flotante=0;
                    divisionCero=0;
                    factA=0;
                    factB=0;
                    printf("\nSe reinicio la calculadora.\n");


                break;
            case 6:
                printf("Hasta luego!");
                break;
            default:
               printf("DEFAULT");
                break;
        }

        system("pause");
        system("color 0F");
        system("cls");
    }


    return 0;
}


