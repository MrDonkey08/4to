#include "Lista.cpp"
#include "Lista.h"
#include "NodoLista.cpp"
#include "NodoLista.h"
#include "Producto.h"
#include <bits/stdc++.h>
#include <iostream>

#include <fstream>
#include <cstdlib>

using namespace std;

int Menu() {
	setlocale(LC_CTYPE, "Spanish");

	int Opc;

	cout << "\n\nBienvenido al sistema de registro de productos.\n\n"
		<< "\n(1) Registrar un nuevo producto.\n"
		<< "\n(2) Dar de baja un producto.\n"
		<< "\n(3) Verificar si un producto ya fue registrado.\n"
		<< "\n(4) Imprimir la lista de productos registrados.\n"
		<< "\n(5) Salir.\n"
		<< "\n\nIngrese opci�n de trabajo: ";
	cin >> Opc;
	return Opc;
}

int main() {
    ofstream lista;

	Lista<Producto> ListaProds;
	Producto ObjProd;
	NodoLista<Producto> *Apunt;
	int Opc, Res, Clave;

    lista.open("prod_electronicos.dat", ios::binary);

    if(!lista) {
        cerr << "No se pudo abrir el archivo \n";
        exit(1);
    }

	Opc = Menu();

	while (Opc >= 1 && Opc <= 4) {
		switch (Opc) {
		case 1: {
			cout << "\n\nIngrese datos del producto a registrar:";
			cin >> ObjProd;

			Producto Produc(ObjProd.ObtenerClave(), " ", 0);
			Apunt = ListaProds.BuscaOrdenada(Produc);

			if (!Apunt){
                ListaProds.InsertaOrdenCrec(ObjProd);
                lista << ObjProd << endl;
			} else {
				cout << "\nClave utilizada.\n";
			}

			break;
		}

		case 2: {
			cout << "\n\nIngrese la clave del producto a eliminar: ";
			cin >> Clave;

			Producto Produc(Clave, " ", 0);
			Res = ListaProds.EliminaUnNodo(Produc);

			switch (Res) {
			case 1:
				cout << "\n\nEl producto ya fue eliminado.\n";

				break;

			case 0:
				cout << "\n\nEse producto no se ? encuentra registrado.\n";

				break;

			case -1:
				cout << "\n\nNo hay productos ? registrados.\n";

				break;
			}
		} break;
		case 3: {
			cout << "\n\nIngrese la clave del producto a buscar: ";
			cin >> Clave;

			Producto Produc(Clave, " ", 0);
			Apunt = ListaProds.BuscaOrdenada(Produc);

			if (!Apunt)
				cout << "\n\nEse producto no est� registrado.\n\n";
			else {
				cout << "\n\nEse producto est� registrado.\n";
				ListaProds.ImprimeUnNodo(Apunt);
			}
		}

		break;

		case 4:
			ListaProds.ImprimeRecursivo(ListaProds.RegresaPrimero());

			break;
		}

		Opc = Menu();
	}

	return 0;
}

