//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno Alejandro Barrachina Argudo
// Usuario del juez de clase A81
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Aqui explicacion de la función que resuelve el problema.
//
//  El algoritmo recorre todos los tiempos guardados en el vector para ver si se mejoran marcas o no.
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// El bucle se ejecuta tantas veces como elementos haya en el vector: O(n)
//
//*******************************

struct tSol
{
    int maxPruebasFallidas = -1;
    int ini = 0;
};

// Aqui la función implementada por el alumno para resolver el problema
auto resolver(std::vector<int> const &v)
{
    int best = v[0];
    int contFail = 0;

    tSol sol;

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] <= best)
        {
            ++contFail;
            if (sol.ini != i - contFail + 1)
            {
                sol.ini = i - contFail + 1;
            }
        }
        else
        {
            if (v[i] > best)
            {
                best = v[i];
                if (contFail > sol.maxPruebasFallidas)
                {
                    sol.maxPruebasFallidas = contFail;
                    sol.ini = i - sol.maxPruebasFallidas + 1;
                }
                contFail = 0;
            }
        }
    }
    if (sol.maxPruebasFallidas == -1)
    {
        sol.maxPruebasFallidas = contFail;
    }
    else if (sol.maxPruebasFallidas == 0)
    {
        sol.ini = v.size();
    }

    return sol;
}

// Resuelve cada caso de la entrada
bool resuelveCaso()
{
    int n;

    std::cin >> n;

    if (n == 0)
    {
        return false;
    }

    std::vector<int> marks(n);

    for (int &i : marks)
    {
        std::cin >> i;
    }

    tSol sol = resolver(marks);

    std::cout << sol.maxPruebasFallidas << " " << sol.ini << '\n';

    return true;
}

int main()
{
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
