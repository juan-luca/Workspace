using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Moto:Vehiculo
    {
        public ECilindrada cilindrada;

        public Moto(string marca, EPais pais, string modelo, float precio, ECilindrada cilindrada) : base(marca,pais, modelo,precio)
        {
            this.cilindrada = cilindrada;
        }
        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Moto)
            {
                rta = this == (Moto)obj;
            }

            return rta;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public static implicit operator  Single(Moto m)
        {


            return m.precio;
        }

        public static bool operator ==(Moto m1, Moto m2)
        {
            return m1.cilindrada == m2.cilindrada && (Vehiculo)m1 == (Vehiculo)m2;
        }
        public static bool operator !=(Moto m1, Moto m2)
        {
            return !(m1 == m2);
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine((string)(Vehiculo)this);
            sb.AppendLine("Cilindrada: " + this.cilindrada);
            return sb.ToString();
        }
    }
}
