/*
Castellanos Ramirez Gustavo Fabian
Guzm�n Zavala Daniel
Juarez Rubio Alan Yair
Hernandez Hurtado  Leonel
*/ 
#ifndef DIGRAFICA_
#define DIGRAFICA_

#include <iostream>

using namespace std;

#define MAX 10

// Funci�n auxiliar que obtiene el valor m�s peque�o de dos dados como par�metros. La utiliza el m�todo de Dijkstra.
inline int Minimo(int Val1, int Val2) {
    int Min = Val1;
	if (Val2 < Min) { Min = Val2; }
	return Min;
}

// Definici�n de la plantilla de la clase DiGrafica. Se incluyen como atributos, adem�s de la matriz de adyacencia, el n�mero de v�rtices y su nombre, otros elementos que son utilizados en los métodos.
template <class T>
class DiGrafica {
	private:
		// Declarac�n del arreglo donde se almacenan las distancias entre los v�rtices.
		T MatAdy[MAX][MAX];
		int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX], VerInt[MAX][MAX];

	public:
		// M�todo constructor y m�todos auxiliares para leer la informaci�n relacionada a la gr�fica e imprimir los resultados obtenidos al aplicar los dem�s m�todos.
		DiGrafica();
		void Lee();
		void Imprime(int);
		
		int getNumeroVertices();
		T* getVertices();
		T* getDistMin();
		T** getCerTran();
		T** getMatAdy();
		T** getVerInt();
		
		// M�todos que recorren una gr�fica dirigida, encontrando caminos de distancias minimas.
		void Warshall();
		void Floyd();
		void FloydVerInt();
		int Dijkstra();
		void pausarPantalla();
		
};

#endif
