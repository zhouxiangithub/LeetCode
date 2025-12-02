#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> isExist;
        for (int num : nums) {
            isExist[num] = 1;
        }
        ListNode res(0, head);
        ListNode* node = &res;
        while (node->next) {
            if (isExist[node->next->val]) {
                node->next = node->next->next;
            }
            else {
                node = node->next;
            }
        }
        return res.next;
    }
};