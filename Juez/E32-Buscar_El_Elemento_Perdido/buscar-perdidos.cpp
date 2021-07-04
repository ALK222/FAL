// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Coste T(n) = { Co si ini+1=fin, T(n/2) + C1 en el resto de casos) Complejidad O(nlog(n))
int resolver(std::vector<int> const &completo, std::vector<int> const &perdidos, int const &begin, int const &end)
{
    if (begin + 1 == end)
    {
        return completo[begin] == perdidos[begin] ? completo[end] : perdidos[begin];
    }
    else
    {
        int middle = (begin + end) / 2;

        if (completo[middle] == perdidos[middle])
        {
            return resolver(completo, perdidos, middle, end);
        }
        else
        {
            return resolver(completo, perdidos, begin, middle);
        }
    }
}

void resuelveCaso()
{
    int numElementos;

    std::cin >> numElementos;

    std::vector<int> vectorCompleto(numElementos);

    for (int &i : vectorCompleto)
    {
        std::cin >> i;
    }

    std::vector<int> vectorPerdido(numElementos - 1);

    for (int &i : vectorPerdido)
    {
        std::cin >> i;
    }

    if (vectorCompleto.size() == 1 || vectorCompleto[0] != vectorPerdido[0])
    {
        std::cout << vectorCompleto[0] << '\n';
    }
    else if (vectorCompleto[numElementos - 1] != vectorPerdido[vectorPerdido.size() - 1])
    {
        std::cout << vectorCompleto[numElementos - 1] << '\n';
    }
    else
    {
        std::cout << resolver(vectorCompleto, vectorPerdido, 0, vectorPerdido.size() - 1) << '\n';
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
