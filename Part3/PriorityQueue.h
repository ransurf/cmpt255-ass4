/*
 * PriorityQueue.h
 *
 * Class Description: Models a Priority Queue
 * Class Invariant: - First in first out
 *                  - Sorted by time and type
 *                  - no access beyond the front of the queue
 *                  - adds elements in sort order
 * Last Modified: March 2022
 * Author: Daehyung Kwak
 */

#pragma once

#include "EmptyDataCollectionException.h"
#include "BinaryHeap.h"

using namespace std;

template <class ElementType>
class PriorityQueue
{

private:
    static const int MAX_ELEMENTS = 100;
    BinaryHeap<ElementType> elements = BinaryHeap<ElementType>();
    int elementCount;
    int capacity;

public:
    // Let's put our constructor(s) and destructor (if any) ***here***.

    // Default Constructor
    PriorityQueue();

    // Default Destructor
    ~PriorityQueue();

    /******* Public Interface - START - *******/

    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const ElementType &newElement);

    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const;

    /******* Public Interface - END - *******/

    // Let's feel free to add other private helper methods to our Priority Queue class.

    // Description: Returns the elementCount of the Priority Queue
    int getElementCount() const;

}; // end PriorityQueue

#include "PriorityQueue.cpp"