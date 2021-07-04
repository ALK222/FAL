//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno Alejandro Barrachina Argudo
// Usuario del juez de clase A81
//
//***************************************************

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
int recursionNoFinal(int numero, int digito)
{

    // Aqui el código del alumno
    if (numero < 10)
    {
        return numero % 10 == digito ? 1 : 0;
    }
    else
    {
        return recursionNoFinal(numero / 10, digito) + (numero % 10 == digito ? 1 : 0);
    }
}

// Función recursiva final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionFinal(int numero, int digito, int cont)
{

    // Aqui el código del alumno

    if (numero < 10)
    {
        return numero == digito ? cont + 1 : cont;
    }
    else
    {
        if (numero % 10 == digito)
        {
            cont++;
        }

        return recursionFinal(numero / 10, digito, cont);
    }
}

void resuelveCaso()
{
    // lectura de los datos
    int numero, digito;
    std::cin >> numero >> digito;
    // LLamadas a las funciones recursivas
    // Modificar parámetros o tipo de retorno donde se necesite
    int s1 = recursionNoFinal(numero, digito);
    int s2 = recursionFinal(numero, digito, 0);
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
