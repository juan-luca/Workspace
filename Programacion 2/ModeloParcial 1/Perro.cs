using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial_1
{
    public class Perro:Mascota
    {
        private int edad;
        private bool esAlfa;
        #region properties
       
        #endregion
        #region constructores
        public Perro(string nombre, string raza):base(nombre,raza)
        {
            this.edad = 0;
            this.esAlfa = false;

        }
        public Perro(string nombre, string raza, int edad, bool esAlfa) : this(nombre,raza)
        {
            
            this.edad = edad;
            this.esAlfa = esAlfa;

        }
        #endregion
        #region METODOS
        

        protected override string Ficha()
        {
            StringBuilder sb = new StringBuilder();
            if(esAlfa)
            {
                sb.AppendLine("Perro - "+base.DatosCompletos()+" - Alfa de la manada - Edad " +(int)this);
            }else
            {
                sb.AppendLine("Perro - " + base.DatosCompletos() + " - Edad " + (int)this);
            }
            

            return sb.ToString();
        }


        #endregion

        #region SOBRECARGAS

        public static explicit operator int(Perro p)
        {
            return p.edad;
        }
        public static bool operator ==(Perro p1, Perro p2)
        {
            bool ret = false;
            
            if((Mascota)p1 == (Mascota)p2 && p1.edad == p2.edad)
            {
                ret = true;
            }
            return ret;
        }
        public static bool operator !=(Perro p1, Perro p2)
        {
            return !(p1 == p2);
        }

        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Perro)
            {
                rta = this == (Perro)obj;
            }

            return rta;
        }

        public override string ToString()
        {
            return this.Ficha();
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
        #endregion

    }
}
