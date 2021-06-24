// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

// Explicación del algoritmo utilizado
/*
    Para cada elemento miramos si el numero de ventas marca un maximo historico. Si es asi, metemos el año en el vector final

*/

// Coste del algoritmo utilizado: coste lineal O(n), siendo n el numero de elementos en el vector de ventas

std::vector<int> resolver(int const &firstYear, std::vector<int> const &sales)
{

    std::vector<int> sol;

    int lastMax = sales[0];

    for (int i = 1; i < sales.size(); ++i)
    {
        lastMax = std::max(lastMax, sales[i - 1]);
        if (lastMax < sales[i])
        {
            sol.push_back(firstYear + i);
        }
    }

    return sol;
}

void resuelveCaso()
{
    int y1;
    int y2;

    std::cin >> y1 >> y2;

    std::vector<int> sales;

    int aux;

    for (int i = 0; i <= y2 - y1; ++i)
    {
        std::cin >> aux;

        sales.push_back(aux);
    }

    std::vector<int> sol = resolver(y1, sales);

    for (size_t i = 0; i < sol.size(); ++i)
    {
        std::cout << sol[i] << " ";
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

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
