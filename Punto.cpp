#include "Punto.h"
#include <cmath>

Punto crearPunto( double x, double y, double z ) {
    Punto p;
    p.x=x;
    p.y=y;
    p.z=z;
    return p;
}

double obtenerx(Punto p ) {
    return p.x;
}

double obtenery(Punto p ) {
    return p.y;
}

double obtenerz(Punto p ) {
    return p.z;
}

double DistanciaEuclidiana(Punto p1, Punto p2) {
    double resultado=0;
    double t1=p2.x-p1.x;
    double t2=p2.y-p1.y;
    double t3=p2.z-p1.z;
    t1=std::pow(t1,2);
    t2=std::pow(t2,2);
    t3=std::pow(t3,2);
    resultado=t1+t2+t3;
    return std::sqrt(resultado);
}

double DistanciaManhathan(Punto p1, Punto p2) {
    double resultado=0;
    double t1=p2.x-p1.x;
    double t2=p2.y-p1.y;
    double t3=p2.z-p1.z;
    t1=std::abs(t1);
    t2=std::abs(t2);
    t3=std::abs(t3);
    resultado=t1+t2+t3;
    return resultado;
}
