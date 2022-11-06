#include <iostream>
using namespace std;

class Pilas {
   private:
    class Nodo {
       public:
        int numero;
        Nodo *siguiente;
    };
    Nodo *root;

   public:
    Pilas();
    ~Pilas();
    void push(int x);
    int pop();
    void imprimir();
};