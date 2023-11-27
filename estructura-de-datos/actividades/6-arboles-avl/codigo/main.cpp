#include <iostream>
#include "ArbolAVL.h"
#include "ArbolAVL.cpp"

int main() {
    ArbolAVL<int> arbol;

    // Insertar elementos en el árbol AVL.
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(30);
    arbol.insertar(15);
    arbol.insertar(5);

    // Mostrar el árbol antes de las rotaciones.
    std::cout << "Árbol AVL antes de las rotaciones:" << std::endl;
    arbol.recorridoInOrder(); 

    // Insertar un elemento que requiere una rotación.
    arbol.insertar(25);

    // Mostrar el árbol después de las rotaciones.
    std::cout << "\nÁrbol AVL después de la inserción y rotaciones:" << std::endl;
    arbol.recorridoInOrder(); 

    return 0;
}
