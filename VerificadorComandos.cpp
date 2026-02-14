#include "verificar_comandos.h"
#include "ayuda.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

VerificadorComandos::VerificadorComandos() {}

bool VerificadorComandos::procesar(const string& linea) {

    vector<string> tokens = tokenizar(linea);
    if (tokens.empty()) return true;

    string cmd = tokens[0];

    if (cmd == "salir") {
        if (tokens.size() != 1) {
            cerr << "(Formato erroneo) El comando salir no recibe parametros." << endl;
            exit(EXIT_FAILURE);
        }
        return false;
    }

    else if (cmd == "ayuda") {
        if (!validarAyuda(tokens)) {
            exit(EXIT_FAILURE);
        }

        if (tokens.size() == 1)
            mostrar_ayuda();
        else
            mostrar_ayuda_comando(tokens[1]);
    }

    else if (cmd == "cargar_comandos") {
        if (!validarCargarComandos(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Comando válido." << endl;
    }

    else if (cmd == "cargar_elementos") {
        if (!validarCargarElementos(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Comando válido." << endl;
    }

    else if (cmd == "agregar_movimiento") {

        if (!validarAgregarMovimiento(tokens)) {
            cerr << "(Error) Formato inválido en el comando agregar_movimiento." << endl;
            exit(EXIT_FAILURE);
        }

        cout << "(Resultado exitoso) Movimiento agregado correctamente." << endl;
    }

    else if (cmd == "agregar_analisis") {
        if (!validarAgregarAnalisis(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Analisis agregado correctamente." << endl;
    }

    else if (cmd == "agregar_elemento") {
        if (!validarAgregarElemento(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Elemento agregado correctamente." << endl;
    }

    else if (cmd == "guardar") {
        if (!validarGuardar(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Archivo guardado correctamente." << endl;
    }

    else if (cmd == "simular_comandos") {
        if (!validarSimularComandos(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Simulacion ejecutada correctamente." << endl;
    }

    else if (cmd == "ubicar_elementos") {
        if (!validarUbicarElementos(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Elementos ubicados." << endl;
    }

    else if (cmd == "en_cuadrante") {
        if (!validarEnCuadrante(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Consulta realizada." << endl;
    }

    else if (cmd == "crear_mapa") {
        if (!validarCrearMapa(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Mapa creado." << endl;
    }

    else if (cmd == "ruta_mas_larga") {
        if (!validarRutaMasLarga(tokens)) {
            exit(EXIT_FAILURE);
        }
        cout << "(Resultado exitoso) Ruta calculada." << endl;
    }

    else {
        cerr << "(Error) Comando no reconocido." << endl;
        exit(EXIT_FAILURE);
    }

    return true;
}

vector<string> VerificadorComandos::tokenizar(const string& linea) const {
    vector<string> tokens;
    istringstream iss(linea);
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

bool VerificadorComandos::esNumero(const string& texto) const {
    stringstream ss(texto);
    double numero;
    return (ss >> numero) && ss.eof();
}

bool VerificadorComandos::validarAyuda(const vector<string>& tokens) const {
    if (tokens.size() == 1 || tokens.size() == 2) return true;
    cerr << "(Formato erroneo) Uso: ayuda [comando]" << endl;
    return false;
}

bool VerificadorComandos::validarCargarComandos(const vector<string>& tokens) const {
    if (tokens.size() != 2) {
        cerr << "(Formato erroneo) Uso: cargar_comandos nombre_archivo" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarCargarElementos(const vector<string>& tokens) const {
    if (tokens.size() != 2) {
        cerr << "(Formato erroneo) Uso: cargar_elementos nombre_archivo" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarAgregarMovimiento(const vector<string>& tokens) const {

    if (tokens.size() != 4) {
        cerr << "(Formato erroneo) Uso: agregar_movimiento <avanzar|girar> <magnitud> <unidad>" << endl;
        return false;
    }

    string tipo = tokens[1];
    string magnitud = tokens[2];
    string unidad = tokens[3];

    if (tipo != "avanzar" && tipo != "girar") {
        cerr << "(Error) Tipo de movimiento inválido." << endl;
        return false;
    }

    if (!esNumero(magnitud)) {
        cerr << "(Error) La magnitud debe ser numérica." << endl;
        return false;
    }

    if (tipo == "avanzar") {
        if (unidad != "cm" && unidad != "dm" && unidad != "m" && unidad != "km") {
            cerr << "(Error) Unidad inválida para avanzar." << endl;
            return false;
        }
    }

    if (tipo == "girar") {
        if (unidad != "grd" && unidad != "rad") {
            cerr << "(Error) Unidad inválida para girar." << endl;
            return false;
        }
    }

    return true;
}

bool VerificadorComandos::validarAgregarAnalisis(const vector<string>& tokens) const {
    if (tokens.size() < 3 || tokens.size() > 4) {
        cerr << "(Formato erroneo) Informacion del analisis incorrecta." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarAgregarElemento(const vector<string>& tokens) const {
    if (tokens.size() != 6) {
        cerr << "(Formato erroneo) Informacion del elemento incorrecta." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarGuardar(const vector<string>& tokens) const {
    if (tokens.size() != 3) {
        cerr << "(Formato erroneo) Uso: guardar tipo_archivo nombre_archivo" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarSimularComandos(const vector<string>& tokens) const {
    if (tokens.size() != 3 || !esNumero(tokens[1]) || !esNumero(tokens[2])) {
        cerr << "(Formato erroneo) Uso: simular_comandos <num> <num>" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarUbicarElementos(const vector<string>& tokens) const {
    return tokens.size() == 1;
}

bool VerificadorComandos::validarEnCuadrante(const vector<string>& tokens) const {
    if (tokens.size() != 5) return false;
    return true;
}

bool VerificadorComandos::validarCrearMapa(const vector<string>& tokens) const {
    if (tokens.size() != 2 || !esNumero(tokens[1])) return false;
    double coef = stod(tokens[1]);
    return coef >= 0 && coef <= 1;
}

bool VerificadorComandos::validarRutaMasLarga(const vector<string>& tokens) const {
    return tokens.size() == 1;
}
