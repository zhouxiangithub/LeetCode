#pragma once
using namespace std;
#include <unordered_set>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//哈希表
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr)
        {
            if (seen.count(head))
            {
                return head;
            }
            seen.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

//快慢指针
/*
    任意时刻,快指针走的距离都是慢指针的两倍,所以:
        a+n*(b+c)+b = 2*(a+b)
    ==> a = c+(n-1)*(b+c)
    可得:从相遇点到入环点的距离加上(n-1)圈的环等于从链表头部到入环点的距离
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode* node = head;
                while (node != slow)
                {
                    node = node->next;
                    slow = slow->next;
                }
                return node;
            }
        }
        return nullptr;
    }
};