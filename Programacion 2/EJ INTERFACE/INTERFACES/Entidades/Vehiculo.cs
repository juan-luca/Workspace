using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    abstract class Vehiculo
    {
        public double _precio;


        public void MostrarPrecio()
        {
            Console.WriteLine("Precio: " + this._precio);
        }


        public Vehiculo(double precio)
        {
            this._precio = precio;
        }
    }
}
