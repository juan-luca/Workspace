#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#include "MenuABM.h"

#define tOrquesta 50
#define tTipoOrquesta 3
#define tMusico 1000
#define tInstrumento 20
int main()
{
    Orquesta Orquesta[tOrquesta];
    TipoOrquesta TipoOrquesta[3];
    Instrumento Instrumento[tInstrumento];
    Musico Musico[tMusico];

    hardCodearTipoOrquesta(TipoOrquesta,tTipoOrquesta);
    MenuABM(Orquesta, Instrumento,Musico, tOrquesta);
    return 0;
}
