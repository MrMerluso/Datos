/*
 * Clase principal del programa.
 * Implementa los constructores y metodos esenciales que permiten el inicio del
 * programa, asi como la interaccion entre todas las clases.
 * INF-134 Estructuras de Datos
 */

#include <iostream>		// Biblioteca para las operaciones de entrada y salida
#include <fstream>			// Biblioteca para el tratamiendo de archivos
#include <stdlib.h>
#include "Map.h"			// Biblioteca de cabecera para el uso del mapa
using namespace std;		// Incluye espacio de nombres para palabras reservadas

int main(int argc, char* argv[]) {
	ifstream map_in;	// MAPA

	if (argc != 2) {
		cout << "Usage: ./Tarea5 <pbm input file> " << endl;
		exit(1);
	}

	map_in.open(argv[1]);		// map_in.open("archivo.pbm");
	if (map_in.fail()) {
		cout << "Error al abrir el archivo " << argv[1] << endl;
		exit(1);
	}

	Map map(map_in); // inicia el mapa
	map.dim(); //Muestra las dimensiones del mapa en pantalla
	map.islands_positions(); //Muestra posiciones de las islas en pantalla
	map_in.close();			// Cierra el archivo del map
	return 0;
}
