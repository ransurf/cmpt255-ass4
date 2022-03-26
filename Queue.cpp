#include "Queue.h"

using namespace std;


template <class ElementType>
Queue<ElementType>::Queue(){
    elementCount = 0;
    head = NULL;
    tail = NULL;
}

template <class ElementType>
Queue<ElementType>::~Queue(){
    for (int i = 0; i < getElementCount(); i++){
        dequeue();
    }
}

template <class ElementType>
int Queue<ElementType>::getElementCount() const {
    return this->elementCount;
}

template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return this->elementCount == 0;
}

template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement){

    Node<ElementType>* newNode = new Node<ElementType>(newElement);
    if (isEmpty()){
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    return true;
}

template <class ElementType>
bool Queue<ElementType>::dequeue(){
    if (isEmpty())
        return false;

    Node<ElementType>* toBeRemoved = this->head;
    this->head = this->head->next;
    if (getElementCount() == 1){
        this->tail = NULL;
    }

    delete toBeRemoved;
    toBeRemoved = NULL;
    elementCount--;
    return true;
}

template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException){
    if (isEmpty()){
        throw EmptyDataCollectionException("Queue is empty");
    } else {
        return head->data;
    }
}

