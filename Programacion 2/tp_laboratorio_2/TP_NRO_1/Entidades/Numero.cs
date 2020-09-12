using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Numero
    {
        private double numero;

        public Numero()
        {
            this.numero = 0;
        }
        public Numero(double numero)
        {
            setNumero(numero.ToString());
        }
        public Numero(string strNumero)
        {
            setNumero(strNumero);
        }
        public void setNumero(string strNumero)
        {
            this.numero = validarNumero(strNumero);
        }
        public double validarNumero(string strNumero)
        {
            double retorno = 0;
            double.TryParse(strNumero, out retorno);
            return retorno;
        }

        public static double operator +(Numero n1, Numero n2)
            {
            return n1.numero + n2.numero;
            }
        public static double operator -(Numero n1, Numero n2)
        {
            return n1.numero - n2.numero;
        }
        public static double operator *(Numero n1, Numero n2)
        {
            return n1.numero * n2.numero;
        }
        public static double operator /(Numero n1, Numero n2)
        {
            double retorno = double.MinValue;
            if(n1.numero  > 0 && n2.numero > 0)
            {
                retorno = n1.numero / n2.numero;
            }

            return retorno;
        }

        public static string DecimalBinario(double num)
        {
            Int32 numero = Convert.ToInt32(num);

            String cadena = "";


            if (numero > 0)
            {

                while (numero > 0)
                {
                    if (numero % 2 == 0)
                    {
                        cadena = "0" + cadena;
                    }
                    else
                    {
                        cadena = "1" + cadena;
                    }
                    numero = (int)(numero / 2);
                }

            }

            return cadena;
        }
        public static string DecimalBinario(string strNumero)
        {
            Int32 numero = 0;
            Int32.TryParse(strNumero, out numero);
            String cadena = "";

            
            if (numero > 0)
            {
                
                while (numero > 0)
                {
                    if (numero % 2 == 0)
                    {
                        cadena = "0" + cadena;
                    }
                    else
                    {
                        cadena = "1" + cadena;
                    }
                    numero = (int)(numero / 2);
                }
                
            }

            return cadena;

        }

        public static string BinarioDecimal(string strNumero)
        {
            char[] array = strNumero.ToCharArray();
            
            Array.Reverse(array);
          
            int num = 0;

            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] == '1')
                {
                    
                    if (i == 0)
                    {
                        num += 1;
                    }
                    else
                    {
                        num += (int)Math.Pow(2, i);
                    }
                }

            }

            return num.ToString();
        }

        public static bool EsBinario(string strNumero)
        {
            bool ret = false;
            int cont = 0;
            char[] array = strNumero.ToCharArray();

            Array.Reverse(array);

            

            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] == '1' || array[i] == '0')
                {
                    cont++;
                   
                }

            }

            if(array.Length==cont)
            {
                ret = true;
            }
            return ret;
        }


    }
}
