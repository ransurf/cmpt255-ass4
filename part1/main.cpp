#include "Queue.h"
#include <string>
#include <assert.h>
using namespace std;

void queueTest1() {
    Queue<string>* q = new Queue<string>();
    assert(q->isEmpty());
    delete q;
}

void queueTest2() {
    Queue<string>* q = new Queue<string>();
    q->enqueue("a");
    assert(!q->isEmpty());
    delete q;
}

int main(int argc, char *argv[]) {
    queueTest1();
    queueTest2();
    // Queue<string>* q = new Queue<string>();
    return 0;
}