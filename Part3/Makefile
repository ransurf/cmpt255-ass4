all: BankSimApp

BankSimApp: EmptyDataCollectionException.o SimulationApp.o BinaryHeap.h PriorityQueue.h Queue.h Event.h
	g++ -Wall -o BankSimApp SimulationApp.o EmptyDataCollectionException.o

SimulationApp.o: SimulationApp.cpp
	g++ -Wall -c SimulationApp.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f BankSimApp *.o