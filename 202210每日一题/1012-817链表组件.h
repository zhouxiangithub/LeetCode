#pragma once
using namespace std;
#include <vector>
#include <unordered_set>

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

/*
    在链表中计算有多少组件的起始位置, 需满足以下条件:
    (1)节点的值在数组nums中且节点位于链表起始位置;
    (2)节点的值在数组nums中且节点的前一个点不在数组nums中
*/
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int num : nums)
        {
            numsSet.emplace(num);
        }
        bool inSet = false;
        int res = 0;
        while (head != nullptr)
        {
            if (numsSet.count(head->val))
            {
                if (!inSet)
                {
                    inSet = true;
                    res++;
                }
            }
            else
            {
                inSet = false;
            }
            head = head->next;
        }
        return res;
    }
};