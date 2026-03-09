
#include "analisis.h"
#include <string>
Analisis Analisis::CrearAnalisis(std::string tipo, std::string objeto, std::string comentario) {
    Analisis a;
    a.tipo=tipo;
    a.objeto=objeto;
    a.comentario=comentario;
    return a;
}

std::string Analisis:: ObtenerTipoAnalisis() {
    return tipo;
}

std::string Analisis:: ObtenerObjeto() {
    return objeto;
}
std::string Analisis:: ObtenerComentario() {
    return comentario;
}
bool Analisis:: tieneComentario() {
    if (comentario.empty()) {
        return false;
    }else{
        return true;
    }
}
