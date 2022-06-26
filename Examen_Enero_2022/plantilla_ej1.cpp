/*
NOMBRE Y APELLIDOS: Alejandro Barrachina Argudo

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/
#include <iostream>

using namespace std;

/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada de la especificaci�n y el dise�o sistem�tico
del mismo.
*/

/*
PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

*/
int cuantos_entre(float v[], int n, float a, float b);
/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

*/

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables
	- v[]                <float>: array de numeros a analizar
	- n                  <int>:   numero de elementos en el array
	- a                  <float>: numero menor
	- b                  <float>: numero mayor
	- mayoresoMenoresQue <int>:   total de numeros del array en el intervalo [a,b]
	- i                  <int>:   indice para recorrer el array

Paso 2. Invariante
	res = #i : 0 < i <= n y a <= v[i] <=b

Paso 3. Inicializaci�n
	- mayoresOmenoresQue = 0;
	- i = 0;

Paso 4. Condici�n del bucle, y c�digo tras el bucle.
	- condicion del bucle: i < n
	- codigo tras el bucle: return mayoresoMenoresQue

Paso 5. Cuerpo del bucle
	- Se comprueba si el valor de v en el indice i está en el intervalo [a,b], si esta en el intervalo se suma 1 a la variable
	mayoresoMenoresQue

Paso 6. Justificaci�n de que el algoritmo siempre termina.
	Al ser un bucle for siempre se avanza la variable i, por lo tanto en algun momento i >= n

Paso 7. Complejidad:
	O(n) siendo n el numero de elementos en el array. Solo se recorre cada elemento una vez.

*/

int cuantos_entre(float v[], int n, float a, float b)
{
	// A IMPLEMENTAR
	int mayoresoMenoresQue = 0;

	for (int i = 0; i < n; ++i)
	{
		if (v[i] >= a && v[i] <= b)
		{
			mayoresoMenoresQue++;
		}
	}

	return mayoresoMenoresQue;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR
const int MAX_ELEMS = 10000;

bool ejecuta_caso()
{
	int n;
	cin >> n;
	if (n == -1)
		return false;
	else
	{
		float a, b;
		cin >> a >> b;
		float v[MAX_ELEMS];

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		cout << cuantos_entre(v, n, a, b) << endl;
		return true;
	}
}

int main()
{
	while (ejecuta_caso())
		;
}
