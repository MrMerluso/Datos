/*
 * Clase que permite manejar el mapa
 * (trabaja con archivos de extension "pbm").
 * INF-134 Estructuras de Datos
 */

#ifndef MAP_H_			// Comprueba si la etiqueta no esta definida
#define MAP_H_			// Crea una bandera en tiempo de compilacion

#include <fstream>			// Biblioteca para las operaciones con archivos
#include <iostream>		

class Map{
	public:
	/* Constructores y metodos */
		Map(): _array(NULL), _width(0), _height(0) {}
		Map(std::ifstream& data);
		bool** getArray() {return _array;}
		int getWidth() {return _width;}
		int getHeight() {return _height;}
		void dim();
		bool isThere_an_island(int x, int y);
		void islands_positions();
	private:
	/* Declaracion de variables */
		bool** _array;
		int _width, _height;
};

#endif 		/* Codigo se incluye en el paquete
 	 	 	 * que se envia al compilador hasta aqui */
