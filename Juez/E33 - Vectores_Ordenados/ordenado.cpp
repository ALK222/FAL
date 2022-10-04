#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



bool esta_ordenado(int a[], int n) {
	// A IMPLEMENTAR
	bool resul = true;
	int i = 1;
	while (i < n && resul) {
		if (a[i - 1] <= a[i]) {
			resul = true;
		}
		else {
			resul = false;
		}
		i++;
	}
	return resul;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA - NO MODIFICAR */

const int TMAX = 1000000;  // No se podrán leer vectores de más de un millón de elementos

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
		if (esta_ordenado(a, n)) cout << "SI" << endl;
		else cout << "NO" << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}