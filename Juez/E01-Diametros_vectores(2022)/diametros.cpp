/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO:


Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/


#include <iostream>

using namespace std;


//n siempre ser� positivo (es decir, pod�is asumir n >= 1)
int diametro(int a[], int n) {
	 // A IMPLEMENTAR
	int menor = a[0];
	int mayor = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < menor) {
			menor = a[i];
		}
		if (a[i] > mayor) {
			mayor = a[i];
		}
	}
	return abs(menor - mayor);
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

const int TMAX = 1000000;  // No se podr�n leer vectores de m�s de un mill�n de elementos

bool ejecuta_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1 || n > TMAX) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << diametro(a, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}