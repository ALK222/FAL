/*
NOMBRE Y APELLIDOS: Alejandro Barrachina Argudo

IMPORTANTE: Si no se añade el nombre y apellidos,
el ejercicio no se corregirá (puntuará como 0).

*/
#include <iostream>

using namespace std;

const int MAX_PROCESOS = 100;

// Tipo para codificar los datos de entrada
// al problema
typedef struct
{
	int t_procesamiento; // Tiempo de procesamiento 'T' de los procesadores.
	// Cada procesador permite utizar, como máximo,
	// 'T' unidades de tiempo.
	int t_procesos[MAX_PROCESOS]; // Unidades de tiempo requeridas por cada proceso.
	int b_procesos[MAX_PROCESOS]; // Beneficio reportado por cada proceso.
	int n;						  // Número de procesos 'N' (n <= MAX_PROCESOS).
} tEntrada;

typedef struct
{
	int tiempoUsado;
	int beneficioConseguido;
} tProcesador;
/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del diseño del algoritmo. No
se tendrá en cuenta la codificación del algoritmo, a menos que
esté acompañada del diseño sistemático del mismo.
*/

/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos
	- p1           <tPRocesador>: primer procesador del problema, lleva la cuenta de la satisfaccion y tiempo usado del procesador
	- p2           <tPRocesador>: segundo procesador del problema, lleva la cuenta de la satisfaccion y tiempo usado del procesador
	- maxBeneficio <int>:         maximo beneficio conseguido en total
	- entrada      <tEntrada>:    datos de procesos, satisfacción, etc
	- nivel        <int>:         numero del proceso a comprobar

(2) ¿Cómo son las soluciones parciales de este problema?

	Las soluciones parciales del problema son los datos almacenados en cada procesador.

(3) ¿Cuándo una solución parcial es viable?
	En este caso solo se exploran soluciones viables, ya que nunca hacemos que ningun procesador se pase de tiempo de procesamiento

(4) ¿Cuándo una solución parcial es una solución final al problema?
	Cuando se han comprobado todos los procesos, es decir, nivel == entrada.n. Entonces se comprobará si es la solución óptima.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?
	Se comprueba el siguiente proceso para ambos procesadores.

(6) Si estás utilizando algún criterio de poda adicional, explica detalladamente
	el criterio utilizado
		Comprobamos si el tiempo del proceso a analizar no es mayor que el tiempo de procesamiento total de ambos procesadores

(7) Análisis de casos

(7.1) Caso(s) base
	nivel = entrada.n => se comprueba si la suma de ambos procesadores en cuanto a satisfacción es la máxima conseguida.

(7.2) Caso(s) recursivos
	1.- Comprobamos que el proceso es viable:
		Si es viable:
		1.1.- Procesador 1:
			- Comprobamos si el procesador tiene tiempo suficiente para el proceso:
				-Si lo tiene:
					- Se suma el tiempo y la satisfacción
					- Se llama a la función para analizar el siguiente proceso
					- Se resta el tiempo y la satisfacción
				- Si no lo tiene no se hace nada
		1.2.- Procesador 2:
			- Comprobamos si el procesador tiene tiempo suficiente para el proceso:
				-Si lo tiene:
					- Se suma el tiempo y la satisfacción
					- Se llama a la función para analizar el siguiente proceso
					- Se resta el tiempo y la satisfacción
				- Si no lo tiene no se hace nada
		Si no lo es, no se hace nada
	2.- Pasamos al siguiente proceso: pase lo que pase en el paso anterior, analizamos el siguiente nivel para comprobar su viabilidad


(8) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.

	La generalización ya genera la solución final


*/

void max_beneficioAux(tProcesador p1, tProcesador p2, int &maxBeneficio, tEntrada entrada, int nivel)
{
	if (nivel == entrada.n)
	{
		if (p1.beneficioConseguido + p2.beneficioConseguido > maxBeneficio)
		{
			maxBeneficio = p1.beneficioConseguido + p2.beneficioConseguido;
		}
	}
	else
	{
		if (entrada.t_procesos[nivel] <= entrada.t_procesamiento)
		{
			if (p1.tiempoUsado + entrada.t_procesos[nivel] <= entrada.t_procesamiento)
			{
				p1.tiempoUsado += entrada.t_procesos[nivel];
				p1.beneficioConseguido += entrada.b_procesos[nivel];
				max_beneficioAux(p1, p2, maxBeneficio, entrada, nivel + 1);
				p1.tiempoUsado -= entrada.t_procesos[nivel];
				p1.beneficioConseguido -= entrada.b_procesos[nivel];
			}

			if (p2.tiempoUsado + entrada.t_procesos[nivel] <= entrada.t_procesamiento)
			{
				p2.tiempoUsado += entrada.t_procesos[nivel];
				p2.beneficioConseguido += entrada.b_procesos[nivel];
				max_beneficioAux(p1, p2, maxBeneficio, entrada, nivel + 1);
				p2.tiempoUsado -= entrada.t_procesos[nivel];
				p2.beneficioConseguido -= entrada.b_procesos[nivel];
			}
		}

		max_beneficioAux(p1, p2, maxBeneficio, entrada, nivel + 1);
	}
}

int max_beneficio(const tEntrada &entrada)
{
	// A IMPLEMENTAR: Debe devolver el beneficio máximo
	// que puede conseguirse
	tProcesador p1;
	tProcesador p2;
	p1.tiempoUsado = 0;
	p1.beneficioConseguido = 0;
	p2.tiempoUsado = 0;
	p2.beneficioConseguido = 0;
	int maxBeneficio;

	max_beneficioAux(p1, p2, maxBeneficio, entrada, 0);

	return maxBeneficio;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el código que sigue no se corregirán (puntuarán 0).

bool ejecuta_caso()
{
	int t_procesamiento;
	int n_procesos;
	cin >> t_procesamiento >> n_procesos;
	if (t_procesamiento == 0 && n_procesos == 0)
	{
		return false;
	}
	else
	{
		tEntrada entrada;
		entrada.n = n_procesos;
		entrada.t_procesamiento = t_procesamiento;
		for (int p = 0; p < n_procesos; p++)
		{
			cin >> entrada.t_procesos[p];
		}
		for (int p = 0; p < n_procesos; p++)
		{
			cin >> entrada.b_procesos[p];
		}
		cout << max_beneficio(entrada) << endl;
		return true;
	}
}

int main()
{
	while (ejecuta_caso())
		;
	return 0;
}
