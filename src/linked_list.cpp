#pragma once
#include "linked_list.h"


/*
循环过程形象化
假设链表是这样：
head -> [10] -> [20] -> [30] -> nullptr
拆的过程：
cur 指向 [10]，tmp 保存 [10]，cur 移动到 [20]，删除 [10]
cur 指向 [20]，tmp 保存 [20]，cur 移动到 [30]，删除 [20]
cur 指向 [30]，tmp 保存 [30]，cur 移动到 nullptr，删除 [30]
cur 为空，循环结束，链表完全释放
总结一句话
析构函数就是 一个一个拆掉链表的车厢，把占用的内存清理掉，防止“火车车厢”堆在内存里造成浪费。
*/
// 析构函数：释放链表
template<typename T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* cur = head;
    while (cur) {
        ListNode<T>* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

/*
总结成一句话
造一个新车厢（节点）。
如果火车空，把它当火车头。
如果火车不空，找到最后一个车厢。
把新车厢挂到火车尾巴上。
*/
// push_back
template<typename T>
void LinkedList<T>::push_back(const T& value) {
    ListNode<T>* node = new ListNode<T>(value);
    if (!head) {
        head = node;
        return;
    }
    ListNode<T>* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

// print
template<typename T>
void LinkedList<T>::print() const {
    ListNode<T>* cur = head;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

// reverse
template<typename T>
void LinkedList<T>::reverse() {
    ListNode<T>* prev = nullptr;
    ListNode<T>* cur = head;
    while (cur) {
        ListNode<T>* next_node = cur->next;
   //        std::cout<<"next_node:"<<next_node->val<<" cur->next:"<<cur->next->val<<std::endl;
        cur->next = prev;
        //std::cout<<"cur->next:"<<cur->next->val<<" prev:"<<prev->val<<std::endl;
        prev = cur;
        //std::cout<<"prev:"<<prev->val<<" cur:"<<cur->val<<std::endl;
        cur = next_node;
        //std::cout<<"cur:"<<cur->val<<" next_node:"<<next_node->val<<std::endl;
    }
    head = prev;
    //std::cout<<"head:"<<head->val<<" prev:"<<prev->val<<std::endl;
}


template<typename T>
void LinkedList<T>::delete_node(ListNode<T>* pToBeDeleted) {
    if (!head || !pToBeDeleted) return;

    // 删除的不是尾节点
    if (pToBeDeleted->next != nullptr) {
        ListNode<T>* pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;
        delete pNext;
    }
    // 删除的是唯一节点（头也是尾）
    else if (head == pToBeDeleted) {
        delete pToBeDeleted;
        head = nullptr;
    }
    // 删除尾节点
    else {
        ListNode<T>* pNode = head;
        while (pNode && pNode->next != pToBeDeleted) {
            pNode = pNode->next;
        }
        if (pNode) { // 找到前驱节点
            pNode->next = nullptr;
            delete pToBeDeleted;
        }
    }
}

// delete duplication
template<typename T>
void LinkedList<T>::delete_duplication() {

    if(head==nullptr){
        return; 
    }
    ListNode<T>* prev = nullptr;
    ListNode<T>* cur = head;

    while(cur!=nullptr){
        ListNode<T>* next = cur->next;

        bool needDelete = false;
        
        if(next!=nullptr && next->val==cur->val){
            needDelete = true;
        }
        if(!needDelete){
            prev=cur;
            cur=cur->next;
        }
        else{
            T value = cur->val;
            ListNode<T>* toBeDel=cur;
            
             while (toBeDel != nullptr && toBeDel->val == value)
            {
                next = toBeDel->next;
                delete toBeDel;
                toBeDel = next;
            }

            if (prev == nullptr)
                head = next;
            else
                prev->next = next;

            cur = next;
        }

    }

}

// print_list_reversingly helper
template<typename T>
void print_reversingly_helper(ListNode<T>* node) {
    if(!node) return;
    print_reversingly_helper(node->next);
    std::cout << "=========>"<<node->val << " ";
}


template<typename T>
void LinkedList<T>::print_list_reversingly(){
    if(head !=nullptr){
        if(head->next !=nullptr){
             print_reversingly_helper(head);
        }
        std::cout <<"value:"<<head->val<<std::endl;            
    }
}


// 显式实例化模板
template class LinkedList<int>;
