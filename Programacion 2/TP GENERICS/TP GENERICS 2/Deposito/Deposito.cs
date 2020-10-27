using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Deposito
{
    public class Deposito <T>
    {
        private int _capacidadMaxima;
        private List<T> _lista = new List<T>();

        public Deposito(int capacidad)
        {
            this._capacidadMaxima = capacidad;

        }
        public bool Agregar(T c)
        {
            return this + c;
        }
        public bool Remover(T c)
        {
            return this - c;
        }

        public static bool operator +(Deposito<T>  d, T c)
        {
            bool ret = false;
            if (d._lista.Count < d._capacidadMaxima)
            {
                d._lista.Add(c);
                ret = true;
            }

            return ret;
        }
        public static bool operator -(Deposito<T> d, T c)
        {
            bool ret = false;
            if (d._lista.Contains(c))
            {
                d._lista.RemoveAt(d.GetIndice(c));
                ret = true;
            }

            return ret;
        }
        private int GetIndice(T c)
        {
            int ret = -1;
            int cont = 0;
            foreach (T item in _lista)
            {

                if (item.Equals(c))
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

            foreach (T item in _lista)
            {
                sb.AppendLine(item.ToString());
            }

            return sb.ToString();
        }
    }
}
