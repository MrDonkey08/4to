/*
Castellanos Ramirez Gustavo Fabian
Guzm�n Zavala Daniel
Juarez Rubio Alan Yair
Hernandez Hurtado  Leonel
*/
#include "DiGrafica.h"
#include <windows.h>
#include <limits>

// M�todo constructor. Inicializa el n�mero de vertices en cero y a la matriz de adyacencias MatAdy con un valor arbitrario muy grande (999), indicando que no existe camino entre los nodos correspondientes. Además, asigna ceros a los arreglos auxiliares que se usan en los métodos.
template <class T>
DiGrafica<T>::DiGrafica() {
	int Ind1, Ind2;

	for (Ind1 = 0; Ind1 < MAX; Ind1++) {
		DistMin[Ind1] = 0;
		for (Ind2 = 0; Ind2 < MAX; Ind2++) {
			if (Ind1 != Ind2) {
				MatAdy[Ind1][Ind2] = 999;
			} else {
				MatAdy[Ind1][Ind2] = 0;
			}

			CerTran[Ind1][Ind2] = 0;
			VerInt[Ind1][Ind2] = 0;
		}
	}
	NumVer = 0;
}

// M�todo que lee los datos de la gr�fica dirigida directamente del teclado.
template <class T>
void DiGrafica<T>::Lee() {
	int NumArcos, Indice, Origen, Destino;

	cout << "Ingrese n�mero de v�rtices de la gr�fica dirigida: ";
	cin >> NumVer;

	cout << "\n\nIngrese los nombres de los v�rtices de la gr�fica dirigida: ";

	cout << "\n";

	for (Indice = 0; Indice < NumVer; Indice++) {
		cout << "\n\t";
		cin >> Vertices[Indice];
	}

	pausarPantalla();
	system("cls");

	cout << "Total de aristas de la gr�fica dirigida: ";
	cin >> NumArcos;
	cout << "\n\n";

	for (Indice = 0; Indice < NumArcos; Indice++) {
		cout << "Ingrese v�rtice origen: ";
		cin >> Origen;

		cout << "\n\nIngrese v�rtice destino: ";
		cin >> Destino;

		cout << "\n\nDistancia de origen a destino: ";
		cin >> MatAdy[Origen - 1][Destino - 1];
	}



}

// M�todo que imprime informaci�n relacionada a una gr�fica dirigida. Por medio de un n�mero entero se selecciona lo que se va a imprimir, lo cual depende del m�todo aplicado para recorrer la digráfica.
template <class T>
void DiGrafica<T>::Imprime(int Opc) {
	int Ind1, Ind2;

	switch (Opc) {
		// Impresi�n de la matriz de adyacencia o de costos.
		case 0:
			cout << "Matriz de Adyacencia o de Costos: \n\n";

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				cout << Vertices[Ind1] << ": ";
				for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
					cout << MatAdy[Ind1][Ind2] << "\t";
				}
				cout << endl;
			}
			break;
		// Impresi�n de la cerradura transitiva correspondiente a la matriz de adyacencia. Se obtiene cuando se aplica el método de Warshall.
		case 1:
			cout << "Cerradura Transitiva de la Matriz de Adyacencia:" << endl << endl;

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				cout << Vertices[Ind1] << ":";
				for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
					cout << CerTran[Ind1][Ind2] << "\t";
				}
				cout << endl;
			}
			break;
		// Impresi�n de la matriz de distancias m�nimas entre todos los vertices de la grafica. Se obtiene por medio del método de Floyd.
		case 2:
			cout << "Matriz de Distancias M�nimas: " << endl << endl;

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				cout << Vertices[Ind1] << ":";
				for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
					cout << MatAdy[Ind1][Ind2] << "\t";
				}
			 cout << endl;
			}
			break;
		// Impresi�n de la matriz con los vertices intermedios usados para establecer los caminos de distancias mínimas. Esta impresión complementa la de la opción 2 cuando se aplica el método FloydVerInt.
		case 3:
			cout << "V�rtices Intermedios para lograr distancias m�nimas:" << endl << endl;

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
					cout << VerInt[Ind1][Ind2] << "\t";
				}
				cout << endl;
			}
			break;
		// Impresi�n de las distancias m�nimas entre un vertice y los dem�s. Se obtiene con el método de Dijkstra.
		case 4:
			cout << "\n\nDistancias m�nimas a partir del v�rtice:" << Vertices[0] << "\n\n";

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				cout << " " << DistMin[Ind1] << "\t" << endl;
			}
			break;

		default: break;
	}

}

// M�todo que determina si existe un camino entre cada uno de los  vertices de la gr�fica dirigida. CerTran es una matriz que representa  la cerradura transitiva de la matriz de adyacencia.

template <class T>
void DiGrafica<T>::Warshall() {
	int Ind1, Ind2, Ind3;
	// En la posici�n i,j de la matriz de adyacencia se asigna el valor 999 si no existe un camino directo del vertice i al vertice j. La cerradura transitiva se forma inicialmente a partir de la matriz de adyacencia.
	for (Ind1= 0; Ind1 < NumVer; Ind1  ++) {
		for (Ind2= 0; Ind2 < NumVer; Ind2  ++) {
			if (MatAdy[Ind1][Ind2] != 999) { CerTran[Ind1][Ind2]= 1; }
		}
	}

	// Se recorren todos los vetices para determinar si existe un camino entre �l y los dem�s, usando otros vertices como intermedios.
	for (Ind3= 0; Ind3 < NumVer; Ind3  ++) {
		for (Ind1= 0; Ind1 < NumVer; Ind1  ++) {
			for (Ind2= 0; Ind2 < NumVer; Ind2  ++) {
				CerTran[Ind1][Ind2] |=
				CerTran[Ind1][Ind3] &&
				CerTran[Ind3][Ind2];
			}
		}
	}
}

// M�todo que encuentra el camino de costo m�nimo entre todos los vertices de la gr�fica dirigida. Va modificando la matriz de adyacencia a medida que encuentra un camino m�s corto entre dos vértices.

template <class T> void DiGrafica<T>::Floyd() {
	int Ind1, Ind2, Ind3;
	for (Ind3 = 0; Ind3 < NumVer; Ind3++) {
		for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
			for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
				if ((MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2]) {
					MatAdy[Ind1][Ind2] = MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
				}
			}
		}
	}
}

// M�todo Floyd modificado para que, adem�s de encontrar las distancias minimas entre todos los vertices de una digr�fica, genere una matriz (VerInt) con los vertices intermedios utilizados para minimizar las distancias. Este método usa los atributos Vertices (arreglo que almacena los nombres de todos los vértices de la digráfica) y VerInt (arreglo donde se van guardando los vértices intermedios. Fue inicia- lizado en 0 en el método constructor).

template <class T>
void DiGrafica<T>::FloydVerInt() {
	int Ind1, Ind2, Ind3;

	for (Ind3= 0; Ind3 < NumVer; Ind3  ++) {
		for (Ind1= 0; Ind1 < NumVer; Ind1  ++) {
			for (Ind2= 0; Ind2 < NumVer; Ind2  ++) {
				if ((MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2]) {
					MatAdy[Ind1][Ind2] = MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
					VerInt[Ind1][Ind2]= Vertices[Ind3];
				}
			}
		}
	}
}

// Método que encuentra la distancia mínima entre un v�rtice dado y los dem�s v�rtices de una gr�fica dirigida. En el arreglo DistMin se almacenan las distancias m�nimas desde el v�rtice origen a cada uno de los otros nodos. Es decir DistMin[i] almacena la menor distancia entre el vértice origen y el vértice i.


template <class T>
int DiGrafica<T>::Dijkstra() {
	int Aux[MAX], VertInc[MAX], Ver1, Ver2, Ind1, Ind2, Menor, Band, Origen;
	// El arreglo VertInc se utiliza para guardar los vértices elegidos por ser los de la distancia m�nima. El arreglo Aux es un arreglo lógico que indica si el nodo de la posici�n i ya fue incluido en VertInc y de esta manera evitar ciclos.
	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		Aux[Ind1] = 0;
		VertInc[Ind1] = 0;
	}

	cout << "Ingrese v�rtice origen: ";
	cin >> Origen;
	Origen--;

	Aux[Origen - 1] = 1;
	// El arreglo donde se guardan las distancias m�nimas del Origen a los dem�s v�rtices se inicializa con los valores de la matriz de adyacencia.
	for (Ind1 = 0; Ind1 < NumVer; Ind1++){
		DistMin[Ind1] = MatAdy[Origen][Ind1];
	}

	for (Ind1 = 0; Ind1 << NumVer; Ind1++) {
		// Se busca el v�rtice Ver1 en (Vertices - VertInc) tal que DistMin[Ver1] sea el m�nimo valor. Se usa el 999 como valor inicial ya que es el elegido para indicar que no existe camino entre dos vértices.
		Menor = 999;

		for (Ind2 = 1; Ind2 < NumVer; Ind2++)
			if (DistMin[Ind2] < Menor && !Aux[Ind2]) {
				Ver1 = Ind2;
				Menor = DistMin[Ind2];
			}
		// Se incluye Ver1 a VertInc y se actualiza el arreglo Aux.
		VertInc[Ind1] = Ver1;
		Aux[Ver1] = 1;

		// Se busca la distancia minima para cada vértice Ver2 en (Vertices - VertInc).
		for (Ver2 = 1; Ver2 < NumVer; Ver2++) {
			Band = 0;

			Ind2 = 1;

			while (Ind2 < NumVer && !Band) {
				if (VertInc[Ind2] == Ver2) {
					Band = 1;
				} else {
					Ind2++;
				}
			}

			if (!Band) {
				DistMin[Ver2] = Minimo(DistMin[Ver2], DistMin[Ver1] + MatAdy[Ver1][Ver2]);
			}
		}
	}

	return Origen;
}

template <class T> void DiGrafica<T>:: pausarPantalla(){

	cout << "\n\nPresiona <enter> para continuar.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada despu�s de cada opci�n
    cin.get();
}

template <class T> int DiGrafica<T>::getNumeroVertices(){

	return NumVer;

}

template <class T> T* DiGrafica<T>::getVertices(){

	T* Matriz = new T[getNumeroVertices()];

	//Crear la matriz dinamicamente

	for (int i = 0; i < getNumeroVertices(); i++){

		Matriz[i] = Vertices[i];

	}

	return Matriz;

}

template <class T> T* DiGrafica<T>::getDistMin(){

	T* Matriz = new T[getNumeroVertices()];

	//Crear la matriz dinamicamente

	for (int i = 0; i < getNumeroVertices(); i++){

		Matriz[i] = DistMin[i];

	}

	return Matriz;

}

template <class T> T** DiGrafica<T>::getCerTran(){

	T** Matriz = new T*[getNumeroVertices()];

	//Crear la matriz dinamicamente

	for (int i = 0; i < getNumeroVertices(); i++){

		Matriz[i] = new T[getNumeroVertices()];

	}

	//Copiar matriz

	for (int i = 0; i < getNumeroVertices(); i++){

		for (int j = 0; j < getNumeroVertices(); j++) {

				Matriz[i][j] = CerTran[i][j];

		}
	}

	return Matriz;

}

template <class T> T** DiGrafica<T>::getMatAdy(){

	T** Matriz = new T*[getNumeroVertices()];

	//Crear la matriz dinamicamente

	for (int i = 0; i < getNumeroVertices(); i++){

		Matriz[i] = new T[getNumeroVertices()];

	}

	//Copiar matriz

	for (int i = 0; i < getNumeroVertices(); i++){

		for (int j = 0; j < getNumeroVertices(); j++) {

				Matriz[i][j] = MatAdy[i][j];

		}
	}

	return Matriz;

}

template <class T> T** DiGrafica<T>::getVerInt(){

	T** Matriz = new T*[getNumeroVertices()];

	//Crear la matriz dinamicamente

	for (int i = 0; i < getNumeroVertices(); i++){

		Matriz[i] = new T[getNumeroVertices()];

	}

	//Copiar matriz

	for (int i = 0; i < getNumeroVertices(); i++){

		for (int j = 0; j < getNumeroVertices(); j++) {

				Matriz[i][j] = VerInt[i][j];

		}
	}

	return Matriz;

}
