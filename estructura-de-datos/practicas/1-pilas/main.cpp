#include "Pila_Libros.h"
#include <iomanip>
#include <iostream>
#include <locale.h>
#include <string.h>

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

/*
Práctica 1: Pilas || Estructura de Datos D02 2023B || Equipo: 3

- Guzmán Zavala Daniel
- Hernandez Hurtado Leonel
- Juarez Rubio ALan Yahir
*/

void pausarPantalla();
void limpiarPantalla();

void azul();
void blanco();
void rojo();
void purpura();
void amarillo();
void verde();

class Cheque {
	private:
		int Numero, CuentaADepositar;
		char Banco[10];
		double Monto;

	public:
		Cheque();
		~Cheque();
		void ImprimeDatos();
		void ingresarDatos();
		double getMonto() { return Monto; };
};

Cheque::Cheque() {}

Cheque::~Cheque() {}

void Cheque::ImprimeDatos() {
	azul();
	cout << "\n" << setw(20) << " " << "Numero de cheque: " << endl;
	blanco();
	cout << setw(10) << " " << Numero << endl;
	azul();
	cout << setw(20) << " " << "Del banco: " << endl;
	blanco();
	cout << setw(10) << " " << Banco << endl;
	azul();
	cout << setw(20) << " " << "Depositado en la cuenta: " << endl;
	blanco();
	cout << setw(10) << " " << CuentaADepositar << endl;
	azul();
	cout << setw(20) << " " << "Monto: " << endl;
	blanco();
	cout << setw(10) << " " << Monto << endl;
}

void Cheque::ingresarDatos() {
	azul();
	cout << setw(20) << " " << "Numero de cheque: " << endl;
	blanco();
	cin >> Numero;
	azul();
	cout << setw(20) << " " << "Ingresar el banco: " << endl;
	blanco();
	cin >> Banco;
	azul();
	cout << setw(20) << " " << "Ingresar cuenta: " << endl;
	blanco();
	cin >> CuentaADepositar;
	azul();
	cout << setw(20) << " " << "Monto: " << endl;
	blanco();
	cin >> Monto;
}

class ChequeRechazado : public Cheque {
	private:
		double Cargo;

	public:
		ChequeRechazado();
		~ChequeRechazado();
		void ImprimeDatos();
};

ChequeRechazado::ChequeRechazado() {}

ChequeRechazado::~ChequeRechazado() {}

void ChequeRechazado::ImprimeDatos() {
	Cheque::ImprimeDatos();
	Cargo = getMonto() * 0.10;
	azul();
	cout << setw(10) << " " << "Cargo por rechazo: " << endl;
	blanco();
	cout << setw(10) << " " << "$ " << Cargo << endl;
}

class Banco {
	private:
		Pila<Cheque> Cheques;
		Pila<ChequeRechazado> ChequesRe;

	public:
		Banco();
		~Banco();
		void EliminarCheque();
		void EliminarChequeR();
		void RegistroCheque(Cheque);
		void RegistroChequeR(ChequeRechazado);
};

Banco::Banco() {}

Banco::~Banco() {}

void Banco::EliminarCheque() {
	Cheque ChequeCli;
	if (!Cheques.PilaVacia()) {
		Cheques - &ChequeCli;
		rojo();
		cout << setw(10) << " " << "Cheque Eliminado: " << endl;
		blanco();
		ChequeCli.ImprimeDatos();
	} else {
		rojo();
		cout << setw(10) << " " << "No hay cheques por eliminar.\n\n ";
		blanco();
	}
}

void Banco::EliminarChequeR() {
	ChequeRechazado ChequeCli;
	if (!ChequesRe.PilaVacia()) {
		ChequesRe - &ChequeCli;
		rojo();
		cout << setw(10) << " " << "Cheque rechazado eliminado: " << endl;
		blanco();
		ChequeCli.ImprimeDatos();
	} else {
		rojo();
		cout << setw(10) << " " << "No hay cheques rechazados por procesar.\n\n ";
		blanco();
	}
}

void Banco::RegistroCheque(Cheque ChequeCli) {
	if (!Cheques.PilaLlena()) {
		ChequeCli.ingresarDatos();
		azul();
		cout << setw(10) << " " << "Registrando el cheque: " << endl;
		blanco();
		ChequeCli.ImprimeDatos();
		Cheques + ChequeCli;
	} else {
		rojo();
		cout << setw(10) << " " << "No se pudo registrar el cheque por falta de espacio. \n\n ";
		blanco();
	}
}

void Banco::RegistroChequeR(ChequeRechazado ChequeCli) {
	if (!ChequesRe.PilaLlena()) {
		ChequeCli.ingresarDatos();
		cout << setw(10) << " " << "Registrando el cheque rechazado: " << endl;
		ChequeCli.ImprimeDatos();
		ChequesRe + ChequeCli;
	} else {
		rojo();
		cout << setw(10) << " " << "No se pudo registrar el cheque rechazado por falta de espacio. "
						"\n\n";
		blanco();
	}
}

int Menu() {
	limpiarPantalla();
	int opcion;
	do {
		cout << "\n";
		azul();
		cout << setw(30) << " " << "Menu" << endl;
		blanco();
		cout << setw(10) << " " << "1. Insertar cheque\n" << endl;
		cout << setw(10) << " " << "2. Eliminar cheque\n" << endl;
		cout << setw(10) << " " << "3. Insertar cheque Rechazado\n" << endl;
		cout << setw(10) << " " << "4. Eliminar cheque Rechazado\n" << endl;
		cout << setw(10) << " " << "5. Salir\n" << endl;
		cout << setw(10) << " " << "Elige una opcion: ";
		cin >> opcion;
		limpiarPantalla();
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 &&
		opcion != 5);
	return opcion;
}

int main() {
	setlocale(LC_CTYPE, "spanish");
	Cheque cheque;
	Banco banco;
	ChequeRechazado chequeRe;
	int opcion;
	do {
		opcion = Menu();
		switch (opcion) {
			case 1: {
				banco.RegistroCheque(cheque);
				pausarPantalla();
				limpiarPantalla();
				break;
			}

			case 2: {
				banco.EliminarCheque();
				pausarPantalla();
				limpiarPantalla();
				break;
			}

			case 3: {
				banco.RegistroChequeR(chequeRe);
				pausarPantalla();
				limpiarPantalla();
				break;
			}

			case 4: {
				banco.EliminarChequeR();
				pausarPantalla();
				limpiarPantalla();
				break;
			}
		}
	} while (opcion != 5);
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