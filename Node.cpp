/*
 * Node.h
 *
 * Class Description: Models a Node of a link-list like data structure
 * Class Invariant: - next is either a pointer to another node or NULL
 * Last Modified: March 2022
 * Author: Daehyung Kwak
 */

#include <cstdio>  // Needed for NULL
#include "Node.h"

template <class ElementType>
Node<ElementType>::Node()
{
    next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
    data = theData;
    next = NULL;
}
