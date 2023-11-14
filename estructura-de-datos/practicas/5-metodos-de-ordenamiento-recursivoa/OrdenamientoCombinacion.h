/*
Castellanos Ramírez Gustavo Fabián
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

#ifndef ORDENAMIENTOCOMBINACION_H_INCLUDED
#define ORDENAMIENTOCOMBINACION_H_INCLUDED
// Fig 19.5: OrdenamientoCombinacion.h
// Clase que crea un vector lleno de enteros aleatorios.
// Proporciona una función para ordenar el vector con el ordenamiento por
// combinación.
#include <vector>
using std::vector;

// Definición de la clase OrdenamientoCombinacion
class OrdenamientoCombinacion {
	public:
		OrdenamientoCombinacion(int); // el constructor inicializa el vector
		void ordenar(int); // ordena el vector usando el ordenamiento por combinación
		void mostrarElementos() const; // muestra los elementos del vector

	private:
		int tamanio; 							// tamaño del vector
		vector<int> datos;						// vector de valores int
		void ordenarSubVector(int, int, int);	// ordena el subvector
		void combinar(int, int, int, int, int); // combina dos vectores ordenados
		void mostrarSubVector(int, int) const;	// muestra el subvector
};

#endif // ORDENAMIENTOCOMBINACION_H_INCLUDED
