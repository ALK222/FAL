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
- <int> inf entrada : poder mínimo de para combatir
- <int> sup entrada: poder máximo de para combatir
- <int> mid entrada/salida : valor intermedio de poder entre inf y sup



(2) An�lisis de casos:

(2.1) Casos base
max_duelos <= 1 n >= 0
El poder necesario será la suma de los n combatientes


(2.2) Casos recursivos

si max_duelos > 1 y n > 0
se calcula la cota máxima y minima,
si vence(max), se comprueba vence(max-1) para ver si max es el minimo.
si vence(max-1) devuelve false, max es la solución.
si vence(max-1) devuelve true, se calcula otra vez el minimo y max = max - 1
si vence(max) devuelve false, se calcula otra vez el minimo y max = max + 1

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

Tras llamar a la cota en la función principal llamamos a la generalización.
Esta generalización va modificando inf y sup para obtener el minimo poder, que será la mitad de ambos.
cuando la generalización acaba, devuelve el minimo.

(4) An�lisis de la complejidad del algoritmo
T(base) = n * c_0
t(n) = c_1 + T(n/2)

la complejidad por lo tanto es O(n^2)

*/
bool vence(int enemigos[], int n, int max_duelos, int power)
{ //igual que el mono del ejercicio 5 pero con más violencia
    int i = 0, combate = 1, suma = 0;
    while (i < n && (enemigos[i] <= power) && (combate <= max_duelos))
    { // si se supera el numero de combates o el numero de combatiendes, salimos del bucle
        suma += enemigos[i];
        if (suma > power)
        { // si la suma de los combates es mayor al poder, sumamos un combate más
            suma = enemigos[i];
            combate++;
        }
        i++;
    }
    return i == n && combate <= max_duelos;
}

void acota(int enemigos[], int n, int max_duelos, int &inf, int &sup)
{
    inf = 0;
    sup = 2;
    while (!vence(enemigos, n, max_duelos, sup))
    {
        inf = sup;
        sup *= 2;
    }
}

int calcula_poder(int enemigos[], int n, int max_duelos, int inf, int sup)
{
    int mid = (inf + sup) / 2;
    if (vence(enemigos, n, max_duelos, mid))
    { // comprobamos si m es el poder que queremos
        if (!vence(enemigos, n, max_duelos, mid - 1))
        { // si m es valido, miramos si es el minimo
            return mid;
        }
        else
        {
            return calcula_poder(enemigos, n, max_duelos, inf, mid - 1); // si no es el minimo, disminuimos el poder, too much mamadisimo
        }
    }
    else
        return calcula_poder(enemigos, n, max_duelos, mid + 1, sup); // si es demasiado pequeño, aumentamos el poder
}

int min_poder(int enemigos[], int n, int max_duelos)
{
    int inf;
    int sup;
    acota(enemigos, n, max_duelos, inf, sup);
    return calcula_poder(enemigos, n, max_duelos, inf, sup);
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
