using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Integrador
{
    public class ParaisoFiscal
    {
        #region ATRIBUTOS
        private List<CuentaOffShore> _listadoCuentas;
        private EParaisosFiscales _lugar;
        static int cantidadDeCuentas;
        static DateTime fechaDeInicioActividades;
        #endregion


        #region CONSTRUCTORES
        static ParaisoFiscal()
        {
            cantidadDeCuentas = 0;
            fechaDeInicioActividades = DateTime.Now;
        }

        private ParaisoFiscal()
        {
            this._listadoCuentas = new List<CuentaOffShore>();
        }

        private ParaisoFiscal(EParaisosFiscales lugar) : this()
        {

            this._lugar = lugar;

        }

        #endregion

        #region METODOS
        public void MostrarParaiso()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Fecha de inicio de actividades: " + fechaDeInicioActividades);
            sb.AppendLine("Lugar de radicacion: : " + this._lugar);
            sb.AppendLine("Cantidad de cuentas: " + this._listadoCuentas.Count);

            sb.AppendLine("--------------------------------- DETALLE DE CUENTAS ---------------------------------");

            foreach (CuentaOffShore cuenta in this._listadoCuentas)
            {
                sb.AppendLine(""+ Cliente.RetornarDatos(cuenta.getDueño()));
                sb.AppendLine("Numero de cuenta de Cuenta : " + (int)cuenta);
                sb.AppendLine("Saldo : " + cuenta.getSaldo());
            }
            Console.WriteLine(sb.ToString());

        }

        #endregion

        #region SOBRECARGAS

        public static bool operator ==(ParaisoFiscal pf, CuentaOffShore cos)
        {
            bool retorno = false;
            foreach (CuentaOffShore cuenta in pf._listadoCuentas)
            {
                if(cuenta==cos)
                {
                    retorno = true;
                        continue;

                }
            }
            return retorno;

        }
        public static bool operator !=(ParaisoFiscal pf, CuentaOffShore cos)
        {

            return !(pf == cos);
        }

        public static ParaisoFiscal operator -(ParaisoFiscal pf, CuentaOffShore cos)
        {
            bool retorno = false;
            if(pf==cos)
            {
                if(pf._listadoCuentas.Remove(cos))
                {
                    cantidadDeCuentas--;
                    retorno =true;
                }
                
            }

            if(retorno)
            {
                Console.WriteLine("Se quito la cuenta del Paraiso ....");
            }else
            {
                Console.WriteLine("No se logro eliminar la cuenta ....");
            }
            return pf;
        }

        public static ParaisoFiscal operator +(ParaisoFiscal pf, CuentaOffShore cos)
        {
            bool retorno = false;
            if (pf != cos)
            {
                    pf._listadoCuentas.Add(cos);
                    cantidadDeCuentas++;
                    retorno = true;
            }else
            {
                if(pf==cos)
                {
                    foreach (CuentaOffShore aux in pf._listadoCuentas)
                    {

                        if (aux == cos)
                        {
                           aux.setSaldo(cos.getSaldo()+ aux.getSaldo());
                            retorno = true;
                            continue;

                        }
                        
                    }
                    
                }

            }
            
            if (retorno)
            {
                Console.WriteLine("Se agrego la cuenta al Paraiso ....");
            }
            else
            {
                Console.WriteLine("No se logro agregar la cuenta ....");
            }
            return pf;

        }

        public static implicit operator ParaisoFiscal(EParaisosFiscales epf)
        {
            return new ParaisoFiscal(epf);
        }
        #endregion
    }
}
