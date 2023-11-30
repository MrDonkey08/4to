/*
- Nombre: Alan Yahir Juárez Rubio
- Actividad 2: ADT - Listas Estáticas
*/

#include "Arreglo.h"
#include "Arreglo.cpp"

#include <locale>
#include <limits>

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
#endif

short int menu();
void limpiarPantalla();
void pausarPantalla();
void opcInvalida();
int ingresarTamanio();
bool errorNumero();

int main() {
	setlocale(LC_CTYPE, "Spanish");
	limpiarPantalla();

	short int opc;
	bool datosIngresados = 0;
	Arreglo<float> calificaciones(MAX);

	do {
		opc = menu();

		switch (opc) {
			case 1:
				calificaciones.Escribir();
				datosIngresados = 1; // Option to input grades
				break;

			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				if(datosIngresados) {
					switch (opc){
						case 2:
							cout << "Calificaciones:\n\n";
							calificaciones.Leer(); // Option to print grades
							break;

						case 3:
							cout << "Calificación más alta: " << calificaciones.BuscaMayor() << endl;
							break;

						case 4:
							cout << "Calificación más baja: " << calificaciones.BuscaMenor() << endl;
							break;

						case 5:
							calificaciones.ImprimirTotalMenor(6);
							break;

						case 6:
							calificaciones.ImprimirTotalMayor(8.5);
							break;
					}
				} else {
					cout << "Error: No se han ingresado calificaciones" << endl;
				}
				break;

			case 7:
				cout << "¡Adiós, bonito día! ¡Vuelve pronto!\n\n"
					<< "Presiona <enter> para salir";
				break;

			default: opcInvalida(); break;
}

		if (opc != 7) {
			pausarPantalla();
			limpiarPantalla();
		}

	} while (opc != 7);

	return 0;
}

short int menu() {
	short int opc = 0;
	bool error = 0;

	do {
		cout << "MENÚ – SISTEMA DE CALIFICACIONES\n\n"
			<< "1. Ingresar las calificaciones\n"
			<< "2. Imprimir las calificaciones\n"
			<< "3. Mostrar calificación más alta\n"
			<< "4. Mostrar calificación más baja\n"
			<< "5. Imprimir total de calificaciones menores a 6\n"
			<< "6. Imprimir total de calificaciones mayores a 8.5\n"
			<< "7. Salir\n\n"
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