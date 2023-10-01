#pragma once
using namespace std;
#include <unordered_map>

struct DLinkedNode {
    int key, value;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode() :key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) :key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int capacity) :capacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key))
        {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key))
        {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if (size > capacity)
            {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else
        {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node)
    {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DLinkedNode* node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail()
    {
        DLinkedNode* node = tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */