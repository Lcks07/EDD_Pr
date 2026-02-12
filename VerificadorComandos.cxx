#include VerificadorComandos.h 

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std; 

VerificadorComandos::VerificadorComandos () {}//constructor 
// Procesador Principal 
  vector <string> tokens = tokenizar(linea); 
  if (tokens.empty()) return true; 
  const string& cmd= tokens[0]; 
  
  if (cmd=="salir"){
      if (token.size()!=1){
        cout<<"(Formato erroneo) El comando salir no reibe parametros. "<<endl; 
        return true; 
  }
      return false; 
}

else if (cmd=="ayuda") validarAyuda(tokens); 
else if (cmd=="cargar_comandos") validarCargarComandos(tokens);
else if (cmd=="cargar_elementos") validarCargarElementos(tokens); 
else if (cmd=="agregar_movimiento") validarCargarMovimiento(tokens); 
else if (cmd=="agregar_analisis") validarAgregarAnalisis(tokens);
else if (cmd=="agregar_elemento") validarAgregarElemento(tokens);
else if (cmd=="guardar_elemento") validarGuardarElemento(tokens); 
else if (cmd=="simular_comando") validarSimularComando(tokens); 
else if (cmd=="ubicar_elmentos") validarUbicarElementos(tokens); 
else if (cmd=="en_cuadrante") validarEnCuagrante(tokens); 
else if (cmd=="crear_mapa") valiadarCrearMapa(tokens); 
else if (cmd=="ruta_mas_larga") validarRutaMasLarga(tokens); 

else {
  cout<<"COMANDO NO RECONOCIDO "<<endl; 
}
return true; 
}
