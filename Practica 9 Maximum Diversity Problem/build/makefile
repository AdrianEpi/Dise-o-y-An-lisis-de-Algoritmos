#Variable objetos
OBJECTS = main.o vertex.o edge.o graph.o Framework.o Algorithm.o Chrono.o $(ALGORITHMS)
ALGORITHMS = GreedyAlgorithm.o AnotherGreedyAlgorithm.o GraspAlgorithm.o
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


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run1:
	../bin/maxmean ../inputs/max_div_15_2.txt

run2:
	../bin/maxmean ../inputs/max_div_15_3.txt

run3:
	../bin/maxmean ../inputs/max_div_20_2.txt

run4:
	../bin/maxmean ../inputs/max_div_20_3.txt

run5:
	../bin/maxmean ../inputs/max_div_30_2.txt

run6:
	../bin/maxmean ../inputs/max_div_30_3.txt

git:
	git add ../.
	git commit -m "Upload"
	git push
