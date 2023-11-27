#include "ArbolAVL.h"
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
int ArbolAVL<T>::altura(NodoAVL<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura;
}

template <typename T>
int ArbolAVL<T>::balance(NodoAVL<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionDerecha(NodoAVL<T>* y) {
    NodoAVL<T>* x = y->izquierda;
    NodoAVL<T>* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = std::max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = std::max(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionIzquierda(NodoAVL<T>* x) {
    NodoAVL<T>* y = x->derecha;
    NodoAVL<T>* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = std::max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = std::max(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::insertar(NodoAVL<T>* nodo, const T& valor) {
    // Implementa la inserción normal de un árbol binario de búsqueda.
    if (nodo == nullptr) {
        return new NodoAVL<T>(valor);
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    } else {
        // No permitir duplicados (puedes manejarlo de otra manera si lo deseas).
        return nodo;
    }

    // Actualizar la altura de este nodo.
    nodo->altura = 1 + std::max(altura(nodo->izquierda), altura(nodo->derecha));

    // Obtener el factor de equilibrio de este nodo.
    int factorEquilibrio = balance(nodo);

    // Casos de rotación.
    // Rotación simple a la derecha.
    if (factorEquilibrio > 1 && valor < nodo->izquierda->dato) {
        return rotacionDerecha(nodo);
    }
    // Rotación simple a la izquierda.
    if (factorEquilibrio < -1 && valor > nodo->derecha->dato) {
        return rotacionIzquierda(nodo);
    }
    // Rotación doble a la izquierda-derecha.
    if (factorEquilibrio > 1 && valor > nodo->izquierda->dato) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }
    // Rotación doble a la derecha-izquierda.
    if (factorEquilibrio < -1 && valor < nodo->derecha->dato) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

template <typename T>
void ArbolAVL<T>::insertar(const T& valor) {
    raiz = insertar(raiz, valor);
}

// Implementa la función destructora para liberar la memoria.
template <typename T>
ArbolAVL<T>::~ArbolAVL() {
    // Puedes implementar la liberación de la memoria aquí.
    // Por ejemplo, utilizando un recorrido postorden para eliminar los nodos.
}

template <typename T>
void  ArbolAVL<T>::recorridoInOrderAux(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        recorridoInOrderAux(nodo->izquierda);
        std::cout << nodo->dato << " ";
        recorridoInOrderAux(nodo->derecha);
    }
}

template <typename T>
void  ArbolAVL<T>::ArbolAVL::recorridoInOrder() {
    recorridoInOrderAux(raiz);
    std::cout << std::endl;
}