#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
	0<n<tam(a)
*/

int llena_mochila(const int a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     resul = PARA_TODO i: 0<i<n: SUMA PARA_TODO j: 0<=j<i: a_j <=k

	 
 */
 

/*
DISEÑO DEL ALGORITMO:

Paso 1. Variables
	maximo -> int que guarda el maximo de elementos
	i -> int que sirve de indice para el array
	suma -> int que guarda el peso actual de los elementos
	total -> int con los elementos acuales
	res -> int que indica el ultimo elemento comprobado

Paso 2. Invariante
     0<i<n Y suma<=k

Paso 3. Inicialización
	maximo = 0;
	i = n - 1;
	suma = 0;
	total = 1;
	res = n -  1;

Paso 4. Condición del bucle, y código tras el bucle.
	Condicion -> (i>=0) Y ((n - i + 1) - max_total >= 0)
	Despues del bucle -> conseguimos la postcondicion
	
Paso 5. Cuerpo del bucle
	Pueden darse 2 casos:

	1.1:	suma > k - a[i] -> reiniciamos i hasta el ultimo numero sin comprobar

	1.2: suma <= k - a[i] -> suma += a[i], total++ y seguimos iterando
	
	Se dan otros 2 casos:
		
	2.1: total <= max_total -> no se actualiza max_total

	2.2: total > max_total -> se actualiza max_total

Paso 6. Justificación de que el algoritmo siempre termina.
 		En cada iteracion incrementa i hasta que toma el valor n-1
		siendo este la expresion de cota
 
Paso 7. Complejidad:
	MEJOR CASO: Coste Constante O(1)
		n=1
		T = Tini_y_fin + Tbucle
	
	PEOR CASO: Coste Lineal O(n)
		n>1
		T = Tini_y_fin + (n * Tbucle)
			Lim(n tiende a infinito) Tini_y_fin + (n * Tbucle) = Tbucle
*/

int llena_mochila(const int a[], int n, int k) {
	  // A IMPLEMENTAR
	int maximo = 0;
	int i = n - 1;
	int suma = 0;
	int total = 1;
	int res = n -  1;
	while (i >= 0) {
		suma += a[i];
		if (suma > k) {
			suma = suma - a[res];
			total -= 1;
			res--;
		}
		if (total > maximo) {
			maximo = total;
		}
		total++;
		i--;
	}
	return maximo;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int & n) {
	cin >> n; 
   for (int i=0; i < n; i++) {
	   cin >> a[i]; 
   }   
}

int main() {
	static int a[TMAX];
	int n;
    do {
	   lee_vector(a,n);	   
	   if (n>=0) {
		   int k;
		   cin >> k;
		   cout << llena_mochila(a, n, k) << endl;
	   }
   }
   while (n != -1);
}