#include "kth_smallest_elements.h"

template <typename T>

T BSTKth<T>::getDefaultValue(){
     // use std::is_integral<T>::value or std::is_floating_point<T>::value 来判断是否为数值类型
    constexpr bool IsNumeric = std::is_integral<T>::value || std::is_floating_point<T>::value;
    
    // Call the auxiliary structure to realize the logic of the original if constexpr
    return DefaultValueHelper<T, IsNumeric>::get();
    }

template <typename T>
T BSTKth<T>::kthSmallest(TreeNode<T>* root, int k){
    if(root == nullptr || k <= 0){
        return getDefaultValue();
    }   
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* current = root;
    int count = 0;

    while(current != nullptr || !s.empty()){
        // Go to the leftmost node
        while(current != nullptr){
            s.push(current);
            current = current->left;
        }
        // Get Current Minimum element
        current = s.top();
        s.pop();

        // count the nodes
        count++;

        // find the kth smallest element and stop
        if(count == k){
            return current->val;
        }

        // find the right next maximum element
        current = current->right;
    }
    return getDefaultValue(); // If k is larger than the number of nodes in the tree
}

template <typename T>
TreeNode<T>* BSTKth<T>::buildBTS(const std::vector<T>& data){
    if (data.empty()){
        return nullptr;
    }
    TreeNode<T>* root = new TreeNode<T>(data[0]);

    auto insert = [](TreeNode<T>* node, T val){
        TreeNode<T>* current = node;
        TreeNode<T>* parent = nullptr;

        while (current != nullptr){
            parent = current;
            // new value is less than current node's value, go left
            if (val < current->val){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        //new value is less than parent node's value, insert to the left
        if (val < parent->val){
            parent->left = new TreeNode<T>(val);
        }else{
            parent->right = new TreeNode<T>(val);
        }
    };
    // build the BST，Through the loop, put all the remaining data elements into 
    // the tree in turn according to the rules of left and right.
    for (size_t i = 1; i < data.size(); ++i){
        insert(root, data[i]);
    }

    return root;
}


template <typename T>
void BSTKth<T>::deleteTree(TreeNode<T>* root){
    if(root == nullptr){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

template class BSTKth<int>;
template class BSTKth<double>;
template class BSTKth<float>;













