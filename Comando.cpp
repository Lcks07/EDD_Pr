#include "comando.h"
#include <string>

Comando Comando:: CrearComandoMovimiento( Movimiento m) {
    Comando c;
    c.discriminador="Movimiento";
    c.m=m;
    return c;
}

Comando Comando:: CrearComandoAnalisis(Analisis a) {
    Comando c;
    c.discriminador="Analisis";
    c.a=a;
    return c;
}

bool Comando:: esMovimiento() {
    if (discriminador=="Movimiento") {
        return true;
    }else {
        return false;
    }
}
bool Comando:: esAnalisis() {
    if (discriminador=="Analisis") {
        return true;
    }else {
        return false;
    }
}

Movimiento Comando:: ObtenerMovimiento() {
    return m;
}

Analisis Comando:: ObtenerAnalisis() {
    return a;
}
