#ifndef PUNTO_H
#define PUNTO_H

struct Punto {
    double x;
    double y;
    double z;

    Punto crearPunto( double x, double y, double z );
    double obtenerx();
    double obtenery();
    double obtenerz();
    double DistanciaEuclidiana(Punto p1, Punto p2);
    double DistanciaManhathan(Punto p1, Punto p2);

};



#endif 
