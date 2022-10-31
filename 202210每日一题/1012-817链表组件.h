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
    �������м����ж����������ʼλ��, ��������������:
    (1)�ڵ��ֵ������nums���ҽڵ�λ��������ʼλ��;
    (2)�ڵ��ֵ������nums���ҽڵ��ǰһ���㲻������nums��
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