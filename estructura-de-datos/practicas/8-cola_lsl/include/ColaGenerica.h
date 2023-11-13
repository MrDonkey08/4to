#ifndef ColaGenerica_h
#define ColaGenerica_h

template <class T>
class ColaGenerica{
	protected:
		class NodoCola {
		public:
			NodoCola *siguiente;
			T elemento;
			NodoCola(T x) {
				elemento = x;
				siguiente = nullptr;
			}
		};
		NodoCola *frente;
		NodoCola *final;

	public:
		ColaGenerica() { frente = final = nullptr; }
		void insertar(T elemento);
		T quitar();
		void borrarCola();
		T frenteCola() const;
		bool colaVacia() const;
		~ColaGenerica() { borrarCola(); }
};

#endif