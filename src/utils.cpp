#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

void cargarDesdeCSV(const string& nombreArchivo, ArbolBinario& arbol) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Saltar la primera línea (cabecera)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string idStr, name, lastName, genderStr, ageStr, idFatherStr, isDeadStr, wasKingStr, isKingStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, lastName, ',');
        getline(ss, genderStr, ',');
        getline(ss, ageStr, ',');
        getline(ss, idFatherStr, ',');
        getline(ss, isDeadStr, ',');
        getline(ss, wasKingStr, ',');
        getline(ss, isKingStr, ',');

        // Convertir a tipos adecuados
        int id = stoi(idStr);
        char gender = genderStr[0];
        int age = stoi(ageStr);
        int idFather = stoi(idFatherStr);
        bool isDead = stoi(isDeadStr) == 1;
        bool wasKing = stoi(wasKingStr) == 1;
        bool isKing = stoi(isKingStr) == 1;

        // Crear nodo y agregarlo al arbol
        Nodo* nuevoNodo = new Nodo(id, name, lastName, gender, age, idFather, isDead, wasKing, isKing);
        arbol.insertarNodo(nuevoNodo);
    }

    archivo.close();
}
