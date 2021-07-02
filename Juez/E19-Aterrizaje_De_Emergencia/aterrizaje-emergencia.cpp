// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>
#include <vector>

// Aqui explicacion de la función que resuelve el problema.
//
//  El algoritmo recorre todos los elementos del vector buscando tramos de n >= longitud elementos.
//
// Si se encuentra con un numero que rompe la racha, reinicia el largo actual
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// C_{0} = coste de inicio y fin
// C_{1} = coste de las operaciones del bucle
//
// Teniendo en cuenta que el bucle se ejecuta tantas veces como elementos haya:
// lim_{n->infinito} C_{0} + nC_{1} = C_{1} => O(n)
//

// Aqui la función implementada por el alumno para resolver el problema
std::vector<int> resolver(std::vector<int> const &v, int l)
{
    int longAct = 0;

    int aux = v[0];

    std::vector<int> sol;

    for (int i = 0; i < v.size(); ++i)
    {
        if (0 == std::abs(aux - v[i]) || 1 == std::abs(aux - v[i]))
        {
            longAct++;
            if (longAct == l)
            {
                sol.push_back(i - l + 1);
            }
        }
        else
        {
            longAct = 1;
        }
        aux = v[i];
    }

    return sol;
}

// Resuelve cada caso de la entrada
bool resuelveCaso()
{
    int numElem, L;
    std::cin >> numElem >> L;
    if (numElem == 0 && L == 0)
        return false;
    std::vector<int> v(numElem);
    for (int &n : v)
        std::cin >> n;

    // LLamada a la funcion que resuelve el problema

    auto sol = resolver(v, L);

    // Escribir el resultado
    std::cout << sol.size();

    for (int i : sol)
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
    {
    } //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
