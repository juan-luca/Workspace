using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Integrador
{
    public class Cliente
    {
        #region ATRIBUTOS
        private string _aliasParaIncognito;
        private string _nombre;
        private ETipoCliente tipoDeCliente;


        public string AliasParaIncognito 
        { 
            get
            {
                if (_aliasParaIncognito == "Sin Alias")
                {
                    CrearAlias();
                }

                return _aliasParaIncognito;
            }

         }

        #endregion


        #region CONSTRUCTORES
        private Cliente()
        {
            this.tipoDeCliente = ETipoCliente.SinTipo;
            this._aliasParaIncognito = "Sin Alias";
            this._nombre = "NN";

        }

        public Cliente(ETipoCliente tipodecliente) : this() 
        {
            this.tipoDeCliente = tipodecliente;
        }

        public Cliente(ETipoCliente tipocliente, string nombre) : this(tipocliente)
        {
            this._nombre = nombre;
        }
        #endregion

        #region METODOS
      

        private void CrearAlias()
        {
            Random rnd = new Random();

            this._aliasParaIncognito = rnd.Next(1000, 9999).ToString() + tipoDeCliente; 

        }
        private string RetornarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Tipo de Cliente: "+this.tipoDeCliente.ToString());
            sb.AppendLine("Nombre: "+this._nombre);
            sb.AppendLine("Alias: "+this.AliasParaIncognito);

            return sb.ToString();
        }

        public static string RetornarDatos(Cliente UnCliente)
        {
            return UnCliente.RetornarDatos();
        }

        #endregion




    }
}
