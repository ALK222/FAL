/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>
using namespace std;

/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada del dise�o sistem�tico del mismo.
*/

/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.
	  #NOMBRE#  #ENTRADA/SALIDA#  #TIPO#  #PROPOSITO#
	- inicio     (entrada)         <int>:  primera posición del intervalo a analizar
	- fin        (entrada)         <int>:  ultima posición del intervalo a analizar
	- n          (entrada)         <int>:  total de elementos del array a
	- a[]        (entrada)         <int>:  array de elementos original
	- b[]        (entrada)         <int>:  array de elementos con intruso
	- intruso    (salida)          <int>:  valor intruso del array b


(2) An�lisis de casos:

(2.1) Casos base
	1.- fin == 0:
		comprobamos si el valor inicial es distinto en ambos arrays.
	2.- inicio = n-1
		comprobamos si el elemento distinto es el ultimo elemento del array b

(2.2) Casos recursivos

	Si a[mitad] != b[mitad] y [(a[mitad - 1] == b[mitad]) && (a[mitad] != b[mitad + 1])], esto quiere decir que el elemento intruso esta mas atras que la posicion mitad
	En caso de que a[mitad] == b[mitad], entonces el intruso estara mas a delante.

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.
	Al acabar la generalizacion ya tenemos el intruso


(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n
	C_0: coste de inicio del algoritmo
	C_1: coste recursivo

(4.2) Resoluci�n utilizando los patrones vistos en clase

(4.3) Determinaci�n justificada de la complejidad del algoritmo final.



*/

void intrusoAux(int inicio, int fin, int n, int a[], int b[], int &intruso)
{
	if (fin == 0)
	{
		if (a[0] != b[0])
		{
			intruso = b[0];
		}
	}
	else if (inicio == n - 1)
	{
		intruso = b[n];
	}
	else
	{
		int mitad = (inicio + fin) / 2;
		if (a[mitad] != b[mitad])
		{
			if (a[mitad - 1] == b[mitad])
			{
				if (a[mitad] != b[mitad + 1])
				{
					intruso = b[mitad];
				}
				else
				{
					intrusoAux(inicio, mitad, n, a, b, intruso);
				}
			}
			else
			{
				intruso = b[mitad];
			}
		}
		else
		{
			intrusoAux(mitad, fin, n, a, b, intruso);
		}
	}
}

// El vector 'a' tiene 'n' elmenentos. El vector 'b' n+1
int intruso(int a[], int n, int b[])
{
	// A IMPLEMENTAR
	int intruso = -1;

	intrusoAux(0, n, n, a, b, intruso);

	return intruso;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const int NMAX = 10000; // El vector 'a' no tendr� m�s de 10000 de elementos

bool ejecuta_caso()
{
	int n;
	cin >> n;
	if (n == -1)
	{
		return false;
	}
	else
	{
		int a[NMAX];
		int b[NMAX + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++)
		{
			cin >> b[i];
		}
		cout << intruso(a, n, b) << endl;
		return true;
	}
}

int main()
{
	while (ejecuta_caso())
		;
	return 0;
}
