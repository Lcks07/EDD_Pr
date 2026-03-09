#include "elemento_interes.h"

ElementoInteres::ElementoInteres() {}

ElementoInteres::ElementoInteres(string tipo, double tam, string unidad, double x, double y) {

    tipoElemento = tipo;
    tamanio = tam;
    this->unidad = unidad;

    Punto p(x, y, 0);
    posicion = p;
}

string ElementoInteres::Get_TipoElemento() {
    return tipoElemento;
}

double ElementoInteres::Get_Tamanio() {
    return tamanio;
}

string ElementoInteres::Get_Unidad() {
    return unidad;
}

Punto ElementoInteres::Get_Posicion() {
    return posicion;
}

double ElementoInteres::TamanioEnMetros() {

    if (unidad == "cm")
        return tamanio / 100;

    if (unidad == "dm")
        return tamanio / 10;

    if (unidad == "m")
        return tamanio;

    if (unidad == "km")
        return tamanio * 1000;

    return tamanio;
}

bool ElementoInteres::EsValidoElemento(string tipo, double tam, string unidad) {

    bool tipoValido =
        tipo == "roca" ||
        tipo == "crater" ||
        tipo == "monticulo" ||
        tipo == "duna";

    bool unidadValida =
        unidad == "cm" ||
        unidad == "dm" ||
        unidad == "m" ||
        unidad == "km";

    return tipoValido && unidadValida && tam >= 0;
}
