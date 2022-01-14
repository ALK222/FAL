#include <iostream>

using namespace std;

const int TMAX = 2000000; // No habr� vectores de m�s de dos millones de elementos

/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

*/

int num_brillantes(float a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'


 */

int num_brillantes(float a[], int n)
{
    // Implementa aqu� el algoritmo.
    // Para cada bucle, indica un invariante y una expresi�n
    // de cota que permitan justificar la correcci�n del algoritmo
    float sumaTotal = a[0];
    int numBrillantes = 0;
    for (int i = 1; i < n; ++i)
    {
        sumaTotal += a[i];
    }
    float media = sumaTotal / n;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] - media >= 0.5)
        {
            numBrillantes++;
        }
    }
    return numBrillantes;
}

/* Complejidad: Determina justificadamente la complejidad del algoritmo

*/

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(float a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    static float a[TMAX];
    int n;
    do
    {
        lee_vector(a, n);
        if (n >= 0)
        {
            cout << num_brillantes(a, n) << endl;
        }
    } while (n != -1);
}
