#include <iostream>
#include <assert.h>
#include "Queue.h"
using namespace std;

void test_queue() {
    cout << "Testing Queue() ..." << endl;
    // Test 1
    cout << "Test 1: ";
    Queue<int> q = Queue<int>();
    assert(q.isEmpty());
    cout << "Passed" << endl;

    // Test 2
    cout << "Test 2: ";

    Queue<int> q2 = Queue<int>();
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);

    assert(!q2.isEmpty());
    assert(q2.peek() == 1);
    q2.dequeue();
    assert(q2.peek() == 2);
    q2.dequeue();
    assert(q2.peek() == 3);

    cout << "Passed" << endl;

    // Test 3
    cout << "Test 3: ";
    Queue<int> q3 = Queue<int>();
    q3.enqueue(1);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.dequeue();
    q3.dequeue();
    q3.dequeue();
    assert(q3.isEmpty());
    cout << "Passed" << endl;

    // Test 4
    cout << "Test 4: ";
    Queue<int> q4 = Queue<int>();
    for(int i = 0; i < 10; i++) {
        q4.enqueue(i);
    }
    assert(q4.peek() == 0);
    
    for(int j = 0; j < 10; j++) {
        q4.dequeue();
    }
    try {
        q4.peek();
        assert(false);
    } catch(EmptyDataCollectionException e) {
        cout << "Passed" << endl;
    }

    cout << "Test Queue() Passed" << endl;
}

int main() {
    test_queue();
    return 0;
}