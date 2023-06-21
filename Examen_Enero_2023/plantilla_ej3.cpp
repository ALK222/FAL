/*
NOMBRE Y APELLIDOS:

*/


#include <iostream>

using namespace std;

static const int MAX_MONEDAS = 100;

/* Tipo para representar los datos de entrada */
typedef struct {
  int num_monedas;     /* N�mero de monedas a repartir */
  int min_monedas;     /* M�nimo de monedas que debe recibir cada pirata -los dos deben
                          recibir este m�nimo n�mero de monedas */
  int valor_monedas[MAX_MONEDAS];  /* Valor de las distintas monedas a repartir */
} tEntrada;


/*
(1) �C�mo son las soluciones parciales viables de este problema?

(2) �Cu�ndo una soluci�n es final?

(3) Dada una soluci�n viable, �c�mo se generan nuevas soluciones viables a partir de ella?

(4) �C�mo se representar�n las soluciones en este problema? Describe los distintos elementos
    de informaci�n que las componen, indicando si se representan como par�metros de entrada,
	de entrada/salida (estado global), si se representan impl�citamente...

(5) �Qu� marcadores utiliza el algoritmo? Describe claramente su prop�sito, los elementos
    de informaci�n que los componen, as� como si dichos elementos se representan como par�metros
	de entrada, de entrada/salida (estado global)... 

(6) Si el algoritmo utiliza generalizaci�n, indica como es la misma, describiendo claramente
    el prop�sito de cada par�metro.
	
(7) An�lisis de casos: casos base, casos recursivos

(8) Si el algoritmo utiliza una generalizaci�n, describe c�mo se implementa el algoritmo
    en t�rminos de la misma (inmersi�n)

*/

 
  /* - En min_dif debe devolverse la m�nima diferencia que puede conseguirse.
     - En num_formas debe devolverse el n�mero de soluciones que presentan dicha diferencia m�nima.
   */	 
 void reparte(const tEntrada& entrada, int& min_dif, int& num_formas) {
	 // A IMPLEMENTAR
 }

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/

 bool ejecuta_caso() {
	 int num_monedas;
	 cin >> num_monedas;
	 if (num_monedas == -1) return false;
	 else {
		 tEntrada entrada;
		 entrada.num_monedas = num_monedas;
		 cin >> entrada.min_monedas;
		 for (int m = 0; m < num_monedas; m++) {
			 cin >> entrada.valor_monedas[m];
		 }
		 int min_dif;
		 int num_formas;
		 reparte(entrada, min_dif, num_formas);
		 cout << min_dif << " " << num_formas << endl;
		 return true;
	 }
 }

 int main() {
	 while (ejecuta_caso());
	 return 0;
 }