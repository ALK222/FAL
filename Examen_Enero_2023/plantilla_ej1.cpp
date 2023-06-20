/*
NOMBRE Y APELLIDOS: Rodrigo Sosa Saez

*/

#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aquí la precondición de la función.
	P={0 < n <= tam(a)}

*/

bool /* resul */ hay_c_tramo(int a[], int n, int c);

/*
	   POSTCONDICION DE LA FUNCION:
	   ---Escribe aquí la poscondición de la función. Para refirte
	   ---al valor devuelto por la función, utiliza la pseudo-variable
	   ---'resul'
	(1) Definiciones auxiliares (si procede):
		suma = SUMA i: 0<=i<n: a[i]

	(2) Postcondición
		Q={ suma = c || EXISTE i: 0<=i<n: a[i] = c }

 */



/* DISEÑO DEL ALGORITMO:
	--- Detalla aquí el proceso seguido para diseñar el
	--- algoritmo

	PASO 1. Variables adicionales (aparte de los parámetros y el resultado)
			(bool)  tramo: sirve para indicar si hay elementos problematicos en el tramo, que requieran que se corrija
			(int)		i: es el iterador del bucle e indica el elemento actual
			(int)	 suma: guarda la suma de los elementos previos, siendo esta menor o igual al valor c
			(int)	 prim: indica la primera posicion del tramo de elementos del bucle

	PASO 2. Invariante
	   (2.1) Definiciones auxiliares (si procede)
			suma: SUMA u: 0<=u<i: a[u];
			resul: suma==c ||EXISTE u: 0<=u<i: a[u] == c;
	   
	   (2.2) Invariante
			i<n && !resul

	PASO 3. Código de inicialización, justificando que, tras
	        dicho código, se cumple el invariante
			bool resul = false;
			bool tramo = true;
			int i = 0;
			int suma = a[0];
			int prim = -1;

				
	
	PASO 4. Condición del bucle, código tras el bucle (si procede),
	        y justificación de que, una vez finalizado el algoritmo,
			se cumple la postcondición
			
			Condicion: deben quedar elementos por analizar y no se ha encontrado una solucion
			Codigo tras el bucle: el algoritmo devuelve si se ha encontrado una solucion o no

			Justificacion de que se cumple la postcondicion: la postcondicion dice que si la suma de varios elementos en orden es igual a un valor c
															 o si existe un elemento cuyo valor es igual a c este sera true,
															 si no se cumple ninguna de estas condiciones y no quedan elementos por analizar se devolvera false
															 y si se cumple alguna de estas condiciones se devuelve true.


    PASO 5. Diseño del cuerpo del bucle, justificando que dicho código
	        preserva el invariante
			
			Hay 3 casos para cada iteracion:
			1)	el elemento es mayor que c: reseteamos los valores de la suma y el inicio del tramo
			2) el elemento es igual a c: indicamos que se cumple resul y saldra del algoritmo
			3) el elemento es menor que c: se mira si hay un tramo estudiandose, donde hay 2 opciones:
				3.1) el tramo no existe: se inicia la suma con el elemento que se estudia y se indica que esa posicion es el inicio del tramo
				3.2) el tramo existe: dependiendo del resultado de la suma con el elemento hay 3 posibilidades:
					a) si es menor que c: se suma el elemento
					b) si es igual a c:	indicamos que se cumple resul y saldra del algoritmo
					c) si es mayor que ce: se acortara el tramo desde le principio hasta que el resultado sea menor o igual a c


	PASO 6: Expresión de cota y justificación de que el algoritmo siempre 
	        termina
			
			Exresion de cota es (n-i y !resul)
			Cuando n-i sea 0 quiere decir que no quedan elementos para analizar y terminara el algoritmo
			y cuando resul sea true, tambien terminara porque habremos cumplido el proposito de este


	PASO 7: Determinación justificada de la complejidad del algoritmo
		Coste: ini_fin + n*bucle
		Siendo ini_fin el coste de inicializacion y finalizacion del algoritmo y bucle el coste de las operaciones que hay en el bucle
		Esto hace que el coste sea O(n), siendo n la cantidad de elementos del vector


*/

bool /* resul */ hay_c_tramo(int a[], int n, int c){
	/* IMPLEMENTACION */
	bool resul = false;
	bool tramo = true;
	int i = 0;
	int suma = a[0];
	int prim = -1;
	while (i < n && !resul) {
		if (a[i] > c) {			//Si el elemento es mayor que c
			suma = 0;				//Reseteamos suma
			prim = -1;				//Reseteamos primera posicion del tramo
		}
		else if (a[i] == c) {	//Si el elemnto es igual a c
			resul = true;			//Indicamos que se cumple resul
		}
		else {					//Si el elemento es menor que c
			if (prim == -1) {		//Si no hay ningun tramo hecho
				prim = i;				//Indicamos el inicio del tramo
				suma = a[i];			//Empezamos la suma
			}
			else {						//Si ya hay un tramo 
				if (suma + a[i] == c) {		//Si la suma mas el elemento es igual a c
					suma += a[i];			//Sumamos el elemento
					resul = true;			//Indicamos que se cumple resul
				}
				else if (suma + a[i] < c) {	//Si la suma mas el elemento es menor que c
					suma += a[i];				//Sumamos el elemento
				}
				else {						//Si la suma mas el elemento es mayor que c
					
					while (prim < i && tramo) {				//Hasta que no queden elementos en el tramo o el tramo haya finalizado de arreglarse
						if (suma + a[i] - a[prim] > c) {		//Si la suma menos el primer elemento del tramo mas el elemento es mayor que c
							suma -= a[prim];						//Quetamos el primer elemento del tramo
						}
						else if (suma + a[i] - a[prim] == c) {	//Si la suma menos el primer elemento del tramo mas el elemento es igual a c
							resul = true;							//Indicamos que se cumple resul
							tramo = false;							//Indicamos que el tramo ya ha sido arreglado
						}
						else {									//Si la suma menos el primer elemento del tramo mas el elemento es menor que c
							suma -= a[prim];						//Quitamos el primer elemento del tramo
							tramo = false;							//Indicamos que el tramo ha sido arreglado
						}
						prim++;									//Actualizamos el inicio del tramo
					}
					suma += a[i];	//Sumamos el elemento
					tramo = true;	//Indicamos que el tramo esta arreglado
				}
			}
		}
		i++;	//Pasamos al siguiente elemento
	}
	return resul;
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
	  int c;
	  cin >> c;
	  if (hay_c_tramo(a,n,c)) {
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
