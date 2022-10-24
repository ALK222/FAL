
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
	0<n<=tam(a)
*/

int tramo_mas_corto(bool a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     tramo_true(a[],n) = ((#i : 0<i<n a[i]==1) Y (0: a[i] == 0))
	 resul = min i : tramo_true(a[],n) == k
	 
 */
 

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables
	resul -> int que guarda el tramo mas corto
	tramo_act -> int con el tramo que estamos contando actualmente
	cont -> int que indica los true que llevamos contando
	i -> int que sieve de indice para recorrer el array

Paso 2. Invariante
     tramo_act < resul 

Paso 3. Inicializaci�n
	resul = n;
	tramo_act = 0;
	cont = 0;
	i = 0;

Paso 4. Condici�n del bucle, y c�digo tras el bucle.
	Condicion ->	i < n
	Codigo tras el bucle ->	Comprueba el caso en el que k es superior a los true contados y
							el caso en el que solo piden un true
Paso 5. Cuerpo del bucle
	Aumentamos el tramo actual independientemente de si es true o false y
	en caso de que sea un true, aparte de aumentar el contador de true hay 2 posibles casos:

	1:	Si el contador es igual a k ->	estudiamos si el tramo estudiado es mas pequeño y
										de forma independiente reseteamos los contadores del tramo y true para seguir estudiando posibilidades

	2:	Si el contador es 1 y k es diferente a 1 -> reseteamos el contador del tramo

	Independientemente de estas posibilidades seguimos iterando

Paso 6. Justificaci�n de que el algoritmo siempre termina.
 		En cada iteracion incrementa i hasta que toma el valor n-1
		siendo este la expresion de cota
 
Paso 7. Complejidad:
	MEJOR CASO: Orden Constante O(1)
		n=0;
		T = Tini_y_fin

	PEOR CASO: Orden Lineal O(n)
		n>0;
		T = Tini_y_fin + (n * Tbucle)
			Lim(n tiende a infinito) Tini_y_fin + (n * Tbucle) = Tbucle
 
*/
 


int tramo_mas_corto(bool a[], int n, int k) {
   // A IMPLEMENTAR
	int resul = n;		//Tramo mas corto
	int tramo_act = 0;	//Tramo que estamos contando
	int cont = 0;		//Numero de true que llevamos contando
	int i = 0;
	while (i < n) {
		tramo_act++;
		if (a[i] == 1) {
			cont++;
			if (cont == k) {
				if (tramo_act < resul) {
					resul = tramo_act;
				}
				cont = 1;
				tramo_act = 1;
			}
			else if (cont == 1 && k != 1) {
				tramo_act = 1;
			}			
		}
		i++;
	}
	if (tramo_act == resul && cont < k) {
		resul = n + 1;
	}
	if (k == 1 && cont > 0) {
		resul = 1;
	}
	return resul;
}	

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR */

   
void lee_caso(int& n, bool a[], int& k) {
	cin >> n;
	if (n != -1) {
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			a[i] = bool(elem);
		}
		cin >> k;
	}
}

const int MAX_TAM = 100;
int main() {
	int n;
	bool a[MAX_TAM];
	int k;
	do {
		lee_caso(n, a, k);
		if (n != -1) {
			cout << tramo_mas_corto(a, n, k) << endl;
		}
	} while (n != -1);
}
	
	