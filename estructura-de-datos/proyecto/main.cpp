// Aplicación del concepto de gráficas para encontrar el conjunto mínimo de carreteras, con el menor costo asociado, que una un grupo de ciudades. 
#include "DiGrafica.h"
#include "DiGrafica.cpp"

#include <locale>
#include <limits>

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
#endif

// Definición de códigos de escape ANSI para colores en la consola de Linux
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

void azul();
void blanco();
void rojo();
void purpura();
void amarillo();
void verde();

short int menu();
void limpiarPantalla();
void pausarPantalla();
void opcInvalida();
bool errorNumero();

int main() {
	setlocale(LC_CTYPE, "Spanish");
	limpiarPantalla();

	short int opc;
	DiGrafica<int> RedFerrov;

	do {
		opc = menu();

		switch (opc) {
			case 0: 
				break;

			case 1: {
				RedFerrov.Warshall();
				RedFerrov.Imprime(1);
				break;
			}

			case 2: {
				RedFerrov.Floyd();
				RedFerrov.Imprime(2);
				break;
			}

			case 3: {
				RedFerrov.FloydVerInt();
				RedFerrov.Imprime(3);
				break;
			}

			case 4: {
				RedFerrov.Dijkstra();
				RedFerrov.Imprime(4);
				break;
			}
				
			case 5:
				cout << "Adiós, !bonito día! !Vuelve pronto!\n\n"
				<< "Presiona <enter> para salir\n\n";
				break;

			default: opcInvalida(); break;
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
			<< "1. Ciudades que están comunicadas entre sí (Warshall)\n"
			<< "2. Mínimo costo entre todas las ciudades (Floyd)\n"
			<< "3. Mínimo costo entre todas las ciudades y ciudades intermedias (FloydVerInt)\n"
			<< "4. Mínimo costo entre una ciudad y las otras (Dijkstra)\n"
			<< "5. Salir del programa\n\n"
			<< "Digite una opción: ";
		cin >> opc;

		error = errorNumero();

		pausarPantalla();
		limpiarPantalla();

	} while (error);

	return opc;
}

void limpiarPantalla() { system("clear || cls"); }

void pausarPantalla() {
	cout << "\n\nPresiona <enter> para continuar.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el búfer de entrada después de cada opción
    cin.get();
}

void opcInvalida() { cout << "Opción inválida. Inténtalo de nuevo."; }

bool errorNumero() {
	bool error = 0;

	if(cin.fail()) {
		error = 1;
		// Si la entrada no es un número entero válido
		cin.clear(); // Restablecer el estado de error
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el búfer de entrada
		cout << "\nError: Ingrese un número válido.\n";
	}

	return error;
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