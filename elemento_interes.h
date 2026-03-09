#ifndef ELEMENTO_INTERES_H
#define ELEMENTO_INTERES_H

#include <string>

using namespace std;

class ElementoInteres {

private:

    string tipoElemento;
    double tamanio;
    string unidad;
    double x;
    double y;
    double z;

public:

    // Constructores
    ElementoInteres();
    ElementoInteres(string tipo, double tam, string unidad, double x, double y );

    // Getters
    string Get_TipoElemento();
    double Get_Tamanio();
    string Get_Unidad();
    double Get_X();
    double Get_Y();
    double Get_Z();
    double DistanciaEuclidiana(double x1,double y1,double z1,double x2,double y2,double z2);
    bool EsValidoElemento(string tipo, double tam, string unidad, double x, double y, double z);
    double DistanciaManhattan(double x1,double y1,double z1,double x2,double y2,double z2);

    // Operaciones
    double TamanioEnMetros();

    static bool EsValidoElemento(string tipo, double tam, string unidad);
};

#endif
