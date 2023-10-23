#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>

using namespace std;

#define MAX 100
/* Plantilla de la clase Arreglo. Se incluyen sólo los métodos requeridos para la aplicación de la operación de búsqueda. */
template <class T> class Arreglo {
	private:
		T Datos[MAX];
		int Tam;

	public:
		Arreglo();
		void Lectura();
		void Escribe();
		int RegresaTam();
		T RegresaValor(int);
};
/* Declaración del método constructor. Inicializa el número actual de elementos en 0. */
template <class T> Arreglo<T>::Arreglo() { Tam = 0; }
/* Método que permite leer el número de elementos que se van a almacenar y el valor de cada uno de ellos. Valida que el total de elementos sea al menos 1 y que no supere el máximo especificado. */
template <class T> void Arreglo<T>::Lectura() {
	int Indice;

	do {
		cout <<"\n\n Ingrese número de datos a guardar : ";
		cin >> Tam;
	} while ((Tam<1) || (Tam > MAX));
	for (Indice = 0; Indice < Tam; Indice++) {
		cout <<"\nIngrese el "<< Indice + 1 <<" dato : ";
		cin >> Datos[Indice];
	}
}
/* Método que despliega en pantalla los valores almacenados en el arreglo. */
template <class T> void Arreglo<T>::Escribe() {
	int Indice;
	if (Tam > 0) {
	cout <<"\n Impresión de datos\n";
	for (Indice = 0; Indice < Tam; Indice++)
		cout << '\t' << Datos[Indice];
	} else
	cout << "\nNo hay elementos registrados.";
}
/* Método que permite a usuarios externos a la clase conocer el total de elementos guardados en el arreglo. */
template <class T> int Arreglo<T>::RegresaTam() { return Tam; }
/* Método que permite a usuarios externos a la clase conocer el dato almacenado en cierta casilla del arreglo. Recibe como parámetro un entero y regresa como resultado el valor almacenado en la posición indicada por dicho número. */
template <class T> T Arreglo<T>::RegresaValor(int Indice) {
	return Datos[Indice];
}

#endif
