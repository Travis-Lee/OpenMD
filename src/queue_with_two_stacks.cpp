#include "queue_with_two_stacks.h"
#include <iostream>

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
    // 打印转移前 inStack
    std::stack<T> temp = inStack;  // 拷贝
    std::cout << "inStack before transfer (top -> bottom): ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // 开始 transfer
    while (!inStack.empty()) {
        outStack.push(inStack.top());
        inStack.pop();
    }

    // 打印转移后 outStack
    temp = outStack;  // 拷贝
    std::cout << "outStack after transfer (top -> bottom): ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }    
    std::cout<<std::endl;
}



template<typename T>
void QueueWithTwoStacks<T>::push(T node) {
    inStack.push(node);
}

template<typename T>
void QueueWithTwoStacks<T>::copy(std::stack<T> &a, std::stack<T> &b) {
    while(a.size()){
        b.push(a.top());
        a.pop();
    }
}

template<typename T>
T QueueWithTwoStacks<T>::pop(){

    copy(inStack,outStack);
    int res=outStack.top();
    outStack.pop();
    copy(outStack,inStack);
    
    return res;
}



// 显式实例化模板
template class QueueWithTwoStacks<int>;
