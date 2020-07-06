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

void printerEnqueue(printer *&queue, string doc){
    node * temp = new node;
    temp->doc = doc;
    temp->next = NULL;
    if(queue->front == NULL && queue->back == NULL){
        queue->front = queue->back = temp;
        return;
    }
    queue->back->next = temp;
    queue->back = temp;
}

void printerDequeue(printer *&queue){
    node * temp = queue->front;
    if(queue->front == queue->back){
        queue->front = queue->back = NULL;
    }else{
        queue->front = queue->front->next;
    }
    delete temp;
}

// Ler los documentos de los stack y meterlos al q
void readDocs(stack *&hubStack, stack *&javiStack, stack *&johnStack, printer *&queue){
    int i=0;
    while(hubStack!=NULL || javiStack!=NULL || johnStack != NULL){
        if(hubStack!=NULL){
            printerEnqueue(queue,hubStack->doc);
            popFromStack(hubStack);
            i++;
        }
        if(javiStack!=NULL){
            printerEnqueue(queue,javiStack->doc);
            popFromStack(javiStack);
            i++;
        }
        if(johnStack!=NULL){
            printerEnqueue(queue,johnStack->doc);
            popFromStack(johnStack);
            i++;
        }
        
    }
    cout<<i<<" documents added!"<<endl;
}

void print(printer *&queue){
    while(queue->front != NULL){
        cout << queue->front->doc << endl;
        printerDequeue(queue); 
    }
}

//Las siguientes funciones son para retornar el documento y el stack al que se vna a añadir.
//Pensé en hacerlo con una sola funcion y retornar una lista con los dos strings pero StackOverflow 
//me dijo "no, no, no" (podía causar problemas con memoria y no queria lidiar con eso)

// TODO: NO FUNCIONA CON EL EJEMPLO "add how to poner atencion en clases online easy to john stack"
// ya que hay 2 "to" en el string y las funciones dividen cuando encuentran el primer "to". FIX FAST.
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
// NO USAR ESTA FUNCION PARA LO QUE PIDE LA TAREA
void printQueue(printer *nodo){
    for(node *it = nodo->front;it != NULL; it = it->next){
        cout<<it->doc<<endl;
    }
}