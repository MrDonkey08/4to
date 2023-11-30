/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/ 

#ifndef ERROR_H 
#define ERROR_H

#include <iostream>
#include <limits>

using namespace std;

inline void opcInvalida() { cout << "Opción inválida. Intentalo de nuevo."; }

inline bool errorNumero() {
	bool error = 0;

	if(cin.fail()) {
		error = 1;
		// Si la entrada no es un número entero válido
		cin.clear(); // Restablecer el estado de error
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
		cout << "\nError: Ingrese un número válido.\n";
	}

	return error;
}

#endif