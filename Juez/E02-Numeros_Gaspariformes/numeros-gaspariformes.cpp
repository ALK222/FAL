#include <iostream>

using namespace std;

const int TMAX = 2000000; // No habr� vectores de m�s de dos millones de elementos

/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
	0 < n <= tam(a)

*/
bool es_gaspariforme(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

  resul = (PARATODO 0 < i < n : es_gaspariforme(i))


 */

/*
 DISE�O DEL ALGORITMO:
 -- Especifica cada paso del dise�o en cada apartado indicado

 Paso 1. Variables
	SumaParcial<Int>: sumas parciales en cada momento del algoritmo
	i<Int>: indice para recorrer el array
	gaspariforme<bool>: comprobante de que el numero es gaspariforme

 Paso 2. Invariante
	gaspariforme = (PARATODO 0 < i < n : SUM a[i] >= 0)

 Paso 3. Inicializaci�n
	i se inicia a 0 para ponerlo en el primer punto del array
	gaspariformes a true para cumplir una de las condiciones del bucle
	sumasParciales a 0 para no tener suma inicial



 Paso 4. Condici�n del bucle, y c�digo tras el bucle
	CONDICION: 0 < i < n-1 y que las sumas parciales sean gaspariformes
	DESPUES DEL BUCLE: comprobamos si el numero es gaspariforme con su ultima suma


 Paso 5. Cuerpo del bucle
 Se realiza la suma parcial y se comprueba que no es negativa


 Paso 6. Justificaci�n de que el algoritmo siempre termina

 El numero de i siempre avanza hasta ser igual que n, terminando así el algoritmo


 Paso 7. Complejidad
  O(N)

 */

bool es_gaspariforme(const int a[], int n)
{
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
    int i = 0;
    int sumaParcial = 0;
    bool gaspariforme = true;
    while (i < (n - 1) && gaspariforme)
    {
        sumaParcial += a[i];
        if (sumaParcial <= 0)
        {
            gaspariforme = false;
        }

        ++i;
    }
    sumaParcial += a[i];
    if (sumaParcial != 0)
    {
        gaspariforme = false;
    }
    return gaspariforme;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    static int a[TMAX];
    int n;
    do
    {
        lee_vector(a, n);
        if (n >= 0)
        {
            if (es_gaspariforme(a, n))
                cout << "SI" << endl;
            else
                cout << "NO" << endl;
        }
    } while (n >= 0);
}
