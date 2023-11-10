#include "Lista.h"
#include <bits/stdc++.h>
using namespace std;

template <class T> Lista<T>::Lista() { Primero = NULL; }

template <class T> NodoLista<T> *Lista<T>::RegresaPrimero() { return Primero; }

template <class T> void Lista<T>::CreaInicio() {
	NodoLista<T> *P;
	T Dato;
	char Resp;

	Primero = new NodoLista<T>();
	cout << "Ingrese la informaci�n a almacenar: \n";
	cin >> Dato;
	Primero->Info = Dato;
	cout << "\n�Desea ingresar otro elemento (S/N)? ";
	cin >> Resp;

	while (Resp == 'S' || Resp == 's') {
		cout << "Ingrese la informaci�n: \n";
		cin >> Dato;
		P = new NodoLista<T>();
		P->Info = Dato;
		P->Liga = Primero;
		Primero = P;
		cout << "\n�Desea ingresar otro elemento (S/N)? ";
		cin >> Resp;
	}
}

template <class T> void Lista<T>::CreaFinal() {
	NodoLista<T> *P, *Ultimo;
	T Dato;
	char Resp;
	Primero = new NodoLista<T>();

	cout << "Ingrese la informaci�n a almacenar: \n";
	cin >> Dato;
	Primero->Info = Dato;

	Ultimo = Primero;
	cout << "\n�Desea ingresar otro elemento (S/N)? ";
	cin >> Resp;

	while (Resp == 'S' || Resp == 's') {
		cout << "\nIngrese la informaci�n \n";
		cin >> Dato;
		P = new NodoLista<T>();
		P->Info = Dato;
		Ultimo->Liga = P;
		Ultimo = P;
		cout << "\n�Desea ingresar otro elemento (S/N)? ";
		cin >> Resp;
	}
}

template <class T> void Lista<T>::ImprimeIterativo() {
	NodoLista<T> *P;
	P = Primero;

	while (P) {
		cout << "\nInformaci�n: " << P->Info;
		P = P->Liga;
	}

	cout << "\n";
}

template <class T> void Lista<T>::ImprimeRecursivo(NodoLista<T> *P) {
	if (P) {
		cout << "\nInformaci�n: " << P->Info;
		ImprimeRecursivo(P->Liga);
	}
	cout << "\n";
}

template <class T> void Lista<T>::ImprimeUnNodo(NodoLista<T> *P) {
	if (P)
		cout << P->Info;
}

template <class T> void Lista<T>::InsertaInicio(T Dato) {
	NodoLista<T> *P;
	P = new NodoLista<T>();
	P->Info = Dato;
	P->Liga = Primero;
	Primero = P;
}

template <class T> void Lista<T>::InsertaFinal(T Dato) {
	NodoLista<T> *P, *Ultimo;

	P = new NodoLista<T>();
	P->Info = Dato;

	if (Primero) {
		Ultimo = Primero;
		while (Ultimo->Liga)
			Ultimo = Ultimo->Liga;

		Ultimo->Liga = P;
	} else
		Primero = P;
}

template <class T> void Lista<T>::InsertaOrdenCrec(T Dato) {
	NodoLista<T> *P, *Q, *Ant;

	if (!Primero || Primero->Info > Dato)
		InsertaInicio(Dato);
	else {
		Q = Primero;

		while (Q && Q->Info < Dato) {
			Ant = Q;
			Q = Q->Liga;
		}

		P = new NodoLista<T>();
		P->Info = Dato;
		Ant->Liga = P;
		P->Liga = Q;
	}
}

template <class T> int Lista<T>::InsertaAntes(T Dato, T Ref) {
	NodoLista<T> *P, *Ant, *Q;
	int Resp = 1;

	if (Primero) {
		Q = Primero;
		while ((Q != NULL) && (Q->Info != Ref)) {
			Ant = Q;
			Q = Q->Liga;
		}
		if (Q != NULL) {
			P = new NodoLista<T>();
			P->Info = Dato;
			/* El dato de referencia es el primero de la lista. */
			if (Primero == Q) {
				P->Liga = Primero;
				Primero = P;
			} else {
				Ant->Liga = P;
				P->Liga = Q;
			}
		} else
			/* No se encontr� el dato dado como referencia. */
			Resp = 0;
	} else
		/* La lista est� vac�a. */
		Resp = -1;

	return Resp;
}

template <class T> int Lista<T>::InsertaDespues(T Dato, T Ref) {
	NodoLista<T> *Q, *P;
	int Resp = 1;

	if (Primero) {
		Q = Primero;

		while ((Q != NULL) && (Q->Info != Ref))

			Q = Q->Liga;

		if (Q != NULL) {
			P = new NodoLista<T>();
			P->Info = Dato;
			P->Liga = Q->Liga;
			Q->Liga = P;
		}

		else
			Resp = 0;
	}

	else
		Resp = -1;

	return Resp;
}

template <class T> int Lista<T>::EliminaPrimero() {
	NodoLista<T> *P;
	int Resp = 1;

	if (Primero) {
		P = Primero;
		Primero = P->Liga;
		delete (P);
	}

	else
		Resp = 0;

	return Resp;
}

template <class T> int Lista<T>::EliminaUltimo() {
	NodoLista<T> *Ant, *P;

	int Resp = 1;

	if (Primero) {
		if (!Primero->Liga) {
			delete (Primero);
			Primero = NULL;
		} else {
			P = Primero;

			while (P->Liga) {
				Ant = P;
				P = P->Liga;
			}

			Ant->Liga = NULL;
			delete (P);
		}
	}

	else
		Resp = 0;

	return Resp;
}

template <class T> int Lista<T>::EliminaUnNodo(T Ref) {
	NodoLista<T> *P, *Ant;
	int Resp = 1;

	if (Primero) {
		P = Primero;

		while ((P->Liga) && (P->Info != Ref)) {
			Ant = P;
			P = P->Liga;
		}

		if (P->Info != Ref)
			Resp = 0;

		else {
			if (Primero == P)
				Primero = P->Liga;

			else
				Ant->Liga = P->Liga;

			delete (P);
		}
	}

	else
		Resp = -1;
	return Resp;
}

template <class T> int Lista<T>::EliminaAnterior(T Ref) {
	NodoLista<T> *Q, *Ant, *P;
	int Resp = 1;
	if (Primero) {
		if (Primero->Info == Ref)

			Resp = 2;

		else {
			Q = Primero;
			Ant = Primero;

			while ((Q->Info != Ref) && (Q->Liga)) {
				P = Ant;
				Ant = Q;
				Q = Q->Liga;
			}

			if (Q->Info != Ref)
				Resp = 3;

			else if (Primero->Liga == Q) {
				delete (Primero);
				Primero = Q;
			}

			else {
				P->Liga = Q;
				delete (Ant);
			}
		}
	}

	else
		Resp = 4;

	return Resp;
}

template <class T> NodoLista<T> *Lista<T>::BuscaDesordenada(T Ref) {
	NodoLista<T> *Q, *Resp = NULL;
	if (Primero) {
		Q = Primero;

		while ((Q->Info != Ref) && (Q->Liga))
			Q = Q->Liga;

		if (Q->Info == Ref)
			Resp = Q;
	}

	return Resp;
}

template <class T> NodoLista<T> *Lista<T>::BuscaOrdenada(T Ref) {
	NodoLista<T> *Q, *Resp = NULL;

	if (Primero) {
		Q = Primero;

		while ((Q->Info < Ref) && (Q->Liga))
			Q = Q->Liga;

		if (Q->Info == Ref)

			Resp = Q;
	}

	return Resp;
}

template <class T>
NodoLista<T> *Lista<T>::BuscaRecursivo(T Dato, NodoLista<T> *Q) {
	if (Q)
		if (Q->Info == Dato)
			return Q;

		else
			return BuscaRecursivo(Dato, Q->Liga);

	else
		return NULL;
}
