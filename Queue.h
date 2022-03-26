/*
 * Queue.h
 *
 * Class Description: Models a Queue
 * Class Invariant: - First in first out
 *                  - no access beyond the front of the queue
 *                  - only add new element to the back
 * Last Modified: June 2017
 * Author: Brendin Green
 */

#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

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

// Basic Constructor for Queue
template <class ElementType>
Queue<ElementType>::Queue(){
    elementCount = 0;
    head = NULL;
    tail = NULL;
}

// Basic Destructor for Queue
template <class ElementType>
Queue<ElementType>::~Queue(){
    for (int i = 0; i < getElementCount(); i++){
        dequeue();
    }
}

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int Queue<ElementType>::getElementCount() const {
    return this->elementCount;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return this->elementCount == 0;
}

// Description: Adds newElement to the "back" of this Queue
//              (not necessarily the "back" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement){

    Node<ElementType>* newNode = new Node<ElementType>(newElement);
    if (isEmpty()){
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail-> next = newNode;
        this->tail = this->tail->next;
    }
    elementCount++;
    return true;
}

// Description: Removes the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::dequeue(){
    if (isEmpty())
        return false;

    Node<ElementType>* toBeRemoved;
    if (getElementCount() == 1) {
        toBeRemoved = this->head;
        this->head = NULL;
        this->tail = NULL;
    } else {
        toBeRemoved = this->head;
        this->head = this->head->next;
    }

    delete toBeRemoved;
    toBeRemoved = NULL;
    elementCount--;
    return true;
}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType Queue<ElementType>::peek() const {
    if (isEmpty()){
        throw EmptyDataCollectionException("Queue is empty");
    } else {
        return head->data;
    }
}

// Description: Prints all elements of the queue for testing purposes.
// Postcondition: This Queue is unchanged.
// Time Efficiency: O(n)
template <class ElementType>
void Queue<ElementType>::printAll() const {
    Node<ElementType>* current = head;
    while (current != NULL){
        cout << current->data << endl;
        current = current->next;
    }
}


