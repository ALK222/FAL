// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

/*
    Precondicion:  {0 <= a1.size < 10^9 && 0 <= a2.size < 10^9}
    Invariante:    {paraTodo i,j : 0 <= i < a1.size, 0 <= a2.size: Existe k: 0 <= k <= i,j : v[k]: a1[i] = a2[j]}
    Postcondicion: { paraTodo k: existe i,j: k 0 <= k <= i,j : v[k]: a1[i] = a2[j]}
*/

std::vector<int> resolver(std::vector<int> const &a1, std::vector<int> const &a2)
{
    int i = 0;
    int j = 0;

    std::vector<int> sol;

    while (i < a1.size() && j < a2.size())
    {
        if (a1[i] < a2[j])
        {
            ++i;
        }
        else if (a1[i] > a2[j])
        {
            ++j;
        }
        else
        {
            sol.push_back(a1[i]);
            ++i;
            ++j;
        }
    }

    return sol;
}

void resuelveCaso()
{
    int elemento;
    std::vector<int> a1;
    std::vector<int> a2;

    std::cin >> elemento;

    while (elemento != 0)
    {
        a1.push_back(elemento);
        std::cin >> elemento;
    }

    std::cin >> elemento;

    while (elemento != 0)
    {
        a2.push_back(elemento);
        std::cin >> elemento;
    }

    std::sort(a1.begin(), a1.end());
    std::sort(a2.begin(), a2.end());

    std::vector<int> sol = resolver(a1, a2);

    for (int i = 0; i < sol.size(); ++i)
    {
        std::cout << sol[i] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
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
