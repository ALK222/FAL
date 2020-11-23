/*
N� DE GRUPO: 09
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA: Alejandro Barrachina Argudo y Rodrigo Sosa Saez

EN CASO DE QUE ALGUNO DE LOS MIEMBROS DEL
GRUPO NO HAYA PARTICIPADO EN LA PRACTICA,
INDICARLO AQUI, EXPLICANDO TAMBI�N EL MOTIVO:



*/

#include <iostream>

using namespace std;

const int TMAX = 2000000; // No habr� vectores de m�s de dos millones de elementos

/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  0<n<=tam(a)
*/

int llena_mochila(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

  result = PARATODO i: SUMA i : a_0 +...+ a_i <= k

 */

/*
  DISE�O DEL ALGORITMO:

  Paso 1. Variables
     --ENTRADA: a, n, k
     --SALIDA: max_total
     --CONTROL: i para recorrer todo el array
                j para recorrer los siguientes numero a i

     -- suma y total para almacenar datos de la suma del peso

  Paso 2. Invariante

 0 < i < n y suma <= k

  Paso 3. Inicializaci�n
     si i = n; total = 0; suma = 0; max_suma = 0;

  Paso 4. Condici�n del bucle, y c�digo tras el bucle.
   --CONDICION bucle 1: i >= 0 y (n-i+1)-max_total >= 0
   una vez terminado el bucle se consigue la postcondicion

  Paso 5. Cuerpo del bucle
   Como el bucle exige 0< i < n por lo tanto a[i] siempre existe
   Pueden darse 2 casos:
     --suma > k - a[i]
     se reincia i hasta el ultimo numero no comprobado

     --suma <= k -a[i]
     por lo tanto suma += a[i], total++ y se sigue iterando

   Despues de estos casos pueden darse otros 2:
     -total <= max_total
     no se actualiza el max_total
     -total > max_total
     max_total se actualiza 

  Paso 6. Justificaci�n de que el algoritmo siempre termina.
  En cada iteración aumentamos i y, por lo tanto podemos tomar como expresion de cota n - i
  en cada iteracion del bucle interno aumentamos j por lo que la cota puede ser i - j

  Paso 7. Complejidad:

   C_0 = coste de inicio y fin
   C_1 = coste bucle while1

   MEJOR CASO:
   n = 1
   Tm = C_0 + C_1= coste constante

   PEOR CASO:

   n > 1
   TM = lim n=> infinito C_0 + n*(n-1)* C_1 => O(n^2) orden cuadratico

  */

int llena_mochila(const int a[], int n, int k)
{
    // A IMPLEMENTAR
    int max_total = 0;
    int i = 0;
    int suma = 0;
    int total = 0;
    while (i <= n && (n - i + 1) - max_total >= 0)
    {
        if (suma <= k - a[i])
        {
            suma += a[i];
            total++;
        }
        else
        {
            i -= total;
            suma = 0;
            total = 0;
        }
        if (total > max_total)
        {
            max_total = total;
        }

        i++;
    }

    return max_total;
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
            int k;
            cin >> k;
            cout << llena_mochila(a, n, k) << endl;
        }
    } while (n != -1);
}
