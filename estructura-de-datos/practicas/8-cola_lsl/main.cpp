#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
#endif

#include "include/ColaGenerica.h"

using namespace std;

void menu();
void escribir(string);
void lectura(string);
int ranNum(float, float);
void limpiarPantalla();
void opcInvalida();
	
int main() {
	setlocale(LC_CTYPE, "Spanish");

	cout << ranNum(1, 3) << endl;

	menu();

	return 0;
}

void menu() {
	short int opc;

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
				escribir("numeros_suerte1.txt");
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
		limpiarPantalla();
	}
}

void escribir(string file) {
	ofstream archivo;

	// file = "archivo/" + file;

	archivo.open("archivos/" + file, ios::out);

	if (!archivo) {
		cerr << "No se pudo abrir el archivo\n";
		exit(1);
	}
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

void limpiarPantalla() {
	cout << "\n\nPresiona <enter> para continuar.";
	cin.ignore();
	cin.get();

#ifdef _WIN32
	system("cls"); // Para Windows
#else
	system("clear"); // Para sistemas basados en Unix/Linux
#endif
}

int randNum(int min, int max) { return rand() % (max - min + 1) + min; }

void opcInvalida() { cout << "Opción inválida. Inténtelo de nuevo."; }
