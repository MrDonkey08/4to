#ifndef Libro_h
#define Libro_h

#include <bits/stdc++.h>

using namespace std;

class Libro {
	private:
		string 
			nombreLibro = "",
			autor = "", 
			editorial = "";

	public:
		Libro() {}
		Libro(string, string, string);
		~Libro() {}

		void establecerNombre(string);
		void establecerAutor(string);
		void establecerEditorial(string);

		string obtenerNombre() const;
		string obtenerAutor() const;
		string obtenerEditorial() const;

		friend ostream &operator<<(std::ostream &os, const Libro &Libro);
};

#endif
