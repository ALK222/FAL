#include <iostream>
using namespace std;

const unsigned int MAX_NINIOS = 20; // maximo numero de ni�os
                                    // el n�mero de sitios siempre
                                    // ser� menor o igual que el
                                    // n�mero de ni�os

// Representaci�n de la matriz de satisfacciones
typedef struct
{
    int n_ninios;                    // numero de ni�os.
    int n_sitios;                    // numero de sitios
    int sat[MAX_NINIOS][MAX_NINIOS]; // la posici�n i,j representa la satisfaccion
                                     // que siente el ninio i si se le asigna el sitio j
} tMatrizSatisfacciones;

/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/

int calculoSatisfaccion(int listaSatisfaccion[MAX_NINIOS], int numKid, const int sat[MAX_NINIOS][MAX_NINIOS], int numHermano)
{
    int suma = 0;
    int malAsignado = 0;
    bool tenemosHermano = false;
    for (int i = 0; i < numKid; ++i)
    {
        // lista[i] = sitio
        if ((i % numKid) == listaSatisfaccion[i])
        {
            ++malAsignado;
        }
        if (listaSatisfaccion[numHermano] > 0)
        {
            tenemosHermano = true;
        }
        suma += sat[listaSatisfaccion[i]][i] > 0 ? sat[listaSatisfaccion[i]][i] : 0;
    }
    if (malAsignado >= numKid / 3)
    {
        return 0;
    }
    return !tenemosHermano ? 0 : suma;
}

void actualizaLista(int peorLista[], int mejorLista[], int numElementos)
{
    for (int i = 0; i < numElementos; ++i)
    {
        mejorLista[i] = peorLista[i];
    }
}

bool contiene(int sitios[MAX_NINIOS], unsigned int n, int sitio)
{
    bool enc = false;
    unsigned int alumno = 0;
    while (!enc && alumno < n)
    {
        enc = sitios[alumno] == sitio;
        alumno++;
    }
    return enc;
}

void encuentraSitios(const tMatrizSatisfacciones &sats, unsigned int sitioActual, int totalNinios[MAX_NINIOS], bool &haySitio, int mejorSitio[MAX_NINIOS], int hermano)
{
    if (sats.n_sitios == sitioActual)
    {
        if (!haySitio || calculoSatisfaccion(mejorSitio, sats.n_sitios, sats.sat, hermano) < calculoSatisfaccion(totalNinios, sats.n_ninios, sats.sat, hermano))
        {
            actualizaLista(totalNinios, mejorSitio, sats.n_sitios);
            haySitio = true;
        }
    }
    else
    {
        for (int kid = 0; kid < sats.n_sitios; ++kid)
        {
            if (sats.sat[sitioActual][kid] >= 0 && !contiene(totalNinios, kid, sitioActual))
            {
                totalNinios[kid] = sitioActual;
                encuentraSitios(sats, sitioActual + 1, totalNinios, haySitio, mejorSitio, hermano);
            }
        }
    }
}

int satisfaccion_maxima(const tMatrizSatisfacciones &sats, int h)
{
    // A IMPLEMENTAR

    int mejorSitio[MAX_NINIOS];
    int totalNinios[MAX_NINIOS];
    bool hay_sitio = false;
    encuentraSitios(sats, 0, totalNinios, hay_sitio, mejorSitio, h);

    return calculoSatisfaccion(mejorSitio, sats.n_sitios, sats.sat, h);
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso()
{
    tMatrizSatisfacciones sats;
    cin >> sats.n_ninios;
    if (sats.n_ninios != -1)
    {
        cin >> sats.n_sitios;
        int h;
        cin >> h;
        for (int sitio = 0; sitio < sats.n_sitios; sitio++)
        {
            for (int ninio = 0; ninio < sats.n_ninios; ninio++)
            {
                cin >> sats.sat[ninio][sitio];
            }
        }
        cout << satisfaccion_maxima(sats, h) << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (ejecuta_caso())
        ;
}
