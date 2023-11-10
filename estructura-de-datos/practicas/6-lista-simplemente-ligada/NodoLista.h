#ifndef NodoLista_h
#define NodoLista_h

#include "Lista.h"
template <class T> class Lista;

template <class T> class NodoLista {
	private:
		NodoLista<T> *Liga;
		T Info;

	public:
		NodoLista();
		T RegresaInfo();
		friend class Lista<T>;
};

#endif
