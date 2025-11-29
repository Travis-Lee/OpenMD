#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <iostream>
#include <cassert>
#include "../common/list_node.h"

/*
template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T v) : val(v), next(nullptr) {}
};
*/

template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList();

    // 添加节点到尾部
    void push_back(const T& value);

    // 输出链表
    void print() const;

    // 反转链表
    void reverse();

    // delete node
    void delete_node(ListNode<T>* pToBeDeleted);
    
    // delete duplication
    void delete_duplication();

    // print list from end to begain
    void print_list_reversingly();
    
    // 获取头指针
    ListNode<T>* get_head() const { return head; }

private:
    ListNode<T>* head;
};

// include 模板实现
//#include "linked_list.tpp"

#endif

