using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Integrador
{
    public class CuentaOffShore
    {

        #region ATRIBUTOS

        private Cliente _dueño;
        private int _numeroCuenta;
        private double _saldo;
        
        #endregion


        #region CONSTRUCTORES
        

        public CuentaOffShore(Cliente dueño,int numero, double saldoInicial)
        {
            this._dueño = dueño;
            this._numeroCuenta = numero;
            this._saldo = saldoInicial;

        }

        public CuentaOffShore(String nombre, ETipoCliente tipoCliente, int numero, double saldoInicial) : this(new Cliente(tipoCliente, nombre), numero, saldoInicial)
        {
           
        }
        #endregion

        #region METODOS
        public Cliente getDueño()
        {
            return this._dueño;
        }

        public double getSaldo()
        {
            return this._saldo;
        }

        public void setSaldo(double valor)
        {
            this._saldo = valor;
        }

        #endregion

        #region SOBRECARGAS
        public static bool operator ==(CuentaOffShore cos1, CuentaOffShore cos2)
        {
            bool ret = false;
            
            if(cos1._numeroCuenta==cos2._numeroCuenta && cos1._dueño.AliasParaIncognito == cos2._dueño.AliasParaIncognito)
            {
                ret = true;
            }
            return ret;
        }
        public static bool operator !=(CuentaOffShore cos1, CuentaOffShore cos2)
        {

            bool ret = false;

            if (cos1._numeroCuenta != cos2._numeroCuenta && cos1._dueño.AliasParaIncognito != cos2._dueño.AliasParaIncognito)
            {
                ret = true;
            }
            return ret;
        }
        public static explicit operator int(CuentaOffShore cos)
        {
            return cos._numeroCuenta;
        }
        #endregion
    }
}
