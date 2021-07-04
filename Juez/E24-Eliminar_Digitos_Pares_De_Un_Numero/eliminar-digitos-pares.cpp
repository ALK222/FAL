// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Aqui la función implementada por el alumno para resolver el problema
auto resolver(long long int num)
{
    if (num < 10)
    {
        if (num % 2 == 1)
        {
            return num;
        }
        else
        {
            return (long long int)0;
        }
    }
    else
    {
        if ((num % 10) % 2 == 1)
        {
            return resolver(num / 10) * 10 + num % 10;
        }
        else
        {
            return resolver(num / 10);
        }
    }
}

// Resuelve cada caso de la entrada
bool resuelveCaso()
{
    long long int num;
    std::cin >> num;
    if (!std::cin)
    {
        return false;
    }

    auto sol = resolver(num);

    // escribir sol
    std::cout << sol << '\n';

    return true;
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
    {
    } //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
