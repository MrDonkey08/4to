/*
- Nombre: Alan Yahir Juárez Rubio
- Actividad 2: ADT - Listas Estáticas
*/

#include "Arreglo.h"

template <class T>
Arreglo<T>::Arreglo(int Valor) {
	Tam = Valor;
}

template <class T>
void Arreglo<T>::Escribir() {
	int Indice;
	do {
		cout << "Ingrese el total de elementos : ";
		cin >> Tam;
	} while (Tam < 1 || Tam > MAX);

	cout << "\nIngrese los datos:\n\n";

	for (Indice = 0; Indice < Tam; Indice++) {
		cout << Indice  + 1 << ": ";
		cin >> Datos[Indice];
	}
}

template <class T>
void Arreglo<T>::Leer() {
	int Indice;
	for (Indice = 0; Indice < Tam; Indice++)
		cout << Indice + 1 << ". " << Datos[Indice] << endl;
}

template <class T>
T Arreglo<T>::BuscaMayor() const {
    T mayor = Datos[0];
    for (int i = 1; i < Tam; i++) {
        if (Datos[i] > mayor) {
            mayor = Datos[i];
        }
    }
    return mayor;
}

template <class T>
T Arreglo<T>::BuscaMenor() const {
    T menor = Datos[0];
    for (int i = 1; i < Tam; i++) {
        if (Datos[i] < menor) {
            menor = Datos[i];
        }
    }
    return menor;
}

template <class T>
int Arreglo<T>::ImprimirTotalMenor(T limite) const {
    int total = 0;
    for (int i = 0; i < Tam; i++) {
        if (Datos[i] < limite) {
            total++;
        }
    }
    cout << "Total de calificaciones menores a " << limite << ": " << total << endl;
    return total;
}

template <class T>
int Arreglo<T>::ImprimirTotalMayor(T limite) const {
    int total = 0;
    for (int i = 0; i < Tam; i++) {
        if (Datos[i] > limite) {
            total++;
        }
    }
    cout << "Total de calificaciones mayores a " << limite << ": " << total << endl;
    return total;
}