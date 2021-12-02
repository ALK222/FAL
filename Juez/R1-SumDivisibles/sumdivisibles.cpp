// ALEJANDRO BARRACHINA ARGUDO
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

bool sumdivisible(int n)
{
    /* IMPLEMENTACION:
	   Esta función será el punto de entrada a tu algoritmo.
	   Puedes implementar, además, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El número cuya sumdivisibilidad debes determinar.
	   -- La función deberá devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/
    if (n < 10)
    {
        return true;
    }
    int suma = 0;
    int cont = 0;
    int aux = n;

    while (aux > 0)
    {
        suma += (aux % 10);
        aux /= 10;
        ++cont;
    }
    if (suma % cont == 0)
    {
        return sumdivisible(n / 10);
    }
    else
    {
        return false;
    }
}

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR */

int main()
{
    int n;
    do
    {
        cin >> n;
        if (n > 0)
        {
            if (sumdivisible(n))
                cout << "SI" << endl;
            else
                cout << "NO" << endl;
        }
    } while (n > 0);
}
