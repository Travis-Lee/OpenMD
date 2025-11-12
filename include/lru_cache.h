#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>

// 双向链表节点
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity);
    ～ LRUCache() = default;
    int get(int key);
    void put(int key, int value);

private:
    int cap; // 缓存容量
    Node* head; // 链表头（最近使用）
    Node* tail; // 链表尾（最久未使用）
    std::unordered_map<int, Node*> mp; // key -> 节点映射

    void remove(Node* node); // 从链表移除
    void insertToHead(Node* node); // 插到头部
};

#endif

