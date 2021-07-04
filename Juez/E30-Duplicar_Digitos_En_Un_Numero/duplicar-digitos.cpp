// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A81

#include <iostream>
#include <fstream>

// Aqui ecuaciones recursivas que resuelven el problema.
// Se puede elegir dar las ecuaciones para una recursión final
// o para una no final.
//
//
//

// Función recursiva no final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionNoFinal(int numero)
{

    // Aqui el código del alumno
    if (numero < 10)
    {
        return numero * 11;
    }
    else
    {

        return recursionNoFinal(numero / 10) * 100 + numero % 10 * 11;
    }
}

// Función recursiva final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionFinal(int numero, int duplicado, int pow)
{

    // Aqui el código del alumno
    if (numero < 10)
    {
        return duplicado + numero * pow * 11;
    }
    else
    {

        int duplicadoActual = duplicado + ((numero % 10) * 11) * pow;
        pow *= 10;
        return recursionFinal(numero / 10, duplicadoActual, pow * 10);
    }
}

void resuelveCaso()
{
    // lectura de los datos
    int numero;
    std::cin >> numero;
    // LLamadas a las funciones recursivas
    // Modificar parámetros o tipo de retorno donde se necesite
    int s1 = recursionNoFinal(numero);
    int s2 = recursionFinal(numero, 0, 1);
    // Escribir los resultados. Modificar si se necesita
    std::cout << s1 << ' ' << s2 << '\n';
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
