/*
NOMBRE Y APELLIDOS: Rodrigo Sosa Saez y Laura Reyes Caballero

IMPORTANTE: Si no se añade el nombre y apellidos,
el ejercicio no se corregirá (puntuará como 0).

*/
#include <iostream>

using namespace std;


const int MAX_PROCESOS = 100; 

// Tipo para codificar los datos de entrada
// al problema
typedef struct {
	int t_procesamiento;  // Tiempo de procesamiento 'T' de los procesadores.
	                      // Cada procesador permite utizar, como máximo,
						  // 'T' unidades de tiempo.
	int t_procesos[MAX_PROCESOS];  // Unidades de tiempo requeridas por cada proceso. 
	int b_procesos[MAX_PROCESOS];  // Beneficio reportado por cada proceso.
	int n;                         // Número de procesos 'N' (n <= MAX_PROCESOS).
} tEntrada;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del diseño del algoritmo. No 
se tendrá en cuenta la codificación del algoritmo, a menos que
esté acompañada del diseño sistemático del mismo.
*/


/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos
	(entrada)			<tEntrada> entrada		-> datos del problema
	(entrada)			<int> pr_act			-> proceso a estudiar
	(entrada)			<int> t1_rest			-> tiempo del primer procesador
	(entrada)			<int> t2_resta			-> tiempo del segundo procesador 
	(entrada)			<int> benefecio_act		-> beneficio actual
	(entrada)			<int> max_beneficio		-> poda de posibles soluciones
	(entrada/salida)	<int> mejor_beneficio	-> mejor solucion posible del problema

(2) ¿Cómo son las soluciones parciales de este problema?
	Son implicitas(en el estado local de cada activacion)
	Se tratan de las asignaciones de procesos a procesadores

(3) ¿Cuándo una solución parcial es viable?
	Cuando se compara con la poda y dicha solucion es mejor

(4) ¿Cuándo una solución parcial es una solución final al problema?
	Cuando hemos investigado todos los procesos posibles

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?
	Se estudian estas 3 posibilidades:
		1) El proceso actual se pone en el procesador 1
		2) El proceso actual se pone en el procesador 2
		3) El proceso actual no se pone en ningun procesador

(6) Si estás utilizando algún criterio de poda adicional, explica detalladamente
    el criterio utilizado
	MARCADORES:
		t1_restante (como parametro de entrada)
		t2_restante (como parametro de entrada)
		benefecio_act (como parametro de entrada)
		max_beneficio (parametro de entrada, poda)
(7) Análisis de casos

(7.1) Caso(s) base
	Todos los procesos se han considerado
		Sabemos que hemos encontrado el mejor beneficio (por uso de poda)
		Actualizar

(7.2) Caso(s) recursivos
	Probamos a asignar el proceso actual en el procesador 1
	Probamos a asignar el proceso actual en el procesador 2
	No asignamos el proceso actual a ningun procesador

(8) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.
	Llamamos a la generalizacion con los parametros entrada, 0, entrada.t_procesamiento, entrada.t_procesamiento, 0, total, maximo.
	Cuando la generalizacion termina se ha modificado el parametro maximo,
	que sirve de solucion para el algoritmo principal
	


*/
void encuentra_maximo(const tEntrada& entrada, int pr_act, int t1_rest, int t2_rest, int beneficio_act, int total_beneficio, int& mejor_beneficio) {
	if (pr_act == entrada.n) {
		mejor_beneficio = beneficio_act;
	}
	else {
		if (entrada.t_procesos[pr_act] <= t1_rest && beneficio_act + total_beneficio > mejor_beneficio) {
			encuentra_maximo(entrada, pr_act + 1, t1_rest - entrada.t_procesos[pr_act], t2_rest, beneficio_act + entrada.b_procesos[pr_act], total_beneficio - entrada.b_procesos[pr_act], mejor_beneficio);
		}
		if (entrada.t_procesos[pr_act] <= t2_rest && beneficio_act + total_beneficio > mejor_beneficio) {
			encuentra_maximo(entrada, pr_act + 1, t1_rest, t2_rest - entrada.t_procesos[pr_act], beneficio_act + entrada.b_procesos[pr_act], total_beneficio - entrada.b_procesos[pr_act], mejor_beneficio);
		}
		if (beneficio_act + (total_beneficio - entrada.b_procesos[pr_act]) > mejor_beneficio) {
			encuentra_maximo(entrada, pr_act + 1, t1_rest, t2_rest, beneficio_act, total_beneficio - entrada.b_procesos[pr_act], mejor_beneficio);
		}
	}
}

int max_beneficio(const tEntrada& entrada) {
	// A IMPLEMENTAR: Debe devolver el beneficio máximo
	// que puede conseguirse
	int total = 0;
	for (int i = 0; i < entrada.n; i++) {
		total += entrada.b_procesos[i];
	}
	int maximo = 0;
	encuentra_maximo(entrada, 0, entrada.t_procesamiento, entrada.t_procesamiento, 0, total, maximo);
	return maximo;
}


/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el código que sigue no se corregirán (puntuarán 0).

bool ejecuta_caso() {
	int t_procesamiento;
	int n_procesos;
	cin >> t_procesamiento >> n_procesos;
	if (t_procesamiento == 0 && n_procesos == 0) {
		return false;
	}
	else {
		tEntrada entrada;
		entrada.n = n_procesos;
		entrada.t_procesamiento = t_procesamiento;
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.t_procesos[p];
		}
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.b_procesos[p];
		}
		cout << max_beneficio(entrada) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}



