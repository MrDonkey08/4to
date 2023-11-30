/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

#include "./include/DiGrafica.h"
#include "./src/DiGrafica.cpp"

#include "./include/colores.h"
#include "./include/error.h"
#include "./include/pantalla.h"

#include <cstdlib> // for system function
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <sys/stat.h>

using namespace std;

short int menu();
void crearCarpeta(string);

void cargarWarshall(DiGrafica<int> &RedFerrov);
void cargarFloyd(DiGrafica<int> &RedFerrov);
void cargarFloydVerInt(DiGrafica<int> &RedFerrov);
bool cargarDikstra(DiGrafica<int> &RedFerrov, bool Carga, int Nodo);

int main() {
	setlocale(LC_CTYPE, "Spanish");
	limpiarPantalla();
	bool Dikstra = true;
	int Auxiliar;

	short int opc;
	DiGrafica<int> RedFerrov;

	do {
		opc = menu();

		switch (opc) {
			case 0:

				RedFerrov.Lee();
				RedFerrov.Imprime(0);

				break;

			case 1:

				RedFerrov.Warshall();
				RedFerrov.Imprime(1);
				cargarWarshall(RedFerrov);

				break;

			case 2:

				RedFerrov.Floyd();
				RedFerrov.Imprime(2);
				cargarFloyd(RedFerrov);

				break;

			case 3:

				RedFerrov.FloydVerInt();
				RedFerrov.Imprime(3);
				cargarFloydVerInt(RedFerrov);

				break;

			case 4:

				Auxiliar = RedFerrov.Dijkstra();
				RedFerrov.Imprime(4);
				Dikstra = cargarDikstra(RedFerrov, Dikstra, Auxiliar);

				break;

			case 5:
				cout << "Adiós, !Bonito día! !Vuelve pronto!\n\n"
					<< "Presiona <enter> para salir";
				pausarPantalla();
				limpiarPantalla();
				break;

			default:
				opcInvalida();
				break;
		}

		if (opc != 5) {
			pausarPantalla();
			limpiarPantalla();
		}

	} while (opc != 5);

	return 0;
}

short int menu() {
	short int opc = 0;
	bool error = 0;

	do {
		cout << "Bienvenido\n\n"
			<< "Menú - Sistema Ferroviario\n\n"
			<< "0. Ingresar datos e imprimir matriz de adyacencias\n"
			<< "1. Ciudades que estan comunicadas entre si (Warshall)\n"
			<< "2. Minimo costo entre todas las ciudades (Floyd)\n"
			<< "3. Minimo costo entre todas las ciudades y ciudades intermedias (FloydVerInt)\n"
			<< "4. Minimo costo entre una ciudad y las otras (Dijkstra)\n"
			<< "5. Salir del programa\n\n"
			<< "Digite una opción: ";
		cin >> opc;

		error = errorNumero();

		pausarPantalla();
		limpiarPantalla();

	} while (error);

	return opc;
}

void cargarWarshall(DiGrafica<int> &RedFerrov) {
	string Carpeta =  "archivos";
	crearCarpeta(Carpeta);

	string Ruta = Carpeta + "/Warshall.txt";

	ofstream Archivo(Ruta.c_str());
	int Numero_Vertices = RedFerrov.getNumeroVertices();
	int **Matriz = RedFerrov.getCerTran();
	int *Vertices = RedFerrov.getVertices();

	if (!Archivo) {
		cerr << "\n\nNo fue posible guadarlo exitosamente en el archivo Warshall.txt";
	}

	for (int i = 0; i < Numero_Vertices; i++) {
		Archivo << Vertices[i] << ": ";

		for (int j = 0; j < Numero_Vertices; j++) {
			Archivo << Matriz[i][j] << " ";
		}

		Archivo << "\n";
	}

	delete[] Vertices;
	delete[] Matriz;

	Archivo.close();
}

void cargarFloyd(DiGrafica<int> &RedFerrov) {
	string Carpeta =  "archivos";
	crearCarpeta(Carpeta);
	string Ruta = Carpeta + "/Floyd.txt";

	ofstream Archivo(Ruta.c_str());
	int Numero_Vertices = RedFerrov.getNumeroVertices();
	int **Matriz = RedFerrov.getMatAdy();
	int *Vertices = RedFerrov.getVertices();

	if (!Archivo) {

		cerr << "\n\nNo fue posible guadarlo exitosamente en el archivo Floyd.txt";
	}

	for (int i = 0; i < Numero_Vertices; i++) {
		Archivo << Vertices[i] << ": ";

		for (int j = 0; j < Numero_Vertices; j++) {
			Archivo << Matriz[i][j] << " ";
		}

		Archivo << "\n";
	}

	delete[] Vertices;
	delete[] Matriz;

	Archivo.close();
}

void cargarFloydVerInt(DiGrafica<int> &RedFerrov) {
	string Carpeta =  "archivos";
	crearCarpeta(Carpeta);
	string Ruta = Carpeta + "/FloydVerInt.txt";

	ofstream Archivo(Ruta.c_str());
	int Numero_Vertices = RedFerrov.getNumeroVertices();
	int **Matriz = RedFerrov.getVerInt();
	int *Vertices = RedFerrov.getVertices();

	if (!Archivo) {
		cerr << "\n\nNo fue posible guadarlo exitosamente en el archivo FloydVerInt.txt";
	}

	for (int i = 0; i < Numero_Vertices; i++) {
		Archivo << Vertices[i] << ": ";

		for (int j = 0; j < Numero_Vertices; j++) {
			Archivo << Matriz[i][j] << " ";
		}

		Archivo << "\n";
	}

	delete[] Vertices;
	delete[] Matriz;

	Archivo.close();
}

bool cargarDikstra(DiGrafica<int> &RedFerrov, bool Carga, int Nodo) {
	string Carpeta =  "archivos";
	crearCarpeta(Carpeta);
	crearCarpeta("archivos"); // Reemplaza con la ruta de tu carpeta

	string Ruta = Carpeta + "/Dikstra.txt";
	ofstream Archivo;

	if (Carga)
		Archivo.open(Ruta.c_str());
	else {
		Archivo.open(Ruta.c_str(), ios::app | ios::ate);
		Archivo << "\n\n";
	}

	Archivo << "--- Vertice " << Nodo << " --- \n\n";

	int Numero_Vertices = RedFerrov.getNumeroVertices();
	int *Matriz = RedFerrov.getDistMin();
	int *Vertices = RedFerrov.getVertices();

	if (!Archivo) {
		cerr << "\n\nNo fue posible guadarlo exitosamente en el archivo Dikstra.txt";
	}

	for (int i = 0; i < Numero_Vertices; i++) {
		Archivo << Vertices[i] << ": ";
		Archivo << Matriz[i] << " ";
		Archivo << "\n";
	}

	delete[] Vertices;
	delete[] Matriz;

	Archivo.close();

	return false;
}

void crearCarpeta(string carpeta) {
	// Use mkdir based on the operating system
#ifdef _WIN32
	if (mkdir(carpeta.c_str()) == 1) {
		cerr << "Error creating directory" << endl;
		exit(EXIT_FAILURE);
	}
#else
	if (mkdir(carpeta.c_str(), 0777) == 1) {
		cerr << "Error creating directory" << endl;
		exit(EXIT_FAILURE);
	}
#endif
}