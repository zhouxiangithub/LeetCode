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

//��ϣ��
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

//����ָ��
/*
    ����ʱ��,��ָ���ߵľ��붼����ָ�������,����:
        a+n*(b+c)+b = 2*(a+b)
    ==> a = c+(n-1)*(b+c)
    �ɵ�:�������㵽�뻷��ľ������(n-1)Ȧ�Ļ����ڴ�����ͷ�����뻷��ľ���
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