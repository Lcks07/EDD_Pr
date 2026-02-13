#include "ayuda.h"

using namespace std;



void mostrar_ayuda() {

    cout << "Comandos disponibles:" << endl;
    cout << "  ayuda [comando]" << endl;
    cout << "  cargar_comandos nombre_archivo" << endl;
    cout << "  cargar_elementos nombre_archivo" << endl;
    cout << "  agregar_movimiento tipo magnitud unidad" << endl;
    cout << "  agregar_analisis tipo objeto 'comentario'" << endl;
    cout << "  agregar_elemento tipo tamaño unidad x y" << endl;
    cout << "  guardar tipo_archivo nombre_archivo" << endl;
    cout << "  simular_comandos coordX coordY" << endl;
    cout << "  ubicar_elementos" << endl;
    cout << "  en_cuadrante x_min x_max y_min y_max" << endl;
    cout << "  crear_mapa coeficiente_conectividad" << endl;
    cout << "  ruta_mas_larga" << endl;
    cout << "  salir" << endl;
}

void mostrar_ayuda_comando(const string& comando) {

    if (comando == "cargar_comandos") ayuda_cargar_comandos();
    else if (comando == "cargar_elementos") ayuda_cargar_elementos();
    else if (comando == "agregar_movimiento") ayuda_agregar_movimiento();
    else if (comando == "agregar_analisis") ayuda_agregar_analisis();
    else if (comando == "agregar_elemento") ayuda_agregar_elemento();
    else if (comando == "guardar") ayuda_guardar();
    else if (comando == "simular_comandos") ayuda_simular_comandos();
    else if (comando == "ubicar_elementos") ayuda_ubicar_elementos();
    else if (comando == "en_cuadrante") ayuda_en_cuadrante();
    else if (comando == "crear_mapa") ayuda_crear_mapa();
    else if (comando == "ruta_mas_larga") ayuda_ruta_mas_larga();
    else if (comando == "salir") cout << "salir: Termina la ejecución del programa." << endl;
    else ayuda_no_disponible(comando);
}

void ayuda_cargar_comandos() {
    cout << "Uso: cargar_comandos nombre_archivo" << endl;
    cout << "Carga en memoria los comandos de desplazamiento desde un archivo." << endl;
}

void ayuda_cargar_elementos() {
    cout << "Uso: cargar_elementos nombre_archivo" << endl;
    cout << "Carga en memoria los elementos del terreno desde un archivo." << endl;
}
void ayuda_agregar_movimiento() {
    cout << "Uso: agregar_movimiento tipo magnitud unidad" << endl;
    cout << "tipo: avanzar | girar" << endl;
    cout << "unidad avanzar: cm, dm, m, km" << endl;
    cout << "unidad girar: grd, rad" << endl;
}

void ayuda_agregar_analisis() {
    cout << "Uso: agregar_analisis tipo objeto 'comentario'" << endl;
    cout << "tipo: fotografiar | composicion | perforar" << endl;
    cout << "El comentario es opcional y debe ir entre comillas simples." << endl;
}

void ayuda_agregar_elemento() {
    cout << "Uso: agregar_elemento tipo tamaño unidad coordX coordY" << endl;
    cout << "tipo: roca | crater | monticulo | duna" << endl;
    cout << "unidad: cm, dm, m, km" << endl;
}

void ayuda_guardar() {
    cout << "Uso: guardar tipo_archivo nombre_archivo" << endl;
    cout << "tipo_archivo: comandos | elementos" << endl;
}

void ayuda_simular_comandos() {
    cout << "Uso: simular_comandos coordX coordY" << endl;
}

void ayuda_ubicar_elementos() {
    cout << "Uso: ubicar_elementos" << endl;
}

void ayuda_en_cuadrante() {
    cout << "Uso: en_cuadrante x_min x_max y_min y_max" << endl;
    cout << "Debe cumplirse x_min < x_max y y_min < y_max." << endl;
}

void ayuda_crear_mapa() {
    cout << "Uso: crear_mapa coeficiente_conectividad" << endl;
    cout << "El coeficiente debe estar entre 0 y 1." << endl;
}

void ayuda_ruta_mas_larga() {
    cout << "Uso: ruta_mas_larga" << endl;
}

void ayuda_no_disponible(const string& comando) {
    cout << "No hay ayuda disponible para el comando: " << comando << endl;
}
