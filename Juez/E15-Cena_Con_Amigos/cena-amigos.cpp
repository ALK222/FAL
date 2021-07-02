// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

// Explicación del algoritmo utilizado
/*
    El algoritmo recorre todos los elementos del vector y los va sumando.
    Si la suma es menor que el elemento actual, la suma se iguala al elemento actual y se reinicia el contador de secuencia.
    Si la suma actual es mayor que la suma maxima, se actualizan los valores de la solucion
*/

// Coste del algoritmo utilizado: O(n) siendo n el numero de elementos en el vector

struct tSol
{
    int sumaMaxSub = INT_MIN;
    int diaInicio = 0;
    int subSecSize = 0;
};

void resolver(std::vector<int> const &v, tSol &sol)
{
    int sumaActual = 0;
    int contSec = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        sumaActual += v[i];
        ++contSec;
        if (sumaActual <= v[i])
        {
            sumaActual = v[i];
            contSec = 1;
        }
        if (sumaActual > sol.sumaMaxSub)
        {
            sol.subSecSize = contSec;
            sol.diaInicio = i - sol.subSecSize + 1;
            sol.sumaMaxSub = sumaActual;
        }
    }
}

// Entrada y salida de datos
bool resuelveCaso()
{

    int n;

    std::cin >> n;

    if (!std::cin)
    {
        return false;
    }

    std::vector<int> gramos(n);

    for (int &i : gramos)
    {
        std::cin >> i;
    }

    tSol sol;
    resolver(gramos, sol);

    std::cout << sol.sumaMaxSub << ' ' << sol.diaInicio << ' ' << sol.subSecSize << '\n';

    return true;
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
