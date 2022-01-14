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

typedef unsigned long long t_num;

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

void cuenta_singulares_menoresque(t_num n, t_num &c, bool &es_singular, int &d_mas_sig)
{
    if (n <= 9)
    {
        c = n;
        es_singular = true;
        d_mas_sig = n;
    }
    else
    {
        cuenta_singulares_menoresque(n / 10, c, es_singular, d_mas_sig);
        c *= 9;
        c++;
        if (es_singular)
        {
            c += (n % 10 <= d_mas_sig ? (n % 10) : (n % 10 - 1));
        }
        es_singular = es_singular && (n % 10 != d_mas_sig);
    }
}

t_num num_singulares_menoresque(t_num n)
{
    // Punto de entrada al algoritmo.
    // A implementar

    t_num c;
    bool es_singular;
    int d_mas_sig;
    cuenta_singulares_menoresque(n, c, es_singular, d_mas_sig);
    return c;
}

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
