/*
N� DE GRUPO: 09
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA: Alejandro Barrachina Argudo, Rodrigo Sosa Saez

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
    El tamaño del array entre 0 TMAX y que n != -1

*/
bool divertida(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION: 
 
  Q: { resul = (  (PARATODO i:0<=i<n:(SUMA j:0<=j<=i:a[i])>=0) && ( (SUMA i:0<=i<n:a[i])=0 ) ) }
   
 */

bool divertida(const int a[], int n)
{
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */

    int i = 0;
    int sumai = 0;
    while (i < n && sumai >= 0)
    {
        sumai += a[i];
        i++;
    }
    return sumai == 0;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso 
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema

    Tamaño del problema: n

    F{0} = Coste de inicio y fin
    F{1} = coste iteración while

    Peor caso: F{0} + n*F{1} = orden n => complejidad lineal
   
*/

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR! */

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
            if (divertida(a, n))
                cout << "SI" << endl;
            else
                cout << "NO" << endl;
        }
    } while (n != -1);
}
