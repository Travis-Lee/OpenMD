#include "../include/add_two_numbers.h"
#include <iostream>

template <typename T>
ListNode<T>* AddTwoNumbers<T>::buildList(const std::vector<T>& nums) {
    if (nums.empty()) return nullptr;

    ListNode<T>* head = new ListNode<T>(nums[0]);
    ListNode<T>* curr = head;

    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode<T>(nums[i]);
        curr = curr->next;
    }
    return head;
}

template <typename T>
void AddTwoNumbers<T>::printList(ListNode<T>* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

template <typename T>
ListNode<T>* AddTwoNumbers<T>::addTwoNumbers(ListNode<T>* l1, ListNode<T>* l2) {
    ListNode<T> dummy(0);
    ListNode<T>* curr = &dummy;

    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        curr->next = new ListNode<T>(sum % 10);
        curr = curr->next;
    }

    return dummy.next;
}

//
// ⭐⭐ 关键点：显式实例化模板，让 cpp 文件真正生成代码
//
template class AddTwoNumbers<int>;

