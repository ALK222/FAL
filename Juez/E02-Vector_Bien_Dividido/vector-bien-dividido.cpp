// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <utility>
#include <algorithm>

bool resolver()
{
    int elementosVector;
    int posicion;
    int maximo = INT_MIN;
    int minimo = INT_MAX;

    int numeroActual;

    std::cin >> elementosVector >> posicion;

    if (posicion == elementosVector - 1)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }

    for (int i = 0; i < elementosVector; i++)
    {
        std::cin >> numeroActual;

        if (i <= posicion)
        {
            maximo = std::max(maximo, numeroActual);
        }
        else
        {
            minimo = std::min(minimo, numeroActual);
        }
    }

    return maximo < minimo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    if (resolver())
    {
        std::cout << "SI\n";
    }
    else
    {
        std::cout << "NO\n";
    }
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
        resuelveCaso();

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
