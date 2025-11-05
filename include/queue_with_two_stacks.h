#ifndef QUEUE_WITH_TWO_STACKS_HPP
#define QUEUE_WITH_TWO_STACKS_HPP

#include <stack>
#include <stdexcept>

template<typename T>
class QueueWithTwoStacks {
public:
    QueueWithTwoStacks() = default;

    // 入队
    void enqueue(const T& value);

    // 出队
    T dequeue();

    // 查看队首元素
    T front();

    // 是否为空
    bool empty() const;

    // 队列大小
    size_t size() const;

private:
    std::stack<T> inStack;   // 入栈
    std::stack<T> outStack;  // 出栈

    // 将 inStack 的元素倒入 outStack
    void transfer();
};

#endif // QUEUE_WITH_TWO_STACKS_HPP

