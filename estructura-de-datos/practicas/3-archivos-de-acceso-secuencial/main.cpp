/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juarez Rubio Alan Yair
Hernandez Hurtado Leonel
*/

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#else
#endif

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <windows.h>
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
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

void mostrarRegistro(char *const, int, char *const);
void opcion1(char *const, int, char *const);
void opcion2(char *const, int, char *const);
void opcion3(char *const, int, char *const);

int Menu() {
	limpiarPantalla();
	int opcion;
	do {
		cout << "\n";
		azul();
		cout << setw(30) << " " << "Menu - Asociacion de Deportistas Jalisciences\n" << endl;
		blanco();
		cout << setw(10) << " " << "1. Mostrar deportistas menores de edad (5-17)\n" << endl;
		cout << setw(10) << " " << "2. Mostrar deportistas mayores de edad (18-59)\n" << endl;
		cout << setw(10) << " " << "3. Mostrar deportistas adultos mayores (60-85)\n" << endl;
		cout << setw(10) << " " << "4. Salir\n" << endl;
		cout << setw(10) << " " << "Elige una opcion: ";
		cin >> opcion;
		limpiarPantalla();
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
	return opcion;
}

int main() {

	char nombre[30];
	int edad;
	char deporte[20];

	ifstream archivoDeportistasEntrada;

	archivoDeportistasEntrada.open("deportistas.txt", ios::in);

	if (!archivoDeportistasEntrada) {

		rojo();
		cerr << "No se puede abrir el archivo" << endl;
		blanco();
		exit(1);
	}

	int opcion;
	do {
		opcion = Menu();
		switch (opcion) {
			case 1: {
				opcion1(nombre, edad, deporte);
				pausarPantalla();
				limpiarPantalla();
				break;
			}

			case 2: {
				opcion2(nombre, edad, deporte);
				pausarPantalla();
				limpiarPantalla();
				break;
			}

			case 3: {
				opcion3(nombre, edad, deporte);
				pausarPantalla();
				limpiarPantalla();
				break;
			}
		}
	} while (opcion != 4);
	cout << "\n\n";
	azul();
	cout << setw(10) << " " << "Adios ;)" << endl << endl;
	blanco();
	archivoDeportistasEntrada.close();

	return 0;
}

void opcion1(char *const nombre, int edad, char *deporte) {
	ifstream archivoDeportistasEntrada;
	archivoDeportistasEntrada.open("deportistas.txt", ios::in);
	if (!archivoDeportistasEntrada) {

		rojo();
		cerr << "No se puede abrir el archivo" << endl;
		blanco();
		exit(1);
	}
	verde();
	cout << setw(10) << "--------------------------------------------------------" << endl;
	cout << setw(10) << " " << left << setw(10) << "DEPORTISTAS MENORES DE EDAD" << endl;
	azul();
	cout << setw(10) << " " << left << setw(10) << "NOMBRE" << setw(10) << "EDAD" << setw(10) << "DEPORTE\n" << endl;
	blanco();
	while (archivoDeportistasEntrada >> nombre >> edad >> deporte)
		if (edad >= 5 && edad <= 17) {
			mostrarRegistro(nombre, edad, deporte);
		}
}

void opcion2(char *const nombre, int edad, char *deporte) {
	ifstream archivoDeportistasEntrada;
	archivoDeportistasEntrada.open("deportistas.txt", ios::in);
	verde();
	cout << setw(10) << "--------------------------------------------------------" << endl;
	cout << setw(10) << " " << left << setw(10) << "DEPORTISTAS MAYORES DE EDAD" << endl;
	azul();
	cout << setw(10) << " " << left << setw(10) << "NOMBRE" << setw(10) << "EDAD" << setw(10) << "DEPORTE\n" << endl;
	blanco();
	while (archivoDeportistasEntrada >> nombre >> edad >> deporte)
		if (edad >= 18 && edad <= 59) {
			mostrarRegistro(nombre, edad, deporte);
		}
}

void opcion3(char *const nombre, int edad, char *deporte) {
	ifstream archivoDeportistasEntrada;
	archivoDeportistasEntrada.open("deportistas.txt", ios::in);
	verde();
	cout << setw(10) << "--------------------------------------------------------" << endl;
	cout << setw(10) << " " << left << setw(10) << "DEPORTISTAS ADULTOS MAYORES" << endl;
	azul();
	cout << setw(10) << " " << left << setw(10) << "NOMBRE" << setw(10) << "EDAD" << setw(10) << "DEPORTE\n" << endl;
	blanco();
	while (archivoDeportistasEntrada >> nombre >> edad >> deporte)
		if (edad >= 60 && edad <= 85) {
			mostrarRegistro(nombre, edad, deporte);
		}
}

void mostrarRegistro(char *const nombre, int edad, char *deporte) {

	cout << setw(10) << " " << left << setw(10) << nombre << setw(10) << edad << setw(10) << deporte << endl;
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