#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class Nodo {
private:
    int id;                 // Identificador único del nodo
    string name;            // Nombre del miembro
    string lastName;        // Apellido del miembro
    char gender;            // Género: 'H' para hombre, 'M' para mujer
    int age;                // Edad del miembro
    int idFather;           // ID del padre (0 si es el primer rey)
    bool isDead;            // 1 si está muerto, 0 si está vivo
    bool wasKing;           // 1 si fue rey, 0 si no lo fue
    bool isKing;            // 1 si es el rey actual, 0 si no lo es

    Nodo* hijoIzquierdo;    // Puntero al hijo primogénito
    Nodo* hijoDerecho;      // Puntero al segundo hijo

public:
    // Constructor
    Nodo(int id, string name, string lastName, char gender, int age, int idFather, bool isDead, bool wasKing, bool isKing);

    // Getters
    int getId();
    string getName();
    string getLastName();
    char getGender();
    int getAge();
    int getIdFather();
    bool getIsDead();
    bool getWasKing();
    bool getIsKing();
    Nodo* getHijoIzquierdo();
    Nodo* getHijoDerecho();

    // Setters
    void setName(string name);
    void setLastName(string lastName);
    void setGender(char gender);
    void setAge(int age);
    void setIsDead(bool isDead);
    void setWasKing(bool wasKing);
    void setIsKing(bool isKing);
    void setHijoIzquierdo(Nodo* hijoIzquierdo);
    void setHijoDerecho(Nodo* hijoDerecho);
};

#endif
