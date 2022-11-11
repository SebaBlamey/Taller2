#include "Pilas.h"

#include <iostream>

Pilas::Pilas() {
    root = NULL;
}
void Pilas::push(int x) {
    Nodo *nuevo = new Nodo();
    nuevo->numero = x;
    if (root == NULL) {
        root = nuevo;
    } else {
        nuevo->siguiente = root;
        root = nuevo;
    }
}

int Pilas::pop() {
    Nodo *aux = root;
    int numero = aux->numero;
    root = aux->siguiente;
    delete aux;
    return numero;
}

void Pilas::imprimir() {
    Nodo *temp = root;
    while (temp != NULL) {
        cout <<"\t" << temp->numero << endl;
        temp = temp->siguiente;
    }
}

Pilas::~Pilas() {
    Nodo *temp = root;
    while (temp != NULL) {
        Nodo *temp2 = temp;
        temp = temp->siguiente;
        delete temp2;
    }
}