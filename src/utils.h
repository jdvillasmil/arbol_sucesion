#ifndef UTILS_H
#define UTILS_H

#include "nodo.h"
#include "arbol_binario.h"
#include <string>
using namespace std;

// Leer nodos desde archivo CSV y construir el arbol
void cargarDesdeCSV(const string& nombreArchivo, ArbolBinario& arbol);

#endif
