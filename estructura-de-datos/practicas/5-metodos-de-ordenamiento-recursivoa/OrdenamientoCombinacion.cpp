/*
Castellanos Ramirez Gustavo Fabian
GuzmÃ¡n Zavala Daniel
Juarez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

// Fig 19.6: OrdenamientoCombinacion.cpp
// DefiniciÃ³n de las funciones miembro de la clase OrdenamientoCombinacion.

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib> // prototipos para las funciones srand y rand
using std::rand;
using std::srand;

#include <ctime> // prototipo para la funciÃ³n time
using std::time;

#include "OrdenamientoCombinacion.h" // definiciÃ³n de la clase OrdenamientoCombinacion

// el constructor llena el vector con enteros aleatorios
OrdenamientoCombinacion::OrdenamientoCombinacion(int tamanioVector) {
	tamanio = (tamanioVector > 0 ? tamanioVector : 10); // valida tamanioVector
	srand(time(
			0)); // siempra el generador de nÃºmeros aleatorios usando la hora actual

	// llena el vector con valores int aleatorios en el rango de 10 a 99
	for (int i = 0; i < tamanio; i++)
		datos.push_back(10 + rand() % 90);
} // fin del constructor de OrdenamientoCombinacion

// divide el vector, ordena los subvectores y los combina en un vector ordenado
void OrdenamientoCombinacion::ordenar(int opcion) {
	ordenarSubVector(0, tamanio - 1,
									 opcion); // ordena todo el vector en forma recursiva
} // fin de la funciÃ³n ordenar

// funciÃ³n recursiva para ordenar los subvectores
void OrdenamientoCombinacion::ordenarSubVector(int inferior, int superior, int opcion) {
	// prueba el caso base; el tamaÃ±o del vector es igual a 1
	if ((superior - inferior) >= 1) // si no es el caso base
	{
		int medio1 =
				(inferior + superior) / 2; // calcula el elemento medio del vector
		int medio2 = medio1 + 1; // calcula el siguiente elemento mÃ¡s arriba

		// imprime el paso de divisiÃ³n
		cout << " division: ";
		mostrarSubVector(inferior, superior);
		cout << endl << " ";
		mostrarSubVector(inferior, medio1);
		cout << endl << " ";
		mostrarSubVector(medio2, superior);
		cout << endl << endl;

		// divide el vector a la mitad; ordena cada mitad (llamadas recursivas)
		ordenarSubVector(inferior, medio1, opcion); // primera mitad del vector
		ordenarSubVector(medio2, superior, opcion); // segunda mitad del vector

		// combina dos vectores ordenados despuÃ©s de que regresan las llamadas de
		// divisiÃ³n
		combinar(inferior, medio1, medio2, superior, opcion);
	} // fin de if
} // fin de la funciÃ³n ordenarSubVector

// combina dos subvectores ordenados en un subvector ordenado
void OrdenamientoCombinacion::combinar(int izquierdo, int medio1, int medio2,
																			 int derecho, int opcion) {
	int indiceIzq = izquierdo;			 // Ã­ndice en el subvector izquierdo
	int indiceDer = medio2;					// Ã­ndice en el subvector derecho
	int indiceCombinado = izquierdo; // Ã­ndice en vector de trabajo temporal
	vector<int> combinado(tamanio);	// vector de trabajo

	// imprime dos subvectores antes de combinar
	cout << "combinacion:";
	mostrarSubVector(izquierdo, medio1);
	cout << endl << "";
	mostrarSubVector(medio2, derecho);
	cout << endl;
	if (opcion == 1) {
		// combina los vectores hasta llegar al final de uno de ellos
		while (indiceIzq <= medio1 && indiceDer <= derecho) {
			// coloca el menor de dos elementos actuales en el resultado
			// y se desplaza al siguiente espacio en el vector
			if (datos[indiceIzq] <= datos[indiceDer])
				combinado[indiceCombinado++] = datos[indiceIzq++];
			else
				combinado[indiceCombinado++] = datos[indiceDer++];
		} // fin de while

		if (indiceIzq == medio2) // si estÃ¡ al final del vector izquierdo
		{
			while (indiceDer <= derecho) // copia en el resto del vector derecho
				combinado[indiceCombinado++] = datos[indiceDer++];
		}		// fin de if
		else // al final del vector derecho
		{
			while (indiceIzq <= medio1) // copia en el resto del vector izquierdo
				combinado[indiceCombinado++] = datos[indiceIzq++];
		} // fin de else

		// copia los valores de vuelta al vector original
		for (int i = izquierdo; i <= derecho; i++)
			datos[i] = combinado[i];

		// imprime el vector combinado
		cout << " ";
		mostrarSubVector(izquierdo, derecho);
		cout << endl << endl;
	}
	if (opcion == 2) {
		// combina los vectores hasta llegar al final de uno de ellos
		while (indiceIzq <= medio1 && indiceDer <= derecho) {
			// coloca el menor de dos elementos actuales en el resultado
			// y se desplaza al siguiente espacio en el vector
			if (datos[indiceIzq] >= datos[indiceDer])
				combinado[indiceCombinado++] = datos[indiceIzq++];
			else
				combinado[indiceCombinado++] = datos[indiceDer++];
		} // fin de while

		if (indiceIzq == medio2) // si estÃ¡ al final del vector izquierdo
		{
			while (indiceDer <= derecho) // copia en el resto del vector derecho
				combinado[indiceCombinado++] = datos[indiceDer++];
		}		// fin de if
		else // al final del vector derecho
		{
			while (indiceIzq <= medio1) // copia en el resto del vector izquierdo
				combinado[indiceCombinado++] = datos[indiceIzq++];
		} // fin de else

		// copia los valores de vuelta al vector original
		for (int i = izquierdo; i <= derecho; i++)
			datos[i] = combinado[i];

		// imprime el vector combinado
		cout << " ";
		mostrarSubVector(izquierdo, derecho);
		cout << endl << endl;
	}
} // fin de la funciÃ³n combinar

// muestra los elementos en el vector
void OrdenamientoCombinacion::mostrarElementos() const {
	mostrarSubVector(0, tamanio - 1);
} // fin de la funciÃ³n mostrarElementos

// muestra ciertos valores en el vector
void OrdenamientoCombinacion::mostrarSubVector(int inferior,
																							 int superior) const {
	// imprime espacios para alineaciÃ³n
	for (int i = 0; i < inferior; i++)
		cout << " ";

	// imprime elementos izquierdo en el vector
	for (int i = inferior; i <= superior; i++)
		cout << " " << datos[i];
} // fin de la funciÃ³n mostrarSubVector