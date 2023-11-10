#ifndef Producto_h
#define Producto_h

#include <iostream>
using namespace std;

class Producto {
	private:
		int Clave;
		char NomProd[64];
		double Precio;

	public:
		Producto();
		Producto(int, char[], double);
		int ObtenerClave();
		char ObtenerNomProd();
		double ObtenerPrecio();
		double RegresaPrecio();
		int operator == (Producto);
		int operator != (Producto);
		int operator > (Producto);
		int operator < (Producto);
		friend istream &operator>>(istream &, Producto &);
		friend ostream &operator<<(ostream &, Producto &);
};

#endif
