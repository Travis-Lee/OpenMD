#include "invert_binary_tree.h"

template<typename T>
TreeNode<T>* InvertBinaryTree<T>::invertRecursive(){
    return invertRecursiveHelper(root);
    return root;
}
template<typename T>
TreeNode<T>* InvertBinaryTree<T>::invertRecursiveHelper(TreeNode<T>* node){
    if(node == nullptr){
        return nullptr;
    }
    //Recursively invert left and right subtrees
    TreeNode<T>* left_inverted = invertRecursiveHelper(node->left);
    TreeNode<T>* right_inverted = invertRecursiveHelper(node->right);       

    //Swap left and right children
    node->left = right_inverted;
    node->right = left_inverted;
    return node;
}

template<typename T>
TreeNode<T>* InvertBinaryTree<T>::invertIterative(){
    if(root == nullptr){
        return nullptr;
    }

    std::queue<TreeNode<T>*> node_queue;
    node_queue.push(root);

    while(!node_queue.empty()){
        TreeNode<T>* current = node_queue.front();
        node_queue.pop();

        //Swap left and right children
        std::swap(current->left, current->right);

        //Enqueue non-null children
        if(current->left != nullptr){
            node_queue.push(current->left);
        }
        if(current->right != nullptr){
            node_queue.push(current->right);
        }
    }
    return root;
}

template class InvertBinaryTree<int>;
