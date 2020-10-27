using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Concesionaria
    {
        private int capacidad;
        private List<Vehiculo> vehiculos;

        public double PrecioDeAutos
        {
            get
            {
                double precioTotalAutos = 0;
                foreach(Vehiculo v in this.vehiculos)
                {
                    if(v is Auto)
                    {
                        precioTotalAutos += (double)(Auto)v;
                    }
                }
                return precioTotalAutos;
            }

        }
        public double PrecioDeMotos
        {
            get
            {
                double precioTotalMotos = 0;
                foreach (Vehiculo v in this.vehiculos)
                {
                    if (v is Moto)
                    {
                        precioTotalMotos += (double)(Moto)v;
                    }
                }
                return precioTotalMotos;
            }

        }

        public double PrecioTotal
        {
            get
            {
                double precioTotal= 0;
                foreach (Vehiculo v in this.vehiculos)
                {
                    if (v is Moto)
                    {
                        precioTotal += (double)(Moto)v;
                    }else
                    {
                        if (v is Auto)
                        {
                            precioTotal += (double)(Auto)v;
                        }
                    }
                }
                return precioTotal;
            }

        }


        private Concesionaria()
        {
            vehiculos = new List<Vehiculo>();
        }
        private Concesionaria(int capacidad):this()
        {
            this.capacidad = capacidad;
        }

        public static implicit operator Concesionaria(int capacidad)
        {
            Concesionaria s = new Concesionaria(capacidad);
            return s;
        }



        private double ObtenerPrecio(EVehiculo tipoVehiculo)
        {
            double retorno = 0;

            foreach (Vehiculo x in this.vehiculos)
            {
                switch (tipoVehiculo)
                {
                    case (EVehiculo.PrecioDeAutos):
                        if (x is Auto)
                            retorno += (Double)((Auto)x);
                        break;

                    case (EVehiculo.PrecioDeMotos):
                        if (x is Moto)
                            retorno += ((Moto)x);
                        break;

                   
                    default:
                        if (x is Auto)
                            retorno += (Double)((Auto)x);
                        if (x is Moto)
                            retorno += ((Moto)x);
                        break;
                }

            }
            return retorno;
        }

        public static string Mostrar(Concesionaria c)
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Capacidad: "+ c.capacidad);
            sb.AppendLine("Autos: "+ c.PrecioDeAutos);
            sb.AppendLine("Motos: "+ c.PrecioDeMotos);
            sb.AppendLine("Total: "+ c.PrecioTotal);
            sb.AppendLine("******************************** ");
            sb.AppendLine("Vehiculos:    ");
            sb.AppendLine("******************************** ");

            foreach (Vehiculo v in c.vehiculos)
            {
                

                if (v is Auto)
                    sb.AppendLine(((Auto)v).ToString());

                if (v is Moto)
                    sb.AppendLine(((Moto)v).ToString());
            }

            return sb.ToString();
        }




        public static bool operator ==(Concesionaria c, Vehiculo v)
        {
            foreach (Vehiculo vaux in c.vehiculos)
            {

                if (vaux is Auto && v is Auto)
                {
                    if ((Auto)vaux == (Auto)v)
                    {
                        return true;
                        break; 
                    }
                }

                if (vaux is Moto && v is Moto)
                {
                    if ((Moto)vaux == (Moto)v)
                    {
                        return true;
                        break;
                    }
                }
            }
            return false;
        }
        public static bool operator !=(Concesionaria c, Vehiculo v)
        {
            return !(c == v);
        }

      
        public static Concesionaria operator +(Concesionaria c, Vehiculo v)
        {
                int acum = 0;
            foreach (Vehiculo x in c.vehiculos)
            {
                acum++;
            }

            if (acum < c.capacidad && c != v && !Object.Equals(c, v))
            {
                c.vehiculos.Add(v);
                Console.WriteLine(" El vehiculo ya esta en la concesionaria!");
            }
            else
            {
                Console.WriteLine("No hay mas lugar en la concesionaria!");
            }
            return c;
        }


        public override bool Equals(object obj)
        {
            bool rta = false;

            if (obj is Concesionaria)
            {
                rta = this == (Concesionaria)obj;
            }

            return rta;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }



    }
}
