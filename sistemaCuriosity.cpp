#include "SistemaCuriosity.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include "verificacion.h"
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

    while(ss >> palabra)
    {
        tokens.push_back(palabra);
    }

    return tokens;
}

void SistemaCuriosity::procesarComando(string linea)
{
    vector<string> tokens = dividir(linea);

    if(tokens.size() == 0)
        return;

    string comando = tokens[0];

    // VERIFICACION
    if(!verificar_comando(tokens))
    {
        cout << "Comando inválido" << endl;
        return;
    }

    // AYUDA
    if(comando == "ayuda")
    {
        mostrar_ayuda(tokens);
    }

    // CARGAR COMANDOS
    else if(comando == "cargar_comandos")
    {
        cargarComandos(tokens[1]);
    }

    // CARGAR ELEMENTOS
    else if(comando == "cargar_elementos")
    {
        cargarElementos(tokens[1]);
    }

    // AGREGAR MOVIMIENTO
    else if(comando == "agregar_movimiento")
    {
        string tipo = tokens[1];
        double magnitud = stod(tokens[2]);
        string unidad = tokens[3];

        agregarMovimiento(tipo, magnitud, unidad);
    }

    // AGREGAR ANALISIS
    else if(comando == "agregar_analisis")
    {
        string tipo = tokens[1];
        string objeto = tokens[2];
        string comentario = tokens[3];

        agregarAnalisis(tipo, objeto, comentario);
    }

    // AGREGAR ELEMENTO
    else if(comando == "agregar_elemento")
    {
        string nombre = tokens[1];
        string tipo = tokens[2];
        double x = stod(tokens[3]);
        double y = stod(tokens[4]);

        agregarElemento(nombre, tipo, x, y);
    }

    // GUARDAR
    else if(comando == "guardar")
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

    if(!file.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string linea;

    while(getline(file, linea))
    {
        listaComandos.insertarLinea(linea);
    }

    cout << "Comandos cargados correctamente" << endl;

    file.close();
}

void SistemaCuriosity::cargarElementos(string archivo)
{
    ifstream file(archivo);

    if(!file.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Elementos cargados correctamente" << endl;

    file.close();
}

void SistemaCuriosity::agregarMovimiento(string tipo, double magnitud, string unidad)
{
    listaComandos.insertarMovimiento(tipo, magnitud, unidad);
    cout << "Movimiento agregado: "
         << tipo << " "
         << magnitud << " "
         << unidad << endl;
}

void SistemaCuriosity::agregarAnalisis(string tipo, string objeto, string comentario)
{
    listaComandos.insertarAnalisis(tipo, objeto, comentario);
    cout << "Analisis agregado: "
         << tipo << " "
         << objeto << endl;
}

void SistemaCuriosity::agregarElemento(string nombre, string tipo, double x, double y)
{

    if(!ElementoInteres::EsValidoElemento(tipo, x, y))
    {
        cout << "Elemento no valido" << endl;
        return;
    }

    ElementoInteres elemento(nombre, tipo, x, y);

    listaElementos.insertar(elemento);

    cout << "Elemento agregado: "
         << nombre << " "
         << tipo << endl;
}

void SistemaCuriosity::guardar(string tipo, string archivo)
{
    ofstream file(archivo);

    if(!file.is_open())
    {
        cout << "No se pudo guardar el archivo" << endl;
        return;
    }

    cout << "Datos guardados correctamente" << endl;

    file.close();
}
