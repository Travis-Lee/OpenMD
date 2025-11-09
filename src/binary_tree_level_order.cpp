#include "binary_tree_level_order.h"
#include <iostream>


template<typename T>
std::vector<std::vector<T>> BinaryTreeLevelOrder<T>::levelOrder(TreeNode<T>* root) {
    //创建一个二维数组 result 用来存放每一层的节点
    std::vector<std::vector<T>> result;
    //如果树是空的（根节点是 null），直接返回空结果
    if (root == nullptr) return result;

    //queue 队列，用来按层顺序处理节点
    std::queue<TreeNode<T>*> q;
    //先把根节点放进去
    q.push(root);

    int temp=0;
    //当队列不空时一直循环
    while (!q.empty()) {
        //当前队列里有多少个节点，这些就是 当前层的节点,其实就是看当前层有几个节点的
        int size = q.size();
        //创建 level 数组存当前层的值，目的就是为了存当前层的值，比如：只有一个3，那么level里最后就放一个3.
        std::vector<T> level;

        //遍历当前层的所有节点
        for (int i = 0; i < size; i++) {
            //取出队列的第一个节点 → node = q.front()比如：第二层【9，20】循环一次q.front()->9->node指向9，取值node->val=9，下面没有孩子-> 队列变化，循环第二次：q.front->20->node指向20，取值node->val=20 孩子15，17放入队列->下一层准备好
            TreeNode<T>* node = q.front();
            //队列删除这个节点 → q.pop()
            q.pop();
            //把值加入当前层数组 → level.push_back(node->val)，这里是把当层处理的层的值加入到level里，比如现在这层有9，20这里只存20.
            level.push_back(node->val);

            //当前层存入level之后要看这个节点的下面有没有左右节点了,这里处理之后q里就会存入下一层可能出现的值，比如：第一层只有3，第二层有【9，20】那么q里就会有【9，20】2个值了。
            //如果有左孩子，放进队列
            if (node->left) q.push(node->left);
            //如果有右孩子，放进队列
            if (node->right) q.push(node->right);
        }

        //如果有右孩子，放进队列;每次循环一层就完成一次添加
        result.push_back(level);
        temp++;
        std::cout<<"temp:=======>"<<temp<<std::endl;
    }

    //返回最终的二维数组
    return result;
}

// ✅ 显式模板实例化（必须有，否则链接失败）
template class BinaryTreeLevelOrder<int>;

