#include "Mascotas_Clientes.h"
void mostrarMascotasConSusDuenios(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota)
{
    int i;
    int j;
    printf("\n\n");
    for(i=0; i<tamMascota; i++)
    {

        for(j=0; j<tamCliente; j++)
        {
            if(mascota[i].idDuenio == cliente[j].idCliente)
            {
                printf("%s %s %s %d %.2f %c %s\n",mascota[i].nombre,
                       mascota[i].tipo,
                       mascota[i].raza,
                       mascota[i].edad,
                       mascota[i].peso,
                       mascota[i].sexo,
                       cliente[j].nombre);
            }
        }

    }
}

void mostrarClientesConSusMascotas(eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota)
{
    int i;
    int j;
    printf("\n\n");
    for(i=0;i<tamCliente;i++)
    {
        for(j=0;j<tamMascota;j++)
        {
            if(cliente[i].idCliente==mascota[j].idDuenio)
            {
                printf("%s %s %s %s\n",cliente[i].nombre,cliente[i].apellido,mascota[j].nombre,mascota[j].tipo);
            }
        }
    }
}
