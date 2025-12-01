#pragma once

//template node structure definition 
template <typename T>
struct TreeNode {
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    
    // 构造函数
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

