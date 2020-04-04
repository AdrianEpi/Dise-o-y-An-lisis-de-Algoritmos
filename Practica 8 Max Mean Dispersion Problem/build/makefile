#Variable objetos
OBJECTS = main.o fileReader.o voraz.o GRASP.o multiarranque.o vns.o
#Flags de compilacion
CFLAGS = -c -std=c++17

maxmean: $(OBJECTS)
	g++  $(OBJECTS) -o maxmean
	mv *.o ../objects
	mv maxmean ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

fileReader.o: ../src/fileReader.cpp ../include/fileReader.hpp
	g++ $(CFLAGS) ../src/fileReader.cpp

voraz.o: ../src/voraz.cpp ../include/voraz.hpp
	g++ $(CFLAGS) ../src/voraz.cpp

GRASP.o: ../src/GRASP.cpp ../include/GRASP.hpp
	g++ $(CFLAGS) ../src/GRASP.cpp

multiarranque.o: ../src/multiarranque.cpp ../include/multiarranque.hpp
	g++ $(CFLAGS) ../src/multiarranque.cpp

vns.o: ../src/vns.cpp ../include/vns.hpp
	g++ $(CFLAGS) ../src/vns.cpp

.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*



