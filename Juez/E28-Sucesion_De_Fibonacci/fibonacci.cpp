//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno Alejandro Barrachina Argudo
// Usuario del juez de clase A81
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

//*******************************
// Aqui explicacion del algoritmo y calculo del coste.
//
//
//
//
//*******************************

// Aqui la funcion que resuelve el problema
struct tSol
{
    bool esInteresante = false;
    int sumaIzq = 0;
};

unsigned long int fibonacci(unsigned long int const num, unsigned long int const a, unsigned long int const b)
{
    return (num == 0) ? b : fibonacci(num - 1, b, a + b);
}

// Para lectura de datos y mostrar los resultados
bool resuelveCaso()
{
    unsigned long int num;

    std::cin >> num;

    if (!std::cin)
    {
        return false;
    }

    if (num == 0)
    {
        std::cout << "0\n";
    }
    else
    {
        unsigned long int sol = fibonacci(num - 1, 0, 1);

        std::cout << sol << '\n';
    }

    return true;
}

int main()
{
    // Para redireccionar la entrada del juez
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
