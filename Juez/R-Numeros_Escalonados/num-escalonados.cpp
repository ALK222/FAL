/*
NOMBRE Y APELLIDOS: ALEJANDRO BARRACHINA ARGUDO


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
 n <t_num> entrada= numero a analizar
 c <t_num> salida = numero total de escalonados menor que n
 es_escalonado <bool> salida = será cierto siu n es alternado, falso en cualquier otro caso
 d_anterior <t_num> salida = digito anterior al comprobado

(2) Análisis de casos:

(2.1) Casos base
n <= 9; c = n

(2.2) Casos recursivos
c > 9;
resolvemos el problema para n/10.

si n es escalonado, {calculos no hechos porque faltan tocar los numero para que de el resultado correcto)
si n no es escalonado, {calculos no hechos porque faltan tocar los numero para que de el resultado correcto)

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

la generalización se invoca tras inicializar las variables, en cuanto finaliza la generalización se tiene el numero deseado.

(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinación de las ecuaciones de recurrencia para la generalización
C_1 = Coste de inicio y fin
C_2 coste recursivo

(4.2) Resolución utilizando los patrones vistos en clase

Por el método de despliegue tenemos que : C_1 + C_2 = C_1 + C_2 + C_2 +..(tantas veces como digitos) C_2

(4.3) Determinación justificada de la complejidad del algoritmo final.

Por los patrones de resolucion de ecuaciones de clase, la funcion es O(n)



*/

t_num subir(t_num num)
{
    return (num == 9) ? 0 : num + 1;
}

t_num bajar(t_num num)
{
    return (num == 0) ? 9 : num - 1;
}

void cuenta_escalonados(t_num n, t_num &c, bool &es_escalonado, t_num &d_ant)
{
    if (n < 10)
    {
        c = n;
        es_escalonado = true;
        d_ant = n;
    }
    else
    {
        t_num last = n % 10;
        t_num num = n / 10;
        cuenta_escalonados(num, c, es_escalonado, d_ant);
        c *= 2;
        c += 8;

        if (es_escalonado)
        {
            if (last > subir(d_ant))
            {
                ++c;
            }
            if (last > bajar(d_ant))
            {
                ++c;
            }
        }
        /*es_escalonado = es_escalonado && (!(d_ant == subir(last) || d_ant == bajar(last)));*/
        if (es_escalonado)
        {
            if (!(last == subir(d_ant) || (last == bajar(d_ant))))
            {
                es_escalonado = false;
            }
        }
        d_ant = last;
    }
}

t_num num_escalonados(t_num n)
{
    // A IMPLEMENTAR
    t_num c;
    bool es_escalonado = false;
    t_num d_ant;
    if (n < 10)
    {
        return n;
    }
    cuenta_escalonados(n, c, es_escalonado, d_ant);

    return c;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

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
        cout << num_escalonados((t_num)n) << endl;
        return true;
    }
}

int main()
{
    while (procesa_caso())
        ;
}
