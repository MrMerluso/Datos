#include <iostream>
#include <string>

#include "fx.hpp"

using namespace std;

int main(){

    printer *Printer = new printer;
    Printer->back = NULL;
    Printer->front = NULL;

    stack *hubStack = NULL;
    stack *javiStack = NULL;
    stack *johnStack = NULL;
    
    string command;

    //Podría usar un switch para hacerlo fancy, pero esto es más fácil.
    while(true){
        cin>>command;
        if(command == "add"){
            string args;
            getline(cin,args);
            
            if (getStackOwner(args) == "hubert stack"){
                cout << "hubert" << endl;
                pushToStack(hubStack,getDoc(args));
            }
            else if (getStackOwner(args) == "javiera stack"){
                cout << "javi" << endl;
                pushToStack(javiStack,getDoc(args));
            }
            else if (getStackOwner(args) == "john stack"){
                cout << "john" << endl;
                pushToStack(johnStack,getDoc(args));
            }        

        }else if (command == "turn"){

            string arg;
            cin>>arg;
            //Asumo que cuando se apaga la impresora se libera la memoria

            cout << command << "and" << arg << endl;
            if(arg== "on"){
                Printer->turnPrinterOn();
                cout << Printer->isOn << endl;
            }
            else if(arg == "off"){
                Printer->turnPrinterOff();
                // liberarMemoria();
                cout << Printer->isOn << endl;
                break;
            }

        }else if(command == "read"){
            if(Printer->checkPrinter()){
                readDocs(hubStack,javiStack,johnStack,Printer);
                printQueue(Printer);
            }else{
                cout << "the printer is off" << endl;
            }

        }else if(command == "print"){
            if(Printer->checkPrinter()){
                print(Printer);
            }else{
                cout << "the printer is off" << endl;
            }
        }
    }
    printQueue(Printer);
    cout << "hubStack" << endl;
    printStack(hubStack);
    cout << "javiStack" << endl;
    printStack(javiStack);
    cout << "johnStack" << endl;
    printStack(johnStack);

    /* cout << printer.checkPrinter() << endl;

    printer.turnPrinter();

    cout << printer.checkPrinter() << endl; */

    return 0;
}