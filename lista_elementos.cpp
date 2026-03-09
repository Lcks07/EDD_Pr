#include "lista_elementos.h"

ListaElementos::ListaElementos() {}

void ListaElementos::AgregarElemento(ElementoInteres elemento) {

    elementos.push_back(elemento);
}

ElementoInteres ListaElementos::ObtenerElemento(int posicion) {

    list<ElementoInteres>::iterator it = elementos.begin();

    advance(it, posicion);

    return *it;
}

int ListaElementos::TamanioElementos() {

    return elementos.size();
}

bool ListaElementos::EstaVaciaElementos() {

    return elementos.empty();
}

void ListaElementos::LimpiarElementos() {

    elementos.clear();
}
