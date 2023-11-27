#include "Grafica.h"

// Declaración del método constructor. Inicializa el número de vértices en cero y la matriz de distancias con un valor arbitrario muy grande (999), excepto en la diagonal principal, donde el costo es cero.
template <class T>
Grafica<T>::Grafica() {
	for (int Ind1 = 0; Ind1 < MAX; Ind1++) {
		for (int Ind2 = 0; Ind2 < MAX; Ind2++) {
			if (Ind1 != Ind2) {
				MatAdy[Ind1][Ind2] = 999;
			} else {
				MatAdy[Ind1][Ind2] = 0;
			}
		}
	}

	NumVer = 0;
}

// Método que lee del teclado la información de la gráfica. En esta solución el nombre de los vértices sólo pueden ser valores enteros.
template <class T>
void Grafica<T>::Lee() {
	int Aristas, Costo, Ind1, Origen, Destino;

	cout << "\n\nIngrese total de vértices de la gráfica: ";
	cin >> NumVer;

	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		cout << "\nIngrese el nombre del vértice: ";
		cin >> Vertices[Ind1];
	}

	cout << "\n\nIngrese total de aristas de la gráfica: ";
	cin >> Aristas;

	for (Ind1 = 0; Ind1 < Aristas; Ind1++) {
		cout << "\nVértice origen: ";
		cin >> Origen;

		cout << "\nVértice destino: ";
		cin >> Destino;

		cout << "\nCosto de ir de " << Origen << " a " << Destino << ": ";
		cin >> Costo;

		MatAdy[Origen - 1][Destino - 1] = Costo;
		MatAdy[Destino - 1][Origen - 1] = Costo;
	}
}

template <class T>
void Grafica<T>::Imprime() {
	int Ind1, Ind2;
	// Impresión de la matriz de adyacencia o de costos.
	cout << "\n\n Matriz de Adyacencia o de Costos: \n\n";

	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		cout << Vertices[Ind1] << ": ";
		for (Ind2 = 0; Ind2 < NumVer; Ind2++) {
			cout << MatAdy[Ind1][Ind2] << "\t";
		}
		cout << endl;
	}

	cout << endl;
}

/* Este método encuentra el árbol abarcador de costo mínimo de una gráfica. En el arreglo VerAux se almacenan los vértices con menor costo que van formando el árbol abarcador. */
template <class T>
void Grafica<T>::Prim() {
	int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;

	/* Inicializa el subconjunto de vértices VerAux con el valor del primer vértice. */
	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		MCosto[Ind1] = MatAdy[0][Ind1];
		VerAux[Ind1] = 0;
	}

	cout << "\n\n\nArcos y costos del árbol abarcador de costo mínimo\n\n";
	cout << "\nVértice Vértice Costo \n";

	/* Encuentra el vértice VerMen en (Vertices - VerAux) tal que el costo de ir de dicho vértice a uno de VerAux sea mínimo. */
	for (Ind1 = 0; Ind1 < NumVer - 1; Ind1++) {
		MenCos = MCosto[1];
		VerMen = 1;

		for (Ind2 = 2; Ind2 < NumVer; Ind2++) {
			if (MCosto[Ind2] < MenCos) {
				MenCos = MCosto[Ind2];
				VerMen = Ind2;
			}
		}

		cout << "\n" << Vertices[VerMen] << Vertices[VerAux[VerMen]] << " - " << MatAdy[VerMen][VerAux[VerMen]];

		/* Se agrega el vértice VerMen a VerAux y se redefinen los costos asociados. */
		MCosto[VerMen] = 1000;

		for (Ind2 = 1; Ind2 < NumVer; Ind2++) {
			if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000) {
				MCosto[Ind2] = MatAdy[VerMen][Ind2];
				VerAux[Ind2] = VerMen;
			}
		}
	}

	cout << "\n\n";
}

template <class T>
void Grafica<T>::Kruskal() {
	/* El arreglo auxiliar ArisCosto[][] almacena en cada renglón los datos de una arista: vértices adyacentes y costo. El arreglo Partic[] almacena particiones de Vertices. Inicialmente Partic = {{1},{2},...,{NumVer}}.*/
	int ArisCosto[2 * MAX][3], Partic[MAX], Ind1, Ind2, Ver1, Ver2, TotAris, Menor, Mayor, Band;

	/* Inicializa Partic[]. */
	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		Partic[Ind1] = Ind1;
	}

	/* Inicializa ArisCosto[][]. */
	Ver1 = 0;
	Ver2 = 0;
	TotAris = 0;

	for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
		for (Ind2 = Ind1; Ind2 < NumVer; Ind2++) {
			if (MatAdy[Ind1][Ind2] != 0 && MatAdy[Ind1][Ind2] != 999) {
				ArisCosto[Ver1][Ver2++] = Ind1;
				ArisCosto[Ver1][Ver2++] = Ind2;
				ArisCosto[Ver1++][Ver2] = MatAdy[Ind1][Ind2];
				Ver2 = 0;
				TotAris++;
			}
		}
	}
	
	/* Ciclo en el cual se seleccionan aristas y se agregan los vértices mientras existan vértices en Partic que se encuentren en distintas particiones. */
	Band = 0;
	while (Band != 1) {
		/* Se selecciona la arista de menor costo. */
		Menor = 999;
		for (Ind1 = 0; Ind1 < TotAris; Ind1++) {
			if (ArisCosto[Ind1][2] < Menor) {
				Ver1 = ArisCosto[Ind1][0];
				Ver2 = ArisCosto[Ind1][1];
				Menor = ArisCosto[Ind1][2];
				Ind2 = Ind1;
			}
		}

		/* Se elimina la arista de menor costo de la matriz ArisCosto. */
		ArisCosto[Ind2][2] = 999;

		/* Se verifica que la arista (Ver1, Ver2) una dos vértices que pertenecen a particiones diferentes. */
		if (Partic[Ver1] != Partic[Ver2]) {
			cout << "\nVértice: " << Vertices[Ver1] << " Vértice: " << Vertices[Ver2] << " Costo: " << MatAdy[Ver1][Ver2] << "\n\n";
			Mayor = Maximo(Partic[Ver1], Partic[Ver2]);

			for (Ind1 = 0; Ind1 < NumVer; Ind1++) {
				if (Ind1 == Ver1 || Ind1 == Ver2 || Partic[Ind1] == Mayor) {
					Partic[Ind1] = Minimo(Partic[Ver1], Partic[Ver2]);
				}
			}
		}

		/* Ciclo para determinar si quedan vértices en particiones diferentes. */
		for (Ind1 = 0; Ind1 < NumVer && !Band; Ind1++) {
			if (Partic[Ind1] != 0) {
				Band = 1;
			}
		}

		/* Si existen particiones en Partic se debe seguir con el proceso. */
		Band = !Band;
	}
}