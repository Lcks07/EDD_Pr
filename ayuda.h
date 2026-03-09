#ifndef AYUDA_H
#define AYUDA_H

#include <string>
#include <iostream>
using namespace std;

void mostrar_ayuda();


void mostrar_ayuda_comando(const string& comando);



void ayuda_cargar_comandos();
void ayuda_cargar_elementos();
void ayuda_agregar_movimiento();
void ayuda_agregar_analisis();
void ayuda_agregar_elemento();
void ayuda_guardar();
void ayuda_simular_comandos();


void ayuda_ubicar_elementos();
void ayuda_en_cuadrante();

void ayuda_crear_mapa();
void ayuda_ruta_mas_larga();

void ayuda_no_disponible(const string& comando);

#endif // AYUDA_H
