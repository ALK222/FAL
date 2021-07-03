// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Aqui la función implementada por el alumno para resolver el problema
auto resolver(long long int num, long long int sum, long long int pow)
{
    if (num < 10)
    {
        return (9 - num) * pow + sum;
    }
    else
    {
        return resolver((num / 10), (9 - (num % 10)) * pow + sum, pow * 10);
    }
}

auto invertir(int num, int res)
{
    if (res == 0 && num < 10)
    {
        return 9 - num;
    }
    else if (num == 0)
    {
        return res;
    }
    else
    {
        return invertir(num / 10, res * 10 + (9 - (num % 10)));
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

    auto sol = resolver(num, 0, 1);

    auto inverso = invertir(num, 0);

    // escribir sol
    std::cout << sol << ' ' << inverso << '\n';

    return true;
}

int main()
{

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
