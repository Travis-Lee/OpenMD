#ifndef BINARY_TREE_LEVEL_ORDER_H
#define BINARY_TREE_LEVEL_ORDER_H

#include <vector>
#include <queue>
#include "../common/tree_node.h"


// 模板层序遍历类
template<typename T>
class BinaryTreeLevelOrder {
public:
    //这里是为了按照树的深度打印每层的树的值
    std::vector<std::vector<T>> levelOrder(TreeNode<T>* root);
};

#endif // BINARY_TREE_LEVEL_ORDER_H

