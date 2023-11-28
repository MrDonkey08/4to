/* Aplicación del concepto de gráficas para encontrar el conjunto mínimo de carreteras, con el menor costo asociado, que una un grupo de ciudades. */
#include "Grafica.h"
#include "Grafica.cpp"

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
bool errorNumero();

int main() {
	setlocale(LC_CTYPE, "Spanish");
	limpiarPantalla();

	short int opc;
	Grafica<int> Caminos;
	bool datosIngresados = 0;

	do {
		opc = menu();

		switch (opc) {
			case 1:
				cout << "Ingrese datos de las ciudades (vértices) y de las carreteras (aristas)\n";
				Caminos.Lee();
				datosIngresados = 1;
				break;

			cout << "Datos Ingresados: " << datosIngresados << endl;

			case 2:
			case 3:
			case 4:
				if (datosIngresados) {
					switch (opc) {
						case 2: Caminos.Imprime(); break;

						case 3:
							cout << "La red mínima de carreteras requerida para unir todas las ciudades es :\n";
							Caminos.Kruskal();
							break;

						case 4: Caminos.Prim(); break;
					}
				} else {
					cout << "Error: No se han introducido datos.";
				}
				break;

			case 5:
				cout << "Adiós, !bonito día! !Vuelve pronto!\n\n"
					<< "Presiona <enter> para salir";
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
			<<	"Menú del Sistema\n\n"
			<< "Digite una opción\n\n"
			<< "1. Ingresar datos de la Gráfica\n"
			<< "2. Imprimir datos de la Gráfica\n"
			<< "3. Usar método de Kruskal\n"
			<< "4. Usar método de Prim\n"
			<< "5. Salir del programa\n\n"
			<< "Opción: ";
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

void opcInvalida() { cout << "Opción inválida. Inténtelo de nuevo."; }

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

/*
Capturar y probar el programa 8.3 (le falta la función imprime la cual se puede reutilizar de la pág. 415) y programa 8.4 (le falta un menú) con los datos de la figura 8.16 y la tabla 8.11. Del libro de Estructura de Datos Orientada a Objetos Algoritmos con C++ de laAutora: Silvia Guardati
*/