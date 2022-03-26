#include "PriorityQueue.h"

using namespace std;

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(): elementCount(0), capacity(PriorityQueue::MAX_ELEMENTS){}

template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const {
    return elementCount;
}

template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return getElementCount() == 0;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement){
    if (getElementCount() < capacity) {

        for (int i = 0; i < getElementCount(); i++) {
            if (elements[i] > newElement){
                // Insert before ith element
                for (int j = getElementCount(); j > i; j--){
                    elements[j] = elements[j-1];
                }
                elements[i] = newElement;

                elementCount++;
                return true;
            } else if (elements[i] == newElement) {
                return false;
            }
        }
        elements[elementCount] = newElement;
        elementCount++;
        return true;
    }
    return false;
}

template <class ElementType>
bool PriorityQueue<ElementType>::dequeue(){
    if (isEmpty()) {
        return false;
    }

    for (int i = 0; i < getElementCount(); i++){
        elements[i-1] = elements[i];
    }
    elementCount--;
    return true;
}

template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const {
    if (isEmpty()){
        throw EmptyDataCollectionException("Priority Queue is empty");
    }
    return elements[0];
}

