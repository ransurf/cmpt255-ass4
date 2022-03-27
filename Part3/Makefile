all: td

td: EmptyDataCollectionException.o SimulationApp.o BinaryHeap.h PriorityQueue.h Queue.h Event.h
	g++ -Wall -o td SimulationApp.o EmptyDataCollectionException.o

SimulationApp.o: SimulationApp.cpp
	g++ -Wall -c SimulationApp.cpp

# Event.o: Event.cpp Event.h
# 	g++ -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o