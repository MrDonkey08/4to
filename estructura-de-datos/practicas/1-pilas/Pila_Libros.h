#ifndef pilas_libro_H_INCLUDED
#define pilas_libro_H_INCLUDED
#define MAX 2

/* Práctica 1: Pilas || Estructura de Datos D02 2023B || Equipo: 3
- Guzmán Zavala Daniel
- Hernandez Hurtado Leonel
- Juarez Rubio ALan Jahir
*/

template <class T> class Pila {

private:
	T EspacioPila[MAX];
	int Tope;

public:
	Pila();
	void operator+(T);
	void operator-(T *);
	int PilaLlena();
	int PilaVacia();
};

template <class T> Pila<T>::Pila() : Tope(-1) {}

template <class T> int Pila<T>::PilaLlena() {
	if (Tope == MAX - 1)
		return 1;
	else
		return 0;
}

template <class T> int Pila<T>::PilaVacia() {
	if (Tope == -1)
		return 1;
	else
		return 0;
}

template <class T> void Pila<T>::operator+(T Valor) {
	Tope++;
	EspacioPila[Tope] = Valor;
}

template <class T> void Pila<T>::operator-(T *Valor) {
	*Valor = EspacioPila[Tope];
	Tope--;
}

#endif
