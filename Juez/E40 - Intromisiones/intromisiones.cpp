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
	PARAMETROS:
		(entrada)	<int> a[]	-> vector sin intromision
		(entrada)	<int> b[]	-> vector con intromision
		(entrada)	<int> n		-> tama�o de vector a
		(entrada)	<int> i		-> inicio del tramo
		(entrada)	<int> j		-> fin del tramo


(2) An�lisis de casos:

(2.1) Casos base
	i==j
		b[i]=b[j] es intromision

(2.2) Casos recursivos
	i < j
		Sea m=(i+j)/2
		Si b[m] == a[m]
			la intomision esta en el tramo m+1 a j
		Si b[m] != a[m]
			la intomision esta en el tramo i a m

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n 
del algoritmo. Describe de manera clara y concisa c�mo se lleva a 
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.
	Se invoca a la generalizacion con a[],n,b[],0,n-1
	El resulatado se devuelve directamente



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n
	T(n) = c0 si ini==fin
	T(n) = c1 + 2T(n/2) si ini!=fin
(4.2) Resoluci�n utilizando los patrones vistos en clase
	El problema se ha resuleto siguiendo el esquema Divide y Venceras

(4.3) Determinaci�n justificada de la complejidad del algoritmo final.
	Como a=1 es igual a b^k=2^1=2
	El coste del algoritmo es O(n log n)


*/

int buscar(int a[], int n, int b[], int ini, int fin) {
	if (ini == fin) {
		return b[ini];
	}
	else {
		int mid = (ini + fin) / 2;
		if (a[mid] == b[mid]) {
			return buscar(a, n, b, mid + 1, fin);
		}
		else {
			return buscar(a, n, b, ini, mid);
		}
	}
}

// El vector 'a' tiene 'n' elmenentos. El vector 'b' n+1
int intruso(int a[], int n, int b[]) {
   // A IMPLEMENTAR
	int ini = 0;
	int fin = n;
	return buscar(a, n, b, ini, fin);
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const int NMAX = 10000; // El vector 'a' no tendr� m�s de 10000 de elementos

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		int a[NMAX];
		int b[NMAX + 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++) {
			cin >> b[i];
		}
		cout << intruso(a, n, b) << endl;
        return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}