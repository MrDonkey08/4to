#ifndef ARBOLAVL_H
#define ARBOLAVL_H

template <typename T>
class NodoAVL {
public:
    T dato;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL(const T& valor) : dato(valor), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

template <typename T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;

    int altura(NodoAVL<T>* nodo);
    int balance(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* y);
    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* x);
    NodoAVL<T>* insertar(NodoAVL<T>* nodo, const T& valor);

public:
    ArbolAVL() : raiz(nullptr) {}
    ~ArbolAVL();

    void insertar(const T& valor);
	void recorridoInOrderAux(NodoAVL<T>* nodo);
	void recorridoInOrder();    // Puedes agregar más funciones según tus necesidades, como eliminar, buscar, recorrer, etc.
};

#endif
