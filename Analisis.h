#ifndef ANALISIS_H
#define ANALISIS_H
#include <string>

struct Analisis {
    std::string tipo;
    std::string objeto;
    std::string comentario;

    Analisis CrearAnalisis(std::string tipo, std::string objeto, std::string comentario);
    std::string ObtenerTipoAnalisis();
    std::string ObtenerObjeto();
    std::string ObtenerComentario();
    bool tieneComentario();


};



#endif //ANALISIS_H



#endif //ANALISIS_H
