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

tSol resolver(int num, int sumaDer)
{
    if (num < 10)
    {
        if (num == 0 || sumaDer % num != 0)
        {
            return {false, 0};
        }
        else
        {
            return {true, num};
        }
    }
    else
    {
        if (sumaDer % (num % 10))
        {
            return {false, 0};
        }

        auto sol = resolver(num / 10, sumaDer + num % 10); // 621348 --> 62134 , 0 + 8(...)

        if (!sol.esInteresante || sol.sumaIzq % (num % 10) != 0)
        {
            return {false, 0};
        }
        else
        {
            return {true, sol.sumaIzq + (num % 10)};
        }
    }
}

// Para lectura de datos y mostrar los resultados
void resuelveCaso()
{
    // Lectura de datos
    int num;
    std::cin >> num;

    // LLamar a la función que resuelve el problema
    tSol sol = resolver(num, 0);

    // Escribir el resultado
    std::cout << (sol.esInteresante ? "SI\n" : "NO\n");
}

int main()
{
    // Para redireccionar la entrada del juez
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
