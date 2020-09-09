using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase04SobreCarga
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Sobrecarga";

            Cosa cosaUno = new Cosa();
            Cosa cosaDos = new Cosa("Pedro");
            Cosa cosaTres = new Cosa(23,"Qoqo");

            cosaUno.EstablecerValor("Rei");
            cosaUno.EstablecerValor(13); 
            cosaUno.Mostrar();
            
            cosaDos.EstablecerValor(23);
            cosaDos.Mostrar();

            cosaTres.Mostrar();

            Console.ReadKey(true);
        }
    }
}
