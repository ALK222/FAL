#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
	0<=n<=tam(a)

*/
int num_chupiguays(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
	num_chupiguays(n) = a[n] = (a[n-1] + (i veces) + a[n-i]) * b: 0<=i<n;
	resul = PARA_TODO i: 0<=i<n : num_chuiguays(i)

	 
 */
 

/*
DISEÑO DEL ALGORITMO:
-- Especifica cada paso del diseño en cada apartado indicado

Paso 1. Variables
	a[] y n -> Entrada
	resul -> Salida
	i -> control
	suma -> almacena la suma del vector

Paso 2. Invariante
	(0<=i<=n) Y num_chupiguays(a,i)

Paso 3. Inicialización
	i=0;
	res=0;
	suma=0;

Paso 4. Condición del bucle, y código tras el bucle
	Condicion -> i<n
	Codigo tras el bucle -> La postcondicion


Paso 5. Cuerpo del bucle
	Pueden darse 2 casos:

	1:	a[i] % suma == 0 -> resul++

	2:	a[i] % suma != 0 -> resul no incrementa

	En ambos se sigue iterando

Paso 6. Justificación de que el algoritmo siempre termina
	En cada iteracion incrementa i hasta que toma el valor n-1
	siendo este la expresion de cota


Paso 7. Complejidad
	MEJOR CASO: Orden Constante O(1)
		n = 0
		T = Tini_y_fin

	PEOR CASO: Orden Lineal O(n)
		n != 0
		T = Tini_y_fin + (n * Tbucle);
			Lim(n tiende a infinito) Tini_y_fin + (n * tBucle) = tBucle 
*/


int num_chupiguays(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int i = 0;
	int suma = 0;
	int resul = 0;
	while (i < n) {
		if (suma != 0) {
			if (a[i] % suma == 0) {
				resul++;
			}
		}
		else {
			if (a[i] == 0) {
				resul++;
			}
		}
		suma += a[i];
		i++;
	}
	return resul;
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
		   cout << num_chupiguays(a, n) << endl;
	   }
   }
   while (n != -1);
}