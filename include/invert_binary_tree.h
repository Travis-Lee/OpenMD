/**
 * @file invert_binary_tree.h
 * @author Travis-LEE 
 * @brief Invert Binary Tree Header File
 * “Invert Binary Tree” means flipping a binary tree into its mirror image.
 * 
 * More intuitively:
 * For every node in the tree, swap its left and right children.
 * After doing this for all nodes, the entire tree looks like a mirror reflection of the original.
 * 
 * Input：
 *       4
 *      / \
 *     2   7
 *    / \ / \
 *   1  3 6  9
 *
 * Output：
 *      4 
 *     / \
 *    7   2  
 *   / \ / \
 *  9  6 3  1
 * 
 * Each node swaps its left and right child.
 * The whole tree becomes a mirror image.
 * 
 * Algorithm Idea
 * The most common way to invert a binary tree is recursion.
 * Steps:
 * If the current node is null, return null.
 * Recursively invert the left and right subtrees.
 * Swap the left and right children of the current node.
 * Return the current node.
 **/
#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include "../common/tree_node.h"

template<typename T>
class InvertBinaryTree { 
public:
    // Constructor: initialize with a root pointer
    InvertBinaryTree(TreeNode<T>* root) : root(root) {}

    //Recursive inversion function
    TreeNode<T>* invertRecursive();

    //Iterative inversion function
    TreeNode<T>* invertIterative();

    TreeNode<T>* getRoot() const { return root; }

private:
    TreeNode<T>* root;

    //Recursive helper function
    TreeNode<T>* invertRecursiveHelper(TreeNode<T>* node);
};
