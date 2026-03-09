#ifndef SISTEMA_CURIOSITY_H
#define SISTEMA_CURIOSITY_H

#include <string>
#include <vector>

#include "ListaElementos.h"
#include "ListaComandos.h"

using namespace std;

class SistemaCuriosity
{
private:

    // Estructuras del sistema
    ListaElementos listaElementos;
    ListaComandos listaComandos;

public:

    SistemaCuriosity();

    // Procesador general de comandos
    void procesarComando(string linea);

    // Comandos del componente 1
    void cargarComandos(string archivo);
    void cargarElementos(string archivo);

    void agregarMovimiento(string tipo, double magnitud, string unidad);
    void agregarAnalisis(string tipo, string objeto, string comentario);
    void agregarElemento(string nombre, string tipo, double x, double y);

    void guardar(string tipo, string archivo);
};

#endif
