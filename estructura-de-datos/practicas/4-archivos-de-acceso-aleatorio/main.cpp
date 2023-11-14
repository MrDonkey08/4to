/*
Castellanos Ramírez Gustavo Fabián
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

#include "Deportistas.h"
#include "Deportistas.cpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
// Definición de códigos de escape ANSI para colores en la consola de Linux
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_PURPLE "\x1b[35m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#endif

using namespace std;

void limpiarPantalla();
void pausarPantalla();

void azul();
void blanco();
void rojo();
void purpura();
void amarillo();
void verde();

int Menu() {
	system("cls");
	int opcion;
	do {
		cout << "\n";
		azul();
		cout << setw(30) << " "
			<< "MENU - ASOCIACION DE DEPORTISTAS TAPATIOS" << endl;
		blanco();
		cout << setw(10) << " "
			<< "1. Consulta individual\n"
			<< endl;
		cout << setw(10) << " "
			<< "2. Consultas generales\n"
			<< endl;
		cout << setw(10) << " "
			<< "3. Salir\n"
			<< endl;
		cout << setw(10) << " "
			<< "Elige una opcion: ";
		cin >> opcion;
		system("cls");
	} while (opcion != 1 && opcion != 2 && opcion != 3);
	return opcion;
}

void consulta_in(ifstream &archDeportistasEntrada, Deportistas d) {
	int num;
	system("cls");
	cout << setw(10) << " " << "Escriba el numero de socio: ";
	cin >> num;
	archDeportistasEntrada.seekg((num - 1) * sizeof(Deportistas)); // seekg(n,ios::beg);
	archDeportistasEntrada.read(reinterpret_cast<char *>(&d), sizeof(Deportistas));
	if (d.getNumeroDeSocio() == 0) {
		rojo();
		cout << left << setw(15) << "EL NUMERO DE SOCIO NO EXISTE..." << endl;
		blanco();
		return;
	}
	azul();
	cout << left << setw(15) << "NUMERO DE SOCIO" << ":" << d.getNumeroDeSocio() << endl;
	blanco();
	cout << left << setw(15) << "NOMBRE" << ":" << d.getNombre() << "\n";
	cout << left << setw(15) << "EDAD" << ":" << d.getEdad() << "\n";
	cout << left << setw(15) << "DEPORTE" << ":" << d.getDeporte() << "\n";
	archDeportistasEntrada.seekg(0, ios::beg);
}
void consulta_ge(ifstream &archDeportistasEntrada, Deportistas d) {
	system("cls");
	azul();
	cout << left << setw(10) << "N. SOCIO" << setw(16) << "NOMBRE" << setw(11) << "EDAD" << left << setw(10) << right << "DEPORTE" << endl;
	blanco();
	while (archDeportistasEntrada && !archDeportistasEntrada.eof()) {
		// muestra un registro
		if (d.getNumeroDeSocio() != 0) {
			cout << left << setw(10) << d.getNumeroDeSocio() << setw(16)
				<< d.getNombre() << setw(11) << d.getEdad() << setw(10)
				<< d.getDeporte() << endl;
		}
		// lee el siguiente registro del archivo
		archDeportistasEntrada.read(reinterpret_cast<char *>(&d), sizeof(Deportistas));
	}
	archDeportistasEntrada.clear();
	archDeportistasEntrada.seekg(0, ios::beg);
}
int main() {
	// variables locales a main
	int opcion;

	Deportistas d; // Objeto Deportista
	ifstream archDeportistasEntrada; // archivo logico
	archDeportistasEntrada.open("deportistas.dat", ios::in | ios::binary);
	// salir del programa si ofstream no puede abrir el archivo
	if (!archDeportistasEntrada) {
		cerr << "No se pudo abrir el archivo. " << endl;
		exit(1);
	}

	do {
		opcion = Menu();
		switch (opcion) {
			case 1: {
				consulta_in(archDeportistasEntrada, d);
				pausarPantalla();
				system("cls");
				break;
			}

			case 2: {
				consulta_ge(archDeportistasEntrada, d);
				pausarPantalla();
				system("cls");
				break;
			}
		}
	} while (opcion != 3);
	cout << "\n\n";
	azul();
	cout << setw(10) << " " << "Adios ;)" << endl << endl;
	blanco();

	archDeportistasEntrada.close();

	return 0;
}

void pausarPantalla(){
	cout << "\n\nPresiona <enter> para continuar.";
	cin.ignore();
	cin.get();
}

void limpiarPantalla() {
#ifdef _WIN32
	limpiarPantalla(); // Para Windows
#else
	system("clear"); // Para sistemas basados en Unix/Linux
#endif
}

// Funciones para colores de fuente
void azul() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
#else
    cout << ANSI_COLOR_BLUE;
#endif
}

void blanco() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
#else
    cout << ANSI_COLOR_WHITE;
#endif
}

void rojo() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
#else
    cout << ANSI_COLOR_RED;
#endif
}

void purpura() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 5);
#else
    cout << ANSI_COLOR_PURPLE;
#endif
}

void amarillo() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
#else
    cout << ANSI_COLOR_YELLOW;
#endif
}

void verde() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
#else
    cout << ANSI_COLOR_GREEN;
#endif
}
