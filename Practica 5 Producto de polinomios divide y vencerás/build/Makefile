#Variable objetos
OBJECTS = main.o monomio.o polinomio.o
#Flags de compilacion
CFLAGS = -c -std=c++17

polinomioDyV: $(OBJECTS)
	g++  $(OBJECTS) -o polinomioDyV
	mv *.o ../objects
	mv polinomioDyV ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

monomio.o: ../src/monomio.cpp ../include/monomio.hpp
	g++ $(CFLAGS) ../src/monomio.cpp

polinomio.o: ../src/polinomio.cpp ../include/polinomio.hpp
	g++ $(CFLAGS) ../src/polinomio.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/polinomioDyV 100 100 1
