#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <string>

struct Movimiento {
    std::string tipo;
    std::string unidad;
    double magnitud;

    Movimiento CrearMovimiento(std::string tipo, std::string uniddad, double magnitud);
    std::string ObtenerTipo();
    std::string ObtenerUnidad();
    double ObtenerMagnitud();

    double Magnitud_Metros(Movimiento m);
    double Magnitud_randianes(Movimiento m);

};



#endif //MOVIMIENTO_H
