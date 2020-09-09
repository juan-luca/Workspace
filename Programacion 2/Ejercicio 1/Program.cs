using System;

namespace Ejercicio_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n1, n2, n3, n4, n5;
            int max=0;
            Console.Title = "Ejercicio 1";
            Console.WriteLine("Ingrese el numero 1");
            Int32.TryParse(Console.ReadLine(), out n1);
            if(max<n1)
            {
                max = n1;
            }
            Console.WriteLine("Ingrese el numero 2");
            Int32.TryParse(Console.ReadLine(), out n2);
            if (max < n2)
            {
                max = n2;
            }
            Console.WriteLine("Ingrese el numero 3");
            Int32.TryParse(Console.ReadLine(), out n3);
            if (max < n3)
            {
                max = n3;
            }
            Console.WriteLine("Ingrese el numero 4");
            Int32.TryParse(Console.ReadLine(), out n4);
            if (max < n4)
            {
                max = n4;
            }
            Console.WriteLine("Ingrese el numero 5");
            Int32.TryParse(Console.ReadLine(), out n5);
            if (max < n5)
            {
                max = n5;
            }

            Console.WriteLine("El numero mas es " + max);


        }
    }
}
