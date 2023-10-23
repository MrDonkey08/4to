#ifndef SECUENCIALDERORD_H
#define SECUENCIALDERORD_H

template <class T>
class SecuencialDesord : public Busqueda<T>
{
    public:
        int Busca (Arreglo<T>, T);
};

int SecuencialDesord<T>::Busca(Arreglo<T> Arre, T Dato)
{
    int Indice= 0, Posic = –1;
    while ((Indice < Arre.RegresaTam()) && (Dato != Arre.RegresaValor(Indice)))
    Indice++;
    if (Indice < Arre.RegresaTam())
    Posic= Indice;
    return Posic;
}

#endif // SECUENCIALDERORD_H
