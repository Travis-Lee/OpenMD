#include "uniTest.h"
#include <iostream>

int test_queue_with_two_stacks() {
    QueueWithTwoStacks<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front: " << q.front() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 2

    q.enqueue(4);
    std::cout << "Front: " << q.front() << "\n"; // 3
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 3
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 4

    if (q.empty()) std::cout << "Queue is empty\n";

    return 0;
}


