/*
 * Node.h
 *
 * Class Description: Models a Node of a link-list like data structure
 * Class Invariant: - next is either a pointer to another node or NULL
 * Last Modified: March 2022
 * Author: Daehyung Kwak
 */

#pragma once

template <class ElementType>
class Node {

public:
    ElementType data;
    Node<ElementType>* next;

    // Default Constructor
    Node();
    // Constructor with data parameter
    Node(ElementType theData);
};

// Default COnstructor
// Post Condition: Data not set, next set to NULL
template <class ElementType>
Node<ElementType>::Node()
{
    next = NULL;
}

// Parametrized Constructor
// Post Condition: Data set from argument, next set to NULL
template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
    data = theData;
    next = NULL;
}


