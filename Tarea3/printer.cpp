#include <iostream>
#include <string>

#include "fx.hpp"

using namespace std;

void pushToStack(stack *&nodo, string doc){
    stack * tmp = new stack;
    tmp->doc=doc;
    tmp->next=nodo;
    nodo = tmp;
};

void popFromStack(stack *&nodo){
    stack * tmp = nodo;
    nodo = nodo->next;
    tmp->next=NULL;
    delete tmp;
}

//Las siguientes funciones son para retornar el documento y el stack al que se vna a añadir.
//Pensé en hacerlo con una sola funcion y retornar una lista con los dos strings pero StackOverflow 
//me dijo "no, no, no" (podía causar problemas con memoria y no queria lidiar con eso)

string getDoc(string s){
    string delimiter = " to ";
    int pos = s.find(delimiter);
    string token = s.substr(0,pos);
    return token;
}

string getStackOwner(string s){
    string delimiter = " to ";
    int pos = s.find(delimiter);
    string token = s.erase(0, pos + delimiter.length());
    return token;
}

//Funciones temporales para imprimir por pantalla lista/cola, remover antes de entregar(?)
void printStack(stack *nodo){
    for(stack *it = nodo;it != NULL; it = it->next){
        cout<<it->doc<<endl;
    }
}

void printQueue(printer *nodo){
    for(node *it = nodo->front;it != NULL; it = it->next){
        cout<<it->doc<<endl;
    }
}