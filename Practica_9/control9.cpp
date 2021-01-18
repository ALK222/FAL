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

/* Estructura utilizada para almacenar la información de un tema */
typedef struct
{
    float tiempo_req; // tiempo requerido para estudiar el tema
    float nota_prim;  // aportación a la nota de la primera parte
    float nota_sec;   // aportación a la nota de la segunda parte
} tInfoTema;

/*
DISEÑO DEL ALGORITMO

Para superar este ejercicio, aparte de programar el algoritmo, debes
describir aqui detalladamente su diseño (parámetros y variables utilizados,
y su cometido, cometido de los resultados devueltos por las funciones,
idea general del algoritmo, estructura de las soluciones,
análisis de casos, acciones realizadas para cada caso...)

el algoritmo utiliza una generalización en calcula_puntuación

VARIABLES:

-temario_actual para saber que tema se está comprobando
-nota_primero para saber la nota del primer examen
-nota_segundo para saber la nota del segundoe examen
-nota_max para saber la nota final maxima
-tiempo_usado para saber el tiempo que se ha invertido en estudiar

la generalizacion calcula el mejor caso posible y de ahi se saca el resultado final dependiendo de la nota

en cada paso de la vuelta atrás si alguna de las notas parciales es menor que 5, la nota maxima no se actualiza



*/
const unsigned int MAX_TEMAS = 20;

void actualizar_mejor_nota(const float prim_nota, const float seg_nota, float &max_nota)
{
    max_nota = (prim_nota + seg_nota) / 2;
}

void calcular_nota(const tInfoTema info_temas[], int temario_actual, float tiempo_disponible, float &nota_primero, float &nota_segundo, float &nota_max, float &tiempo_usado, int total_temas)
{
    if (temario_actual == 0)
    {
        if ((nota_primero + nota_segundo) / 2 > nota_max && nota_primero >= 5 && nota_segundo >= 5)
        {
            actualizar_mejor_nota(nota_primero, nota_segundo, nota_max);
        }
    }
    else
    {
        calcular_nota(info_temas, temario_actual - 1, tiempo_disponible, nota_primero, nota_segundo, nota_max, tiempo_usado, total_temas);
        if (tiempo_usado + info_temas[temario_actual].tiempo_req <= tiempo_disponible)
        {
            nota_primero += info_temas[temario_actual].nota_prim;
            nota_segundo += info_temas[temario_actual].nota_sec;
            tiempo_usado += info_temas[temario_actual].tiempo_req;
            calcular_nota(info_temas, temario_actual - 1, tiempo_disponible, nota_primero, nota_segundo, nota_max, tiempo_usado, total_temas);
            nota_primero -= info_temas[temario_actual].nota_prim;
            nota_segundo -= info_temas[temario_actual].nota_sec;
            tiempo_usado -= info_temas[temario_actual].tiempo_req;
        }
    }
}

/* temas: Información sobre los temas de los que consta el examen (ver tInfoTema)
   num_temas: Numero de temas de los que consta el examen -su información aparece
              al principio de info_temas
   tiempo_disponible: Tiempo total disponible para realizar el examen.
   Valor devuelto: La puntuación media máxima que se puede conseguir, o -1 si no
                   es posible aprobar el examen */
float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible)
{
    /* ESTA FUNCIÓN SERÁ EL PUNTO DE ENTRADA AL ALGORITMO. Puedes, después, utilizar las
       funciones auxiliares que consideres oportuno, pero debes incluir la justificación para ello
       en el comentario de descripción detallado del diseño de dicho algoritmo */
    int temario_actual = num_temas - 1;
    float nota_primero = 0;
    float nota_segundo = 0;
    float nota_max = -1;
    float tiempo_usado = 0;
    calcular_nota(info_temas, temario_actual, tiempo_disponible, nota_primero, nota_segundo, nota_max, tiempo_usado, num_temas);
    return nota_max >= 10 ? 10 : nota_max;
}

/* Código para leer y ejecutar casos de prueba: no debe modificarse */

bool procesa_caso()
{
    int num_temas;
    tInfoTema info_temas[MAX_TEMAS];
    cin >> num_temas;
    if (num_temas != -1)
    {
        float tiempo_disponible;
        cin >> tiempo_disponible;
        for (int i = 0; i < num_temas; i++)
        {
            cin >> info_temas[i].tiempo_req;
            cin >> info_temas[i].nota_prim;
            cin >> info_temas[i].nota_sec;
        }
        cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (procesa_caso())
        ;
}
