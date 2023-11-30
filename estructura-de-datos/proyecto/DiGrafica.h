/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juarez Rubio Alan Yair
Hernandez Hurtado  Leonel
*/ 
#ifndef DIGRAFICA_
#define DIGRAFICA_

#include <iostream>

using namespace std;

#define MAX 10

// Función auxiliar que obtiene el valor más pequeño de dos dados como parámetros. La utiliza el método de Dijkstra.
inline int Minimo(int Val1, int Val2) {
    int Min = Val1;
	if (Val2 < Min) { Min = Val2; }
	return Min;
}

// Definición de la plantilla de la clase DiGrafica. Se incluyen como atributos, además de la matriz de adyacencia, el número de vértices y su nombre, otros elementos que son utilizados en los mÃ©todos.
template <class T>
class DiGrafica {
	private:
		// Declaracón del arreglo donde se almacenan las distancias entre los vértices.
		T MatAdy[MAX][MAX];
		int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX], VerInt[MAX][MAX];

	public:
		// Método constructor y métodos auxiliares para leer la información relacionada a la gráfica e imprimir los resultados obtenidos al aplicar los demás métodos.
		DiGrafica();
		void Lee();
		void Imprime(int);
		
		int getNumeroVertices();
		T* getVertices();
		T* getDistMin();
		T** getCerTran();
		T** getMatAdy();
		T** getVerInt();
		
		// Métodos que recorren una gráfica dirigida, encontrando caminos de distancias minimas.
		void Warshall();
		void Floyd();
		void FloydVerInt();
		int Dijkstra();
		void pausarPantalla();
		
};

#endif
