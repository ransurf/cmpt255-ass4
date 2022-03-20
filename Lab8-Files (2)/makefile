all: td

td: testDriver.o Event.o EmptyDataCollectionException.o BinaryHeap.h
	g++ -Wall -o td testDriver.o Event.o EmptyDataCollectionException.o

testDriver.o: testDriver.cpp
	g++ -Wall -c testDriver.cpp 
		
Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o