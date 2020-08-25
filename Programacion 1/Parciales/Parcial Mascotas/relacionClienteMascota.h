
#include "clientes.h"
#include "mascotas.h"


int printOneMascota(Mascota [],Cliente [], int , TipoMascota [],Raza []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int printMascotas(Mascota [], Cliente [] , TipoMascota [], Raza []);
/**
*-Imprpime todas las mascotas
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/

int printClientesMascotas(Cliente [],Mascota [], TipoMascota [], Raza []);
/**
*-Imprpime la las mascotas con sus clientes
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int removeCliente(Cliente [], Mascota [] , int );
int printClientes2MascotasUp(Cliente [],Mascota []);
int printMascotas3anios(Mascota [], Cliente [],TipoMascota [], Raza Raza[]);
/**
*-Imprpime la las masco
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int printMascotasOrderedByTipo(Mascota [],Cliente [], TipoMascota [], Raza[]);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int printMascotasByTipo(Mascota [],Cliente [], TipoMascota [], Raza []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int printClientesCantMascotas(Cliente [],Mascota []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int printClientesCantMascotasAlfabeticoNombre(Cliente [],Mascota []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int promedioEdadMascota(Mascota []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int promedioEdadMascotaByTipo(Mascota [], TipoMascota []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int promedioClientesBySexo( Cliente []);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int modifyMascota(Mascota [],int ,int ,TipoMascota TipoMascota[], Raza Raza[], Cliente Cliente[]);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/
int printClientesIdemSexo(Cliente Cliente[], Mascota Mascota[]);
/**
*-Imprpime la mascota con el id seleccionado
*
*-Mascota[] Estructura de mascota
*-Cliente[] Estructura de cliente
*-TipoMascota[] Estructura de tipo
*-Raza [] Estructura de raza
*-return int - 0 si es correcta la query, -1 error
*/





//getRazaMascota(Raza,listaMascota[z].idTipo, razaMascota);
//diseño


void membreteMascotas();
void membreteMascotasCliente();
void membreteMascotasTipo();
void membrete11();
