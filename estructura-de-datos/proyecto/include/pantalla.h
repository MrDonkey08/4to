/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/ 

#ifndef PANTALLA_H 
#define PANTALLA_H

#include <iostream>
#include <limits>

using namespace std;

// Para limpiar pantalla en diferentes SO's
#ifdef _WIN32
#include <cstdlib> // Para Windows
#else
#include <unistd.h> // Para sistemas basados en Unix/Linux
#endif

inline void limpiarPantalla() { system("clear || cls"); }

inline void pausarPantalla() {
	cout << "\n\nPresiona <enter> para continuar.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada después de cada opción
    cin.get();
}

#endif