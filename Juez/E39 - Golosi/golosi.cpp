/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>

using namespace std;

/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No 
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada de la especificaci�n y el dise�o sistem�tico
del mismo.
*/


/*
   vcs: vector de valores cal�ricos.
   vns: vector de valores nutricionales.
   n: N�mero de chuches.
   u: Umbral cal�rico
*/
/*
PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  no_negativos(a,n) = PARATODO i: 0<=i<=n: a[i]>=0
  no_exceden (a,n,u) = PARATODO i<=i<n: a[i]<=u
	P={0< n< min(tam(vcs), tam(vns)) && no_negativos(vcs,n) && no_negativos(vns,n) && no_excede(vcs,n,u)}
*/
int mejor_cajita(int vcs[], int vns[], int n, int u);
/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
		max_vn= max i,j: 0<=i<=j<n &&suma(vcs,i,j)<=u: suma(vns,i,j)
		suma(a,i,j)= SUMA u: i<=u<=j: a[u]
		Q={max_vn(vns,vcs,n,u)}
*/

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables
		
		suma_n	<int>	->	guarda la suma de vns actual
		suma_c	<int>	->	guarda la suma de vnc actual
		i		<int>	->	inicio de ventana
		j		<int>	->	pos siguente en ventana
		resul	<int>	->	guarda la mejor suma de vns y sirve de resultado

Paso 2. Invariante
		ventana_completa(vcs,i,j,u) = (0<i && j<n: suma(vcs,i-1,j)>u)

		max_vn(vns,vnc,j,u,resul) && suma(vcs,i,j-1) && suma (vns,i,j-1) && ventana_compleya(vcs,i,j,u) 0<=i<=j<=n

Paso 3. Inicializaci�n
		
		int suma_n = vns[0];
		int suma_c = vcs[0];
		int i = 0;
		int j = 1;
		int resul = vns[0];

Paso 4. Condici�n del bucle, y c�digo tras el bucle.
		
		condicion		->	j<n
		tras el bucle	->	No hace falta

Paso 5. Cuerpo del bucle
		Caso 1 (suma_c+vcs[j]<=u):
			suma_c+=vcs[j];
			suma_n+=vns[j];
			j++;
			if(suma_n>resul){
				resul = suma_n;
			}

		Caso 2 (suma_c+vcs[j]>u):
			suma_c -=vcs[i];
			suma_n -=vns[i];
			i++;

Paso 6. Justificaci�n de que el algoritmo siempre termina.
		2n - (i + j)

Paso 7. Complejidad:
		Como mucho el algoritmo da 2n vueltas, cada vuelta es Theta(1),
		Por tanto el coste del algoritmo es Theta(n)

*/
int mejor_cajita(int vcs[], int vns[], int n, int u) {
	// A IMPLEMENTAR: Devolver el mayor valor nutricionales
	// que puede conseguirse sin superar el umbral cal�rico.
	// Recuerda: vcs[n]: vector de valores cal�ricos,
	//           vns[n]: vector de valores nutricionales,
	//           u: umbral cal�rico
	//           Debe devolverse el m�ximo valor nutricional 
	//           que puede conseguirse.
	int suma_n = vns[0];
		int suma_c = vcs[0];
		int i = 0;
		int j = 1;
		int resul = vns[0];
	while (j < n) {					//Mientras queden chuches
		if (suma_c+vcs[j]<=u) {
			suma_c+=vcs[j];
			suma_n+=vns[j];
			j++;
			if(suma_n>resul){
				resul = suma_n;
			}
		}
		else {
			suma_c -=vcs[i];
			suma_n -=vns[i];
			i++;
		}
	}
	return resul;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const static int MAX_CHUCHES = 1000000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false; 
	else {
		static int calorias[MAX_CHUCHES];
		static int nutricionales[MAX_CHUCHES];
		for (int i = 0; i < n; i++) {
			cin >> calorias[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> nutricionales[i];
		}
		int umbral;
		cin >> umbral;
		cout << mejor_cajita(calorias, nutricionales, n, umbral) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}