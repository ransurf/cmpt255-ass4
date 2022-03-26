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

using namespace std;

template <class ElementType>
class PriorityQueue
{

private:
    static const int MAX_ELEMENTS = 100;
    ElementType elements[MAX_ELEMENTS];
    int elementCount;
    int capacity;

public:
    // Let's put our constructor(s) and destructor (if any) ***here***.

    // Default Constructor
    PriorityQueue();

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
    ElementType &peek() const;

    /******* Public Interface - END - *******/

    // Let's feel free to add other private helper methods to our Priority Queue class.

}; // end PriorityQueue

// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() : elementCount(0), capacity(PriorityQueue::MAX_ELEMENTS) {}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType &newElement) {
    // If elementCount is less than capacity, then we can add the element
    if (elementCount < capacity)
    {

        // Loop through the elements to find the correct position to insert
        for (int i = 0; i < elementCount; i++)
        {
            if (elements[i] > newElement)
            {
                // Insert before ith element
                for (int j = elementCount; j > i; j--)
                {
                    elements[j] = elements[j - 1];
                }
                elements[i] = newElement;

                elementCount++;
                return true;
            }
            // Do not allow duplicate elements
            else if (elements[i] == newElement)
            {
                return false;
            }
        }
        // If element at i th is less than newElement
        elements[elementCount] = newElement;
        elementCount++;
        return true;
    }
    return false;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue() {
    if (isEmpty())
    {
        throw EmptyDataCollectionException("PriorityQueue::dequeue() called on empty PriorityQueue");
    }
    elementCount--;
}

// Description: Returns (but does not remove) the element with the next
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &PriorityQueue<ElementType>::peek() const {
    if (isEmpty())
    {
        throw EmptyDataCollectionException("PriorityQueue::peek() called on empty PriorityQueue");
    }
    return elements[elementCount - 1];
}
