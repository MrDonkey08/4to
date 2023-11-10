#include "PilaGenerica.h"

using namespace std;

template <class T> const bool PilaGenerica<T>::pilaVacia() {
	return cima == NULL;
}

template <class T> void PilaGenerica<T>::insertar(T elemento) {
	NodoPila *nuevo;
	nuevo = new NodoPila(elemento);
	nuevo->siguiente = cima;
	cima = nuevo;
}

template <class T> T PilaGenerica<T>::quitar() {
	if (pilaVacia())
		throw "Pila vacia, no se puede extraer.";
	T aux = cima->elemento;
	cima = cima->siguiente;
	return aux;
}

template <class T> T PilaGenerica<T>::cimaPila(){
	if (pilaVacia())
		throw "Pila vacia";
	return cima->elemento;
}

template <class T> const void PilaGenerica<T>::limpiarPila() {
	NodoPila *n;
	while (!pilaVacia()) {
		n = cima;
		cima = cima->siguiente;
		delete n;
	}
}
