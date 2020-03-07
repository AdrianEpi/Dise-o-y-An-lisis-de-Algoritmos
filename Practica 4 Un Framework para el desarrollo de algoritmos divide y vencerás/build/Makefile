#Variable objetos
OBJECTS = main.o Framework.o Problema.o Solucion.o
#Flags de compilacion
CFLAGS = -c -std=c++17

game: $(OBJECTS)
	g++  $(OBJECTS) -o game
	mv *.o ../objects
	mv game ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

Framework.o: ../src/Framework.cpp ../include/Framework.h
	g++ $(CFLAGS) ../src/Framework.cpp

Problema.o: ../src/Problema.cpp ../include/Problema.h
	g++ $(CFLAGS) ../src/Problema.cpp

Solucion.o: ../src/Solucion.cpp ../include/Solucion.h
	g++ $(CFLAGS) ../src/Solucion.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/game


