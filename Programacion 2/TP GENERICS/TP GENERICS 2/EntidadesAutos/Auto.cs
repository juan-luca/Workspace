using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadesAuto
{
    public class Auto
    {
        private string _color;
        private string _marca;

        public string Color 
        { 
            get => _color; 
        }
        protected string Marca
        { 
            get => _marca;
        }

        public Auto(string color, string marca)
        {
            this._color = color;
            this._marca = marca;


        }

        public override bool Equals(object obj)
        {
            bool ret=false;

            if(obj is Auto)
            {
                ret = this == (Auto)obj;
            }


            return ret;

        }

        public static bool operator ==(Auto a1, Auto a2)
        {


            return a1._color == a2._color && a1._marca == a2._marca;
        }
        public static bool operator !=(Auto a1, Auto a2)
        {
            return !(a1 == a2);
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Marca: "+Marca);
            sb.AppendLine("Color: " + Color);
            return sb.ToString();
        }


    }
}
