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

  *** RESPONDE AQUI AL APARTADO 1
  *
  *<Int> masSig: entrada -> almacena la suma de los digitos mas significativos
  *<Int> menosSig: entrada -> almacena la suma de los digitos menos significativos
  *<unsigned int> m: entrada -> almacena el numero con el ultimo digito quitado
  *<unsigned int> y: entrada -> almacena el numero con el primer digito quitado
  *<unsigned int> m: entrada -> almacena el numero con el ultimo digito quitado


(2) An�lisis de casos:

(2.1) Casos base

  *** RESPONDE AQUI AL APARTADO 2.1
  Sum i: 0<=i<0. Solucion NO
  Sum i: 0 < i <= 1. Solucion SI siempre que el numero sea distinto de 0

(2.2) Casos recursivos

  *** RESPONDE AQUI AL APARTADO 2.2
  SUM i: 0 <=i<n : x = (sum_digitos(Mas_sig, i) % i == 0) Y (suma_digitos(Menos_sig, i) % i == 0)


(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

  *** RESPONDE AQUI AL APARTADO 3
  *
  *El algortimo calcula la suma de los numeros mas y menos significativos de cada digito que observemos almacenandolo en dos variables distintas
  *
  *Se invoca la generalacización con dos numeros distintos que almacenarán las dos sumas inicializados a 0.
  *
  *la propia generalización nos da el resultado final


*/

bool suma(int &masSig, int &menosSig, unsigned int m, unsigned int y, int count, bool fin)
{
    int ult_digit = m % 10;

    if (fin)
    {
        count /= 10;
        int x = y / count;
        if (x == 0)
        {
            return false;
        }
        if (masSig % x == 0)
        {
            masSig += x;
            if (y % count == 0)
            {
                return true;
            }
            else
            {
                return suma(masSig, menosSig, m / 10, y % count, count, true);
            }
        }
        else
        {
            return false;
        }
    }
    if (ult_digit == 0)
    {
        return false;
    }
    if (menosSig % ult_digit == 0)
    {
        count *= 10;
        menosSig += ult_digit;
        if (m / 10 == 0)
        {
            return suma(masSig, menosSig, m / 10, y, count, true);
        }
        else
        {

            return suma(masSig, menosSig, m / 10, y, count, false);
        }
    }
    else
    {
        return false;
    }
}

bool es_interesante(unsigned int n)
{
    int masSig = 0;
    int menosSig = 0;
    return suma(masSig, menosSig, n, n, 1, false);
}

void ejecuta_caso()
{
    unsigned int n;
    cin >> n;
    if (es_interesante(n))
    {
        cout << "SI" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    unsigned int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; i++)
    {
        ejecuta_caso();
    }
}
