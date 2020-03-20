#Variable objetos
OBJECTS = main.o calendar.o
#Flags de compilacion
CFLAGS = -c -std=c++17

calendar: $(OBJECTS)
	g++  $(OBJECTS) -o calendar
	mv *.o ../objects
	mv calendar ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

calendar.o: ../src/calendar.cpp ../include/calendar.hpp
	g++ $(CFLAGS) ../src/calendar.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/calendar 16

