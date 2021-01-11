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

const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
                                      // Representaci�n de la matriz de afinidades
typedef struct
{
    unsigned int n_clientes;                             // numero de clientes.
    unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES]; // la matriz se almacena en las 'n_clientes' primeras filas,
                                                         // 'n_clientes' primeras columnas
} tMatrizAfinidad;

/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

<Int[]> parejas: array ordenador con las mejores parejas
<Int[]> mejores_parejas: array con las mejores parejas antes de terminar la generalizacion, nos sirve para obtener mejores valores en el array final.
<bool> hay_parejas: para saber si todo el mundo está emparejado


(2) �C�mo son las soluciones parciales de este problema?
las soluciones parciales se traducen en el orden del array mejores_parejas, que nos da los valores para la mejor pareja posible

(3) �Cu�ndo una soluci�n parcial es viable?

al llegar al ultimo cliente, cuando mejores_parejas supera a parejas en valor total

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?
al hacer la suma de las afinidades de las parejas de forma [i][i+1] aumentando i en 2 para no repetir individuos

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

al comparar que parejas tenga un valor mayor que mejores_parejas

(6) An�lisis de casos

(6.1) Caso(s) base

Si num_clientes = 2 => son la mejor pareja en caso de que haya afinidad, y la suma de su afinidad es la afinidad total de emparejamiento

(6.2) Caso(s) recursivos

si num_clientes > 2 : comprobamos todas las parejas posibles para un cliente n, y seleccionamos la mejor que no haya sido utilizada ya.

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.

al salir de la generalización tenemos un array ordenado con los individuos de las parejas.
Para obtener el resultado tenemos que sumar sus afinidades dos a dos, es decir [i][i+1] e incrementamos i en 2.

*/
bool contiene(int parejas[MAX_CLIENTES], unsigned int n, int cliente)
{
    bool enc = false;
    int c = 0;
    while (!enc && c < n)
    {
        enc = parejas[c] == cliente;
        c++;
    }
    return enc;
}

void actualiza_parejas(int parejas[MAX_CLIENTES], int mejor_parejas[MAX_CLIENTES], int total_clientes)
{
    for (int client = 0; client < total_clientes; client++)
    {
        mejor_parejas[client] = parejas[client];
    }
}

int afinidad(const unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES], int parejas[MAX_CLIENTES], int total_clientes)
{
    int k = 0;
    for (int i = 1; i < total_clientes; i += 2)
    {
        k += afinidades[parejas[i]][parejas[i - 1]];
    }
    return k;
}

void encuentra_pareja(const unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES], unsigned int num_cliente, int parejas[MAX_CLIENTES], bool &hay_pareja, int mejor_pareja[MAX_CLIENTES], int total_clientes)
{
    if (num_cliente == total_clientes)
    {
        if (!hay_pareja || (afinidad(afinidades, parejas, total_clientes) > afinidad(afinidades, mejor_pareja, total_clientes)))
        {
            actualiza_parejas(parejas, mejor_pareja, total_clientes);
            hay_pareja = true;
        }
    }
    else
    {
        for (int cliente = 0; cliente < total_clientes; cliente++)
        {
            if (!contiene(parejas, num_cliente, cliente))
            {
                parejas[num_cliente] = cliente;
                encuentra_pareja(afinidades, num_cliente + 1, parejas, hay_pareja, mejor_pareja, total_clientes);
            }
        }
    }
}

int maxima_afinidad(const tMatrizAfinidad &as)
{
    // Punto de entrada al algoritmo: as representa la matriz de afinidades
    // (ver definici�n de tMatrizAfinidad). Una vez finalizado el algoritmo,
    // deber� devolverse el valor pedido. Pueden definirse todas las
    // funciones auxiliares que se considere oportuno.
    int mejor_pareja[MAX_CLIENTES];
    int total_parejas[MAX_CLIENTES];
    bool hay_pareja = false;
    total_parejas[0] = 0;
    encuentra_pareja(as.afinidades, 1, total_parejas, hay_pareja, mejor_pareja, as.n_clientes);
    unsigned int total = 0;
    unsigned int i = 1;
    while (hay_pareja && i <= as.n_clientes - 1)
    {
        if (as.afinidades[mejor_pareja[i]][mejor_pareja[i - 1]] <= 0 || as.afinidades[mejor_pareja[i - 1]][mejor_pareja[i]] <= 0)
        {
            hay_pareja = false;
        }
        total += as.afinidades[mejor_pareja[i]][mejor_pareja[i - 1]] + as.afinidades[mejor_pareja[i - 1]][mejor_pareja[i]];
        i += 2;
    }
    return hay_pareja && as.n_clientes % 2 == 0 ? total : 0;
}

void ejecuta_caso()
{
    tMatrizAfinidad as;
    cin >> as.n_clientes;
    for (unsigned int i = 0; i < as.n_clientes; i++)
    {
        for (unsigned int j = 0; j < as.n_clientes; j++)
        {
            cin >> as.afinidades[i][j];
        }
    }
    cout << maxima_afinidad(as) << endl;
}

int main()
{
    unsigned int num_casos;
    cin >> num_casos;
    for (unsigned int i = 0; i < num_casos; i++)
    {
        ejecuta_caso();
    }
}
