all: BankSimApp

BankSimApp: EmptyDataCollectionException.o BankSimApp.o Event.o BinaryHeap.h PriorityQueue.h Queue.h
	g++ -Wall -o BankSimApp BankSimApp.o EmptyDataCollectionException.o Event.o

Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f BankSimApp *.o