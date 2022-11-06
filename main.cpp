#include <iostream>
#include <math.h>
#include <string>
#include "Pila.h"
using namespace std;

int tamanoTorre;
bool check_number(string);
void TowerHANNOI(int,ptrPila,ptrPila,ptrPila,char,char,char);



int main()
{

    char A,B,C;

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

    //AQUI COMIENZAN LOS CAMBIOS

    //Declaracion de las pilas
    ptrPila Torre1=NULL; 
    ptrPila Torre2=NULL;
    ptrPila Torre3=NULL;


    // Aqui se llenan las pilas de mayor a menor (5-4-3-2-1) para que quede ordenada de forma (1-2-3-4-5)
    for (int i = tamanoTorre; i > 0; i--)
    {
        push(Torre1,i);
    }

    //LLamado de la funcion recursiva
    // destaco que las variables A B C son para imprimir que disco se movio
    // el problema esta en lo que contienen las pilas

    TowerHANNOI(tamanoTorre,Torre1,Torre3,Torre2,'A','C','B');




    return 0;
}

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}



void TowerHANNOI(int n,ptrPila Torre1,ptrPila Torre3,ptrPila Torre2,char A,char C,char B){   //Torre 1 = Origen, Torre 2 = Aux, Torre 3 = Destino
    int x = 0; // indice del disco (puede tener error asi que aun queda a revision)
    //Solo cuando N sea igual a 1 se va a realizar el movimiento de los n-1 discos
    if(n == 1){
        x = pop(Torre1); //desapilacion de la Torre indice y obtencion del disco
        push(Torre3,x); // Apilacion para la Torre indice

        //Cuidado con la seccion de arriba ya que aqui puede ser que este el error
        //ya que a medida que avanza el algoritmo Torre 1 cambia de pila, lo mismo con Torre 3

        cout<<"Mueva el bloque "<<n<<" desde "<<A<<" hasta  "<<C<<endl;
        return;
    }else{
        //Primer llamado de la funcion recursiva.
        TowerHANNOI(n-1,Torre1,Torre2,Torre3,A,B,C);
        //Aqui se mueve el disco mas grande de la funcion a la posicion final
        x = pop(Torre1);
        push(Torre2,x);
        cout<<"Mueva el bloque "<<n<<" desde "<<A<<" hasta  "<<C<<endl;
        //Ultimo llamado de la funcion recursiva, y que permite mover los n-1 discos de la posicion auxiliar a la destino
        TowerHANNOI(n-1,Torre2,Torre3,Torre1,B,C,A);
    }    
    return;
}