#include "queue_with_two_stacks.h"

template<typename T>
void QueueWithTwoStacks<T>::enqueue(const T& value) {
    inStack.push(value);
}

template<typename T>
T QueueWithTwoStacks<T>::dequeue() {
    if (outStack.empty()) {
        transfer();
    }
    if (outStack.empty()) {
        throw std::out_of_range("Queue is empty");
    }
    T value = outStack.top();
    outStack.pop();
    return value;
}

template<typename T>
T QueueWithTwoStacks<T>::front() {
    if (outStack.empty()) {
        transfer();
    }
    if (outStack.empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return outStack.top();
}

template<typename T>
bool QueueWithTwoStacks<T>::empty() const {
    return inStack.empty() && outStack.empty();
}

template<typename T>
size_t QueueWithTwoStacks<T>::size() const {
    return inStack.size() + outStack.size();
}

template<typename T>
void QueueWithTwoStacks<T>::transfer() {
    while (!inStack.empty()) {
        outStack.push(inStack.top());
        inStack.pop();
    }
}

// 显式实例化模板
template class QueueWithTwoStacks<int>;
