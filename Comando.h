
#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include "movimiento.h"
#include "analisis.h"

struct Comando {

    std::string discriminador;
    Movimiento m;
    Analisis a;

    Comando CrearComandoMovimiento( Movimiento m);
    Comando CrearComandoAnalisis(Analisis a);
    bool esMovimiento();
    bool esAnalisis();
    Movimiento ObtenerMovimiento();
    Analisis ObtenerAnalisis();
};


