/*
N� DE GRUPO: 09
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA: Alejandro Barrachina Argudo y Rodrigo Sosa Saez

EN CASO DE QUE ALGUNO DE LOS MIEMBROS DEL
GRUPO NO HAYA PARTICIPADO EN LA PRACTICA,
INDICARLO AQUI, EXPLICANDO TAMBI�N EL MOTIVO:



*/

// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una
// implementaci�n 'naif' del algoritmo
#include <iostream>

#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;

typedef unsigned long long t_num;

/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base
n <= 10: num_sing = n;


(2.2) Casos recursivos
n >= 10 : num_sing = (PARATODO x: x_1 != x_2, x_3 ... x_n)

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

la generalización se invoca tras inicializar la variable c que lleva la cuenta y la variable de control ok que nos dice si hay que sumar o no.

en cuanto finaliza la generalizacion, ya obtenemos en c el dato final buscado

*/

t_num digito_mas_significativo_n(t_num n)
{
	while (n > 9)
	{
		n = n / 10;
	}
	return n;
}

void es_singular_n(t_num n, t_num &c, bool &ok, t_num msd)
{
	if (n == 0)
	{
		c = 1;
		ok = false;
	}
	else if (n < 10)
	{
		c += max((t_num)0, (t_num)(n));
		ok = true;
	}
	else
	{

		es_singular_n(n / 10, c, ok, msd);
		c *= 9;
		if (n >= 100)
		{
			c += n / 10;
		}
		else
		{
			ok = ok && (n % 10 != msd);
			c += (ok ? max((t_num)0, (t_num)(n % 10)) : 1);
		}

		//ok = ok && (n % 10 != msd);
	}
}

t_num num_singulares_menoresque(t_num n)
{
	// Punto de entrada al algoritmo.
	// A implementar
	t_num num = 0;
	bool prueba1 = false;
	t_num msd = digito_mas_significativo_n(n);

	es_singular_n(n, num, prueba1, msd);
	return num;
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n
 si n <= 10, el algoritmo invierte un tiempo constante c_0
 si n > 10, el algoritmo invierte un tiempo constante c_1 en la división del numero, al que debe sumarse el tiempo que tarda en hacer la suma del numero final para n/10
 T(0) = C_0
 T(1) = C_1 + T(n/10), n > 10
(2) Resoluci�n utilizando los patrones vistos en clase
Utilizando el metodo de desplegado:
T(n) = c_1 + T(n/10) = C-1 + C-1 + T(n/100) = k*c_1 + T(n/10^k)
el proceso acaba cuando n =< 10, es decir n = 10^k, por lo tanto k = log_2 n
(3) Determinaci�n justificada de la complejidad del algoritmo final.
T(n) = log_10 n c_1 + c_1 + c_0
T(n) pertenece a O(log_n) con n potencia de 10
*/

#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n)
{
	while (n > 9)
	{
		n = n / 10;
	}
	return (unsigned short)n;
}
bool es_singular(t_num n)
{
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes)
	{
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n)
{
	t_num num = 0;
	for (t_num i = 0; i < n; i++)
	{
		if (es_singular(i))
		{
			num++;
		}
	}
	return num;
}
#endif

#ifdef DOM_JUDGE
bool ejecuta_caso()
{
	long long n;
	cin >> n;
	if (n == -1)
	{
		return false;
	}
	else
	{
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}
#endif

int main()
{

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++)
	{
		t_num n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n))
		{
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso())
		;
#endif
}
