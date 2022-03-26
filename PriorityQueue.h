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
class PriorityQueue {

private:

    static const int MAX_ELEMENTS = 100;
    ElementType elements[PriorityQueue::MAX_ELEMENTS];
    int elementCount;
    int capacity;

public:

    // Let's put our constructor(s) and destructor (if any) ***here***.

    // Default Constructor
    PriorityQueue();

/******* Public Interface - START - *******/

    // Description: Returns the number of elements in the Priority Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const ElementType& newElement);

    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const;

    // Description: Prints all elements of the PriorityQueue for testing purposes.
    // Postcondition: This PriorityQueue is unchanged.
    // Time Efficiency: O(n)
    void printAll() const;

/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Priority Queue class.

}; // end PriorityQueue

// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(): elementCount(0), capacity(PriorityQueue::MAX_ELEMENTS){}

// Description: Returns the number of elements in the Priority Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return getElementCount() == 0;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement){
    if (getElementCount() < capacity) {

        for (int i = 0; i < getElementCount(); i++) {
            if (elements[i] < newElement){
                // Insert before ith element
                for (int j = getElementCount(); j > i; j--){
                    elements[j] = elements[j-1];
                }
                elements[i] = newElement;

                elementCount++;
                return true;
            }
        }
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
bool PriorityQueue<ElementType>::dequeue(){
    if (isEmpty()) {
        return false;
    }
    elementCount--;
    return true;
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const {
    if (isEmpty()){
        throw EmptyDataCollectionException("Priority Queue is empty");
    }
    return elements[getElementCount()-1];
}

// Description: Prints all elements of the PriorityQueue for testing purposes.
// Postcondition: This PriorityQueue is unchanged.
// Time Efficiency: O(n)
template <class ElementType>
void PriorityQueue<ElementType>::printAll() const {
    for (int i = 0; i < getElementCount(); i++){
        cout << elements[i] << endl;
    }
}

