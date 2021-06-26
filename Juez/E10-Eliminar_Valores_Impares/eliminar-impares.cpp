// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
/*
    El algoritmo presenta un unico bucle con una comparacion y un incremento. En este bucle miramos si el elemento a comprobar es par, en caso de serlo lo movemos hasta la posición siguiente al ultimo elemento par ordenado.
*/

// Coste del algoritmo utilizado
// Todos los elementos del bucle son constantes, por lo tanto el coste es del orden de  O(v.size()). La operacion resize sobre un vector es de coste constante.

// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int> &v)
{
    // Codigo del alumno

    int ultimoAlumno = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] % 2 == 0)
        {
            v[ultimoAlumno] = v[i];
            ultimoAlumno++;
        }
    }

    v.resize(ultimoAlumno);
}

// Funcion que lee de la entrada,
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso()
{
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1)
        return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i)
    {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0)
        std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main()
{
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
