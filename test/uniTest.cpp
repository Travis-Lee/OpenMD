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


int test_queue_with_two_stacks_2() {

    QueueWithTwoStacks<int> q;

    // 入队
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "=======>Pop: " << q.pop() << std::endl; // 1
    std::cout << "========>Pop: " << q.pop() << std::endl; // 2

    // 再入队
    q.push(4);
    std::cout<<"111111"<<std::endl;
    std::cout << "Pop: " << q.pop() << std::endl; // 3
    std::cout<<"22222"<<std::endl;
    std::cout << "Pop: " << q.pop() << std::endl; // 4

    // 队列是否为空
    if (q.empty()) std::cout << "Queue is empty" << std::endl;


    return 0;
}
