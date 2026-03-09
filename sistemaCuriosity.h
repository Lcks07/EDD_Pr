#ifndef SISTEMA_CURIOSITY_H
#define SISTEMA_CURIOSITY_H

#include <string>
#include <vector>

#include "lista_elementos.h"
#include "lista_comandos.h"

using namespace std;

class SistemaCuriosity
{
private:

    // Estructuras principales del sistema
    ListaElementos elementos;
    ListaComandos comandos;

public:

    SistemaCuriosity();

    // Procesador general de comandos
    void procesarComando(string linea);

    // Comandos del sistema
    void cargarComandos(string archivo);
    void cargarElementos(string archivo);

    void agregarMovimiento(string tipo, double magnitud, string unidad);
    void agregarAnalisis(string tipo, string objeto, string comentario);

    void agregarElemento(string tipo, double tam, string unidad, double x, double y);

    void guardar(string tipo, string archivo);

    void simularComandos(double x, double y);

    // NUEVOS COMANDOS
    void ubicarElementos(double x, double y, double radio);
    void enCuadrante(int cuadrante);
};

#endif
