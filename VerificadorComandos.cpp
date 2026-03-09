#include "verificar_comandos.h"
#include "ayuda.h"

// CORRECCIÓN: se agregan los includes que faltaban para poder usar ListaComandos y ListaElementos
#include "lista_comandos.h"
#include "lista_elementos.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

// CORRECCIÓN: las variables globales ahora se pueden declarar porque los tipos están incluidos
ListaComandos listaComandos;
ListaElementos listaElementos;

// -------------------------------------------------------
// Constructor
// -------------------------------------------------------
VerificadorComandos::VerificadorComandos() {}

// -------------------------------------------------------
// tokenizar: divide una línea en palabras
// -------------------------------------------------------
vector<string> VerificadorComandos::tokenizar(const string& linea) const {
    vector<string> tokens;
    stringstream ss(linea);
    string palabra;
    while (ss >> palabra)
        tokens.push_back(palabra);
    return tokens;
}

// -------------------------------------------------------
// esNumero: verifica si un string es numérico
// -------------------------------------------------------
bool VerificadorComandos::esNumero(const string& texto) const {
    if (texto.empty()) return false;
    size_t inicio = 0;
    if (texto[0] == '-') inicio = 1;
    bool tienePunto = false;
    for (size_t i = inicio; i < texto.size(); i++) {
        if (texto[i] == '.') {
            if (tienePunto) return false;
            tienePunto = true;
        } else if (!isdigit(texto[i])) {
            return false;
        }
    }
    return true;
}

// -------------------------------------------------------
// Validadores
// -------------------------------------------------------
bool VerificadorComandos::validarAyuda(const vector<string>& tokens) const {
    if (tokens.size() > 2) {
        cout << "(Formato erroneo) ayuda recibe como máximo un argumento." << endl;
        return false;
    }
    return true;
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
        cout << "(Formato erroneo) Uso: agregar_movimiento tipo magnitud unidad" << endl;
        return false;
    }
    string tipo = tokens[1];
    if (tipo != "avanzar" && tipo != "girar") {
        cout << "(Formato erroneo) tipo debe ser 'avanzar' o 'girar'." << endl;
        return false;
    }
    if (!esNumero(tokens[2])) {
        cout << "(Formato erroneo) magnitud debe ser un número." << endl;
        return false;
    }
    string unidad = tokens[3];
    if (tipo == "avanzar" && unidad != "cm" && unidad != "dm" && unidad != "m" && unidad != "km") {
        cout << "(Formato erroneo) unidad para avanzar: cm, dm, m, km." << endl;
        return false;
    }
    if (tipo == "girar" && unidad != "grd" && unidad != "rad") {
        cout << "(Formato erroneo) unidad para girar: grd, rad." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarAgregarAnalisis(const vector<string>& tokens) const {
    if (tokens.size() < 3 || tokens.size() > 4) {
        cout << "(Formato erroneo) Uso: agregar_analisis tipo objeto ['comentario']" << endl;
        return false;
    }
    string tipo = tokens[1];
    if (tipo != "fotografiar" && tipo != "composicion" && tipo != "perforar") {
        cout << "(Formato erroneo) tipo debe ser 'fotografiar', 'composicion' o 'perforar'." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarAgregarElemento(const vector<string>& tokens) const {
    if (tokens.size() != 6) {
        cout << "(Formato erroneo) Uso: agregar_elemento tipo tamaño unidad coordX coordY" << endl;
        return false;
    }
    string tipo = tokens[1];
    if (tipo != "roca" && tipo != "crater" && tipo != "monticulo" && tipo != "duna") {
        cout << "(Formato erroneo) tipo debe ser 'roca', 'crater', 'monticulo' o 'duna'." << endl;
        return false;
    }
    if (!esNumero(tokens[2]) || !esNumero(tokens[4]) || !esNumero(tokens[5])) {
        cout << "(Formato erroneo) tamaño, coordX y coordY deben ser números." << endl;
        return false;
    }
    string unidad = tokens[3];
    if (unidad != "cm" && unidad != "dm" && unidad != "m" && unidad != "km") {
        cout << "(Formato erroneo) unidad debe ser cm, dm, m o km." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarGuardar(const vector<string>& tokens) const {
    if (tokens.size() != 3) {
        cout << "(Formato erroneo) Uso: guardar tipo_archivo nombre_archivo" << endl;
        return false;
    }
    string tipo = tokens[1];
    if (tipo != "comandos" && tipo != "elementos") {
        cout << "(Formato erroneo) tipo_archivo debe ser 'comandos' o 'elementos'." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarSimularComandos(const vector<string>& tokens) const {
    if (tokens.size() != 3) {
        cout << "(Formato erroneo) Uso: simular_comandos coordX coordY" << endl;
        return false;
    }
    if (!esNumero(tokens[1]) || !esNumero(tokens[2])) {
        cout << "(Formato erroneo) coordX y coordY deben ser números." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarUbicarElementos(const vector<string>& tokens) const {
    if (tokens.size() != 4) {
        cout << "(Formato erroneo) Uso: ubicar_elementos coordX coordY radio" << endl;
        return false;
    }
    if (!esNumero(tokens[1]) || !esNumero(tokens[2]) || !esNumero(tokens[3])) {
        cout << "(Formato erroneo) coordX, coordY y radio deben ser números." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarEnCuadrante(const vector<string>& tokens) const {
    if (tokens.size() != 2) {
        cout << "(Formato erroneo) Uso: en_cuadrante numero_cuadrante (1-4)" << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarCrearMapa(const vector<string>& tokens) const {
    if (tokens.size() != 2) {
        cout << "(Formato erroneo) Uso: crear_mapa coeficiente_conectividad" << endl;
        return false;
    }
    if (!esNumero(tokens[1])) {
        cout << "(Formato erroneo) coeficiente_conectividad debe ser un número." << endl;
        return false;
    }
    return true;
}

bool VerificadorComandos::validarRutaMasLarga(const vector<string>& tokens) const {
    if (tokens.size() != 1) {
        cout << "(Formato erroneo) ruta_mas_larga no recibe parámetros." << endl;
        return false;
    }
    return true;
}

// -------------------------------------------------------
// procesar: recibe una línea y ejecuta el comando
// -------------------------------------------------------
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

    // =========================
    // CARGAR COMANDOS
    // =========================
    else if (cmd == "cargar_comandos") {

        if (validarCargarComandos(tokens)) {

            string nombreArchivo = tokens[1];
            ifstream archivo(nombreArchivo);

            if (!archivo) {
                cout << "(Archivo erróneo) " << nombreArchivo
                     << " no se encuentra o no puede leerse." << endl;
                return true;
            }

            // CORRECCIÓN: era limpiar() → método real es Limpiar()
            listaComandos.Limpiar();

            string lineaArchivo;
            int contador = 0;

            while (getline(archivo, lineaArchivo)) {

                vector<string> datos = tokenizar(lineaArchivo);

                if (datos.size() >= 3) {

                    if (datos[0] == "avanzar" || datos[0] == "girar") {

                        // CORRECCIÓN: no existe agregarMovimiento() en ListaComandos
                        // Se construye con CrearMovimiento + CrearComandoMovimiento + AgregarComando
                        Movimiento m = Movimiento().CrearMovimiento(datos[0], datos[2], stod(datos[1]));
                        Comando c = Comando().CrearComandoMovimiento(m);
                        listaComandos.AgregarComando(c);
                    }
                    else {

                        string comentario = "";
                        if (datos.size() >= 4)
                            comentario = datos[3];

                        // CORRECCIÓN: no existe agregarAnalisis() en ListaComandos
                        Analisis a = Analisis().CrearAnalisis(datos[0], datos[1], comentario);
                        Comando c = Comando().CrearComandoAnalisis(a);
                        listaComandos.AgregarComando(c);
                    }

                    contador++;
                }
            }

            if (contador == 0)
                cout << "(Archivo vacío) " << nombreArchivo
                     << " no contiene comandos." << endl;
            else
                cout << "(Resultado exitoso) " << contador
                     << " comandos cargados correctamente desde "
                     << nombreArchivo << "." << endl;
        }
    }

    // =========================
    // CARGAR ELEMENTOS
    // =========================
    else if (cmd == "cargar_elementos") {

        if (validarCargarElementos(tokens)) {

            string nombreArchivo = tokens[1];
            ifstream archivo(nombreArchivo);

            if (!archivo) {
                cout << "(Archivo erróneo) " << nombreArchivo
                     << " no se encuentra o no puede leerse." << endl;
                return true;
            }

            // CORRECCIÓN: era limpiar() → método real es LimpiarElementos()
            listaElementos.LimpiarElementos();

            string tipo, unidad;
            double tamano, x, y;
            int contador = 0;

            while (archivo >> tipo >> tamano >> unidad >> x >> y) {

                // CORRECCIÓN: agregarElemento() en ListaElementos recibe un ElementoInteres, no 5 args
                ElementoInteres e(tipo, tamano, unidad, x, y);
                listaElementos.AgregarElemento(e);
                contador++;
            }

            if (contador == 0)
                cout << "(Archivo vacío) " << nombreArchivo
                     << " no contiene elementos." << endl;
            else
                cout << "(Resultado exitoso) " << contador
                     << " elementos cargados correctamente desde "
                     << nombreArchivo << "." << endl;
        }
    }

    // =========================
    // AGREGAR MOVIMIENTO
    // =========================
    else if (cmd == "agregar_movimiento") {

        if (validarAgregarMovimiento(tokens)) {

            Movimiento m = Movimiento().CrearMovimiento(tokens[1], tokens[3], stod(tokens[2]));
            Comando c = Comando().CrearComandoMovimiento(m);
            listaComandos.AgregarComando(c);

            cout << "(Resultado exitoso) El comando de movimiento ha sido agregado exitosamente." << endl;
        }
    }

    // =========================
    // AGREGAR ANALISIS
    // =========================
    else if (cmd == "agregar_analisis") {

        if (validarAgregarAnalisis(tokens)) {

            string comentario = "";
            if (tokens.size() == 4)
                comentario = tokens[3];

            Analisis a = Analisis().CrearAnalisis(tokens[1], tokens[2], comentario);
            Comando c = Comando().CrearComandoAnalisis(a);
            listaComandos.AgregarComando(c);

            cout << "(Resultado exitoso) El comando de análisis ha sido agregado exitosamente." << endl;
        }
    }

    // =========================
    // AGREGAR ELEMENTO
    // =========================
    else if (cmd == "agregar_elemento") {

        if (validarAgregarElemento(tokens)) {

            ElementoInteres e(tokens[1], stod(tokens[2]), tokens[3], stod(tokens[4]), stod(tokens[5]));
            listaElementos.AgregarElemento(e);

            cout << "(Resultado exitoso) El elemento ha sido agregado exitosamente." << endl;
        }
    }

    // =========================
    // GUARDAR
    // =========================
    else if (cmd == "guardar") {

        if (validarGuardar(tokens)) {

            string tipo = tokens[1];
            string nombreArchivo = tokens[2];

            ofstream archivo(nombreArchivo);

            if (!archivo) {
                cout << "(Problemas en archivo) Error guardando en "
                     << nombreArchivo << "." << endl;
                return true;
            }

            // CORRECCIÓN: no existen guardarEnArchivo() en ninguno de los dos TADs
            // Se itera manualmente con los getters reales
            if (tipo == "comandos") {

                for (int i = 0; i < listaComandos.Tamanio(); i++) {
                    Comando c = listaComandos.ObtenerComando(i);

                    if (c.esMovimiento()) {
                        Movimiento m = c.ObtenerMovimiento();
                        archivo << m.ObtenerTipo() << " "
                                << m.ObtenerMagnitud() << " "
                                << m.ObtenerUnidad() << "\n";
                    } else {
                        Analisis a = c.ObtenerAnalisis();
                        archivo << a.ObtenerTipoAnalisis() << " "
                                << a.ObtenerObjeto();
                        if (a.tieneComentario())
                            archivo << " " << a.ObtenerComentario();
                        archivo << "\n";
                    }
                }
            }
            else {

                for (int i = 0; i < listaElementos.TamanioElementos(); i++) {
                    ElementoInteres e = listaElementos.ObtenerElemento(i);
                    archivo << e.Get_TipoElemento() << " "
                            << e.Get_Tamanio() << " "
                            << e.Get_Unidad() << " "
                            << e.Get_X() << " "
                            << e.Get_Y() << "\n";
                }
            }

            cout << "(Escritura exitosa) La información ha sido guardada en "
                 << nombreArchivo << "." << endl;
        }
    }

    // =========================
    // SIMULAR COMANDOS
    // =========================
    else if (cmd == "simular_comandos") {

        if (validarSimularComandos(tokens)) {

            double x = stod(tokens[1]);
            double y = stod(tokens[2]);

            // CORRECCIÓN: era estaVacia() → método real es EstaVacia()
            if (listaComandos.EstaVacia()) {
                cout << "(No hay información) La información requerida no está almacenada en memoria." << endl;
                return true;
            }

            double angulo = 0;

            // CORRECCIÓN: era obtenerLista() → se itera con ObtenerComando(i) y Tamanio()
            // Era comando.tipo directamente → ahora se usa ObtenerMovimiento() + ObtenerTipo()
            for (int i = 0; i < listaComandos.Tamanio(); i++) {

                Comando c = listaComandos.ObtenerComando(i);

                if (c.esMovimiento()) {

                    Movimiento m = c.ObtenerMovimiento();

                    if (m.ObtenerTipo() == "girar") {
                        if (m.ObtenerUnidad() == "grd")
                            angulo += m.ObtenerMagnitud();
                        else
                            angulo += m.ObtenerMagnitud() * 180.0 / M_PI;
                    }

                    if (m.ObtenerTipo() == "avanzar") {
                        double distancia = m.ObtenerMagnitud();
                        x += distancia * cos(angulo * M_PI / 180.0);
                        y += distancia * sin(angulo * M_PI / 180.0);
                    }
                }
            }

            cout << "(Resultado exitoso) La simulación de los comandos, a partir de la posición ("
                 << tokens[1] << "," << tokens[2] << "), deja al robot en la nueva posición ("
                 << x << "," << y << ")." << endl;
        }
    }

    // =========================
    // COMANDO NO RECONOCIDO
    // =========================
    else {
        cout << "COMANDO NO RECONOCIDO" << endl;
    }

    return true;
}
