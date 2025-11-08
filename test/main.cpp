#include "reverse_words.h"
#include "linked_list.h"
#include "binary_search.h"
#include "array_duplication.h"
#include "mat.h"
#include "sorter.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "string_replacer.h"
#include "uniTest.h"


void test_replace_space(){
    const int MAX_SIZE = 100;
    char testStr[MAX_SIZE] = "Hello World and Munich";
    std::cout << "Before: " << testStr << std::endl;
    
    StringReplacer<char>::ReplaceBlank(testStr, MAX_SIZE);
    std::cout << "After:  " << testStr << std::endl;

}

void test(){
    LinkedList<int> list;

    // 插入带重复的有序链表：1 2 2 3 3 4 5
    list.push_back(1);
    list.push_back(2);
    list.push_back(2);
    list.push_back(3);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << "Before: ";
    list.print();

    list.delete_duplication();

    std::cout << "After:  ";
    list.print();
    
    list.print_list_reversingly();
}

void test_array_dup(){
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    std::size_t length = sizeof(arr)/sizeof(arr[0]);
    int dup;
    ArrDup<int> finder;
    bool found = finder.find_duplicate(arr, length, &dup);

    if(found)
        std::cout << "Found duplicate: " << dup << std::endl;
    else
        std::cout << "No duplicate found" << std::endl;

    finder.find_duplicate(arr,length);
    
    if(finder.found) {
        std::cout << "找到重复数字：" << finder.dup_value
                  << "，下标：" << finder.dup_index << std::endl;
    } else {
        std::cout << "没有找到重复数字" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    ReverseWord RW;
    char a[]="hello world!";
    //printf("%s\n",RW.strrevw(a));
    printf("%s\n",RW.reverse_string(a));

    Mat<int> m(2, 3);

    int v = 1;
    for (size_t i = 0; i < m.rows(); ++i)
        for (size_t j = 0; j < m.cols(); ++j)
            m(i, j) = v++;

    int* arr = m.data();
    for (size_t k = 0; k < m.size(); ++k)
        std::cout << arr[k] << " ";

    std::cout << "\nrows = " << m.rows() << ", cols = " << m.cols() << "\n";

    int dataA[2][3] = {{1,2,3},{4,5,6}};
    int dataB[3][2] = {{7,8},{9,10},{11,12}};

    // 直接用数组初始化 Mat 对象
    Mat<int> A(dataA);
    Mat<int> B(dataB);

    Mat<int> C = Mat<int>::mat_multiply(A, B);

    for (size_t i = 0; i < C.rows(); ++i) {
        for (size_t j = 0; j < C.cols(); ++j)
            std::cout << C(i, j) << " ";
        std::cout << "\n";
    }


    std::vector<int> vecC=C.mat2vec();
    std::cout << "Matrix C as vector: ";
    for (auto v : vecC) std::cout << v << " ";
    std::cout << std::endl;


    LinkedList<int> list;

    // 插入一些元素
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    std::cout << "Original list: ";
    list.print();

    // 反转
    list.reverse();

    std::cout << "Reversed list: ";
    list.print();

    std::vector<int> num;
    num.push_back(10);
    num.push_back(20);
    num.push_back(30);
    num.push_back(40);

    std::cout<<"size:"<<num.size()<<std::endl;
    std::cout<<"first:"<<num.front()<<std::endl;
    std::cout<<"last:"<<num.back()<<std::endl;

    for(auto it=num.begin(); it!=num.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    
    num.pop_back();

    for(auto it=num.begin(); it!=num.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    // sorter arrary 
    int array[] = {5, 2, 8, 1, 4};
    int n = sizeof(array) / sizeof(array[0]);

    Sorter<int>::sort(array, n);

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }

    
    int arr1[] = {3, 1, 4, 1, 5, 9};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    std::cout << "int数组最大值：" << Sorter<int>::get_max(arr1,n1) << std::endl;  // 输出 9
    std::cout << "int数组最小值：" << Sorter<int>::get_min(arr1,n1) << std::endl;  // 输出 9

    double arr2[] = {2.7, 3.1, 1.6, 5.5};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    std::cout << "double数组最大值：" << Sorter<double>::get_max(arr2,n2) << std::endl;  // 输出 5.5
    std::cout << "double数组最小值：" << Sorter<double>::get_min(arr2,n2) << std::endl;  // 输出 5.5
    std::cout << "double数组平均值：" << Sorter<double>::get_mean(arr2,n2) << std::endl;  // 输出 5.5

    int barr[] = {1, 3, 5, 7, 9, 11};
    int bn = sizeof(barr)/sizeof(barr[0]);

    int idx1 = BSorter<int>::binary_search(barr, bn, 7);
    std::cout << "7 的位置是: " << idx1 << std::endl;

    int idx2 = BSorter<int>::binary_search(barr, bn, 4);
    std::cout << "4 的位置是: " << idx2 << std::endl;

      // 假设我们要删除第二个节点（20）
    ListNode<int>* head = list.get_head();
    ListNode<int>* node_to_delete = head->next; // 第二个节点

    list.delete_node(node_to_delete);

    std::cout << "After deletion: ";
    list.print(); // 输出: 10 30
   
    test();

    test_array_dup();
 
    test_replace_space();

    test_queue_with_two_stacks();
    test_queue_with_two_stacks_2();
    
    test_power();
    
    test_ransom_note();

    test_interval_inserter();

    test_max_subarray();
    
    test_two_sum();

    test_matrix01();    

    test_points_k_closest();

    test_longest_substring();
    
    return 0;
}


