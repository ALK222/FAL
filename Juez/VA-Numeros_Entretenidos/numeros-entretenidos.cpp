/* NOMBRE Y APELLIDOS:
    Alejandro Barrachina Argudo
*/

#include <iostream>

using namespace std;

typedef unsigned long long t_num;

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

void resolver(t_num &d, unsigned short n, unsigned int k, int nivel, int &res, int sumDigs)
{
    for (int i = 0; i < 10; i++)
    {
        if (d % 10 != i) // si los digitos son distintos entonces se suma en sumDigs
        {
            sumDigs += i;
            if (sumDigs <= k) // se comprueba que la suma no exceda al maximo
            {
                d = d * 10 + i;
                if (nivel + 1 == n) // nivel es el numero de digitos - 1 que tiene el numero actualmente
                {
                    res++;
                }
                else
                {
                    resolver(d, n, k, nivel + 1, res, sumDigs);
                }
                d = d / 10; // volvemos a tener el digito mas alto
            }
            sumDigs -= i; // la suma de dijitos se queda a d
        }
    }
}

/// <summary>
///
/// </summary>
/// <param name="d">digito de comienzo</param>
/// <param name="n">numero de digitos</param>
/// <param name="k">Valor máximo de la suma</param>
/// <returns></returns>
t_num cuenta_entretenidos(unsigned short d, unsigned short n, unsigned int k)
{
    // PUNTO DE ENTRADA AL ALGORITMO
    int res = 0;
    t_num d1 = d;

    resolver(d1, n, k, 1, res, d);

    return res;
}

bool ejecuta_caso()
{
    int n;
    cin >> n;
    if (n == -1)
    {
        return false;
    }
    else
    {
        unsigned short d;
        unsigned int k;
        cin >> d >> k;
        cout << cuenta_entretenidos((unsigned short)d, n, k) << endl;
        return true;
    }
}

int main()
{
    while (ejecuta_caso())
        ;
}
