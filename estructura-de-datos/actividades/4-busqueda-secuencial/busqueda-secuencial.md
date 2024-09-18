# Búsqueda Secuencial

## Marco Teórico

1. Anexar la Figura 10.1 pág. 507 del libro de la maestra Silvia Guardati

![ | center](attachments/figura.jpg)

2. ¿Qué es la búsqueda secuencial? pág. 508

La búsqueda secuencial consiste en recorrer el arreglo, elemento por elemento,
empezando con el primero, hasta llegar al dato buscado o hasta que se hayan
evaluado todos los componentes del arreglo. Esta última condición se modifica si
el arreglo está ordenado.

**Referencias:** Guardati S. (2007). _ESTRUCTURA DE DATOS ORIENTADA A OBJETOS
(1ra ed.)_. Editorial. Pearson

<div style="page-break-after: always;"></div>

## Código

```cpp
/*
Juárez Rubio Alan Yahir
Actividad: Búsqueda Secuencial
Algoritmo de ordenamiento: Bubble Sort
*/

#include <iostream>
#include <vector>
#include <locale>

using namespace std;

template <class T> class Busqueda {
	public:
		virtual int Busca(vector<T>, T) = 0;
		virtual void Ordenar(vector<T> &) = 0;
};

template <class T> class SecuencialDesord : public Busqueda<T> {
	public:
		int Busca(vector<T> Arre, T Dato) {
			int Indice = 0, Posic = -1;
			while (Indice < Arre.size() && Dato != Arre[Indice])
				Indice++;
			if (Indice < Arre.size())
				Posic = Indice;
			return Posic;
		}

		void Ordenar(vector<T> &Arre) {
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
};

int main() {
	setlocale(LC_CTYPE, "spanish");

	vector<int> miArreglo;
	SecuencialDesord<int> busqueda;

	int opc;
	bool datosIngresados = false;

	do {
		cout << "MENÚ - BUSQUEDA SECUENCIAL\n"
			<< "1. Llenar el arreglo (desordenado)\n"
			<< "2. Mostrar el arreglo\n"
			<< "3. Búsqueda desordenada\n"
			<< "4. Ordenar el arreglo\n"
			<< "5. Búsqueda ordenada\n"
			<< "0. Salir\n"
			<< "Elige tu opción: ";
		cin >> opc;

		switch (opc) {
			case 1:
				// Ingresar varios datos
				int numDatos;
				cout << "¿Cuántos datos desea ingresar? ";
				cin >> numDatos;

				if (numDatos <= 0) {
					cout << "Número de datos no válido. Debe ser un número positivo.\n";
				} else {
					for (int i = 0; i < numDatos; i++) {
						int dato;
						cout << "Ingrese el dato #" << (i + 1) << ": ";
						cin >> dato;
						miArreglo.push_back(dato);
					}
					datosIngresados = true;
					cout << numDatos << " datos han sido ingresados.\n";
				}
				break;

			case 2:
				// Imprimir datos
				if (datosIngresados) {
					cout << "Datos en el arreglo:\n";
					for (const auto &elem : miArreglo) {
						cout << elem << " ";
					}
					cout << endl;
				} else {
					cout << "No se han ingresado datos.\n";
				}
				break;

			case 3:
				// Búsqueda desordenada
				if (datosIngresados) {
					int datoABuscar;
					cout << "Ingrese el dato que desea buscar: ";
					cin >> datoABuscar;
					int posicion = busqueda.Busca(miArreglo, datoABuscar);
					if (posicion != -1) {
						cout << "El dato " << datoABuscar
											<< " se encuentra en la posición " << posicion + 1 << "."
											<< endl;
					} else {
						cout << "El dato no se encuentra en el arreglo.\n";
					}
				} else {
					cout << "No se han ingresado datos.\n";
				}
				break;

			case 4:
				// Ordenar datos e imprimirlos
				if (datosIngresados) {
					busqueda.Ordenar(miArreglo);
					cout << "Datos ordenados:\n";
					for (const auto &elem : miArreglo) {
						cout << elem << " ";
					}
					cout << endl;
				} else {
					cout << "No se han ingresado datos.\n";
				}
				break;

			case 5:
				// Búsqueda ordenada
				cout << "Esta opción aún no ha sido implementada.\n";
				break;

			case 0:
				// Salir
				cout << "Saliendo del programa.\n";
				break;

			default:
				cout
						<< "Opción inválida. Por favor, seleccione una opción válida."
						<< endl;
				break;
		}
	} while (opc != 0);

	return 0;
}
```

<div style="page-break-after: always;"></div>

## Imágenes de la corrida

![ | center](attachments/A4-1.jpg)

![ | center](attachments/A4-2.jpg)

![ | center](attachments/A4-3.jpg)

![ | center](attachments/A4-4.jpg)

![ | center](attachments/A4-5.jpg)

![ | center](attachments/A4-6.jpg)

![ | center](attachments/A4-7.jpg)

![ | center](attachments/A4-8.jpg)

![ | center](attachments/A4-9.jpg)

![ | center](attachments/A4-10.jpg)

![ | center](attachments/A4-11.jpg)

![ | center](attachments/A4-12.jpg)

![ | center](attachments/A4-13.jpg)

![ | center](attachments/A4-14.jpg)
