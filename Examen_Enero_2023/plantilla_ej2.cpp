/*
NOMBRE Y APELLIDOS: Rodrigo Sosa Saez

*/

#include <iostream>
using namespace std;


/*
Nota: NO es necesario que especifiques el algoritmo, ni las
funciones auxiliares utilizadas. Pero, en caso de utilizar
una generalización, sí debes describir sus parámetros, 
su resultado, y el próposito de los mismos 

(1) SI UTILIZAS UNA GENERALIZACION, DETALLA AQUÍ SUS PARÁMETROS,
    SU RESULTADO, Y EL PROPÓSITO DE LOS MISMOS 
	los parametro de entrada son:
	int  a[] (entrada):	el vector que guarda todos los elementos
	int n (entrada):	la cantidad de elementos del vector
	int ini (entrada):	elemento inicial del tramo a estudiar
	int fin (entrada):	elemento final del tramo a estudiar
	
	El proposito de los parametro ini y fin son para acotar los extremos de los tramos a estudiar
	y calcular el elemento central del tramo y para dividir el tamano del problema en 2 subproblemas
	si no se puede resolver de manera satisfactoria

	el algoritmo devuelve un bool indicando si el algoritmo tiene un elemento "ni fu ni fa"


(2) DISEÑO (CASOS)
		Casos Base:
			n=1: false (un valor es el mayor y el menor a la vez)
		Casos recursivos:
			n>1: sacamos el valor central y lo comparamos con los extremos
				1) si es menor que el final y mayor que el inicial -> true
				2) si es menor o igual al inicial -> llamada recursiva final a la segunda mitad del tramo
				3) si es mayor o igual al final -> llamada recursiva final a la primera mitad del tramo

(3) JUSTIFICACION DE LA TERMINACION DEL ALGORITMO
		En cada llamada recursiva se utiliza una mitad del tramo inicial, asi hasta que en el peor caso
		solo utilizamos un elemento, que se corresponde con el caso base, por lo que se devuelve false;
		en cualquier otro caso, el valor central estara entro los de los extremos y devolvera true;

(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE
	bool (resul) resolver ((in)int  a[],(in) int n,(in) int ini,(in) int fin) 
		

(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO
		T(n) = c0 (caso base, n<=1), siendo c0 el coste del if y su return
		T(n) = c1 + 2T(n/2) siendo c1 el coste del if y del return

		Con estas ecuaciones de recurrencia, sabemos que el coste del algoritmo es O(n log(n))
*/

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/

bool resolver(int  a[], int n, int ini, int fin) {
	if (ini + 1 == fin) {					//Si solo hay un elemento
		return false;							//Devolvemos false
	}
	int m = (ini + fin) / 2;				//Calculamos el centro del tramo
	if (a[m] > a[0] && a[m] < a[n - 1]) {	//Si el valor del centro es mayor que el inicio y menor que el final
		return true;							//Devolvemos cierto
	}
	else {									//En otro caso
		if (a[m] <= a[0]) {						//Si el valor del medio es menor o igual que el inicial
			return resolver(a, n, m, fin);			//Calculamos el tramo que va desde la mitad al final

		}
		else {									//En otro caso
			return resolver(a, n, ini, m);			//Calculamos el tramo que va desde el inicio hasta la mitas
		}
	}
	return false;							//Para cualquier otra cosa devolvemos false
}


bool hay_nifunifa(int a[], int n) {
	if (n > 0) {	//Si el vector no es vacio
		return resolver(a, n, 0, n);	//Llamamos a la funcion auxiliar con las posiciones inicial y final
	}
	return false;
}

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/


const static int MAX_ELEMS=1000000;
bool ejecuta_caso() {
  	static int a[MAX_ELEMS];
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
      for (int i=0; i < n; i++) {
		  cin >> a[i];
	  }
	  if (hay_nifunifa(a,n)) {
		  cout << "SI" << endl;
	  }
	  else {
	      cout << "NO" << endl;
	  }	  
      return true;	  
	}
}

int main() {
	while(ejecuta_caso());
}
