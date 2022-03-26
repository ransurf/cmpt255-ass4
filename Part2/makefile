all: td

td: EmptyDataCollectionException.o testDriver.o BinaryHeap.h PriorityQueue.h
	g++ -Wall -o td testDriver.o EmptyDataCollectionException.o

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -Wall -c BinaryHeap.cpp

testDriver.o: testDriver.cpp PriorityQueue.h
	g++ -Wall -c testDriver.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o