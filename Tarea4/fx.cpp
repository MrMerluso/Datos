#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#include"fx.hpp"

void readFile(string file, node *& head){
    string line;
    string delimiter = ";";
    ifstream readFile(file);

    while (getline(readFile,line)){ //leer el archivo
        string aux[4];              // head en la que se pone el string
        
        int i2 = 0;

        int pos = 0;
        string token;

        while((pos = line.find(delimiter)) != string::npos){        //dividir string en ";"        
            token = line.substr(0,pos);
            aux[i2] = token;
            line.erase(0,pos+delimiter.length());
            i2++;
        };

        aux[3]=line;
        
        addList(head,aux);

    }
    
}

void addList(node *&head, string linea[4]){
    
    node * newStudent = new node;
    
    newStudent->info.rol = linea[0];
    newStudent->info.nombre = linea[1];
    newStudent->info.carrera = linea[2];
    newStudent->info.yr = linea[3];
    
    node * aux1=head;
    node * aux2;
    
    while(aux1 != NULL){
        
        aux2 = aux1;
        aux1 = aux1->next;
    }
    
    if(head == aux1){
        head = newStudent;
    }else{
        aux2->next = newStudent;
    };
    newStudent->next=aux1;
    
}

void insertStudent(node *&head, string * arreglo, int largo){
    // while(head != NULL){
    //     char rol = head->info.rol;
    // }
}

int sumRol(string rol){
    int suma = 0;
    if(rol.find("K") != string::npos){
        rol = rol.substr(0,9);
    }
    int ROL = stoi(rol);
    while(ROL!=0){
        int digito = ROL % 10;
        suma +=digito;
        ROL /= 10;
    }
    return suma;
}

int hash(string x, int largo){
    int suma = sumRol(x);
    return suma % largo;
}

void removeList(node *&head){
    node * tmp = head;
    head = head->next;
    tmp->next=NULL;
    delete tmp;
}

void printList(node *head){  //imprimir lista en pantalla
    int count = 0;
    for (node *it = head; it != NULL; it = it -> next) {
        cout <<it->info.nombre<< endl;
        count++;
    }
}
