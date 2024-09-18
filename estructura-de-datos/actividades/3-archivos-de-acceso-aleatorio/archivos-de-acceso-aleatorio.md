# Archivos de Acceso Aleatorio

## Marco Teórico

1. Los sistemas de reservación de aerolíneas, sistemas bancarios, sistemas de
   punto de venta, cajeros automáticos y demás tipos de sistemas de
   procesamiento de transacciones son ejemplos de aplicaciones de procesamiento
   de **archivos de acceso aleatorio**.

<a>

2. Como lo hemos dicho antes C++ no impone una estructura en un archivo. De esta
   forma, las aplicaciones que deseen utilizar archivos de acceso aleatorio
   deben crearlos. Puede utilizarse una variedad de técnicas para crear archivos
   de este tipo. Tal vez el método más sencillo sea requerir que todos los
   registros en un archivo sean **del mismo tamaño**.

<a>

3. Dibujar la Fig. 17.9 de la pág. 722 del libro del maestro Deitel 6ta. edición

![](attachments/fig-17.9-pp.722.jpg)

4. ¿Para qué sirve la función seekp( )?

La función seekp() en C++ se utiliza para establecer la posición de escritura en
un archivo de salida. Permite mover el puntero de escritura a una ubicación
específica en el archivo, lo que es útil cuando se necesita escribir datos en
una posición específica en lugar de al final del archivo.

5. ¿Para qué sirve la función write( )?

La función write() en C++ se utiliza para escribir datos en un archivo binario.
Permite escribir una secuencia de bytes en el archivo, que puede ser cualquier
tipo de datos, como estructuras o registros. Es útil para almacenar información
en archivos binarios.

6. ¿Para qué sirve el operador reinterpret_cast?

El operador reinterpret_cast en C++ se utiliza para convertir un puntero de un
tipo a otro sin cambiar el valor apuntado. Se utiliza principalmente en
situaciones donde se necesita convertir un puntero a un tipo de dato en otro
tipo de dato, como cuando se trabaja con archivos binarios y se necesita
interpretar los bytes en una estructura específica. Es importante usarlo con
precaución, ya que puede generar problemas si no se realiza correctamente.

<div style="page-break-after: always;"></div>

## Código

### main.cpp

```cpp
// Juárez Rubio Alan Yahir

//Como escribir en un archivo de acceso aleatorio

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>

#include "Deportista.h"
using namespace std;

int main(){
	setlocale(LC_CTYPE, "spanish");

	// variables locales a main
	int edad, numeroDeSocio;
	char nombre[15];
	char deporte[10];

	Deportista d; // Objeto Deportista
	ofstream archDeportistaSalida; // archivo logico
	archDeportistaSalida.open("deportistas.dat", ios::binary);

	// salir del programa si ofstream no puede abrir el archivo
	if (!archDeportistaSalida) {
		cerr << "No se pudo abrir el archivo. " << endl;
		exit(1);
	}
	cout << "Escriba el numero de socio (De 1 a 100, 0 para terminar la entrada)\n? ";
	cin >> numeroDeSocio;
	d.establecerNumeroDeSocio(numeroDeSocio);

	// el usuario proporciona la informacion que se guarda en el archivo
	while(d.obtenerNumeroDeSocio()>=1&&d.obtenerNumeroDeSocio()<=100){
		cout << "Teclea nombre, edad y deporte\n? ";
		cin >> setw(15) >> nombre;
		cin >> edad;
		cin >> setw(15) >> deporte;

		// establecer los valores nombre, edad y deporte del registro
		d.establecerNombre(nombre);
		d.establecerEdad(edad);
		d.establecerDeporte(deporte);

		// buscar la posicion en el archivo del registro especifico por el usuario
		archDeportistaSalida.seekp((d.obtenerNumeroDeSocio() - 1) *sizeof(Deportista)); // see kp(n,ios::beg)

		// escribir la informacion especificada por el usuario en el archivo
		archDeportistaSalida.write(reinterpret_cast<const char *>(&d), sizeof(Deportista));

		// permitir que el usuario especifique otro numero de socio
		cout << "Escriba el numero de socio (De 1 a 100, 0 para terminar la entrada)\n? ";
		cin >> numeroDeSocio;
		d.establecerNumeroDeSocio(numeroDeSocio);
	}

	archDeportistaSalida.close();
	return 0;
}
```

<div style="page-break-after: always;"></div>

### Deportista.h

```cpp
// Juárez Rubio Alan Yahir

#ifndef DEPORTISTA_H
#define DEPORTISTA_H

#include <iostream>
#include <string>

using namespace std;

class Deportista {
	private:
		int NumeroDeSocio;
		string Nombre;
		int Edad;
		string Deporte;

	public:
		Deportista();
		Deportista(int, string, int, string);

		void establecerNumeroDeSocio(int);
		int obtenerNumeroDeSocio();

		void establecerNombre(string);
		string obtenerNombre();

		void establecerEdad(int);
		int obtenerEdad();

		void establecerDeporte(string);
		string obtenerDeporte();
};

#endif
```

<div style="page-break-after: always;"></div>

### Deportista.cpp

```cpp
// Juárez Rubio Alan Yahir

#include <iostream>
#include <string>

#include "Deportista.h"

using namespace std;

void Deportista::establecerNumeroDeSocio(int NumeroDeSocio) {
    this->NumeroDeSocio = NumeroDeSocio;
}

void Deportista::establecerNombre(string Nombre) {
    this->Nombre = Nombre;
}

void Deportista::establecerEdad(int Edad) {
    this->Edad = Edad;
}

void Deportista::establecerDeporte(string Deporte) {
    this->Deporte = Deporte;
}

int Deportista::obtenerNumeroDeSocio() {
    return NumeroDeSocio;
}

string Deportista::obtenerNombre() {
    return Nombre;
}

int Deportista::obtenerEdad() {
    return Edad;
}

string Deportista::obtenerDeporte() {
    return Deporte;
}

Deportista::Deportista() {
    NumeroDeSocio = 0;
    Nombre = "";
    Edad = 0;
    Deporte = "";
}
Deportista::Deportista(int NumeroDeSocio, string Nombre, int Edad, string Deporte) {
    establecerNumeroDeSocio(NumeroDeSocio);
    establecerNombre(Nombre);
    establecerEdad(Edad);
    establecerDeporte(Deporte);
}
```

<div style="page-break-after: always;"></div>

## Imágenes de ejecución

![ |  center](attachments/output.jpg)

![ | center](attachments/dat-1.jpg)

![ | center](attachments/dat-2.jpg)

<div style="page-break-after: always;"></div>

## Conclusión

Para finalizar, esta práctica se me hizo interesante ya que no solo guardamos
datos de manera permanente, sino que los guardamos en bloques de bytes, lo cual
permite gestionar los datos de una manera más sencillas. Entiendo el código y
todo, pero no entiendo el porqué trabajar con un archivo binario como ".dat".
