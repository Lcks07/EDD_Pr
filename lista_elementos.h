#ifndef LISTA_ELEMENTOS_H
#define LISTA_ELEMENTOS_H

#include <list>
#include "elemento_interes.h"

using namespace std;

class ListaElementos {

private:

    list<ElementoInteres> elementos;

public:

    // Constructor
    ListaElementos();

    // Operaciones del TAD
    void AgregarElemento(ElementoInteres elemento);

    ElementoInteres ObtenerElemento(int posicion);

    int TamanioElementos();

    bool EstaVaciaElementos();

    void LimpiarElementos();
};

#endif
