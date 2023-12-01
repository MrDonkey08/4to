/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

#include "../include/DiGrafica.h"
#include "../include/pantalla.h"

// Método constructor. Inicializa el número de vertices en cero y a la matriz de adyacencias MatAdy con un valor arbitrario muy grande (999), indicando que no existe camino entre los nodos correspondientes. Además, asigna ceros a los arreglos auxiliares que se usan en los métodos.
template <class T> DiGrafica<T>::DiGrafica() {
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

// Método que lee los datos de la gráfica dirigida directamente del teclado.
template <class T> void DiGrafica<T>::Lee() {
	int NumArcos, Indice, Origen, Destino;

	cout << "Ingrese número de vértices de la gráfica dirigida: ";
	cin >> NumVer;

	cout << "\n\nIngrese los nombres de los vértices de la gráfica dirigida: ";

	cout << "\n";

	for (Indice = 0; Indice < NumVer; Indice++) {
		cout << "\n\t";
		cin >> Vertices[Indice];
	}

	pausarPantalla();
	limpiarPantalla();

	cout << "Total de aristas de la gráfica dirigida: ";
	cin >> NumArcos;
	cout << "\n\n";

	for (Indice = 0; Indice < NumArcos; Indice++) {
		cout << "Ingrese vértice origen: ";
		cin >> Origen;

		cout << "\n\nIngrese vértice destino: ";
		cin >> Destino;

		cout << "\n\nDistancia de origen a destino: ";
		cin >> MatAdy[Origen - 1][Destino - 1];

		pausarPantalla();
		limpiarPantalla();
	}
}

// Método que imprime información relacionada a una gráfica dirigida. Por medio de un número entero se selecciona lo que se va a imprimir, lo cual depende del método aplicado para recorrer la digráfica.
template <class T> void DiGrafica<T>::Imprime(int Opc) {
	int Ind1, Ind2;

	switch (Opc) {
	// Impresión de la matriz de adyacencia o de costos.
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
		// Impresión de la cerradura transitiva correspondiente a la matriz de adyacencia. Se obtiene cuando se aplica el método de Warshall.
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
		// Impresión de la matriz de distancias mínimas entre todos los vertices de la grafica. Se obtiene por medio del método de Floyd.
		case 2:
			cout << "Matriz de Distancias Mínimas: " << endl << endl;

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				cout << Vertices[Ind1] << ":";
				for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
					cout << MatAdy[Ind1][Ind2] << "\t";
				}
				cout << endl;
			}
			break;
		// Impresión de la matriz con los vertices intermedios usados para establecer los caminos de distancias mínimas. Esta impresión complementa la de la opción 2 cuando se aplica el método FloydVerInt.
		case 3:
			cout << "Vértices Intermedios para lograr distancias mínimas:" << endl<< endl;

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
					cout << VerInt[Ind1][Ind2] << "\t";
				}
				cout << endl;
			}
			break;
		// Impresión de las distancias mínimas entre un vertice y los demás. Se obtiene con el método de Dijkstra.
		case 4:
			cout << "\n\nDistancias mínimas a partir del vértice:" << Vertices[0] << "\n\n";

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				cout << " " << DistMin[Ind1] << "\t" << endl;
			}
			break;

		default: break;
	}
}

// Método que determina si existe un camino entre cada uno de los	vertices de la gráfica dirigida. CerTran es una matriz que representa	la cerradura transitiva de la matriz de adyacencia.

template <class T> void DiGrafica<T>::Warshall() {
	int Ind1, Ind2, Ind3;
	// En la posición i,j de la matriz de adyacencia se asigna el valor 999 si no existe un camino directo del vertice i al vertice j. La cerradura transitiva se forma inicialmente a partir de la matriz de adyacencia.
	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
			if (MatAdy[Ind1][Ind2] != 999) {
				CerTran[Ind1][Ind2] = 1;
			}
		}
	}

	// Se recorren todos los vetices para determinar si existe un camino entre él y los demás, usando otros vertices como intermedios.
	for (Ind3 = 0; Ind3 < NumVer; Ind3++) {
		for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
			for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
				CerTran[Ind1][Ind2] |= CerTran[Ind1][Ind3] && CerTran[Ind3][Ind2];
			}
		}
	}
}

// Método que encuentra el camino de costo mínimo entre todos los vertices de la gráfica dirigida. Va modificando la matriz de adyacencia a medida que encuentra un camino más corto entre dos vértices.

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

// Método Floyd modificado para que, además de encontrar las distancias minimas entre todos los vertices de una digráfica, genere una matriz (VerInt) con los vertices intermedios utilizados para minimizar las distancias. Este método usa los atributos Vertices (arreglo que almacena los nombres de todos los vértices de la digráfica) y VerInt (arreglo donde se van guardando los vértices intermedios. Fue inicia- lizado en 0 en el método constructor).
template <class T>
void DiGrafica<T>::FloydVerInt() {
	int Ind1, Ind2, Ind3;

	for (Ind3= 0; Ind3 < NumVer; Ind3++) {
		for (Ind1= 0; Ind1 < NumVer; Ind1 ++) {
			for (Ind2= 0; Ind2 < NumVer; Ind2 ++) {
				if ((MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2]) {
					MatAdy[Ind1][Ind2] = MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
					VerInt[Ind1][Ind2] = Vertices[Ind3];
				}
			}
		}
	}
}

// Método que encuentra la distancia mínima entre un vértice dado y los demás vértices de una gráfica dirigida. En el arreglo DistMin se almacenan las distancias mínimas desde el vértice origen a cada uno de los otros nodos. Es decir DistMin[i] almacena la menor distancia entre el vértice origen y el vértice i.

template <class T> int DiGrafica<T>::Dijkstra() {
	int Aux[MAX], VertInc[MAX], Ver1, Ver2, Ind1, Ind2, Menor, Band, Origen;
	// El arreglo VertInc se utiliza para guardar los vértices elegidos por ser los de la distancia mínima. El arreglo Aux es un arreglo lógico que indica si el nodo de la posición i ya fue incluido en VertInc y de esta manera evitar ciclos.
	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		Aux[Ind1] = 0;
		VertInc[Ind1] = 0;
	}

	cout << "Ingrese vértice origen: ";
	cin >> Origen;
	Origen--;

	Aux[Origen - 1] = 1;
	// El arreglo donde se guardan las distancias mínimas del Origen a los demás vértices se inicializa con los valores de la matriz de adyacencia.
	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		DistMin[Ind1] = MatAdy[Origen][Ind1];
	}

	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		// Se busca el vértice Ver1 en (Vertices - VertInc) tal que DistMin[Ver1] sea el mínimo valor. Se usa el 999 como valor inicial ya que es el elegido para indicar que no existe camino entre dos vértices.
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

template <class T> int DiGrafica<T>::getNumeroVertices() { return NumVer; }

template <class T> T *DiGrafica<T>::getVertices() {
	T *Matriz = new T[getNumeroVertices()];

	// Crear la matriz dinamicamente
	for (int i = 0; i < getNumeroVertices(); i++) {
		Matriz[i] = Vertices[i];
	}

	return Matriz;
}

template <class T> T *DiGrafica<T>::getDistMin() {
	T *Matriz = new T[getNumeroVertices()];

	// Crear la matriz dinamicamente
	for (int i = 0; i < getNumeroVertices(); i++) {
		Matriz[i] = DistMin[i];
	}

	return Matriz;
}

template <class T> T **DiGrafica<T>::getCerTran() {
	T **Matriz = new T *[getNumeroVertices()];

	// Crear la matriz dinamicamente
	for (int i = 0; i < getNumeroVertices(); i++) {
		Matriz[i] = new T[getNumeroVertices()];
	}

	// Copiar matriz
	for (int i = 0; i < getNumeroVertices(); i++) {
		for (int j = 0; j < getNumeroVertices(); j++) {
			Matriz[i][j] = CerTran[i][j];
		}
	}

	return Matriz;
}

template <class T> T **DiGrafica<T>::getMatAdy() {
	T **Matriz = new T *[getNumeroVertices()];

	// Crear la matriz dinamicamente
	for (int i = 0; i < getNumeroVertices(); i++) {
		Matriz[i] = new T[getNumeroVertices()];
	}

	// Copiar matriz
	for (int i = 0; i < getNumeroVertices(); i++) {
		for (int j = 0; j < getNumeroVertices(); j++) {
			Matriz[i][j] = MatAdy[i][j];
		}
	}

	return Matriz;
}

template <class T> T **DiGrafica<T>::getVerInt() {
	T **Matriz = new T *[getNumeroVertices()];

	// Crear la matriz dinamicamente
	for (int i = 0; i < getNumeroVertices(); i++) {
		Matriz[i] = new T[getNumeroVertices()];
	}

	// Copiar matriz
	for (int i = 0; i < getNumeroVertices(); i++) {
		for (int j = 0; j < getNumeroVertices(); j++) {
			Matriz[i][j] = VerInt[i][j];
		}
	}

	return Matriz;
}
