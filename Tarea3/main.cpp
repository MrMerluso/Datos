#include <iostream>

#include "fx.hpp"

using namespace std;

int main(){

    printer printer;

    string command;

    cin>>command;

    if(command == "add"){
        string args;
        getline(cin,args);

        cout << "comm: " << command << " arg: " << args <<endl;
    }else if (command == "turn")
    {
        string arg;
        cin>>arg;

        cout << "comm: " << command << " arg: " << arg <<endl;
    }
    

    /* cout << printer.checkPrinter() << endl;

    printer.turnPrinter();

    cout << printer.checkPrinter() << endl; */

    return 0;
}