# all: td

# td: Event.o PriorityQueue.h Queue.o EmptyDataCollectionException.o
# 	g++ -Wall -o td Event.o PriorityQueue.h Queue.o EmptyDataCollectionException.o

# Event.o: Event.cpp Event.h
# 	g++ -Wall -c Event.cpp

# EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
# 	g++ -Wall -c EmptyDataCollectionException.cpp

# PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
# 	g++ -Wall -c PriorityQueue.cpp

# Queue.o: Queue.cpp Queue.h
# 	g++ -Wall -c Queue.cpp

# clean:
# 	rm -f td *.o



all: td

td: EmptyDataCollectionException.o testDriver.o BinaryHeap.h PriorityQueue.h Queue.h
	g++ -Wall -o td testDriver.o EmptyDataCollectionException.o

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -Wall -c BinaryHeap.cpp

testDriver.o: SimulationApp.cpp PriorityQueue.h
	g++ -Wall -c SimulationApp.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o