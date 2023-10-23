#include <iostream>
#include <vector>
#include <locale>

#include "Arreglo.h"
#include "Busqueda.h"
#include "Persona.h"

using namespace std;

void menu();
void ordenar();

int main(){
	setlocale(LC_CTYPE, "spanish");

	int opc;

	SecuencialOrdenado<Persona> Buscador;
	Arreglo<Persona> Asistentes;
	int Resp;
	char Nom[64];

	do {
		menu();

		cin >> opc;

		switch (opc){
			case 1: Asistentes.Lectura(); break;
			case 2: Asistentes.Escribe(); break;
			//case 3: Ordenar.Ordenar(Asistentes); break;
			case 4:{
				cout << "\nIngresa el nombre de la persona a buscar: ";
				cin >> Nom;

				Persona Alguien(0,Nom,"");

				if (Resp >= 0)
					cout << "\n\nSe encontró a la persona y sus datos completos son\n" << Asistentes.RegresaValor(Resp) << "\n";
				else
					cout << "\n\nNO se encontró a la persona\n\n";
				break;
			}
			case 5: cout << "\n\nHas salido del programa. ¡Vuelve pronto!\n\n"; break;

			default: cout << "\n\nOpción incorrecta. Inténtalo de nuevo\n\n"; break;
		}
	} while(opc != 5);

	return 0;
}

void menu(){
	cout << "Menú\n\n"
		<< "1. Agregar elementos\n"
		<< "2. Mostrar\n"
		<< "3. Ordenar\n"
		<< "4. Búsqueda Secuencial\n"
		<< "5. Salir\n\n"
		<< "Opción: ";
}
