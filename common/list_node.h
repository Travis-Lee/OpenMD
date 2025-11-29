#pragma once

template <typename T>
struct ListNode {
    T val;
    ListNode<T>* next;
    ListNode(T x) : val(x), next(nullptr) {}
};

