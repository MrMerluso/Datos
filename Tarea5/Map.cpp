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
	read.erase(std::remove(read.begin(),read.end(),' '),read.end());

	for (int h = 0; h < _height; h++) {
		for (int w = 0; w < _width; w++) {			// Guarda informacion en el arreglo
			(read[(h*_width) + w] == '1') ?
				_array[h][w] = true : _array[h][w] = false;
		}
	}
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

void Map::islands_positions(){
	for(int j = 0; j < _height; j++){
		for(int i = 0; i<_width;i++){
			if(isThere_an_island(i,j)) cout<<"Isla en: ("<< i << "," << j<<") ";	
		}
		cout<<endl;
	}
	/* Metodo que escribe en pantalla las las posiciones de las islas */
}				
