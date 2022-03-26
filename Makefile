# all: td

td: Event.o PriorityQueue.o Queue.o EmptyDataCollectionException.o
	g++ -Wall -o td Event.o PriorityQueue.o Queue.o EmptyDataCollectionException.o

Event.o: Event.cpp Event.h
	g++ -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -Wall -c EmptyDataCollectionException.cpp

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ -Wall -c PriorityQueue.cpp

Queue.o: Queue.h Queue.cpp
	g++ -Wall -c Queue.cpp

clean:
	rm -f td *.o