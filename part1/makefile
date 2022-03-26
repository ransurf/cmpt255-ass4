all: td

td: main.o Queue.o Node.o EmptyDataCollectionException.o
	g++ -Wall -o td main.o Queue.o Node.o EmptyDataCollectionException.o

main.o: main.cpp
	g++ -Wall -c main.cpp 
		
Queue.o: Queue.h Queue.cpp
	g++ -Wall -c Queue.cpp

Node.o: Node.h Node.cpp
	g++ -Wall -c Node.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o