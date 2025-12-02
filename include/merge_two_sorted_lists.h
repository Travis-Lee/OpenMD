/**
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 * Input: list1 = [], list2 = []
 * Output: []
 * 
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 * Merge: The resulting new linked list must include all nodes for both list1 and list2
 *
 * Sort: The merged new list must still maintain an ordered state from smallest to largest value 
 * 
 * Preserve Duplicates: If both lists contain the same value(eg., list1 has a 1, and list2 also has a 1), both instances of the value will be retained in the new list. This is because we are moving nodes, not performing value de-duplication.
 *
 *
 **/
#pragma once
#include <iostream>
#include <string>
#include "../common/list_node.h"

/**
 * @brief Template class for merging two sorted linked lists.
 * The template parameter T is used for generic implementation structures.
 */
template<typename T>
class MergeTwoSortedLists {
public:
    /**
     * @brief Merges two sorted linked lists into a single sorted linked list.
     * @param list1 Pointer to the head of the first sorted linked list.
     * @param list2 Pointer to the head of the second sorted linked list.
     * @return ListNode<T>* Head of the merged sorted linked list.
     */
    ListNode<T>* mergeTwoLists(ListNode<T>* list1, ListNode<T>* list2);
};