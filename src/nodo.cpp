#include "nodo.h"

// Constructor
Nodo::Nodo(int id, string name, string lastName, char gender, int age, int idFather, bool isDead, bool wasKing, bool isKing) {
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->gender = gender;
    this->age = age;
    this->idFather = idFather;
    this->isDead = isDead;
    this->wasKing = wasKing;
    this->isKing = isKing;
    this->hijoIzquierdo = nullptr;
    this->hijoDerecho = nullptr;
}

// Getters
int Nodo::getId() { return id; }
string Nodo::getName() { return name; }
string Nodo::getLastName() { return lastName; }
char Nodo::getGender() { return gender; }
int Nodo::getAge() { return age; }
int Nodo::getIdFather() { return idFather; }
bool Nodo::getIsDead() { return isDead; }
bool Nodo::getWasKing() { return wasKing; }
bool Nodo::getIsKing() { return isKing; }
Nodo* Nodo::getHijoIzquierdo() { return hijoIzquierdo; }
Nodo* Nodo::getHijoDerecho() { return hijoDerecho; }

// Setters
void Nodo::setName(string name) { this->name = name; }
void Nodo::setLastName(string lastName) { this->lastName = lastName; }
void Nodo::setGender(char gender) { this->gender = gender; }
void Nodo::setAge(int age) { this->age = age; }
void Nodo::setIsDead(bool isDead) { this->isDead = isDead; }
void Nodo::setWasKing(bool wasKing) { this->wasKing = wasKing; }
void Nodo::setIsKing(bool isKing) { this->isKing = isKing; }
void Nodo::setHijoIzquierdo(Nodo* hijoIzquierdo) { this->hijoIzquierdo = hijoIzquierdo; }
void Nodo::setHijoDerecho(Nodo* hijoDerecho) { this->hijoDerecho = hijoDerecho; }
