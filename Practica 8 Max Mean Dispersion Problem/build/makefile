#Variable objetos
OBJECTS = main.o vertex.o edge.o graph.o Framework.o Algorithm.o Chrono.o $(ALGORITHMS)
ALGORITHMS = GreedyAlgorithm.o AnotherGreedyAlgorithm.o GraspAlgorithm.o MultiBootAlgorithm.o
#Flags de compilacion
CFLAGS = -c -std=c++17

maxmean: $(OBJECTS)
	g++  $(OBJECTS) -o maxmean
	mv *.o ../objects
	mv maxmean ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

vertex.o: ../src/vertex.cpp ../include/vertex.hpp
	g++ $(CFLAGS) ../src/vertex.cpp

edge.o: ../src/edge.cpp ../include/edge.hpp
	g++ $(CFLAGS) ../src/edge.cpp

graph.o: ../src/graph.cpp ../include/graph.hpp
	g++ $(CFLAGS) ../src/graph.cpp

Framework.o: ../src/Framework.cpp ../include/Framework.hpp
	g++ $(CFLAGS) ../src/Framework.cpp

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp

Algorithm.o: ../src/Algorithm.cpp ../include/Algorithm.hpp
	g++ $(CFLAGS) ../src/Algorithm.cpp

GreedyAlgorithm.o: ../src/GreedyAlgorithm.cpp ../include/GreedyAlgorithm.hpp
	g++ $(CFLAGS) ../src/GreedyAlgorithm.cpp

AnotherGreedyAlgorithm.o: ../src/AnotherGreedyAlgorithm.cpp ../include/AnotherGreedyAlgorithm.hpp
	g++ $(CFLAGS) ../src/AnotherGreedyAlgorithm.cpp

GraspAlgorithm.o: ../src/GraspAlgorithm.cpp ../include/GraspAlgorithm.hpp
	g++ $(CFLAGS) ../src/GraspAlgorithm.cpp

MultiBootAlgorithm.o: ../src/MultiBootAlgorithm.cpp ../include/MultiBootAlgorithm.hpp
	g++ $(CFLAGS) ../src/MultiBootAlgorithm.cpp

.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/maxmean

