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

int test_power() {
    // 使用 Power<double>
    Power<double> p;

    double base1 = 2.0;
    int exp1 = 10;

    double result1 = p.power(base1, exp1);
    std::cout << base1 << "^" << exp1 << " = " << result1 << std::endl;

    // 测试负指数
    double base2 = 2.0;
    int exp2 = -3;

    double result2 = p.power(base2, exp2);
    std::cout << base2 << "^" << exp2 << " = " << result2 << std::endl;

    // 测试 0 的负指数，检查 g_InvalidInput
    double base3 = 0.0;
    int exp3 = -1;

    double result3 = p.power(base3, exp3);
    if (p.isInvalid()) {
        std::cout << "Invalid input: 0 cannot be raised to negative power." << std::endl;
    } else {
        std::cout << base3 << "^" << exp3 << " = " << result3 << std::endl;
    }

    return 0;
}

int test_ransom_note(){
    RansomNote<char> rn;

    std::cout<<"1111"<<std::endl;
    std::string ransomNote1 = "a";
    std::string magazine1 = "b";
    std::cout << std::boolalpha << rn.canConstruct(ransomNote1, magazine1) << std::endl; // false

    std::cout<<"2222"<<std::endl;
    std::string ransomNote2 = "aa";
    std::string magazine2 = "ab";
    std::cout << std::boolalpha << rn.canConstruct(ransomNote2, magazine2) << std::endl; // false

    std::cout<<"3333"<<std::endl;
    std::string ransomNote3 = "aa";
    std::string magazine3 = "aab";
    std::cout << std::boolalpha << rn.canConstruct(ransomNote3, magazine3) << std::endl; // true

    return 0;
}

int test_interval_inserter(){
    
    IntervalInserter<int> inserter;
    
    std::vector<Interval<int>> intervals = {
        Interval<int>(1,2),
        Interval<int>(3,5),
        Interval<int>(6,7),
        Interval<int>(8,10),
        Interval<int>(12,16)
    };

    Interval<int> newInterval(4,9);

    std::vector<Interval<int>> result = inserter.insert(intervals, newInterval);

    std::cout << "Merged Intervals: ";
    for (const auto& i : result) {
        std::cout << "[ " << i.start << ", " << i.end << "] ";
    }
    std::cout << std::endl;

    return 0;

}


