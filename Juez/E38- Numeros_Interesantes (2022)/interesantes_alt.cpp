
#include <iostream>
using namespace std;

/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos
	GENERALIZACION:
		(entrada)	n			<int>	->	segmento inicial del numero
		(entrada)	menos_sig	<int>	->	suna de los gigitos menos significativos
		(salida)	mas_sig		<int>	->	suma de los digitos mas significativos
		(salida)	lo_es		<bool>	->	indica si el numero es interesante

	Caso Base: (n<=9)
		mas_sig = n
		si n!=0 && smenos % n ==0 -> lo_es=true
	
	Caso Base:  (n>9) && (((n % 10 == 0) || (menos_sig % (n%10) == 0)) -> lo_es = false
	
	Caso Recursivo : (n>9) && ((n % 10 != 0) || (menos_sig % (n%10) == 0))
		Supongamos resuelto el problema para n/10, siendo la suma de digitos menos significativos menos_sig + n % 10:
			lo_es_aux -> true si n/10 es interesnate, false si no lo es
			En caso de que lo_es_aux == true, es mas_sig esta la suma de todos los digitos n/10
			lo_es = true si lo_es_aux == true y (mas_sig % (n % 10) == 0)
			En caso de que lo_es == true, mas_sig+=n%10;
	INMERSION:
		Se invoca al a generalizacion con n, 0, mas_sig y lo_es
		El resultado es lo_es


ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.
	T(n) = c0, n <= 9
	T(n) = c1 + T(n/10), n > 9
		k=0, a=1, b=10
	Como a=b^k -> O(n^0 *log n) -> O(log n)

*/

void resuelve(unsigned int n, unsigned int menos_sig, unsigned int& mas_sig, bool& lo_es ) {
	if(n<=9) {
		mas_sig = n;
		lo_es = (n != 0) && (menos_sig % n == 0);
	}
	else{
		unsigned int ultimo = n%10;
		if(ultimo == 0 || (menos_sig % ultimo != 0)) {
			lo_es = false;
		}
		else{
			unsigned int mas_sig_aux;
			bool lo_es_aux;
			resuelve (n/10, menos_sig + n%10, mas_sig_aux, lo_es_aux);
			if(!lo_es_aux || mas_sig_aux % ultimo != 0) {
				lo_es = false;
			}
			else{
				lo_es = true;
				mas_sig = mas_sig_aux + n%10;
			}
		}
	}
}

bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
	unsigned int mas_sig;
	bool lo_es;
	resuelve(n, 0, mas_sig, lo_es);
	return lo_es;
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
