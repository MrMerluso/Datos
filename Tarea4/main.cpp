#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#include"fx.hpp"

int main(int argc, char *argv[]){

    node * lista = NULL;

    string file = argv[1];
    int largo = atoi(argv[2]);

    alumno * alumnos = NULL;

    alumnos = new alumno[largo];

    

    

    readFile(file,lista);
    
    
    

    insertStudent(lista,alumnos,largo);

    delete [] alumnos;
    
    

    return 0;
}