#pragma once
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);

        if (head == nullptr) //循环链表为空
        {
            node->next = node;
            return node;
        }

        if (head->next == head) //循环链表中只有一个节点
        {
            head->next = node;
            node->next = head;
            return head;
        }

        // 3 -> 4 -> 1 -> 3
        // 3 -> 4 -> 1 -> 2 -> 3
        Node* curr = head, * next = head->next;
        while (next != head)
        {
            // 3 -> 4
            if (insertVal >= curr->val && insertVal <= next->val)
            {
                break;
            }

            // 4 -> 1
            if (curr->val > next->val)
            {
                if (insertVal > curr->val || insertVal < next->val)
                {
                    break;
                }
            }

            curr = curr->next;
            next = next->next;
        }
        curr->next = node;
        node->next = next;
        return head;
    }
};