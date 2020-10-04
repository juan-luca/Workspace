using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lavadero
{
    public class Lavadero
    {
        private List<Vehiculo> vehiculos;
            private float precioAuto;
        private float precioCamion;
        private float precioMoto;
        private string Lav;

        protected string lavadero 
        {
            get
            {
                StringBuilder sb = new StringBuilder();
                sb.AppendLine("PRECIOS: ");
                sb.AppendLine("Auto: " +precioAuto  );
                sb.AppendLine("Camion: "+precioCamion);
                sb.AppendLine("Moto: "+precioMoto);
                Lav = sb.ToString();
                return Lav;
            }
        }
        public List<Vehiculo> Vehiculos 
        { 
            get => vehiculos; 
        }

        private Lavadero()
        {
            this.vehiculos = new List<Vehiculo>();

        }

        public Lavadero(List<Vehiculo> Vehiculos, float precioAuto, float precioCamion, float precioMoto):this()
        {
            this.precioAuto = precioAuto;
            this.precioCamion = precioCamion;
            this.precioMoto = precioMoto;
        }

        #region METODOS
        public double MostrarTotalFacturado()
        {
            double total=0;
            int cantCamiones = 0;
            int cantAutos = 0;
            int cantMotos = 0;

            foreach (Vehiculo item in this.vehiculos)
            {
                if(item is Auto)
                {
                    cantAutos++;
                }else if( item is Moto)
                       {
                             cantMotos++;
                       }else if(item is Camion)
                            {
                                    cantCamiones++;
                             }
                

            }
            total = cantCamiones * precioCamion + cantAutos * precioAuto + cantMotos * precioMoto;

            return total;
        }
        public double MostrarTotalFacturado(EVehiculos vehiculo)
        {
            double total = 0;
            int cantCamiones = 0;
            int cantAutos = 0;
            int cantMotos = 0;

            foreach (Vehiculo item in this.vehiculos)
            {
                
               switch(vehiculo.ToString())
                {
                    case "Auto":
                        if(item is Auto)
                        {
                            cantAutos++;
                        }
                        break;
                    case "Moto":
                        if (item is Moto)
                        {
                            cantMotos++;
                        }
                        break;
                    case "Camion":
                        if (item is Camion)
                        {
                            cantCamiones++;
                        }
                        break;

                }

            }
            total = cantCamiones * precioCamion + cantAutos * precioAuto + cantMotos * precioMoto;

            

            return total;
        }

        #endregion

        #region SOBRECARGAS

            public static bool  operator ==(Vehiculo v, Lavadero l)
            {
                   
                    return l.vehiculos.Contains(v);
            }

        public static bool operator !=(Vehiculo v, Lavadero l)
        {

            return !(v==l);
        }

        #endregion

    }
}
