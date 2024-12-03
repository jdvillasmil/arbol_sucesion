#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "nodo.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class ArbolBinario {
private:
    Nodo* raiz;  // Puntero a la raíz del árbol

public:
    // Constructor
    ArbolBinario();

    // Destructor
    ~ArbolBinario();

    // Métodos básicos
    void insertarNodo(Nodo* nuevoNodo); // Insertar un nodo en el árbol
    Nodo* buscarNodo(int id);           // Buscar un nodo por ID
    void mostrarArbol();                // Mostrar el árbol completo en preorden

    // Métodos para sucesión
    void mostrarLineaSucesion();       // Mostrar la línea de sucesión actual
    bool reasignarRey();               // Reasignar automáticamente al nuevo rey
    void modificarNodo(int id);        // Modificar datos de un nodo por ID

    // Métodos auxiliares
    void destruirArbol(Nodo* nodo);    // Liberar memoria del árbol
    void imprimirPreorden(Nodo* nodo); // Recorrido preorden
    void imprimirLineaSucesion(Nodo* nodo); // Recorrido preorden (solo vivos)
    Nodo* encontrarRey(Nodo* nodo);    // Encontrar el nuevo rey

    // Getters
    Nodo* getRaiz();
};

#endif
