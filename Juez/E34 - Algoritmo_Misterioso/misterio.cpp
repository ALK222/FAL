#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habrá vectores de más de un millón de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  
	0 < n <= TMAX

*/

 
int misterio(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int resul = a[0];
	int cont = 1;
	int aux = 1;
	for (int i = 1; i < n; i++) {//recorremos el vector
		if (a[i] == a[i - 1]) {		//si el elemento es igual al anterior
			aux++;					//aumentamos las veces que se repite el numero
		}
		else {						//si es distinto
			if (aux > cont) {			//si las repeticiones son mas que las del elemento con mayor repeticiones
				cont = aux;					//sustituimos repeticiones
				resul = a[i - 1];			//sustituimos el elemento del resultado
			}
			else if ((aux == cont) && (a[i - 1] < resul)) {	//si las repeticiones son las mismas pero el elemento es menor al resultado
				resul = a[i - 1];			//sustituimos el elemento del resultado
			}
			aux = 1;					//reseteamos las repeticiones
		}
	}
	if (aux > cont) {			//si las repeticiones son mas que las del elemento con mayor repeticiones
		cont = aux;					//sustituimos repeticiones
		resul = a[n - 1];			//sustituimos el elemento del resultado
	}
	else if ((aux == cont) && (a[n - 1] < resul)) {	//si las repeticiones son las mismas pero el elemento es menor al resultado
		resul = a[n - 1];			//sustituimos el elemento del resultado
	}
	return resul;
} 

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso 
   -- de este algoritmo, indicando claramente cuál es el tamaño del problema
	
	En cualquier caso, se recorre una vez cada elemento del array,
	por lo que el algoritmo tiene coste lineal => O(n)
*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

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
		   cout << misterio(a, n) << endl;
	   }
   }
   while (n != -1);
}