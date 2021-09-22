#pragma once
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* deleteNode(ListNode* head, int val)
	{
		if (head->val == val)
		{
			return head->next;
		}
		ListNode* pre = head, * cur = head->next;
		while (cur != nullptr && cur->val != val)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur != nullptr)
		{
			pre->next = cur->next;
		}
		return head;
	}

	ListNode* deleteNode(ListNode* head, int val)
	{
		if (head->val == val)
		{
			return head->next;
		}
		ListNode* pre = head, * cur = head->next;
		while (cur != nullptr)
		{
			if (cur->val == val)
			{
				pre->next = cur->next;
				break;
			}
			pre = cur;
			cur = cur->next;
		}
		return head;
	}
};