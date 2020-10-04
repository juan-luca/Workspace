using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Lavadero
{
    class Auto:Vehiculo
    {
        protected int cantidadAsientos;
        public Auto(string patente, Byte cantruedas, EMarcas marca, int cantidadAsientos):base(patente, cantruedas, marca)
        {
            this.cantidadAsientos = cantidadAsientos;
        }

        public string MostrarAuto()
        {

            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.Mostrar());
            sb.AppendLine("Cantidad de asientos: " + this.cantidadAsientos);

            return sb.ToString();
        }

    }
}
