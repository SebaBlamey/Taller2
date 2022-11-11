#include <math.h>
#include <iostream>
#include <string>
#include "Pilas.h"
using namespace std;

int tamanoTorre;
bool check_number(string);
void TowerHANNOI2(int, Pilas*, Pilas*, Pilas*, char, char, char);

int main() {
    char A, B, C;
    //Seccion para solicitar los N discos que poseera la torre
    string number_turret;
    cout << "Cuantos discos debe tener la torre -> ";
    cin >> number_turret;
    //Seccion para determinar la comprobacion de digito
    while (!check_number(number_turret)) {
        cout << "[INVALIDO] Cuantos discos debe tener la torre -> ";
        cin >> number_turret;
    }
    tamanoTorre = stoi(number_turret);
    cout << "Se resuelve con " << (pow(2, tamanoTorre) - 1) << " movimientos" << endl;
    //Creacion de los Stacks
    Pilas *Torre1 = new Pilas();
    Pilas *Torre2 = new Pilas();
    Pilas *Torre3 = new Pilas();

    //Ciclo for para poder almacenar la informacion solicitada por el usuario
    for (int i = tamanoTorre; i > 0; i--) {
        Torre1->push(i);
    }

    cout <<"  Antes del Algoritmo"<<endl;
    cout <<" ______________________"<<endl;    

    cout <<"      Torre 1"<<endl;
    cout <<"     ________"<<endl;
    Torre1->imprimir();
    cout <<"      Torre 2"<<endl;
    cout <<"     ________"<<endl;    
    Torre2->imprimir();
    cout <<"      Torre 3"<<endl;
    cout <<"     ________"<<endl;    


    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    Torre3->imprimir();    
    //Llamado de la funcion
    TowerHANNOI2(tamanoTorre, Torre1, Torre3, Torre2, 'A', 'C', 'B');
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;

    cout <<"  Despues del Algoritmo"<<endl;
    cout <<" ______________________"<<endl;    

    cout <<"      Torre 1"<<endl;
    cout <<"     ________"<<endl;
    Torre1->imprimir();
    cout <<"      Torre 2"<<endl;
    cout <<"     ________"<<endl;    
    Torre2->imprimir();
    cout <<"      Torre 3"<<endl;
    cout <<"     ________"<<endl;    
    Torre3->imprimir();
    

    

    return 0;
}
/**
 * Funcion que permite verificar si la cantidad de discos ingresados sea realmente un digito y no un signo o letra
 *  @param string str Se utiliza para confirmar si es un numero 
 *  @return devuelve un true si es una letra, y un false si es un numero
*/
bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
/**
 * Funcion que permite simular el traslado de los discos de una torre origen a una destino, pasando por una auxiliar.
 * Destacar que tiene 2 llamados recurisvos, ya que realiza la funcion de (2^n)-1 que es la funcion para determinar los n pasos de la torre.
 * El algoritmo consiste en mover los n-1 discos de la torre principal a la torre auxiliar, luego mover el disco mas grande a la torre destino, y finalmente mover los n-1 discos a la torre desitno
 * 
 * @param int n  Entero que simula la cantidad de discos (los N discos)
 * @param Pilas *Torre1  Pila con nombre Torre 1, Esta Torre viene siendo la Torre origen, desde donde comienzan los discos
 * @param Pilas *Torre2  Pila Con nombre Torre 2, Esta Torre viene siendo la Torre Auxiliar, la cual se usara para hacer los movimientos necesarios
 * @param Pilas *Torre3  Pila con nombre Torre 3, Esta Torre viene siendo la Torre Destino y sera la torre que albergue los discos al final del algoritmo
 * @param char  El Char 'A' simula la torre 1
 * @param char  El Char 'B' simula la torre 2
 * @param char  El Char 'C' simula la torre 3
 * 
 * Destacar que el orden de los parametros va cambiando segun va avanzando el algoritmo, por ejemplo para mover un disco en una torre de 1 solo disc, bastara con moverlo de una torre a otra,
 * sin importar que torre sea, puede ser la auxiliar o la destino.
 * Sin embargo si la torre tiene 2 o mas discos, aqui los parametros si van a variar, ya que al principio, se movera el primer disco a la torre auxiliar, luego el segundo disco a la torre destino
 * y finalmente se volvera a mover el disco 1 desde la torre auxiliar a la torre 3, dicho con parametros seria lo siguiente: 
 * disco 1 de T1 a T2
 * disco 2 de T1 a T3
 * disco 1 de T2 a T3
 * 
 * Y destacar que si son 3 discos, primero se harian los movimientos pertinentes para una torre con 2 discos, agregandole el disco adicional.
 * 
*/
void TowerHANNOI2(int n, Pilas *Torre1, Pilas *Torre3, Pilas *Torre2, char A, char C, char B) {
    int x = 0;                                                                               

    if (n == 1) {
        Torre3->push(Torre1->pop());
        cout << "Se mueve el bloque " << n << " desde " << A << " hasta  " << C << endl;
        return;
    } else {
        TowerHANNOI2(n - 1, Torre1, Torre2, Torre3, A, B, C);
        int aux = Torre1->pop();
        Torre3->push(aux);
        cout << "Se mueve el bloque " << n << " desde " << A << " hasta  " << C << endl;        
        TowerHANNOI2(n - 1, Torre2, Torre3, Torre1, B, C, A);
    }
    return;
    
}