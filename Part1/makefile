all: td

td: testDriver.o EmptyDataCollectionException.o Queue.h
	g++ -Wall -o td testDriver.o EmptyDataCollectionException.o

# Queue.o: Queue.h Queue.cpp
# 	g++ -Wall -c Queue.cpp

testDriver.o: testDriver.cpp
	g++ -Wall -c testDriver.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o