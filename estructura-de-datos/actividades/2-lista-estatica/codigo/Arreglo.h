/*
- Nombre: Alan Yahir Juárez Rubio
- Actividad 2: ADT - Listas Estáticas
*/

#ifndef ARREGLO_H
#define ARREGLO_H

#define MAX 80

#include <iostream>

using namespace std;

template <class T>
class Arreglo {
	private:
		T Datos[MAX];
		int Tam;

	public:
		Arreglo(int);
		void Escribir();
		void Leer();
		T BuscaMayor() const;
		T BuscaMenor() const;
		int ImprimirTotalMenor(T limite) const;
		int ImprimirTotalMayor(T limite) const;
};

#endif
