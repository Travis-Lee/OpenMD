#include "merge_two_sorted_lists.h"
#include <algorithm>

template<typename T>
ListNode<T>* MergeTwoSortedLists<T>::mergeTwoLists(ListNode<T>* list1, ListNode<T>* list2) {
    // Create a dummy node to simplify edge cases
    ListNode<T>* dummy = new ListNode<T>(0);
    ListNode<T>* tail = dummy;   
    
    // Main comparison loop
    while (list1 != nullptr && list2 != nullptr) {  
        if (list1->val <= list2->val) {
            tail->next = list1;  // Link the smaller node to the merged list
            list1 = list1->next; // Move to the next node in list1
        } else {
            tail->next = list2;  // Link the smaller node to the merged list
            list2 = list2->next; // Move to the next node in list2
        }
        tail = tail->next; // Advance the tail pointer
    }
    
    // Attach the remaining nodes, only one list can be non-null at this point
    // Attach the rest of the non-empty list to the tail
    if(list1 != nullptr) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    ListNode<T>* result = dummy->next;
    delete dummy;  // Free the dummy node
    return result;  // Return the head of the merged list       
}

template class MergeTwoSortedLists<int>;
