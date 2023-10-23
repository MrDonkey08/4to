#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>

template <class T> class Busqueda {
	public:
		virtual int Busca(Arreglo<T>, T) = 0;
};

template <class T>
class SecuencialDesord: public Busqueda<T>{
    public:
    int Busca (Arreglo<T>, T);
};


template <class T>
    int SecuencialDesord<T>::Busca(Arreglo<T> Arre, T Dato){
    int Indice= 0, Posic = -1;
    while (Indice < Arre.RegresaTam() && Dato != Arre.RegresaValor(Indice))
        Indice++;
    if (Indice < Arre.RegresaTam())
        Posic = Indice;
    return Posic;
}

template <class T>
class SecuencialOrdenado: public Busqueda<T>{
    public:
        int Busca (Arreglo<T>, T);
};

template <class T>
int SecuencialOrdenado<T>::Busca(Arreglo<T> Arre, T Dato){
    int Indice= 0, Posic;
    while (Indice < Arre.RegresaTam() && Dato > Arre.RegresaValor(Indice))
        Indice++;
    if (Indice == Arre.RegresaTam() || Dato < Arre.RegresaValor(Indice))
        Posic= -(Indice + 1);
    else
        Posic= Indice;
    return Posic;
}


template <class T>
void Ordenar(Arreglo<T> &Arre) {
    // Algoritmo de ordenación (Bubble Sort)
    int n = Arre.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (Arre[j] > Arre[j + 1]) {
                // Intercambia Arre[j] y Arre[j + 1]
                T temp = Arre[j];
                Arre[j] = Arre[j + 1];
                Arre[j + 1] = temp;
                swapped = true;
            }
        }
        // Si no hubo intercambios en esta pasada, los datos ya están ordenados
        if (!swapped)
            break;
    }
}

#endif
