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

void resolver(tObjetos objetos, int numObjetos, int capacidad, bool &hay_espacio, tCajas cajasActuales, int &mejorNumCajas)
{
    if (numObjetos == objetos.n_objetos)
    {
        // cajasActuales.numCajas = numCajas(cajasActuales.cajas, objetos, capacidad, numObjetos);
        if (!hay_espacio || cajasActuales.numCajas <= mejorNumCajas)
        {
            // actualizarCajas(cajasActuales.cajas, mejorNumCajas.cajas, cajasActuales.numCajas);
            mejorNumCajas = cajasActuales.numCajas;
            hay_espacio = true;
        }
    }
    else
    {
        for (int index = 0; index <= cajasActuales.numCajas && cajasActuales.numCajas <= objetos.n_objetos + 1; ++index)
        {
            if (cajasActuales.cajas[index] < 0)
            {
                cajasActuales.cajas[index] = 0;
            }
            if (cajasActuales.cajas[index] + objetos.tamanios[numObjetos] <= capacidad)
            {
                cajasActuales.cajas[index] += objetos.tamanios[numObjetos];
                resolver(objetos, numObjetos + 1, capacidad, hay_espacio, cajasActuales, mejorNumCajas);
                // cout << "INDEX: " << index << " NUMOBJT: " << numObjetos << endl;
                cajasActuales.cajas[index] -= objetos.tamanios[numObjetos];
                if (cajasActuales.cajas[index] == 0)
                {
                    cajasActuales.numCajas--;
                }
            }
            else
            {
                if (index == cajasActuales.numCajas - 1)
                {
                    cajasActuales.numCajas++;
                }
            }
        }
    }
}

int min_numero_de_cajas(const tObjetos &objetos, int capacidad_caja)
{
    //// A IMPLEMENTAR
    tCajas cajasOrdenadas;
    int mejorCombinacion;
    cajasOrdenadas.numCajas = 1;
    cajasOrdenadas.cajas[0] = objetos.tamanios[0]; /*
      mejorCombinacion.numCajas = 0;
      cajasOrdenadas.cajas[0] = objetos.tamanios[0];*/
    bool hay_espacio = false;

    resolver(objetos, 1, capacidad_caja, hay_espacio, cajasOrdenadas, mejorCombinacion);

    return mejorCombinacion; /*numCajas(mejorCombinacion, objetos, capacidad_caja);   */
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
