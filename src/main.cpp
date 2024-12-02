#include <iostream>
#include "arbol_binario.h"
#include "utils.h"
using namespace std;

int main() {
    ArbolBinario arbol;

    // Cargar nodos desde el archivo sucesion.csv
    cargarDesdeCSV("bin/sucesion.csv", arbol);

    // Mostrar el arbol cargado
    cout << "Arbol cargado desde CSV en preorden:" << endl;
    arbol.mostrarArbol();

    return 0;
}
