using Entidades;
using System;
using System.Windows.Forms;




namespace MiCalculadora
{
    public partial class FormCalculadora : Form
    {
        Validar v = new Validar();

        public FormCalculadora()
        {
            

            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.comboBox1.Items.AddRange(new String[] { "+", "-", "*", "/" });
        }

       

      

        private void button1_Click(object sender, EventArgs e)
        {
            double total;
            if(string.IsNullOrEmpty(textBox1.Text) || string.IsNullOrEmpty(textBox2.Text))
            {
                MessageBox.Show("Ingrese un numero en ambos campos por favor...", "ATENCION", MessageBoxButtons.YesNo, MessageBoxIcon.Error);

            }else
            {
                total=Operar(this.textBox1.Text, this.textBox2.Text, this.comboBox1.Text);
                if(total == double.MinValue)
                {
                    Resultado.Text = "SYNTAX ERROR";
                }
                else
                { 
                    Resultado.Text = total.ToString();
                }
                
            }
        }
        private static double Operar(string numero1, string numero2, string operador)
        {
            double total = 0;

            Numero numeroUno = new Numero(numero1);
            Numero numeroDos = new Numero(numero2);
            total = Calculadora.Operar(numeroUno, numeroDos, operador);
            return total;
        }

      

        private void button3_Click(object sender, EventArgs e)
        {
            this.Dispose(); 
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Limpiar();
        }
        private void Limpiar()
        {
            this.textBox1.Text = "";
            this.textBox2.Text = "";
            this.Resultado.Text = "";
            this.comboBox1.Text = "+";
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            v.NumerosDecimales(e);
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            v.NumerosDecimales(e);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Resultado.Text = Numero.DecimalBinario(Resultado.Text);
        }

        private void button5_Click(object sender, EventArgs e)
        {


            if(Numero.EsBinario(Resultado.Text)==true)
            {
                Resultado.Text = Numero.BinarioDecimal(Resultado.Text);
            }else
            {
                MessageBox.Show("El numero debe ser BINARIO para poder convertirlo a decimal", "ATENCION", MessageBoxButtons.YesNo, MessageBoxIcon.Error);
            }
            
        }

      
    }
}
