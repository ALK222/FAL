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
#include <algorithm>
#include <string>

//*******************************
// Aqui especificación de la función que resuelve el problema.
//
// - Precondicion: el vector sera de tamaño 0 < n < max_int
// - Postcondicion: resul = paratodo i: 0 < i < n: alturaPiso(i) > alturaEdificio(i+1) && pisoLibre(i) != -1
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// C_0 = coste de inicio y fin del algoritmo(creacion de variables y return)
// C_1 = coste interno del bucle(comparaciones, push_back y max)
//
// Teniendo en cuenta que el bucle se ejecuta n veces: lim_{n->infinito} C_0 + n*C_1 = C_1 => O(n)
//
//*******************************

struct tPiso
{
    std::string name;
    int altura;
    int libre;
};

using vecPis = std::vector<tPiso>;
// Aqui la función implementada por el alumno
std::vector<std::string> resolver(vecPis const &v)
{
    int alturaAntEdificio = -1;

    std::vector<std::string> sol;

    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (v[i].libre != -1 && v[i].libre > alturaAntEdificio)
        {
            sol.push_back(v[i].name);
        }
        alturaAntEdificio = std::max(alturaAntEdificio, v[i].altura);
    }
    return sol;
}

bool resuelveCaso()
{
    int numEdificios;
    std::cin >> numEdificios;
    if (numEdificios == 0)
        return false;

    // Lectura del resto de los datos
    vecPis pisos(numEdificios);

    for (tPiso &p : pisos)
    {
        std::cin >> p.name >> p.altura >> p.libre;
    }

    // LLamada a la funcion que resuelve el problema

    auto sol = resolver(pisos);

    // Escribir el resultado

    if (sol.empty())
    {
        std::cout << "Ninguno\n";
    }
    else
    {
        std::cout << sol.size() << '\n';

        for (std::string s : sol)
        {
            std::cout << s << ' ';
        }

        std::cout << '\n';
    }

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
