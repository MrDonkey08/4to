// Fig 19.07: Fig20_07.cpp
// Programa de prueba de OrdenamientoCombinacion.

/*
Castellanos Ramírez Gustavo Fabián
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

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

#include "OrdenamientoCombinacion.h"
#include "OrdenamientoCombinacion.cpp"

void limpiarPantalla();
void pausarPantalla();

void azul();
void blanco();
void rojo();
void purpura();
void amarillo();
void verde();

int Menu() {
	limpiarPantalla();
	int opcion;
	do {
		cout << "\n";
		azul();
		cout << setw(30) << " " << "MENU - METODO DE ORDENAMIENTO RECURSIVO" << endl;
		blanco();
		cout << setw(10) << " " << "1. Ordenamiento creciente\n" << endl;
		cout << setw(10) << " " << "2. Ordenamiento decreciente\n" << endl;
		cout << setw(10) << " " << "3. Salir\n" << endl;
		cout << setw(10) << " " << "Elige una opcion: ";
		cin >> opcion;
		limpiarPantalla();
	} while (opcion != 1 && opcion != 2 && opcion != 3);
	return opcion;
}

int main() {
	// crea un objeto para realizar el ordenamiento por combinaciÃ³n
	OrdenamientoCombinacion vectorOrdenamiento(10);
	int opcion;
	do {
		opcion = Menu();
		switch (opcion) {
			case 1: {
				vectorOrdenamiento.ordenar(opcion);
				azul();
				cout << "Vector ordenado (creciente):" << endl;
				blanco();
				vectorOrdenamiento.mostrarElementos(); // imprime el vector ordenado
				cout << endl;
				pausarPantalla();
				limpiarPantalla();
				break;
			}

			case 2: {
				vectorOrdenamiento.ordenar(opcion);
				azul();
				cout << "Vector ordenado (decreciente):" << endl;
				blanco();
				vectorOrdenamiento.mostrarElementos(); // imprime el vector ordenado
				cout << endl;
				pausarPantalla();
				limpiarPantalla();
				break;
			}
		}
	} while (opcion != 3);
	cout << "\n\n";
	azul();
	cout << setw(10) << " " << "Adios ;)" << endl << endl;
	blanco();

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