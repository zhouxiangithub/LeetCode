#pragma once
using namespace std;
#include <vector>
#include <queue>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b)
    {
        if (!a || !b)
        {
            return a ? a : b;
        }
        ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
        while (aPtr && bPtr)
        {
            if (aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else
            {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};

class Solution {
public:
    struct  Status
    {
        int val;
        ListNode* ptr;
        bool operator < (const Status& rhs) const
        {
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node : lists)
        {
            if (node)
            {
                q.push({ node->val,node });
            }
        }
        ListNode head, * tail = &head;
        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next)
            {
                q.push({ f.ptr->next->val,f.ptr->next });
            }
        }
        return head.next;
    }
};