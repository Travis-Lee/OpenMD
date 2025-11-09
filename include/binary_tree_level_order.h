#ifndef BINARY_TREE_LEVEL_ORDER_H
#define BINARY_TREE_LEVEL_ORDER_H

#include <vector>
#include <queue>

// 模板二叉树节点结构
template<typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    //这是 构造节点。意思：当我创建一个节点时，比如：TreeNode<int>* node = new TreeNode<int>(3)，他会自动变成val=？，left=null，right=null
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

// 模板层序遍历类
template<typename T>
class BinaryTreeLevelOrder {
public:
    //这里是为了按照树的深度打印每层的树的值
    std::vector<std::vector<T>> levelOrder(TreeNode<T>* root);
};

#endif // BINARY_TREE_LEVEL_ORDER_H

