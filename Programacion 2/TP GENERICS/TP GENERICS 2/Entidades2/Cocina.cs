using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Cocina
    {
        private int _codigo;
        private bool _esIndustrial;
        private double _precio;

        public int Codigo
        {
            get => _codigo;
        }
        protected bool EsIndustrial
        {
            get => _esIndustrial;
        }
        protected double Precio
        {
            get => _precio;
        }

        public Cocina(int codigo, double precio, bool esIndustrial)
        {
            this._codigo=codigo;
            this._esIndustrial=esIndustrial;
            this._precio = precio;


        }

        public override bool Equals(object obj)
        {
            bool ret = false;

            if (obj is Cocina)
            {
                ret = this == (Cocina)obj;
            }


            return ret;

        }

        public static bool operator ==(Cocina c1, Cocina c2)
        {


            return c1._codigo==c2._codigo;
        }
        public static bool operator !=(Cocina c1, Cocina c2)
        {
            return !(c1 == c2);
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Codigo: " + Codigo);
            sb.AppendLine("Es industrial: " + EsIndustrial);
            sb.AppendLine("Precio: $" + Precio);
            return sb.ToString();
        }


    }
}
