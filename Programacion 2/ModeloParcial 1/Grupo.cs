using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial_1
{
    public class Grupo
    {
        private List<Mascota> manada;
        private string nombre;
        private static ETipoManada tipo;

        public static ETipoManada Tipo 
        { 
            set 
            {
                Grupo.tipo = value;
            }
        }

        static Grupo()
        {
            Grupo.Tipo = ETipoManada.Unica;
        }
        private Grupo()
        {
            this.manada = new List<Mascota>();
        }
        public Grupo(string nombre):this()
        {
            this.nombre = nombre;
        }
        public Grupo(string nombre,ETipoManada tipo ) : this(nombre)
        {
            Tipo = tipo;
        }

        #region SOBRECARGAS
        public static implicit operator string(Grupo g)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Grupo: " + g.nombre + " - Tipo: " + Grupo.tipo.ToString());
            sb.AppendLine("Integrantes ("+ g.manada.Count() + "):" );
            
            foreach(Mascota m in g.manada)
            {
                sb.AppendLine(m.ToString());
            }
            
            return sb.ToString();
        }
        
        public static bool operator ==(Grupo g, Mascota m)
        {
            bool ret = false;
            foreach(Mascota item in g.manada)
            {
                if(item.Equals(m))
                {
                    ret = true;
                    continue;
                }
            }

            return ret;
        }
        public static bool operator !=(Grupo g, Mascota m)
        {
            return !(g == m);
        }
        public static Grupo operator +(Grupo g, Mascota m)
        {
            if(g!=m)
            {
                g.manada.Add(m);
            }else
            {
                Console.WriteLine(m.ToString()+" ya pertenece al grupo.");
            }
            return g;
        }
        public static Grupo operator -(Grupo g, Mascota m)
        {
            if (g == m)
            {
                g.manada.Remove(m);
            }
            else
            {
                Console.WriteLine(m.ToString()+" no pertenece al grupo.");
            }
            return g;
        }

        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Grupo)
            {
                rta = this == (Grupo)obj;
            }

            return rta;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        #endregion
    }
}
