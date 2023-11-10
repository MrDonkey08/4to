#include "Libro.h"

using namespace std;

Libro::Libro(string nombreLibro, string autor, string editorial) {
	this->nombreLibro = nombreLibro;
	this->autor = autor;
	this->editorial = editorial;
}

void Libro::establecerNombre(string nombreLibro) {
	this->nombreLibro = nombreLibro;
}
void Libro::establecerAutor(string autor) { this->autor = autor; }
void Libro::establecerEditorial(string editorial) {
	this->editorial = editorial;
}

string Libro::obtenerNombre() const { return nombreLibro; }
string Libro::obtenerAutor() const { return autor; }
string Libro::obtenerEditorial() const { return editorial; }

ostream &operator<<(ostream &os, const Libro &Libro) {
	os << "Nombre: " << Libro.obtenerNombre() << endl
		<< "Autor: " << Libro.obtenerAutor() << endl
		<< "Editorial: " << Libro.obtenerEditorial();
	return os;
}
