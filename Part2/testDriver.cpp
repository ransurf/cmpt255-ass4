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

    assert(!pq2.isEmpty());
    assert(pq2.peekPriority() == 1);
    pq2.dequeue();
    assert(pq2.peekPriority() == 2);
    pq2.dequeue();
    assert(pq2.peekPriority() == 3);

    cout << "Passed" << endl;
}

int main() {
    test_priorityQueue();
    return 0;
}