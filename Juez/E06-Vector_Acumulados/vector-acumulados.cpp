// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;
// Calcula un vector con los valores acumulados
// Recibe un vector a con los datos de entrada
// Devuelve en un vector diferente v los datos de entrada acumulados
// Postcondicion de la función para todo i: 0 <= i < v.size(): v[i] = Sum k : 0 <= k <= i: a[i]
void resolver(std::vector<int> const &a, std::vector<lli> &v)
{
    v.push_back(lli(a[0]));

    for (size_t i = 1; i < a.size(); i++)
    {
        v.push_back(lli(a[i]) + v[i - 1]);
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0)
        return false;

    // Lee el resto de los datos en un vector

    std::vector<int> nacimientos;

    for (int i = 0; i <= std::abs(a1 - a2); ++i)
    {
        int n;
        std::cin >> n;

        nacimientos.push_back(n);
    }

    std::vector<lli> acumulados;

    resolver(nacimientos, acumulados);

    lli sol;

    // Lectura de las preguntas
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int f1, f2;
        std::cin >> f1 >> f2;

        if (f1 - a1 != 0)
        {
            sol = acumulados[f2 - a1] - acumulados[f1 - a1 - 1];
        }
        else
        {
            sol = acumulados[f2 - a1];
        }

        std::cout << sol << '\n';
    }
    std::cout << "---\n";

    return true;
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto

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
