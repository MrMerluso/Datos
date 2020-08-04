#ifndef FX_HPP
#define FX_HPP

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct alumno{
    string rol;
    string nombre;
    string carrera;
    string yr;
};

struct node{
    alumno * info;
    node * next;
};

void readFile(string file, node *&head);
int sumRol(string rol);
int hasah(string x, int largo);
void insertStudent(node *&head, alumno* arreglo, int largo);

void addList(node *&head,string linea[4]);
void removeList(node *&head);

void printList(node *head);

#endif