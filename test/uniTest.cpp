#include "uniTest.h"
#include <iostream>
#include <vector>

int test_queue_with_two_stacks() {
    QueueWithTwoStacks<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front: " << q.front() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 1
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 2

    q.enqueue(4);
    std::cout << "Front: " << q.front() << "\n"; // 3
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 3
    std::cout << "Dequeue: " << q.dequeue() << "\n"; // 4

    if (q.empty()) std::cout << "Queue is empty\n";

    return 0;
}


int test_queue_with_two_stacks_2() {

    QueueWithTwoStacks<int> q;

    // 入队
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "=======>Pop: " << q.pop() << std::endl; // 1
    std::cout << "========>Pop: " << q.pop() << std::endl; // 2

    // 再入队
    q.push(4);
    std::cout<<"111111"<<std::endl;
    std::cout << "Pop: " << q.pop() << std::endl; // 3
    std::cout<<"22222"<<std::endl;
    std::cout << "Pop: " << q.pop() << std::endl; // 4

    // 队列是否为空
    if (q.empty()) std::cout << "Queue is empty" << std::endl;


    return 0;
}

int test_power() {
    // 使用 Power<double>
    Power<double> p;

    double base1 = 2.0;
    int exp1 = 10;

    double result1 = p.power(base1, exp1);
    std::cout << base1 << "^" << exp1 << " = " << result1 << std::endl;

    // 测试负指数
    double base2 = 2.0;
    int exp2 = -3;

    double result2 = p.power(base2, exp2);
    std::cout << base2 << "^" << exp2 << " = " << result2 << std::endl;

    // 测试 0 的负指数，检查 g_InvalidInput
    double base3 = 0.0;
    int exp3 = -1;

    double result3 = p.power(base3, exp3);
    if (p.isInvalid()) {
        std::cout << "Invalid input: 0 cannot be raised to negative power." << std::endl;
    } else {
        std::cout << base3 << "^" << exp3 << " = " << result3 << std::endl;
    }

    return 0;
}

int test_ransom_note(){
    RansomNote<char> rn;

    std::cout<<"1111"<<std::endl;
    std::string ransomNote1 = "a";
    std::string magazine1 = "b";
    std::cout << std::boolalpha << rn.canConstruct(ransomNote1, magazine1) << std::endl; // false

    std::cout<<"2222"<<std::endl;
    std::string ransomNote2 = "aa";
    std::string magazine2 = "ab";
    std::cout << std::boolalpha << rn.canConstruct(ransomNote2, magazine2) << std::endl; // false

    std::cout<<"3333"<<std::endl;
    std::string ransomNote3 = "aa";
    std::string magazine3 = "aab";
    std::cout << std::boolalpha << rn.canConstruct(ransomNote3, magazine3) << std::endl; // true

    return 0;
}

int test_interval_inserter(){
    
    IntervalInserter<int> inserter;
    
    std::vector<Interval<int>> intervals = {
        Interval<int>(1,2),
        Interval<int>(3,5),
        Interval<int>(6,7),
        Interval<int>(8,10),
        Interval<int>(12,16)
    };

    Interval<int> newInterval(4,9);

    std::vector<Interval<int>> result = inserter.insert(intervals, newInterval);

    std::cout << "Merged Intervals: ";
    for (const auto& i : result) {
        std::cout << "[ " << i.start << ", " << i.end << "] ";
    }
    std::cout << std::endl;

    return 0;

}

int test_max_subarray(){

    MaxSubarray<int> solver;

    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = solver.findMaxSum(nums);

    std::cout << "Maximum Subarray Sum = " << result << std::endl;

    return 0;
}

int test_two_sum(){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = TwoSum::findIndices(nums, target);

    std::cout << "Result: [" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}

int test_matrix01(){
    std::vector<std::vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}  //{0, 0, 0}
    };

    Matrix01<int> solver;
    
    std::vector<std::vector<int>> result = solver.updateMatrix(mat);

    std::cout<<"Res distance matrix:\n";

    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}


int test_points_k_closest(){
    KClosestPoints<int> solver;

    std::vector<std::vector<int>> points = {{1,3},{-2,2},{3,3}};
    int k = 2;

    std::vector<std::vector<int>> result = solver.findClosest(points, k);

    std::cout << "k=" << k << " closest points to origin:\n";
    for(const auto& p : result){
        std::cout << "[" << p[0] << "," << p[1] << "]\n";
    }

    return 0;
}

int test_longest_substring(){

    LongestSubstring solver; // 创建对象

    std::string s = "abcabcbb";

    // 调用返回长度的函数
    int len = solver.lengthOfLongestSubstring(s);
    std::cout << "Length of longest substring: " << len << std::endl;

    // 调用返回最长子串的函数
    std::string longest = solver.getLongestSubstring(s);
    std::cout << "Longest substring: " << longest << std::endl;
    
    return 0;
}

int test_three_sum(){

    ThreeSum solver;
    
    std::vector<int> nums={-1,0,1,2,-1,-4};

    std::vector<std::vector<int>> triplets = solver.findTriplets(nums);

    std::cout<<"Triplets that sum to 0:"<<std::endl;

    for(const auto& t: triplets){
        std::cout<<"[";
        for(size_t i=0; i<t.size();i++){
            std::cout<<t[i];
            if(i<t.size()-1) std::cout<<",";
        }
        std::cout<<"]"<<std::endl;
    }

    return 0;
}

int test_binary_tree_level_ordre(){
    // 创建树节点（你的例子 [3,9,20,null,null,15,7]）
    TreeNode<int>* root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    // 创建层序遍历对象
    BinaryTreeLevelOrder<int> btree;

    // 调用层序遍历方法
    std::vector<std::vector<int>> result = btree.levelOrder(root);

    // 输出结果
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i < result.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;

    // 释放内存
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

int test_lru_cache(){
    LRUCache cache(2); // 容量 2

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // 输出 1
    cache.put(3, 3); // 淘汰 key=2
    std::cout << cache.get(2) << std::endl; // 输出 -1
    cache.put(4, 4); // 淘汰 key=1
    std::cout << cache.get(1) << std::endl; // 输出 -1
    std::cout << cache.get(3) << std::endl; // 输出 3
    std::cout << cache.get(4) << std::endl; // 输出 4

    return 0;
}

int test_add_two_numbers(){
    AddTwoNumbers<int> solver;

    auto l1 = solver.buildList({2,4,3});
    auto l2 = solver.buildList({5,6,4});

    auto sum = solver.addTwoNumbers(l1, l2);

    solver.printList(sum);

    return 0;
}

int test_kth_smallest_elements(){
    BSTKth<int> solver;

    std::vector<int> data = {5,3,6,2,4,1};
    TreeNode<int>* root = solver.buildBTS(data);

    int k = 3;
    int kth_smallest = solver.kthSmallest(root, k);

    std::cout << k << "th smallest element in BST: " << kth_smallest << std::endl;

    // 释放内存
    solver.deleteTree(root);

    return 0;
}