// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

int resolver(std::vector<int> const &v)
{
    int maxRep = 0;
    int repAct = 0;
    int aux = v[0];
    int max = v[0];

    for (int i : v)
    {
        if (i == aux)
        {
            ++repAct;

            if (maxRep < repAct)
            {
                maxRep = repAct;
                max = i;
            }
        }
        else
        {
            repAct = 1;
        }
    }
    return max;
}

// Entrada y salida de datos
bool resuelveCaso()
{

    int n;

    std::cin >> n;

    if (n == -1)
    {
        return false;
    }

    std::vector<int> road(n);

    for (int &i : road)
    {
        std::cin >> i;
    }

    std::sort(road.begin(), road.end());

    int sol = resolver(road);

    std::cout << sol << '\n';

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
