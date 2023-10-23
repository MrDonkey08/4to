#ifndef BINARIA_H
#define BINARIA_H

#include "Busqueda.h"
#include "Arreglo.h"

/* Definición de la clase encargada de realizar la búsqueda binaria un arreglo ordenado. Es una clase derivada de Busqueda y en ella se especifica el método Busca(). */
template <class T>
class Binaria : public Busqueda <T> {
	public:
		int Busca(Arreglo <T>, T);
};

/* Método que realiza la búsqueda de un elemento en un arreglo cuyos valores están ordenados de manera creciente. Se parte el espacio de búsqueda a la mitad y se compara el dato buscado con el valor que ocupa la posición central. Si son iguales, la búsqueda termina con éxito. En caso contrario se evalúa si es menor o mayor y según sea el caso se redefine el extremo derecho o izquierdo respectivamente y se vuelve a calcular el elemento central. Recibe como parámetros el dato a buscar y el arreglo en el cual se llevará a cabo la operación. Si lo encuentra da como resultado la posición, en caso contrario regresa el negativo de la posición en la que debería estar, más 1. */

template <class T>
int Binaria<T>::Busca(Arreglo<T> Arre, T Dato){
    int Izq = 0, Der = Arre.RegresaTam(), Cen, Posic;
    Cen = (Izq + Der) / 2;

    while (Izq <= Der && Dato != Arre.RegresaValor(Cen)){
        if (Dato < Arre.RegresaValor(Cen))
            Der = Cen - 1;
        else
            Izq = Cen + 1;
        Cen = (Izq + Der) / 2;
    }
    if (Izq <= Der)
        Posic = Cen;
    else
        Posic = -(Izq + 1);
    return Posic;
}

#endif BINARIA_H
