#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int tamanoTorre;
bool check_number(string);

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
    return 0;
}

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}