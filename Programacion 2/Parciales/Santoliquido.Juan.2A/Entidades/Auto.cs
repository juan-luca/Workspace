using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Auto: Vehiculo
    {
        public ETipo tipo;

        public Auto(string modelo, float precio, Fabricante fabri, ETipo tipo):base(precio,modelo,fabri)
        {
            this.tipo = tipo;
        }
        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Auto)
            {
                rta = this == (Auto)obj;
            }

            return rta;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public static explicit operator Single(Auto a)
        {
            

            return a.precio;
        }

        public static bool operator ==(Auto a1, Auto a2)
        {
            return a1.tipo == a2.tipo && (Vehiculo)a1 == (Vehiculo)a2;
        }
        public static bool operator !=(Auto a1, Auto a2)
        {
            return !(a1 == a2);
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            
            sb.AppendLine((string)(Vehiculo)this);
            sb.AppendLine("Tipo: "+this.tipo);
            return sb.ToString();
        }
    }
}
