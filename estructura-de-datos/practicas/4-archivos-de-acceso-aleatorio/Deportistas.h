/*
Castellanos Ramírez Gustavo Fabián
Guzmán Zavala Daniel
Juárez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/

#ifndef DEPORTISTAS_H_INCLUDED
#define DEPORTISTAS_H_INCLUDED
#include <iostream>

using namespace std;

class Deportistas {
	private:
		int numeroDeSocio, edad;
		char nombre[15], deporte[15];

	public:
		Deportistas(int = 0, string = "", int = 0, string = "");
		int getNumeroDeSocio() { return numeroDeSocio; };
		void setNumeroDeSocio(int numeroDeSocio) {
			this->numeroDeSocio = numeroDeSocio;
		};
		void setNombre(string);
		string getNombre() { return nombre; };
		void setEdad(int edad) { this->edad = edad; };
		int getEdad() { return edad; };
		void setDeporte(string);
		string getDeporte() { return deporte; };
};

#endif // DEPORTISTAS_H_INCLUDED
