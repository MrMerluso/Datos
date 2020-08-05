#include <iostream>
#include <string>

#include "fx.hpp"

using namespace std;


// Stack functions
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

// Queue functions
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

    while(hubStack!=NULL || javiStack!=NULL || johnStack != NULL){
        if(hubStack!=NULL){
            printerEnqueue(queue,hubStack->doc);
            popFromStack(hubStack);
            
        }
        if(javiStack!=NULL){
            printerEnqueue(queue,javiStack->doc);
            popFromStack(javiStack);
            
        }
        if(johnStack!=NULL){
            printerEnqueue(queue,johnStack->doc);
            popFromStack(johnStack);
            
        }
        
    }
    
}

// imprimir y remover elementos del queue
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
    string delimiter = "to";
    int pos = 0;
    string token;
    int last = 0; 
    int next = 0;
    while ((next = s.find(delimiter, last)) != string::npos){

        token = token+s.substr(last, next - last);
        if (s.find(delimiter, next+2) != string::npos){
            token = token+"to";
        }
        last = next + 2;
    }

    return token;
}


string getStackOwner(string s){
    string delimiter = "to";
    int pos = 0;

    int last = 0; 
    int next = 0;
    while ((next = s.find(delimiter, last)) != string::npos){

        last = next + 2;
    }
    return s.substr(last);
}

void liberarMemoria(stack *&hubStack, stack *&javiStack, stack *&johnStack, printer *&queue){
    while(hubStack!=NULL || javiStack!=NULL || johnStack != NULL){
        if(hubStack!=NULL){
            
            popFromStack(hubStack);
            
        }
        if(javiStack!=NULL){
            
            popFromStack(javiStack);
            
        }
        if(johnStack!=NULL){
            
            popFromStack(johnStack);
            
        }
    }
    delete hubStack;
    delete javiStack;
    delete johnStack;
    while(queue->front = NULL){
        printerDequeue(queue);
    }
    delete(queue);
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