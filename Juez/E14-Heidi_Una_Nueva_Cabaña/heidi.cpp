// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

struct tSol
{
    int longMax = 0;
    std::vector<int> pos;
};

auto resolver(std::vector<int> const &v, int n)
{
    tSol sol;

    int i = v.size() - 1;
    int auxMax = v[i];
    --i;
    int cont = 1;

    while (i >= 0)
    {
        if (auxMax < v[i])
        {
            auxMax = v[i];
            cont = 1;
        }
        else if (auxMax == v[i])
        {
            ++cont;
            if (cont == n)
            {
                sol.pos.push_back(i + cont - 1);
            }
            if (cont > sol.longMax && cont >= n)
            {
                sol.longMax = cont;
            }
        }
        else
        {
            cont = 0;
        }
        --i;
    }

    return sol;
}

// Entrada y salida de datos
bool resuelveCaso()
{
    int dim;
    int num;

    std::cin >> dim >> num;

    if (!std::cin)
    {
        return false;
    }

    std::vector<int> llanos(dim);

    for (int &i : llanos)
    {
        std::cin >> i;
    }

    auto sol = resolver(llanos, num);

    std::cout << sol.longMax << ' ' << sol.pos.size();

    for (const int i : sol.pos)
    {
        std::cout << ' ' << i;
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
