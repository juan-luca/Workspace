using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial_1
{
    public class Gato:Mascota
    {


        #region constructores
        public Gato(string nombre, string raza):base(nombre,raza)
        {
        }
        #endregion
        #region METODOS
        

            protected override string Ficha()
        {
            StringBuilder sb = new StringBuilder();
            
            
                sb.AppendLine("Gato - " + base.DatosCompletos());
            


            return sb.ToString();
        }


        #endregion

        #region SOBRECARGAS
        public static bool operator ==(Gato g1, Gato g2)
        {
            
            return (Mascota)g1== (Mascota)g2;
        }
        public static bool operator !=(Gato g1, Gato g2)
        {
            return !(g1 == g2);
        }

        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Gato)
            {
                rta = this == (Gato)obj;
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
