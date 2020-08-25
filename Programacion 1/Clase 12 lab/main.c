#include <stdio.h>
#include <stdlib.h>
#include "productos.h"

int main()
{

    eProducto productos[10];
    eProveedor proveedores[4];

    hardCodearProv(proveedores,4);
    hardCodearProd(productos,10);
    mostrarProvConSusProductos(productos, 10, proveedores, 4);
    mostrarProvConMasProd(productos, 10, proveedores, 4);
    return 0;
}
