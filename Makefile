all: td

td: SimulationApp.o Queue.h PriorityQueue.h Node.h Event.o EmptyDataCollectionException.o
	g++ -Wall -o td SimulationApp.o Event.o EmptyDataCollectionException.o

Event.o: Event.cpp Event.h
	g++ -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o