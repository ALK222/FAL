/*
NOMBRE Y APELLIDOS: ALEJANDRO BARRACHINA ARGUDO



*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TMAX = 300000; // No habr� vectores de m�s de trescientos mil elementos

/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
0 < n < tam(a)

*/

int num_sec_multiplos(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

  totalSecuencias = (#i : PARATODO 0 < i < n : secuenciaActual(i) == k)
 */

/*
 DISE�O DEL ALGORITMO:

 Paso 1. Variables
- secuenciaActual<int>: lleva la cuenta de la longitud de la secuencia actual
- totalSecuencias<int>: numero total de secuencias que cumplen el numero k
- i<int>: indice para recorrer el array

 Paso 2. Invariante
- secuenciaActual = (#i: PARATODO 0 < i =< k : a[i] es multiplo de a[i-1])

 Paso 3. Inicializaci�n
Se inicializa secuenciaActual a 1 (un numero siempre es multiplo de si mismo), totalSecuencias a 0 e i a 0.

 Paso 4. Condici�n del bucle, y c�digo tras el bucle.
- Condición del bucle: i < n, el indice debe ser menor que el tamaño del array
- Código tras el bucle: se hace una última comprobación para el largo de la secuencia y se aumenta o se disminuye
totalSecuencias en consecuencia.

 Paso 5. Cuerpo del bucle
- Primero se comprueba si el numero del indice y el anterior son multiplos:
- En caso de serlo se añade a la secuencia actual 1 más
- En caso de no serlo se resetea la secuencia
- Tras la primera comprobación miramos el largo de la secuencia actual. Si es el que queremos añadimos 1 al total de secuencias

 Paso 6. Justificaci�n de que el algoritmo siempre termina (expresi�n de cota).
sea o no multiplo el numero se suma 1 al indice en cada vuelta. Así eventualmente i será igual a n


 Paso 7. Complejidad:
En el mejor de los casos (k = 1), el coste es constante porque todos los numeros son multiplos de si mismos.
En el peor de los casos se recorre una vez cada elemento del array:
Coste de inicio (C_{0}) = variables e if inicial.
Coste del bucle (C_{1}) = cuerpo del bucle
Coste tras el bucle (C_{2}) = if y return finales.

Lim_{n->infinito} C_{0} + nC_{1} + C_{2} = C_{1}

Por lo tanto sería un coste lineal.

El algoritmo es O(n)

 */

int num_sec_multiplos(const int a[], int n, int k)
{

    // IMPLEMENTAR AQUI ALGORITMO
    int totalSecuencias = 0;
    int secuenciaActual = 1;
    if (k == 1)
    {
        return n;
    }

    int i = 1;

    while (i < n)
    {
        if (a[i] % a[i - 1] == 0)
        {
            i++;
            secuenciaActual++;
        }
        else
        {
            ++i;
            secuenciaActual = 1;
        }
        if (secuenciaActual >= k)
        {
            totalSecuencias++;
            secuenciaActual = k - 1;
        }
    }
    if (secuenciaActual >= k)
    {
        totalSecuencias++;
        secuenciaActual -= k;
    }

    return totalSecuencias;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso()
{
    static int a[TMAX];
    int n;
    cin >> n;
    if (n == -1)
    {
        return false;
    }
    else
    {
        int k;
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << num_sec_multiplos(a, n, k) << endl;
        return true;
    }
}

int main()
{
    while (ejecuta_caso())
        ;
}
