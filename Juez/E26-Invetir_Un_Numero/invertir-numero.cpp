// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Aqui la función implementada por el alumno para resolver el problema
auto invertir(int num, int res)
{
    if (res == 0 && num < 10)
    {
        return num;
    }
    else if (num == 0)
    {
        return res;
    }
    else
    {
        return invertir(num / 10, res * 10 + (num % 10));
    }
}

// Resuelve cada caso de la entrada
bool resuelveCaso()
{
    long long int num;
    std::cin >> num;
    if (num == 0)
    {
        return false;
    }

    auto inverso = invertir(num, 0);

    // escribir sol
    std::cout << inverso << '\n';

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
