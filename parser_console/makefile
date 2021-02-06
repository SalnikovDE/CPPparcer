all: parcer

parcer: main.o FilterCollection.o Filter.o FileHandler.o Params.o
	g++ main.o FilterCollection.o Filter.o FileHandler.o Params.o -o parcer

main.o: main.cpp
	g++ -c main.cpp

FilterCollection.o: CPPs/FilterCollection.cpp
	g++ -c CPPs/FilterCollection.cpp

Filter.o: CPPs/Filter.cpp
	g++ -c CPPs/Filter.cpp

FileHandler.o: CPPs/FileHandler.cpp
	g++ -c CPPs/FileHandler.cpp

Params.o: CPPs/Params.cpp
	g++ -c CPPs/Params.cpp

clean:
	rm -rf *.o parcer
