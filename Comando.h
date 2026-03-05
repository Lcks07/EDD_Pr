
#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include "Movimiento.h"
#include "Analisis.h"

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



#endif //COMANDO_H
