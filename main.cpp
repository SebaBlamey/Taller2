#include <iostream>
#include <math.h>
#include <string>
#include "Pila.h"
using namespace std;

int tamanoTorre;
bool check_number(string);
void TowerHANNOI(int,ptrPila,ptrPila,ptrPila);



int main()
{

    string number_turret;
    cout << "Cuantos discos debe tener la torre -> ";
    cin >> number_turret;
    while(!check_number(number_turret))
    {
        cout << "[INVALIDO] Cuantos discos debe tener la torre -> ";
        cin >> number_turret;
    }
    tamanoTorre = stoi(number_turret);
    cout << "Se resuelve con "<< (pow(2,tamanoTorre) - 1)<< " movimientos" << endl;

    ptrPila Torre1=NULL; // Origen
    ptrPila Torre2=NULL;
    ptrPila Torre3=NULL;

    for (int i = tamanoTorre; i > 0; i--)
    {
        push(Torre1,i);
    }

    mostrar_pila(Torre1);
    
    cout << "--------------"<< endl;
    mostrar_pila(Torre1);
    cout << "--------------"<< endl;
    mostrar_pila(Torre2);
    cout << "--------------"<< endl;
    mostrar_pila(Torre3);
    cout << "--------------"<< endl;
    TowerHANNOI(tamanoTorre,Torre1,Torre2,Torre3);
    cout << "--------------"<< endl;
    return 0;
}

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}



void TowerHANNOI(int n,ptrPila TorreOrigen,ptrPila TorreDestino,ptrPila TorreAuxiliar){   //Torre 1 = Origen, Torre 2 = Aux, Torre 3 = Destino
    
    if(n == 1){
        int x = pop(TorreOrigen);
        push(TorreDestino,x);
        
        return;
    }else{
        cout << "."<< endl;
        TowerHANNOI(n-1,TorreOrigen,TorreAuxiliar,TorreDestino);
        cout << "."<< endl;
        int x = pop(TorreOrigen);
        push(TorreDestino,x);
        TowerHANNOI(n-1,TorreAuxiliar,TorreDestino,TorreOrigen);
        cout << "."<< endl;
    }
    return;
}