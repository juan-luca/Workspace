#include <stdio.h>
#include <stdlib.h>
#include "proveedores.h"
int main()
{

    eProducto productos[10];
    eProveedor proveedores[4];
    ProvProd listpp[4];

    hardCodearProv(proveedores,4);
    hardCodearProd(productos,10);
    iniProvProd(productos, 10, proveedores,4,listpp);
    mostrarProvConSusProductos(productos, 10, proveedores, 4);
    mostrarProvConMasProd(productos, 10, proveedores, 4, listpp);
    return 0;
}
