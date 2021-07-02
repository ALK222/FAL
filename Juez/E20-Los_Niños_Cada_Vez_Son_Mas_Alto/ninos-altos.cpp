// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

//*******************************
// Aqui especificación de la función que resuelve el problema.
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
//
//
//
//*******************************

// Aqui la función implementada por el alumno
int resolver(std::vector<int> const &v, int const &intervalo)
{
    int maxLong = 0;

    int acumulados = 0;

    int pos = 0;

    for (int i = 0; i < intervalo; ++i)
    {
        acumulados += v[i];
        maxLong = acumulados;
    }

    int k = 0;

    for (int i = intervalo; i < v.size(); ++i)
    {
        acumulados -= v[k];

        acumulados += v[i];

        maxLong = acumulados > maxLong ? acumulados : maxLong;

        ++k;
    }

    return maxLong;
}

std::vector<int> acumular(std::vector<int> const &v, int const &numMedidas)
{

    std::vector<int> sol(numMedidas, 0);
    for (int i = 0; i < v.size(); ++i)
    {
        sol[v[i] - 1]++;
    }

    return sol;
}

bool resuelveCaso()
{
    int numMedidas, medidaMax, longIntervalo;
    std::cin >> numMedidas >> medidaMax >> longIntervalo;
    if (numMedidas == -1)
        return false;
    std::vector<int> v(numMedidas);
    for (int &i : v)
        std::cin >> i;
    // LLamada a la funcion que resuelve el problema

    auto acum = acumular(v, medidaMax);

    auto sol = resolver(acum, longIntervalo);

    // Escribir el resultado

    std::cout << sol << '\n';

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
