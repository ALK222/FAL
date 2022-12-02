
#include <iostream>
using namespace std;

/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/

int resuelve(int num, int sumaDer, bool& esInteresante) {
	if (esInteresante && num != 0) {
		if (num < 10 && sumaDer % num == 0) {
			return num;
		}
		else {
			int aux = num % 10;
			if (aux != 0) {
				if (sumaDer % aux != 0) {
					esInteresante = false;
					return aux;
				}
				else {
					sumaDer += aux;
					int sumaIzq = resuelve(num / 10, sumaDer, esInteresante);
					if (sumaIzq % aux != 0) {
						esInteresante = false;
						return aux;
					}
					else {
						return sumaIzq + aux;
					}
				}
			}
			else {
				esInteresante = false;
				return 0;
			
			}
		}
	}
	if (num == 0) {
		esInteresante = false;
	}
	return 0;
}

bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
	bool esInteresante = true;
	int sumaDer = 0;
	resuelve(n, sumaDer, esInteresante);
	return esInteresante;
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
    }
}
