#include <iostream>

// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una
// implementaci�n 'naif' del algoritmo
#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/
typedef long long tnum;

void resolver(tnum n, unsigned short d, tnum &res, bool &hay_menores, int &d_ant)
{
    if (n < 10)
    {
        res = (n > d && d != 0) ? d : n;
        hay_menores = true;
        d_ant = n;
    }
    else
    {

        resolver((n / 10), d, res, hay_menores, d_ant);
        tnum last = n % 10;
        res *= 9;
        // res++;
        if (hay_menores)
        {
            res += (d_ant > d) ? d_ant - 1 : d;

            if (last < d)
            {
                hay_menores = false;
            }
        }

        // hay_menores = hay_menores && (d_ant < d);
        d_ant = last;
    }
}

tnum num_sin_digito_menoresque(tnum n, unsigned short d)
{
    // PUNTO DE ENTRADA AL ALGORITMO
    tnum res;
    bool hay_menores;
    int d_ant;
    resolver(n, d, res, hay_menores, d_ant);
    return res;
}

#ifndef DOM_JUDGE
bool contiene_digito(tnum n, unsigned short d)
{
    if (n == 0)
    {
        return d == 0;
    }
    else
    {
        bool lo_contiene = false;
        while (n > 0 && !lo_contiene)
        {
            lo_contiene = (n % 10 == d);
            n = n / 10;
        }
        return lo_contiene;
    }
}

tnum num_sin_digito_menoresque_naif(tnum n, unsigned short d)
{
    tnum num = 0;
    for (tnum i = 0; i < n; i++)
    {
        if (!contiene_digito(i, d))
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
    tnum n;
    cin >> n;
    if (n == -1)
    {
        return false;
    }
    else
    {
        unsigned short d;
        cin >> d;
        cout << num_sin_digito_menoresque(n, d) << endl;
        return true;
    }
}
#endif

int main()
{

#ifndef DOM_JUDGE
    bool ok = true;
    srand(time(NULL));
    int i = 0;
    while (i < 1000 && ok)
    {
        tnum n = (tnum)rand();
        unsigned short d = (unsigned short)(rand() % 10);
        if (num_sin_digito_menoresque_naif(n, d) != num_sin_digito_menoresque(n, d))
        {
            cout << "NO FUNCIONA" << endl;
            cout << n << " " << d << ":" << num_sin_digito_menoresque_naif(n, d) << "..." << num_sin_digito_menoresque(n, d) << endl;
            ok = false;
        }
        i++;
    }
    if (ok)
        cout << "OK" << endl;
    system("pause");
#endif

#ifdef DOM_JUDGE
    while (ejecuta_caso())
        ;
#endif
}
