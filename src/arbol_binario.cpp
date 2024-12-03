#include "arbol_binario.h"

// Constructor
ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

// Destructor
ArbolBinario::~ArbolBinario() {
    destruirArbol(raiz);
}

// Liberar memoria del árbol
void ArbolBinario::destruirArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->getHijoIzquierdo());
        destruirArbol(nodo->getHijoDerecho());
        delete nodo;
    }
}

// Insertar un nodo en el árbol
void ArbolBinario::insertarNodo(Nodo* nuevoNodo) {
    if (raiz == nullptr) {
        raiz = nuevoNodo;
    } else {
        queue<Nodo*> cola;
        cola.push(raiz);

        while (!cola.empty()) {
            Nodo* actual = cola.front();
            cola.pop();

            if (actual->getHijoIzquierdo() == nullptr) {
                actual->setHijoIzquierdo(nuevoNodo);
                return;
            } else {
                cola.push(actual->getHijoIzquierdo());
            }

            if (actual->getHijoDerecho() == nullptr) {
                actual->setHijoDerecho(nuevoNodo);
                return;
            } else {
                cola.push(actual->getHijoDerecho());
            }
        }
    }
}

// Buscar un nodo por ID
Nodo* ArbolBinario::buscarNodo(int id) {
    if (raiz == nullptr) return nullptr;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();

        if (actual->getId() == id) {
            return actual;
        }

        if (actual->getHijoIzquierdo() != nullptr) {
            cola.push(actual->getHijoIzquierdo());
        }

        if (actual->getHijoDerecho() != nullptr) {
            cola.push(actual->getHijoDerecho());
        }
    }

    return nullptr;
}

// Mostrar el árbol completo (Preorden)
void ArbolBinario::mostrarArbol() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio." << endl;
    } else {
        imprimirPreorden(raiz);
    }
}

// Imprimir recorrido en preorden
void ArbolBinario::imprimirPreorden(Nodo* nodo) {
    if (nodo != nullptr) {
        cout << nodo->getName() << " " << nodo->getLastName() << endl;
        imprimirPreorden(nodo->getHijoIzquierdo());
        imprimirPreorden(nodo->getHijoDerecho());
    }
}

// Mostrar la linea de sucesion (solo nodos vivos)
void ArbolBinario::mostrarLineaSucesion() {
    if (raiz == nullptr) {
        cout << "No hay linea de sucesion, el arbol esta vacio." << endl;
    } else {
        cout << "Linea de sucesion actual:" << endl;
        imprimirLineaSucesion(raiz);
    }
}

// Recorrido preorden filtrando nodos vivos
void ArbolBinario::imprimirLineaSucesion(Nodo* nodo) {
    if (nodo != nullptr) {
        if (!nodo->getIsDead()) { // Solo imprimir si el nodo esta vivo
            cout << nodo->getName() << " " << nodo->getLastName() << endl;
        }
        imprimirLineaSucesion(nodo->getHijoIzquierdo());
        imprimirLineaSucesion(nodo->getHijoDerecho());
    }
}

// Reasignar automaticamente al nuevo rey
bool ArbolBinario::reasignarRey() {
    if (raiz == nullptr) {
        cout << "No hay rey actual, el arbol esta vacio." << endl;
        return false;
    }

    if (raiz->getIsDead()) {
        Nodo* nuevoRey = encontrarRey(raiz);
        if (nuevoRey != nullptr) {
            raiz->setIsKing(false); // Eliminar al rey actual
            nuevoRey->setIsKing(true);
            cout << "El nuevo rey es: " << nuevoRey->getName() << " " << nuevoRey->getLastName() << endl;
            return true;
        } else {
            cout << "No se encontro un sucesor vivo para el rey." << endl;
            return false;
        }
    }

    cout << "El rey actual aun esta vivo: " << raiz->getName() << endl;
    return true;
}

// Encontrar el nuevo rey (recursivo)
Nodo* ArbolBinario::encontrarRey(Nodo* nodo) {
    if (nodo == nullptr) return nullptr;

    // Si el nodo esta vivo, es el nuevo rey
    if (!nodo->getIsDead()) {
        return nodo;
    }

    // Buscar en el hijo primogenito
    Nodo* posibleRey = encontrarRey(nodo->getHijoIzquierdo());
    if (posibleRey != nullptr) return posibleRey;

    // Buscar en el segundo hijo
    return encontrarRey(nodo->getHijoDerecho());
}

// Modificar datos de un nodo por ID
void ArbolBinario::modificarNodo(int id) {
    Nodo* nodo = buscarNodo(id); // Buscar el nodo por su ID
    if (nodo == nullptr) {
        cout << "Nodo con ID " << id << " no encontrado." << endl;
        return;
    }

    // Mostrar datos actuales del nodo
    cout << "Datos actuales del nodo:" << endl;
    cout << "Nombre: " << nodo->getName() << endl;
    cout << "Apellido: " << nodo->getLastName() << endl;
    cout << "Genero: " << nodo->getGender() << endl;
    cout << "Edad: " << nodo->getAge() << endl;
    cout << "¿Muerto?: " << (nodo->getIsDead() ? "Si" : "No") << endl;

    // Solicitar nuevos datos
    string nuevoNombre, nuevoApellido;
    char nuevoGenero;
    int nuevaEdad;
    bool estaMuerto;

    cout << "\nIngrese los nuevos datos (deje vacio para no cambiar):" << endl;

    // Nombre
    cout << "Nuevo nombre: ";
    getline(cin, nuevoNombre);
    if (!nuevoNombre.empty()) {
        nodo->setName(nuevoNombre);
    }

    // Apellido
    cout << "Nuevo apellido: ";
    getline(cin, nuevoApellido);
    if (!nuevoApellido.empty()) {
        nodo->setLastName(nuevoApellido);
    }

    // Genero
    cout << "Nuevo genero (H/M): ";
    cin >> nuevoGenero;
    nodo->setGender(nuevoGenero);

    // Edad
    cout << "Nueva edad: ";
    cin >> nuevaEdad;
    nodo->setAge(nuevaEdad);

    // ¿Muerto?
    cout << "¿Esta muerto? (1 = Si, 0 = No): ";
    cin >> estaMuerto;
    nodo->setIsDead(estaMuerto);

    cout << "Los datos del nodo han sido actualizados." << endl;
}
