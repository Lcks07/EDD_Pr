#include "sistemaCuriosity.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

#include "ayuda.h"

using namespace std;

SistemaCuriosity::SistemaCuriosity()
{
}

vector<string> dividir(string linea)
{
    vector<string> tokens;
    stringstream ss(linea);
    string palabra;
    while (ss >> palabra)
        tokens.push_back(palabra);
    return tokens;
}

void SistemaCuriosity::procesarComando(string linea)
{
    vector<string> tokens = dividir(linea);
    if (tokens.size() == 0) return;

    string comando = tokens[0];

    if (comando == "ayuda")
    {
        if (tokens.size() == 1) mostrar_ayuda();
        else mostrar_ayuda_comando(tokens[1]);
    }
    else if (comando == "cargar_comandos")
    {
        cargarComandos(tokens[1]);
    }
    else if (comando == "cargar_elementos")
    {
        cargarElementos(tokens[1]);
    }
    else if (comando == "agregar_movimiento")
    {
        agregarMovimiento(tokens[1], stod(tokens[2]), tokens[3]);
    }
    else if (comando == "agregar_analisis")
    {
        string comentario = (tokens.size() >= 4) ? tokens[3] : "";
        agregarAnalisis(tokens[1], tokens[2], comentario);
    }
    else if (comando == "agregar_elemento")
    {
        agregarElemento(tokens[1], stod(tokens[2]), tokens[3], stod(tokens[4]), stod(tokens[5]));
    }
    else if (comando == "simular_comandos")
    {
        simularComandos(stod(tokens[1]), stod(tokens[2]));
    }
    else if (comando == "ubicar_elementos")
    {
        ubicarElementos(stod(tokens[1]), stod(tokens[2]), stod(tokens[3]));
    }
    else if (comando == "en_cuadrante")
    {
        enCuadrante(stoi(tokens[1]));
    }
    else if (comando == "guardar")
    {
        guardar(tokens[1], tokens[2]);
    }
    else
    {
        cout << "Comando no reconocido" << endl;
    }
}

void SistemaCuriosity::cargarComandos(string archivo)
{
    ifstream file(archivo);
    if (!file) {
        cout << "(Archivo erróneo) " << archivo << " no se encuentra o no puede leerse.\n";
        return;
    }

    comandos.Limpiar();
    string linea;
    int contador = 0;

    while (getline(file, linea)) {
        stringstream ss(linea);
        string tipo;
        ss >> tipo;

        if (tipo == "avanzar" || tipo == "girar") {
            double magnitud;
            string unidad;
            ss >> magnitud >> unidad;
            Movimiento m = Movimiento().CrearMovimiento(tipo, unidad, magnitud);
            Comando c = Comando().CrearComandoMovimiento(m);
            comandos.AgregarComando(c);
            contador++;
        }
        else {
            string objeto, comentario = "";
            ss >> objeto;
            getline(ss, comentario);
            if (!comentario.empty() && comentario[0] == ' ')
                comentario = comentario.substr(1);
            Analisis a = Analisis().CrearAnalisis(tipo, objeto, comentario);
            Comando c = Comando().CrearComandoAnalisis(a);
            comandos.AgregarComando(c);
            contador++;
        }
    }

    if (contador == 0)
        cout << "(Archivo vacío) " << archivo << " no contiene comandos.\n";
    else
        cout << "(Resultado exitoso) " << contador << " comandos cargados correctamente desde " << archivo << ".\n";
}

void SistemaCuriosity::cargarElementos(string archivo)
{
    ifstream file(archivo);
    if (!file) {
        cout << "(Archivo erróneo) " << archivo << " no se encuentra o no puede leerse.\n";
        return;
    }

    elementos.LimpiarElementos();
    int contador = 0;
    string tipo, unidad;
    double tam, x, y;

    while (file >> tipo >> tam >> unidad >> x >> y) {
        ElementoInteres e(tipo, tam, unidad, x, y);
        elementos.AgregarElemento(e);
        contador++;
    }

    if (contador == 0)
        cout << "(Archivo vacío) " << archivo << " no contiene elementos.\n";
    else
        cout << "(Resultado exitoso) " << contador << " elementos cargados correctamente desde " << archivo << ".\n";
}

void SistemaCuriosity::agregarMovimiento(string tipo, double magnitud, string unidad)
{
    Movimiento m = Movimiento().CrearMovimiento(tipo, unidad, magnitud);
    Comando c = Comando().CrearComandoMovimiento(m);
    comandos.AgregarComando(c);
    cout << "(Resultado exitoso) El comando de movimiento ha sido agregado exitosamente.\n";
}

void SistemaCuriosity::agregarAnalisis(string tipo, string objeto, string comentario)
{
    Analisis a = Analisis().CrearAnalisis(tipo, objeto, comentario);
    Comando c = Comando().CrearComandoAnalisis(a);
    comandos.AgregarComando(c);
    cout << "(Resultado exitoso) El comando de análisis ha sido agregado exitosamente.\n";
}

void SistemaCuriosity::agregarElemento(string tipo, double tam, string unidad, double x, double y)
{
    if (!ElementoInteres::EsValidoElemento(tipo, tam, unidad)) {
        cout << "(Elemento no válido) Los parámetros ingresados no son válidos." << endl;
        return;
    }
    ElementoInteres e(tipo, tam, unidad, x, y);
    elementos.AgregarElemento(e);
    cout << "(Resultado exitoso) El elemento ha sido agregado exitosamente.\n";
}

void SistemaCuriosity::guardar(string tipo, string archivo)
{
    ofstream file(archivo);
    if (!file) {
        cout << "(Problemas en archivo) Error guardando en " << archivo << ".\n";
        return;
    }

    if (tipo == "comandos") {
        for (int i = 0; i < comandos.Tamanio(); i++) {
            Comando c = comandos.ObtenerComando(i);
            if (c.esMovimiento()) {
                Movimiento m = c.ObtenerMovimiento();
                file << m.ObtenerTipo() << " " << m.ObtenerMagnitud() << " " << m.ObtenerUnidad() << "\n";
            }
            else {
                Analisis a = c.ObtenerAnalisis();
                file << a.ObtenerTipoAnalisis() << " " << a.ObtenerObjeto();
                if (a.tieneComentario()) file << " " << a.ObtenerComentario();
                file << "\n";
            }
        }
    }
    else if (tipo == "elementos") {
        for (int i = 0; i < elementos.TamanioElementos(); i++) {
            ElementoInteres e = elementos.ObtenerElemento(i);
            // CORRECCIÓN: ya no existe Get_Posicion() ni Punto
            // Se usan directamente Get_X() y Get_Y()
            file << e.Get_TipoElemento() << " "
                 << e.Get_Tamanio()      << " "
                 << e.Get_Unidad()       << " "
                 << e.Get_X()            << " "
                 << e.Get_Y()            << "\n";
        }
    }

    cout << "(Escritura exitosa) La información ha sido guardada en " << archivo << ".\n";
}

void SistemaCuriosity::simularComandos(double x, double y)
{
    if (comandos.EstaVacia()) {
        cout << "(No hay información) La información requerida no está almacenada en memoria.\n";
        return;
    }

    double angulo = 0;

    for (int i = 0; i < comandos.Tamanio(); i++) {
        Comando c = comandos.ObtenerComando(i);
        if (c.esMovimiento()) {
            Movimiento m = c.ObtenerMovimiento();
            if (m.ObtenerTipo() == "girar") {
                if (m.ObtenerUnidad() == "grd")
                    angulo += m.ObtenerMagnitud();
                else
                    angulo += m.ObtenerMagnitud() * 180.0 / M_PI;
            }
            if (m.ObtenerTipo() == "avanzar") {
                double dist = m.ObtenerMagnitud();
                x += dist * cos(angulo * M_PI / 180.0);
                y += dist * sin(angulo * M_PI / 180.0);
            }
        }
    }

    cout << "(Resultado exitoso) La simulación de los comandos deja al robot en la nueva posición ("
         << x << "," << y << ").\n";
}

void SistemaCuriosity::ubicarElementos(double x, double y, double radio)
{
    if (elementos.EstaVaciaElementos()) {
        cout << "(No hay información) La información requerida no está almacenada en memoria.\n";
        return;
    }

    bool encontrado = false;

    for (int i = 0; i < elementos.TamanioElementos(); i++) {
        ElementoInteres e = elementos.ObtenerElemento(i);
        // CORRECCIÓN: se usan Get_X() y Get_Y() en vez de Get_Posicion()
        double dx = e.Get_X() - x;
        double dy = e.Get_Y() - y;
        double dist = sqrt(dx * dx + dy * dy);

        if (dist <= radio) {
            cout << e.Get_TipoElemento() << " "
                 << e.Get_Tamanio()      << " "
                 << e.Get_Unidad()       << " ("
                 << e.Get_X()            << ", "
                 << e.Get_Y()            << ")" << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontraron elementos dentro del radio indicado.\n";
}

void SistemaCuriosity::enCuadrante(int cuadrante)
{
    if (elementos.EstaVaciaElementos()) {
        cout << "(No hay información) La información requerida no está almacenada en memoria.\n";
        return;
    }

    for (int i = 0; i < elementos.TamanioElementos(); i++) {
        ElementoInteres e = elementos.ObtenerElemento(i);
        // CORRECCIÓN: se usan Get_X() y Get_Y() en vez de Get_Posicion()
        double ex = e.Get_X();
        double ey = e.Get_Y();

        bool enRango = false;
        if (cuadrante == 1 && ex > 0 && ey > 0) enRango = true;
        if (cuadrante == 2 && ex < 0 && ey > 0) enRango = true;
        if (cuadrante == 3 && ex < 0 && ey < 0) enRango = true;
        if (cuadrante == 4 && ex > 0 && ey < 0) enRango = true;

        if (enRango) {
            cout << e.Get_TipoElemento() << " "
                 << e.Get_Tamanio()      << " "
                 << e.Get_Unidad()       << " ("
                 << ex << ", " << ey     << ")" << endl;
        }
    }
}
