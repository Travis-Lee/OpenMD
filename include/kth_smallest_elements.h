/*
#####################################################################
#        3                 5                15                      
#      /   \             /   \            /    \
#     1     4           3     6          9      18
#      \              /   \            /   \
#       2            2     4         3        7
#                   /              /  
#                  1              1     
#
#
# Input: root = [3,1,4,null,2], k = 1
# Output: 1
#
# Input: root = [5,3,6,2,4,null,null,1], k = 3
# Output: 3
#
# Input: root = [15,9,18,3,7,null,null,1], k = 3
# Output: 7
#
#
# solution：
#
# 目标： 对二叉搜索树（BST）中的所有值进行排序。
# The Goal：
# The whole point of the problem is to sort all numbers(the value) that are hidden inside the Binary Search Tree(BST).
# 
# 方向： 排序的方向是 从小到大（升序）。
# The Direction:
# We're sorting them from the smallest to the biggest (in ascending order)
#
# 结果： 找到排序后的队伍中，索引为 k 的那个值。
# The Result:
# Once they're sorted, we just need to grab the number that is standing in the k-th spot in that line. 
#
# 🔑 核心结论
#  The Key Takeway
#
#  目标就是找到排序后的第 k 个值。
#  排序的方向是 从小到大。
#  So, the goal is definitely to find the sorted k-th value. The sorting is always smallest to biggest.  
#  
#  BST 的厉害之处在于，它让计算机不需要用传统的排序算法（如快速排序）来做这件事。它只需要使用一个叫中序遍历的特殊技巧，就可以在数到 k 的时候停止，从而高效地找到答案！
#
#  The cool thing about the BST is that it's a cheat code for your computer. You don't have to actually use slow sorting methods like Quick Sort! You just use a special trick called Inorder Traversal(which means you're just following the path from smallest to largest), and the moment you count k items, you stop! This makes finding the answer super-fast. 
#
#####################################################################
*/

#pragma once
#include "../common/tree_node.h"
#include <vector>
#include <stack>
#include <type_traits>
#include <iostream>
#include <algorithm>

template <typename T, bool IsNumeric>
struct DefaultValueHelper {
    static T get() { return T{}; } // return default constructed value
};


template <typename T>
struct DefaultValueHelper<T, true> {
    static T get() { return T(-1); } // return -1
};


template <typename T>

class BSTKth{

public:
    /**
     *@brief Use iterative middle-order traversal to find the kth small value in BST.
     */
    T kthSmallest(TreeNode<T>* root, int k); 

    /**
     *@brief Build BST according to the array (for testing only). 
     */
    TreeNode<T>* buildBTS(const std::vector<T>& data);

    /**
     *@brief Release the mem of the tree
     */
    void deleteTree(TreeNode<T>* root);

private:
    //If the kth smallest element cannot be found, return the default value.
    T getDefaultValue();

};













