/*
Castellanos Ramírez Gustavo Fabián
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

#include "Deportistas.h"
#include <iostream>
#include <string.h>

using namespace std;

Deportistas::Deportistas(int valorNumeroDeSocio, string valorNombre, int valorEdad, string valorDeporte) {
	setNumeroDeSocio(valorNumeroDeSocio);
	setNombre(valorNombre);
	setEdad(valorEdad);
	setDeporte(valorDeporte);
}

void Deportistas::setNombre(string cadenaNombre) {
	// copia a lo más 15 caracteres de la cadena a apellidoPaterno
	const char *valorNombre = cadenaNombre.data();
	int longitud = cadenaNombre.size();
	longitud = (longitud < 15 ? longitud : 14);
	strncpy(nombre, valorNombre, longitud);
	nombre[longitud] = '\0'; // adjunta un carácter nulo a apellidoPaterno
}

void Deportistas::setDeporte(string cadenaDeporte) {
	// copia a lo más 15 caracteres de la cadena a apellidoPaterno
	const char *valorDeporte = cadenaDeporte.data();
	int longitud = cadenaDeporte.size();
	longitud = (longitud < 15 ? longitud : 14);
	strncpy(deporte, valorDeporte, longitud);
	deporte[longitud] = '\0'; // adjunta un carácter nulo a apellidoPaterno
}