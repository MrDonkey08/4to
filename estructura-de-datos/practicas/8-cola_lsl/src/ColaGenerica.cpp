#include "../include/ColaGenerica.h"

template <class T> void ColaGenerica<T>::insertar(T elemento) {
	NodoCola *nuevo;
	nuevo = new NodoCola(elemento);
	if (colaVacia()) {
		frente = nuevo;
	} else {
		final->siguiente = nuevo;
	}
	final = nuevo;
}

template <class T> T ColaGenerica<T>::quitar() {
	if (colaVacia())
		throw "Cola vacía, no se puede extraer.";
	T aux = frente->elemento;
	NodoCola *a = frente;
	frente = frente->siguiente;
	delete a;
	return aux;
}
	
template <class T> T ColaGenerica<T>::frenteCola() const {
	if (colaVacia())
		throw "Cola vacía";
	return frente->elemento;
}

template <class T> void ColaGenerica<T>::borrarCola() {
	while (frente != nullptr) {
		NodoCola *a;
		a = frente;
		frente = frente->siguiente;
		delete a;
	}
	final = nullptr;
}

template <class T> bool ColaGenerica<T>::colaVacia() const {
	return frente == nullptr;
}