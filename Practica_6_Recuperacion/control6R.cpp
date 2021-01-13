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

typedef unsigned long long t_num;

/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.

- n <t_num> entrada: numero que queremos calcular
- c <t_num> salida: numero total de numeros singulares menores que n
- es_alternado <bool> salida: será cierto si n es alternado, falso en cualquier otro caso
- d_anterior <int> salida: digito anterior al que estamos comprobando

(2) Análisis de casos:

(2.1) Casos base
n <= 9:
c = n
es_singular = true
d_mas_sig = n

(2.2) Casos recursivos

c > 9

Resolvemos el problema para n - 1 / 10. sean c', es_alternado' y d_anterior' los resultados devueltos
d_anterior' = n / 10;

n es alterno:
- c = 5*c' + 10 + {d_anterior' si continuará siendo alterno || d_anterior' - 1 / 2 si dejará de ser alterno}

si n no es alterno:
- c = 5*c' + 10

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

la generalización se invoca tras inicializar la variable c que lleva la cuenta y la variable de control ok que nos dice si hay que sumar o no.

en cuanto finaliza la generalizacion, ya obtenemos en c el dato final buscado

*/

void cuenta_alternados(t_num n, t_num &c, bool &es_alternado, int &d_anterior)
{
    if (n <= 9)
    {
        c = n;
        es_alternado = true;
        d_anterior = n;
    }
    else
    {
        cuenta_alternados(n / 10, c, es_alternado, d_anterior);
        c--;
        c *= 5;
        c += 10;
        d_anterior = n % 10;

        if (es_alternado)
        {
            c += ((n / 10) % 2 != d_anterior % 2 ? (d_anterior / 2) : ((d_anterior + 1) / 2));
        }
        es_alternado = es_alternado && ((n / 10) % 2 != d_anterior % 2);
    }
}

t_num num_alternados(t_num n)
{
    // PUNTO ENTRADA AL ALGORITMO
    t_num c;
    bool es_alternado;
    int d_anterior;
    if (n <= 10)
    {
        return n;
    }
    cuenta_alternados(n, c, es_alternado, d_anterior);

    return c;
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización
si n <= 10, el algoritmo invierte un tiempo constante c_0
 si n > 10, el algoritmo invierte un tiempo constante c_1 en la división del numero, al que debe sumarse el tiempo que tarda en hacer la suma del numero final para n/10
 T(0) = C_0
 T(1) = C_1 + T(n/10), n > 10

(2) Resolución utilizando los patrones vistos en clase
Utilizando el metodo de desplegado:
T(n) = c_1 + T(n/10) = C-1 + C-1 + T(n/100) = k*c_1 + T(n/10^k)
el proceso acaba cuando n =< 10, es decir n = 10^k, por lo tanto k = log_2 n
(3) Determinación justificada de la complejidad del algoritmo final.
T(n) = log_10 n c_1 + c_1 + c_0
T(n) pertenece a O(log_n) con n potencia de 10

*/

bool procesa_caso()
{
    long long n;
    cin >> n;
    if (n == -1)
    {
        return false;
    }
    else
    {
        cout << num_alternados((t_num)n) << endl;
        return true;
    }
}

int main()
{
    while (procesa_caso())
        ;
}
