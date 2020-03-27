#Variable objetos
OBJECTS = main.o lcs.o
#Flags de compilacion
CFLAGS = -c -std=c++17

default: $(OBJECTS)
	g++  $(OBJECTS) -o lcs
	mv *.o ../objects
	mv lcs ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

lcs.o: ../src/lcs.cpp ../include/lcs.hpp
	g++ $(CFLAGS) ../src/lcs.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/lcs
