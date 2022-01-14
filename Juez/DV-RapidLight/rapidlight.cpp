/*
NOMBRE Y APELLIDOS: Alejandro Barrachina Argudo


*/

#include <iostream>

using namespace std;

/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.


(2) Análisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinación de las ecuaciones de recurrencia para la generalización

(4.2) Resolución utilizando los patrones vistos en clase

(4.3) Determinación justificada de la complejidad del algoritmo final.



*/

bool llega(int etapas[], int n, int max_paradas, int capacidad)
{
	int i = 0;
	int paradas = 0;
	int suma = 0;

	bool capReached = false;

	while (i < n && !capReached && paradas <= max_paradas)
	{

		suma += etapas[i];
		capReached = capacidad < etapas[i];
		if (suma > capacidad)
		{
			suma = etapas[i];
			paradas++;
		}
		++i;
	}
	return !capReached && paradas <= max_paradas;
}

void acota(int etapas[], int n, int max_paradas, int &inf, int &sup)
{
	inf = 0;
	sup = 2;
	while (!llega(etapas, n, max_paradas, sup))
	{
		inf = sup;
		sup *= 2;
	}
}

int calcula_capacidad(int etapas[], int n, int max_paradas, int inf, int sup)
{
	int mid = (inf + sup) / 2;
	if (llega(etapas, n, max_paradas, mid))
	{
		if (!llega(etapas, n, max_paradas, mid - 1))
		{
			return mid;
		}
		else
		{
			return calcula_capacidad(etapas, n, max_paradas, inf, mid - 1);
		}
	}
	else
	{
		return calcula_capacidad(etapas, n, max_paradas, mid + 1, inf);
	}
}

int min_capacidad(int etapas[], int n, int repostajes_permitidos)
{
	// A IMPLEMENTAR
	int inf = 0;
	int sup = 0;
	acota(etapas, n, repostajes_permitidos, inf, sup);
	return calcula_capacidad(etapas, n, repostajes_permitidos, inf, sup);
}

int v[100000];
int n, c;

int main()
{

	while (cin >> n, n != -1)
	{
		cin >> c;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		cout << min_capacidad(v, n, c) << '\n';
	}

	return 0;
}
