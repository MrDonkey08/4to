#ifndef Lista_h
#define Lista_h

#include "NodoLista.h"

template <class T> class NodoLista;

template <class T> class Lista {
	private:
		NodoLista<T> *Primero;

	public:
		Lista();
		NodoLista<T> *RegresaPrimero();
		void CreaInicio();
		void CreaFinal();
		void ImprimeIterativo();
		void ImprimeRecursivo(NodoLista<T> *);
		void ImprimeUnNodo(NodoLista<T> *);
		void InsertaInicio(T);
		void InsertaFinal(T);
		void InsertaOrdenCrec(T);
		int InsertaAntes(T, T);
		int InsertaDespues(T, T);
		int EliminaPrimero();
		int EliminaUltimo();
		int EliminaUnNodo(T);
		int EliminaAnterior(T);
		int EliminaDespues(T);
		NodoLista<T> *BuscaDesordenada(T);
		NodoLista<T> *BuscaOrdenada(T);
		NodoLista<T> *BuscaRecursivo(T, NodoLista<T> *);
};

#endif
