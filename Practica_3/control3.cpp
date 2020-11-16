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
  --- 0<n<=tam(a)

*/
int num_chupiguays(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

  num_chupi(n) = a[n] = (a[n-1] + (i veces) + a[n- i]) * b: 0 <= i < n;
  resul = PARATODO i: 0<= i < n; : num_chupi(i);


 */

/*
  DISE�O DEL ALGORITMO:
  -- Especifica cada paso del dise�o en cada apartado indicado

  Paso 1. Variables
     --ENTRADA: a y n
     --SALIDA resul
     --CONTROL i para recorrer el bucle
     --SUMA para almacenar la suma del vector

  Paso 2. Invariante
   0 <= i <= n Y num_chupiguays(a, i)

  Paso 3. Inicializaci�n
  si i = 0; res = 0; suma = 0;


  Paso 4. Condici�n del bucle, y c�digo tras el bucle
   --CONDICION i <n
   Una vez terminado el bucle se consigue directamente la postcondicion


  Paso 5. Cuerpo del bucle
  Como el bucle exige i < n --> a[i] siempre tendrá sentido
  Pueden darse dos casos
     -- suma % a[i] == 0
     por lo tanto resul++
     se sigue iterando

     -- a[i] % suma != 0
     por lo tanto no se hace nada y se sigue iterando


  Paso 6. Justificaci�n de que el algoritmo siempre termina
  En cada iteración aumentamos i, por lo tanto podemos tomar como expresion de cota n - i


  Paso 7. Complejidad
  -- MEJOR CASO:
     n = 0
     Tm = Tini_y_fin --> orden constante O(1)

 -- PEOR CASO:
     n != 0
     TM = Tini_y_fin + n*Tbucle  --> Lim_{n tiende infinito)  Tini_y_fin + n*Tbucle = Tbucle --> O(n) orden lineal
  */

int num_chupiguays(const int a[], int n)
{
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
    int i = 0;
    int suma = 0;
    int resul = 0;
    while (i < n)
    {

        if (suma != 0)
        {
            if (a[i] % suma == 0)
            {
                resul++;
            }
        }
        else
        {
            if (a[i] == 0)
            {
                resul++;
            }
        }
        suma += a[i];
        i++;
    }
    return resul;
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
            cout << num_chupiguays(a, n) << endl;
        }
    } while (n != -1);
}
