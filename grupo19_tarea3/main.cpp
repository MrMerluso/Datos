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
            
            if (getStackOwner(args) == " hubert stack"){
                
                pushToStack(hubStack,getDoc(args));
            }
            else if (getStackOwner(args) == " javiera stack"){

                pushToStack(javiStack,getDoc(args));
            }
            else if (getStackOwner(args) == " john stack"){

                pushToStack(johnStack,getDoc(args));
            }        

        }else if (command == "turn"){

            string arg;
            cin>>arg;
            //Asumo que cuando se apaga la impresora se libera la memoria

            if(arg== "on"){
                Printer->turnPrinterOn();
            }
            else if(arg == "off"){
                Printer->turnPrinterOff();
                liberarMemoria(hubStack,javiStack,johnStack,Printer);
                break;
            }

        }else if(command == "read"){
            if(Printer->checkPrinter()){
                readDocs(hubStack,javiStack,johnStack,Printer);
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
    // printQueue(Printer);
    // cout << "hubStack" << endl;
    // printStack(hubStack);
    // cout << "javiStack" << endl;
    // printStack(javiStack);
    // cout << "johnStack" << endl;
    // printStack(johnStack);

    /* cout << printer.checkPrinter() << endl;

    printer.turnPrinter();

    cout << printer.checkPrinter() << endl; */

    return 0;
}