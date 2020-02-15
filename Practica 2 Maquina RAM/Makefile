#Flags de compilacion
CFLAGS = -c -std=c++17

ram_sim: main.o machineRAM.o inputTape.o instruction.o outputTape.o registers.o tag.o tagRegister.o
	g++  main.o machineRAM.o inputTape.o instruction.o outputTape.o registers.o tag.o tagRegister.o -o ram_sim
	mv *.o ./objects
	mv ram_sim ./bin


main.o: ./src/main.cpp
	g++ $(CFLAGS) ./src/main.cpp

machineRAM.o: ./src/machineRAM.cpp ./include/machineRAM.hpp
	g++ $(CFLAGS) ./src/machineRAM.cpp

inputTape.o: ./src/inputTape.cpp ./include/inputTape.hpp
	g++ $(CFLAGS) ./src/inputTape.cpp

instruction.o: ./src/instruction.cpp ./include/instruction.hpp
	g++ $(CFLAGS) ./src/instruction.cpp

outputTape.o: ./src/outputTape.cpp ./include/outputTape.hpp
	g++ $(CFLAGS) ./src/outputTape.cpp

registers.o: ./src/registers.cpp ./include/registers.hpp
	g++ $(CFLAGS) ./src/registers.cpp

tag.o: ./src/tag.cpp ./include/tag.hpp
	g++ $(CFLAGS) ./src/tag.cpp

tagRegister.o: ./src/tagRegister.cpp ./include/tagRegister.hpp
	g++ $(CFLAGS) ./src/tagRegister.cpp



.PHONY: clean
clean:
	rm -rf ./objects/*.o
	rm -rf ./bin/*

run1:
	./bin/ram_sim ./inputs/ram_program.ram ./inputs/input_tape.in ./inputs/output_tape.out 1

run0:
	./bin/ram_sim ./inputs/ram_program.ram ./inputs/input_tape.in ./inputs/output_tape.out 1
