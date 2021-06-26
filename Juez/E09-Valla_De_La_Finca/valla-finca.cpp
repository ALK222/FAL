// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Explicacion del algoritmo:
/*
    El algoritmo tiene dos bucles. El primero se ejecuta tantas veces como metros nuevo de tela tengamos.
    Las instrucciones del primer bucle incluyen una comparacion y un incremento, ambas de coste constante, por lo tanto el coste de este bucle es el numero de vueltas que da el bucle por el coste de cada vuelta y esta en el orden O(n), siendo n el tamaño del intervalo.

    El segundo bucle recorre todos los elementos del vector desde el final del primer intervalo hasta el final del segundo. Por lo tanto el numero de vueltas que da es valla.size() - metrosNuevos.
    En cada vuelta se realizan 3 comparaciones y 3 incrementos y un max. Por lo tanto el coste de este bucle es de O(valla.size() - p), siendo el peor caso (p == 1) a O(valla.size())
*/

int resolver(std::vector<int> const &valla, int const &metrosNuevos)
{
    int partesRotas = 0;

    int pos = -1;

    int maximoRotos = 0;

    for (int i = 0; i < metrosNuevos; ++i)
    {
        if (valla[i] == 0)
        {
            partesRotas++;
        }
    }

    if (partesRotas > 0)
    {
        pos = 0;
    }

    maximoRotos = partesRotas;

    for (int j = metrosNuevos; j < valla.size(); ++j)
    {
        if (valla[j - metrosNuevos] == 0)
        {
            --partesRotas;
        }

        if (valla[j] == 0)
        {
            ++partesRotas;
        }

        maximoRotos = std::max(maximoRotos, partesRotas);

        if (partesRotas >= maximoRotos && partesRotas != 0)
        {
            pos = j - metrosNuevos + 1;
        }
    }

    return pos;
}

bool resuelveCaso()
{

    int metrosConstruidos;
    int metrosNuevos;

    std::cin >> metrosConstruidos;

    if (metrosConstruidos == 0)
    {
        return false;
    }

    std::cin >> metrosNuevos;

    std::vector<int> valla;

    int n;

    for (int i = 0; i < metrosConstruidos; ++i)
    {
        std::cin >> n;

        valla.push_back(n);
    }

    int pos = resolver(valla, metrosNuevos);

    if (pos == -1)
    {
        std::cout << "No hace falta\n";
    }
    else
    {
        std::cout << pos << '\n';
    }

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

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
