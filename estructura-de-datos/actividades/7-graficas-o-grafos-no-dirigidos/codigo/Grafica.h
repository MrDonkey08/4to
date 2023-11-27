#ifndef GRAFICA_H
#define GRAFICA_H

#include <iostream>
#include <string>

using namespace std;

// Máximo número de vértices que maneja la clase Gráfica.
#define MAX 20

// Función auxiliar que obtiene el valor más pequeño de dos dados como parámetros. La utiliza el método de Kruskal.
inline int Minimo(int Val1, int Val2) {
	int Min = Val1;	
	if (Val2 < Min) { Min = Val2; }
	return Min;
}

// Función auxiliar que obtiene el valor más grande de dos dados como parámetros. La utiliza el método de Kruskal.
inline int Maximo(int Val1, int Val2) {
	int Max = Val1;	
	if (Val2 > Max) { Max = Val2; }
	return Max;
}

// Definición de la plantilla de la clase Grafica. Se incluyen como atributos la matriz de adyacencia (MatAdy), el total de vértices (NumVer) y sus nombres (Vertices).
template <class T>
class Grafica {
	private:
		T MatAdy[MAX][MAX];
		int NumVer, Vertices[MAX];

	public:
		Grafica();
		void Lee();
		void Imprime();
		// Métodos que calculan el árbol abarcador de costo mínimo.
		void Prim();
		void Kruskal();
};

#endif