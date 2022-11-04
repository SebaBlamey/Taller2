#include <iostream>
using namespace std;
 
struct nodo{
    int nro;
    struct nodo *sgte;
};
 
typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )
 
/*                        Apilar elemento      
------------------------------------------------------------------------*/
void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
}
 
/*                Desapilar elemento(devuelve elemento)      
------------------------------------------------------------------------*/
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;
     
     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila
     
     p = aux->sgte ;
     delete(aux);
     
     return num;
}
 
/*                     Muestra elementos de la pila      
------------------------------------------------------------------------*/
void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }    
}
 
/*                Eliminar todos los elementos de la pila      
------------------------------------------------------------------------*/
void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}
 