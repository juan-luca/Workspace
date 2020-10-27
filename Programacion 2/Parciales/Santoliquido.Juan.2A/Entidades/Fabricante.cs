using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Fabricante
    {
        private string marca;
        private EPais pais;
        public Fabricante(string marca, EPais pais)
        {
            this.marca = marca;
            this.pais = pais;
        }
        public static implicit operator string(Fabricante f)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Marca: " + f.marca);
            sb.AppendLine("Pais: " + f.pais);

            return sb.ToString();
        }

        public static bool operator ==(Fabricante f1, Fabricante f2)
        {
           

            return f1.pais == f2.pais && f1.marca == f2.marca;
        }
        public static bool operator !=(Fabricante f1, Fabricante f2)
        {
            return !(f1 == f2);
        }
    }
}
