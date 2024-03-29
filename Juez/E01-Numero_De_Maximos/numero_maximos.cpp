// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <iomanip>
#include <fstream>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int puntActual;
    int personasConMaximaPunt = 0;
    int maxPuntuacion;

    bool nuevoMaximo = false;

    std::cin >> puntActual;

    maxPuntuacion = puntActual;

    while (puntActual != 0)
    {
        nuevoMaximo = puntActual > maxPuntuacion;

        maxPuntuacion = std::max(puntActual, maxPuntuacion);

        if (nuevoMaximo)
        {
            personasConMaximaPunt = 1;
        }
        else if (puntActual == maxPuntuacion)
        {
            personasConMaximaPunt++;
        }

        std::cin >> puntActual;
    }

    std::cout << maxPuntuacion << " " << personasConMaximaPunt << '\n';
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
