all: BankSimApp

BankSimApp: EmptyDataCollectionException.o BankSimApp.o BinaryHeap.h PriorityQueue.h Queue.h Event.h
	g++ -Wall -o BankSimApp BankSimApp.o EmptyDataCollectionException.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f BankSimApp *.o