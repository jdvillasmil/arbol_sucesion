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
        cout << "El árbol está vacío." << endl;
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

// Getter para obtener la raíz
Nodo* ArbolBinario::getRaiz() {
    return raiz;
}
