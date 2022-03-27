/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Daehyung Kwak and John Mavrick Reyes
 * Date: March 26, 2022
 */
  
#pragma once
#include "EmptyDataCollectionException.h"
#include <iostream>
using namespace std;

template <class ElementType>
class Queue {
	
    private:
        static unsigned const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        ElementType* elements;             // To do: replace this by int * elements -> Question 4.a)

        unsigned elementCount;                      // Number of elements in the Queue
        unsigned capacity;                          // Actual capacity of the data structure (number of cells in the array)
        unsigned frontindex;                        // Index the topmost element
        unsigned backindex;                         // Index where the next element will be placed               

        // Description: Resize the array
        bool resize(const int size);

        // Description: Remove the non-usable element
        // bool clean();

    public:
        // Description:  Constructor
        Queue();


        // Description: Destructor
        ~Queue();


        // Description:  Inserts element x at the back (O(1))
        void enqueue(const ElementType& x);


        // Description:  Removes the frontmost element (O(1))
        // Precondition:  Queue not empty
        void dequeue();


        // Description:  Returns a copy of the frontmost element (O(1))
        // Precondition:  Queue not empty
        ElementType& peek() const;


        // Description:  Returns true if and only if queue empty (O(1))
        bool isEmpty() const;
};


#include "Queue.cpp"