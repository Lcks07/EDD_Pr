#ifndef VERIFICAR_COMANDOS_H
#define VERIFICAR_COMANDOS_H

#include <string>
#include <vector>

class VerificadorComandos {

public:
    VerificadorComandos();
    bool procesar(const std::string& linea);

private:
    std::vector<std::string> tokenizar(const std::string& linea) const;
    bool esNumero(const std::string& texto) const;

    bool validarAyuda(const std::vector<std::string>& tokens) const;
    bool validarCargarComandos(const std::vector<std::string>& tokens) const;
    bool validarCargarElementos(const std::vector<std::string>& tokens) const;
    bool validarAgregarMovimiento(const std::vector<std::string>& tokens) const;
    bool validarAgregarAnalisis(const std::vector<std::string>& tokens) const;
    bool validarAgregarElemento(const std::vector<std::string>& tokens) const;
    bool validarGuardar(const std::vector<std::string>& tokens) const;
    bool validarSimularComandos(const std::vector<std::string>& tokens) const;
    bool validarUbicarElementos(const std::vector<std::string>& tokens) const;
    bool validarEnCuadrante(const std::vector<std::string>& tokens) const;
    bool validarCrearMapa(const std::vector<std::string>& tokens) const;
    bool validarRutaMasLarga(const std::vector<std::string>& tokens) const;
};

#endif
}


