// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Explicación del algoritmo utilizado
/*
    El algoritmo recorre todos los elementos del vector y comprueba si estan en una posicion correcta.
*/

// Coste del algoritmo utilizado: O(n) siendo n el numero de elementos en el vector

void resolver(std::vector<int> &v)
{
    int nuevoTam = 0;

    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (v[i] % 2 == 0 && nuevoTam % 2 == 0 || v[i] % 2 == 1 && nuevoTam % 2 == 1)
        {
            std::swap(v[nuevoTam], v[i]);
            ++nuevoTam;
            if (nuevoTam <= i)
            {
                nuevoTam++;
            }
        }
    }
    if (nuevoTam % 2 == 1)
    {
        --nuevoTam;
    }

    v.resize(nuevoTam);
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

    std::vector<int> pares(n);

    for (int &i : pares)
    {
        std::cin >> i;
    }
    resolver(pares);

    for (int i : pares)
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
