# Universidad de Guadalajara

## <center>Centro Universitario de Ciencias Exactas E Ingenierías</center>



![Portada-UDG | left | 200](../../../../attachments/images/portada-udg.jpeg) ![Portada-CUCEI | right | 200](../../../../attachments/images/portada-cucei.jpeg)
 
<br> <br> <br> <br> <br><br> <br><br><br><br><br><br><br><br><br><br><br>

### Tarea 5: Búsqueda Binaria

### Estudiante: Juárez Rubio Alan Yahir

### Materia: Estructura de Datos

### Sección: D02

### Calendario: 2023-B

### Profesora: Guerrero Carlos Ana Jazmín

### Fecha de entrega: 23/10/2023

<div style="page-break-after: always;"></div>




# Búsqueda Binaria

## Marco Teórico

1. Explique con sus palabras en qué consiste la búsqueda binaria. (Lectura del punto 10.2.2 páginas 516 a la 519).

La **búsquda binaria** es un algoritmo que consiste en tener un arreglo ordenado ascendentemente para ir dividiéndolo en mitades e ir comparando cada uno de los extremos "en donde se hizo el corte" (por decirlo de una manera). Esto lo hace hasta encontrar la posición del valor o hasta recorrer todo el arreglo. Si encuentra el arreglo, te devuelve la posición, en caso contrario, te devuelve el valor en negativo en dónde se podría insertar dicho elemento manteniendo el orden.

2. Anexar la Figura 10.3 pág. 518 del libro de la maestra Silvia Guardati.

![ | center](attachments/Pasted%20image%2020231023130058.jpg)

### Referencias

- Guardati S. (2007). _ESTRUCTURA DE DATOS ORIENTADA A OBJETOS (1ra ed.)_. Editorial. Pearson

<div style="page-break-after: always;"></div>

## Código

### Main.cpp

```cpp
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
```

<div style="page-break-after: always;"></div>

### Arreglo.h

```cpp
/*
Nombre: Alan Yahir Juárez Rubio
Actividad 5: Búsqueda Binaria
Método de Ordenamiento: Bubble Sort
*/

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

#endif
```

<div style="page-break-after: always;"></div>

### Busqueda.h

```cpp
/*
Nombre: Alan Yahir Juárez Rubio
Actividad 5: Búsqueda Binaria
Método de Ordenamiento: Bubble Sort
*/

#ifndef Arreglo_H
#define Arreglo_H

#include <iostream>

using namespace std;

#define MAX 100
/* Plantilla de la clase Arreglo. Se incluyen sólo los métodos requeridos para la aplicación de la operación de búsqueda. */
template <class T> class Arreglo {
	private:
		T Datos[MAX];
		int Tam;

	public:
		Arreglo();
		void Lectura();
		void Escribe();
		int RegresaTam();
		T RegresaValor(int);
		void Ordenar();
};

/* Declaración del método constructor. Inicializa el número actual de elementos en 0. */
template <class T> Arreglo<T>::Arreglo() { Tam = 0; }
/* Método que permite leer el número de elementos que se van a almacenar y el valor de cada uno de ellos. Valida que el total de elementos sea al menos 1 y que no supere el máximo especificado. */
template <class T> void Arreglo<T>::Lectura() {
	int Indice;

	do {
		cout <<"\n\n Ingrese número de datos a guardar : ";
		cin >> Tam;
	} while ((Tam<1) || (Tam > MAX));
	for (Indice = 0; Indice < Tam; Indice++) {
		cout <<"\nIngrese el "<< Indice + 1 <<" dato : ";
		cin >> Datos[Indice];
	}
}
/* Método que despliega en pantalla los valores almacenados en el Arreglo. */
template <class T> void Arreglo<T>::Escribe() {
	int Indice;
	if (Tam > 0) {
	cout <<"\n Impresión de datos\n";
	for (Indice = 0; Indice < Tam; Indice++)
		cout << '\t' << Datos[Indice];
	} else
	cout << "\nNo hay elementos registrados.";
}
/* Método que permite a usuarios externos a la clase conocer el total de elementos guardados en el Arreglo. */
template <class T> int Arreglo<T>::RegresaTam() { return Tam; }
/* Método que permite a usuarios externos a la clase conocer el dato almacenado en cierta casilla del Arreglo. Recibe como parámetro un entero y regresa como resultado el valor almacenado en la posición indicada por dicho número. */
template <class T> T Arreglo<T>::RegresaValor(int Indice) {
	return Datos[Indice];
}

template <class T> void Arreglo<T>::Ordenar() {
    // Algoritmo de ordenación (Bubble Sort)
    bool swapped;
    for (int i = 0; i < Tam - 1; i++) {
        swapped = false;
        for (int j = 0; j < Tam - i - 1; j++) {
            if (Datos[j] > Datos[j + 1]) {
                // Intercambia Datos[j] y Datos[j + 1]
                T temp = Datos[j];
                Datos[j] = Datos[j + 1];
                Datos[j + 1] = temp;
                swapped = true;
            }
        }
        // Si no hubo intercambios en esta pasada, los datos ya están ordenados
        if (!swapped)
            break;
    }
}

#endif
```

<div style="page-break-after: always;"></div>

### Binaria.h

```cpp
/*
Nombre: Alan Yahir Juárez Rubio
Actividad 5: Búsqueda Binaria
Método de Ordenamiento: Bubble Sort
*/

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
```

<div style="page-break-after: always;"></div>

## Imágenes de la corrida

![ | center |](attachments/0-menu.png)

<center>Menú</center>



![ | center](attachments/1.png)

<center>PASO 1: Llenar el arreglo con 10 datos de tipo entero de forma desordenada</center>

![ | center](attachments/2.png)

<center>PASO 2: Mostrar el arreglo</center>

![ | center](attachments/3.png)

<center>PASO 3: Ordenar el arreglo</center>

![ | center](attachments/4.png)

<center>PASO 4: Elegir la búsqueda binaria y buscar un elemento que SE ENCUENTRA en el arreglo</center>

![ | center](attachments/5.png)

<center>PASO 5: Elegir la búsqueda binaria y buscar un elemento que NO SE ENCUENTRA en el arreglo</center>

![ | center](attachments/6.png)

<center>PASO 6: Salir</center>

<div style="page-break-after: always;"></div>

## Conclusión

En retrospectiva, esta actividad me pareció muy interestante de realizar debido a que aprendí el funcionamiento y la utilidad de los algoritmos de búsqueda. En concreto este se me hizo interesante debido a que, para su funcionamiento, es necesario ordenar el arreglo y, por lo tanto, uno debe escoger el **algoritmo de ordenamiento** más ideal según sea el caso, esto con el fin de mejorar el rendimiento del programa. 

Para finalizar, me gustaría señalar que este algoritmo, a comparación de la **búsqueda secuencial**, analiza el arreglo de una manera más óptima. El punto malo que encuentro en la **búsqueda binara** respecto a la **secuencial** es que forzosamente requiere que el arreglo se encuentre ordenado. 