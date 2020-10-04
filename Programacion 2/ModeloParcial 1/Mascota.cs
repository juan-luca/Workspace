using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial_1
{
    public abstract class Mascota
    {
        private string nombre;
        private string raza;

        #region properties
        protected string Nombre 
        { 
            get => nombre;
        }
        protected string Raza 
        { 
            get => raza; 
        }
        #endregion
        #region constructores
        public Mascota(string nombre, string raza)
        {
            this.nombre = nombre;
            this.raza = raza;

        }
        #endregion
        #region METODOS
        protected virtual string DatosCompletos()
        {
            return this.Nombre + " - " + this.Raza;
        }

        protected abstract string Ficha();

        
        #endregion

        #region SOBRECARGAS
        public static bool operator ==(Mascota m1, Mascota m2)
        {
            
                return m1.nombre == m2.nombre && m1.raza == m2.raza;
        }
        public static bool operator !=(Mascota m1, Mascota m2)
        {
            return !(m1 == m2);
        }

        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Mascota)
            {
                rta = this == (Mascota)obj;
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
