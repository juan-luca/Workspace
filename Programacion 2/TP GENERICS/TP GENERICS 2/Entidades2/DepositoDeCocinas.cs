using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class DepositoDeCocinas
    {
        private int _capacidadMaxima;
        private List<Cocina> _lista = new List<Cocina>();

        public DepositoDeCocinas(int capacidad)
        {
            this._capacidadMaxima = capacidad;

        }
        public bool Agregar(Cocina c)
        {
            return this + c;
        }
        public bool Remover(Cocina c)
        {
            return this - c;
        }

        public static bool operator +(DepositoDeCocinas d, Cocina c)
        {
            bool ret = false;
            if (d._lista.Count < d._capacidadMaxima)
            {
                d._lista.Add(c);
                ret = true;
            }

            return ret;
        }
        public static bool operator -(DepositoDeCocinas d, Cocina c)
        {
            bool ret = false;
            if (d._lista.Contains(c))
            {
                d._lista.RemoveAt(d.GetIndice(c));
                ret = true;
            }
           
            return ret;
        }
        private int GetIndice(Cocina c)
        {
            int ret = -1;
            int cont = 0;
            foreach (Cocina item in _lista)
            {

                if (item == c)
                {
                    ret = cont;
                }
                cont++;
            }
            return ret;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Capacidad maxima: " + _capacidadMaxima);

            foreach (Cocina item in _lista)
            {
                sb.AppendLine(item.ToString());
            }

            return sb.ToString();
        }
    }
}
