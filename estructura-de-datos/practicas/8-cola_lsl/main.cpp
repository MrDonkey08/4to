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

using namespace std;

void menu();
void escribir(string, int);
void lectura(string);
int ranNum(int, int);

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
	int minimo = 0, maximo = 0, numGenerar = 0, aux = 0;
	ColaGenerica<int> suerte;

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
			case 1:
				cout << "Dígita el valor mínimo: ";
				cin >> minimo;

				cout << "\nDigita el valor máximo: ";
				cin >> maximo;
				
				cout << "\nDigita la cantidad de números a generar: ";
				cin >> numGenerar;

				if (numGenerar > 0) {
					pausarPantalla();
					limpiarPantalla();

					cout << "Los números de la suerte son:\n\n";

					for (int i = 0; i < numGenerar; i++) {
						aux = ranNum(minimo, maximo);

						cout << i+1 << ". " << aux << endl;

						suerte.insertar(aux);
						escribir("numeros_suerte2.txt", aux);
					}
				} else {
					cout << "Error: solo se aceptan cantidades positivas.";
				}

				break;
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

void escribir(string file, int num) {
	ofstream archivo;

	// file = "archivo/" + file;

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

int ranNum(int minimo, int maximo) {
	return rand() % (maximo - minimo + 1) + minimo;
}

void opcInvalida() { cout << "Opción inválida. Inténtelo de nuevo."; }
