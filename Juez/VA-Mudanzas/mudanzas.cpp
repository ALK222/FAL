
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

// int totalITS;

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
int numCajas(const int objetos[], const tObjetos objs, const int capacidad)
{
    int numCajas = 0;
    int sumaActual = 0;
    for (int i = 0; i < objs.n_objetos; ++i)
    {
        int index = objetos[i];
        if (sumaActual + objs.tamanios[index] >= capacidad)
        {
            sumaActual = sumaActual + objs.tamanios[index] > capacidad ? objs.tamanios[index] : 0;
            numCajas++;
        }
        else
        {
            sumaActual += objs.tamanios[index];
        }
    }
    if (sumaActual > 0)
    {
        numCajas++;
    }
    return numCajas;
}

void actualizarCajas(int cajasUsadas[], int mejoresCajas[], int numObjetos)
{
    for (int i = 0; i < numObjetos; ++i)
    {
        mejoresCajas[i] = cajasUsadas[i];
    }
}

void printList(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void printBools(bool b[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << b[i] ? "TRUE " : "FALSE ";
    }
    cout << "\n";
}

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

void resolver(tObjetos objetos, int numObjetos, int capacidad, bool &hay_espacio, int cajasActuales[], int mejoresCajas[])
{
    if (numObjetos == objetos.n_objetos)
    {
        if (!hay_espacio || (numCajas(cajasActuales, objetos, capacidad) < numCajas(mejoresCajas, objetos, capacidad)))
        {
            actualizarCajas(cajasActuales, mejoresCajas, objetos.n_objetos);
            hay_espacio = true;
        }
    }
    else
    {
        for (int objeto = 0; objeto < objetos.n_objetos; ++objeto)
        {
            if (!contiene(cajasActuales, numObjetos, objeto))
            {
                // totalITS++;
                cajasActuales[numObjetos] = objeto;
                /*printList(mejoresCajas, objetos.n_objetos);
                printList(cajasActuales, objetos.n_objetos);*/
                resolver(objetos, numObjetos + 1, capacidad, hay_espacio, cajasActuales, mejoresCajas);
                // printBools(objetosUsados, objetos.n_objetos);
                // objetosUsados[objeto] = false;
            }
        }
    }
}

int min_numero_de_cajas(const tObjetos &objetos, int capacidad_caja)
{
    //// A IMPLEMENTAR
    // bool objetosUsados[MAX_OBJS] = { 0 };
    ////initUsados(objetosUsados, objetos.n_objetos);
    int objetosOrdenados[MAX_OBJS];
    int mejorCombinacion[MAX_OBJS];
    bool hay_espacio = false;
    objetosOrdenados[0] = 0;
    resolver(objetos, 1, capacidad_caja, hay_espacio, objetosOrdenados, mejorCombinacion);
    // cout << totalITS << endl;
    return numCajas(mejorCombinacion, objetos, capacidad_caja);
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
