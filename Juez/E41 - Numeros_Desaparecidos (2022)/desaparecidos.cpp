
#include <iostream>
using namespace std;


const int TMAX = 300000;  // No habrá vectores de más e 300000 elementos


/*
(1) En caso de utilizar una generalizacion, 
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.
	<int> ini (entrada):					primera posicion del array
	<int> fin (entrada):					ultima posicion del array
	<int> desaparecido (entrada/salida):	mayor numero que falta


(2) Análisis de casos:

(2.1) Casos base
	fin=ini+1 && a[ini]!=(a[fin]-1)
	Solo hay 2 elementos en el vector y no son valores consecutivos


(2.2) Casos recursivos
	se calcula la mitad del vector (mid) y
	si faltan(ini,mid) es true, se busca el numero que falta en el tramo ini-mid
	si flatan(ini,mid) es false, se busca el numero que falta en el tramo mid-fin	

(3) En caso de utilizar una generalizacion, definición por inmersión 
del algoritmo. Describe de manera clara y concisa cómo se lleva a 
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.
	Despues de tener las cotas ini y fin en la funcion principal, llamamos a la generalizacion,
	esta va dividiendo el vector en mitades para obtener el mayor de los numeros que faltan,
	cuando esta termina, devuelve dicho numero.


(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinación de las ecuaciones de recurrencia para la generalización
		T(base)= n*c_0
		T(n)= c_1+T(n/2)

(4.2) Resolución utilizando los patrones vistos en clase
		El promesa se resuelve usando el esquema "Divide y Venceras"

(4.3) Determinación justificada de la complejidad del algoritmo final.
		Segun las ecuaciones de recurrencia vistas, la complejidad es O(n^2)


*/
bool faltan(int a[], int ini, int n) {
	bool falta = false;
	while (!falta && ini < n) {
		if (a[ini] != a[ini + 1] - 1) {
			falta = true;
		}
		ini++;
	}
	return falta;
}

void buscaDesaparecido(int a[], int ini, int fin, int& desaparecido) {
	if (fin == ini + 1) {
		if (a[ini] != a[fin] - 1) {
			desaparecido = a[fin] - 1;
		}
	}
	else {
		int mid = (ini + fin) / 2;
		int aux = desaparecido;
		if (!faltan(a, mid, fin)) {
			buscaDesaparecido(a, ini, mid, desaparecido);
		}
		else {
			buscaDesaparecido(a, mid, fin, desaparecido);
		}
		if (desaparecido < aux) {
			desaparecido = aux;
		}
	}
}

int num_perdido(int a[], int n) {
	// A IMPLEMENTAR
	int ini = 0;
	int desaparecido = 0;
	int fin = n - 1;
	buscaDesaparecido(a, ini, fin, desaparecido);
	return desaparecido;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool procesa_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
   	   for (int i=0; i < n; i++) {
         cin >> a[i];		
	   }
	   cout << num_perdido(a,n) << endl;
	   return true;
	}
}


int main() {
    while (procesa_caso());
}