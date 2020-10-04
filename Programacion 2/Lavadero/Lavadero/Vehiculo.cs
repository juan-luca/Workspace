using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lavadero
{
    public class Vehiculo
    {

        protected string patente;
        protected Byte cantRuedas;
        protected EMarcas marca;
        protected string Patente 
        { 
            get => patente; 
        }
        protected EMarcas Marca 
        { 
            get => marca;
        }

        protected string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Patente: {0}\r\n" + this.patente);
            sb.AppendLine("Marca: {0}\r\n" + this.marca.ToString());
            sb.AppendLine("Cantidad de ruedas: {0}\r\n" + this.cantRuedas.ToString());
            sb.AppendLine("---------------------");

            return sb.ToString();
        }

        public Vehiculo(string patente, Byte cantruedas, EMarcas marca)
        {
            this.patente = patente;
            this.cantRuedas = cantruedas;
            this.marca = marca;
        }

        public static bool operator ==(Vehiculo v1, Vehiculo v2)
        {
            bool retorno = false;
            if(v1.patente==v2.patente && v1.marca == v2.marca)
            {
                retorno = true;
            }
            return retorno;
        }
        public static bool operator !=(Vehiculo v1, Vehiculo v2)
        {
            
            
            return !(v1==v2);
        }

    }
}
