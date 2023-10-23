#ifndef ORDENAR_H
#define ORDENAR_H

template <class T> class Ordenar {
    public:
        virtual int Busca(vector<T>, T) = 0;
        virtual void Ordenar(vector<T> &) = 0;
};

template <class T> class SecuencialDesord : public Ordenar<T> {
public:
int Busca(vector<T> Arre, T Dato) {
int Indice = 0, Posic = -1;
while (Indice < Arre.size() && Dato != Arre[Indice])
Indice++;
if (Indice < Arre.size())
Posic = Indice;
return Posic;
}

    void Ordenar(vector<T> &Arre) {
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
};

#endif // ORDENAR_H
