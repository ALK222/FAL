// ALUMNO: Alejandro Barrachina Argudo
#include <iostream>
using namespace std;

const int MAX_OBJS = 20;
// Lista con los objetos a portar
typedef struct
{
    int tamanios[MAX_OBJS]; // Array en cuyas primeras posiciones se guardan
                            // los tamaños de los objetos
    int n_objetos;          // Numero de objetos
} tObjetos;

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

typedef struct
{
    int cajas[MAX_OBJS];
    int numCajas;
} tCajas;
int numCajas(const int objetos[], const tObjetos objs, const int capacidad, int numObjetos)
{
    int numCajas = 1;
    int suma = 0;
    int sumaActual;
    for (int i = 0; i < numObjetos; i++)
    {
        sumaActual = objetos[i] < 0 ? 0 : objetos[i];

        if (suma + sumaActual > capacidad)
        {
            suma = sumaActual;
            numCajas++;
        }
        else
        {
            suma += sumaActual;
        }
    }
    return numCajas;
}

// void actualizarCajas(int cajasUsadas[], int mejoresCajas[], int numObjetos)
//{
//     for (int i = 0; i < numObjetos; ++i)
//     {
//         mejoresCajas[i] = cajasUsadas[i];
//     }
// }

bool contiene(int c[], int n, int obj)
{
    bool enc = false;
    int i = 0;
    while (!enc && i < n)
    {
        enc = c[i] == obj;
        ++i;
    }
    return enc;
}

void resolver(tObjetos objetos, int numObjetos, int capacidad, tCajas cajasActuales, int &mejorNumCajas)
{
    if (numObjetos == objetos.n_objetos)
    {
        if (cajasActuales.numCajas < mejorNumCajas)
        {
            mejorNumCajas = cajasActuales.numCajas;
        }
    }
    else if (mejorNumCajas > cajasActuales.numCajas)
    {
        for (int index = 0; index < cajasActuales.numCajas; ++index)
        {
            int nuevoTam = cajasActuales.cajas[index] + objetos.tamanios[numObjetos];
            if (nuevoTam <= capacidad)
            {
                cajasActuales.cajas[index] += objetos.tamanios[numObjetos];
                resolver(objetos, numObjetos + 1, capacidad, cajasActuales, mejorNumCajas);
                cajasActuales.cajas[index] -= objetos.tamanios[numObjetos];
            }
        }
        cajasActuales.numCajas++;
        cajasActuales.cajas[cajasActuales.numCajas - 1] += objetos.tamanios[numObjetos];
        resolver(objetos, numObjetos + 1, capacidad, cajasActuales, mejorNumCajas);
        cajasActuales.cajas[cajasActuales.numCajas - 1] -= objetos.tamanios[numObjetos];
        cajasActuales.numCajas--;
    }
}

int min_numero_de_cajas(const tObjetos &objetos, int capacidad_caja)
{
    //// A IMPLEMENTAR
    tCajas cajasOrdenadas;
    int mejorCombinacion = objetos.n_objetos;
    cajasOrdenadas.numCajas = 0;
    for (int i = 0; i < objetos.n_objetos; ++i)
    {
        cajasOrdenadas.cajas[i] = 0;
    }

    resolver(objetos, 0, capacidad_caja, cajasOrdenadas, mejorCombinacion);

    return mejorCombinacion;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso()
{
    int capacidad;
    cin >> capacidad;
    if (capacidad != -1)
    {
        tObjetos objetos;
        cin >> objetos.n_objetos;
        for (int i = 0; i < objetos.n_objetos; i++)
        {
            cin >> objetos.tamanios[i];
        }

        cout << min_numero_de_cajas(objetos, capacidad) << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (ejecuta_caso())
        ;
}
