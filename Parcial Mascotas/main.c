#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#include "MenuABM.h"


int main()
{
    Cliente Cliente[C];
    Mascota Mascota[M];
    TipoMascota TipoMascota[TM];
    Raza Raza[R];

    MenuABM(Mascota, Cliente, TipoMascota, Raza);
   /* Orquesta Orquesta[tOrquesta];
    TipoOrquesta TipoOrquesta[3];
    Instrumento Instrumento[tInstrumento];
    Musico Musico[tMusico];

    hardCodearTipoOrquesta(TipoOrquesta,tTipoOrquesta);
    MenuABM(Orquesta, Instrumento,Musico, tOrquesta);*/
    return 0;
}
