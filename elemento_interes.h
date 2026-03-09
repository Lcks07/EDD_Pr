#ifndef ELEMENTO_INTERES_H
#define ELEMENTO_INTERES_H

#include <string>
#include "punto.h"

using namespace std;

class ElementoInteres {

private:

    string tipoElemento;
    double tamanio;
    string unidad;
    Punto posicion;

public:

    // Constructores
    ElementoInteres();
    ElementoInteres(string tipo, double tam, string unidad, double x, double y);

    // Getters
    string Get_TipoElemento();
    double Get_Tamanio();
    string Get_Unidad();
    Punto Get_Posicion();

    // Operaciones
    double TamanioEnMetros();

    static bool EsValidoElemento(string tipo, double tam, string unidad);
};

#endif
