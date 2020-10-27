using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Vehiculo
    {
        protected List<Fabricante> fabricante;
        protected Random generadorDeVelocidades;
        protected string modelo;
        protected float precio;
        protected int velocidadMaxima;

        protected int VelocidadMaxima
        {
            get
            {
                if (this.velocidadMaxima == 0)
                {
                    generadorDeVelocidades = new Random();
                    this.velocidadMaxima = generadorDeVelocidades.Next(100, 280);
                }
                return this.velocidadMaxima;

            }
        }
        private static string Mostrar(Vehiculo v)
        {
            StringBuilder sb = new StringBuilder();
            foreach(Fabricante F in v.fabricante)
            {
                sb.AppendLine((string)F);
            }
            
            sb.AppendLine("Modelo: " + v.modelo);
            sb.AppendLine("Precio: " + v.precio);
            sb.AppendLine("Velocidad Maxima: " + v.velocidadMaxima);

            return sb.ToString();
        }
        public static explicit operator string(Vehiculo v)
        {
            

            return Mostrar(v);
        }

        public static bool operator ==(Vehiculo v1, Vehiculo v2)
        {
          

            return v1.modelo == v2.modelo && v1.fabricante == v2.fabricante;
        }
        public static bool operator !=(Vehiculo v1, Vehiculo v2)
        {
            return !(v1 == v2);
        }

        
            static Vehiculo()
            {
            //Vehiculo.generadorDeVelocidades = new Random();
        }


        public Vehiculo(float precio, string modelo, Fabricante fabri)
        {
            this.fabricante = new List<Fabricante>();
            this.precio = precio;
            this.modelo = modelo;
                this.fabricante.Add(fabri);


        }
        public Vehiculo(string marca, EPais pais, string modelo,float precio)
        {
            this.fabricante = new List<Fabricante>();
            Fabricante fabri = new Fabricante(marca, pais);
            this.precio = precio;
            this.modelo = modelo;
            this.fabricante.Add(fabri);
        }

    }
}
