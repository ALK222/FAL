// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Coste T(n) = { Co si ini+1=fin, T(n/2) + C1 en el resto de casos) Complejidad O(nlog(n))
char resolver(std::vector<char> const &inmates, int const &begin, int const &end)
{
    if (begin + 1 == end)
    {
        return inmates[begin] + 1;
    }
    else
    {
        int middle = (end + begin) / 2;

        if ((inmates[begin] - begin) != (inmates[middle] - middle))
        {
            return resolver(inmates, begin, middle);
        }
        else
        {
            return resolver(inmates, middle, end);
        }
    }
}

void resuelveCaso()
{
    char first;
    char last;

    std::cin >> first >> last;

    std::vector<char> inmates(last - first);

    for (char &a : inmates)
    {
        std::cin >> a;
    }

    if (inmates[0] != first)
    {
        std::cout << first << '\n';
    }
    else if (inmates[inmates.size() - 1] != last)
    {
        std::cout << last << '\n';
    }
    else
    {
        std::cout << resolver(inmates, 0, inmates.size() - 1) << '\n';
    }
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
