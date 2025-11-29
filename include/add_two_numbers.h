#pragma once
#include <vector>
#include "../common/list_node.h"

template <typename T>
class AddTwoNumbers {
public:
    ListNode<T>* addTwoNumbers(ListNode<T>* l1, ListNode<T>* l2);
    ListNode<T>* buildList(const std::vector<T>& nums);
    void printList(ListNode<T>* head);
};

// 声明模板实例（但不定义）
//extern template class AddTwoNumbers<int>;

