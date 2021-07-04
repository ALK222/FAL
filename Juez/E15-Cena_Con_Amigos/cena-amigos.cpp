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
    int sumaMaxSub = 0;
    int diaInicio = 0;
    int subSecSize = 0;
};

tSol resolver(std::vector<int> const &v)
{
    tSol sol;
    int sumaActual = 0;
    int contSec = 0;
    int ini = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        sumaActual += v[i];
        if (sumaActual > 0)
        {
            if (contSec == 0)
            {
                ini = i;
            }

            contSec++;

            if (sumaActual > sol.sumaMaxSub)
            {
                sol.sumaMaxSub = sumaActual;
                sol.subSecSize = contSec;
                sol.diaInicio = ini;
            }
        }
        else if (sumaActual > sol.sumaMaxSub)
        {
            sol.sumaMaxSub = sumaActual;
            sol.subSecSize = contSec;
            sol.diaInicio = ini;
        }
        else
        {
            contSec = 0;
            sumaActual = 0;
        }
        if (sol.sumaMaxSub == sumaActual && sol.subSecSize > contSec)
        {
            sol.subSecSize = contSec;
            sol.diaInicio = ini;
        }
    }

    return sol;
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

    tSol sol = resolver(gramos);

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
