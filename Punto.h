#ifndef PUNTO_H
#define PUNTO_H

struct Punto {
    double x;
    double y;
    double z;

    Punto crearPunto( double x, double y, double z );
    double obtenerx(Punto p );
    double obtenery(Punto p);
    double obtenerz(Punto p);
    double DistanciaEuclidiana(Punto p1, Punto p2);
    double DistanciaManhathan(Punto p1, Punto p2);

};



#endif //PUNTO_H

