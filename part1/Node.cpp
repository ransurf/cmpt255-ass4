#include "Node.h"

// Default COnstructor
// Post Condition: Data not set, next set to NULL
template <class ElementType>
Node<ElementType>::Node()
{
    this->next = NULL;
}

// Parametrized Constructor
// Post Condition: Data set from argument, next set to NULL
template <class ElementType>
Node<ElementType>::Node(const ElementType& element)
{
    this->data = element;
    this->next = NULL;
}