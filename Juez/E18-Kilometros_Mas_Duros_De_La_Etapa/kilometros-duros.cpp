//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Aqui explicacion de la función que resuelve el problema.
//
// El algoritmo recorre todos los elementos del vector buscando el tramo de mayor desnivel
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// El primer bucle tiene un coste de orden O(t), siendo t el tamaño del tramo a mirar
// El segundo bucle tiene un coste de orden O(n - t), siendo t el numero de elementos en el vector
//
//*******************************

struct tSol
{
    int desnivel = 0;
    int pos = 0;
    int lastPos = 0;
};

// Aqui la función implementada por el alumno para resolver el problema
auto resolver(std::vector<int> const &v, int const &tramo)
{
    tSol sol;

    int desnivel = 0;

    for (int i = 0; i < tramo; ++i)
    {
        sol.desnivel += v[i];
    }

    desnivel = sol.desnivel;

    for (int i = tramo; i < v.size(); ++i)
    {
        desnivel += v[i] - v[i - tramo];

        if (desnivel > sol.desnivel)
        {
            sol = {desnivel, i + 1 - tramo, i + 1 - tramo};
        }
        else if (desnivel == sol.desnivel)
        {
            sol.lastPos = i + 1 - tramo;
        }
    }
    return sol;
}

// Resuelve cada caso de la entrada
bool resuelveCaso()
{
    // Lectura de los datos
    int numKilometros, longitudTramo;
    std::cin >> numKilometros >> longitudTramo;
    if (numKilometros == 0 && longitudTramo == 0)
        return false;
    std::vector<int> v(numKilometros); // nombre y altura
    for (int &n : v)
    {
        std::cin >> n;
    }
    // LLamada a la funcion que resuelve el problema

    tSol sol = resolver(v, longitudTramo);

    // Escribir el resultado

    std::cout << sol.desnivel << ' ' << sol.pos << ' ' << sol.lastPos << '\n';

    return true;
}

int main()
{
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
