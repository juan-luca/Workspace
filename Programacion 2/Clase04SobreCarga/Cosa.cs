using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Clase04SobreCarga
{
    class Cosa
    {
        private int entero;
        private string cadena;
        private DateTime fecha;

        public Cosa()
        {
            this.entero = 0;
            this.cadena = "";
            this.fecha = DateTime.Now;
        }

        public Cosa(string cadena)
        {
            this.entero = 0;
            this.cadena = cadena;
            this.fecha = DateTime.Now;
        }

        public Cosa(int numero, string cadena)
        {
            this.entero = numero;
            this.cadena = cadena;
            this.fecha = DateTime.Now;
        }

        public void EstablecerValor(int numero) {
            this.entero = numero;
        }

        public void EstablecerValor(string cadena)
        {
            this.cadena = cadena;
        }
        public void EstablecerValor(DateTime fecha)
        {
            this.fecha = fecha;
        }

        public void Mostrar()
        {
            Console.WriteLine("Cadena: {0}", this.cadena);
            Console.WriteLine("Numero: {0}", this.entero);
            Console.WriteLine("Fecha: {0}", this.fecha);
            Console.WriteLine("\n");
        }

    }
}
