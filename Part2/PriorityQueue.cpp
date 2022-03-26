#include "PriorityQueue.h"

// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() : elementCount(0), capacity(MAX_ELEMENTS) {}

// Default Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {

}

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
        elements.insert(newElement);
        this->elementCount++;
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
    elements.remove();
    elementCount--;
}

// Description: Returns (but does not remove) the element with the next
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const {
    if (isEmpty())
    {
        throw EmptyDataCollectionException("PriorityQueue::peek() called on empty PriorityQueue");
    }
    return elements.retrieve();
}
