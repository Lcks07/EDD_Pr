#include "elemento_interes.h"
#include <string>
#include <cmath>   // CORRECCIÓN: faltaba este include para pow() y sqrt()

using namespace std;

// Constructor por defecto
ElementoInteres::ElementoInteres() {}

// CORRECCIÓN: el constructor estaba escrito como función fábrica (creaba un objeto 'e'
// y hacía return e, lo cual es inválido en un constructor).
// Un constructor inicializa directamente los atributos del objeto con 'this'.
// También usaba nombres 'tipo' y 'tam' en vez de los atributos reales 'tipoElemento' y 'tamanio'.
ElementoInteres::ElementoInteres(string tipo, double tam, string unidad, double x, double y) {
    this->tipoElemento = tipo;
    this->tamanio      = tam;
    this->unidad       = unidad;
    this->x            = x;
    this->y            = y;
    this->z            = 0;
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

double ElementoInteres::Get_X() {
    return x;
}

double ElementoInteres::Get_Y() {
    return y;
}

double ElementoInteres::Get_Z() {
    return z;
}

double ElementoInteres::TamanioEnMetros() {

    if (unidad == "cm") return tamanio / 100;
    if (unidad == "dm") return tamanio / 10;
    if (unidad == "m")  return tamanio;
    if (unidad == "km") return tamanio * 1000;

    return tamanio;
}

bool ElementoInteres::EsValidoElemento(string tipo, double tam, string unidad) {

    bool tipoValido =
        tipo == "roca"     ||
        tipo == "crater"   ||
        tipo == "monticulo"||
        tipo == "duna";

    bool unidadValida =
        unidad == "cm" ||
        unidad == "dm" ||
        unidad == "m"  ||
        unidad == "km";

    return tipoValido && unidadValida && tam >= 0;
}

// CORRECCIÓN: estas funciones son métodos de la clase, deben tener ElementoInteres::
// y además faltaba el #include <cmath> para pow(), sqrt() y abs()
double ElementoInteres::DistanciaEuclidiana(double x1, double y1, double z1,
                                             double x2, double y2, double z2) {
    return sqrt(
        pow(x2 - x1, 2) +
        pow(y2 - y1, 2) +
        pow(z2 - z1, 2)
    );
}

double ElementoInteres::DistanciaManhattan(double x1, double y1, double z1,
                                            double x2, double y2, double z2) {
    return abs(x2 - x1) + abs(y2 - y1) + abs(z2 - z1);
}
