#ifndef FX_HPP
#define FX_HPP

#include <iostream>
#include <string>

using namespace std;

// Sé que este es el metodo "pajero" de implementar esto, pero son las 1:17 AM
// y estoy haciendo esto porque estoy aburrido

struct node{
    string doc;
    node *next;
    
};

struct printer{     

    node *front, *back;     
    bool isOn = false;

    // No tengo idea de si esta es la forma correcta de añadir esto al archivo hpp. Que mal.


    bool checkPrinter(){
        return isOn;
    }

    void turnPrinterOn(){
        isOn=true;
        cout << "the printer is on" << endl;  
    }

    void turnPrinterOff(){
        isOn=false;
    }
};

struct stack{
    string doc;
    stack *next;
};


void pushToStack(stack *&nodo, string doc);
void popFromStack(stack *&nodo);

void printerEnqueue(printer *&queue, string doc);
void printerDequeue(printer *&queue);

void readDocs(stack *&hubStack, stack *&javiStack, stack *&johnStack, printer *&queue);
void print(printer *&queue);

string getDoc(string s);
string getStackOwner(string s);

void liberarMemoria(stack *&hubStack, stack *&javiStack, stack *&johnStack, printer *&queue);

void printStack(stack *nodo);
void printQueue(printer *nodo);
#endif