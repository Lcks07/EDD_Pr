
#ifndef LISTA_COMANDOS_H
#define LISTA_COMANDOS_H
#include "Comando.h"
#include <list>
#include "Comando.h"
struct ListaComandos {
    std::list<Comando> comandos;

    ListaComandos CrearListaComandos();
    void AgregarComando(Comando c);
    Comando ObtenerComando(int i);
    int Tamanio();
    bool EstaVacia();
    void Limpiar();
};


#endif //LISTA_COMANDOS_H
