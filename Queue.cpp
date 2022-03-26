// /* 
//  * Queue.cpp
//  *
//  * Description: Implementation of an int sequence with enqueue/dequeue ...
//  * Class Invariant: ... in FIFO order
//  *
//  * Author:
//  * Date:
//  */
 
// #include "Queue.h"


// // Description:  Constructor
// template <class ElementType>
// Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
// } 

// template <class ElementType>
// Queue<ElementType>::~Queue() {
//     if(this->capacity > 0) {
//         delete [] this->elements;
//     }
// }

// template <class ElementType>
// bool Queue<ElementType>::resize(const int size) {
//     // If (backindex - frontindex) is more than the given size OR elementCount less than the Initial Capacity
//     // Do not allow resize
//     if(size < this->backindex - this->frontindex || size < this->INITIAL_CAPACITY) {
//         return false;
//     }

//     // Create new array of given size
//     int* newArr = new ElementType[size];

//     // Copy the oldArr elements to the new array
//     for(int i = this->frontindex; i < this->backindex; i++) {
//         newArr[i - this->frontindex] = this->elements[i];
//     }

//     // Change capacity
//     this->capacity = size;
//     this->backindex = this->elementCount;

//     // Reset frontindex
//     this->frontindex = 0;

//     // Replace old Arr with new Arr
//     int* oldArr = this->elements;
//     this->elements = newArr;
//     delete [] oldArr;

//     return true;
// }

// // Description:  Inserts element x at the back (O(1))
// template <class ElementType>
// void Queue<ElementType>::enqueue(const ElementType& x) {
//     // If elementCount 0, initialize
//     if(this->elementCount == 0)
//     {
//         this->elements = new ElementType[this->INITIAL_CAPACITY];
//         this->capacity = this->INITIAL_CAPACITY;
//     }
//     // If capacity and elementCount size is the same, increase capacity * 2
//     else if(this->capacity <= this->backindex + 1) {
//         resize(this->capacity * 2);
//     }

//     elementCount++;
//     elements[backindex] = x;
//     backindex = (backindex + 1) % capacity;
// } 


// // Description:  Removes the frontmost element (O(1))
// // Precondition:  Queue not empty
// template <class ElementType>
// void Queue<ElementType>::dequeue() {
//     // If elementCount < 0.25 Array Capacity AND 1/2 * Array Capacity >  Initial Capacity , half the resize.
//     bool cond1 = (double)this->elementCount < (double)(0.25 * this->capacity);
//     bool cond2 = ((int)(0.5 * this->capacity) > this->INITIAL_CAPACITY);
//     if(cond1 && cond2) {
//         resize(this->capacity * 0.5);
//     }

//     this->elementCount--;
//     frontindex = (frontindex + 1) % capacity;
// } 


// // Description:  Returns a copy of the frontmost element (O(1))
// // Precondition:  Queue not empty
// template <class ElementType>
// ElementType& Queue<ElementType>::peek() const {
//     return elements[frontindex];
// } 


// // Description:  Returns true if and only if queue empty (O(1))
// template <class ElementType>
// bool Queue<ElementType>::isEmpty() const {
//     return elementCount == 0;
// }
