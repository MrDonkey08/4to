/* Aplicación del concepto de gráficas para encontrar el conjunto mínimo de carreteras, con el menor costo asociado, que una un grupo de ciudades. */
#include "Grafica.h"
#include "Grafica.cpp"

int main() {
	Grafica<int> Caminos;
	cout << "\n\nIngrese datos de las ciudades(vértices) y de las carreteras(aristas)\n\n";
	
	Caminos.Lee();
	Caminos.Imprime();
	
	cout <<"\n\nLa red mínima de carreteras requerida para unir todas las ciudades es :\n";
	
	Caminos.Kruskal();
	Caminos.Prim();

	return 0;
}

/*
Capturar y probar el programa 8.3 (le falta la función imprime la cual se puede reutilizar de la pág. 415) y programa 8.4 (le falta un menú) con los datos de la figura 8.16 y la tabla 8.11. Del libro de Estructura de Datos Orientada a Objetos Algoritmos con C++ de laAutora: Silvia Guardati
*/