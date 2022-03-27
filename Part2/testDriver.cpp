#include "PriorityQueue.h"
#include <iostream>
#include <assert.h>
using namespace std;

void test_priorityQueue() {
    cout << "Testing PriorityQueue() ..." << endl;
    // Test 1
    cout << "Test 1: ";
    PriorityQueue<int> pq = PriorityQueue<int>();
    assert(pq.isEmpty());
    cout << "Passed" << endl;

    // Test 2
    cout << "Test 2: ";

    PriorityQueue<int> pq2 = PriorityQueue<int>();
    pq2.enqueue(1);
    pq2.enqueue(2);
    pq2.enqueue(3);

    // cout << pq2.isEmpty() << endl;
    // assert(!pq2.isEmpty());
    assert(pq2.peek() == 1);
    pq2.dequeue();
    assert(pq2.peek() == 2);
    pq2.dequeue();
    assert(pq2.peek() == 3);

    cout << "Passed" << endl;

    // Test 3
    cout << "Test 3: ";
    PriorityQueue<int> pq3 = PriorityQueue<int>();
    pq3.enqueue(1);
    pq3.enqueue(2);
    pq3.enqueue(3);
    pq3.dequeue();
    pq3.dequeue();
    pq3.dequeue();
    assert(pq3.isEmpty());
    cout << "Passed" << endl;

    // Test 4
    cout << "Test 4: ";
    PriorityQueue<int> pq4 = PriorityQueue<int>();
    pq4.enqueue(1);
    pq4.enqueue(2);
    pq4.enqueue(3);
    pq4.dequeue();
    pq4.dequeue();
    pq4.dequeue();
    pq4.enqueue(4);
    assert(pq4.peek() == 4);
    cout << "Passed" << endl;

    // Test 5, random insertions and deletions
    cout << "Test 5: ";
    PriorityQueue<int> pq5 = PriorityQueue<int>();
    pq5.enqueue(1);
    pq5.enqueue(3);
    pq5.enqueue(2);
    pq5.enqueue(7);
    pq5.enqueue(5);
    pq5.enqueue(10);
    pq5.enqueue(4);
    pq5.enqueue(9);
    pq5.enqueue(6);
    pq5.enqueue(8);
    pq5.enqueue(11);
     
    //dequeue and assert
    assert(pq5.peek() == 1);
    pq5.dequeue();
    assert(pq5.peek() == 2);
    pq5.dequeue();
    assert(pq5.peek() == 3);
    pq5.dequeue();
    assert(pq5.peek() == 4);
    pq5.dequeue();
    assert(pq5.peek() == 5);
    pq5.dequeue();
    assert(pq5.peek() == 6);
    pq5.dequeue();
    assert(pq5.peek() == 7);
    pq5.dequeue();
    assert(pq5.peek() == 8);
    pq5.dequeue();
    assert(pq5.peek() == 9);
    pq5.dequeue();
    assert(pq5.peek() == 10);
    pq5.dequeue();
    assert(pq5.peek() == 11);
    pq5.dequeue();
    assert(pq5.isEmpty());
    cout << "Passed" << endl;
}

int main() {
    test_priorityQueue();
    return 0;
}

