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

    // =========================
    // SALIR
    // =========================
    if (cmd == "salir") {
        if (tokens.size() != 1) {
            cout << "(Formato erroneo) El comando salir no recibe parametros." << endl;
            return true;
        }
        return false;
    }

    // =========================
    // AYUDA
    // =========================
    else if (cmd == "ayuda") {

        if (validarAyuda(tokens)) {
            if (tokens.size() == 1)
                mostrar_ayuda();
            else
                mostrar_ayuda_comando(tokens[1]);
        }
    }

    else if (cmd == "cargar_comandos") {
        if (validarCargarComandos(tokens))
            cout << "(Resultado exitoso) Comando vÃ¡lido." << endl;
    }

    else if (cmd == "cargar_elementos") {
        if (validarCargarElementos(tokens))
            cout << "(Resultado exitoso) Comando vÃ¡lido." << endl;
    }

    else if (cmd == "agregar_movimiento") {
        if (validarAgregarMovimiento(tokens))
            cout << "(Resultado exitoso) Movimiento agregado correctamente." << endl;
    }

    else if (cmd == "agregar_analisis") {
        if (validarAgregarAnalisis(tokens))
            cout << "(Resultado exitoso) Analisis agregado correctamente." << endl;
    }

    else if (cmd == "agregar_elemento") {
        if (validarAgregarElemento(tokens))
            cout << "(Resultado exitoso) Elemento agregado correctamente." << endl;
    }

    else if (cmd == "guardar") {
        if (validarGuardar(tokens))
            cout << "(Resultado exitoso) Archivo guardado correctamente." << endl;
    }

    else if (cmd == "simular_comandos") {
        if (validarSimularComandos(tokens))
            cout << "(Resultado exitoso) Simulacion ejecutada correctamente." << endl;
    }

    else if (cmd == "ubicar_elementos") {
        if (validarUbicarElementos(tokens))
            cout << "(Resultado exitoso) Elementos ubicados." << endl;
    }

    else if (cmd == "en_cuadrante") {
        if (validarEnCuadrante(tokens))
            cout << "(Resultado exitoso) Consulta realizada." << endl;
    }

    else if (cmd == "crear_mapa") {
        if (validarCrearMapa(tokens))
            cout << "(Resultado exitoso) Mapa creado." << endl;
    }

    else if (cmd == "ruta_mas_larga") {
        if (validarRutaMasLarga(tokens))
            cout << "(Resultado exitoso) Ruta calculada." << endl;
    }

    else {
        cout << "COMANDO NO RECONOCIDO" << endl;
    }

    return true;
}

// ============================================================
// TOKENIZADOR
// ============================================================

vector<string> VerificadorComandos::tokenizar(const string& linea) const {
    vector<string> tokens;
    istringstream iss(linea);
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

// ============================================================
// VALIDACIÃ“N DE NÃšMEROS
// ============================================================

bool VerificadorComandos::esNumero(const string& texto) const {
    stringstream ss(texto);
    double numero;
    return (ss >> numero) && ss.eof();
}

// ============================================================
// VALIDACIONES
// ============================================================

bool VerificadorComandos::validarAyuda(const vector<string>& tokens) const {

    if (tokens.size() == 1) return true;
    if (tokens.size() == 2) return true;

    cout << "(Formato erroneo) Uso: ayuda [comando]" << endl;
    return false;
}

bool VerificadorComandos::validarCargarComandos(const vector<string>& tokens) const {

    if (tokens.size() != 2) {
        cout << "(Formato erroneo) Uso: cargar_comandos nombre_archivo" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarCargarElementos(const vector<string>& tokens) const {

    if (tokens.size() != 2) {
        cout << "(Formato erroneo) Uso: cargar_elementos nombre_archivo" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarAgregarMovimiento(const vector<string>& tokens) const {

    if (tokens.size() != 4) {
        cout << "(Formato errÃ³neo) La informaciÃ³n del movimiento no corresponde a los datos esperados." << endl;
        return false;
    }

    string tipo = tokens[1];
    string magnitud = tokens[2];
    string unidad = tokens[3];

    if (tipo != "avanzar" && tipo != "girar") return false;
    if (!esNumero(magnitud)) return false;

    if (tipo == "avanzar") {
        if (unidad != "cm" && unidad != "dm" && unidad != "m" && unidad != "km")
            return false;
    }

    if (tipo == "girar") {
        if (unidad != "grd" && unidad != "rad")
            return false;
    }

    return true;
}

bool VerificadorComandos::validarAgregarAnalisis(const vector<string>& tokens) const {

    if (tokens.size() < 3 || tokens.size() > 4) {
        cout << "(Formato errÃ³neo) InformaciÃ³n del anÃ¡lisis incorrecta." << endl;
        return false;
    }

    string tipo = tokens[1];

    if (tipo != "fotografiar" && tipo != "composicion" && tipo != "perforar")
        return false;

    if (tokens.size() == 4) {
        string comentario = tokens[3];
        if (comentario.size() < 2 || comentario.front() != '\'' || comentario.back() != '\'')
            return false;
    }

    return true;
}

bool VerificadorComandos::validarAgregarElemento(const vector<string>& tokens) const {

    if (tokens.size() != 6) {
        cout << "(Formato errÃ³neo) InformaciÃ³n del elemento incorrecta." << endl;
        return false;
    }

    string tipo = tokens[1];
    string tamaÃ±o = tokens[2];
    string unidad = tokens[3];

    if (tipo != "roca" && tipo != "crater" && tipo != "monticulo" && tipo != "duna")
        return false;

    if (!esNumero(tamaÃ±o) || !esNumero(tokens[4]) || !esNumero(tokens[5]))
        return false;

    if (unidad != "cm" && unidad != "dm" && unidad != "m" && unidad != "km")
        return false;

    return true;
}

bool VerificadorComandos::validarGuardar(const vector<string>& tokens) const {

    if (tokens.size() != 3) {
        cout << "(Formato erroneo) Uso: guardar tipo_archivo nombre_archivo" << endl;
        return false;
    }

    if (tokens[1] != "comandos" && tokens[1] != "elementos")
        return false;

    return true;
}

bool VerificadorComandos::validarSimularComandos(const vector<string>& tokens) const {

    if (tokens.size() != 3) return false;
    if (!esNumero(tokens[1]) || !esNumero(tokens[2])) return false;

    return true;
}

bool VerificadorComandos::validarUbicarElementos(const vector<string>& tokens) const {

    return tokens.size() == 1;
}

bool VerificadorComandos::validarEnCuadrante(const vector<string>& tokens) const {

    if (tokens.size() != 5) return false;

    if (!esNumero(tokens[1]) || !esNumero(tokens[2]) ||
        !esNumero(tokens[3]) || !esNumero(tokens[4]))
        return false;

    double x1 = stod(tokens[1]);
    double x2 = stod(tokens[2]);
    double y1 = stod(tokens[3]);
    double y2 = stod(tokens[4]);

    if (x1 >= x2 || y1 >= y2) return false;

    return true;
}

bool VerificadorComandos::validarCrearMapa(const vector<string>& tokens) const {

    if (tokens.size() != 2) return false;
    if (!esNumero(tokens[1])) return false;

    double coef = stod(tokens[1]);

    if (coef < 0 || coef > 1) return false;

    return true;
}

bool VerificadorComandos::validarRutaMasLarga(const vector<string>& tokens) const {

    return tokens.size() == 1;
}
