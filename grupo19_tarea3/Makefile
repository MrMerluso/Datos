tarea3: main.o printer.o
	g++ main.o printer.o -o tarea3

main.o: main.cpp
	g++ -c main.cpp

printer.o: printer.cpp fx.hpp
	g++ -c printer.cpp
	
clean:
	rm *.o tarea3