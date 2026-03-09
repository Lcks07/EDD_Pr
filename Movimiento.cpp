#include "movimiento.h"
#include <cmath>

Movimiento Movimiento::CrearMovimiento(std::string tipo, std::string unidad, double magnitud) {
    Movimiento m;
    m.unidad = unidad;
    m.magnitud = magnitud;
    m.tipo = tipo;
    return m;
}

std::string Movimiento::ObtenerTipo() {
    return tipo;
}

std::string Movimiento::ObtenerUnidad() {
    return unidad;
}

double  Movimiento:: ObtenerMagnitud() {
    return magnitud;
}

double Movimiento::Magnitud_Metros(Movimiento m) {
    if (m.tipo=="avanzar") {
            if (m.unidad=="cm") {
                return m.magnitud*0.01;
            }else if (m.unidad=="dm") {
                return m.magnitud*0.1;
            }else if (m.unidad=="m") {
                return m.magnitud*1;
            }else if (m.unidad=="km") {
                return m.magnitud*1000;
            }
            else {
                return -1;
        }
    }
    return -1;
}

double Movimiento::Magnitud_randianes(Movimiento m) {
    constexpr double PI = 3.14159265358979323846;
    if (m.tipo=="girar") {
        if (m.unidad=="grd") {
            return m.magnitud*PI/180;
        }
    else if (m.unidad=="rad") {
        return m.magnitud;
    }
    else {
        return -1;
    }
        }else {
            return -1;
        }
}
