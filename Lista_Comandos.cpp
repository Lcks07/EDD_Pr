
#include "Lista_Comandos.h"
#include <list>
#include "Comando.h"
ListaComandos ListaComandos::CrearListaComandos() {
    ListaComandos lc;
    return lc;
}

void ListaComandos:: AgregarComando(Comando c) {
    comandos.push_back(c);
}

Comando ListaComandos:: ObtenerComando(int i) {
    std::list<Comando>::iterator it = comandos.begin();
    int x=0;
    for (; it != comandos.end(); it++) {
        if (x == i) {
            return *it;
        }
        x++;
    }
    Comando vacio;
    return vacio;
}

int ListaComandos:: Tamanio() {
    int tamnio=comandos.size();
    return tamnio;
}
bool ListaComandos::EstaVacia() {
    if (comandos.empty()) {
        return true;
    }else {
        return false;
    }
}

void ListaComandos:: Limpiar() {
    comandos.clear();
}
