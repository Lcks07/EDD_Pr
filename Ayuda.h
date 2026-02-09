#ifndef AYUDA_H
#define AYUDA_H

#include <string>
#include <iostream>
using namespace std;
/*
 * =========================================================
 * Proyecto Curiosity - Entrega 0
 * Archivo: ayuda.h
 *
 * Contiene la interfaz del sistema de ayuda del programa.
 * =========================================================
 */

/* =========================
   Ayuda general
   ========================= */

/**
 * Muestra la lista de comandos disponibles en el sistema.
 */
void mostrar_ayuda();

/**
 * Muestra la ayuda detallada de un comando específico.
 */
void mostrar_ayuda_comando(const string& comando);

/* =========================
   Ayudas por componente
   ========================= */

/* -------- Componente 1: Manejo de información -------- */

void ayuda_cargar_comandos();
void ayuda_cargar_elementos();
void ayuda_agregar_movimiento();
void ayuda_agregar_analisis();
void ayuda_agregar_elemento();
void ayuda_guardar();
void ayuda_simular_comandos();

/* -------- Componente 2: Planeación de desplazamientos -------- */

void ayuda_ubicar_elementos();
void ayuda_en_cuadrante();

/* -------- Componente 3: Recorridos entre puntos de interés -------- */

void ayuda_crear_mapa();
void ayuda_ruta_mas_larga();

/* =========================
   Utilidades del sistema de ayuda
   ========================= */

/**
 * Muestra un mensaje cuando el comando solicitado
 * no tiene ayuda definida.
 */
void ayuda_no_disponible(const string& comando);

#endif // AYUDA_H
