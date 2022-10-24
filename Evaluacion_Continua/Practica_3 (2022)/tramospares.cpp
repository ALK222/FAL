/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:


Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/


#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.
	0<n<tam(v)

*/


int /* resul */ long_tramo_par_mas_largo(int v[], unsigned int n);

	/*
	   POSTCONDICION DE LA FUNCION:
	   ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
	   ---al valor devuelto por la funci�n, utiliza la pseudo-variable
	   ---'resul'
	(1) Definiciones auxiliares (si procede):
		tramo_pares(v[],n) = ((#i : a[i]%2 == 0) Y (0: a[i]%2!=0))

	(2) Postcondici�n
		resul = MAX tramo_pares(v[],n);


    */



	/* DISE�O DEL ALGORITMO:
	--- Detalla aqu� el proceso seguido para dise�ar el
	--- algoritmo

	PASO 1. Variables adicionales (aparte de los par�metros y el resultado)
		tramo_act -> inr que guarda la longitud del tramo actual
	PASO 2. Invariante
	   (2.1) Definiciones auxiliares (si procede)
		a[i]%2==0
	   
	   
	   (2.2) Invariante
		tramo_act>resul

	PASO 3. C�digo de inicializaci�n, justificando que, tras
	        dicho c�digo, se cumple el invariante
			i = 0 -> indice que recorre el array
			resul = 0 -> indica la longitud del tramo mas largo
			tramo_act = 0 -> indica la longitud del tramo actual
	
	PASO 4. Condici�n del bucle, c�digo tras el bucle (si procede),
	        y justificaci�n de que, una vez finalizado el algoritmo,
			se cumple la postcondici�n

			condicion ->	i < n

			codigo despues del bucle ->	comprueba que el tramo actual es mas largo que los anteriores

    PASO 5. Dise�o del cuerpo del bucle, justificando que dicho c�digo
	        preserva el invariante

			Hay 2 casos pobiles, tras los que se sigu iterando:

			1: a[i] es par ->	aumentamos el tramo actual

			2: a[i] no es par ->	comprobamos si el tramo era el mas largo y
									resteamos el tramo actual a 0

	PASO 6: Expresi�n de cota y justificaci�n de que el algoritmo siempre 
	        termina
			Como por cada iteracion incrementamos el indice del array,
			tomamos como cota n-1 para que termine de estudiar el array

	PASO 7: Determinaci�n justificada de la complejidad del algoritmo
			Orden Lineal O(n)
			Tm = Tini_y_fin + (n*Tbucle)
				Lim(n tiende a infinito) Tini_y_fin + (n*Tbucle) = Tbucle

	*/


int /* resul */ long_tramo_par_mas_largo(int v[], int n) {
	/* IMPLEMENTACION */
	int i = 0;
	int tramo_act = 0;
	int resul = 0;
	while (i < n) {
		if (v[i] % 2 == 0) {
			tramo_act++;
		}
		else {
			if (tramo_act > resul) {
				resul = tramo_act;
			}
			tramo_act = 0;
		}
		i++;
	}
	return resul;
}	



/* PROGRAMA DE PRUEBA: No modificar */

const int MAX_ELEMS = 1000000;
 
bool ejecuta_caso() {
	int n;
	cin >> n;
	static int v[MAX_ELEMS];
	if (n == -1) return false;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << long_tramo_par_mas_largo(v, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}