#include <iostream>
#include <string>
#include "verificar_comandos.h"

using namespace std;

int main() {
    VerificadorComandos verificador;
    string linea;

    bool continuar = true;

    while (continuar) {
        cout << "$ ";
        getline(cin, linea);

        continuar = verificador.procesar(linea);
    }

    return 0;
}
