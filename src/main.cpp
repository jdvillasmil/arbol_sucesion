#include <iostream>
#include "nodo.h"
using namespace std;

int main() {
    // Crear un nodo de prueba
    Nodo* rey = new Nodo(1, "Juan", "Primero", 'H', 68, 0, false, true, true);

    // Mostrar datos del nodo
    cout << "Rey: " << rey->getName() << " " << rey->getLastName() << endl;
    cout << "Es rey actual: " << (rey->getIsKing() ? "Si" : "No") << endl;

    // Modificar datos
    rey->setAge(69);
    cout << "Edad actualizada: " << rey->getAge() << endl;

    // Liberar memoria
    delete rey;
    return 0;
}
