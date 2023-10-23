#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <vector>
#include <locale>
#include <string.h>

using namespace std;

/* Definición de la clase Persona. Se incluyen sobrecarga de operadores para que objetos de este tipo puedan ser usados directamente en la operación de búsqueda. */
class Persona {
	private:
		int AnioNac;
		char NomPers[64], LugNac[64];

	public:
		Persona();
		Persona(int, char[], char[]);
		int operator>(Persona);
		int operator<(Persona);
		friend istream &operator>>(istream &,  Persona &);
		friend ostream &operator<<(ostream &, const Persona &);
};

Persona::Persona() {}

Persona::Persona(int ANac, char NomP[], char LugN[]) {
	AnioNac = ANac;
	strcpy(NomPers, NomP);
	strcpy(LugNac, LugN);
}
/* Sobrecarga del operador > para comparar dos objetos de la clase Persona. Una persona es "mayor que" otra si su nombre lo es. Este operador permitirá buscar a una persona, por su nombre, en un arreglo de personas ordenado alfabéticamente. */
int Persona::operator>(Persona Pers) {
	int Resp = 0;
	if (strcmp(NomPers, Pers.NomPers) > 0)
	Resp = 1;
	return Resp;
}
/* Sobrecarga del operador < para comparar dos objetos de la clase Persona. Una persona es "menor que" otra si su nombre lo es. Este operador permitirá buscar a una persona, por su nombre, en un arreglo de personas ordenado alfabéticamente. */
int Persona::operator<(Persona Pers) {
	int Resp = 0;
	if (strcmp(NomPers, Pers.NomPers) < 0)
	Resp = 1;
	return Resp;
}
/* Sobrecarga del operador >> para que un objeto tipo Persona pueda ser leído directamente. */
istream &operator>>(istream &Lee, Persona &ObjPers) {
	cout <<"\n\nIngrese nombre de la Persona : ";
	Lee >> ObjPers.NomPers;
	cout <<"\n\nIngrese año de nacimiento : ";
	Lee >> ObjPers.AnioNac;
	cout <<"\n\nIngrese lugar de nacimiento : ";
	Lee >> ObjPers.LugNac;
	return Lee;
}

/* Sobrecarga del operador << para que un objeto tipo Persona pueda ser impreso directamente. */
ostream &operator<<(ostream &Escribe, const Persona &ObjPers) {
	Escribe <<"\n\nDatos de la Persona\n";
	Escribe <<"\nNombre : "<< ObjPers.NomPers;
	Escribe <<"\nLugar de nacimiento : "<< ObjPers.LugNac;
	Escribe <<"\nAño de nacimiento : "<< ObjPers.AnioNac;
	return Escribe;
}

#endif
