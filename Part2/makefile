all: td

td: EmptyDataCollectionException.o TestDriver.o BinaryHeap.h PriorityQueue.h
	g++ -Wall -o td TestDriver.o EmptyDataCollectionException.o

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -Wall -c BinaryHeap.cpp

TestDriver.o: TestDriver.cpp PriorityQueue.h
	g++ -Wall -c TestDriver.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o