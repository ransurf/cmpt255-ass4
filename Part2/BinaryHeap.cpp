/* 
 * BinaryHeap.cpp
 *
 * NOTE: You can replace/modify the code in the body of the methods fond in this file.
 *       If you decide to keep the code, make sure it works as expected.
 *
 * To do: fill in the two blank spaces below
 * Blank space 1: The choices are "minimum" or "maximum" 
 *                   (Todo: fill in the other blank spaces below.)
 * Blank space 2: Refer to our lecture notes for the data structure used as CDT.
 * Description: min Binary Heap data collection ADT class. 
 *              array implementation.
 *
 * Class Invariant:  Always a min Binary Heap
 * 
 * Author: Daehyung Kwak and John Mavrick Reyes
 *
 * Last Modification: March 26 2022
 *
 */  

#include "BinaryHeap.h"  // Header file
#include <math.h> 
  
// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {
   elementCount = 0;
   
} // end of default constructor

	
// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
   return elementCount;
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a min Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(const ElementType& newElement) {

    bool ableToInsert = true;
	if(100 > elementCount) {
		elements[elementCount] = newElement;
		elementCount++;
		reHeapUp(elementCount-1);
	}
	
    return ableToInsert;

} // end insert


// Utility method - Recursively put the array back into a min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {

	if(indexOfBottom > 0) {
		int indexOfParent = floor((indexOfBottom - 1) / 2);
		if(elements[indexOfBottom] <= elements[indexOfParent])
		{
			//Swap
			ElementType temp = elements[indexOfParent];
			elements[indexOfParent] = elements[indexOfBottom];
			elements[indexOfBottom] = temp;
			reHeapUp(indexOfParent);
		}
	}

	return;
	
} // end reHeapUp


// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a min Binary Heap after the removal.	
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {
	if ( elementCount == 0 )
    	throw(EmptyDataCollectionException("remove() called with an empty BinaryHeap.")); 
   
	elementCount--;
	elements[0] = elements[elementCount];
	reHeapDown(0);

	return;
}  // end remove


// Utility method - Recursively put the array back into a min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

	unsigned int indexOfMinChild = indexOfRoot;
	
	// Find indices of children.
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;

	// If we need to swap, select the smallest child
    if (elements[indexOfRoot] > elements[indexOfLeftChild])
    	indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount) {
		if (elements[indexOfMinChild] > elements[indexOfRightChild])
		    indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot) {
		
	   ElementType temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapDown(indexOfMinChild);
    }

	return;
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType BinaryHeap<ElementType>::retrieve() const {
   
   // Enforce precondition
   if ( elementCount > 0 )
      return elements[0];
   else
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 

}  // end retrieve


// For Testing Purposes
// Description: Prints the content of "rhs".
template <class ElementType>
ostream& operator<<(ostream & os, const BinaryHeap<ElementType>& rhs) {
	
	for ( unsigned int index = 0; index < rhs.elementCount; index++ )
		os << rhs.elements[index]; // Print data

	return os;
} // end of operator <<


//  End of implementation file.