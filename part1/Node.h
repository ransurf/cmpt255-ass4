#pragma once

#include <cstddef>

template <class ElementType>
class Node {

public:
    ElementType data;
    Node<ElementType>* next;

    // Default Constructor
    Node();
    // Constructor with data parameter
    Node(const ElementType& theData);
};

#include "Node.cpp"