// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

// Coste del algoritmo utilizado: O(n) siendo n el numero de elementos en el vector

// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos.
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor
std::vector<int> resolver(std::vector<int> const &v, int maximoValores)
{
    int n = 0;
    int m = 0;

    std::vector<int> sol;

    std::vector<int> aux(maximoValores + 1, 0);

    for (int i = 0; i < v.size(); ++i)
    {
        ++aux[v[i]];
        n = m;

        m = std::max(m, aux[v[i]]);

        if (n < m)
        {
            sol.clear();
            sol.push_back(v[i]);
        }
        else if (aux[v[i]] == m)
        {
            sol.push_back(v[i]);
        }
    }

    return sol;
}

// Entrada y salida de datos
bool resuelveCaso()
{
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1)
        return false; // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int &i : v)
        std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que
    // aparecen más veces

    std::vector<int> sol;

    sol = resolver(v, valorMax);

    std::sort(sol.begin(), sol.end(), std::greater<int>());

    // Escribir los valores del vector que ha calculado resolver

    for (int &i : sol)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

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
