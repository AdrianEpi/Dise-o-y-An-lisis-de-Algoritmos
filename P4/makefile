CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -O2
LDFLAGS=-g -O2

FRAMEWORK_SRS=framework/Framework.cpp framework/Problema.cpp framework/Solucion.cpp
MERGESORT_SRS=src/mergeSortP.cpp src/mergeSortS.cpp
QUICKSORT_SRS=src/quickSortP.cpp src/quickSortS.cpp

SRCS=main.cpp $(FRAMEWORK_SRS) $(MERGESORT_SRS) $(QUICKSORT_SRS)
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o sort $(OBJS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend
