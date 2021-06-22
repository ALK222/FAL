// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado
// Se hace un struct con los datos de la solucion, dentro del bucle se pueden dar tres situaciones:
//  - Si hay un nuevo minimo sumamos los datos acumulados
//  - Si es el mismo minimo se incrementa n para saber cuantas veces se ha repetido
//  - Si no se da ninguno de los otros dos casos, se suma y se incrementa el numero de elementos

// Coste del algoritmo utilizado

struct tSol
{
    int suma = 0;
    int numElementos = 0;
};

// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
tSol resolver(std::vector<int> const &v)
{
    // Inicialización de variables
    // Codigo del alumno

    tSol sol;

    int repeticionMinimo = 1;

    int minimo = v[0];

    int aux;

    for (int i = 1; i < v.size(); ++i)
    {

        // Aqui el código del alumno
        // No deben hacerse más bucles

        aux = minimo;

        minimo = std::min(minimo, v[i]);

        if (minimo != aux)
        {
            sol.suma += aux * repeticionMinimo;

            sol.numElementos += repeticionMinimo;

            repeticionMinimo = 1;
        }
        else if (minimo == v[i])
        {
            repeticionMinimo++;
        }
        else
        {
            sol.suma += v[i];
            sol.numElementos++;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // Lectura de los datos
    int numElem;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int &i : v)
        std::cin >> i;
    // LLamar a la función resolver
    tSol s = resolver(v);
    // Escribir los resultados
    std::cout << s.suma << ' ' << s.numElementos << '\n';
}

int main()
{
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
