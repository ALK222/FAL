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

/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

(4) An�lisis de la complejidad del algoritmo

*/

bool cruza(int enemigos[], int n, int max_duelos, int power)
{
    int i = 0, salt = 0, suma = 0;
    while (i < n && (enemigos[i] <= power) && (salt <= max_duelos))
    {
        suma += enemigos[i];
        if (suma > power)
        {
            salt++;
            suma = enemigos[i];
        }
        i++;
    }
    return i == n;
}

void acota(int enemigos[], int n, int max_duelos, int &ini, int &fin)
{
    ini = 0;
    fin = 2;
    while (!cruza(enemigos, n, max_duelos, fin))
    {
        ini = fin;
        fin *= 2;
    }
}

int aux(int enemigos[], int n, int max_duelos, int ini, int fin)
{
    int m = (ini + fin) / 2;
    if (cruza(enemigos, n, max_duelos, m))
    {
        if (!cruza(enemigos, n, max_duelos, m - 1))
        {
            return m + enemigos[sizeof(enemigos) - 1];
        }
        else
        {
            return aux(enemigos, n, max_duelos, ini, m - 1);
        }
    }
    else
        return aux(enemigos, n, max_duelos, m + 1, fin);
}

//int calcula_min(int enemigos[], int n, int ini, int final)
//{
//		int mid = ini + final / 2;
//		if (se_vence(enemigos, n, mid))
//		{
//			if(!se_vence(enemigos, n,mid-1))
//			{
//				return mid;
//			}
//			else
//			{
//				return calcula_min(enemigos, n, ini, mid - 1);
//			}
//		}
//		else
//		{
//			return calcula_min(enemigos, n, mid + 1, final);
//		}
//}

int min_poder(int enemigos[], int n, int max_duelos)
{
    // Punto de entrada al algoritmo: a implementar
    int ini, fin;
    acota(enemigos, n, max_duelos, ini, fin);
    return aux(enemigos, n, max_duelos, ini, fin);
}

const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso()
{
    int enemigos[MAX_ENEMIGOS];
    int num_enemigos;
    cin >> num_enemigos;
    if (num_enemigos == -1)
    {
        return false;
    }
    else
    {
        int max_torneos;
        cin >> max_torneos;
        for (int i = 0; i < num_enemigos; i++)
        {
            cin >> enemigos[i];
        }
        cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
        return true;
    }
}

int main()
{
    while (ejecuta_caso())
        ;
}
