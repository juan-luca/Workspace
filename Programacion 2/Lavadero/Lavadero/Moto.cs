using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lavadero
{
    public class Moto:Vehiculo
    {

        protected float cilindrada;

        public Moto(string patente, Byte cantruedas, EMarcas marca, float cilindrada) : base(patente, cantruedas, marca)
        {
            this.cilindrada = cilindrada;

        }

        public string MostrarMoto()
        {
            
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.Mostrar());
            sb.AppendLine("Cilindrada: "+this.cilindrada);

            return sb.ToString();
        }
    }
}
