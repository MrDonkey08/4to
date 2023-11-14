#include <iostream>
#include <queue>
#include <string>
/*
Castellanos Ramirez Gustavo Fabian
Guzmán Zavala Daniel
Juarez Rubio Alan Yahir
Hernandez Hurtado Leonel
*/
using namespace std;

class Alumno {
	private:
		string nombre;
		string carrera;
		int materiasAprobadas;
		double promedioGeneral;

	public:
		Alumno(string n, string c, int ma, double pg)
				: nombre(n), carrera(c), materiasAprobadas(ma), promedioGeneral(pg) {}

		string getNombre() const { return nombre; }

		string getCarrera() const { return carrera; }

		int getMateriasAprobadas() const { return materiasAprobadas; }

		double getPromedioGeneral() const { return promedioGeneral; }
};

int main() {
	queue<Alumno> colaSolicitudes;

	int opcion;

	do {
		cout << "\nMENU â€“ SISTEMA ADMINISTRADOR DE CONSTANCIAS";
		cout << "\n1. Dar de alta la solicitud de un alumno (insertar)";
		cout << "\n2. Elaborar una constancia (eliminar)";
		cout << "\n3. Salir";
		cout << "\nElige tu opcion: ";
		cin >> opcion;

		switch (opcion) {
			case 1: {
				string nombre, carrera;
				int materiasAprobadas;
				double promedioGeneral;

				cout << "Nombre del alumno: ";
				cin.ignore(); // Limpiar el buffer del teclado
				getline(cin, nombre);

				cout << "Nombre de la carrera: ";
				getline(cin, carrera);

				cout << "Total de materias aprobadas: ";
				cin >> materiasAprobadas;

				cout << "Promedio general: ";
				cin >> promedioGeneral;

				Alumno nuevoAlumno(nombre, carrera, materiasAprobadas, promedioGeneral);
				colaSolicitudes.push(nuevoAlumno);

				cout << "Solicitud de alumno encolada con Exito." << endl;

				break;
			}
			case 2:
				if (!colaSolicitudes.empty()) {
					Alumno alumnoAtendido = colaSolicitudes.front();
					colaSolicitudes.pop();

					cout << "\nCONSTANCIA GENERADA\n";
					cout << "Nombre del alumno: " << alumnoAtendido.getNombre() << endl;
					cout << "Carrera: " << alumnoAtendido.getCarrera() << endl;
					cout << "Materias aprobadas: " << alumnoAtendido.getMateriasAprobadas()
						<< endl;
					cout << "Promedio general: " << alumnoAtendido.getPromedioGeneral()
						<< endl;
				} else {
					cout << "\nNo hay solicitudes pendientes en la cola.\n";
				}

				break;
			case 3:
				cout << "Saliendo del programa...\n";

				break;
			default:
				cout << "Opcion no valida. Intentalo de nuevo.\n";
		}
	} while (opcion != 3);

	return 0;
}