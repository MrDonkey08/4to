#include <bits/stdc++.h>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
#endif

#include "include/ColaGenerica.h"
#include "src/ColaGenerica.cpp"


const int N = 99;
#define randomize (srand(time(NULL)))
#define random(num) (rand() % (num))

using namespace std;

void menu();
void escribir(string);
void lectura(string);

void numsSuerte();
template <class T> void mostrarCola(ColaGenerica<T> &q);

void limpiarPantalla();
void pausarPantalla();
void opcInvalida();

int main() {
	limpiarPantalla();
	setlocale(LC_CTYPE, "Spanish");

	menu();

	return 0;
}

void menu() {
	short int opc = 0;

	while (opc != 3) {

		cout << " --- Bienvenido al Sistema ---\n\n"
			<< "Menú - Números de la Suerte\n\n"
			<< "1. Generar y mostrar números de la suerte (guardar en archivo1) \n"
			<< "2. Cargar archivo2, generar y mostrar números de la suerte \n"
			<< "3. Salir\n\n"
			<< "Digita tu opción: ";
		cin >> opc;
		cout << endl;

		switch (opc) {
			case 1: numsSuerte(); break;
			case 2:
				// abrirArchivo("numeros_suerte2.txt");
				break;
			case 3:
				cout << "Has salido del programa. ¡Vuelve pronto!\n";
				break;
			default:
				opcInvalida();
				break;
		}
		pausarPantalla();
		limpiarPantalla();
	}
}

void borrar(string file) {
	ofstream archivo;

	archivo.open("archivos/" + file, ios::out);

	if (!archivo) {
		cerr << "No se pudo abrir el archivo\n";
		exit(1);
	}
}

void escribir(string file, int num) {
	ofstream archivo;

	archivo.open("archivos/" + file, ios::app);

	if (!archivo) {
		cerr << "No se pudo abrir el archivo\n";
		exit(1);
	}

	archivo << num << endl;
}


void leer(string file) {
	ifstream archivo;

	archivo.open("archivos/" + file, ios::in);

	if (!archivo) {
		cerr << "No se pudo abrir el archivo\n";
		exit(1);
	}

	while (!archivo.eof()) { // eof = end of file -> Devuelve True si es el final
	}
}

void pausarPantalla(){
	cout << "\n\nPresiona <enter> para continuar.";
	cin.ignore();
	cin.get();
}

void limpiarPantalla() {
	#ifdef _WIN32
		system("cls"); // Para Windows
	#else
		system("clear"); // Para sistemas basados en Unix/Linux
	#endif
}

void numsSuerte() {
	int n, n1, n2;
	ColaGenerica<int> q;
	randomize;
	// número inicial de elementos de la lista
	n = 11 + random(N);
	// se generan n números aleatorios
	for (int i = 1; i <= n; i++) {
		q.insertar(random(N * 3));
	}

	// se genera aleatoriamente el intervalo n1
	n1 = 1 + random(11);
	// se retiran de la cola elementos a distancia n1

	cout << "Se quitan los números:\n\n";

	while (n1 <= n) {
		int nt;
		n2 = 0; // contador de elementos que quedan

		for (int i = 1; i <= n; i++) {
			nt = q.quitar();

			if (i % n1 == 1) {
				cout << nt << endl;
			} else {
				q.insertar(nt); // se vuelve a meter en la cola
				n2++;
			}
		}
		n = n2;
		n1 = 1 + random(11);
	}

	cout << "\nLos números de la suerte son: \n\n";

	mostrarCola(q);
}

template <class T> void mostrarCola(ColaGenerica<T> &q) {
	int v;

	borrar("numeros_suerte1.txt");

	for (int i = 1; !q.colaVacia(); i++) {
		v = q.quitar();
		cout << i << ". " << v << endl;
		escribir("numeros_suerte1.txt", v);
	}
	
	cout << endl;
}

void opcInvalida() { cout << "Opción inválida. Inténtelo de nuevo."; }
