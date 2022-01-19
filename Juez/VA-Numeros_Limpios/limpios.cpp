

#include <iostream>

using namespace std;

typedef unsigned long long t_num;

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

void resolver(unsigned short d, unsigned short alpha, t_num n, unsigned int s, t_num nextN, unsigned int sumaSAct, unsigned int cantidad, int &contador)
{
    if (sumaSAct == s && nextN != 0) // Llegamos a la suma necesaria y el numero es distinto de 0
    {
        ++contador;
    }
    else
    {
        unsigned int nextDig = 1;
        bool cont = true;
        while (cont)
        {
            if (nextDig > 9 || sumaSAct + nextDig > s || (nextN * 10) + nextDig >= n) // si llegamos nextDig = 9, hemos terminado todos los digitos, igual con las sumas totales y parciales
            {
                cont = false;
            }
            else
            {
                if (nextDig != d)
                {
                    resolver(d, alpha, n, s, (nextN * 10) + nextDig, sumaSAct + nextDig, 0, contador);
                }
                else if (cantidad + 1 < alpha) // comprobamos que aún no hemos pasado del tamaño pedido
                {
                    resolver(d, alpha, n, s, (nextN * 10) + nextDig, sumaSAct + nextDig, cantidad + 1, contador);
                }
                nextDig++;
            }
        }
    }
}

int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s)
{
    // PUNTO DE ENTRADA DEL ALGORITMO

    int cont = 0;
    resolver(d, alpha, n, s, 0, 0, 0, cont);
    return cont;
}

bool ejecuta_caso()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return false;
    }
    else
    {
        unsigned short alpha;
        unsigned int s;
        t_num n;
        cin >> alpha >> s >> n;
        cout << num_limpios(d, alpha, n, s) << endl;
        return true;
    }
}

int main()
{
    while (ejecuta_caso())
        ;
}
