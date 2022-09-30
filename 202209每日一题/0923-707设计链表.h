#pragma once
using namespace std;
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val)
    {
        this->val = val;
    }
};

//单向链表
class MyLinkedList {
private:
    int size;
    ListNode* head;
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
    }

    int get(int index) {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        ListNode* cur = head;
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size)
        {
            return;
        }
        index = max(0, index);
        size++;
        ListNode* node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        ListNode* addNode = new ListNode(val);
        addNode->next = node->next;
        node->next = addNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
        {
            return;
        }
        size--;
        ListNode* node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        ListNode* delNode = node->next;
        node->next = node->next->next;
        delete delNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

struct DLinkListNode {
    int val;
    DLinkListNode* prev, * next;
    DLinkListNode(int _val) :val(_val), prev(nullptr), next(nullptr) {}
};

//双向链表
class MyLinkedList {
private:
    int size;
    DLinkListNode* head;
    DLinkListNode* tail;
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new DLinkListNode(0);
        this->tail = new DLinkListNode(0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int index) {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        DLinkListNode* curr;
        if (index + 1 < size - index) //从头开始找
        {
            curr = head;
            for (int i = 0; i <= index; i++)
            {
                curr = curr->next;
            }
        }
        else //从尾开始找
        {
            curr = tail;
            for (int i = 0; i < size - index; i++)
            {
                curr = curr->prev;
            }
        }
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size)
        {
            return;
        }
        index = max(0, index);
        DLinkListNode* pre, * next;
        if (index < size - index)
        {
            pre = head;
            for (int i = 0; i < index; i++)
            {
                pre = pre->next;
            }
            next = pre->next;
        }
        else
        {
            next = tail;
            for (int i = 0; i < size - index; i++)
            {
                next = next->prev;
            }
            pre = next->prev;
        }
        size++;
        DLinkListNode* addNode = new DLinkListNode(val);
        addNode->prev = pre;
        addNode->next = next;
        pre->next = addNode;
        next->prev = addNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
        {
            return;
        }
        DLinkListNode* pre, * next;
        if (index < size - index)
        {
            pre = head;
            for (int i = 0; i < index; i++)
            {
                pre = pre->next;
            }
            next = pre->next->next;
        }
        else
        {
            next = tail;
            for (int i = 0; i < size - index - 1; i++)
            {
                next = next->prev;
            }
            pre = next->prev->prev;
        }
        size--;
        DLinkListNode* delNode = pre->next;
        pre->next = next;
        next->prev = pre;
        delete delNode;
    }
};