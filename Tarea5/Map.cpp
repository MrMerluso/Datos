/*
 * Implementación de las funciones para manejar el mapa
 * (trabaja con archivos de extension "pbm").
 * INF-134 Estructuras de Datos
 */

#include <string> 			// Biblioteca para utilizar funciones sobre strings
#include <limits>			// Biblioteca para funciones que definen limites
#include "Map.h"			/* Incluye libreria de cabecera que define
							 * los constructores y metodos a implementar */
#include <stdlib.h>
#include <cmath>

using namespace std;		// Incluye espacio  de nombres para palabras reservadas

Map::Map(ifstream& data){
	string read, aux;
	data.ignore(numeric_limits<streamsize>::max(), '\n');
	data.ignore(numeric_limits<streamsize>::max(), '\n');

	getline(data, read, ' ');
	_width = atoi(read.c_str());		// Obtiene ancho desde archivo
	getline(data, read);
	_height = atoi(read.c_str());	// Obtiene largo desde archivo

	_array = new bool*[_height];					// Define alto del arreglo
	for (int h = 0; h < _height; h++) {
		_array[h] = new bool[_width];				// Define ancho del arreglo
	}

	getline(data, read);
	while (!data.eof()) {
		getline(data, aux);		// Lee linea por linea desde data
		read += aux;			// Las almacena en un string
	}

	int length = read.length();
	for (int i = length-1; i >= 0; --i) {
		if(read[i] == ' ')
			read.erase(i, 1);
	}
	//read.erase(std::remove(read.begin(),read.end(),' '),read.end());

	for (int h = 0; h < _height; h++) {
		for (int w = 0; w < _width; w++) {			// Guarda informacion en el arreglo
			(read[(h*_width) + w] == '1') ?
				_array[h][w] = true : _array[h][w] = false;
		}
	}
	
	costos = new int * [];
	/* Constructor que se encarga de obtener y almacenar informacion desde data */
}


bool Map::isThere_an_island(int x, int y) {
	return (_array[y][x]);
	/* Metodo que retorna true en caso de hallar una isla */
}
void Map::dim(){
	cout << "width = " << _width << " height = " << _height << endl;
	/* Metodo que escribe en pantalla las dimensiones */
}

void Map::islands_positions(queue *&c){

	for(int j = 0; j < _height; j++){
		for(int i = 0; i<_width;i++){
			if(isThere_an_island(i,j)) {
				cout<<"Isla en: ("<< i << "," << j<<") ";
				ponerEnCola(i,j,c);
			}
		}
		cout<<endl;
	}
	/* Metodo que escribe en pantalla las las posiciones de las islas */
}	

int Map::getDistance(node * a, node * b){
	int x1 = a->x;
	int y1 = a->y;
	int x2 = b->x;
	int y2 = b->y;

	int resta1 = x2-x1;
	int resta2 = y2-y1;

	return round(hypot(resta1,resta2));

}

//funciones cola

void ponerEnCola(int x, int y, queue *&c){
    node * temp = new node;
    temp->x = x;
	temp->y = y;
    temp->next = NULL;

    if(c->front == NULL && c->back == NULL){
        c->front = c->back = temp;
        return;
    }
    c->back->next = temp;
    c->back = temp;
}

void quitar(queue *&c){

	node *tmp = c->front;
	c->front = c->front->next;
	delete tmp;

	
}

int queueLength(queue *c){
	int count = 0;
	for(node *it = c->front;it != NULL; it = it->next){
		count++;
	}
	return count;
}

void PRINT(queue *c){
    for(node *it = c->front;it != NULL; it = it->next){
        cout<<"("<< it->x << "," << it->y <<")" <<endl;
    }
}
