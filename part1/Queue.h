#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"
#include <cstddef>
using namespace std;

template <class ElementType>
class Queue {

private:

    int elementCount;
    Node<ElementType>* head;
    Node<ElementType>* tail;

public:

    // Let's put our constructor(s) and destructor (if any) ***here***.

    // Default Constructor
    Queue();
    // Default Destructor
    ~Queue();

/******* Public Interface - START - *******/

    // Description: Returns the number of elements in the Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Adds newElement to the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const ElementType& newElement);

    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns (a copy of) the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const;

    // Description: Prints all elements of the queue for testing purposes.
    // Postcondition: This Queue is unchanged.
    // Time Efficiency: O(n)
    void printAll() const;

/******* Public Interface - END - *******/

};

#include "Queue.cpp"