/*
Nombre: Alan Yahir Juárez Rubio
Actividad 5: Búsqueda Binaria
Método de Ordenamiento: Bubble Sort
*/

#include <iostream>
#include <locale>

#include "Arreglo.h"
#include "Busqueda.h"
#include "Binaria.h"

using namespace std;

void menu();
void ordenar();

int main(){
	setlocale(LC_CTYPE, "spanish");

	int opc, dato, posic;
	bool ordenado = false;

	Arreglo<int> vec;
	Binaria<int> busqueda;

	do {
		menu();
		cin >> opc;
        cout << "\n";

		switch (opc){
			case 1: vec.Lectura(); break;
			case 2: vec.Escribe(); break;
			case 3:
			    ordenado = true;
			    vec.Ordenar(); break;
			case 4:
			    if(ordenado == true){
                    cout << "Ingresa el número a buscar: "; cin >> dato;

                    posic = busqueda.Busca(vec, dato);

                    if (posic < 0) {
                        cout << "\nDato no encontrado en el arreglo." << endl;
                    } else {
                        cout << "\nEl valor " << dato << " fue encontrado en la posición " << posic << endl;
                    }

			    } else{
                    cout << "\nArreglo no ordenado. Use la función para ordenar e inténtelo de nuevo\n\n";
			    }
                break;

			case 5: cout << "\n\nHas salido del programa. ¡Vuelve pronto!\n\n"; break;

			default: cout << "\n\nOpción incorrecta. Inténtalo de nuevo\n\n"; break;
		}
	} while(opc != 5);

	return 0;
}

void menu(){
	cout << "\nMenú\n\n"
		<< "1. Agregar elementos\n"
		<< "2. Mostrar\n"
		<< "3. Ordenar\n"
		<< "4. Búsqueda Secuencial\n"
		<< "5. Salir\n\n"
		<< "Opción: ";
}
