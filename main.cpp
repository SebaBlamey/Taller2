#include <math.h>

#include <iostream>
#include <string>

#include "Pila.h"
#include "Pilas.h"
using namespace std;

int tamanoTorre;
bool check_number(string);
void TowerHANNOI2(int, Pilas, Pilas, Pilas, char, char, char);

int main() {
    char A, B, C;

    string number_turret;
    cout << "Cuantos discos debe tener la torre -> ";
    cin >> number_turret;
    while (!check_number(number_turret)) {
        cout << "[INVALIDO] Cuantos discos debe tener la torre -> ";
        cin >> number_turret;
    }
    tamanoTorre = stoi(number_turret);
    cout << "Se resuelve con " << (pow(2, tamanoTorre) - 1) << " movimientos" << endl;

    // AQUI COMIENZAN LOS CAMBIOS

    // Declaracion de las pilas
    /*ptrPila Torre1=NULL;
    ptrPila Torre2=NULL;
    ptrPila Torre3=NULL;*/

    Pilas *Torre1 = new Pilas();
    Pilas *Torre2 = new Pilas();
    Pilas *Torre3 = new Pilas();

    // Aqui se llenan las pilas de mayor a menor (5-4-3-2-1) para que quede ordenada de forma (1-2-3-4-5)
    for (int i = tamanoTorre; i > 0; i--) {
        Torre1->push(i);
    }

    // LLamado de la funcion recursiva
    //  destaco que las variables A B C son para imprimir que disco se movio
    //  el problema esta en lo que contienen las pilas
    Torre1->imprimir();
    Torre2->imprimir();
    Torre3->imprimir();

    TowerHANNOI2(tamanoTorre, *Torre1, *Torre3, *Torre2, 'A', 'C', 'B');

    Torre1->imprimir();
    Torre2->imprimir();
    Torre3->imprimir();

    return 0;
}

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

void TowerHANNOI2(int n, Pilas Torre1, Pilas Torre2, Pilas Torre3, char A, char C, char B) {
    int x = 0;                                                                               // indice del disco (puede tener error asi que aun queda a revision)
    // Solo cuando N sea igual a 1 se va a realizar el movimiento de los n-1 discos
    if (n == 1) {
        cout << "======Opcion1======" << endl;
        Torre3.push(Torre1.pop());

        cout << "Torre1" << endl;
        Torre1.imprimir();
        cout << "Torre3" << endl;
        Torre3.imprimir();

        // Cuidado con la seccion de arriba ya que aqui puede ser que este el error
        // ya que a medida que avanza el algoritmo Torre 1 cambia de pila, lo mismo con Torre 3

        cout << "Muevaa el bloque " << n << " desde " << A << " hasta  " << C << endl;
        return;
    } else {
        cout << "======Opcion2======" << endl;
        cout << "Torre1" << endl;
        Torre1.imprimir();
        cout << "Torre3" << endl;
        Torre3.imprimir();
        // Primer llamado de la funcion recursiva.
        TowerHANNOI2(n - 1, Torre1, Torre2, Torre3, A, B, C);
        // Aqui se mueve el disco mas grande de la funcion a la posicion final
        Torre2.push(Torre1.pop());
        cout << "Mueva el bloque " << n << " desde " << A << " hasta  " << C << endl;
        // Ultimo llamado de la funcion recursiva, y que permite mover los n-1 discos de la posicion auxiliar a la destino
        TowerHANNOI2(n - 1, Torre2, Torre3, Torre1, B, C, A);
    }
    return;
    
}
