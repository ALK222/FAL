// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Aqui explicacion de la función que resuelve el problema.
//
//  El algoritmo recorre todos los elementos del vector buscando tramos de n >= longitud elementos.
//
//  Se busca o bien la pagina mas interesante o el conjunto de paginas mas interesante
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// C_{0} = coste de inicio y fin
// C_{1} = coste de las operaciones del bucle
//
// Teniendo en cuenta que el bucle se ejecuta tantas veces como elementos haya:
// lim_{n->infinito} C_{0} + nC_{1} = C_{1} => O(n)
//

struct tSol
{
    int interesante = 0;
    int masInteresante = 0;
    int pos = 0;
};

// Aqui la función implementada por el alumno para resolver el problema
auto resolver(std::vector<int> const &v, int const &tramo)
{
    tSol sol;

    int interesante = 0;

    for (int i = 0; i < tramo; ++i)
    {
        sol.interesante += v[i];
        sol.masInteresante = std::max(sol.masInteresante, v[i]);
    }

    interesante = sol.interesante;

    for (int i = tramo; i < v.size(); ++i)
    {
        interesante += v[i] - v[i - tramo];

        if (interesante >= sol.interesante)
        {
            sol = {interesante, std::max(v[i], sol.masInteresante), i + 1 - tramo};
        }
        else if (v[i] > sol.masInteresante)
        {
            sol.interesante = v[i];
            sol.masInteresante = v[i];
            sol.pos = i + 1 - tramo;
        }
    }
    return sol;
}

// Resuelve cada caso de la entrada
bool resuelveCaso()
{
    int numElem, numPags;
    std::cin >> numElem >> numPags;
    if (numElem == 0 && numPags == 0)
        return false;
    std::vector<int> v(numElem);
    for (int &n : v)
        std::cin >> n;

    // LLamada a la funcion que resuelve el problema

    auto sol = resolver(v, numPags);

    // Escribir el resultado

    std::cout << sol.pos << '\n';

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
