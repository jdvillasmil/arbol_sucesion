#include <iostream>
#include "arbol_binario.h"
#include "utils.h"
using namespace std;

void mostrarMenu() {
    cout << "\n--- Menu del Sistema de Sucesion ---" << endl;
    cout << "1. Cargar datos desde el archivo CSV" << endl;
    cout << "2. Mostrar la linea de sucesion actual" << endl;
    cout << "3. Reasignar automaticamente al nuevo rey" << endl;
    cout << "4. Modificar los datos de un nodo" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    ArbolBinario arbol;
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        int opcion;
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                cargarDesdeCSV("bin/sucesion.csv", arbol);
                cout << "Datos cargados correctamente desde sucesion.csv." << endl;
                break;
            }
            case 2: {
                cout << "Linea de sucesion actual:" << endl;
                arbol.mostrarLineaSucesion();
                break;
            }
            case 3: {
                cout << "Reasignando al nuevo rey..." << endl;
                arbol.reasignarRey();
                break;
            }
            case 4: {
                cout << "Ingrese el ID del nodo a modificar: ";
                int id;
                cin >> id;
                cin.ignore();
                arbol.modificarNodo(id);
                break;
            }
            case 5: {
                cout << "Hasta luego!" << endl;
                salir = true;
                break;
            }
            default: {
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
                break;
            }
        }
    }

    return 0;
}
