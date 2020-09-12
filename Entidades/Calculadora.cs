using System;

public static class Calculadora
{

	public static double Operar(double num1, double num2, string operador)
	{
		double tot=0;
		switch(operador)
        {
			case "+":
				tot = num1 + num2;
				break;
			case "-":
				tot = num1 - num2;
				break;
			case "*":
				tot = num1 * num2;
				break;
			case "/":
				tot = num1 / num2;
				break;
		}
		return tot;
	}
	private static string ValidarOperador(char operador)
	{
		if(operador!= '+' || operador != '-' || operador != '*' || operador != '/')
        {
			operador = '+';
        }
		return operador.ToString();
	}
	
}
