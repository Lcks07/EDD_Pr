#indef VERIFICADOR_COMANDOS_H
#define VERIFICADOR_COMANDOS_H

#include <string>
#include <vector>

class VerificadorComandos{

public: 
  VerificarComandos()

  bool procesar (const std::String&linea); // procesa la liena ingresada y retorna false si el comando es salir

private: 

std::vector<std::string> tokenizar (const std::string&linea) const; // divide la linea en palabras 
bool esNumero(const std::string& texto) const;// verfica que el string represente un numero valido 

    // Validadores por comando
    void validarAyuda(const std::vector<std::string>& tokens) const;
    void validarAgregarMovimiento(const std::vector<std::string>& tokens) const;
    void validarAgregarAnalisis(const std::vector<std::string>& tokens) const;
    void validarAgregarElemento(const std::vector<std::string>& tokens) const;
};

#endif






}


