// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const &v, int alturaNave, int &posIni, int &posFin)
{
    // Codigo del alumno

    int longMax = 0;
    int longAct = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > alturaNave)
        {
            ++longAct;
            if (longMax < longAct)
            {
                longMax = longAct;
                posFin = i;
                posIni = i - longAct + 1;
            }
        }
        else
        {
            longAct = 0;
        }
    }
}

// Funcion que lee de la entrada,
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso()
{
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int &i : v)
        std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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
