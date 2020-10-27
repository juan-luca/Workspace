using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadesAuto
{
    public class DepositoDeAutos
    {
        private int _capacidadMaxima;
        private List<Auto> _lista = new List<Auto>();

        public DepositoDeAutos(int capacidad)
        {
            this._capacidadMaxima = capacidad;

        }
        public bool Agregar(Auto a)
        {
           return this + a;
        }
        public bool Remover(Auto a)
        {
            return this - a;
        }

        public static bool operator +(DepositoDeAutos d, Auto a)
        {
            bool ret = false;
            if(d._lista.Count < d._capacidadMaxima && d.GetIndice(a)==-1)
            {
                d._lista.Add(a);
                ret = true;
            }

            return ret;
        }
        public static bool operator -(DepositoDeAutos d,Auto a)
        {
            bool ret = false;
            if(d._lista.Contains(a))
            {
                d._lista.RemoveAt(d.GetIndice(a));
                ret = true;
            }
            /*
            int cont = 0;
            foreach(Auto item in d._lista)
            {
                if(cont == d.GetIndice(a))
                {
                    if(item == a)
                    {
                        d._lista.Remove(a);
                        ret = true;
                    }
                }
                cont++;

            }*/
            return ret;
        }
        private  int GetIndice(Auto a)
        {
            int ret = -1;
            int cont = 0;
            foreach(Auto item in _lista)
            {
                
                if(item==a)
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
            
            foreach(Auto item in _lista)
            {
                sb.AppendLine(item.ToString());
            }
            
            return sb.ToString();
        }
    }
}
