# Registros

## Marco Teórico

### ¿Qué es una estructura o registro?

Un registro es una estructura de datos que permite almacenar un conjunto de elementos no necesariamente del mismo tipo. Esta agrupación se guarda bajo un mismo nombre; esto permite una mejor eficiencia respecto a las estructuras básicas

### ¿Qué es un arreglo de estructuras?

Es una forma de agrupar múltiples estructuras del mismo tipo en una sola colección. Cada elemento del arreglo es una instancia individual de la estructura.

### ¿A qué se le conoce como estructuras anidadas?

Una estructura puede contener otras estructuras llamadas estructuras anidadas, las cuales ahorran tiempo en la escritura de programas que utilizan estructuras similares. Se han de definir los miembros comunes solo una vez en su propia estructura.

### Referencias

- Tutoriales programación. (s.f.). _27 - Estructura de datos tipo registro (struct)_. https://www.tutorialesprogramacionya.com/cya/detalleconcepto.php?punto=27&codigo=27&inicio=15

- Parazibyte's blog. (s.f.). _Arreglo de structs en C_. https://parzibyte.me/blog/2020/12/30/arreglo-structs-c/

- Aguilar, L. & Martínez, I. (2014). _Programación en C, C++, Java y UML_ (2da edición). Mc Graw Hill

<div style="page-break-after: always;"></div>

## Actividades Previas

- Transcribe y analiza el programa de la página 290, del libro: Programación en C,
C++, Java y UML del Autor: Luis Joyanes Aguilar, 2da Edición, Mc Graw Hill.

```cpp
#include <stdio.h>
#include <time.h>

struct fecha
{
	unsigned int mes, dia, anyo;
};
struct tiempo
{
	unsigned int horas, minutos;
};
enum tipo_operacion {deposito, retirada, aldia, estado};

typedef struct fecha Fecha;
typedef struct tiempo Tiempo;
typedef enum tipo_operacion TipOperacion;

struct registro_operacion
{
	long numero_cuenta;
	float cantidad;
	TipOperacion operacion;
	Fecha f;
	Tiempo t;
};
typedef struct registro_operacion RegistrOperacion;
RegistrOperacion entrada(void);
int main()
{
	RegistrOperacion w;
	w = entrada();
	printf("\n Operación realizada\n\n");
	printf("\t%ld\n",w.numero_cuenta);
	printf("\t%d-%d-%d\n",w.f.dia,w.f.mes,w.f.anyo);
	printf("\t%d:%d\n",w.t.horas,w.t.minutos);
	return 0;
}

RegistrOperacion entrada(void)
{
	int x, y, z;
	RegistrOperacion una;
	printf("\nNúmero de cuenta: ");
	scanf("%ld",&una.numero_cuenta);
	puts("\tTipo de operación");
	puts("Deposito(0)");
	puts("Retirada de fondos(1)");
	puts("Puesta al dia(2)");
	puts("Estado de la cuenta(3)");
	scanf("%d",&una.operacion);
	printf("\nFecha (dia mes año): ");
	scanf("%d %d %d",&una.f.dia,&una.f.mes,&una.f.anyo);
	printf("Hora de la operacion(hora minuto): ");
	scanf("%d %d",&una.t.horas,&una.t.minutos);
	return una;
}
```

<div style="page-break-after: always;"></div>

## Práctica

### Código

```cpp
#include <iostream>
#include <locale>
#include <string>

using namespace std;

void altas(int i);
void cons(int i);
void cons_generales();
void cons_individual();

typedef struct {
    int dia, mes, anyo;
} tefecha;

typedef struct {
    char nombre[50];
    char domicilio[50];
    char telefono[15];
    char correo[50];
    tefecha fecha_nacimiento;
} tagenda;

tagenda agenda[5];

int main() {
    setlocale(LC_CTYPE, "spanish");

    int opt = 0, usuarios = 0;

    do {
        cout << "Menú - agenda\n\n";
        cout << "1. Altas\n";
        cout << "2. Consultas Generales\n";
        cout << "3. Consulta Individual\n";
        cout << "4. Salir\n\n";
        cout << "Opción: ";
        cin >> opt;
        cout << "\n";

        switch (opt) {
            case 4: cout << "¡Adios, vuelve pronto!"; break;
            case 1:
                if (usuarios >= 5){
                    cout << "Lista llena: " << endl;
                    }
                else{
                    altas(usuarios);
                    usuarios += 1;
                }
                break;

            case 2: cons_generales(); break;
            case 3: cons_individual(); break;
            default:
                cout << "Opción inválida. Inténtalo de nuevo.";
                break;
        }
    } while (opt != 4);
}

void altas(int i) {
        cin.ignore();
        cout << "Datos \n\n";
        cout << "Nombre: ";
        cin.getline(agenda[i].nombre, 50);
        cout << "Domicilio: ";
        cin.getline(agenda[i].domicilio, 50);
        cout << "Teléfono: ";
        cin.getline(agenda[i].telefono, 15);
        cout << "Correo: ";
        cin.getline(agenda[i].correo, 50);
        cout << "Fecha de nacimiento:\n";
        cout << "- Día: ";
        cin >> agenda[i].fecha_nacimiento.dia;
        cout << "- Mes: ";
        cin >>agenda[i].fecha_nacimiento.mes;
        cout << "- Año: ";
        cin >> agenda[i].fecha_nacimiento.anyo;
        cin.ignore();
}


void cons(int i) {
    cout << "Usuario " << i << "\n\n";
    cout << "Nombre: " << agenda[i].nombre << endl;
    cout << "Domicilio: " << agenda[i].domicilio << endl;
    cout << "Teléfono: " << agenda[i].telefono << endl;
    cout << "Correo: " << agenda[i].correo << endl;
    cout << "Fecha de nacimiento: \n\n";
    cout << "- Día: " << agenda[i].fecha_nacimiento.dia << endl;
    cout << "- Mes: " << agenda[i].fecha_nacimiento.mes << endl;
    cout << "- Año: " << agenda[i].fecha_nacimiento.anyo << "\n\n";
}

void cons_generales() {
    for (int i = 0; i < 5; i++) {
        cons(i);
    }
}

void cons_individual() {
    int usuario;
    cout << "Ingresa el número del usuario: ";
    cin >> usuario;

    if (usuario < 5 && usuario >= 0) {
        cons(usuario);
    } else {
        cout << "Opción inválida. Existen 5 usuarios. Inténtalo de nuevo.\n\n";
    }
}

```

<div style="page-break-after: always;"></div>

### Corrida

![ ](attachments/1.png)

![](attachments/2.png)

![](attachments/3.png)

![](attachments/4.png)

![](attachments/5.png)

![](attachments/6.png)

![](attachments/7.png)

