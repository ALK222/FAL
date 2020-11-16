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

const int TMAX = 1000000; // No habr� vectores de m�s de un mill�n de elementos

/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  El vector debe estar ordenado y 0 < n <= tam(a)

*/
int menor_moda(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
  -- moda(resul,a,n) && PARATODO i:0<=i<n:(moda(a[i],a,n)->a[i]>=resul)
  siendo moda(v,a,n) = (num_ocurs(v,a,n) = max i: 0<=i<n: num_ocurs(a[i],a,n)) y num_ocurs(v,a,n) = # i: 0<=i<n: a[i]=v

*/

int menor_moda(const int a[], int n)
{
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
    int i = 0;
    int mas_repetido = a[0];
    int curr = a[0];
    int curr_rep = 0;
    int max_rep = 0;
    while (i < n)
    {
        if (curr == a[i])
        {
            curr_rep++;
        }
        else
        {
            if (max_rep < curr_rep)
            {
                max_rep = curr_rep;
                mas_repetido = curr;
            }
            curr = a[i];

            curr_rep = 1;
        }
        i++;
    }
    if (max_rep < curr_rep)
    {
        mas_repetido = curr;
    }
    return mas_repetido;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
   Tamaño n

   PEOR CASO: siendo x el coste de inicio y fin y z el coste de una iteracion del while, 
   en el peor de los casos el cote sería x + n*z siendo un coste lienal.

   Lim_{n -> infinito} x + n*z = z => Theta(n) => orden n y coste lineal.

*/

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
            cout << menor_moda(a, n) << endl;
        }
    } while (n != -1);
}
