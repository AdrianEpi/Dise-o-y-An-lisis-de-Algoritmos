#Variable objetos
OBJECTS = main.o Framework.o Problema.o Solucion.o mergeSortP.o mergeSortS.o quickSortP.o quickSortS.o
#Flags de compilacion
CFLAGS = -c -std=c++17

default: $(OBJECTS)
	g++  $(OBJECTS) -o framework
	mv *.o ../objects
	mv framework ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

Framework.o: ../src/Framework.cpp ../includes/Framework.h
	g++ $(CFLAGS) ../src/Framework.cpp

Problema.o: ../src/Problema.cpp ../includes/Problema.h
	g++ $(CFLAGS) ../src/Problema.cpp

Solucion.o: ../src/Solucion.cpp ../includes/Solucion.h
	g++ $(CFLAGS) ../src/Solucion.cpp

mergeSortP.o: ../src/mergeSortP.cpp ../includes/mergeSortP.h
	g++ $(CFLAGS) ../src/mergeSortP.cpp

mergeSortS.o: ../src/mergeSortS.cpp ../includes/mergeSortS.h
	g++ $(CFLAGS) ../src/mergeSortS.cpp

quickSortP.o: ../src/quickSortP.cpp ../includes/quickSortP.h
	g++ $(CFLAGS) ../src/quickSortP.cpp

quickSortS.o: ../src/quickSortS.cpp ../includes/quickSortS.h
	g++ $(CFLAGS) ../src/quickSortS.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run1:
	../bin/framework 1 500

run2:
	../bin/framework 2 500


