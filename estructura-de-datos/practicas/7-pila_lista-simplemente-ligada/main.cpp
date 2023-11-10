#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
#endif

#include "Libro.h"
#include "PilaGenerica.cpp"
#include "PilaGenerica.h"

using namespace std;

void menu();

void insertar(PilaGenerica<Libro> &Informacion);
void eliminar(PilaGenerica<Libro> &Informacion);
void abrirArchivo(PilaGenerica<Libro> &Informacion);

void limpiarPantalla();
void opcInvalida();

int main() {
	setlocale(LC_CTYPE, "Spanish");

	menu();

	return 0;
}

void menu() {
	short int opc;
	PilaGenerica<Libro> Informacion;

	while (opc != 3) {

		cout << " --- Bienvenido al Sistema ---\n\n"
			<< "Menú - Librería CUCEI\n\n"
			<< "1. Comprar Libros (insertar)\n"
			<< "2. Vender Libros (eliminar)\n"
			<< "3. Salir\n\n"
			<< "Digita tu opción: ";
		cin >> opc;
		cout << endl;

		switch (opc) {
			case 1:
				insertar(Informacion);
				break;
			case 2:
				eliminar(Informacion);
				break;
			case 3:
				break;
			default:
				opcInvalida();
				break;
		}
		limpiarPantalla();
	}
}

void insertar(PilaGenerica<Libro> &Informacion) {
	Libro Auxiliar;
	string Temporal;

	cout << "Ingrese los datos del libro a comprar:\n\n";

	cout << "Nombre: ";
	cin >> Temporal;
	Auxiliar.establecerNombre(Temporal);
	cout << endl;

	cout << "Autor: ";
	cin >> Temporal;
	Auxiliar.establecerAutor(Temporal);
	cout << endl;

	cout << "Editorial: ";
	cin >> Temporal;
	Auxiliar.establecerEditorial(Temporal);
	cout << endl;

	Informacion.insertar(Auxiliar);

	return;
}

void eliminar(PilaGenerica<Libro> &Informacion) {
	try {
		Libro Auxiliar;
		Auxiliar = Informacion.quitar();
		cout << "Libro vendido: \n\n" << Auxiliar << endl;

	} catch (const char *Mensaje) {

		cerr << "Error: " << Mensaje << endl;
	}

	return;
}

void abrirArchivo(PilaGenerica<Libro> &Informacion) {
	ifstream Libros;

	Libros.open("Libros.dat", ios::app);

	if (!Libros) {
		cerr << "No se pudo abrir el archivo\n";
		exit(1);
	}

	while (Informacion.pilaVacia()) {
		// En desarrollo
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

void opcInvalida() { cout << "Opción inválida. Inténtelo de nuevo."; }
