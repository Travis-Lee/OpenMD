#include "lru_cache.h"

// 构造函数
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    head = nullptr;
    tail = nullptr;
}

// 从链表移除节点
void LRUCache::remove(Node* node) {
    if (!node) return;
    if (node->prev) node->prev->next = node->next;
    else head = node->next; // node 是头部
    if (node->next) node->next->prev = node->prev;
    else tail = node->prev; // node 是尾部
}

// 插入到链表头部（最近使用）
void LRUCache::insertToHead(Node* node) {
    node->prev = nullptr;
    node->next = head;
    if (head) head->prev = node;
    head = node;
    if (!tail) tail = head; // 第一个节点
}

// get 操作
int LRUCache::get(int key) {
    if (mp.find(key) == mp.end()) return -1;
    Node* node = mp[key];
    remove(node);
    insertToHead(node);
    return node->value;
}

// put 操作
void LRUCache::put(int key, int value) {
    if (mp.find(key) != mp.end()) {
        Node* node = mp[key];
        node->value = value;
        remove(node);
        insertToHead(node);
    } else {
        Node* node = new Node(key, value);
        if (mp.size() == cap) {
            //先保存旧尾节点指针
            Node* oldTail = tail;

            mp.erase(oldTail->key);
            remove(oldTail);
            delete oldTail;
        }
        insertToHead(node);
        mp[key] = node;
    }
}

